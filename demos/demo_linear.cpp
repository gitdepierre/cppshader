#include "demos.h"

namespace Linear
{
	// https:// www.shadertoy.com/view/ssdXRs  Linear transformation, by trinketMage
	// Code has been modified a bit to fit library constraints

	vec4 mainImage(vec2 fragCoord)
	{
		vec2 uv = fragCoord / iResolution.x;
		uv -= 0.5;
		float count = 16.;

		mat2 transformation = mat2(
			cos(iTime), -sin(iTime),
			sin(iTime), cos(iTime)
		);
		vec2 mvUv = transformation * uv;

		vec2 cell = fract(mvUv * count);

		return vec4(cell.x * cell.y);

	}
}
