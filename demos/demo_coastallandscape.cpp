#include "demos.h"

namespace CoastalLandscape
{
	// https:// www.shadertoy.com/view/fstyD4  Coastal Landscape, by bitless
	// Code has been modified a bit to fit library constraints

	// Author: bitless
	// Title: Coastal Landscape

	// Thanks to Patricio Gonzalez Vivo & Jen Lowe for "The Book of Shaders"
	// and Fabrice Neyret (FabriceNeyret2) for https:// shadertoyunofficial.wordpress.com/
	// and Inigo Quilez (iq) for  https:// iquilezles.org/www/index.htm
	// and whole Shadertoy community for inspiration.
#define p(t, a, b, c, d) ( a + b*cos( 6.28318f*(c*t+d) ) ) // IQ's palette function (https:// www.iquilezles.org/www/articles/palettes/palettes.htm)
#define sp(t) p(t,vec3(.26f,.76f,.77f),vec3(1.f,.3f,1.f),vec3(.8f,.4f,.7f),vec3(0.f,.12f,.54f)) // sky palette
#define hue(v) ( .6f + .76f * cos(6.3f*(v) + vec4(0.f,23.f,21.f,0.f) ) ) // hue

// "Hash without Sine", by Dave_Hoskins.
// https:// www.shadertoy.com/view/4djSRW
	simdfloat hash12(vec2 p)
	{
		vec3 p3 = fract(vec3(p.xyx()) * .1031f);
		p3 += dot(p3, p3.yzx() + 33.33f);
		return fract((p3.x + p3.y) * p3.z);
	}

	vec2 hash22(vec2 p)
	{
		vec3 p3 = fract(vec3(p.xyx()) * vec3(.1031f, .1030f, .0973f));
		p3 += dot(p3, p3.yzx() + 33.33f);
		return fract((p3.xx() + p3.yz()) * p3.zy());
	}
	// // // // // // // // // // // // 

	vec2 rotate2D(vec2 st, simdfloat a) {
		return  mat2(cos(a), -sin(a), sin(a), cos(a)) * st;
	}

	simdfloat st(simdfloat a, simdfloat b, simdfloat s) // AA bar
	{
		return smoothstep(a - s, a + s, b);
	}

	simdfloat noise(vec2 p) // gradient noise
	{
		vec2 i = floor(p);
		vec2 f = fract(p);

		vec2 u = f * f * (3.f - 2.f * f);

		return mix(mix(dot(hash22(i + vec2(0.f, 0.f)), f - vec2(0.f, 0.f)),
			dot(hash22(i + vec2(1.f, 0.f)), f - vec2(1.f, 0.f)), u.x),
			mix(dot(hash22(i + vec2(0.f, 1.f)), f - vec2(0.f, 1.f)),
				dot(hash22(i + vec2(1.f, 1.f)), f - vec2(1.f, 1.f)), u.x), u.y);
	}

