#include "demos.h"

namespace Fovea
{
	// https:// www.shadertoy.com/view/4dsXzM Fovea detector, by nimitz
	// Code has been modified a bit to fit library constraints

#define scale 90.f

#define thickness 0.0f
#define lengt 0.13f
#define layers 15.f
#define time iTime*3.

	vec2 hash12(simdfloat p)
	{
		return fract(vec2(sin(p * 591.32f), cos(p * 391.32f)));
	}

	simdfloat hash21(vec2 n)
	{
		return fract(sin(dot(n, vec2(12.9898f, 4.1414f))) * 43758.5453f);
	}

	vec2 hash22(vec2 p)
	{
		p = vec2(dot(p, vec2(127.1f, 311.7f)), dot(p, vec2(269.5f, 183.3f)));
		return fract(sin(p) * 43758.5453f);
	}

	mat2 makem2(simdfloat theta)
	{
		simdfloat c = cos(theta);
		simdfloat s = sin(theta);
		return mat2(c, -s, s, c);
	}

	simdfloat field1(vec2 p)
	{
		vec2 n = floor(p) - 0.5f;
		vec2 f = fract(p) - 0.5f;
		vec2 o = hash22(n) * .35f;
		vec2 r = -f - o;
		r *= makem2(time + hash21(n) * 3.14f);

		simdfloat d = 1.0f - smoothstep(thickness, thickness + 0.09f, abs(r.x));
		d *= 1.f - smoothstep(lengt, lengt + 0.02f, abs(r.y));

		simdfloat d2 = 1.0f - smoothstep(thickness, thickness + 0.09f, abs(r.y));
		d2 *= 1.f - smoothstep(lengt, lengt + 0.02f, abs(r.x));

		return max(d, d2);
	}

	vec4 mainImage(vec2 fragCoord)
	{
		vec2 p = fragCoord.xy() / iResolution.xy() - 0.5f;
		p.x *= iResolution.x / iResolution.y;

		simdfloat mul = (iResolution.x + iResolution.y) / scale;

		vec3 col = vec3(0);
		for (float i = 0.; i < layers; i++)
		{
			vec2 ds = hash12((i) * 2.5f) * .20f;
			col = max(col, field1((p + ds) * mul) * (sin(ds.x * 5100.f + vec3(1.f, 2.f, 3.5)) * .4f + .6f));
		}

		return vec4(col, 1.0f);
	}
}
