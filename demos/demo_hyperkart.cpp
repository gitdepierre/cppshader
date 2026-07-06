#include "demos.h"

namespace Hyperkart
{
	// https://www.shadertoy.com/view/scS3Wm Hyperkart, by diatribes
	// Code has been modified a bit to fit library constraints

#define T (sin(iTime*.6)*64.+iTime*2e2)
#define P(z) (vec3(cos((z)*.015)*16.+cos((z) * .006)  *64., \
                   cos((z)*.011)*24.+cos((z) * .009) * 32., (z)))
#define R(a) mat2(cos(a+vec4(0,33,11,0)))
#define N normalize

    simdfloat boxen(vec3 p) {

        p = abs(fract(p / 4e1) * 4e1 - 2e1) - 2.;
        return min(p.x, min(p.y, p.z));

    }

    thread_local vec4 lights;
    simdfloat map(vec3 p) {
        vec3 q = P(p.z);
        simdfloat m, g = q.y - p.y + 6.;
        m = boxen(p);
        p.xy(p.xy() - q.xy());

        // squiggly line along z
        simdfloat red, blue;
        simdfloat e = min(red = length(p.xy() - sin(p.y / 12. + vec2(5., 1.)) * 12.) - 1.,
            blue = length(p.xy() - sin(p.y / 12. + vec2(0, 1.)) * 12.) - 1.);

        lights += vec4(2, 1e1, 1e1, 0) / (.1 + abs(red) / 1e1);
        lights += vec4(1e1, 2, 1e1, 0) / (.1 + abs(blue) / 1e1);;

        p = abs(p);

        simdfloat tex = abs(length(sin(p * cos(p.yzx() / 3e1) * 4.) / ((p+0.00001f) * 4.)));
        simdfloat tun = min(64. - p.x - p.y + m, 32. - p.y - m);

        simdfloat d = max(min(m, g), tun) - tex;
        return min(e, d);
    }

    vec4 mainImage(vec2 u) {
        lights = 0;
        float i = 0;
        simdfloat s, d;
        vec3  r = iResolution;

        u = (u - r.xy() / 2.) / r.y;

        u.y -= .2;
        vec4 o = vec4(0);
        vec3  p = P(T), ro = p,
            Z = N(P(T + 1e1) - p),
            X = N(vec3(Z.z, 0.0f, -Z)),
            D = N(vec3(R(sin(T * .005) * .4) * u, 1)
                * mat3(-X, cross(X, Z), Z));

        for (; i++ < 128.;)
            p = ro + D * d,
            d += s = map(p) * .8,
            o += lights + 1. / max(s, .01f);


        // normal
        // tetrahedron technique: https://iquilezles.org/articles/normalsSDF/
        const simdfloat h = 0.005;
        const vec2 k = vec2(1, -1);
        vec3 n = N(k.xyy() * map(p + k.xyy() * h) +
            k.yyx() * map(p + k.yyx() * h) +
            k.yxy() * map(p + k.yxy() * h) +
            k.xxx() * map(p + k.xxx() * h));

        // diffuse
        o *= (.1 + max(dot(n, -D), 0.f));

        // reflection march
        vec4 ref;
        lights = vec4(0);
        for (p += n * .05, D = reflect(D, n), s = i = 0.; i++ < 4e1; )
            p += D * s,
            s = map(p) * .8,
            ref += lights + 1. / max(s, .01f);

        o += o * ref;
        o = tanh(o / 6e6 / d);
        return o;
    }
}