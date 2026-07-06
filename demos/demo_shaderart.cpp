#include "demos.h"

namespace ShaderArt
{
	// https://www.shadertoy.com/view/mtyGWy  Shader Art Coding Introduction, by kishimisu
	// Code has been modified a bit to fit library constraints

	vec3 palette(simdfloat t) {
		vec3 a = vec3(0.5f, 0.5f, 0.5f);
		vec3 b = vec3(0.5f, 0.5f, 0.5f);
		vec3 c = vec3(1.0f, 1.0f, 1.0f);
		vec3 d = vec3(0.263f, 0.416f, 0.557f);

		return a + b * cos(6.28318f * (c * t + d));
	}


	vec4 mainImage(vec2 fragCoord) {
		vec2 uv = (fragCoord * 2.0f - iResolution.xy()) / iResolution.y;
		vec2 uv0 = uv;
		vec3 finalColor = vec3(0.0);

		for (float i = 0.0; i < 4.0; i++) {
			uv = fract(uv * 1.5f) - 0.5f;

			simdfloat d = length(uv) * exp(-length(uv0));

			vec3 col = palette(length(uv0) + i * .4f + iTime * .4f);

			d = sin(d * 8.f + iTime) / 8.f;
			d = abs(d);

			d = pow(0.01f / d, 1.2f);

			finalColor += col * d;
		}

		return vec4(finalColor, 1.0);
	}
}
