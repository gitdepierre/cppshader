#include "demos.h"

namespace Julia
{
	// https:// www.shadertoy.com/view/scf3WS Julia Set, by edithidden2_71828
	// Code has been modified a bit to fit library constraints

	vec2 cmult(vec2 a, vec2 b) {
		return vec2(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
	}

	void CMS(mat2& R, mat2& I) {
		mat2 nextR = (R * R) - (I * I);
		mat2 nextI = (R * I) + (I * R);
		R = nextR;
		I = nextI;
	}

	void iterator(mat2& ZRmat, mat2& ZImat, mat2 CRmat, mat2 CImat) {
		CMS(ZRmat, ZImat);
		ZRmat = ZRmat + CRmat;
		ZImat = ZImat + CImat;
	}

	// the function below tells you how far each component of Z is from the orbit trap
	mat2 Zdist(mat2 prev, mat2 ZR, mat2 ZI) {
		return mat2(
			vec2(min(min(abs(ZR[0][0]), abs(ZI[0][0])), prev[0][0]), min(min(abs(ZR[1][0]), abs(ZI[1][0])), prev[1][0])),
			vec2(min(min(abs(ZR[0][1]), abs(ZI[0][1])), prev[0][1]), min(min(abs(ZR[1][1]), abs(ZI[1][1])), prev[1][1]))
		);
	}

	float squish(float x) {
		return x / (x + 1.0f);
	}

	// ;3

	mat2 RAWTRAP(mat2 ZR, mat2 ZI, mat2 CR, mat2 CI) {
		mat2 CZR = ZR;
		mat2 CZI = ZI;
		mat2 bigboi = mat2(vec2(10000.0f), vec2(10000.0f));
		for (int i = 0; i < 70; i++) {
			if (i > 3) { bigboi = Zdist(bigboi, CZR, CZI); }
			iterator(CZR, CZI, CR, CI);
		}
		return bigboi;
	}

	/*below is a bunch of 4 dimensional rotation matrices, which combine
	to allow me to rotate the uv plane through 4 space in every possible way
	*/

	mat4 RXY(simdfloat theta) {
		return mat4(
			vec4(cos(theta), sin(theta), 0.0, 0.0),
			vec4(-sin(theta), cos(theta), 0.0, 0.0),
			vec4(0.0, 0.0, 1.0, 0.0),
			vec4(0.0, 0.0, 0.0, 1.0)
		);
	}

	mat4 RXZ(simdfloat theta) {
		return mat4(
			vec4(cos(theta), 0.0, sin(theta), 0.0),
			vec4(0.0, 1.0, 0.0, 0.0),
			vec4(-sin(theta), 0.0, cos(theta), 0.0),
			vec4(0.0, 0.0, 0.0, 1.0)
		);
	}

	mat4 RXW(simdfloat theta) {
		return mat4(
			vec4(cos(theta), 0.0, 0.0, sin(theta)),
			vec4(0.0, 1.0, 0.0, 0.0),
			vec4(0.0, 0.0, 1.0, 0.0),
			vec4(-sin(theta), 0.0, 0.0, cos(theta))
		);
	}

	mat4 RYZ(simdfloat theta) {
		return mat4(
			vec4(1.0, 0.0, 0.0, 0.0),
			vec4(0.0, cos(theta), sin(theta), 0.0),
			vec4(0.0, -sin(theta), cos(theta), 0.0),
			vec4(0.0, 0.0, 0.0, 1.0)
		);
	}

	mat4 RYW(simdfloat theta) {
		return mat4(
			vec4(1.0, 0.0, 0.0, 0.0),
			vec4(0.0, cos(theta), 0.0, sin(theta)),
			vec4(0.0, 0.0, 1.0, 0.0),
			vec4(0.0, -sin(theta), 0.0, cos(theta))
		);
	}

	mat4 RZW(simdfloat theta) {
		return mat4(
			vec4(1.0, 0.0, 0.0, 0.0),
			vec4(0.0, 1.0, 0.0, 0.0),
			vec4(0.0, 0.0, cos(theta), sin(theta)),
			vec4(0.0, 0.0, -sin(theta), cos(theta))
		);
	}



	vec4 mainImage(vec2 fragCoord) {
		vec2 st = (4.f * fragCoord.xy() / iResolution.xy() - 2.f);
		vec4 CST = vec4(st.x, st.y, 0.0, 0.0);
		simdfloat T1 = cos(0.5 * iTime);
		simdfloat T2 = cos(iTime * (0.5f * 23.0f / 29.0f));
		simdfloat T3 = cos(iTime * (0.5f * 19.0f / 29.0f));
		simdfloat T4 = cos(iTime * (0.5f * 17.0f / 29.0f));
		simdfloat T5 = cos(iTime * (0.5f * 13.0f / 29.0f));
		simdfloat T6 = cos(iTime * (0.5f * 11.0f / 29.0f));
		CST = RXY(T1) * RXZ(T2) * RXW(T3) * RYZ(T4) * RYW(T5) * RZW(T6) * CST;
		mat2 coolplane = mat2(vec2(CST.x, CST.z), vec2(CST.y, CST.w));
		// you can set Creal, Cimag, and Zimag how you want, you have 12 dimensions of choice >// w// <
		mat2 Creal = mat2(vec2(0.1, 0.2), vec2(0.3, 0.2));
		mat2 Cimag = mat2(vec2(0.2, 0.1), vec2(-0.2, 0.1));
		mat2 Zreal = mat2(coolplane[0], vec2(0.3, 0.2));
		mat2 Zimag = mat2(coolplane[1], vec2(0.3, 0.15));
		vec4 Lpos = vec4(0.1) + CST;
		mat2 RAW = RAWTRAP(Zreal, Zimag, Creal, Cimag);
		vec4 fragColor = vec4(1.0) - 3.0 * vec4(vec3(1.0, 0.0, 0.0) * RAW[0][0] + vec3(128.0 / 255.0, 1.0, 0.0) * RAW[1][0] +
			vec3(0.0, 1.0, 1.0) * RAW[0][1] + vec3(128.0 / 255.0, 0.0, 1.0) * RAW[1][1], 1.0 / 3.0);
		return normalize(fragColor) * clamp(length(fragColor), 0.0f, 1.0f);
	}

}
