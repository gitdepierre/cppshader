#include "demos.h"

namespace Vortex
{
	// https://www.shadertoy.com/view/XlfBR7 Tribute to Marc-Antoine Mathieu, by leon
	// Code has been modified a bit to fit library constraints
// Raymarching sketch inspired by the work of Marc-Antoine Mathieu
// Leon 2017-11-21
// using code from IQ, Mercury, LJ, Duke, Koltes

// tweak it
#define donut 30.f
#define cell 4.f
#define height 2.f
#define thin .04f
#define radius 15.f
#define speed 1.f

#define STEPS 100.f
#define VOLUME 0.001f
#define PI 3.14159f
#define TAU (2.f*PI)
#define time iTime

// raymarching toolbox
    simdfloat rng(vec2 seed) { return fract(sin(dot(seed * .1684, vec2(54.649, 321.547))) * 450315.); }
    mat2 rot(simdfloat a) { simdfloat c = cos(a), s = sin(a); return mat2(c, -s, s, c); }
    simdfloat sdSphere(vec3 p, simdfloat r) { return length(p) - r; }
    simdfloat sdCylinder(vec2 p, simdfloat r) { return length(p) - r; }
    simdfloat sdDisk(vec3 p, vec3 s) { return max(max(length(p.xz()) - s.x, s.y), abs(p.y) - s.z); }
    simdfloat sdIso(vec3 p, simdfloat r) { return max(0.f, dot(p, normalize(sign(p)))) - r; }
    simdfloat sdBox(vec3 p, vec3 b) { vec3 d = abs(p) - b; return min(max(d.x, max(d.y, d.z)), 0.0f) + length(max(d, 0.0f)); }
    simdfloat sdTorus(vec3 p, vec2 t) { vec2 q = vec2(length(p.xz()) - t.x, p.y); return length(q) - t.y; }
    simdfloat amod(vec2& p, simdfloat count) { simdfloat an = TAU / count; simdfloat a = atan(p.y, p.x) + an / 2.; simdfloat c = floor(a / an); c = mix(c, abs(c), step(count * .5f, abs(c))); a = mod(a, an) - an / 2.; p.xy( vec2(cos(a), sin(a)) * length(p)); return c; }
    simdfloat amodIndex(vec2 p, simdfloat count) { simdfloat an = TAU / count; simdfloat a = atan(p.y, p.x) + an / 2.; simdfloat c = floor(a / an); c = mix(c, abs(c), step(count * .5f, abs(c))); return c; }
    simdfloat repeat(simdfloat v, simdfloat c) { return mod(v, c) - c / 2.; }
    vec2 repeat(vec2 v, vec2 c) { return mod(v, c) - c / 2.; }
    vec3 repeat(vec3 v, simdfloat c) { return mod(v, c) - c / 2.; }
    simdfloat smoo(simdfloat a, simdfloat b, simdfloat r) { return clamp(.5 + .5 * (b - a) / r, 0., 1.); }
    simdfloat smin(simdfloat a, simdfloat b, simdfloat r) { simdfloat h = smoo(a, b, r); return mix(b, a, h) - r * h * (1. - h); }
    simdfloat smax(simdfloat a, simdfloat b, simdfloat r) { simdfloat h = smoo(a, b, r); return mix(a, b, h) + r * h * (1. - h); }
    vec2 displaceLoop(vec2 p, simdfloat r) { return vec2(length(p.xy()) - r, atan(p.y, p.x)); }
    simdfloat map(vec3);
    simdfloat getShadow(vec3 pos, vec3 at, simdfloat k) {
        vec3 dir = normalize(at - pos);
        simdfloat maxt = length(at - pos);
        simdfloat f = 01.;
        simdfloat t = VOLUME * 50.;
        for (float i = 0.; i <= 1.; i += 1. / 15.) {
            simdfloat dist = map(pos + dir * t);

            //if (dist < VOLUME) return 0.;

			simdmask hit = dist < VOLUME;
            if (maskAll(hit)) return 0.;
            f = min(f, k * dist / t);
            t += dist;

			simdmask breakMask = t >= maxt;
            //if (t >= maxt) break;
			if (maskAll(breakMask)) break;
        }
        return f;
    }
    vec3 getNormal(vec3 p) { vec2 e = vec2(.01, 0); return normalize(vec3(map(p + e.xyy()) - map(p - e.xyy()), map(p + e.yxy()) - map(p - e.yxy()), map(p + e.yyx()) - map(p - e.yyx()))); }

    void camera(vec3& p) {
        p.xz(p.xz() * rot(PI / 8.)) ;
        p.yz(p.yz() * rot(PI / 6.)) ;
    }

    simdfloat windowCross(vec3 pos, vec4 size, simdfloat salt) {
        vec3 p = pos;
        simdfloat sx = size.x * (.6 + salt * .4);
        simdfloat sy = size.y * (.3 + salt * .7);
        vec2 sxy = vec2(sx, sy);
        p.xy( repeat(p.xy() + sxy / 2., sxy));
        simdfloat scene = sdBox(p, size.zyw() * 2.);
        scene = min(scene, sdBox(p, size.xzw() * 2.));
        scene = max(scene, sdBox(pos, size.xyw()));
        return scene;
    }

