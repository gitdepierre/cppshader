#include "demos.h"

namespace Creation
{
	// https:// www.shadertoy.com/view/XsXXDn Creation by Silexars, by Danguafer
	// Code has been modified a bit to fit library constraints

#define t iTime
#define r iResolution.xy()

	vec4 mainImage(vec2 fragCoord) {
		vec3 c;
		simdfloat l, z = t;
		for (int i = 0; i < 3; i++) {
			vec2 uv, p = fragCoord.xy() / r;
			uv = p;
			p -= .5f;
			p.x *= r.x / r.y;
			z += .07f;
			l = length(p);
			uv += p / l * (sin(z) + 1.f) * abs(sin(l * 9.f - z - z));
			c[i] = .01f / length(mod(uv, 1.f) - .5f);
		}
		return vec4(c / l, t);
	}

}
