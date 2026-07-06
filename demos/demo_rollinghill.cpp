#include "demos.h"

namespace RollingHill
{
	// https://www.shadertoy.com/view/Xsf3zX Rolling Hill, by Dave_Hoskins
	// Code has been modified a bit to fit library constraints

	// Rolling hills. By David Hoskins, November 2013.
	// License Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License.

	// https://www.shadertoy.com/view/Xsf3zX

	// v.2.00 Uses eiffie's 'Circle of Confusion' function
	//		  for blurred ray marching into the grass.
	// v.1.02 Camera aberrations.
	// v.1.01 Added better grass, with wind movement.

	// For red/cyan 3D...
	//#define STEREO

#define THRESHOLD .003
#define MOD2 vec2(3.07965, 7.4235)
	thread_local simdfloat PI = 4.0 * atan(1.0);
	thread_local vec3 sunLight = normalize(vec3(0.35, 0.2, 0.3));
	thread_local vec3 cameraPos;
	thread_local vec3 sunColour = vec3(1.0, .75, .6);
	const mat2 rotate2D = mat2(1.932, 1.623, -1.623, 1.952);
	simdfloat gTime = 0.0;

	//--------------------------------------------------------------------------
	// Noise functions...
	simdfloat Hash(simdfloat p)
	{
		vec2 p2 = fract(vec2(p) / MOD2);
		p2 += dot(p2.yx(), p2.xy() + 19.19);
		return fract(p2.x * p2.y);
	}

	//--------------------------------------------------------------------------
	simdfloat Hash(vec2 p)
	{
		p = fract(p / MOD2);
		p += dot(p.xy(), p.yx() + 19.19);
		return fract(p.x * p.y);
	}


	//--------------------------------------------------------------------------
	simdfloat Noise(vec2 x)
	{
		vec2 p = floor(x);
		vec2 f = fract(x);
		f = f * f * (3.0 - 2.0 * f);
		simdfloat n = p.x + p.y * 57.0;
		simdfloat res = mix(mix(Hash(n + 0.0), Hash(n + 1.0), f.x),
			mix(Hash(n + 57.0), Hash(n + 58.0), f.x), f.y);
		return res;
	}

	//  2 out, 2 in...
	vec2 hash22(vec2 p)
	{
		vec3 p3 = fract(vec3(p.xyx()) * vec3(.1031, .1030, .0973));
		p3 += dot(p3, p3.yzx() + 33.33);
		return fract((p3.xx() + p3.yz()) * p3.zy());

	}

	//--------------------------------------------------------------------------
	vec2 Voronoi(vec2 x)
	{
		vec2 p = floor(x);
		vec2 f = fract(x);
		simdfloat res = 100.0;
		vec2 id;
		for (int j = -1; j <= 1; j++)
			for (int i = -1; i <= 1; i++)
			{
				vec2 b = vec2(simdfloat(i), simdfloat(j));
				vec2 r = b - f + hash22(p + b);
				simdfloat d = dot(r, r);

				/*
				if (d < res)
				{
					res = d;
					id.x = Hash(p + b);
				}*/
				simdmask tempMask = d < res;
				if (!maskNone(tempMask))
				{
					res = blendv(res, d, tempMask);
					id.x = blendv(id.x, Hash(p + b), tempMask);
				}
				
			}
		return vec2(max(.4 - sqrt(res), 0.0), id.x);
	}




	//--------------------------------------------------------------------------
	vec2 Terrain(vec2 p)
	{
		simdfloat type = 0.0;
		vec2 pos = p * 0.003;
		simdfloat w = 50.0;
		simdfloat f = .0;
		for (int i = 0; i < 3; i++)
		{
			f += Noise(pos) * w;
			w = w * 0.62;
			pos *= 2.5;
		}

		return vec2(f, type);
	}

	//--------------------------------------------------------------------------
	vec2 Map(vec3 p)
	{
		vec2 h = Terrain(p.xz());
		return vec2(p.y - h.x, h.y);
	}

	//--------------------------------------------------------------------------
	simdfloat FractalNoise(vec2 xy)
	{
		simdfloat w = .7;
		simdfloat f = 0.0;

		for (int i = 0; i < 3; i++)
		{
			f += Noise(xy) * w;
			w = w * 0.6;
			xy = 2.0 * xy;
		}
		return f;
	}

