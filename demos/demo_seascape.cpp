#include "demos.h"

namespace Seascape
{
	// https:// www.shadertoy.com/view/Ms2SD1 Seascape, by TDM
	// Code has been modified a bit to fit library constraints

	const int NUM_STEPS = 32;
	const float PI = 3.141592f;
	const float EPSILON = 1e-3f;
#define EPSILON_NRM (0.1f / iResolution.x)
	// #define AA

	// sea
	const int ITER_GEOMETRY = 3;
	const int ITER_FRAGMENT = 5;
	const simdfloat SEA_HEIGHT = (0.6);
	const simdfloat SEA_CHOPPY = (4.0);
	const simdfloat SEA_SPEED = (0.8);
	const simdfloat SEA_FREQ = (0.16);
	const vec3 SEA_BASE = vec3(0.0, 0.09, 0.18);
	const vec3 SEA_WATER_COLOR = vec3(0.8, 0.9, 0.6) * 0.6;
#define SEA_TIME (1.0f + iTime * SEA_SPEED)
	const mat2 octave_m = mat2(1.6f, 1.2f, -1.2f, 1.6f);
	// #define AA

	// math
	mat3 fromEuler(vec3 ang) {
		vec2 a1 = vec2(sin(ang.x), cos(ang.x));
		vec2 a2 = vec2(sin(ang.y), cos(ang.y));
		vec2 a3 = vec2(sin(ang.z), cos(ang.z));
		mat3 m;
		m[0] = vec3(a1.y * a3.y + a1.x * a2.x * a3.x, a1.y * a2.x * a3.x + a3.y * a1.x, -a2.y * a3.x);
		m[1] = vec3(-a2.y * a1.x, a1.y * a2.y, a2.x);
		m[2] = vec3(a3.y * a1.x * a2.x + a1.y * a3.x, a1.x * a3.x - a1.y * a3.y * a2.x, a2.y * a3.y);
		return m;
	}
	simdfloat hash(vec2 p) {
		simdfloat h = dot(p, vec2(127.1f, 311.7f));
		return fract(sin(h) * 43758.5453123f);
	}
	simdfloat noise(vec2 p) {
		vec2 i = floor(p);
		vec2 f = fract(p);
		vec2 u = f * f * (3.0f - 2.0f * f);
		return -1.0f + 2.0f * mix(mix(hash(i + vec2(0.0f, 0.0f)),
			hash(i + vec2(1.0f, 0.0f)), u.x),
			mix(hash(i + vec2(0.0f, 1.0f)),
				hash(i + vec2(1.0f, 1.0f)), u.x), u.y);
	}

	// lighting
	simdfloat diffuse(vec3 n, vec3 l, simdfloat p) {
		return pow(dot(n, l) * 0.4f + 0.6f, p);
	}
	simdfloat specular(vec3 n, vec3 l, vec3 e, simdfloat s) {
		simdfloat nrm = (s + 8.0f) / (PI * 8.0f);
		return pow(max(dot(reflect(e, n), l), 0.0f), s) * nrm;
	}

	// sky
	vec3 getSkyColor(vec3 e) {
		e.y = (max(e.y, 0.0f) * 0.8f + 0.2f) * 0.8f;
		return vec3(pow(1.0f - e.y, 2.0f), 1.0f - e.y, 0.6f + (1.0f - e.y) * 0.4f) * 1.1f;
	}

	// sea
	simdfloat sea_octave(vec2 uv, simdfloat choppy) {
		uv += noise(uv);
		vec2 wv = 1.0f - abs(sin(uv));
		vec2 swv = abs(cos(uv));
		wv = mix(wv, swv, wv);
		return pow(1.0f - pow(wv.x * wv.y, 0.65f), choppy);
	}

	simdfloat map(vec3 p) {
		simdfloat freq = SEA_FREQ;
		simdfloat amp = SEA_HEIGHT;
		simdfloat choppy = SEA_CHOPPY;
		vec2 uv = p.xz(); uv.x *= 0.75f;

		simdfloat d, h = SIMDZERO;
		for (int i = 0; i < ITER_GEOMETRY; i++) {
			d = sea_octave((uv + SEA_TIME) * freq, choppy);
			d += sea_octave((uv - SEA_TIME) * freq, choppy);
			h += d * amp;
			uv *= octave_m; freq *= 1.9f; amp *= 0.22f;
			choppy = mix(choppy, SIMDONE, 0.2f);
		}
		return p.y - h;
	}

	simdfloat map_detailed(vec3 p) {
		simdfloat freq = SEA_FREQ;
		simdfloat amp = SEA_HEIGHT;
		simdfloat choppy = SEA_CHOPPY;
		vec2 uv = p.xz(); uv.x *= 0.75f;

		simdfloat d, h = SIMDZERO;
		for (int i = 0; i < ITER_FRAGMENT; i++) {
			d = sea_octave((uv + SEA_TIME) * freq, choppy);
			d += sea_octave((uv - SEA_TIME) * freq, choppy);
			h += d * amp;
			uv *= octave_m; freq *= 1.9f; amp *= 0.22f;
			choppy = mix(choppy, SIMDONE, 0.2f);
		}
		return p.y - h;
	}

