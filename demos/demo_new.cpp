#include "demos.h"

namespace New
{
	// https://www.shadertoy.com/view/ssdXRs New shader from shadertoy
	// Code has been modified a bit to fit library constraints

	vec4 mainImage(vec2 fragCoord)
	{
		// Normalized pixel coordinates (from 0 to 1)
		vec2 uv = fragCoord / iResolution.xy();

		// Time varying pixel color
		vec3 col = 0.5 + 0.5 * cos(iTime + uv.xyx() + vec3(0, 2, 4));

		// Output to screen
		return vec4(col, 1.0);

	}
}