	//--------------------------------------------------------------------------
	// Grab all sky information for a given ray from camera
	vec3 GetSky(vec3 rd)
	{
		simdfloat sunAmount = max(dot(rd, sunLight), 0.0f);
		simdfloat v = pow(1.0 - max(rd.y, 0.0f), 6.);
		vec3  sky = mix(vec3(.1, .2, .3), vec3(.32, .32, .32), v);
		sky = sky + sunColour * sunAmount * sunAmount * .25;
		sky = sky + sunColour * min(pow(sunAmount, 800.0) * 1.5, .3);
		return clamp(sky, 0.0, 1.0);
	}

	//--------------------------------------------------------------------------
	// Merge grass into the sky background for correct fog colouring...
	vec3 ApplyFog(vec3  rgb, simdfloat dis, vec3 dir)
	{
		simdfloat fogAmount = clamp(dis * dis * 0.0000012f, 0.0f, 1.0f);
		return mix(rgb, GetSky(dir), fogAmount);
	}

	//--------------------------------------------------------------------------
	vec3 DE(vec3 p)
	{
		simdfloat base = Terrain(p.xz()).x - 1.9;
		simdfloat height = Noise(p.xz() * 2.0) * .75 + Noise(p.xz()) * .35 + Noise(p.xz() * .5) * .2;
		//p.y += height;
		simdfloat y = p.y - base - height;
		y = y * y;
		vec2 ret = Voronoi((p.xz() * 2.5 + sin(y * 2.0 + p.zx() * 12.3) * .12 + vec2(sin(iTime * 1.3 + 1.5 * p.z), sin(iTime * 2.6 + 1.5 * p.x)) * y * .5));
		simdfloat f = ret.x * .65 + y * .5;
		return vec3(y - f * 1.4, clamp(f * 1.1, 0.0, 1.0), ret.y);
	}

	//--------------------------------------------------------------------------
	// eiffie's code for calculating the aperture size for a given distance...
	simdfloat CircleOfConfusion(simdfloat t)
	{
		return max(t * .04, (2.0 / iResolution.y) * (1.0 + t));
	}

	//--------------------------------------------------------------------------
	simdfloat Linstep(simdfloat a, simdfloat b, simdfloat t)
	{
		return clamp((t - a) / (b - a), 0.f, 1.f);
	}

	//--------------------------------------------------------------------------
	vec3 GrassBlades(vec3 rO, vec3 rD, vec3 mat, simdfloat dist)
	{
		simdfloat d = 0.0;
		// Only calculate cCoC once is enough here...
		simdfloat rCoC = CircleOfConfusion(dist * .3);
		simdfloat alpha = 0.0;

		vec4 col = vec4(mat * 0.15, 0.0);

		for (int i = 0; i < 15; i++)
		{
			//if (col.w > .99) break;
			if (maskAll(col.w > .99)) break;

			vec3 p = rO + rD * d;

			vec3 ret = DE(p);
			ret.x += .5 * rCoC;

			
			/*if (ret.x < rCoC)
			{
				alpha = (1.0 - col.y) * Linstep(-rCoC, rCoC, -ret.x);//calculate the mix like cloud density
				// Mix material with white tips for grass...
				vec3 gra = mix(mat, vec3(.35, .35, min(pow(ret.z, 4.0) * 35.0, .35)), pow(ret.y, 9.0) * .7) * ret.y;
				col += vec4(gra * alpha, alpha);
			}*/
			simdmask tempMask = ret.x < rCoC;
			if (!maskNone(tempMask))
			{
				alpha = blendv(alpha, (1.0f - col.y) * Linstep(-rCoC, rCoC, -ret.x), tempMask);
				col = blendv(col, col + vec4(mix(mat, vec3(.35, .35, min(pow(ret.z, 4.0) * 35.0, .35)), pow(ret.y, 9.0) * .7) * ret.y * alpha, alpha), tempMask);
			}
			d += max(ret.x * .7f, .1f);
		}

		/*if (col.w < .2)
			col.xyz() = vec3(0.1, .15, 0.05);*/
		simdmask tempMask2 = col.w < .2;
		if (!maskNone(tempMask2))
			col.xyz(blendv(col.xyz(), vec3(0.1, .15, 0.05), tempMask2));

		return col.xyz();
	}

