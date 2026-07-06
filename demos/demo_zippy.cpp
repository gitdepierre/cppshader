#include "demos.h"

namespace Zippy
{
	// https://www.shadertoy.com/view/XXyGzh Zippy char original version, by SnoopethDuckDuck
    // Code has been modified a bit to fit library constraints

    vec4 mainImage(vec2 u)
    {
        vec2 v = iResolution.xy(),
            w,
            k = u = .2 * (u + u - v) / v.y;

        vec4 o = vec4(1, 2, 3, 0);
        float i = 0;
        for (simdfloat a = .5f, t = iTime;
            ++i < 19.f;
            o += (1.f + cos(vec4(0.f, 1.f, 3.f, 0.f) + t))
            / length((1.f + i * dot(v, v)) * sin(w * 3.f - 9.f * u.yx() + t))
            )
            v = cos(++t - 7.f * u * pow(a += .03f, i)) - 5.f * u,
            u *= mat2(cos(i + t * .02f - vec4(0.f, 11.f, 33.f, 0.f))),
            u += .005f * tanh(40.f * dot(u, u) * cos(1e2f * u.yx() + t))
            + .2f * a * u
            + .003f * cos(t + 4.f * exp(-.01f * dot(o, o))),
            w = u / (1.f - 2.f * dot(u, u));

        o = pow(o = 1.f - sqrt(exp(-o * o * o / 2e2f)), .3f * o / o)
            - dot(k -= u, k) / 250.f;

        return o;
    }
}
