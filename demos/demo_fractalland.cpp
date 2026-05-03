#include "demos.h"

namespace FractalLand
{
	// https:// www.shadertoy.com/view/XsBXWt Fractal Land, by Kali
	// Code has been modified a bit to fit library constraints

	// #define SHOWONLYEDGES
#define NYAN
#define WAVES
// #define BORDER

#define RAY_STEPS 150

#define BRIGHTNESS 1.2f
#define GAMMA 1.4f
#define SATURATION .65f


#define detail .001f
#define t iTime*.5f


	const vec3 origin = vec3(-1.f, .7f, 0.f);
	thread_local simdfloat det = SIMDZERO;
	thread_local simdfloat edge = SIMDZERO;


	// 2D rotation function
	mat2 rot(simdfloat a) {
		return mat2(cos(a), sin(a), -sin(a), cos(a));
	}

	// "Amazing Surface" fractal
	vec4 formula(vec4 p) {
		p.xz(abs(p.xz() + 1.f) - abs(p.xz() - 1.f) - p.xz());
		p.y -= .25f;
		p.xy(p.xy() * rot(radians(35.f)));
		p = p * 2.f / clamp(dot(p.xyz(), p.xyz()), .2f, 1.f);
		return p;
	}

	// Distance function
	simdfloat de(vec3 pos) {
#ifdef WAVES
		pos.y += sin(pos.z - t * 6.f) * .15f; // waves!
#endif
		simdfloat hid = SIMDZERO;
		vec3 tpos = pos;
		tpos.z = abs(3.f - mod(tpos.z, 6.f));
		vec4 p = vec4(tpos, 1.f);
		for (int i = 0; i < 4; i++) { p = formula(p); }
		simdfloat fr = (length(max(vec2(0.f), p.yz() - 1.5f)) - 1.f) / p.w;
		simdfloat ro = max(abs(pos.x + 1.f) - .3f, pos.y - .35f);
		ro = max(ro, -max(abs(pos.x + 1.f) - .1f, pos.y - .5f));
		pos.z = abs(.25f - mod(pos.z, .5f));
		ro = max(ro, -max(abs(pos.z) - .2f, pos.y - .3f));
		ro = max(ro, -max(abs(pos.z) - .01f, -pos.y + .32f));
		simdfloat d = min(fr, ro);
		return d;
	}


	// Camera path
	vec3 path(simdfloat ti) {
		ti *= 1.5f;
		vec3 p = vec3(sin(ti), (1.f - sin(ti * 2.f)) * .5, -ti * 5.f) * .5;
		return p;
	}

	// Calc normals, and here is edge detection, set to variable "edge"

	vec3 normal(vec3 p) {
		vec3 e = vec3(0.0f, det * 5.f, 0.0f);

		simdfloat d1 = de(p - e.yxx()), d2 = de(p + e.yxx());
		simdfloat d3 = de(p - e.xyx()), d4 = de(p + e.xyx());
		simdfloat d5 = de(p - e.xxy()), d6 = de(p + e.xxy());
		simdfloat d = de(p);
		edge = abs(d - 0.5f * (d2 + d1)) + abs(d - 0.5f * (d4 + d3)) + abs(d - 0.5f * (d6 + d5));// edge finder
		edge = min(1.f, pow(edge, .55f) * 15.f);
		return normalize(vec3(d1 - d2, d3 - d4, d5 - d6));
	}

	// Raymarching and 2D graphics