	vec3 getSeaColor(vec3 p, vec3 n, vec3 l, vec3 eye, vec3 dist) {
		simdfloat fresnel = clamp(1.0f - dot(n, -eye), 0.0f, 1.0f);
		fresnel = min(fresnel * fresnel * fresnel, 0.5f);

		vec3 reflected = getSkyColor(reflect(eye, n));
		vec3 refracted = SEA_BASE + diffuse(n, l, (80.0f)) * SEA_WATER_COLOR * 0.12f;

		vec3 color = mix(refracted, reflected, fresnel);

		simdfloat atten = max(1.0f - dot(dist, dist) * 0.001f, 0.0f);
		color += SEA_WATER_COLOR * (p.y - SEA_HEIGHT) * 0.18f * atten;

		color += specular(n, l, eye, 600.0f * inversesqrt(dot(dist, dist)));

		return color;
	}

	// tracing
	vec3 getNormal(vec3 p, simdfloat eps) {
		vec3 n;
		n.y = map_detailed(p);
		n.x = map_detailed(vec3(p.x + eps, p.y, p.z)) - n.y;
		n.z = map_detailed(vec3(p.x, p.y, p.z + eps)) - n.y;
		n.y = eps;
		return normalize(n);
	}


	simdfloat heightMapTracing(vec3 ori, vec3 dir, vec3& p) {
		simdfloat tm = SIMDZERO;
		simdfloat tx = (1000.0f);
		simdfloat hx = map(ori + dir * tx);

		// Note of simdshader author : replaced conditional statement with testmask and blendv logic
		// Execution flow can be broken if every simd lane met the condition, which is checked with maskAll function
		
		// if (hx > 0.0) {
		// 	p = ori + dir * tx;
		// 	return tx;
		// }
		simdmask maskBreak = hx > 0.0;
		p = blendv(p, ori + dir * tx,  maskBreak);
		if (maskAll(maskBreak))
			return tx;

		simdfloat hm = map(ori);
		for (int i = 0; i < NUM_STEPS; i++) {
			simdfloat tmid = mix(tm, tx, hm / (hm - hx));
			p = ori + dir * tmid;
			simdfloat hmid = map(p);

			// Same here, replaced conditional statement with testmask and blendv logic
			
			// if (hmid < 0.0) {
			// 	tx = tmid;
			// 	hx = hmid;
			// }
			// else {
			// 	tm = tmid;
			// 	hm = hmid;
			// }
			simdmask testmask = hmid < 0.0f;
			tx = blendv(tx, tmid, testmask);
			hx = blendv(hx, hmid,  testmask);
			tm = blendv(tmid, tm,  testmask);
			hm = blendv(hmid, hm, testmask);

			// if (abs(hmid) < EPSILON) break;
			if (maskAll(abs(hmid) < EPSILON)) // Break execution flow if every simd lane met the condition
				break;
		}

		simdfloat finalVal = blendv(mix(tm, tx, hm / (hm - hx)), tx,  maskBreak);
		return finalVal;
	}

	vec3 getPixel(vec2 coord, simdfloat time) {
		vec2 uv = coord / iResolution.xy();
		uv = uv * 2.0f - 1.0f;
		uv.x *= iResolution.x / iResolution.y;

		// ray
		vec3 ang = vec3(sin(time * 3.0f) * 0.1f, sin(time) * 0.2f + 0.3f, time);
		vec3 ori = vec3(0.0f, 3.5f, time * 5.0f);
		vec3 dir = normalize(vec3(uv.xy(), -2.0f)); dir.z += length(uv) * 0.14f;
		dir = normalize(dir) * fromEuler(ang);

		// tracing
		vec3 p;
		heightMapTracing(ori, dir, p);
		vec3 dist = p - ori;
		vec3 n = getNormal(p, dot(dist, dist) * EPSILON_NRM);
		vec3 light = normalize(vec3(0.0f, 1.0f, 0.8f));

		// color
		return mix(
			getSkyColor(dir),
			getSeaColor(p, n, light, dir, dist),
			pow(smoothstep(0.0f, -0.02f, dir.y), 0.2f));
	}

	// main
	vec4 mainImage(vec2 fragCoord) {
		simdfloat time = iTime * 0.3f;

#ifdef AA
		vec3 color = vec3(0.0);
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				vec2 uv = fragCoord + vec2(i, j) / 3.0;
				color += getPixel(uv, time);
			}
		}
		color /= 9.0;
#else
		vec3 color = getPixel(fragCoord, time);
#endif

		// post
		return vec4(pow(color, vec3(0.65f)), 1.0f);
	}
}