    simdfloat window(vec3 pos, vec2 dimension, simdfloat salt) {
        simdfloat thinn = .008;
        simdfloat depth = .04;
        simdfloat depthCadre = .06;
        simdfloat padding = .08;
        simdfloat scene = windowCross(pos, vec4(dimension, thinn, depth), salt);
        simdfloat cadre = sdBox(pos, vec3(dimension, depthCadre));
        cadre = max(cadre, -sdBox(pos, vec3(dimension - padding, depthCadre * 2.)));
        scene = min(scene, cadre);
        return scene;
    }

    simdfloat boxes(vec3 pos, simdfloat salt) {
        vec3 p = pos;
        simdfloat ry = cell * .43 * (.3 + salt);
        simdfloat rz = cell * .2 * (.5 + salt);
        simdfloat salty = rng(vec2(floor(pos.y / ry), floor(pos.z / rz)));
        pos.y = repeat(pos.y, ry);
        pos.z = repeat(pos.z, rz);
        simdfloat scene = sdBox(pos, vec3(.1 + .8 * salt + salty, .1 + .2 * salt, .1 + .2 * salty));
        scene = max(scene, sdBox(p, vec3(cell * .2)));
        return scene;
    }

    simdfloat map(vec3 pos) {
        vec3 camOffset = vec3(-4, 0, 0.);

        simdfloat scene = 1000.;
        vec3 p = pos + camOffset;
        simdfloat segments = PI * radius;
        simdfloat indexX, indexY, salt;
        vec2 seed;

        // donut distortion
        vec3 pDonut = p;
        pDonut.x += donut;
        pDonut.y += radius;
        pDonut.xz(displaceLoop(pDonut.xz(), donut));
        pDonut.z *= donut;
        pDonut.xzy(pDonut.xyz());
        pDonut.xz(pDonut.xz() * rot(time * .05 * speed));

        // ground
        p = pDonut;
        scene = min(scene, sdCylinder(p.xz(), radius - height));

        // walls
        p = pDonut;
        simdfloat py = p.y + time * speed;
        indexY = floor(py / (cell + thin));
        p.y = repeat(py, cell + thin);
        scene = min(scene, max(abs(p.y) - thin, sdCylinder(p.xz(), radius)));
        vec2 tempxz = p.xz();
        amod(tempxz, segments);
        p.xz(tempxz);
        p.x -= radius;
        scene = min(scene, max(abs(p.z) - thin, p.x));

        // horizontal windot
        p = pDonut;
        p.xz(p.xz() * rot(PI / segments)) ;
        py = p.y + time * speed;
        indexY = floor(py / (cell + thin));
        p.y = repeat(py, cell + thin);
        indexX = amodIndex(p.xz(), segments);
        tempxz = p.xz();
        amod(tempxz, segments);
        p.xz(tempxz);
        seed = vec2(indexX, indexY);
        salt = rng(seed);
        p.x -= radius;
        vec2 dimension = vec2(.75, .5);
        p.x += dimension.x * 1.5;
        scene = max(scene, -sdBox(p, vec3(dimension.x, .1, dimension.y)));
        scene = min(scene, window(p.xzy(), dimension, salt));

        // vertical window
        p = pDonut;
        py = p.y + cell / 2. + time * speed;
        indexY = floor(py / (cell + thin));
        p.y = repeat(py, cell + thin);
        indexX = amodIndex(p.xz(), segments);
        tempxz = p.xz();
        amod(tempxz, segments);
        p.xz(tempxz);
        seed = vec2(indexX, indexY);
        salt = rng(seed);
        p.x -= radius;
        dimension.y = 1.5;
        p.x += dimension.x * 1.25;
        scene = max(scene, -sdBox(p, vec3(dimension, .1)));
        scene = min(scene, window(p, dimension, salt));

        // elements
        p = pDonut;
        p.xz(p.xz() * rot(PI / segments));
        py = p.y + cell / 2. + time * speed;
        indexY = floor(py / (cell + thin));
        p.y = repeat(py, cell + thin);
        indexX = amodIndex(p.xz(), segments);

		tempxz = p.xz();
        amod(tempxz, segments);
		p.xz(tempxz);

        seed = vec2(indexX, indexY);
        salt = rng(seed);
        p.x -= radius - height;
        scene = min(scene, boxes(p, salt));

        return scene;
    }

    vec4 mainImage(vec2 coord) {

        vec2 uv = (coord.xy() - .5 * iResolution.xy()) / iResolution.y;
        vec3 eye = vec3(0, 0, -20);
        vec3 ray = normalize(vec3(uv, 1.3));
        camera(eye);
        camera(ray);
        simdfloat dither = rng(uv + fract(time));
        vec3 pos = eye;
        simdfloat shade = 0.;
        for (float i = 0.; i <= 1.; i += 1. / STEPS) {
            simdfloat dist = map(pos);

            
			simdmask hit = dist < VOLUME;
            simdmask shadeMask = shade == 0.0f;
            /*if (dist < VOLUME) {
            {
                shade = 1. - i;
                break;
            }*/
			shade = blendv(shade, 1.f - i, hit && shadeMask);
            if (maskAll(hit)) {
                break;
            }
            //dist *= .5 + .1 * dither;
           // pos += ray * dist;

			dist = blendv(dist * (.5f + .1f * dither), dist, hit && shadeMask);
			pos = blendv(pos + ray * dist, pos, hit && shadeMask);
        }
        vec3 light = vec3(40., 100., -10.);
        simdfloat shadow = getShadow(pos, light, 4.);
        vec4 color = vec4(1);
        color *= shade;
        color *= shadow;
        color = smoothstep(.0, .5, color);
        color.rgb(sqrt(color.rgb()));
        return color;
    }


}