	vec3 raymarch(vec3 from, vec3 dir)
	{
		edge = SIMDZERO;
		vec3 p, norm;
		simdfloat d = 100.f;
		simdfloat totdist = SIMDZERO;
		for (int i = 0; i < RAY_STEPS; i++)
		{
			// Note from simdshader author: there was a conditional statement to interrupt the loop when specific conditions were met, 
			// but you can't stop execution flow of some lanes in CPU SIMD logic like you do in glsl, so you need to use a testmask
			// to store the result of the condition, and then blend the branches afterward using blendv. 
			simdmask testmask = d > det && totdist < 25.0f;

			p = blendv(p, from + totdist * dir,  testmask);
			d = blendv(d, de(p), testmask);
			det = blendv(det, detail * exp(.13f * totdist), testmask);
			totdist = blendv(totdist, totdist + d,  testmask);

			if (maskNone(testmask)) // Though, breaking the loop is finally possible if the whole simd vector met the above condition. Here, maskNone check if the testmask is full of 0s
			{
				break;
			}
		}

		vec3 col = vec3(0.f);
		p -= (det - d) * dir;
		norm = normal(p);
#ifdef SHOWONLYEDGES
		col = 1.f - vec3(edge); // show wireframe version
#else
		col = (1.f - abs(norm)) * max(0.f, 1.f - edge * .8f); // set normal as color with dark edges
#endif
		totdist = clamp(totdist, 0.f, 26.f);
		dir.y -= .02f;
		simdfloat sunsize = (7.f);// -max(0.f, texture(iChannel0, vec2(.6, .2)).x) * 5.; // responsive sun size
		simdfloat an = atan(dir.x, dir.y) + iTime * 1.5f; // angle for drawing and rotating sun
		simdfloat s = pow(clamp(1.0f - length(dir.xy()) * sunsize - abs(.2f - mod(an, .4f)), 0.f, 1.f), .1f); // sun
		simdfloat sb = pow(clamp(1.0f - length(dir.xy()) * (sunsize - .2f) - abs(.2f - mod(an, .4f)), 0.f, 1.f), .1f); // sun border
		simdfloat sg = pow(clamp(1.0f - length(dir.xy()) * (sunsize - 4.5f) - .5f * abs(.2f - mod(an, .4f)), 0.f, 1.f), 3.f); // sun rays
		simdfloat y = mix(.45f, 1.2f, pow(smoothstep(0.f, 1.f, .75f - dir.y), 2.f)) * (1.f - sb * .5f); // gradient sky

		// set up background with sky and sun
		vec3 backg = vec3(0.5f, 0.f, 1.f) * ((1.f - s) * (1.f - sg) * y + (1.f - sb) * sg * vec3(1.f, .8f, 0.15f) * 3.f);
		backg += vec3(1.f, .9f, .1f) * s;
		backg = max(backg, sg * vec3(1.f, .9f, .5f));

		col = mix(vec3(1.f, .9f, .3f), col, exp(-.004f * totdist * totdist));// distant fading to sun color
		// if (totdist > 25.f) col = backg; // hit background
		simdmask testmask = totdist > 25.f;
		col = blendv(col, backg,  testmask);

		col = pow(col, vec3(GAMMA)) * BRIGHTNESS;
		col = mix(vec3(length(col)), col, SATURATION);
#ifdef SHOWONLYEDGES
		col = 1.f - vec3(length(col));
#else
		col *= vec3(1.f, .9f, .85f);

#endif
		return col;
	}

	// get camera position
	vec3 move(vec3& dir) {
		vec3 go = path(t);
		vec3 adv = path(t + .7f);
		simdfloat hd = de(adv);
		vec3 advec = normalize(adv - go);
		simdfloat an = adv.x - go.x; an *= min(1.f, abs(adv.z - go.z)) * sign(adv.z - go.z) * .7f;
		dir.xy(dir.xy() * mat2(cos(an), sin(an), -sin(an), cos(an)));
		an = advec.y * 1.7f;
		dir.yz(dir.yz() * mat2(cos(an), sin(an), -sin(an), cos(an)));
		an = atan(advec.x, advec.z);
		dir.xz(dir.xz() * mat2(cos(an), sin(an), -sin(an), cos(an)));
		return go;
	}

	vec4 mainImage(vec2 fragCoord)
	{
		det = SIMDZERO; // Problème de race condition sinon
		edge = SIMDZERO; // Problème de race condition sinon

		vec2 uv = fragCoord.xy() / iResolution.xy() * 2.f - 1.f;
		vec2 oriuv = uv;
		uv.y *= iResolution.y / iResolution.x;
		vec2 mouse = (iMouse.xy() / iResolution.xy() - .5f) * 3.f;

		// Note from simdshader author: another conditional statement here, replaced with testmask and blendv logic
		// if (iMouse.z < 1.f) mouse = vec2(0.f, -0.05);
		simdmask testmask = iMouse.z < 1.f;
		mouse = blendv(mouse, vec2(0.f, -0.05f),  testmask);

		simdfloat fov = .9f - max(0.f, .7f - iTime * .3f);
		vec3 dir = normalize(vec3(uv * fov, 1.f));

		// dir.yz(dir.yz()* rot(mouse.y)) ;
		// dir.xz(dir.xz()* rot(mouse.x)) ;
		vec3 from = origin + move(dir);

		vec3 color = raymarch(from, dir);

#ifdef BORDER
		color = mix(vec3(0.f), color, pow(max(0.f, .95f - length(oriuv * oriuv * oriuv * vec2(1.05f, 1.1f))), .3f));
#endif

		return vec4(color, 1.f);
	}


}
