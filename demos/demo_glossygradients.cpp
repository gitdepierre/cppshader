#include "demos.h"

namespace GlossyGradients
{
    // https://www.shadertoy.com/view/lX2GDR Glossy Gradients, by Peace
	// Code has been modified a bit to fit library constraints
    vec4 mainImage( vec2 fragCoord) {

        simdfloat mr = min(iResolution.x, iResolution.y);
        vec2 uv = (fragCoord * 2.0 - iResolution.xy()) / mr;

        simdfloat d = -iTime * 0.5;
        simdfloat a = 0.0;
        for (float i = 0.0; i < 8.0; ++i) {
            a += cos(i - d - a * uv.x);
            d += sin(uv.y * i + a);
        }
        d += iTime * 0.5;
        vec3 col = vec3(cos(uv * vec2(d, a)) * 0.6 + 0.4, cos(a + d) * 0.5 + 0.5);
        col = cos(col * cos(vec3(d, a, 2.5)) * 0.5 + 0.5);
        return vec4(col, 1);
    }
}