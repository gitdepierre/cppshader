#include "demos.h"

namespace RoadRibbon
{
	// https:// www.shadertoy.com/view/MsfGzr To the road of ribbon, by XT95
	// Code has been modified a bit to fit library constraints

	simdfloat tunnel(vec3 p)
	{
		return cos(p.x) + cos(p.y * 1.5f) + cos(p.z) + cos(p.y * 20.f) * .05f;
	}

	simdfloat ribbon(vec3 p)
	{
		return length(max(abs(p - vec3(cos(p.z * 1.5f) * .3f, -.5f + cos(p.z) * .2f, .0f)) - vec3(.125f, .02f, iTime + 3.f), vec3(.0)));
	}

	simdfloat scene(vec3 p)
	{
		return min(tunnel(p), ribbon(p));
	}

	vec3 getNormal(vec3 p)
	{
		vec3 eps = vec3(.1, 0, 0);
		return normalize(vec3(scene(p + eps.xyy()), scene(p + eps.yxy()), scene(p + eps.yyx())));
	}

	vec4 mainImage(vec2 fragCoord)
	{
		vec2 v = -1.0f + 2.0f * fragCoord.xy() / iResolution.xy();
		v.x = v.x * iResolution.x / iResolution.y;

		vec4 color = vec4(0.0);
		vec3 org = vec3(sin(iTime) * .5f, cos(iTime * .5) * .25 + .25, iTime);
		vec3 dir = normalize(vec3(v.x * 1.6f, v.y, 1.0f));
		vec3 p = org, pp;
		simdfloat d = SIMDZERO;

		// First raymarching
		for (int i = 0; i < 64; i++)
		{
			d = scene(p);
			p = p + (d * dir);
		}
		pp = p;
		simdfloat f = length(p - org) * (0.02);

		// Second raymarching (reflection)
		dir = reflect(dir, getNormal(p));
		p = p + dir;
		for (int i = 0; i < 32; i++)
		{
			d = scene(p);
			p = p + (d * dir);
		}
		color = max(dot(getNormal(p), vec3(.1f, .1f, .0f)), .0f) + vec4(.3, cos(iTime * .5f) * .5f + .5f, sin(iTime * .5f) * .5f + .5f, 1.f) * min(length(p - org) * .04f, 1.f);

		// Ribbon Color
		// Note of simdshader author : replaced conditional statement with blendv logic
		color = blendv( color, mix(color, vec4(cos(iTime * .3f) * .5f + .5f, cos(iTime * .2f) * .5f + .5f, sin(iTime * .3f) * .5f + .5f, 1.f), .3f), tunnel(pp) > ribbon(pp));

		// Final Color
		vec4 fcolor = ((color + vec4(f)) + (1.f - min(pp.y + 1.9f, 1.f)) * vec4(1.f, .8f, .7f, 1.f)) * min(iTime * .5f, 1.f);
		return vec4(fcolor.xyz(), 1.0);
	}
}