	vec4 mainImage(vec2 g)
	{
		vec4 O;
		vec2 r = iResolution.xy()
			, uv = (g + g - r) / r.y
			, sun_pos = vec2(r.x / r.y * .42f, -.53f) // sun position
			, tree_pos = vec2(-r.x / r.y * .42f, -.2f) // tree position
			, sh, u, id, lc, t;

		vec3 f, c;
		simdfloat xd, yd, h, a, l;
		vec4 C;

		simdfloat sm = 3.f / r.y; // smoothness factor for AA

		sh = rotate2D(sun_pos, noise(uv + iTime * .25f) * .3f); // big noise on the sky

		// Note from simdshader author: conditional statements are complicated to use in SIMD logic, so i removed it here and below. For the rest of the code, i used testmasks
		// if (uv.y > -.4f) // drawing the sky
		{
			u = uv + sh;

			yd = (60.f); // number of rings

			id = vec2((length(u) + .01f) * yd, 0.f); // segment id: x - ring number, y - segment number in the ring
			xd = floor(id.x) * .09f; // number of ring segments
			h = (hash12(floor(id.xx())) * .5f + .25f) * (iTime + 10.f) * .25f; // ring shift
			t = rotate2D(u, h); // rotate the ring to the desired angle

			id.y = atan(t.y, t.x) * xd;
			lc = fract(id); // segment local coordinates
			id -= lc;

			// determining the coordinates of the center of the segment in uv space
			t = vec2(cos((id.y + .5f) / xd) * (id.x + .5f) / yd, sin((id.y + .5f) / xd) * (id.x + .5f) / yd);
			t = rotate2D(t, -h) - sh;

			h = noise(t * vec2(.5f, 1.f) - vec2(iTime * .2f, 0.f)) // clouds
				* step(-.25f, t.y); // do not draw clouds below -.25
			h = smoothstep(.052f, .055f, h);


			lc += (noise(lc * vec2(1.f, 4.f) + id)) * vec2(.7f, .2f); // add fine noise

			f = mix(sp(sin(length(u) - .1f)) * .35f, // sky background
				mix(sp(sin(length(u) - .1f) + (hash12(id) - .5f) * .15f), vec3(1.f), h), // mix sky color and clouds
				st(abs(lc.x - .5f), (.4f), sm * yd) * st(abs(lc.y - .5f), (.48f), sm * xd));
		};

		// if (uv.y < -.35f) // drawing water
		{

			simdfloat cld = noise(-sh * vec2(.5f, 1.f) - vec2(iTime * .2f, 0.f)); // cloud density opposite the center of the sun
			cld = 1.f - smoothstep(.0f, .15f, cld) * .5f;

			u = uv * vec2(1.f, 15.f);
			id = floor(u);

			for (float i = 1.f; i > -1.f; i--) // drawing a wave and its neighbors from above and below
			{
				// Code modification here: testmasks are used to store the result of the condition, and then branches are blended afterward using blendv
				simdmask waterMask = id.y + i < -5.f; // Storing the 

				// if (id.y + i < -5.f)
				{
					lc = fract(u) - .5f;
					lc.y = (lc.y + (sin(uv.x * 12.f - iTime * 3.f + id.y + i)) * .25f - i) * 4.f; // set the waveform and divide it into four strips
					h = hash12(vec2(id.y + i, floor(lc.y))); // the number of segments in the strip and its horizontal offset

					xd = 6.f + h * 4.f;
					yd = (30.f);
					lc.x = uv.x * xd + sh.x * 9.f; // divide the strip into segments
					lc.x += sin(iTime * (.5f + h * 2.f)) * .5f; // add a cyclic shift of the strips horizontally
					h = .8f * smoothstep(5.f, .0f, abs(floor(lc.x))) * cld + .1f; // determine brightness of the sun track
					vec3 tempF = mix(f, mix(vec3(0.f, .1f, .5f), vec3(.35f, .35f, 0.f), h), st(lc.y, SIMDZERO, sm * yd)); // mix the color of the water and the color of the track for the background of the water
					lc += noise(lc * vec2(3.f, .5f)) * vec2(.1f, .6f); // add fine noise to the segment

					tempF = mix(tempF,                                                                         // mix the background color
						mix(hue(hash12(floor(lc)) * .1f + .56f).rgb() * (1.2f + floor(lc.y) * .17f), vec3(1.f, 1.f, 0.f), h)     // and the stroke color
						, st(lc.y, SIMDZERO, sm * xd)
						* st(abs(fract(lc.x) - .5f), (.48f), sm * xd) * st(abs(fract(lc.y) - .5f), (.3f), sm * yd)
					);

					f = blendv(f, tempF, waterMask);
				}
			}
		}

		O = vec4(f, 1.f);

		// // // // // // // // // // // drawing the grass
		a = SIMDZERO;
		u = uv + noise(uv * 2.f) * .1f + vec2(0.f, sin(uv.x * 1.f + 3.f) * .4f + .8f);

		f = mix(vec3(.7f, .6f, .2f), vec3(0.f, 1.f, 0.f), sin(iTime * .2f) * .5f + .5f); // color of the grass, changing from green to yellow and back again
		O = mix(O, vec4(f * .4f, 1.f), step(u.y, .0f)); // draw grass background

		xd = (60.f);  // grass size
		u = u * vec2(xd, xd / 3.5f);

		vec2 tempID = id;
		vec2 tempLC = lc;
		simdfloat tempH = h;
		vec2 tempT = t;
		simdfloat tempL;
		simdfloat tempA = a;
		vec3 tempF = f;
		vec4 tempC;
		vec4 tempO = O;

		// Code modification : testmask + blendv logic again.
		simdmask grassMask = u.y < 1.2f;
		// 	if (u.y < 1.2f)
		{
			for (float y = 0.f; y > -3.f; y--)
			{
				for (float x = -2.f; x < 3.f; x++)
				{
					tempID = floor(u) + vec2(x, y);
					tempLC = (fract(u) + vec2(1.f - x, -y)) / vec2(5.f, 3.f);
					tempH = (hash12(tempID) - .5f) * .25f + .5f; // shade and length for an individual blade of grass

					tempLC -= vec2(.3f, .5f - tempH * .4f);
					tempLC.x += sin(((iTime * 1.7f + tempH * 2.f - tempID.x * .05f - tempID.y * .05f) * 1.1f + tempID.y * .5f) * 2.f) * (tempLC.y + .5f) * .5f;
					tempT = abs(tempLC) - vec2(.02f, .5f - tempH * .5f);
					tempL = length(max(tempT, 0.f)) + min(max(tempT.x, tempT.y), 0.f); // distance to the segment (blade of grass)

					tempL -= noise(tempLC * 7.f + tempID) * .1f; // add fine noise
					tempC = vec4(f * .25f, st(tempL, (.1f), sm * xd * .09f)); // grass outline
					tempC = mix(tempC, vec4(f                  // grass foregroud
						* (1.2f + tempLC.y * 2.f)  // the grass is a little darker at the root
						* (1.8f - tempH * 2.5f), 1.f)    // brightness variations for individual blades of grass
						, st(tempL, (.04f), sm * xd * .09f));

					tempO = mix(tempO, tempC, tempC.a * step(tempID.y, -1.f));
					tempA = max(tempA, tempC.a * step(tempID.y, -5.f));  // a testmask to cover the trunk of the tree with grasses in the foreground
				}
			}
		}
		id = blendv(id, tempID, grassMask);
		lc = blendv(lc, tempLC, grassMask);
		h = blendv(h, tempH, grassMask);
		t = blendv(t, tempT,  grassMask);
		l = blendv(l, tempL, grassMask);
		a = blendv(a, tempA, grassMask);
		f = blendv(f, tempF, grassMask);
		C = blendv(C, tempC,  grassMask);
		O = blendv(O, tempO,  grassMask);

		simdfloat T = sin(iTime * .5f); // tree swing cycle

		// 	if (abs(uv.x + tree_pos.x - .1f - T * .1f) < .6f) // drawing the tree
		{
			u = uv + tree_pos;
			// draw the trunk of the tree first
			u.x -= sin(u.y + 1.f) * .2f * (T + .75f); // the trunk bends in the wind
			u += noise(u * 4.5f - 7.f) * .25f; // trunk curvature

			xd = (10.f), yd = (60.f);
			t = u * vec2(1.f, yd); // divide the trunk into segments
			h = hash12(floor(t.yy())); // horizontal shift of the segments and the color tint of the segment
			t.x += h * .01f;
			t.x *= xd;

			lc = fract(t); // segment local coordinates

			simdfloat m = st(abs(t.x - .5f), (.5f), sm * xd) * step(abs(t.y + 20.f), 45.f); // trunk testmask
			C = mix(vec4(.07f) // outline color
				, vec4(.5f, .3f, 0.f, 1.f) * (.4f + h * .4f) // foreground color
				, st(abs(lc.y - .5f), (.4f), sm * yd) * st(abs(lc.x - .5f), (.45f), sm * xd));
			C.a = m;

			xd = (30.f), yd = (15.f);

			for (float xs = 0.f; xs < 4.f; xs++) // drawing four layers of foliage
			{
				u = uv + tree_pos + vec2(xs / xd * .5f - (T + .75f) * .15f, -.7f); // crown position
				u += noise(u * vec2(2.f, 1.f) + vec2(-iTime + xs * .05f, 0.f)) * vec2(-.25f, .1f) * smoothstep(.5f, -1.f, u.y + .7f) * .75f; // leaves rippling in the wind

				t = u * vec2(xd, 1.f);
				h = hash12(floor(t.xx()) + xs * 1.4f); // number of segments for the row

				yd = 5.f + h * 7.f;
				t.y *= yd;

				sh = t;
				lc = fract(t);
				h = hash12(t - lc); // segment color shade


				t = (t - lc) / vec2(xd, yd) + vec2(0, .7f);

				m = (step(0.f, t.y) * step(length(t), .45f) // the shape of the crown - the top
					+ step(t.y, 0.f) * step(-0.7f + sin((floor(u.x) + xs * .5f) * 15.f) * .2f, t.y)) // the bottom
					* step(abs(t.x), .5f) // crown size horizontally
					* st(abs(lc.x - .5f), (.35f), sm * xd * .5f);

				lc += noise((sh)*vec2(1.f, 3.f)) * vec2(.3f, .3f); // add fine noise

				f = hue((h + (sin(iTime * .2f) * .5f + .5f)) * .2f).rgb() - t.x; // color of the segment changes cyclically

				C = mix(C,
					vec4(mix(f * .15f, f * .6f * (.7f + xs * .2f), // mix outline and foreground color
						st(abs(lc.y - .5f), (.47f), sm * yd) * st(abs(lc.x - .5f), (.2f), sm * xd)), m)
					, m);
			}

			return mix(O, C, C.a * (1.f - a));
		}
	}

}
