#include "demos.h"

namespace WickedFractal
{
    // https://www.shadertoy.com/view/scfGzf Wicked Fractal Flight, by diatribes
    // Code has been modified a bit to fit library constraints


#define T (iTime*2e1 + 12. + 2e1*sin(iTime*.5))
#define P(z) (vec3(cos((z) * .03) * 16.,cos((z) * 0.02) * 32., (z)))
#define R(a) mat2(cos(a+vec4(0, 33, 11, 0)))
#define N normalize

    simdfloat apollonian(vec3 p) {
        simdfloat  w, l;
        float s = 0;
        p /= 8.;

        p *= vec3(.6, .5, .25);
        p += cos(p.yzx() * 6. + p.xzy() * 2. + p.zxy() * 4.) * .1;

        for (s = 0., w = .2; s++ < 8.; p *= l, w *= l)
            p = abs(sin(p)) - 1.,
            l = 1.35f / dot(p, p);

        return length(p * 8.) / w - .0002;
    }

    simdfloat gyroid(vec3 p) {
        return 16.f * dot(sin(p / 64.), cos(p.yzx() / 12.));
    }

    simdfloat map(vec3 p) {
        return max(gyroid(p),
            max((cos(p.z * .2f) + 2.f) - length((p - P(p.z)).xy()), apollonian(p)));
    }

    vec4 mainImage(vec2 u) {
        vec4 o;
        simdfloat s = 0, d = 0, a = 0;
        float i = 0;
        vec3 r = iResolution;
        u = (u - r.xy() / 2.0) / r.y;

        vec3 p = P(T * 2.0),
            Z = N(P(T * 2.0 + 7.0) - p),
            X = N(vec3(Z.z, 0, -Z)),
            D = N(vec3(R(sin(iTime * 0.3) * .6) * u, 1) * mat3(-X, cross(X, Z), Z));

        for (o = vec4(0); i++ < 128.;) {
            p += D * s,
                d += s = map(p) * .7,
                o += 2. * vec4(8, 2, 1, 0) + .04 * vec4(1, 2, 6, 4) / (.001 + abs(s));
        }

        o = tanh(o / 1e5 * exp(vec4(3, 2, 1, 0) * d / i));
        return o;
    }

}