#include "demos.h"

namespace Protean
{
	// https://www.shadertoy.com/view/3l23Rh Protean Clouds, by nimitz
	// Code has been modified a bit to fit library constraints

	mat2 rot(simdfloat a) { simdfloat c = cos(a), s = sin(a); return mat2(c, s, -s, c); }
	const mat3 m3 = mat3(0.33338, 0.56034, -0.71817, -0.87887, 0.32651, -0.15323, 0.15162, 0.69596, 0.61339) * 1.93;
	simdfloat mag2(vec2 p) { return dot(p, p); }
	simdfloat linstep(simdfloat mn, simdfloat mx, simdfloat x) { return clamp((x - mn) / (mx - mn), 0.f, 1.f); }
	simdfloat prm1 = SIMDZERO;
	vec2 bsMo = vec2(0);

	vec2 disp(simdfloat t) { return vec2(sin(t * 0.22f) * 1.f, cos(t * 0.175f) * 1.f) * 2.f; }

	vec2 map(vec3 p)
	{
		vec3 p2 = p;
		p2.xy(p2.xy() - disp(p.z).xy());
		p.xy(p.xy() * rot(sin(p.z + iTime) * (0.1f + prm1 * 0.05f) + iTime * 0.09f));
		simdfloat cl = mag2(p2.xy());
		simdfloat d = SIMDZERO;
		p *= .61f;
		simdfloat z = SIMDONE;
		simdfloat trk = SIMDONE;
		simdfloat dspAmp = 0.1f + prm1 * 0.2f;
		for (int i = 0; i < 5; i++)
		{
			p += sin(p.zxy() * 0.75f * trk + iTime * trk * .8f) * dspAmp;
			d -= abs(dot(cos(p), sin(p.yzx())) * z);
			z *= 0.57f;
			trk *= 1.4f;
			p = p * m3;
		}
		d = abs(d + prm1 * 3.f) + prm1 * .3f - 2.5f + bsMo.y;
		return vec2(d + cl * .2f + 0.25f, cl);
	}

	vec4 render(vec3 ro, vec3 rd, simdfloat time)
	{
		vec4 rez = vec4(0);
		const simdfloat ldst = (8.f);
		vec3 lpos = vec3(disp(time + ldst) * 0.5f, time + ldst);
		simdfloat t = (1.5f);
		simdfloat fogT = SIMDZERO;
		for (int i = 0; i < 130; i++)
		{
			// Note of simdshader author : conditional statement here. Loop can be exited if every simd lane met the condition.
			// if (rez.a > 0.99)break;
			if (maskAll(rez.a > 0.99f))
				break;

			vec3 pos = ro + t * rd;
			vec2 mpv = map(pos);
			simdfloat den = clamp(mpv.x - 0.3f, 0.f, 1.f) * 1.12f;
			simdfloat dn = clamp((mpv.x + 2.f), 0.f, 3.f);

			vec4 col = vec4(0);

			// Note of simdshader author : another conditional statement here, replaced with testmask and blendv logic
			simdmask testmask = mpv.x > 0.6f;

			if (!maskNone(testmask)) // If every simd lane don't met the condition, don't execute that code
			{
				vec4 coltemp = vec4(sin(vec3(5.f, 0.4f, 0.2f) + mpv.y * 0.1f + sin(pos.z * 0.4f) * 0.5f + 1.8f) * 0.5f + 0.5f, 0.08f);
				coltemp *= den * den * den;
				coltemp.rgb(coltemp.rgb() * linstep((4.f), (-2.5f), mpv.x) * 2.3f);
				simdfloat dif = clamp((den - map(pos + .8f).x) / 9.f, 0.001f, 1.f);
				dif += clamp((den - map(pos + .35f).x) / 2.5f, 0.001f, 1.f);
				coltemp.xyz(coltemp.xyz() * den * (vec3(0.005f, .045f, .075f) + 1.5f * vec3(0.033f, 0.07f, 0.03f) * dif));
				col = blendv(col, coltemp, testmask);
			}

			simdfloat fogC = exp(t * 0.2f - 2.2f);
			col.rgba(col.rgba() + vec4(0.06f, 0.11f, 0.11f, 0.1f) * clamp(fogC - fogT, 0.f, 1.f));
			fogT = fogC;
			rez = rez + col * (1.f - rez.a);
			t += clamp(0.5f - dn * dn * .05f, 0.09f, 0.3f);
		}
		return clamp(rez, 0.0f, 1.0f);
	}

	simdfloat getsat(vec3 c)
	{
		simdfloat mi = min(min(c.x, c.y), c.z);
		simdfloat ma = max(max(c.x, c.y), c.z);
		return (ma - mi) / (ma + 1e-7f);
	}

	// from my "Will it blend" shader (https://www.shadertoy.com/view/lsdGzN)
	vec3 iLerp(vec3 a, vec3 b, simdfloat x)
	{
		vec3 ic = mix(a, b, x) + vec3(1e-6, 0.f, 0.f);
		simdfloat sd = abs(getsat(ic) - mix(getsat(a), getsat(b), x));
		vec3 dir = normalize(vec3(2.f * ic.x - ic.y - ic.z, 2.f * ic.y - ic.x - ic.z, 2.f * ic.z - ic.y - ic.x));
		simdfloat lgt = dot(vec3(1.0f), ic);
		simdfloat ff = dot(dir, normalize(ic));
		ic += 1.5f * dir * sd * ff * lgt;
		return clamp(ic, 0.f, 1.f);
	}

	vec4 mainImage(vec2 fragCoord)
	{
		vec2 q = fragCoord.xy() / iResolution.xy();
		vec2 p = (fragCoord.xy() - 0.5f * iResolution.xy()) / iResolution.y;
		bsMo = (iMouse.xy() - 0.5f * iResolution.xy()) / iResolution.y;

		simdfloat time = iTime * 3.f;
		vec3 ro = vec3(0, 0, time);

		ro += vec3(sin(iTime) * 0.5f, sin(iTime * 1.f) * 0.f, .0f);

		simdfloat dspAmp = (.85f);
		ro.xy(ro.xy() + disp(ro.z) * dspAmp);
		simdfloat tgtDst = (3.5f);

		vec3 target = normalize(ro - vec3(disp(time + tgtDst) * dspAmp, time + tgtDst));
		ro.x -= bsMo.x * 2.;
		vec3 rightdir = normalize(cross(target, vec3(0.0f, 1.0f, 0.0f)));
		vec3 updir = normalize(cross(rightdir, target));
		rightdir = normalize(cross(updir, target));
		vec3 rd = normalize((p.x * rightdir + p.y * updir) * 1.f - target);
		rd.xy(rd.xy() * rot(-disp(time + 3.5f).x * 0.2f + bsMo.x));
		prm1 = smoothstep(-0.4f, 0.4f, sin(iTime * 0.3f));
		vec4 scn = render(ro, rd, time);

		vec3 col = scn.rgb();
		col = iLerp(col.bgr(), col.rgb(), clamp(1.f - prm1, 0.05f, 1.f));

		col = pow(col, vec3(.55f, 0.65f, 0.6f)) * vec3(1.f, .97f, .9f);

		col *= pow(16.0f * q.x * q.y * (1.0f - q.x) * (1.0f - q.y), 0.12) * 0.7f + 0.3f; // Vign

		return vec4(col, 1.0f);
	}
}