	//--------------------------------------------------------------------------
	// Calculate sun light...
	void DoLighting(vec3& mat, vec3 pos, vec3 normal, vec3 eyeDir, simdfloat dis)
	{
		simdfloat h = dot(sunLight, normal);
		mat = mat * sunColour * (max(h, 0.0f) + .2);
	}

	//--------------------------------------------------------------------------
	vec3 TerrainColour(vec3 pos, vec3 dir, vec3 normal, simdfloat dis, simdfloat type)
	{
		vec3 mat;
		simdmask maskType = (type == 0.0f);

		vec3 tempMat;
		//if (type == 0.0)
		{
			// Random colour...
			tempMat = mix(vec3(.0, .3, .0), vec3(.2, .3, .0), Noise(pos.xz() * .025));
			// Random shadows...
			simdfloat t = FractalNoise(pos.xz() * .1) + .5;
			// Do grass blade tracing...
			tempMat = GrassBlades(pos, dir, tempMat, dis) * t;
			DoLighting(tempMat, pos, normal, dir, dis);
		}

		mat = blendv(mat, tempMat, maskType);
		mat = ApplyFog(mat, dis, dir);
		return mat;
	}

	//--------------------------------------------------------------------------
	// Home in on the surface by dividing by two and split...
	// Note, this does a much better job than using 'abs' on the distance march.
	simdfloat BinarySubdivision(vec3 rO, vec3 rD, simdfloat t, simdfloat oldT)
	{
		simdfloat halfwayT = 0.0;
		for (int n = 0; n < 5; n++)
		{
			halfwayT = (oldT + t) * .5;
			simdfloat h = Map(rO + halfwayT * rD).x;
			//(h < THRESHOLD) ? t = halfwayT : oldT = halfwayT;
			t = blendv(t, halfwayT, h < THRESHOLD);
			oldT = blendv(oldT, halfwayT, h >= THRESHOLD);
		}
		return t;
	}

	//--------------------------------------------------------------------------
	simdmask Scene(vec3 rO, vec3 rD, simdfloat& resT, simdfloat& type)
	{
		simdfloat t = 5.;
		simdfloat oldT = 0.0;
		simdfloat delta = 0.;
		simdfloat h = 0.0;
		simdmask hit = 0;
		for (int j = 0; j < 60; j++)
		{
			vec3 p = rO + t * rD;
			h = Map(p).x; // ...Get this position's height mapping.

			// Are we inside, and close enough to fudge a hit?...
			/*if (h < THRESHOLD)
			{
				hit = true;
				break;
			}*/
			hit = h < THRESHOLD;
			if (maskAll(hit)) break;

			
			oldT = blendv(t, oldT, hit);
			//t += h + (t * 0.04);
			t = blendv( t + h + (t * 0.04f), t, hit);
		}
		type = 0.0;
		resT = BinarySubdivision(rO, rD, t, oldT);
		return hit;
	}

	//--------------------------------------------------------------------------
	vec3 CameraPath(simdfloat t)
	{
		//t = time + t;
		vec2 p = vec2(200.0 * sin(3.54 * t), 200.0 * cos(2.0 * t));
		return vec3(p.x + 55.0, 12.0 + sin(t * .3) * 6.5, -94.0 + p.y);
	}

	//--------------------------------------------------------------------------
	vec3 PostEffects(vec3 rgb, vec2 xy)
	{
		// Gamma first...
		rgb = pow(rgb, vec3(0.45));

		// Then...
#define CONTRAST 1.1
#define SATURATION 1.3
#define BRIGHTNESS 1.3
		rgb = mix(vec3(.5), mix(vec3(dot(vec3(.2125, .7154, .0721), rgb * BRIGHTNESS)), rgb * BRIGHTNESS, SATURATION), CONTRAST);
		// Vignette...
		rgb *= .4 + 0.5 * pow(40.0 * xy.x * xy.y * (1.0 - xy.x) * (1.0 - xy.y), 0.2);
		return rgb;
	}

