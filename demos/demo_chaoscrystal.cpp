#include "demos.h"

namespace ChaosCrystal
{
	// https:// www.shadertoy.com/view/scfGWr  Chaos Crystal, by diatribe
	// Code has been modified a bit to fit library constraints

	vec4 mainImage(vec2 u) {
		vec4 o = vec4(0);
		simdfloat d = 0;
		simdfloat s = 0;
		float i = 0;
		vec3 p = iResolution;
		vec3 r = iResolution;
		vec3 a = cos(vec3(2.0f, 3.0f, 1.0f) + iTime / 3.f);
		for (o *= i; i++ < 1e2f;
			o += 6.f * vec4(1.0f, 2.0f, 8.0f, 0.0f) + (1.f + cos(.3f * i + vec4(6.0f, 4.0f, 2.0f, 0.0f))) / s
			+ min(vec4(8.0f, 2.0f, 5.0f, 0.0f) * d, 2e2f)
			)
			p = vec3((u + u - r.xy()) / r.y * d, d - 5.f),
			p = abs(a * dot(a, p) - cross(a, p)),
			s = max(p.x, max(p.y, p.z)) - .8f - .3f * sin(sin(iTime) + iTime / 2.f),
			p += cos(iTime * 2.f + p.yzx() / 2.f),
			p = abs(fract(p / s) * s - s * .5f),
			s = min(max(p.x, p.y), min(max(p.x, p.z), max(p.y, p.z))) - s / 12.f,
			s = .001f + .3f * abs(s),
			d += s;
		return tanh(o * o / 6e8f);
	}
}