	//--------------------------------------------------------------------------
	vec4 mainImage(vec2 fragCoord)
	{
		vec4 fragColor;
		simdfloat m = (iMouse.x / iResolution.x) * 300.0;
		simdfloat gTime = (iTime * 5.0 + m + 2352.0) * .006;
		vec2 xy = fragCoord.xy() / iResolution.xy();
		vec2 uv = (-1.0 + 2.0 * xy) * vec2(iResolution.x / iResolution.y, 1.0);
		vec3 camTar;

		/*if (xy.y < .13 || xy.y >= .87)
		{
			// Top and bottom cine-crop - what a waste! :)
			fragColor = vec4(vec4(0.0));
			return fragColor;
		}*/

		simdmask maskCrop = (xy.y < .13f) || (xy.y >= .87f);
		if (maskAll(maskCrop))
			{
				// Top and bottom cine-crop - what a waste! :)
				fragColor = vec4(vec4(0.0));
				return fragColor;
		}


#ifdef STEREO
		float isCyan = mod(fragCoord.x + mod(fragCoord.y, 2.0), 2.0);
#endif

		cameraPos = CameraPath(gTime + 0.0);
		cameraPos.x -= 3.0;
		camTar = CameraPath(gTime + .009);
		cameraPos.y += Terrain(CameraPath(gTime + .009).xz()).x;
		camTar.y = cameraPos.y;

		simdfloat roll = .4 * sin(gTime + .5);
		vec3 cw = normalize(camTar - cameraPos);
		vec3 cp = vec3(sin(roll), cos(roll), 0.0);
		vec3 cu = cross(cw, cp);
		vec3 cv = cross(cu, cw);
		vec3 dir = normalize(uv.x * cu + uv.y * cv + 1.3 * cw);
		mat3 camMat = mat3(cu, cv, cw);

#ifdef STEREO
		cameraPos += .85 * cu * isCyan; // move camera to the right - the rd vector is still good
#endif

		vec3 col;
		simdfloat distance;
		simdfloat type;
		simdmask sceneMask = Scene(cameraPos, dir, distance, type);
	//	if (!Scene(cameraPos, dir, distance, type))
		//{
			// Missed scene, now just get the sky...
			vec3 tempCol = GetSky(dir);
		//}
	//	else
		//{
			// Get world coordinate of landscape...
			vec3 pos = cameraPos + distance * dir;
			// Get normal from sampling the high definition height map
			// Use the distance to sample larger gaps to help stop aliasing...
			vec2 p = vec2(0.1, 0.0);
			vec3 nor = vec3(0.0, Terrain(pos.xz()).x, 0.0);
			vec3 v2 = nor - vec3(p.x, Terrain(pos.xz() + p).x, 0.0);
			vec3 v3 = nor - vec3(0.0, Terrain(pos.xz() - p.yx()).x, -p.x);
			nor = cross(v2, v3);
			nor = normalize(nor);

			// Get the colour using all available data...
			col = blendv(tempCol, TerrainColour(pos, dir, nor, distance, type), sceneMask);
	//	}

		// bri is the brightness of sun at the centre of the camera direction.
		// Yeah, the lens flares is not exactly subtle, but it was good fun making it.
		simdfloat bri = dot(cw, sunLight) * .75;
		simdmask maskBri = bri > 0.0f;
		vec3 tempCol2;
		//if (bri > 0.0)
		if (!maskNone(maskBri))
		{
			
			vec2 sunPos = vec2(dot(sunLight, cu), dot(sunLight, cv));
			vec2 uvT = uv - sunPos;
			uvT = uvT * (length(uvT));
			bri = pow(bri, 6.0) * .8;

			// glare = the red shifted blob...
			simdfloat glare1 = max(dot(normalize(vec3(dir.x, dir.y + .3, dir.z)), sunLight), 0.0f) * 1.4;
			// glare2 is the yellow ring...
			simdfloat glare2 = max(1.0 - length(uvT + sunPos * .5) * 4.0, 0.0);
			uvT = mix(uvT, uv, -2.3);
			// glare3 is a purple splodge...
			simdfloat glare3 = max(1.0 - length(uvT + sunPos * 5.0) * 1.2, 0.0);

			tempCol2 += bri * vec3(1.0, .0, .0) * pow(glare1, 12.5) * .05;
			tempCol2 += bri * vec3(1.0, 1.0, 0.2) * pow(glare2, 2.0) * 2.5;
			tempCol2 += bri * sunColour * pow(glare3, 2.0) * 3.0;
		}
		col = blendv(col, col + tempCol2, maskBri);
		col = PostEffects(col, xy);

#ifdef STEREO	
		col *= vec3(isCyan, 1.0 - isCyan, 1.0 - isCyan);
#endif

		return vec4(col, 1.0);
	}

	//--------------------------------------------------------------------------
}