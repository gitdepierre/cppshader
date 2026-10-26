/*
 * MIT License
 *
 * Copyright 2026 Pierre GEISSLER
 *
 * Permission is hereby granted, free of charge, to any person obtaining _a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to USE, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR _a PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
 
#ifndef SIMD_FUNCTIONS
#define SIMD_FUNCTIONS

#include "simd_definitions.h"
#include "simd_vectors.h"
#include "simd_matrix.h"
#include "simd_operators.h"

#pragma region float functions

// acosh functions
/**
 * @brief Computes the inverse hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline simdfloat acosh(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_acosh_float(_x);

#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = std::acosh(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}


/**
 * @brief Computes the inverse hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline vec2 acosh(const vec2& _x)
{
	return { acosh(_x.x), acosh(_x.y) };
}

/**
 * @brief Computes the inverse hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline vec3 acosh(const vec3& _x)
{
	return { acosh(_x.x), acosh(_x.y), acosh(_x.z) };
}

/**
 * @brief Computes the inverse hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline vec4 acosh(const vec4& _x)
{
	return { acosh(_x.x), acosh(_x.y), acosh(_x.z), acosh(_x.w) };
}

// asinh functions
/**
 * @brief Computes the inverse hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline simdfloat asinh(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_asinh_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = std::asinh(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}


/**
 * @brief Computes the inverse hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline vec2 asinh(const vec2& _x)
{
	return { asinh(_x.x), asinh(_x.y) };
}

/**
 * @brief Computes the inverse hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline vec3 asinh(const vec3& _x)
{
	return { asinh(_x.x), asinh(_x.y), asinh(_x.z) };
}

/**
 * @brief Computes the inverse hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline vec4 asinh(const vec4& _x)
{
	return { asinh(_x.x), asinh(_x.y), asinh(_x.z), asinh(_x.w) };
}

// atan functions
/**
 * @brief Computes the inverse tangent.
 * @param _x The input value or vector.
 */
inline simdfloat atan(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_atan_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = std::atan(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the inverse tangent.
 * @param _x The input value or vector.
 */
inline vec2 atan(const vec2& _x)
{
	return { atan(_x.x), atan(_x.y) };
}

/**
 * @brief Computes the inverse tangent.
 * @param _x The input value or vector.
 */
inline vec3 atan(const vec3& _x)
{
	return { atan(_x.x), atan(_x.y), atan(_x.z) };
}

/**
 * @brief Computes the inverse tangent.
 * @param _x The input value or vector.
 */
inline vec4 atan(const vec4& _x)
{
	return { atan(_x.x), atan(_x.y), atan(_x.z), atan(_x.w) };
}

// atan2 functions
/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline simdfloat atan(const simdfloat& _y, const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_atan2_float(_y, _x);
#else
	alignas(SIMDWIDTH * 4) float tempTaba[SIMDWIDTH];
	alignas(SIMDWIDTH * 4) float tempTabb[SIMDWIDTH];
	simd_store_float(tempTaba, _y);
	simd_store_float(tempTabb, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTaba[i] = std::atan2(tempTaba[i], tempTabb[i]);
	}
	return simd_load_float(tempTaba);
#endif
}

/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline simdfloat atan(const float& _y, const float& _x)
{
	return simd_set1_float(std::atan2(_y, _x));
}

/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline vec2 atan(const vec2& _y, const vec2& _x)
{
	return { atan(_y.x, _x.x), atan(_y.y, _x.y) };
}

/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline vec3 atan(const vec3& _y, const vec3& _x)
{
	return { atan(_y.x, _x.x), atan(_y.y, _x.y), atan(_y.z, _x.z) };
}

/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline vec4 atan(const vec4& _y, const vec4& _x)
{
	return { atan(_y.x, _x.x), atan(_y.y, _x.y), atan(_y.z, _x.z), atan(_y.w, _x.w) };
}

// atanh functions
/**
 * @brief Computes the inverse hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline simdfloat atanh(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_atanh_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = std::atanh(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the inverse hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline vec2 atanh(const vec2& _x)
{
	return { atanh(_x.x), atanh(_x.y) };
}

/**
 * @brief Computes the inverse hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline vec3 atanh(const vec3& _x)
{
	return { atanh(_x.x), atanh(_x.y), atanh(_x.z) };
}

/**
 * @brief Computes the inverse hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline vec4 atanh(const vec4& _x)
{
	return { atanh(_x.x), atanh(_x.y), atanh(_x.z), atanh(_x.w) };
}

// blendv functions
/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simdfloat blendv(const simdfloat& _falseval, const simdfloat& _trueval, const simdmask& _mask)
{
#ifdef USE_AVX512
	return _mm512_mask_blend_ps(_mask, _falseval, _trueval);
#else
	return simd_blendv_float(_falseval, _trueval, _mask);
#endif

}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simdfloat blendv(const float& _falseval, const float& _trueval, const simdmask& _mask)
{
	return blendv(simd_set1_float(_falseval), simd_set1_float(_trueval), _mask);
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simdfloat blendv(const simdfloat& _falseval, const float& _trueval, const simdmask& _mask)
{
	return blendv(_falseval, simd_set1_float(_trueval), _mask);
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simdfloat blendv(const float& _falseval, const simdfloat& _trueval, const simdmask& _mask)
{
	return blendv(simd_set1_float(_falseval), _trueval, _mask);
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline vec2 blendv(const vec2& _falseval, const vec2& _trueval, const simdmask& _mask)
{
	return {
		blendv(_falseval.x, _trueval.x, _mask),
		blendv(_falseval.y, _trueval.y, _mask)
	};
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline vec3 blendv(const vec3& _falseval, const vec3& _trueval, const simdmask& _mask)
{
	return {
		blendv(_falseval.x, _trueval.x, _mask),
		blendv(_falseval.y, _trueval.y, _mask),
		blendv(_falseval.z, _trueval.z, _mask)
	};
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline vec4 blendv(const vec4& _falseval, const vec4& _trueval, const simdmask& _mask)
{
	return {
		blendv(_falseval.x, _trueval.x, _mask),
		blendv(_falseval.y, _trueval.y, _mask),
		blendv(_falseval.z, _trueval.z, _mask),
		blendv(_falseval.w, _trueval.w, _mask)
	};
}

// abs functions
/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline simdfloat abs(const simdfloat& _x)
{
	return blendv(_x, -_x, _x < 0.0f);
}

/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline vec2 abs(const vec2& _x)
{
	return { abs(_x.x), abs(_x.y) };
}

/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline vec3 abs(const vec3& _x)
{
	return { abs(_x.x), abs(_x.y), abs(_x.z) };
}

/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline vec4 abs(const vec4& _x)
{
	return { abs(_x.x), abs(_x.y), abs(_x.z), abs(_x.w) };
}

// ceil functions
/**
 * @brief Rounds each component up to the nearest integer.
 * @param _x The input value or vector.
 */
inline simdfloat ceil(const simdfloat& _x)
{
	return simd_ceil_float(_x);
}

/**
 * @brief Rounds each component up to the nearest integer.
 * @param _x The input value or vector.
 */
inline vec2 ceil(const vec2& _x)
{
	return { ceil(_x.x), ceil(_x.y) };
}

/**
 * @brief Rounds each component up to the nearest integer.
 * @param _x The input value or vector.
 */
inline vec3 ceil(const vec3& _x)
{
	return { ceil(_x.x), ceil(_x.y), ceil(_x.z) };
}

/**
 * @brief Rounds each component up to the nearest integer.
 * @param _x The input value or vector.
 */
inline vec4 ceil(const vec4& _x)
{
	return { ceil(_x.x), ceil(_x.y), ceil(_x.z), ceil(_x.w) };
}

// max functions
/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat max(const simdfloat& _val1, const simdfloat& _val2)
{
	return simd_max_float(_val1, _val2);
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat max(const simdfloat& _val1, const float& _val2)
{
	return max(_val1, simd_set1_float(_val2));
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat max(const float& _val1, const simdfloat& _val2)
{
	return max(simd_set1_float(_val1), _val2);
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat max(const float& _val1, const float& _val2)
{
	return max(simd_set1_float(_val1), simd_set1_float(_val2));
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 max(const vec2& _val1, const simdfloat& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 max(const simdfloat& _val1, const vec2& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 max(const vec2& _val1, const float& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 max(const float& _val1, const vec2& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 max(const vec2& _val1, const vec2& _val2)
{
	return {
		max(_val1.x, _val2.x),
		max(_val1.y, _val2.y)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 max(const vec3& _val1, const simdfloat& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 max(const simdfloat& _val1, const vec3& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 max(const vec3& _val1, const float& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 max(const float& _val1, const vec3& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 max(const vec3& _val1, const vec3& _val2)
{
	return {
		max(_val1.x, _val2.x),
		max(_val1.y, _val2.y),
		max(_val1.z, _val2.z)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 max(const vec4& _val1, const simdfloat& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2),
		max(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 max(const simdfloat& _val1, const vec4& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z),
		max(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 max(const vec4& _val1, const float& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2),
		max(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 max(const float& _val1, const vec4& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z),
		max(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 max(const vec4& _val1, const vec4& _val2)
{
	return {
		max(_val1.x, _val2.x),
		max(_val1.y, _val2.y),
		max(_val1.z, _val2.z),
		max(_val1.w, _val2.w)
	};
}

// min functions
/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat min(const simdfloat& _val1, const simdfloat& _val2)
{
	return simd_min_float(_val1, _val2);
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat min(const simdfloat& _val1, const float& _val2)
{
	return min(_val1, simd_set1_float(_val2));
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat min(const float& _val1, const simdfloat& _val2)
{
	return min(simd_set1_float(_val1), _val2);
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat min(const float& _val1, const float& _val2)
{
	return min(simd_set1_float(_val1), simd_set1_float(_val2));
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 min(const vec2& _val1, const simdfloat& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 min(const simdfloat& _val1, const vec2& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 min(const vec2& _val1, const float& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 min(const float& _val1, const vec2& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec2 min(const vec2& _val1, const vec2& _val2)
{
	return {
		min(_val1.x, _val2.x),
		min(_val1.y, _val2.y)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 min(const vec3& _val1, const simdfloat& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 min(const simdfloat& _val1, const vec3& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 min(const vec3& _val1, const float& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 min(const float& _val1, const vec3& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 min(const vec3& _val1, const vec3& _val2)
{
	return {
		min(_val1.x, _val2.x),
		min(_val1.y, _val2.y),
		min(_val1.z, _val2.z)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 min(const vec4& _val1, const simdfloat& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2),
		min(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 min(const simdfloat& _val1, const vec4& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z),
		min(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 min(const vec4& _val1, const float& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2),
		min(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 min(const float& _val1, const vec4& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z),
		min(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec4 min(const vec4& _val1, const vec4& _val2)
{
	return {
		min(_val1.x, _val2.x),
		min(_val1.y, _val2.y),
		min(_val1.z, _val2.z),
		min(_val1.w, _val2.w)
	};
}

// clamp functions
/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdfloat clamp(const simdfloat& _x, const simdfloat& _minval, const simdfloat& _maxval)
{
	return max(min(_x, _maxval), _minval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdfloat clamp(const float& _x, const float& _minval, const float& _maxval)
{
	return clamp(simd_set1_float(_x), simd_set1_float(_minval), simd_set1_float(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdfloat clamp(const float& _x, const float& _minval, const simdfloat& _maxval)
{
	return clamp(simd_set1_float(_x), simd_set1_float(_minval), _maxval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdfloat clamp(const float& _x, const simdfloat& _minval, const float& _maxval)
{
	return clamp(simd_set1_float(_x), _minval, simd_set1_float(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdfloat clamp(const float& _x, const simdfloat& _minval, const simdfloat& _maxval)
{
	return clamp(simd_set1_float(_x), _minval, _maxval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdfloat clamp(const simdfloat& _x, const float& _minval, const float& _maxval)
{
	return clamp(_x, simd_set1_float(_minval), simd_set1_float(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdfloat clamp(const simdfloat& _x, const float& _minval, const simdfloat& _maxval)
{
	return clamp(_x, simd_set1_float(_minval), _maxval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdfloat clamp(const simdfloat& _x, const simdfloat& _minval, const float& _maxval)
{
	return clamp(_x, _minval, simd_set1_float(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec2 clamp(const vec2& _x, const simdfloat& _minval, const simdfloat& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec2 clamp(const vec2& _x, const float& _minval, const float& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec2 clamp(const vec2& _x, const simdfloat& _minval, const float& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec2 clamp(const vec2& _x, const float& _minval, const simdfloat& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec2 clamp(const vec2& _x, const vec2& _minval, const vec2& _maxval)
{
	return {
		clamp(_x.x, _minval.x, _maxval.x),
		clamp(_x.y, _minval.y, _maxval.y)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec3 clamp(const vec3& _x, const simdfloat& _minval, const simdfloat& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec3 clamp(const vec3& _x, const float& _minval, const float& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec3 clamp(const vec3& _x, const simdfloat& _minval, const float& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec3 clamp(const vec3& _x, const float& _minval, const simdfloat& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec3 clamp(const vec3& _x, const vec3& _minval, const vec3& _maxval)
{
	return {
		clamp(_x.x, _minval.x, _maxval.x),
		clamp(_x.y, _minval.y, _maxval.y),
		clamp(_x.z, _minval.z, _maxval.z)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec4 clamp(const vec4& _x, const simdfloat& _minval, const simdfloat& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec4 clamp(const vec4& _x, const float& _minval, const float& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec4 clamp(const vec4& _x, const simdfloat& _minval, const float& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec4 clamp(const vec4& _x, const float& _minval, const simdfloat& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline vec4 clamp(const vec4& _x, const vec4& _minval, const vec4& _maxval)
{
	return {
		clamp(_x.x, _minval.x, _maxval.x),
		clamp(_x.y, _minval.y, _maxval.y),
		clamp(_x.z, _minval.z, _maxval.z),
		clamp(_x.w, _minval.w, _maxval.w)
	};
}

// acos functions
/**
 * @brief Computes the inverse cosine of each component.
 * @param _x The input value or vector.
 */
inline simdfloat acos(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_acos_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = std::acos(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the inverse cosine of each component.
 * @param _x The input value or vector.
 */
inline vec2 acos(const vec2& _x)
{
	return { acos(_x.x), acos(_x.y) };
}

/**
 * @brief Computes the inverse cosine of each component.
 * @param _x The input value or vector.
 */
inline vec3 acos(const vec3& _x)
{
	return { acos(_x.x), acos(_x.y), acos(_x.z) };
}

/**
 * @brief Computes the inverse cosine of each component.
 * @param _x The input value or vector.
 */
inline vec4 acos(const vec4& _x)
{
	return { acos(_x.x), acos(_x.y), acos(_x.z), acos(_x.w) };
}

// asin functions
/**
 * @brief Computes the inverse sine of each component.
 * @param _x The input value or vector.
 */
inline simdfloat asin(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_asin_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = std::asin(tempTab[i]);
	}
	return simd_load_float(tempTab);

#endif
}

/**
 * @brief Computes the inverse sine of each component.
 * @param _x The input value or vector.
 */
inline vec2 asin(const vec2& _x)
{
	return { asin(_x.x), asin(_x.y) };
}

/**
 * @brief Computes the inverse sine of each component.
 * @param _x The input value or vector.
 */
inline vec3 asin(const vec3& _x)
{
	return { asin(_x.x), asin(_x.y), asin(_x.z) };
}

/**
 * @brief Computes the inverse sine of each component.
 * @param _x The input value or vector.
 */
inline vec4 asin(const vec4& _x)
{
	return { asin(_x.x), asin(_x.y), asin(_x.z), asin(_x.w) };
}

// floor functions
/**
 * @brief Rounds each component down to the nearest integer.
 * @param _x The input value or vector.
 */
inline simdfloat floor(const simdfloat& _x)
{
	return simd_floor_float(_x);
}

/**
 * @brief Rounds each component down to the nearest integer.
 * @param _x The input value or vector.
 */
inline vec2 floor(const vec2& _x)
{
	return { floor(_x.x), floor(_x.y) };
}

/**
 * @brief Rounds each component down to the nearest integer.
 * @param _x The input value or vector.
 */
inline vec3 floor(const vec3& _x)
{
	return { floor(_x.x), floor(_x.y), floor(_x.z) };
}

/**
 * @brief Rounds each component down to the nearest integer.
 * @param _x The input value or vector.
 */
inline vec4 floor(const vec4& _x)
{
	return { floor(_x.x), floor(_x.y), floor(_x.z), floor(_x.w) };
}

// mod functions
/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */

inline simdfloat mod(const simdfloat& _value, const simdfloat& _modulus)
{
	return _value - (simd_floor_float( _value / _modulus ) * _modulus);
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simdfloat mod(const simdfloat& _value, const float& _modulus)
{
	return _value - floor(_value / simd_set1_float(_modulus)) * _modulus;
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simdfloat mod(const float& _value, const simdfloat& _modulus)
{
	return simd_set1_float(_value) - floor(simd_set1_float(_value) / _modulus) * _modulus;
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simdfloat mod(const float& _value, const float& _modulus)
{
	return simd_set1_float(_value - std::floor(_value / _modulus) * _modulus);
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec2 mod(const vec2& _value, const vec2& _modulus)
{
	return { mod(_value.x, _modulus.x), mod(_value.y, _modulus.y) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec3 mod(const vec3& _value, const vec3& _modulus)
{
	return { mod(_value.x, _modulus.x), mod(_value.y, _modulus.y), mod(_value.z, _modulus.z) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec4 mod(const vec4& _value, const vec4& _modulus)
{
	return { mod(_value.x, _modulus.x), mod(_value.y, _modulus.y), mod(_value.z, _modulus.z), mod(_value.w, _modulus.w) };
}

/**
 * @brief Computes the cosine of each component.
 * @param _x The input value or vector.
 */
inline simdfloat cos(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_cos_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tabVal[SIMDWIDTH];
	simd_store_float(tabVal, _x);

	alignas(SIMDWIDTH * 4) float tabResult[SIMDWIDTH];
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tabResult[i] = std::cos(tabVal[i]);
	}

	return simd_load_float(tabResult);
#endif
}

/**
 * @brief Computes the cosine of each component.
 * @param _x The input value or vector.
 */
inline vec2 cos(const vec2& _x)
{
	return { cos(_x.x), cos(_x.y) };
}

/**
 * @brief Computes the cosine of each component.
 * @param _x The input value or vector.
 */
inline vec3 cos(const vec3& _x)
{
	return { cos(_x.x), cos(_x.y), cos(_x.z) };
}

/**
 * @brief Computes the cosine of each component.
 * @param _x The input value or vector.
 */
inline vec4 cos(const vec4& _x)
{
	return { cos(_x.x), cos(_x.y), cos(_x.z), cos(_x.w) };
}

// cosh functions
/**
 * @brief Computes the hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline simdfloat cosh(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_cosh_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = std::cosh(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline vec2 cosh(const vec2& _x)
{
	return { cosh(_x.x), cosh(_x.y) };
}

/**
 * @brief Computes the hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline vec3 cosh(const vec3& _x)
{
	return { cosh(_x.x), cosh(_x.y), cosh(_x.z) };
}

/**
 * @brief Computes the hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline vec4 cosh(const vec4& _x)
{
	return { cosh(_x.x), cosh(_x.y), cosh(_x.z), cosh(_x.w) };
}

// cross functions
/**
 * @brief Computes the cross product of two 3D vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline vec3 cross(const vec3& _val1, const vec3& _val2)
{
	return { _val1.y * _val2.z - _val1.z * _val2.y, _val1.z * _val2.x - _val1.x * _val2.z, _val1.x * _val2.y - _val1.y * _val2.x };
}

// degrees functions
/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline simdfloat degrees(const simdfloat& _x)
{
	return simd_mul_float(_x, simd_set1_float(180.0f / 3.1415927f));
}

/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline simdfloat degrees(const float& _x)
{
	return simd_set1_float(_x * (180.0f / 3.1415927f));
}

/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline vec2 degrees(const vec2& _x)
{
	return { degrees(_x.x), degrees(_x.y) };
}

/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline vec3 degrees(const vec3& _x)
{
	return { degrees(_x.x), degrees(_x.y), degrees(_x.z) };
}

/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline vec4 degrees(const vec4& _x)
{
	return { degrees(_x.x), degrees(_x.y), degrees(_x.z), degrees(_x.w) };
}

// distance functions
/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simdfloat distance(const simdfloat& _a, const simdfloat& _b)
{
	return simd_sqrt_float(simd_mul_float(simd_sub_float(_a, _b), simd_sub_float(_a, _b)));
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simdfloat distance(const float& _a, const float& _b)
{
	return std::abs(_a - _b);
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simdfloat distance(const simdfloat& _a, const float& _b)
{
	return distance(_a, simd_set1_float(_b));
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simdfloat distance(const float& _a, const simdfloat& _b)
{
	return distance(simd_set1_float(_a), _b);
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simdfloat distance(const vec2& _a, const vec2& _b)
{
	return simd_sqrt_float(simd_add_float(simd_mul_float(simd_sub_float(_a.x, _b.x), simd_sub_float(_a.x, _b.x)), simd_mul_float(simd_sub_float(_a.y, _b.y), simd_sub_float(_a.y, _b.y))));
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simdfloat distance(const vec3& _a, const vec3& _b)
{
	return simd_sqrt_float(simd_add_float(simd_add_float(simd_mul_float(simd_sub_float(_a.x, _b.x), simd_sub_float(_a.x, _b.x)), simd_mul_float(simd_sub_float(_a.y, _b.y), simd_sub_float(_a.y, _b.y))), simd_mul_float(simd_sub_float(_a.z, _b.z), simd_sub_float(_a.z, _b.z))));
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simdfloat distance(const vec4& _a, const vec4& _b)
{
	return simd_sqrt_float(simd_add_float(simd_add_float(simd_add_float(simd_mul_float(simd_sub_float(_a.x, _b.x), simd_sub_float(_a.x, _b.x)), simd_mul_float(simd_sub_float(_a.y, _b.y), simd_sub_float(_a.y, _b.y))), simd_mul_float(simd_sub_float(_a.z, _b.z), simd_sub_float(_a.z, _b.z))), simd_mul_float(simd_sub_float(_a.w, _b.w), simd_sub_float(_a.w, _b.w))));
}

// dot functions
/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat dot(const float& _val1, const float& _val2)
{
	return _val1 * _val2;
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat dot(const simdfloat& _val1, const float& _val2)
{
	return _val1 * _val2;
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat dot(const float& _val1, const simdfloat& _val2)
{
	return _val1 * _val2;
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat dot(const simdfloat& _val1, const simdfloat& _val2)
{
	return _val1 * _val2;
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat dot(const vec2& _val1, const vec2& _val2)
{
	return simd_add_float(simd_mul_float(_val1.x, _val2.x), simd_mul_float(_val1.y, _val2.y));
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat dot(const vec3& _val1, const vec3& _val2)
{
	return simd_add_float(simd_add_float(simd_mul_float(_val1.x, _val2.x), simd_mul_float(_val1.y, _val2.y)), simd_mul_float(_val1.z, _val2.z));
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdfloat dot(const vec4& _val1, const vec4& _val2)
{
	return simd_add_float(simd_add_float(simd_add_float(simd_mul_float(_val1.x, _val2.x), simd_mul_float(_val1.y, _val2.y)), simd_mul_float(_val1.z, _val2.z)), simd_mul_float(_val1.w, _val2.w));
}

// exp functions
/**
 * @brief Computes the base-e exponential of each component.
 * @param _x The input value or vector.
 */
inline simdfloat exp(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_exp_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = std::exp(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the base-e exponential of each component.
 * @param _x The input value or vector.
 */
inline vec2 exp(const vec2& _x)
{
	return { exp(_x.x), exp(_x.y) };
}

/**
 * @brief Computes the base-e exponential of each component.
 * @param _x The input value or vector.
 */
inline vec3 exp(const vec3& _x)
{
	return { exp(_x.x), exp(_x.y), exp(_x.z) };
}

/**
 * @brief Computes the base-e exponential of each component.
 * @param _x The input value or vector.
 */
inline vec4 exp(const vec4& _x)
{
	return { exp(_x.x), exp(_x.y), exp(_x.z), exp(_x.w) };
}

// exp2 functions
/**
 * @brief Computes the base-2 exponential of each component.
 * @param _x The input value or vector.
 */
inline simdfloat exp2(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_exp2_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = exp2(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the base-2 exponential of each component.
 * @param _x The input value or vector.
 */
inline vec2 exp2(const vec2& _x)
{
	return { exp2(_x.x), exp2(_x.y) };
}

/**
 * @brief Computes the base-2 exponential of each component.
 * @param _x The input value or vector.
 */
inline vec3 exp2(const vec3& _x)
{
	return { exp2(_x.x), exp2(_x.y), exp2(_x.z) };
}

/**
 * @brief Computes the base-2 exponential of each component.
 * @param _x The input value or vector.
 */
inline vec4 exp2(const vec4& _x)
{
	return { exp2(_x.x), exp2(_x.y), exp2(_x.z), exp2(_x.w) };
}

// fma functions
/**
 * @brief Computes fused multiply-add (a * b + c).
 * @param _val1 The first factor for multiplication.
 * @param _val2 The second factor for multiplication.
 * @param _addend The value to add.
 */
inline simdfloat fma(const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _addend)
{
	return simd_add_float(simd_mul_float(_val1, _val2), _addend);
}

/**
 * @brief Computes fused multiply-add (a * b + c).
 * @param _val1 The first factor for multiplication.
 * @param _val2 The second factor for multiplication.
 * @param _addend The value to add.
 */
inline vec2 fma(const vec2& _val1, const vec2& _val2, const vec2& _addend)
{
	return { fma(_val1.x, _val2.x, _addend.x), fma(_val1.y, _val2.y, _addend.y) };
}

/**
 * @brief Computes fused multiply-add (a * b + c).
 * @param _val1 The first factor for multiplication.
 * @param _val2 The second factor for multiplication.
 * @param _addend The value to add.
 */
inline vec3 fma(const vec3& _val1, const vec3& _val2, const vec3& _addend)
{
	return { fma(_val1.x, _val2.x, _addend.x), fma(_val1.y, _val2.y, _addend.y), fma(_val1.z, _val2.z, _addend.z) };
}

/**
 * @brief Computes fused multiply-add (a * b + c).
 * @param _val1 The first factor for multiplication.
 * @param _val2 The second factor for multiplication.
 * @param _addend The value to add.
 */
inline vec4 fma(const vec4& _val1, const vec4& _val2, const vec4& _addend)
{
	return { fma(_val1.x, _val2.x, _addend.x), fma(_val1.y, _val2.y, _addend.y), fma(_val1.z, _val2.z, _addend.z), fma(_val1.w, _val2.w, _addend.w) };
}

// fract functions
/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline simdfloat fract(const simdfloat& _x)
{
	return simd_sub_float(_x, simd_floor_float(_x));
}

/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline simdfloat fract(const float& _x)
{
	return simd_set1_float(_x - floorf(_x));
}

/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline vec2 fract(const vec2& _x)
{
	return { fract(_x.x), fract(_x.y) };
}

/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline vec3 fract(const vec3& _x)
{
	return { fract(_x.x), fract(_x.y), fract(_x.z) };
}

/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline vec4 fract(const vec4& _x)
{
	return { fract(_x.x), fract(_x.y), fract(_x.z), fract(_x.w) };
}

// inversesqrt functions
/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline simdfloat inversesqrt(const simdfloat& _x)
{
#ifndef USE_AVX512
	return simd_rsqrt_float(_x);
#else
	return simd_div_float(simd_set1_float(1.0f), simd_sqrt_float(_x));
#endif
}

/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline simdfloat inversesqrt(const float& _x)
{
	return simd_set1_float(1.0f / sqrtf(_x));
}

/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline vec2 inversesqrt(const vec2& _x)
{
	return { inversesqrt(_x.x), inversesqrt(_x.y) };
}

/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline vec3 inversesqrt(const vec3& _x)
{
	return { inversesqrt(_x.x), inversesqrt(_x.y), inversesqrt(_x.z) };
}

/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline vec4 inversesqrt(const vec4& _x)
{
	return { inversesqrt(_x.x), inversesqrt(_x.y), inversesqrt(_x.z), inversesqrt(_x.w) };
}

// ldexp functions
/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline simdfloat ldexp(const simdfloat& _mantissa, const simdfloat& _exponent)
{
	return simd_mul_float(_mantissa, exp2(_exponent));
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline simdfloat ldexp(const simdfloat& _mantissa, const float& _exponent)
{
	return simd_mul_float(_mantissa, exp2(simd_set1_float(_exponent)));
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline simdfloat ldexp(const float& _mantissa, const simdfloat& _exponent)
{
	return simd_mul_float(simd_set1_float(_mantissa), exp2(_exponent));
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline vec2 ldexp(const vec2& _mantissa, const vec2& _exponent)
{
	return { ldexp(_mantissa.x, _exponent.x), ldexp(_mantissa.y, _exponent.y) };
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline vec3 ldexp(const vec3& _mantissa, const vec3& _exponent)
{
	return { ldexp(_mantissa.x, _exponent.x), ldexp(_mantissa.y, _exponent.y), ldexp(_mantissa.z, _exponent.z) };
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline vec4 ldexp(const vec4& _mantissa, const vec4& _exponent)
{
	return { ldexp(_mantissa.x, _exponent.x), ldexp(_mantissa.y, _exponent.y), ldexp(_mantissa.z, _exponent.z), ldexp(_mantissa.w, _exponent.w) };
}

// length functions
/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simdfloat length(const float& _vec)
{
	return simd_set1_float(std::abs(_vec));
}

/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simdfloat length(const simdfloat& _vec)
{
	return abs(_vec);
}

/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simdfloat length(const vec2& _vec)
{
	return simd_sqrt_float(_vec.x * _vec.x + _vec.y * _vec.y);
}

/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simdfloat length(const vec3& _vec)
{
	return simd_sqrt_float(_vec.x * _vec.x + _vec.y * _vec.y + _vec.z * _vec.z);
}

/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simdfloat length(const vec4& _vec)
{
	return simd_sqrt_float(_vec.x * _vec.x + _vec.y * _vec.y + _vec.z * _vec.z + _vec.w * _vec.w);
}

// lerp functions
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat lerp(const simdfloat& _from, const simdfloat& _to, const simdfloat& _t)
{
	return simd_add_float(simd_mul_float(simd_sub_float(_to, _from), _t), _from);
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat lerp(const simdfloat& _from, const simdfloat& _to, const float& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat lerp(const simdfloat& _from, const float& _to, const simdfloat& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat lerp(const simdfloat& _from, const float& _to, const float& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat lerp(const float& _from, const simdfloat& _to, const simdfloat& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat lerp(const float& _from, const simdfloat& _to, const float& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat lerp(const float& _from, const float& _to, const simdfloat& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat lerp(const float& _from, const float& _to, const float& _t)
{
	return simd_set1_float(_from + _t * (_to - _from));
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec2 lerp(const vec2& _from, const vec2& _to, const simdfloat& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec2 lerp(const vec2& _from, const vec2& _to, const float& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec2 lerp(const vec2& _from, const vec2& _to, const vec2& _t)
{
	return { lerp(_from.x, _to.x, _t.x), lerp(_from.y, _to.y, _t.y) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec3 lerp(const vec3& _from, const vec3& _to, const simdfloat& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t), lerp(_from.z, _to.z, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec3 lerp(const vec3& _from, const vec3& _to, const float& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t), lerp(_from.z, _to.z, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec3 lerp(const vec3& _from, const vec3& _to, const vec3& _t)
{
	return { lerp(_from.x, _to.x, _t.x), lerp(_from.y, _to.y, _t.y), lerp(_from.z, _to.z, _t.z) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec4 lerp(const vec4& _from, const vec4& _to, const simdfloat& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t), lerp(_from.z, _to.z, _t), lerp(_from.w, _to.w, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec4 lerp(const vec4& _from, const vec4& _to, const float& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t), lerp(_from.z, _to.z, _t), lerp(_from.w, _to.w, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec4 lerp(const vec4& _from, const vec4& _to, const vec4& _t)
{
	return { lerp(_from.x, _to.x, _t.x), lerp(_from.y, _to.y, _t.y), lerp(_from.z, _to.z, _t.z), lerp(_from.w, _to.w, _t.w) };
}

// log functions
/**
 * @brief Computes the natural (base-e) logarithm of each component.
 * @param _x The input value or vector.
 */
inline simdfloat log(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_log_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = logf(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the natural (base-e) logarithm of each component.
 * @param _x The input value or vector.
 */
inline vec2 log(const vec2& _x)
{
	return { log(_x.x), log(_x.y) };
}

/**
 * @brief Computes the natural (base-e) logarithm of each component.
 * @param _x The input value or vector.
 */
inline vec3 log(const vec3& _x)
{
	return { log(_x.x), log(_x.y), log(_x.z) };
}

/**
 * @brief Computes the natural (base-e) logarithm of each component.
 * @param _x The input value or vector.
 */
inline vec4 log(const vec4& _x)
{
	return { log(_x.x), log(_x.y), log(_x.z), log(_x.w) };
}

// log2 functions
/**
 * @brief Computes the base-2 logarithm of each component.
 * @param _x The input value or vector.
 */
inline simdfloat log2(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_log2_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = log2f(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the base-2 logarithm of each component.
 * @param _x The input value or vector.
 */
inline vec2 log2(const vec2& _x)
{
	return { log2(_x.x), log2(_x.y) };
}

/**
 * @brief Computes the base-2 logarithm of each component.
 * @param _x The input value or vector.
 */
inline vec3 log2(const vec3& _x)
{
	return { log2(_x.x), log2(_x.y), log2(_x.z) };
}

/**
 * @brief Computes the base-2 logarithm of each component.
 * @param _x The input value or vector.
 */
inline vec4 log2(const vec4& _x)
{
	return { log2(_x.x), log2(_x.y), log2(_x.z), log2(_x.w) };
}

// mix functions
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat mix(const simdfloat& _from, const simdfloat& _to, const simdfloat& _t)
{
	return simd_add_float(simd_mul_float(simd_sub_float(_to, _from), _t), _from);
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat mix(const simdfloat& _from, const simdfloat& _to, const float& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat mix(const simdfloat& _from, const float& _to, const simdfloat& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat mix(const simdfloat& _from, const float& _to, const float& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat mix(const float& _from, const simdfloat& _to, const simdfloat& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat mix(const float& _from, const simdfloat& _to, const float& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat mix(const float& _from, const float& _to, const simdfloat& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simdfloat mix(const float& _from, const float& _to, const float& _t)
{
	return simd_set1_float(_from + _t * (_to - _from));
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec2 mix(const vec2& _from, const vec2& _to, const simdfloat& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec2 mix(const vec2& _from, const vec2& _to, const float& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec2 mix(const vec2& _from, const vec2& _to, const vec2& _t)
{
	return { mix(_from.x, _to.x, _t.x), mix(_from.y, _to.y, _t.y) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec3 mix(const vec3& _from, const vec3& _to, const simdfloat& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t), mix(_from.z, _to.z, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec3 mix(const vec3& _from, const vec3& _to, const float& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t), mix(_from.z, _to.z, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec3 mix(const vec3& _from, const vec3& _to, const vec3& _t)
{
	return { mix(_from.x, _to.x, _t.x), mix(_from.y, _to.y, _t.y), mix(_from.z, _to.z, _t.z) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec4 mix(const vec4& _from, const vec4& _to, const simdfloat& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t), mix(_from.z, _to.z, _t), mix(_from.w, _to.w, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec4 mix(const vec4& _from, const vec4& _to, const float& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t), mix(_from.z, _to.z, _t), mix(_from.w, _to.w, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline vec4 mix(const vec4& _from, const vec4& _to, const vec4& _t)
{
	return { mix(_from.x, _to.x, _t.x), mix(_from.y, _to.y, _t.y), mix(_from.z, _to.z, _t.z), mix(_from.w, _to.w, _t.w) };
}

// modf functions
/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simdfloat modf(const simdfloat& _value, const simdfloat& _modulus)
{
	return simd_sub_float(_value, simd_mul_float(simd_floor_float(simd_div_float(_value, _modulus)), _modulus));
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simdfloat modf(const float& _value, const float& _modulus)
{
	return simd_set1_float(_value - std::floor(_value / _modulus) * _modulus);
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simdfloat modf(const simdfloat& _value, const float& _modulus)
{
	return modf(_value, simd_set1_float(_modulus));
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simdfloat modf(const float& _value, const simdfloat& _modulus)
{
	return modf(simd_set1_float(_value), _modulus);
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec2 modf(const vec2& _value, const simdfloat& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec2 modf(const vec2& _value, const float& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec2 modf(const vec2& _value, const vec2& _modulus)
{
	return { modf(_value.x, _modulus.x), modf(_value.y, _modulus.y) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec3 modf(const vec3& _value, const simdfloat& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus), modf(_value.z, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec3 modf(const vec3& _value, const float& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus), modf(_value.z, _modulus) };
}


/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec3 modf(const vec3& _value, const vec3& _modulus)
{
	return { modf(_value.x, _modulus.x), modf(_value.y, _modulus.y), modf(_value.z, _modulus.z) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec4 modf(const vec4& _value, const simdfloat& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus), modf(_value.z, _modulus), modf(_value.w, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec4 modf(const vec4& _value, const float& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus), modf(_value.z, _modulus), modf(_value.w, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline vec4 modf(const vec4& _value, const vec4& _modulus)
{
	return { modf(_value.x, _modulus.x), modf(_value.y, _modulus.y), modf(_value.z, _modulus.z), modf(_value.w, _modulus.w) };
}

// normalize functions
/**
 * @brief Computes the normalized vector (unit vector).
 * @param _x The input value.
 */
inline simdfloat normalize(const float& _x)
{
	if (_x == 0.0f) return simd_set1_float(0.0f);
	else return simd_set1_float(1.0f);
}

/**
 * @brief Computes the normalized vector (unit vector).
 * @param _x The input value.
 */
inline simdfloat normalize(const simdfloat& _x)
{
	return blendv(_x / abs(_x), 0.0f, _x == 0.0f);
}

/**
 * @brief Computes the normalized vector (unit vector).
 * @param _vec The input vector.
 */
inline vec2 normalize(const vec2& _vec)
{
	return {
		_vec.x / length(_vec),
		_vec.y / length(_vec)
	};
}

/**
 * @brief Computes the normalized vector (unit vector).
 * @param _vec The input vector.
 */
inline vec3 normalize(const vec3& _vec)
{
	return {
		_vec.x / length(_vec),
		_vec.y / length(_vec),
		_vec.z / length(_vec)
	};
}

/**
 * @brief Computes the normalized vector (unit vector).
 * @param _vec The input vector.
 */
inline vec4 normalize(const vec4& _vec)
{
	return {
		_vec.x / length(_vec),
		_vec.y / length(_vec),
		_vec.z / length(_vec),
		_vec.w / length(_vec)
	};
}

// pow functions
/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline simdfloat pow(const simdfloat& _base, const simdfloat& _exponent)
{
#ifndef __GNUC__
	return simd_pow_float(_base, _exponent);
#else
	alignas(SIMDWIDTH * 4) float tempTabA[SIMDWIDTH];
	alignas(SIMDWIDTH * 4) float tempTabB[SIMDWIDTH];
	simd_store_float(tempTabA, _base);
	simd_store_float(tempTabB, _exponent);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTabA[i] = powf(tempTabA[i], tempTabB[i]);
	}
	return simd_load_float(tempTabA);
#endif
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline simdfloat pow(const simdfloat& _base, const float& _exponent)
{
	return pow(_base, simd_set1_float(_exponent));
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline vec2 pow(const vec2& _base, const simdfloat& _exponent)
{
	return {
		pow(_base.x, _exponent),
		pow(_base.y, _exponent)
	};
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline vec2 pow(const vec2& _base, const float& _exponent)
{
	return pow(_base, simd_set1_float(_exponent));
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline vec2 pow(const vec2& _base, const vec2& _exponent)
{
	return {
		pow(_base.x, _exponent.x),
		pow(_base.y, _exponent.y)
	};
}
/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline vec3 pow(const vec3& _base, const simdfloat& _exponent)
{
	return {
		pow(_base.x, _exponent),
		pow(_base.y, _exponent),
		pow(_base.z, _exponent)
	};
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline vec3 pow(const vec3& _base, const float& _exponent)
{
	return pow(_base, simd_set1_float(_exponent));
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline vec3 pow(const vec3& _base, const vec3& _exponent)
{
	return {
		pow(_base.x, _exponent.x),
		pow(_base.y, _exponent.y),
		pow(_base.z, _exponent.z)
	};
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline vec4 pow(const vec4& _base, const simdfloat& _exponent)
{
	return {
		pow(_base.x, _exponent),
		pow(_base.y, _exponent),
		pow(_base.z, _exponent),
		pow(_base.w, _exponent)
	};
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline vec4 pow(const vec4& _base, const float& _exponent)
{
	return pow(_base, simd_set1_float(_exponent));
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline vec4 pow(const vec4& _base, const vec4& _exponent)
{
	return {
		pow(_base.x, _exponent.x),
		pow(_base.y, _exponent.y),
		pow(_base.z, _exponent.z),
		pow(_base.w, _exponent.w)
	};
}

// radians functions
/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline simdfloat radians(const simdfloat& _x)
{
	return simd_mul_float(_x, simd_set1_float(3.1415927f / 180.0f));
}

/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline simdfloat radians(const float& _x)
{
	return simd_set1_float(_x * (3.1415927f / 180.0f));
}

/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline vec2 radians(const vec2& _x)
{
	return { radians(_x.x), radians(_x.y) };
}

/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline vec3 radians(const vec3& _x)
{
	return { radians(_x.x), radians(_x.y), radians(_x.z) };
}

/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline vec4 radians(const vec4& _x)
{
	return { radians(_x.x), radians(_x.y), radians(_x.z), radians(_x.w) };
}

// reflect functions
/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline simdfloat reflect(const float& _incident, const float& _normal)
{
	return _incident - 2.0f * dot(_normal, _incident) * _normal;
}

/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline simdfloat reflect(const simdfloat& _incident, const simdfloat& _normal)
{
	return _incident - 2.0f * dot(_normal, _incident) * _normal;
}

/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline vec2 reflect(const vec2& _incident, const vec2& _normal)
{
	return _incident - 2.0f * dot(_normal, _incident) * _normal;
}

/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline vec3 reflect(const vec3& _incident, const vec3& _normal)
{
	return _incident - 2.0f * dot(_normal, _incident) * _normal;
}

/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline vec4 reflect(const vec4& _incident, const vec4& _normal)
{
	return _incident - 2.0f * dot(_normal, _incident) * _normal;
}

// round functions
/**
 * @brief Rounds each component to the nearest integer.
 * @param _x The input value or vector.
 */
inline simdfloat round(const simdfloat& _x)
{
#ifdef USE_AVX512
	return _mm512_roundscale_ps(_x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
#elif defined (USE_SSE)
	return simd_add_float(simd_floor_float(simd_add_float(_x, simd_set1_float(0.5f))), simd_set1_float(0.0f));
#else
	return simd_round_float(_x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
#endif

}

/**
 * @brief Rounds each component to the nearest integer.
 * @param _x The input value or vector.
 */
inline vec2 round(const vec2& _x)
{
	return { round(_x.x), round(_x.y) };
}

/**
 * @brief Rounds each component to the nearest integer.
 * @param _x The input value or vector.
 */
inline vec3 round(const vec3& _x)
{
	return { round(_x.x), round(_x.y), round(_x.z) };
}

/**
 * @brief Rounds each component to the nearest integer.
 * @param _x The input value or vector.
 */
inline vec4 round(const vec4& _x)
{
	return { round(_x.x), round(_x.y), round(_x.z), round(_x.w) };
}

// sign functions
/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline simdfloat sign(const simdfloat& _x)
{
	simdmask _maskNeg = simd_cmp_float(_x, simd_set1_float(0.0f), _CMP_LT_OQ);
	simdmask _maskZero = simd_cmp_float(_x, simd_set1_float(0.0f), _CMP_EQ_OQ);
	simdfloat final = blendv(simd_set1_float(1.0f), simd_set1_float(-1.0f), _maskNeg);
	final = blendv(final, simd_set1_float(0.0f), _maskZero);
	return final;
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline simdfloat sign(const float& _x)
{
	return simd_set1_float((float)((_x > 0.0f) - (_x < 0.0f)));
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline vec2 sign(const vec2& _x)
{
	return { sign(_x.x), sign(_x.y) };
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline vec3 sign(const vec3& _x)
{
	return { sign(_x.x), sign(_x.y), sign(_x.z) };
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline vec4 sign(const vec4& _x)
{
	return { sign(_x.x), sign(_x.y), sign(_x.z), sign(_x.w) };
}

// sin functions
/**
 * @brief Computes the sine of each component.
 * @param _x The input value or vector.
 */
inline simdfloat sin(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_sin_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = sinf(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the sine of each component.
 * @param _x The input value or vector.
 */
inline vec2 sin(const vec2& _x)
{
	return { sin(_x.x), sin(_x.y) };
}

/**
 * @brief Computes the sine of each component.
 * @param _x The input value or vector.
 */
inline vec3 sin(const vec3& _x)
{
	return { sin(_x.x), sin(_x.y), sin(_x.z) };
}

/**
 * @brief Computes the sine of each component.
 * @param _x The input value or vector.
 */
inline vec4 sin(const vec4& _x)
{
	return { sin(_x.x), sin(_x.y), sin(_x.z), sin(_x.w) };
}

// sinh functions
/**
 * @brief Computes the hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline simdfloat sinh(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_sinh_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = sinhf(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline vec2 sinh(const vec2& _x)
{
	return { sinh(_x.x), sinh(_x.y) };
}

/**
 * @brief Computes the hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline vec3 sinh(const vec3& _x)
{
	return { sinh(_x.x), sinh(_x.y), sinh(_x.z) };
}

/**
 * @brief Computes the hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline vec4 sinh(const vec4& _x)
{
	return { sinh(_x.x), sinh(_x.y), sinh(_x.z), sinh(_x.w) };
}

// smoothstep functions
/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simdfloat smoothstep(const simdfloat& _edge0, const simdfloat& _edge1, const simdfloat& _x)
{
	simdfloat t = clamp((_x - _edge0) / (_edge1 - _edge0), 0.0f, 1.0f);
	return t * t * (3.0f - 2.0f * t);
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simdfloat smoothstep(const float& _edge0, const float& _edge1, const simdfloat& _x)
{
	return smoothstep(simd_set1_float(_edge0), simd_set1_float(_edge1), _x);
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simdfloat smoothstep(const float& _edge0, const float& _edge1, const float& _x)
{
	return smoothstep(simd_set1_float(_edge0), simd_set1_float(_edge1), simd_set1_float(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simdfloat smoothstep(const simdfloat& _edge0, const float& _edge1, const simdfloat& _x)
{
	return smoothstep(_edge0, simd_set1_float(_edge1), _x);
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simdfloat smoothstep(const float& _edge0, const simdfloat& _edge1, const simdfloat& _x)
{
	return smoothstep(simd_set1_float(_edge0), _edge1, _x);
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simdfloat smoothstep(const simdfloat& _edge0, const float& _edge1, const float& _x)
{
	return smoothstep(_edge0, simd_set1_float(_edge1), simd_set1_float(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simdfloat smoothstep(const float& _edge0, const simdfloat& _edge1, const float& _x)
{
	return smoothstep(simd_set1_float(_edge0), _edge1, simd_set1_float(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline vec2 smoothstep(const vec2& _edge0, const vec2& _edge1, const simdfloat& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x),
		smoothstep(_edge0.y, _edge1.y, _x)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline vec2 smoothstep(const vec2& _edge0, const vec2& _edge1, const float& _x)
{
	return smoothstep(_edge0, _edge1, simd_set1_float(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline vec2 smoothstep(const vec2& _edge0, const vec2& _edge1, const vec2& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x.x),
		smoothstep(_edge0.y, _edge1.y, _x.y)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline vec3 smoothstep(const vec3& _edge0, const vec3& _edge1, const simdfloat& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x),
		smoothstep(_edge0.y, _edge1.y, _x),
		smoothstep(_edge0.z, _edge1.z, _x)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline vec3 smoothstep(const vec3& _edge0, const vec3& _edge1, const float& _x)
{
	return smoothstep(_edge0, _edge1, simd_set1_float(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline vec3 smoothstep(const vec3& _edge0, const vec3& _edge1, const vec3& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x.x),
		smoothstep(_edge0.y, _edge1.y, _x.y),
		smoothstep(_edge0.z, _edge1.z, _x.z)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline vec4 smoothstep(const vec4& _edge0, const vec4& _edge1, const simdfloat& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x),
		smoothstep(_edge0.y, _edge1.y, _x),
		smoothstep(_edge0.z, _edge1.z, _x),
		smoothstep(_edge0.w, _edge1.w, _x)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline vec4 smoothstep(const vec4& _edge0, const vec4& _edge1, const float& _x)
{
	return smoothstep(_edge0, _edge1, simd_set1_float(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline vec4 smoothstep(const vec4& _edge0, const vec4& _edge1, const vec4& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x.x),
		smoothstep(_edge0.y, _edge1.y, _x.y),
		smoothstep(_edge0.z, _edge1.z, _x.z),
		smoothstep(_edge0.w, _edge1.w, _x.w)
	};
}

// step functions
/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline simdfloat step(const simdfloat& _edge, const simdfloat& _x)
{
	simdmask _mask = _x < _edge;
	return blendv(simd_set1_float(1.0f), simd_set1_float(0.0f), _mask);
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline simdfloat step(const float& _edge, const float& _x)
{
	return step(simd_set1_float(_edge), simd_set1_float(_x));
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline simdfloat step(const float& _edge, const simdfloat& _x)
{
	return step(simd_set1_float(_edge), _x);
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline simdfloat step(const simdfloat& _edge, const float& _x)
{
	return step(_edge, simd_set1_float(_x));
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline vec2 step(const vec2& _edge, const simdfloat& _x)
{
	return {
		step(_edge.x, _x),
		step(_edge.y, _x)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline vec2 step(const simdfloat& _edge, const vec2& _x)
{
	return {
		step(_edge, _x.x),
		step(_edge, _x.y)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline vec2 step(const vec2& _edge, const vec2& _x)
{
	return {
		step(_edge.x, _x.x),
		step(_edge.y, _x.y)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline vec3 step(const vec3& _edge, const simdfloat& _x)
{
	return {
		step(_edge.x, _x),
		step(_edge.y, _x),
		step(_edge.z, _x)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline vec3 step(const simdfloat& _edge, const vec3& _x)
{
	return {
		step(_edge, _x.x),
		step(_edge, _x.y),
		step(_edge, _x.z)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline vec3 step(const vec3& _edge, const vec3& _x)
{
	return {
		step(_edge.x, _x.x),
		step(_edge.y, _x.y),
		step(_edge.z, _x.z)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline vec4 step(const vec4& _edge, const simdfloat& _x)
{
	return {
		step(_edge.x, _x),
		step(_edge.y, _x),
		step(_edge.z, _x),
		step(_edge.w, _x)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline vec4 step(const simdfloat& _edge, const vec4& _x)
{
	return {
		step(_edge, _x.x),
		step(_edge, _x.y),
		step(_edge, _x.z),
		step(_edge, _x.w)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline vec4 step(const vec4& _edge, const vec4& _x)
{
	return {
		step(_edge.x, _x.x),
		step(_edge.y, _x.y),
		step(_edge.z, _x.z),
		step(_edge.w, _x.w)
	};
}

// sqrt functions
/**
 * @brief Computes the square root of each component.
 * @param _x The input value or vector.
 */
inline simdfloat sqrt(const simdfloat& _x)
{
	return simd_sqrt_float(_x);
}

/**
 * @brief Computes the square root of each component.
 * @param _x The input value or vector.
 */
inline vec2 sqrt(const vec2& _x)
{
	return {
		sqrt(_x.x),
		sqrt(_x.y)
	};
}

/**
 * @brief Computes the square root of each component.
 * @param _x The input value or vector.
 */
inline vec3 sqrt(const vec3& _x)
{
	return {
		sqrt(_x.x),
		sqrt(_x.y),
		sqrt(_x.z)
	};
}

/**
 * @brief Computes the square root of each component.
 * @param _x The input value or vector.
 */
inline vec4 sqrt(const vec4& _x)
{
	return {
		sqrt(_x.x),
		sqrt(_x.y),
		sqrt(_x.z),
		sqrt(_x.w)
	};
}

// refract functions
/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline vec2 refract(const vec2& _incident, const vec2& _normal, const simdfloat& _ior)
{
	simdfloat dotNI = dot(_normal, _incident);
	simdfloat k = 1.0f - _ior * _ior * (1.0f - dotNI * dotNI);
	return blendv(_ior * _incident - (_ior * dotNI + sqrt(k)) * _normal, vec2(0), k < 0.0f);
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline vec2 refract(const vec2& _incident, const vec2& _normal, const float& _ior)
{
	return refract(_incident, _normal, simd_set1_float(_ior));
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline vec3 refract(const vec3& _incident, const vec3& _normal, const simdfloat& _ior)
{
	simdfloat dotNI = dot(_normal, _incident);
	simdfloat k = 1.0f - _ior * _ior * (1.0f - dotNI * dotNI);
	return blendv(_ior * _incident - (_ior * dotNI + sqrt(k)) * _normal, vec3(0), k < 0.0f);
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline vec3 refract(const vec3& _incident, const vec3& _normal, const float& _ior)
{
	return refract(_incident, _normal, simd_set1_float(_ior));
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline vec4 refract(const vec4& _incident, const vec4& _normal, const simdfloat& _ior)
{
	simdfloat dotNI = dot(_normal, _incident);
	simdfloat k = 1.0f - _ior * _ior * (1.0f - dotNI * dotNI);
	return blendv(_ior * _incident - (_ior * dotNI + sqrt(k)) * _normal, vec4(0), k < 0.0f);
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline vec4 refract(const vec4& _incident, const vec4& _normal, const float& _ior)
{
	return refract(_incident, _normal, simd_set1_float(_ior));
}

// stanh functions
/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _x The input value or vector.
 */
inline simdfloat stanh(const simdfloat& _x)
{
	// approximate tanh using _a polynomial (5th degree)
	// tanh(_x) = _x * (27 + _x^2) / (27 + 9x^2)
	simdfloat x2 = simd_mul_float(_x, _x);
	simdfloat numerator = simd_mul_float(_x, simd_add_float(simd_set1_float(27.0f), x2));
	simdfloat denominator = simd_add_float(simd_set1_float(27.0f), simd_mul_float(simd_set1_float(9.0f), x2));
	return simd_div_float(numerator, denominator);
}

/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _x The input value or vector.
 */
inline simdfloat stanh(const float& _x)
{
	return stanh(simd_set1_float(_x));
}

/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _vec The input vector.
 */
inline vec2 stanh(const vec2& _vec)
{
	return {
		stanh(_vec.x),
		stanh(_vec.y)
	};
}

/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _vec The input vector.
 */
inline vec3 stanh(const vec3& _vec)
{
	return {
		stanh(_vec.x),
		stanh(_vec.y),
		stanh(_vec.z)
	};
}

/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _vec The input vector.
 */
inline vec4 stanh(const vec4& _vec)
{
	return {
		stanh(_vec.x),
		stanh(_vec.y),
		stanh(_vec.z),
		stanh(_vec.w)
	};
}

// tan functions
/**
 * @brief Computes the tangent of each component.
 * @param _x The input value or vector.
 */
inline simdfloat tan(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_tan_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = tanf(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the tangent of each component.
 * @param _x The input value or vector.
 */
inline vec2 tan(const vec2& _x)
{
	return {
		tan(_x.x),
		tan(_x.y)
	};
}

/**
 * @brief Computes the tangent of each component.
 * @param _x The input value or vector.
 */
inline vec3 tan(const vec3& _x)
{
	return {
		tan(_x.x),
		tan(_x.y),
		tan(_x.z)
	};
}

/**
 * @brief Computes the tangent of each component.
 * @param _x The input value or vector.
 */
inline vec4 tan(const vec4& _x)
{
	return {
		tan(_x.x),
		tan(_x.y),
		tan(_x.z),
		tan(_x.w)
	};
}

// tanh functions
/**
 * @brief Computes the hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline simdfloat tanh(const simdfloat& _x)
{
#ifndef __GNUC__
	return simd_tanh_float(_x);
#else
	alignas(SIMDWIDTH * 4) float tempTab[SIMDWIDTH];
	simd_store_float(tempTab, _x);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		tempTab[i] = tanhf(tempTab[i]);
	}
	return simd_load_float(tempTab);
#endif
}

/**
 * @brief Computes the hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline vec2 tanh(const vec2& _x)
{
	return {
		tanh(_x.x),
		tanh(_x.y)
	};
}

/**
 * @brief Computes the hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline vec3 tanh(const vec3& _x)
{
	return {
		tanh(_x.x),
		tanh(_x.y),
		tanh(_x.z)
	};
}

/**
 * @brief Computes the hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline vec4 tanh(const vec4& _x)
{
	return {
		tanh(_x.x),
		tanh(_x.y),
		tanh(_x.z),
		tanh(_x.w)
	};
}

// trunc functions
/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline simdfloat trunc(const simdfloat& _x)
{
#ifdef USE_AVX512
	return _mm512_roundscale_ps(_x, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
#elif defined (USE_SSE)
	return _mm_cvtepi32_ps(_mm_cvttps_epi32(_x));
#else
	return simd_round_float(_x, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
#endif
}

/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline simdfloat trunc(const float& _x)
{
	return simd_set1_float(_x - floorf(_x));
}

/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline vec2 trunc(const vec2& _x)
{
	return {
		trunc(_x.x),
		trunc(_x.y)
	};
}

/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline vec3 trunc(const vec3& _x)
{
	return {
		trunc(_x.x),
		trunc(_x.y),
		trunc(_x.z)
	};
}

/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline vec4 trunc(const vec4& _x)
{
	return {
		trunc(_x.x),
		trunc(_x.y),
		trunc(_x.z),
		trunc(_x.w)
	};
}

#pragma region matrix operators and functions

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline vec2 mul(const mat2& _mat, const vec2& _vec)
{
	return {
		dot({_mat.columns[0].x, _mat.columns[1].x}, _vec),
		dot({_mat.columns[0].y, _mat.columns[1].y}, _vec)
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline vec2 mul(const vec2& _vec, const mat2& _mat)
{
	return {
		dot(_vec, _mat.columns[0]),
		dot(_vec, _mat.columns[1])
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat2 mul(const mat2& _val1, const mat2& _val2)
{
	return {
		dot(vec2(_val1.columns[0].x, _val1.columns[1].x), _val2.columns[0]),
		dot(vec2(_val1.columns[0].y, _val1.columns[1].y), _val2.columns[0]),
		dot(vec2(_val1.columns[0].x, _val1.columns[1].x), _val2.columns[1]),
		dot(vec2(_val1.columns[0].y, _val1.columns[1].y), _val2.columns[1])
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline vec3 mul(const mat3& _mat, const vec3& _vec)
{
	return {
		dot({_mat.columns[0].x, _mat.columns[1].x, _mat.columns[2].x}, _vec),
		dot({_mat.columns[0].y, _mat.columns[1].y, _mat.columns[2].y}, _vec),
		dot({_mat.columns[0].z, _mat.columns[1].z, _mat.columns[2].z}, _vec)
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline vec3 mul(const vec3& _vec, const mat3& _mat)
{
	return {
		dot(_vec, _mat.columns[0]),
		dot(_vec, _mat.columns[1]),
		dot(_vec, _mat.columns[2])
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat3 mul(const mat3& _val1, const mat3& _val2)
{
	return {
		dot(vec3(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x), _val2.columns[0]),
		dot(vec3(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y), _val2.columns[0]),
		dot(vec3(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z), _val2.columns[0]),
		dot(vec3(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x), _val2.columns[1]),
		dot(vec3(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y), _val2.columns[1]),
		dot(vec3(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z), _val2.columns[1]),
		dot(vec3(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x), _val2.columns[2]),
		dot(vec3(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y), _val2.columns[2]),
		dot(vec3(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z), _val2.columns[2])
	};
}

// Mat4
/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline vec4 mul(const mat4& _mat, const vec4& _vec)
{
	return {
		dot({_mat.columns[0].x, _mat.columns[1].x, _mat.columns[2].x, _mat.columns[3].x}, _vec),
		dot({_mat.columns[0].y, _mat.columns[1].y, _mat.columns[2].y, _mat.columns[3].y}, _vec),
		dot({_mat.columns[0].z, _mat.columns[1].z, _mat.columns[2].z, _mat.columns[3].z}, _vec),
		dot({_mat.columns[0].w, _mat.columns[1].w, _mat.columns[2].w, _mat.columns[3].w}, _vec)
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline vec4 mul(const vec4& _vec, const mat4& _mat)
{
	return {
		dot(_vec, _mat.columns[0]),
		dot(_vec, _mat.columns[1]),
		dot(_vec, _mat.columns[2]),
		dot(_vec, _mat.columns[3])
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat4 mul(const mat4& _val1, const mat4& _val2)
{
	return {
		dot(vec4(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x, _val1.columns[3].x), _val2.columns[0]),
		dot(vec4(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y, _val1.columns[3].y), _val2.columns[0]),
		dot(vec4(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z, _val1.columns[3].z), _val2.columns[0]),
		dot(vec4(_val1.columns[0].w, _val1.columns[1].w, _val1.columns[2].w, _val1.columns[3].w), _val2.columns[0]),
		dot(vec4(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x, _val1.columns[3].x), _val2.columns[1]),
		dot(vec4(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y, _val1.columns[3].y), _val2.columns[1]),
		dot(vec4(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z, _val1.columns[3].z), _val2.columns[1]),
		dot(vec4(_val1.columns[0].w, _val1.columns[1].w, _val1.columns[2].w, _val1.columns[3].w), _val2.columns[1]),
		dot(vec4(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x, _val1.columns[3].x), _val2.columns[2]),
		dot(vec4(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y, _val1.columns[3].y), _val2.columns[2]),
		dot(vec4(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z, _val1.columns[3].z), _val2.columns[2]),
		dot(vec4(_val1.columns[0].w, _val1.columns[1].w, _val1.columns[2].w, _val1.columns[3].w), _val2.columns[2]),
		dot(vec4(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x, _val1.columns[3].x), _val2.columns[3]),
		dot(vec4(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y, _val1.columns[3].y), _val2.columns[3]),
		dot(vec4(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z, _val1.columns[3].z), _val2.columns[3]),
		dot(vec4(_val1.columns[0].w, _val1.columns[1].w, _val1.columns[2].w, _val1.columns[3].w), _val2.columns[3])
	};
}

#pragma endregion

#pragma region matrix operators
// Matrix operators
/**
 * @brief Overloaded addition operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat2 operator+(const mat2& _val1, const mat2& _val2)
{
	return {
		_val1.columns[0] + _val2.columns[0],
		_val1.columns[1] + _val2.columns[1]
	};
}

/**
 * @brief Overloaded subtraction operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat2 operator-(const mat2& _val1, const mat2& _val2)
{
	return {
		_val1.columns[0] - _val2.columns[0],
		_val1.columns[1] - _val2.columns[1]
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat2 operator*(const mat2& _val1, const mat2& _val2)
{
	return mul(_val1, _val2);
}

/**
 * @brief Overloaded addition-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat2 operator+=(mat2& _val1, const mat2& _val2)
{
	_val1 = _val1 + _val2;
	return _val1;
}

/**
 * @brief Overloaded subtraction-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat2 operator-=(mat2& _val1, const mat2& _val2)
{
	_val1 = _val1 - _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat2 operator*=(mat2& _val1, const mat2& _val2)
{
	_val1 = _val1 * _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline mat2 operator*(const mat2& _mat, const simdfloat& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline mat2 operator*(const simdfloat& _scalar, const mat2& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline mat2 operator*(const mat2& _mat, const float& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline mat2 operator*(const float& _scalar, const mat2& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar
	};
}

// Matrix vector multiplication
/**
 * @brief Overloaded multiplication operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline vec2 operator*(const vec2& _vec, const mat2& _mat)
{
	return mul(_vec, _mat);
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline vec2 operator*(const mat2& _mat, const vec2& _vec)
{
	return mul(_mat, _vec);
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline vec2 operator*=(vec2& _vec, const mat2& _mat)
{
	_vec = mul(_vec, _mat);
	return _vec;
}

// Mat3 multiplication
/**
 * @brief Overloaded addition operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat3 operator+(const mat3& _val1, const mat3& _val2)
{
	return {
		_val1.columns[0] + _val2.columns[0],
		_val1.columns[1] + _val2.columns[1],
		_val1.columns[2] + _val2.columns[2]
	};
}

/**
 * @brief Overloaded subtraction operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat3 operator-(const mat3& _val1, const mat3& _val2)
{
	return {
		_val1.columns[0] - _val2.columns[0],
		_val1.columns[1] - _val2.columns[1],
		_val1.columns[2] - _val2.columns[2]
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat3 operator*(const mat3& _val1, const mat3& _val2)
{
	return mul(_val1, _val2);
}

/**
 * @brief Overloaded addition-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat3 operator+=(mat3& _val1, const mat3& _val2)
{
	_val1 = _val1 + _val2;
	return _val1;
}

/**
 * @brief Overloaded subtraction-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat3 operator-=(mat3& _val1, const mat3& _val2)
{
	_val1 = _val1 - _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat3 operator*=(mat3& _val1, const mat3& _val2)
{
	_val1 = _val1 * _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline mat3 operator*(const mat3& _mat, const simdfloat& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline mat3 operator*(const simdfloat& _scalar, const mat3& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline mat3 operator*(const mat3& _mat, const float& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline mat3 operator*(const float& _scalar, const mat3& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar
	};
}

// Matrix vector multiplication
/**
 * @brief Overloaded multiplication operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline vec3 operator*(const vec3& _vec, const mat3& _mat)
{
	return mul(_vec, _mat);
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline vec3 operator*(const mat3& _mat, const vec3& _vec)
{
	return mul(_mat, _vec);
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline vec3 operator*=(vec3& _vec, const mat3& _mat)
{
	_vec = mul(_vec, _mat);
	return _vec;
}

// Mat4 multiplication
/**
 * @brief Overloaded addition operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat4 operator+(const mat4& _val1, const mat4& _val2)
{
	return {
		_val1.columns[0] + _val2.columns[0],
		_val1.columns[1] + _val2.columns[1],
		_val1.columns[2] + _val2.columns[2],
		_val1.columns[3] + _val2.columns[3]
	};
}

/**
 * @brief Overloaded subtraction operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat4 operator-(const mat4& _val1, const mat4& _val2)
{
	return {
		_val1.columns[0] - _val2.columns[0],
		_val1.columns[1] - _val2.columns[1],
		_val1.columns[2] - _val2.columns[2],
		_val1.columns[3] - _val2.columns[3]
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat4 operator*(const mat4& _val1, const mat4& _val2)
{
	return mul(_val1, _val2);
}

/**
 * @brief Overloaded addition-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat4 operator+=(mat4& _val1, const mat4& _val2)
{
	_val1 = _val1 + _val2;
	return _val1;
}

/**
 * @brief Overloaded subtraction-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat4 operator-=(mat4& _val1, const mat4& _val2)
{
	_val1 = _val1 - _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline mat4 operator*=(mat4& _val1, const mat4& _val2)
{
	_val1 = _val1 * _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline mat4 operator*(const mat4& _mat, const simdfloat& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar,
		_mat.columns[3] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline mat4 operator*(const simdfloat& _scalar, const mat4& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar,
		_mat.columns[3] * _scalar
	};
}

// Matrix vector multiplication
/**
 * @brief Overloaded multiplication operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline vec4 operator*(const vec4& _vec, const mat4& _mat)
{
	return mul(_vec, _mat);
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline vec4 operator*(const mat4& _mat, const vec4& _vec)
{
	return mul(_mat, _vec);
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline vec4 operator*=(vec4& _vec, const mat4& _mat)
{
	_vec = mul(_vec, _mat);
	return _vec;
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline mat4 operator*(const mat4& _mat, const float& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar,
		_mat.columns[3] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline mat4 operator*(const float& _scalar, const mat4& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar,
		_mat.columns[3] * _scalar
	};
}

// determinant for matrices
/**
 * @brief Computes the determinant of a matrix.
 * @param _mat The input matrix.
 */
inline simdfloat determinant(const mat2& _mat)
{
	return _mat.columns[0].x * _mat.columns[1].y - _mat.columns[0].y * _mat.columns[1].x;
}

/**
 * @brief Computes the determinant of a matrix.
 * @param _mat The input matrix.
 */
inline simdfloat determinant(const mat3& _mat)
{
	return _mat.columns[0].x * (_mat.columns[1].y * _mat.columns[2].z - _mat.columns[1].z * _mat.columns[2].y) -
		_mat.columns[0].y * (_mat.columns[1].x * _mat.columns[2].z - _mat.columns[1].z * _mat.columns[2].x) +
		_mat.columns[0].z * (_mat.columns[1].x * _mat.columns[2].y - _mat.columns[1].y * _mat.columns[2].x);
}

/**
 * @brief Computes the determinant of a matrix.
 * @param _mat The input matrix.
 */
inline simdfloat determinant(const mat4& _mat)
{
	return _mat.columns[0].x * (_mat.columns[1].y * (_mat.columns[2].z * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].z) -
		_mat.columns[1].z * (_mat.columns[2].y * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].y) +
		_mat.columns[1].w * (_mat.columns[2].y * _mat.columns[3].z - _mat.columns[2].z * _mat.columns[3].y)) -
		_mat.columns[0].y * (_mat.columns[1].x * (_mat.columns[2].z * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].z) -
			_mat.columns[1].z * (_mat.columns[2].x * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].x) +
			_mat.columns[1].w * (_mat.columns[2].x * _mat.columns[3].z - _mat.columns[2].z * _mat.columns[3].x)) +
		_mat.columns[0].z * (_mat.columns[1].x * (_mat.columns[2].y * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].y) -
			_mat.columns[1].y * (_mat.columns[2].x * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].x) +
			_mat.columns[1].w * (_mat.columns[2].x * _mat.columns[3].y - _mat.columns[2].y * _mat.columns[3].x)) -
		_mat.columns[0].w * (_mat.columns[1].x * (_mat.columns[2].y * _mat.columns[3].z - _mat.columns[2].z * _mat.columns[3].y) -
			_mat.columns[1].y * (_mat.columns[2].x * _mat.columns[3].z - _mat.columns[2].z * _mat.columns[3].x) +
			_mat.columns[1].z * (_mat.columns[2].x * _mat.columns[3].y - _mat.columns[2].y * _mat.columns[3].x));
}

// inverse for matrices
/**
 * @brief Computes the inverse of a matrix.
 * @param _mat The input matrix.
 */
inline mat2 inverse(const mat2& _mat)
{
	return {
		vec2(_mat.columns[1].y, -_mat.columns[0].y) / determinant(_mat),
		vec2(-_mat.columns[1].x, _mat.columns[0].x) / determinant(_mat)
	};
}

/**
 * @brief Computes the inverse of a matrix.
 * @param _mat The input matrix.
 */
inline mat3 inverse(const mat3& _mat)
{
	return {
		vec3(_mat.columns[1].y * _mat.columns[2].z - _mat.columns[1].z * _mat.columns[2].y, _mat.columns[0].z * _mat.columns[2].y - _mat.columns[0].y * _mat.columns[2].z, _mat.columns[0].y * _mat.columns[1].z - _mat.columns[0].z * _mat.columns[1].y) / determinant(_mat),
		vec3(_mat.columns[1].z * _mat.columns[2].x - _mat.columns[1].x * _mat.columns[2].z, _mat.columns[0].x * _mat.columns[2].z - _mat.columns[0].z * _mat.columns[2].x, _mat.columns[0].z * _mat.columns[1].x - _mat.columns[0].x * _mat.columns[1].z) / determinant(_mat),
		vec3(_mat.columns[1].x * _mat.columns[2].y - _mat.columns[1].y * _mat.columns[2].x, _mat.columns[0].y * _mat.columns[2].x - _mat.columns[0].x * _mat.columns[2].y, _mat.columns[0].x * _mat.columns[1].y - _mat.columns[0].y * _mat.columns[1].x) / determinant(_mat)
	};
}

/**
 * @brief Computes the inverse of a matrix.
 * @param _mat The input matrix.
 */
inline mat4 inverse(const mat4& _mat)
{
	return {
		vec4(_mat.columns[1].y * _mat.columns[2].z * _mat.columns[3].w - _mat.columns[1].y * _mat.columns[2].w * _mat.columns[3].z - _mat.columns[1].z * _mat.columns[2].y * _mat.columns[3].w + _mat.columns[1].z * _mat.columns[2].w * _mat.columns[3].y + _mat.columns[1].w * _mat.columns[2].y * _mat.columns[3].z - _mat.columns[1].w * _mat.columns[2].z * _mat.columns[3].y, -_mat.columns[0].y * _mat.columns[2].z * _mat.columns[3].w + _mat.columns[0].y * _mat.columns[2].w * _mat.columns[3].z + _mat.columns[0].z * _mat.columns[2].y * _mat.columns[3].w - _mat.columns[0].z * _mat.columns[2].w * _mat.columns[3].y - _mat.columns[0].w * _mat.columns[2].y * _mat.columns[3].z + _mat.columns[0].w * _mat.columns[2].z * _mat.columns[3].y, _mat.columns[0].y * _mat.columns[1].z * _mat.columns[3].w - _mat.columns[0].y * _mat.columns[1].w * _mat.columns[3].z - _mat.columns[0].z * _mat.columns[1].y * _mat.columns[3].w + _mat.columns[0].z * _mat.columns[1].w * _mat.columns[3].y + _mat.columns[0].w * _mat.columns[1].y * _mat.columns[3].z - _mat.columns[0].w * _mat.columns[1].z * _mat.columns[3].y, -_mat.columns[0].y * _mat.columns[1].z * _mat.columns[2].w + _mat.columns[0].y * _mat.columns[1].w * _mat.columns[2].z + _mat.columns[0].z * _mat.columns[1].y * _mat.columns[2].w - _mat.columns[0].z * _mat.columns[1].w * _mat.columns[2].y - _mat.columns[0].w * _mat.columns[1].y * _mat.columns[2].z + _mat.columns[0].w * _mat.columns[1].z * _mat.columns[2].y) / determinant(_mat),
		vec4(-_mat.columns[1].x * _mat.columns[2].z * _mat.columns[3].w + _mat.columns[1].x * _mat.columns[2].w * _mat.columns[3].z + _mat.columns[1].z * _mat.columns[2].x * _mat.columns[3].w - _mat.columns[1].z * _mat.columns[2].w * _mat.columns[3].x - _mat.columns[1].w * _mat.columns[2].x * _mat.columns[3].z + _mat.columns[1].w * _mat.columns[2].z * _mat.columns[3].x, _mat.columns[0].x * _mat.columns[2].z * _mat.columns[3].w - _mat.columns[0].x * _mat.columns[2].w * _mat.columns[3].z - _mat.columns[0].z * _mat.columns[2].x * _mat.columns[3].w + _mat.columns[0].z * _mat.columns[2].w * _mat.columns[3].x + _mat.columns[0].w * _mat.columns[2].x * _mat.columns[3].z - _mat.columns[0].w * _mat.columns[2].z * _mat.columns[3].x, -_mat.columns[0].x * _mat.columns[1].z * _mat.columns[3].w + _mat.columns[0].x * _mat.columns[1].w * _mat.columns[3].z + _mat.columns[0].z * _mat.columns[1].x * _mat.columns[3].w - _mat.columns[0].z * _mat.columns[1].w * _mat.columns[3].x - _mat.columns[0].w * _mat.columns[1].x * _mat.columns[3].z + _mat.columns[0].w * _mat.columns[1].z * _mat.columns[3].x, 	_mat.columns[0].x * _mat.columns[1].z * _mat.columns[2].w - _mat.columns[0].x * _mat.columns[1].w * _mat.columns[2].z - _mat.columns[0].z * _mat.columns[1].x * _mat.columns[2].w + _mat.columns[0].z * _mat.columns[1].w * _mat.columns[2].x + _mat.columns[0].w * _mat.columns[1].x * _mat.columns[2].z - _mat.columns[0].w * _mat.columns[1].z * _mat.columns[2].x) / determinant(_mat),
		vec4(_mat.columns[1].x * _mat.columns[2].y * _mat.columns[3].w - _mat.columns[1].x * _mat.columns[2].w * _mat.columns[3].y - _mat.columns[1].y * _mat.columns[2].x * _mat.columns[3].w + _mat.columns[1].y * _mat.columns[2].w * _mat.columns[3].x + _mat.columns[1].w * _mat.columns[2].x * _mat.columns[3].y - _mat.columns[1].w * _mat.columns[2].y * _mat.columns[3].x, -_mat.columns[0].x * _mat.columns[2].y * _mat.columns[3].w + _mat.columns[0].x * _mat.columns[2].w * _mat.columns[3].y + _mat.columns[0].y * _mat.columns[2].x * _mat.columns[3].w - _mat.columns[0].y * _mat.columns[2].w * _mat.columns[3].x - _mat.columns[0].w * _mat.columns[2].x * _mat.columns[3].y + _mat.columns[0].w * _mat.columns[2].y * _mat.columns[3].x, 	_mat.columns[0].x * _mat.columns[1].y * _mat.columns[3].w - _mat.columns[0].x * _mat.columns[1].w * _mat.columns[3].y - _mat.columns[0].y * _mat.columns[1].x * _mat.columns[3].w + _mat.columns[0].y * _mat.columns[1].w * _mat.columns[3].x + _mat.columns[0].w * _mat.columns[1].x * _mat.columns[3].y - _mat.columns[0].w * _mat.columns[1].y * _mat.columns[3].x, 	-_mat.columns[0].x * _mat.columns[1].y * _mat.columns[2].w + _mat.columns[0].x * _mat.columns[1].w * _mat.columns[2].y + _mat.columns[0].y * _mat.columns[1].x * _mat.columns[2].w - _mat.columns[0].y * _mat.columns[1].w * _mat.columns[2].x - _mat.columns[0].w * _mat.columns[1].x * _mat.columns[2].y + _mat.columns[0].w * _mat.columns[1].y * _mat.columns[2].x) / determinant(_mat),
		vec4(-_mat.columns[1].x * _mat.columns[2].y * _mat.columns[3].z + _mat.columns[1].x * _mat.columns[2].z * _mat.columns[3].y + _mat.columns[1].y * _mat.columns[2].x * _mat.columns[3].z - _mat.columns[1].y * _mat.columns[2].z * _mat.columns[3].x - _mat.columns[1].z * _mat.columns[2].x * _mat.columns[3].y + _mat.columns[1].z * _mat.columns[2].y * _mat.columns[3].x, 	_mat.columns[0].x * _mat.columns[2].y * _mat.columns[3].z - _mat.columns[0].x * _mat.columns[2].z * _mat.columns[3].y - _mat.columns[0].y * _mat.columns[2].x * _mat.columns[3].z + _mat.columns[0].y * _mat.columns[2].z * _mat.columns[3].x + _mat.columns[0].z * _mat.columns[2].x * _mat.columns[3].y - _mat.columns[0].z * _mat.columns[2].y * _mat.columns[3].x, 	-_mat.columns[0].x * _mat.columns[1].y * _mat.columns[3].z + _mat.columns[0].x * _mat.columns[1].z * _mat.columns[3].y + _mat.columns[0].y * _mat.columns[1].x * _mat.columns[3].z - _mat.columns[0].y * _mat.columns[1].z * _mat.columns[3].x - _mat.columns[0].z * _mat.columns[1].x * _mat.columns[3].y + _mat.columns[0].z * _mat.columns[1].y * _mat.columns[3].x, 	_mat.columns[0].x * _mat.columns[1].y * _mat.columns[2].z - _mat.columns[0].x * _mat.columns[1].z * _mat.columns[2].y - _mat.columns[0].y * _mat.columns[1].x * _mat.columns[2].z + _mat.columns[0].y * _mat.columns[1].z * _mat.columns[2].x + _mat.columns[0].z * _mat.columns[1].x * _mat.columns[2].y - _mat.columns[0].z * _mat.columns[1].y * _mat.columns[2].x) / determinant(_mat)
	};
}

// transpose for matrices
/**
 * @brief Computes the transpose of a matrix.
 * @param _mat The input matrix.
 */
inline mat2 transpose(const mat2& _mat)
{
	return {
		vec2(_mat.columns[0].x, _mat.columns[1].x),
		vec2(_mat.columns[0].y, _mat.columns[1].y)
	};
}

/**
 * @brief Computes the transpose of a matrix.
 * @param _mat The input matrix.
 */
inline mat3 transpose(const mat3& _mat)
{
	return {
		vec3(_mat.columns[0].x, _mat.columns[1].x, _mat.columns[2].x),
		vec3(_mat.columns[0].y, _mat.columns[1].y, _mat.columns[2].y),
		vec3(_mat.columns[0].z, _mat.columns[1].z, _mat.columns[2].z)
	};
}

/**
 * @brief Computes the transpose of a matrix.
 * @param _mat The input matrix.
 */
inline mat4 transpose(const mat4& _mat)
{
	return {
		vec4(_mat.columns[0].x, _mat.columns[1].x, _mat.columns[2].x, _mat.columns[3].x),
		vec4(_mat.columns[0].y, _mat.columns[1].y, _mat.columns[2].y, _mat.columns[3].y),
		vec4(_mat.columns[0].z, _mat.columns[1].z, _mat.columns[2].z, _mat.columns[3].z),
		vec4(_mat.columns[0].w, _mat.columns[1].w, _mat.columns[2].w, _mat.columns[3].w)
	};
}

#pragma endregion
#pragma endregion float functions

#pragma region double functions

// acosh functions
/**
 * @brief Computes the inverse hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline simddouble acosh(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_acosh_double(_x);

#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = acoshf(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}


/**
 * @brief Computes the inverse hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec2 acosh(const dvec2& _x)
{
	return { acosh(_x.x), acosh(_x.y) };
}

/**
 * @brief Computes the inverse hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec3 acosh(const dvec3& _x)
{
	return { acosh(_x.x), acosh(_x.y), acosh(_x.z) };
}

/**
 * @brief Computes the inverse hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec4 acosh(const dvec4& _x)
{
	return { acosh(_x.x), acosh(_x.y), acosh(_x.z), acosh(_x.w) };
}

// asinh functions
/**
 * @brief Computes the inverse hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline simddouble asinh(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_asinh_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = std::asinh(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}


/**
 * @brief Computes the inverse hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline dvec2 asinh(const dvec2& _x)
{
	return { asinh(_x.x), asinh(_x.y) };
}

/**
 * @brief Computes the inverse hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline dvec3 asinh(const dvec3& _x)
{
	return { asinh(_x.x), asinh(_x.y), asinh(_x.z) };
}

/**
 * @brief Computes the inverse hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline dvec4 asinh(const dvec4& _x)
{
	return { asinh(_x.x), asinh(_x.y), asinh(_x.z), asinh(_x.w) };
}

// atan functions
/**
 * @brief Computes the inverse tangent.
 * @param _x The input value or vector.
 */
inline simddouble atan(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_atan_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = std::atan(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the inverse tangent.
 * @param _x The input value or vector.
 */
inline dvec2 atan(const dvec2& _x)
{
	return { atan(_x.x), atan(_x.y) };
}

/**
 * @brief Computes the inverse tangent.
 * @param _x The input value or vector.
 */
inline dvec3 atan(const dvec3& _x)
{
	return { atan(_x.x), atan(_x.y), atan(_x.z) };
}

/**
 * @brief Computes the inverse tangent.
 * @param _x The input value or vector.
 */
inline dvec4 atan(const dvec4& _x)
{
	return { atan(_x.x), atan(_x.y), atan(_x.z), atan(_x.w) };
}

// atan2 functions
/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline simddouble atan(const simddouble& _y, const simddouble& _x)
{
#ifndef __GNUC__
	return simd_atan2_double(_y, _x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTaba[HALFSIMDWIDTH];
	alignas(HALFSIMDWIDTH * 8) double tempTabb[HALFSIMDWIDTH];
	simd_store_double(tempTaba, _y);
	simd_store_double(tempTabb, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTaba[i] = std::atan2(tempTaba[i], tempTabb[i]);
	}
	return simd_load_double(tempTaba);
#endif
}

/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline dvec2 atan(const dvec2& _y, const dvec2& _x)
{
	return { atan(_y.x, _x.x), atan(_y.y, _x.y) };
}

/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline dvec3 atan(const dvec3& _y, const dvec3& _x)
{
	return { atan(_y.x, _x.x), atan(_y.y, _x.y), atan(_y.z, _x.z) };
}

/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline dvec4 atan(const dvec4& _y, const dvec4& _x)
{
	return { atan(_y.x, _x.x), atan(_y.y, _x.y), atan(_y.z, _x.z), atan(_y.w, _x.w)};
}

/**
 * @brief Computes the 2-argument inverse tangent.
 * @param _y The y-component for 2-argument atan.
 * @param _x The input value or vector.
 */
inline simddouble atan(const double& _y, const double& _x)
{
	return simd_set1_double(std::atan2(_y, _x));
}

// atanh functions
/**
 * @brief Computes the inverse hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline simddouble atanh(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_atanh_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = atanh(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the inverse hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline dvec2 atanh(const dvec2& _x)
{
	return { atanh(_x.x), atanh(_x.y) };
}

/**
 * @brief Computes the inverse hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline dvec3 atanh(const dvec3& _x)
{
	return { atanh(_x.x), atanh(_x.y), atanh(_x.z) };
}

/**
 * @brief Computes the inverse hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline dvec4 atanh(const dvec4& _x)
{
	return { atanh(_x.x), atanh(_x.y), atanh(_x.z), atanh(_x.w) };
}

// blendv functions
/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simddouble blendv(const simddouble& _falseval, const simddouble& _trueval, const simddmask& _mask)
{
#ifdef USE_AVX512
	return _mm512_mask_blend_pd(_mask, _falseval, _trueval);
#else
	return simd_blendv_double(_falseval, _trueval, _mask);
#endif
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simddouble blendv(const double& _falseval, const double& _trueval, const simddmask& _mask)
{
	return blendv(simd_set1_double(_falseval), simd_set1_double(_trueval), _mask);
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simddouble blendv(const simddouble& _falseval, const double& _trueval, const simddmask& _mask)
{
	return blendv(_falseval, simd_set1_double(_trueval), _mask);

}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simddouble blendv(const double& _falseval, const simddouble& _trueval, const simddmask& _mask)
{
	return blendv(simd_set1_double(_falseval), _trueval, _mask);

}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline dvec2 blendv(const dvec2& _falseval, const dvec2& _trueval, const simddmask& _mask)
{
	return {
		blendv(_falseval.x, _trueval.x, _mask),
		blendv(_falseval.y, _trueval.y, _mask)
	};
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline dvec3 blendv(const dvec3& _falseval, const dvec3& _trueval, const simddmask& _mask)
{
	return {
		blendv(_falseval.x, _trueval.x, _mask),
		blendv(_falseval.y, _trueval.y, _mask),
		blendv(_falseval.z, _trueval.z, _mask)
	};
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline dvec4 blendv(const dvec4& _falseval, const dvec4& _trueval, const simddmask& _mask)
{
	return {
		blendv(_falseval.x, _trueval.x, _mask),
		blendv(_falseval.y, _trueval.y, _mask),
		blendv(_falseval.z, _trueval.z, _mask),
		blendv(_falseval.w, _trueval.w, _mask)
	};
}

// abs functions
/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline simddouble abs(const simddouble& _x)
{
	return blendv(_x, -_x, _x < 0.0);
}

/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline dvec2 abs(const dvec2& _x)
{
	return { abs(_x.x), abs(_x.y) };
}

/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline dvec3 abs(const dvec3& _x)
{
	return { abs(_x.x), abs(_x.y), abs(_x.z) };
}

/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline dvec4 abs(const dvec4& _x)
{
	return { abs(_x.x), abs(_x.y), abs(_x.z), abs(_x.w) };
}

// ceil functions
/**
 * @brief Rounds each component up to the nearest integer.
 * @param _x The input value or vector.
 */
inline simddouble ceil(const simddouble& _x)
{
	return simd_ceil_double(_x);
}

/**
 * @brief Rounds each component up to the nearest integer.
 * @param _x The input value or vector.
 */
inline dvec2 ceil(const dvec2& _x)
{
	return { ceil(_x.x), ceil(_x.y) };
}

/**
 * @brief Rounds each component up to the nearest integer.
 * @param _x The input value or vector.
 */
inline dvec3 ceil(const dvec3& _x)
{
	return { ceil(_x.x), ceil(_x.y), ceil(_x.z) };
}

/**
 * @brief Rounds each component up to the nearest integer.
 * @param _x The input value or vector.
 */
inline dvec4 ceil(const dvec4& _x)
{
	return { ceil(_x.x), ceil(_x.y), ceil(_x.z), ceil(_x.w) };
}

// max functions
/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble max(const simddouble& _val1, const simddouble& _val2)
{
	return simd_max_double(_val1, _val2);
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble max(const simddouble& _val1, const double& _val2)
{
	return max(_val1, simd_set1_double(_val2));
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble max(const double& _val1, const simddouble& _val2)
{
	return max(simd_set1_double(_val1), _val2);
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble max(const double& _val1, const double& _val2)
{
	return max(simd_set1_double(_val1), simd_set1_double(_val2));
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 max(const dvec2& _val1, const simddouble& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 max(const simddouble& _val1, const dvec2& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 max(const dvec2& _val1, const double& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 max(const double& _val1, const dvec2& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 max(const dvec2& _val1, const dvec2& _val2)
{
	return {
		max(_val1.x, _val2.x),
		max(_val1.y, _val2.y)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 max(const dvec3& _val1, const simddouble& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 max(const simddouble& _val1, const dvec3& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 max(const dvec3& _val1, const double& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 max(const double& _val1, const dvec3& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 max(const dvec3& _val1, const dvec3& _val2)
{
	return {
		max(_val1.x, _val2.x),
		max(_val1.y, _val2.y),
		max(_val1.z, _val2.z)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 max(const dvec4& _val1, const simddouble& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2),
		max(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 max(const simddouble& _val1, const dvec4& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z),
		max(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 max(const dvec4& _val1, const double& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2),
		max(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 max(const double& _val1, const dvec4& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z),
		max(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 max(const dvec4& _val1, const dvec4& _val2)
{
	return {
		max(_val1.x, _val2.x),
		max(_val1.y, _val2.y),
		max(_val1.z, _val2.z),
		max(_val1.w, _val2.w)
	};
}

// min functions
/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble min(const simddouble& _val1, const simddouble& _val2)
{
	return simd_min_double(_val1, _val2);
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble min(const simddouble& _val1, const double& _val2)
{
	return min(_val1, simd_set1_double(_val2));
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble min(const double& _val1, const simddouble& _val2)
{
	return min(simd_set1_double(_val1), _val2);
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble min(const double& _val1, const double& _val2)
{
	return min(simd_set1_double(_val1), simd_set1_double(_val2));
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 min(const dvec2& _val1, const simddouble& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 min(const simddouble& _val1, const dvec2& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 min(const dvec2& _val1, const double& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 min(const double& _val1, const dvec2& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec2 min(const dvec2& _val1, const dvec2& _val2)
{
	return {
		min(_val1.x, _val2.x),
		min(_val1.y, _val2.y)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 min(const dvec3& _val1, const simddouble& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 min(const simddouble& _val1, const dvec3& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 min(const dvec3& _val1, const double& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 min(const double& _val1, const dvec3& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 min(const dvec3& _val1, const dvec3& _val2)
{
	return {
		min(_val1.x, _val2.x),
		min(_val1.y, _val2.y),
		min(_val1.z, _val2.z)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 min(const dvec4& _val1, const simddouble& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2),
		min(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 min(const simddouble& _val1, const dvec4& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z),
		min(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 min(const dvec4& _val1, const double& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2),
		min(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 min(const double& _val1, const dvec4& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z),
		min(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec4 min(const dvec4& _val1, const dvec4& _val2)
{
	return {
		min(_val1.x, _val2.x),
		min(_val1.y, _val2.y),
		min(_val1.z, _val2.z),
		min(_val1.w, _val2.w)
	};
}

// clamp functions
/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simddouble clamp(const simddouble& _x, const simddouble& _minval, const simddouble& _maxval)
{
	return max(min(_x, _maxval), _minval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simddouble clamp(const double& _x, const double& _minval, const double& _maxval)
{
	return clamp(simd_set1_double(_x), simd_set1_double(_minval), simd_set1_double(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simddouble clamp(const double& _x, const double& _minval, const simddouble& _maxval)
{
	return clamp(simd_set1_double(_x), simd_set1_double(_minval), _maxval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simddouble clamp(const double& _x, const simddouble& _minval, const double& _maxval)
{
	return clamp(simd_set1_double(_x), _minval, simd_set1_double(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simddouble clamp(const double& _x, const simddouble& _minval, const simddouble& _maxval)
{
	return clamp(simd_set1_double(_x), _minval, _maxval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simddouble clamp(const simddouble& _x, const double& _minval, const double& _maxval)
{
	return clamp(_x, simd_set1_double(_minval), simd_set1_double(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simddouble clamp(const simddouble& _x, const double& _minval, const simddouble& _maxval)
{
	return clamp(_x, simd_set1_double(_minval), _maxval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simddouble clamp(const simddouble& _x, const simddouble& _minval, const double& _maxval)
{
	return clamp(_x, _minval, simd_set1_double(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec2 clamp(const dvec2& _x, const simddouble& _minval, const simddouble& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec2 clamp(const dvec2& _x, const double& _minval, const double& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec2 clamp(const dvec2& _x, const simddouble& _minval, const double& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec2 clamp(const dvec2& _x, const double& _minval, const simddouble& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec2 clamp(const dvec2& _x, const dvec2& _minval, const dvec2& _maxval)
{
	return {
		clamp(_x.x, _minval.x, _maxval.x),
		clamp(_x.y, _minval.y, _maxval.y)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec3 clamp(const dvec3& _x, const simddouble& _minval, const simddouble& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec3 clamp(const dvec3& _x, const double& _minval, const double& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec3 clamp(const dvec3& _x, const simddouble& _minval, const double& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec3 clamp(const dvec3& _x, const double& _minval, const simddouble& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec3 clamp(const dvec3& _x, const dvec3& _minval, const dvec3& _maxval)
{
	return {
		clamp(_x.x, _minval.x, _maxval.x),
		clamp(_x.y, _minval.y, _maxval.y),
		clamp(_x.z, _minval.z, _maxval.z)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec4 clamp(const dvec4& _x, const simddouble& _minval, const simddouble& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec4 clamp(const dvec4& _x, const double& _minval, const double& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec4 clamp(const dvec4& _x, const simddouble& _minval, const double& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec4 clamp(const dvec4& _x, const double& _minval, const simddouble& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline dvec4 clamp(const dvec4& _x, const dvec4& _minval, const dvec4& _maxval)
{
	return {
		clamp(_x.x, _minval.x, _maxval.x),
		clamp(_x.y, _minval.y, _maxval.y),
		clamp(_x.z, _minval.z, _maxval.z),
		clamp(_x.w, _minval.w, _maxval.w)
	};
}

// acos functions
/**
 * @brief Computes the inverse cosine of each component.
 * @param _x The input value or vector.
 */
inline simddouble acos(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_acos_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = std::acos(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the inverse cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec2 acos(const dvec2& _x)
{
	return { acos(_x.x), acos(_x.y) };
}

/**
 * @brief Computes the inverse cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec3 acos(const dvec3& _x)
{
	return { acos(_x.x), acos(_x.y), acos(_x.z) };
}

/**
 * @brief Computes the inverse cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec4 acos(const dvec4& _x)
{
	return { acos(_x.x), acos(_x.y), acos(_x.z), acos(_x.w) };
}

// asin functions
/**
 * @brief Computes the inverse sine of each component.
 * @param _x The input value or vector.
 */
inline simddouble asin(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_asin_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = asinf(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the inverse sine of each component.
 * @param _x The input value or vector.
 */
inline dvec2 asin(const dvec2& _x)
{
	return { asin(_x.x), asin(_x.y) };
}

/**
 * @brief Computes the inverse sine of each component.
 * @param _x The input value or vector.
 */
inline dvec3 asin(const dvec3& _x)
{
	return { asin(_x.x), asin(_x.y), asin(_x.z) };
}

/**
 * @brief Computes the inverse sine of each component.
 * @param _x The input value or vector.
 */
inline dvec4 asin(const dvec4& _x)
{
	return { asin(_x.x), asin(_x.y), asin(_x.z), asin(_x.w) };
}

// floor functions
/**
 * @brief Rounds each component down to the nearest integer.
 * @param _x The input value or vector.
 */
inline simddouble floor(const simddouble& _x)
{
	return simd_floor_double(_x);
}


/**
 * @brief Rounds each component down to the nearest integer.
 * @param _x The input value or vector.
 */
inline dvec2 floor(const dvec2& _x)
{
	return { floor(_x.x), floor(_x.y) };
}

/**
 * @brief Rounds each component down to the nearest integer.
 * @param _x The input value or vector.
 */
inline dvec3 floor(const dvec3& _x)
{
	return { floor(_x.x), floor(_x.y), floor(_x.z) };
}

/**
 * @brief Rounds each component down to the nearest integer.
 * @param _x The input value or vector.
 */
inline dvec4 floor(const dvec4& _x)
{
	return { floor(_x.x), floor(_x.y), floor(_x.z), floor(_x.w) };
}

// mod functions
/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simddouble mod(const simddouble& _value, const simddouble& _modulus)
{
	return _value - (simd_floor_double(_value/_modulus)*_modulus);
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simddouble mod(const simddouble& _value, const double& _modulus)
{
	return _value - floor(_value / simd_set1_double(_modulus)) * _modulus;
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simddouble mod(const double& _value, const simddouble& _modulus)
{
	return simd_set1_double(_value) - floor(simd_set1_double(_value) / _modulus) * _modulus;
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simddouble mod(const double& _value, const double& _modulus)
{
	return simd_set1_double(_value - std::floor(_value / _modulus) * _modulus);
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec2 mod(const dvec2& _value, const dvec2& _modulus)
{
	return { mod(_value.x, _modulus.x), mod(_value.y, _modulus.y) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec3 mod(const dvec3& _value, const dvec3& _modulus)
{
	return { mod(_value.x, _modulus.x), mod(_value.y, _modulus.y), mod(_value.z, _modulus.z) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec4 mod(const dvec4& _value, const dvec4& _modulus)
{
	return { mod(_value.x, _modulus.x), mod(_value.y, _modulus.y), mod(_value.z, _modulus.z), mod(_value.w, _modulus.w) };
}

/**
 * @brief Computes the cosine of each component.
 * @param _x The input value or vector.
 */
inline simddouble cos(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_cos_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tabIndex[HALFSIMDWIDTH];
	simd_store_double(tabIndex, _x);

	// Pr�fetch des donn�es
	alignas(HALFSIMDWIDTH * 8) double tabResult[HALFSIMDWIDTH];
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tabResult[i] = std::cos(tabIndex[i]);
	}

	return simd_load_double(tabResult);
#endif
}

/**
 * @brief Computes the cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec2 cos(const dvec2& _x)
{
	return { cos(_x.x), cos(_x.y) };
}

/**
 * @brief Computes the cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec3 cos(const dvec3& _x)
{
	return { cos(_x.x), cos(_x.y), cos(_x.z) };
}

/**
 * @brief Computes the cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec4 cos(const dvec4& _x)
{
	return { cos(_x.x), cos(_x.y), cos(_x.z), cos(_x.w) };
}

// cosh functions
/**
 * @brief Computes the hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline simddouble cosh(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_cosh_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = cosh(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec2 cosh(const dvec2& _x)
{
	return { cosh(_x.x), cosh(_x.y) };
}

/**
 * @brief Computes the hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec3 cosh(const dvec3& _x)
{
	return { cosh(_x.x), cosh(_x.y), cosh(_x.z) };
}

/**
 * @brief Computes the hyperbolic cosine of each component.
 * @param _x The input value or vector.
 */
inline dvec4 cosh(const dvec4& _x)
{
	return { cosh(_x.x), cosh(_x.y), cosh(_x.z), cosh(_x.w) };
}

// cross functions
/**
 * @brief Computes the cross product of two 3D vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dvec3 cross(const dvec3& _val1, const dvec3& _val2)
{
	return { _val1.y * _val2.z - _val1.z * _val2.y, _val1.z * _val2.x - _val1.x * _val2.z, _val1.x * _val2.y - _val1.y * _val2.x };
}

// degrees functions
/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline simddouble degrees(const simddouble& _x)
{
	return simd_mul_double(_x, simd_set1_double(180.0 / 3.141592653589793));
}

/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline simddouble degrees(const double& _x)
{
	return simd_set1_double(_x * (180.0 / 3.141592653589793));
}

/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline dvec2 degrees(const dvec2& _x)
{
	return { degrees(_x.x), degrees(_x.y) };
}

/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline dvec3 degrees(const dvec3& _x)
{
	return { degrees(_x.x), degrees(_x.y), degrees(_x.z) };
}

/**
 * @brief Converts radians to degrees for each component.
 * @param _x The input value or vector.
 */
inline dvec4 degrees(const dvec4& _x)
{
	return { degrees(_x.x), degrees(_x.y), degrees(_x.z), degrees(_x.w) };
}

// distance functions
/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simddouble distance(const simddouble& _a, const simddouble& _b)
{
	return simd_sqrt_double(simd_mul_double(simd_sub_double(_a, _b), simd_sub_double(_a, _b)));
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simddouble distance(const double& _a, const double& _b)
{
	return std::abs(_a - _b);
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simddouble distance(const simddouble& _a, const double& _b)
{
	return distance(_a, simd_set1_double(_b));
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simddouble distance(const double& _a, const simddouble& _b)
{
	return distance(simd_set1_double(_a), _b);
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simddouble distance(const dvec2& _a, const dvec2& _b)
{
	return simd_sqrt_double(simd_add_double(simd_mul_double(simd_sub_double(_a.x, _b.x), simd_sub_double(_a.x, _b.x)), simd_mul_double(simd_sub_double(_a.y, _b.y), simd_sub_double(_a.y, _b.y))));
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simddouble distance(const dvec3& _a, const dvec3& _b)
{
	return simd_sqrt_double(simd_add_double(simd_add_double(simd_mul_double(simd_sub_double(_a.x, _b.x), simd_sub_double(_a.x, _b.x)), simd_mul_double(simd_sub_double(_a.y, _b.y), simd_sub_double(_a.y, _b.y))), simd_mul_double(simd_sub_double(_a.z, _b.z), simd_sub_double(_a.z, _b.z))));
}

/**
 * @brief Computes the distance between two points.
 * @param _a The first point.
 * @param _b The second point.
 */
inline simddouble distance(const dvec4& _a, const dvec4& _b)
{
	return simd_sqrt_double(simd_add_double(simd_add_double(simd_add_double(simd_mul_double(simd_sub_double(_a.x, _b.x), simd_sub_double(_a.x, _b.x)), simd_mul_double(simd_sub_double(_a.y, _b.y), simd_sub_double(_a.y, _b.y))), simd_mul_double(simd_sub_double(_a.z, _b.z), simd_sub_double(_a.z, _b.z))), simd_mul_double(simd_sub_double(_a.w, _b.w), simd_sub_double(_a.w, _b.w))));
}

// dot functions
/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble dot(const double& _val1, const double& _val2)
{
	return _val1 * _val2;
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble dot(const simddouble& _val1, const double& _val2)
{
	return _val1 * _val2;
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble dot(const double& _val1, const simddouble& _val2)
{
	return _val1 * _val2;
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble dot(const simddouble& _val1, const simddouble& _val2)
{
	return _val1 * _val2;
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble dot(const dvec2& _val1, const dvec2& _val2)
{
	return simd_add_double(simd_mul_double(_val1.x, _val2.x), simd_mul_double(_val1.y, _val2.y));
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble dot(const dvec3& _val1, const dvec3& _val2)
{
	return simd_add_double(simd_add_double(simd_mul_double(_val1.x, _val2.x), simd_mul_double(_val1.y, _val2.y)), simd_mul_double(_val1.z, _val2.z));
}

/**
 * @brief Computes the dot product of two vectors.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simddouble dot(const dvec4& _val1, const dvec4& _val2)
{
	return simd_add_double(simd_add_double(simd_add_double(simd_mul_double(_val1.x, _val2.x), simd_mul_double(_val1.y, _val2.y)), simd_mul_double(_val1.z, _val2.z)), simd_mul_double(_val1.w, _val2.w));
}

// exp functions
/**
 * @brief Computes the base-e exponential of each component.
 * @param _x The input value or vector.
 */
inline simddouble exp(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_exp_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = std::exp(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the base-e exponential of each component.
 * @param _x The input value or vector.
 */
inline dvec2 exp(const dvec2& _x)
{
	return { exp(_x.x), exp(_x.y) };
}

/**
 * @brief Computes the base-e exponential of each component.
 * @param _x The input value or vector.
 */
inline dvec3 exp(const dvec3& _x)
{
	return { exp(_x.x), exp(_x.y), exp(_x.z) };
}

/**
 * @brief Computes the base-e exponential of each component.
 * @param _x The input value or vector.
 */
inline dvec4 exp(const dvec4& _x)
{
	return { exp(_x.x), exp(_x.y), exp(_x.z), exp(_x.w) };

}

// exp2 functions
/**
 * @brief Computes the base-2 exponential of each component.
 * @param _x The input value or vector.
 */
inline simddouble exp2(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_exp2_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = std::exp2(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the base-2 exponential of each component.
 * @param _x The input value or vector.
 */
inline dvec2 exp2(const dvec2& _x)
{
	return { exp2(_x.x), exp2(_x.y) };
}

/**
 * @brief Computes the base-2 exponential of each component.
 * @param _x The input value or vector.
 */
inline dvec3 exp2(const dvec3& _x)
{
	return { exp2(_x.x), exp2(_x.y), exp2(_x.z) };
}

/**
 * @brief Computes the base-2 exponential of each component.
 * @param _x The input value or vector.
 */
inline dvec4 exp2(const dvec4& _x)
{
	return { exp2(_x.x), exp2(_x.y), exp2(_x.z), exp2(_x.w) };
}

// fma functions
/**
 * @brief Computes fused multiply-add (a * b + c).
 * @param _val1 The first factor for multiplication.
 * @param _val2 The second factor for multiplication.
 * @param _addend The value to add.
 */
inline simddouble fma(const simddouble& _val1, const simddouble& _val2, const simddouble& _addend)
{
	return simd_add_double(simd_mul_double(_val1, _val2), _addend);
}

/**
 * @brief Computes fused multiply-add (a * b + c).
 * @param _val1 The first factor for multiplication.
 * @param _val2 The second factor for multiplication.
 * @param _addend The value to add.
 */
inline dvec2 fma(const dvec2& _val1, const dvec2& _val2, const dvec2& _addend)
{
	return { fma(_val1.x, _val2.x, _addend.x), fma(_val1.y, _val2.y, _addend.y) };
}

/**
 * @brief Computes fused multiply-add (a * b + c).
 * @param _val1 The first factor for multiplication.
 * @param _val2 The second factor for multiplication.
 * @param _addend The value to add.
 */
inline dvec3 fma(const dvec3& _val1, const dvec3& _val2, const dvec3& _addend)
{
	return { fma(_val1.x, _val2.x, _addend.x), fma(_val1.y, _val2.y, _addend.y), fma(_val1.z, _val2.z, _addend.z) };
}

/**
 * @brief Computes fused multiply-add (a * b + c).
 * @param _val1 The first factor for multiplication.
 * @param _val2 The second factor for multiplication.
 * @param _addend The value to add.
 */
inline dvec4 fma(const dvec4& _val1, const dvec4& _val2, const dvec4& _addend)
{
	return { fma(_val1.x, _val2.x, _addend.x), fma(_val1.y, _val2.y, _addend.y), fma(_val1.z, _val2.z, _addend.z), fma(_val1.w, _val2.w, _addend.w) };
}

// fract functions
/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline simddouble fract(const simddouble& _x)
{
	return simd_sub_double(_x, simd_floor_double(_x));
}

/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline simddouble fract(const double& _x)
{
	return simd_set1_double(_x - std::floor(_x));
}

/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline dvec2 fract(const dvec2& _x)
{
	return { fract(_x.x), fract(_x.y) };
}

/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline dvec3 fract(const dvec3& _x)
{
	return { fract(_x.x), fract(_x.y), fract(_x.z) };
}

/**
 * @brief Computes the fractional part of each component.
 * @param _x The input value or vector.
 */
inline dvec4 fract(const dvec4& _x)
{
	return { fract(_x.x), fract(_x.y), fract(_x.z), fract(_x.w) };
}

// inversesqrt functions
/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline simddouble inversesqrt(const simddouble& _x)
{
	// return simd_rsqrt_double(_x);
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = 1.0 / std::sqrt(tempTab[i]);
	}
	return simd_load_double(tempTab);
}

/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline simddouble inversesqrt(const double& _x)
{
	return simd_set1_double(1.0f / std::sqrt(_x));
}

/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline dvec2 inversesqrt(const dvec2& _x)
{
	return { inversesqrt(_x.x), inversesqrt(_x.y) };
}

/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline dvec3 inversesqrt(const dvec3& _x)
{
	return { inversesqrt(_x.x), inversesqrt(_x.y), inversesqrt(_x.z) };
}

/**
 * @brief Computes the inverse square root of each component.
 * @param _x The input value or vector.
 */
inline dvec4 inversesqrt(const dvec4& _x)
{
	return { inversesqrt(_x.x), inversesqrt(_x.y), inversesqrt(_x.z), inversesqrt(_x.w) };
}

// ldexp functions
/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline simddouble ldexp(const simddouble& _mantissa, const simddouble& _exponent)
{
	return simd_mul_double(_mantissa, exp2(_exponent));
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline simddouble ldexp(const simddouble& _mantissa, const double& _exponent)
{
	return simd_mul_double(_mantissa, exp2(simd_set1_double(_exponent)));
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline simddouble ldexp(const double& _mantissa, const simddouble& _exponent)
{
	return simd_mul_double(simd_set1_double(_mantissa), exp2(_exponent));
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline dvec2 ldexp(const dvec2& _mantissa, const dvec2& _exponent)
{
	return { ldexp(_mantissa.x, _exponent.x), ldexp(_mantissa.y, _exponent.y) };
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline dvec3 ldexp(const dvec3& _mantissa, const dvec3& _exponent)
{
	return { ldexp(_mantissa.x, _exponent.x), ldexp(_mantissa.y, _exponent.y), ldexp(_mantissa.z, _exponent.z) };
}

/**
 * @brief Computes mantissa * 2^exponent.
 * @param _mantissa The mantissa (significand).
 * @param _exponent The exponent value.
 */
inline dvec4 ldexp(const dvec4& _mantissa, const dvec4& _exponent)
{
	return { ldexp(_mantissa.x, _exponent.x), ldexp(_mantissa.y, _exponent.y), ldexp(_mantissa.z, _exponent.z), ldexp(_mantissa.w, _exponent.w) };
}

// length functions
/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simddouble length(const double& _vec)
{
	return simd_set1_double(std::abs(_vec));
}

/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simddouble length(const simddouble& _vec)
{
	return _vec;
}

/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simddouble length(const dvec2& _vec)
{
	return simd_sqrt_double(_vec.x * _vec.x + _vec.y * _vec.y);
}

/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simddouble length(const dvec3& _vec)
{
	return simd_sqrt_double(_vec.x * _vec.x + _vec.y * _vec.y + _vec.z * _vec.z);
}

/**
 * @brief Computes the length of a vector.
 * @param _vec The input vector.
 */
inline simddouble length(const dvec4& _vec)
{
	return simd_sqrt_double(_vec.x * _vec.x + _vec.y * _vec.y + _vec.z * _vec.z + _vec.w * _vec.w);
}

// lerp functions
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble lerp(const simddouble& _from, const simddouble& _to, const simddouble& _t)
{
	return simd_add_double(simd_mul_double(simd_sub_double(_to, _from), _t), _from);
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble lerp(const simddouble& _from, const simddouble& _to, const double& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble lerp(const simddouble& _from, const double& _to, const simddouble& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble lerp(const simddouble& _from, const double& _to, const double& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble lerp(const double& _from, const simddouble& _to, const simddouble& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble lerp(const double& _from, const simddouble& _to, const double& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble lerp(const double& _from, const double& _to, const simddouble& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble lerp(const double& _from, const double& _to, const double& _t)
{
	return simd_set1_double(_from + _t * (_to - _from));
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec2 lerp(const dvec2& _from, const dvec2& _to, const simddouble& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec2 lerp(const dvec2& _from, const dvec2& _to, const double& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec2 lerp(const dvec2& _from, const dvec2& _to, const dvec2& _t)
{
	return { lerp(_from.x, _to.x, _t.x), lerp(_from.y, _to.y, _t.y) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec3 lerp(const dvec3& _from, const dvec3& _to, const simddouble& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t), lerp(_from.z, _to.z, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec3 lerp(const dvec3& _from, const dvec3& _to, const double& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t), lerp(_from.z, _to.z, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec3 lerp(const dvec3& _from, const dvec3& _to, const dvec3& _t)
{
	return { lerp(_from.x, _to.x, _t.x), lerp(_from.y, _to.y, _t.y), lerp(_from.z, _to.z, _t.z) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec4 lerp(const dvec4& _from, const dvec4& _to, const simddouble& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t), lerp(_from.z, _to.z, _t), lerp(_from.w, _to.w, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec4 lerp(const dvec4& _from, const dvec4& _to, const double& _t)
{
	return { lerp(_from.x, _to.x, _t), lerp(_from.y, _to.y, _t), lerp(_from.z, _to.z, _t), lerp(_from.w, _to.w, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec4 lerp(const dvec4& _from, const dvec4& _to, const dvec4& _t)
{
	return { lerp(_from.x, _to.x, _t.x), lerp(_from.y, _to.y, _t.y), lerp(_from.z, _to.z, _t.z), lerp(_from.w, _to.w, _t.w) };
}

// log functions
/**
 * @brief Computes the natural (base-e) logarithm of each component.
 * @param _x The input value or vector.
 */
inline simddouble log(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_log_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = logf(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the natural (base-e) logarithm of each component.
 * @param _x The input value or vector.
 */
inline dvec2 log(const dvec2& _x)
{
	return { log(_x.x), log(_x.y) };
}

/**
 * @brief Computes the natural (base-e) logarithm of each component.
 * @param _x The input value or vector.
 */
inline dvec3 log(const dvec3& _x)
{
	return { log(_x.x), log(_x.y), log(_x.z) };
}

/**
 * @brief Computes the natural (base-e) logarithm of each component.
 * @param _x The input value or vector.
 */
inline dvec4 log(const dvec4& _x)
{
	return { log(_x.x), log(_x.y), log(_x.z), log(_x.w) };
}

// log2 functions
/**
 * @brief Computes the base-2 logarithm of each component.
 * @param _x The input value or vector.
 */
inline simddouble log2(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_log2_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = log2f(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the base-2 logarithm of each component.
 * @param _x The input value or vector.
 */
inline dvec2 log2(const dvec2& _x)
{
	return { log2(_x.x), log2(_x.y) };
}

/**
 * @brief Computes the base-2 logarithm of each component.
 * @param _x The input value or vector.
 */
inline dvec3 log2(const dvec3& _x)
{
	return { log2(_x.x), log2(_x.y), log2(_x.z) };
}

/**
 * @brief Computes the base-2 logarithm of each component.
 * @param _x The input value or vector.
 */
inline dvec4 log2(const dvec4& _x)
{
	return { log2(_x.x), log2(_x.y), log2(_x.z), log2(_x.w) };
}

// mix functions
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble mix(const simddouble& _from, const simddouble& _to, const simddouble& _t)
{
	return simd_add_double(simd_mul_double(simd_sub_double(_to, _from), _t), _from);
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble mix(const simddouble& _from, const simddouble& _to, const double& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble mix(const simddouble& _from, const double& _to, const simddouble& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble mix(const simddouble& _from, const double& _to, const double& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble mix(const double& _from, const simddouble& _to, const simddouble& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble mix(const double& _from, const simddouble& _to, const double& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble mix(const double& _from, const double& _to, const simddouble& _t)
{
	return _from + _t * (_to - _from);
}
/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline simddouble mix(const double& _from, const double& _to, const double& _t)
{
	return simd_set1_double(_from + _t * (_to - _from));
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec2 mix(const dvec2& _from, const dvec2& _to, const simddouble& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec2 mix(const dvec2& _from, const dvec2& _to, const double& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec2 mix(const dvec2& _from, const dvec2& _to, const dvec2& _t)
{
	return { mix(_from.x, _to.x, _t.x), mix(_from.y, _to.y, _t.y) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec3 mix(const dvec3& _from, const dvec3& _to, const simddouble& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t), mix(_from.z, _to.z, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec3 mix(const dvec3& _from, const dvec3& _to, const double& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t), mix(_from.z, _to.z, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec3 mix(const dvec3& _from, const dvec3& _to, const dvec3& _t)
{
	return { mix(_from.x, _to.x, _t.x), mix(_from.y, _to.y, _t.y), mix(_from.z, _to.z, _t.z) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec4 mix(const dvec4& _from, const dvec4& _to, const simddouble& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t), mix(_from.z, _to.z, _t), mix(_from.w, _to.w, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec4 mix(const dvec4& _from, const dvec4& _to, const double& _t)
{
	return { mix(_from.x, _to.x, _t), mix(_from.y, _to.y, _t), mix(_from.z, _to.z, _t), mix(_from.w, _to.w, _t) };
}

/**
 * @brief Performs linear interpolation.
 * @param _from The start value for interpolation.
 * @param _to The end value for interpolation.
 * @param _t The interpolation factor.
 */
inline dvec4 mix(const dvec4& _from, const dvec4& _to, const dvec4& _t)
{
	return { mix(_from.x, _to.x, _t.x), mix(_from.y, _to.y, _t.y), mix(_from.z, _to.z, _t.z), mix(_from.w, _to.w, _t.w) };
}

// modf functions
/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simddouble modf(const simddouble& _value, const simddouble& _modulus)
{
	return simd_sub_double(_value, simd_mul_double(simd_floor_double(simd_div_double(_value, _modulus)), _modulus));
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simddouble modf(const double& _value, const double& _modulus)
{
	return simd_set1_double(_value - std::floor(_value / _modulus) * _modulus);
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simddouble modf(const simddouble& _value, const double& _modulus)
{
	return modf(_value, simd_set1_double(_modulus));
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline simddouble modf(const double& _value, const simddouble& _modulus)
{
	return modf(simd_set1_double(_value), _modulus);
}
#

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec2 modf(const dvec2& _value, const simddouble& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec2 modf(const dvec2& _value, const double& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec2 modf(const dvec2& _value, const dvec2& _modulus)
{
	return { modf(_value.x, _modulus.x), modf(_value.y, _modulus.y) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec3 modf(const dvec3& _value, const simddouble& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus), modf(_value.z, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec3 modf(const dvec3& _value, const double& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus), modf(_value.z, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec3 modf(const dvec3& _value, const dvec3& _modulus)
{
	return { modf(_value.x, _modulus.x), modf(_value.y, _modulus.y), modf(_value.z, _modulus.z) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec4 modf(const dvec4& _value, const simddouble& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus), modf(_value.z, _modulus), modf(_value.w, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec4 modf(const dvec4& _value, const double& _modulus)
{
	return { modf(_value.x, _modulus), modf(_value.y, _modulus), modf(_value.z, _modulus), modf(_value.w, _modulus) };
}

/**
 * @brief Computes the component-wise floating-point remainder.
 * @param _value The value to be modulated.
 * @param _modulus The modulus.
 */
inline dvec4 modf(const dvec4& _value, const dvec4& _modulus)
{
	return { modf(_value.x, _modulus.x), modf(_value.y, _modulus.y), modf(_value.z, _modulus.z), modf(_value.w, _modulus.w) };
}

// normalize functions
/**
 * @brief Computes the normalized vector (unit vector).
 * @param _x The input value.
 */
inline simddouble normalize(const double& _x)
{
	if (_x == 0.0) return simd_set1_double(0.0);
	else return simd_set1_double(1.0);
}

/**
 * @brief Computes the normalized vector (unit vector).
 * @param _x The input value.
 */
inline simddouble normalize(const simddouble& _x)
{
	return blendv(1.0, 0.0, _x == 0.0);
}

/**
 * @brief Computes the normalized vector (unit vector).
 * @param _vec The input vector.
 */
inline dvec2 normalize(const dvec2& _vec)
{
	return {
		_vec.x / length(_vec),
		_vec.y / length(_vec)
	};
}

/**
 * @brief Computes the normalized vector (unit vector).
 * @param _vec The input vector.
 */
inline dvec3 normalize(const dvec3& _vec)
{
	return {
		_vec.x / length(_vec),
		_vec.y / length(_vec),
		_vec.z / length(_vec)
	};
}

/**
 * @brief Computes the normalized vector (unit vector).
 * @param _vec The input vector.
 */
inline dvec4 normalize(const dvec4& _vec)
{
	return {
		_vec.x / length(_vec),
		_vec.y / length(_vec),
		_vec.z / length(_vec),
		_vec.w / length(_vec)
	};
}

// pow functions
/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline simddouble pow(const simddouble& _base, const simddouble& _exponent)
{
#ifndef __GNUC__
	return simd_pow_double(_base, _exponent);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTabA[HALFSIMDWIDTH];
	alignas(HALFSIMDWIDTH * 8) double tempTabB[HALFSIMDWIDTH];
	simd_store_double(tempTabA, _base);
	simd_store_double(tempTabB, _exponent);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTabA[i] = pow(tempTabA[i], tempTabB[i]);
	}
	return simd_load_double(tempTabA);
#endif
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline simddouble pow(const simddouble& _base, const double& _exponent)
{
	return pow(_base, simd_set1_double(_exponent));
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline dvec2 pow(const dvec2& _base, const simddouble& _exponent)
{
	return {
		pow(_base.x, _exponent),
		pow(_base.y, _exponent)
	};
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline dvec2 pow(const dvec2& _base, const double& _exponent)
{
	return pow(_base, simd_set1_double(_exponent));
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline dvec2 pow(const dvec2& _base, const dvec2& _exponent)
{
	return {
		pow(_base.x, _exponent.x),
		pow(_base.y, _exponent.y)
	};
}
/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline dvec3 pow(const dvec3& _base, const simddouble& _exponent)
{
	return {
		pow(_base.x, _exponent),
		pow(_base.y, _exponent),
		pow(_base.z, _exponent)
	};
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline dvec3 pow(const dvec3& _base, const double& _exponent)
{
	return pow(_base, simd_set1_double(_exponent));
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline dvec3 pow(const dvec3& _base, const dvec3& _exponent)
{
	return {
		pow(_base.x, _exponent.x),
		pow(_base.y, _exponent.y),
		pow(_base.z, _exponent.z)
	};
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline dvec4 pow(const dvec4& _base, const simddouble& _exponent)
{
	return {
		pow(_base.x, _exponent),
		pow(_base.y, _exponent),
		pow(_base.z, _exponent),
		pow(_base.w, _exponent)
	};
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline dvec4 pow(const dvec4& _base, const double& _exponent)
{
	return pow(_base, simd_set1_double(_exponent));
}

/**
 * @brief Computes the component-wise power of a base raised to an exponent.
 * @param _base The base value.
 * @param _exponent The exponent value.
 */
inline dvec4 pow(const dvec4& _base, const dvec4& _exponent)
{
	return {
		pow(_base.x, _exponent.x),
		pow(_base.y, _exponent.y),
		pow(_base.z, _exponent.z),
		pow(_base.w, _exponent.w)
	};
}

// radians functions
/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline simddouble radians(const simddouble& _x)
{
	return simd_mul_double(_x, simd_set1_double(3.141592653589793 / 180.0));
}

/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline simddouble radians(const double& _x)
{
	return simd_set1_double(_x * (3.141592653589793 / 180.0));
}

/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline dvec2 radians(const dvec2& _x)
{
	return { radians(_x.x), radians(_x.y) };
}

/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline dvec3 radians(const dvec3& _x)
{
	return { radians(_x.x), radians(_x.y), radians(_x.z) };
}

/**
 * @brief Converts degrees to radians for each component.
 * @param _x The input value or vector.
 */
inline dvec4 radians(const dvec4& _x)
{
	return { radians(_x.x), radians(_x.y), radians(_x.z), radians(_x.w) };
}

// reflect functions
/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline simddouble reflect(const double& _incident, const double& _normal)
{
	return _incident - 2.0 * dot(_normal, _incident) * _normal;
}

/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline simddouble reflect(const simddouble& _incident, const simddouble& _normal)
{
	return _incident - 2.0 * dot(_normal, _incident) * _normal;
}

/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline dvec2 reflect(const dvec2& _incident, const dvec2& _normal)
{
	return _incident - 2.0 * dot(_normal, _incident) * _normal;
}

/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline dvec3 reflect(const dvec3& _incident, const dvec3& _normal)
{
	return _incident - 2.0 * dot(_normal, _incident) * _normal;
}

/**
 * @brief Computes the reflection vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 */
inline dvec4 reflect(const dvec4& _incident, const dvec4& _normal)
{
	return _incident - 2.0 * dot(_normal, _incident) * _normal;
}

// round functions
/**
 * @brief Rounds each component to the nearest integer.
 * @param _x The input value or vector.
 */
inline simddouble round(const simddouble& _x)
{
#ifdef USE_AVX512
	return _mm512_roundscale_pd(_x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
#elif defined (USE_SSE)
	return simd_add_double(simd_floor_double(simd_add_double(_x, simd_set1_double(0.5))), simd_set1_double(0.0));
#else
	return simd_round_double(_x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
#endif
}

/**
 * @brief Rounds each component to the nearest integer.
 * @param _x The input value or vector.
 */
inline dvec2 round(const dvec2& _x)
{
	return { round(_x.x), round(_x.y) };
}

/**
 * @brief Rounds each component to the nearest integer.
 * @param _x The input value or vector.
 */
inline dvec3 round(const dvec3& _x)
{
	return { round(_x.x), round(_x.y), round(_x.z) };
}

/**
 * @brief Rounds each component to the nearest integer.
 * @param _x The input value or vector.
 */
inline dvec4 round(const dvec4& _x)
{
	return { round(_x.x), round(_x.y), round(_x.z), round(_x.w) };
}

// sign functions
/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline simddouble sign(const simddouble& _x)
{
	simddmask _maskNeg = simd_cmp_double(_x, simd_set1_double(0.0), _CMP_LT_OQ);
	simddmask _maskZero = simd_cmp_double(_x, simd_set1_double(0.0), _CMP_EQ_OQ);
	simddouble final = blendv(simd_set1_double(1.0), simd_set1_double(-1.0), _maskNeg);
	final = blendv(final, simd_set1_double(0.0), _maskZero);
	return final;
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline simddouble sign(const double& _x)
{
	return simd_set1_double((_x > 0.0) - (_x < 0.0));
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline dvec2 sign(const dvec2& _x)
{
	return { sign(_x.x), sign(_x.y) };
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline dvec3 sign(const dvec3& _x)
{
	return { sign(_x.x), sign(_x.y), sign(_x.z) };
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline dvec4 sign(const dvec4& _x)
{
	return { sign(_x.x), sign(_x.y), sign(_x.z), sign(_x.w) };
}

// sin functions
/**
 * @brief Computes the sine of each component.
 * @param _x The input value or vector.
 */
inline simddouble sin(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_sin_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = sinf(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the sine of each component.
 * @param _x The input value or vector.
 */
inline dvec2 sin(const dvec2& _x)
{
	return { sin(_x.x), sin(_x.y) };
}

/**
 * @brief Computes the sine of each component.
 * @param _x The input value or vector.
 */
inline dvec3 sin(const dvec3& _x)
{
	return { sin(_x.x), sin(_x.y), sin(_x.z) };
}

/**
 * @brief Computes the sine of each component.
 * @param _x The input value or vector.
 */
inline dvec4 sin(const dvec4& _x)
{
	return { sin(_x.x), sin(_x.y), sin(_x.z), sin(_x.w) };
}

// sinh functions
/**
 * @brief Computes the hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline simddouble sinh(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_sinh_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = sinhf(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}


/**
 * @brief Computes the hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline dvec2 sinh(const dvec2& _x)
{
	return { sinh(_x.x), sinh(_x.y) };
}

/**
 * @brief Computes the hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline dvec3 sinh(const dvec3& _x)
{
	return { sinh(_x.x), sinh(_x.y), sinh(_x.z) };
}

/**
 * @brief Computes the hyperbolic sine of each component.
 * @param _x The input value or vector.
 */
inline dvec4 sinh(const dvec4& _x)
{
	return { sinh(_x.x), sinh(_x.y), sinh(_x.z), sinh(_x.w) };
}

// smoothstep functions
/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simddouble smoothstep(const simddouble& _edge0, const simddouble& _edge1, const simddouble& _x)
{
	simddouble t = clamp((_x - _edge0) / (_edge1 - _edge0), 0.0, 1.0);
	return t * t * (3.0 - 2.0 * t);
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simddouble smoothstep(const double& _edge0, const double& _edge1, const simddouble& _x)
{
	return smoothstep(simd_set1_double(_edge0), simd_set1_double(_edge1), _x);
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simddouble smoothstep(const double& _edge0, const double& _edge1, const double& _x)
{
	return smoothstep(simd_set1_double(_edge0), simd_set1_double(_edge1), simd_set1_double(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simddouble smoothstep(const simddouble& _edge0, const double& _edge1, const simddouble& _x)
{
	return smoothstep(_edge0, simd_set1_double(_edge1), _x);
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simddouble smoothstep(const simddouble& _edge0, const double& _edge1, const double& _x)
{
	return smoothstep(_edge0, simd_set1_double(_edge1), simd_set1_double(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simddouble smoothstep(const double& _edge0, const simddouble& _edge1, const simddouble& _x)
{
	return smoothstep(simd_set1_double(_edge0), _edge1, _x);
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline simddouble smoothstep(const double& _edge0, const simddouble& _edge1, const double& _x)
{
	return smoothstep(simd_set1_double(_edge0), _edge1, simd_set1_double(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline dvec2 smoothstep(const dvec2& _edge0, const dvec2& _edge1, const simddouble& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x),
		smoothstep(_edge0.y, _edge1.y, _x)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline dvec2 smoothstep(const dvec2& _edge0, const dvec2& _edge1, const double& _x)
{
	return smoothstep(_edge0, _edge1, simd_set1_double(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline dvec2 smoothstep(const dvec2& _edge0, const dvec2& _edge1, const dvec2& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x.x),
		smoothstep(_edge0.y, _edge1.y, _x.y)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline dvec3 smoothstep(const dvec3& _edge0, const dvec3& _edge1, const simddouble& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x),
		smoothstep(_edge0.y, _edge1.y, _x),
		smoothstep(_edge0.z, _edge1.z, _x)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline dvec3 smoothstep(const dvec3& _edge0, const dvec3& _edge1, const double& _x)
{
	return smoothstep(_edge0, _edge1, simd_set1_double(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline dvec3 smoothstep(const dvec3& _edge0, const dvec3& _edge1, const dvec3& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x.x),
		smoothstep(_edge0.y, _edge1.y, _x.y),
		smoothstep(_edge0.z, _edge1.z, _x.z)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline dvec4 smoothstep(const dvec4& _edge0, const dvec4& _edge1, const simddouble& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x),
		smoothstep(_edge0.y, _edge1.y, _x),
		smoothstep(_edge0.z, _edge1.z, _x),
		smoothstep(_edge0.w, _edge1.w, _x)
	};
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline dvec4 smoothstep(const dvec4& _edge0, const dvec4& _edge1, const double& _x)
{
	return smoothstep(_edge0, _edge1, simd_set1_double(_x));
}

/**
 * @brief Performs a smooth Hermite interpolation.
 * @param _edge0 The lower edge of the smooth step function.
 * @param _edge1 The upper edge of the smooth step function.
 * @param _x The input value or vector.
 */
inline dvec4 smoothstep(const dvec4& _edge0, const dvec4& _edge1, const dvec4& _x)
{
	return {
		smoothstep(_edge0.x, _edge1.x, _x.x),
		smoothstep(_edge0.y, _edge1.y, _x.y),
		smoothstep(_edge0.z, _edge1.z, _x.z),
		smoothstep(_edge0.w, _edge1.w, _x.w)
	};
}

// step functions
/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline simddouble step(const simddouble& _edge, const simddouble& _x)
{
	simddmask _mask = _x < _edge;
	return blendv(simd_set1_double(1.0), simd_set1_double(0.0), _mask);
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline simddouble step(const double& _edge, const double& _x)
{
	return step(simd_set1_double(_edge), simd_set1_double(_x));
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline simddouble step(const double& _edge, const simddouble& _x)
{
	return step(simd_set1_double(_edge), _x);
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline simddouble step(const simddouble& _edge, const double& _x)
{
	return step(_edge, simd_set1_double(_x));
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline dvec2 step(const dvec2& _edge, const simddouble& _x)
{
	return {
		step(_edge.x, _x),
		step(_edge.y, _x)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline dvec2 step(const simddouble& _edge, const dvec2& _x)
{
	return {
		step(_edge, _x.x),
		step(_edge, _x.y)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline dvec2 step(const dvec2& _edge, const dvec2& _x)
{
	return {
		step(_edge.x, _x.x),
		step(_edge.y, _x.y)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline dvec3 step(const dvec3& _edge, const simddouble& _x)
{
	return {
		step(_edge.x, _x),
		step(_edge.y, _x),
		step(_edge.z, _x)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline dvec3 step(const simddouble& _edge, const dvec3& _x)
{
	return {
		step(_edge, _x.x),
		step(_edge, _x.y),
		step(_edge, _x.z)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline dvec3 step(const dvec3& _edge, const dvec3& _x)
{
	return {
		step(_edge.x, _x.x),
		step(_edge.y, _x.y),
		step(_edge.z, _x.z)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline dvec4 step(const dvec4& _edge, const simddouble& _x)
{
	return {
		step(_edge.x, _x),
		step(_edge.y, _x),
		step(_edge.z, _x),
		step(_edge.w, _x)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline dvec4 step(const simddouble& _edge, const dvec4& _x)
{
	return {
		step(_edge, _x.x),
		step(_edge, _x.y),
		step(_edge, _x.z),
		step(_edge, _x.w)
	};
}

/**
 * @brief Generates a step function by comparing two values.
 * @param _edge The edge of the step function.
 * @param _x The input value or vector.
 */
inline dvec4 step(const dvec4& _edge, const dvec4& _x)
{
	return {
		step(_edge.x, _x.x),
		step(_edge.y, _x.y),
		step(_edge.z, _x.z),
		step(_edge.w, _x.w)
	};
}

// sqrt functions
/**
 * @brief Computes the square root of each component.
 * @param _x The input value or vector.
 */
inline simddouble sqrt(const simddouble& _x)
{
	return simd_sqrt_double(_x);
}

/**
 * @brief Computes the square root of each component.
 * @param _x The input value or vector.
 */
inline dvec2 sqrt(const dvec2& _x)
{
	return {
		sqrt(_x.x),
		sqrt(_x.y)
	};
}

/**
 * @brief Computes the square root of each component.
 * @param _x The input value or vector.
 */
inline dvec3 sqrt(const dvec3& _x)
{
	return {
		sqrt(_x.x),
		sqrt(_x.y),
		sqrt(_x.z)
	};
}

/**
 * @brief Computes the square root of each component.
 * @param _x The input value or vector.
 */
inline dvec4 sqrt(const dvec4& _x)
{
	return {
		sqrt(_x.x),
		sqrt(_x.y),
		sqrt(_x.z),
		sqrt(_x.w)
	};
}

// refract functions
/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline dvec2 refract(const dvec2& _incident, const dvec2& _normal, const simddouble& _ior)
{
	simddouble dotNI = dot(_normal, _incident);
	simddouble k = 1.0 - _ior * _ior * (1.0 - dotNI * dotNI);
	return blendv(_ior * _incident - (_ior * dotNI + sqrt(k)) * _normal, dvec2(0), k < 0.0);
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline dvec2 refract(const dvec2& _incident, const dvec2& _normal, const double& _ior)
{
	return refract(_incident, _normal, simd_set1_double(_ior));
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline dvec3 refract(const dvec3& _incident, const dvec3& _normal, const simddouble& _ior)
{
	simddouble dotNI = dot(_normal, _incident);
	simddouble k = 1.0 - _ior * _ior * (1.0 - dotNI * dotNI);
	return blendv(_ior * _incident - (_ior * dotNI + sqrt(k)) * _normal, dvec3(0), k < 0.0);
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline dvec3 refract(const dvec3& _incident, const dvec3& _normal, const double& _ior)
{
	return refract(_incident, _normal, simd_set1_double(_ior));
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline dvec4 refract(const dvec4& _incident, const dvec4& _normal, const simddouble& _ior)
{
	simddouble dotNI = dot(_normal, _incident);
	simddouble k = 1.0 - _ior * _ior * (1.0 - dotNI * dotNI);
	return blendv(_ior * _incident - (_ior * dotNI + sqrt(k)) * _normal, dvec4(0), k < 0.0);
}

/**
 * @brief Computes the refraction vector.
 * @param _incident The incident vector.
 * @param _normal The normal vector.
 * @param _ior The index of refraction.
 */
inline dvec4 refract(const dvec4& _incident, const dvec4& _normal, const double& _ior)
{
	return refract(_incident, _normal, simd_set1_double(_ior));
}

// stanh functions
/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _x The input value or vector.
 */
inline simddouble stanh(const simddouble& _x)
{
	// approximate tanh using _a polynomial (5th degree)
	// tanh(_x) = _x * (27 + _x^2) / (27 + 9x^2)
	simddouble x2 = simd_mul_double(_x, _x);
	simddouble numerator = simd_mul_double(_x, simd_add_double(simd_set1_double(27.0), x2));
	simddouble denominator = simd_add_double(simd_set1_double(27.0), simd_mul_double(simd_set1_double(9.0), x2));
	return simd_div_double(numerator, denominator);
}

/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _x The input value or vector.
 */
inline simddouble stanh(const double& _x)
{
	return stanh(simd_set1_double(_x));
}

/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _vec The input vector.
 */
inline dvec2 stanh(const dvec2& _vec)
{
	return {
		stanh(_vec.x),
		stanh(_vec.y)
	};
}

/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _vec The input vector.
 */
inline dvec3 stanh(const dvec3& _vec)
{
	return {
		stanh(_vec.x),
		stanh(_vec.y),
		stanh(_vec.z)
	};
}

/**
 * @brief Computes an approximation of the hyperbolic tangent.
 * @param _vec The input vector.
 */
inline dvec4 stanh(const dvec4& _vec)
{
	return {
		stanh(_vec.x),
		stanh(_vec.y),
		stanh(_vec.z),
		stanh(_vec.w)
	};
}

// tan functions
/**
 * @brief Computes the tangent of each component.
 * @param _x The input value or vector.
 */
inline simddouble tan(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_tan_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = tanf(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the tangent of each component.
 * @param _x The input value or vector.
 */
inline dvec2 tan(const dvec2& _x)
{
	return {
		tan(_x.x),
		tan(_x.y)
	};
}

/**
 * @brief Computes the tangent of each component.
 * @param _x The input value or vector.
 */
inline dvec3 tan(const dvec3& _x)
{
	return {
		tan(_x.x),
		tan(_x.y),
		tan(_x.z)
	};
}

/**
 * @brief Computes the tangent of each component.
 * @param _x The input value or vector.
 */
inline dvec4 tan(const dvec4& _x)
{
	return {
		tan(_x.x),
		tan(_x.y),
		tan(_x.z),
		tan(_x.w)
	};
}

// tanh functions
/**
 * @brief Computes the hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline simddouble tanh(const simddouble& _x)
{
#ifndef __GNUC__
	return simd_tanh_double(_x);
#else
	alignas(HALFSIMDWIDTH * 8) double tempTab[HALFSIMDWIDTH];
	simd_store_double(tempTab, _x);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		tempTab[i] = tanhf(tempTab[i]);
	}
	return simd_load_double(tempTab);
#endif
}

/**
 * @brief Computes the hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline dvec2 tanh(const dvec2& _x)
{
	return {
		tanh(_x.x),
		tanh(_x.y)
	};
}

/**
 * @brief Computes the hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline dvec3 tanh(const dvec3& _x)
{
	return {
		tanh(_x.x),
		tanh(_x.y),
		tanh(_x.z)
	};
}

/**
 * @brief Computes the hyperbolic tangent of each component.
 * @param _x The input value or vector.
 */
inline dvec4 tanh(const dvec4& _x)
{
	return {
		tanh(_x.x),
		tanh(_x.y),
		tanh(_x.z),
		tanh(_x.w)
	};
}

// trunc functions
/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline simddouble trunc(const simddouble& _x)
{
#ifndef USE_AVX512
#else
#endif

#ifdef USE_AVX512
	return _mm512_roundscale_pd(_x, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
#elif defined (USE_SSE)
	return _mm_cvtepi32_pd(_mm_cvttpd_epi32(_x));
#else
	return simd_round_double(_x, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
#endif
}

/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline simddouble trunc(const double& _x)
{
	return simd_set1_double(_x - std::floor(_x));
}

/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline dvec2 trunc(const dvec2& _x)
{
	return {
		trunc(_x.x),
		trunc(_x.y)
	};
}

/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline dvec3 trunc(const dvec3& _x)
{
	return {
		trunc(_x.x),
		trunc(_x.y),
		trunc(_x.z)
	};
}

/**
 * @brief Truncates the fractional part of each component.
 * @param _x The input value or vector.
 */
inline dvec4 trunc(const dvec4& _x)
{
	return {
		trunc(_x.x),
		trunc(_x.y),
		trunc(_x.z),
		trunc(_x.w)
	};
}

#pragma region matrix operators and functions

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline dvec2 mul(const dmat2& _mat, const dvec2& _vec)
{
	return {
		dot({_mat.columns[0].x, _mat.columns[1].x}, _vec),
		dot({_mat.columns[0].y, _mat.columns[1].y}, _vec)
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline dvec2 mul(const dvec2& _vec, const dmat2& _mat)
{
	return {
		dot(_vec, _mat.columns[0]),
		dot(_vec, _mat.columns[1])
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat2 mul(const dmat2& _val1, const dmat2& _val2)
{
	return {
		dot(dvec2(_val1.columns[0].x, _val1.columns[1].x), _val2.columns[0]),
		dot(dvec2(_val1.columns[0].y, _val1.columns[1].y), _val2.columns[0]),
		dot(dvec2(_val1.columns[0].x, _val1.columns[1].x), _val2.columns[1]),
		dot(dvec2(_val1.columns[0].y, _val1.columns[1].y), _val2.columns[1])
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline dvec3 mul(const dmat3& _mat, const dvec3& _vec)
{
	return {
		dot({_mat.columns[0].x, _mat.columns[1].x, _mat.columns[2].x}, _vec),
		dot({_mat.columns[0].y, _mat.columns[1].y, _mat.columns[2].y}, _vec),
		dot({_mat.columns[0].z, _mat.columns[1].z, _mat.columns[2].z}, _vec)
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline dvec3 mul(const dvec3& _vec, const dmat3& _mat)
{
	return {
		dot(_vec, _mat.columns[0]),
		dot(_vec, _mat.columns[1]),
		dot(_vec, _mat.columns[2])
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat3 mul(const dmat3& _val1, const dmat3& _val2)
{
	return {
		dot(dvec3(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x), _val2.columns[0]),
		dot(dvec3(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y), _val2.columns[0]),
		dot(dvec3(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z), _val2.columns[0]),
		dot(dvec3(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x), _val2.columns[1]),
		dot(dvec3(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y), _val2.columns[1]),
		dot(dvec3(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z), _val2.columns[1]),
		dot(dvec3(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x), _val2.columns[2]),
		dot(dvec3(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y), _val2.columns[2]),
		dot(dvec3(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z), _val2.columns[2])

	};
}

// dmat4
/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline dvec4 mul(const dmat4& _mat, const dvec4& _vec)
{
	return {
		dot({_mat.columns[0].x, _mat.columns[1].x, _mat.columns[2].x, _mat.columns[3].x}, _vec),
		dot({_mat.columns[0].y, _mat.columns[1].y, _mat.columns[2].y, _mat.columns[3].y}, _vec),
		dot({_mat.columns[0].z, _mat.columns[1].z, _mat.columns[2].z, _mat.columns[3].z}, _vec),
		dot({_mat.columns[0].w, _mat.columns[1].w, _mat.columns[2].w, _mat.columns[3].w}, _vec)
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline dvec4 mul(const dvec4& _vec, const dmat4& _mat)
{
	return {
		dot(_vec, _mat.columns[0]),
		dot(_vec, _mat.columns[1]),
		dot(_vec, _mat.columns[2]),
		dot(_vec, _mat.columns[3])
	};
}

/**
 * @brief Performs matrix or matrix-vector multiplication.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat4 mul(const dmat4& _val1, const dmat4& _val2)
{
	return {
		dot(dvec4(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x, _val1.columns[3].x), _val2.columns[0]),
		dot(dvec4(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y, _val1.columns[3].y), _val2.columns[0]),
		dot(dvec4(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z, _val1.columns[3].z), _val2.columns[0]),
		dot(dvec4(_val1.columns[0].w, _val1.columns[1].w, _val1.columns[2].w, _val1.columns[3].w), _val2.columns[0]),
		dot(dvec4(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x, _val1.columns[3].x), _val2.columns[1]),
		dot(dvec4(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y, _val1.columns[3].y), _val2.columns[1]),
		dot(dvec4(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z, _val1.columns[3].z), _val2.columns[1]),
		dot(dvec4(_val1.columns[0].w, _val1.columns[1].w, _val1.columns[2].w, _val1.columns[3].w), _val2.columns[1]),
		dot(dvec4(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x, _val1.columns[3].x), _val2.columns[2]),
		dot(dvec4(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y, _val1.columns[3].y), _val2.columns[2]),
		dot(dvec4(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z, _val1.columns[3].z), _val2.columns[2]),
		dot(dvec4(_val1.columns[0].w, _val1.columns[1].w, _val1.columns[2].w, _val1.columns[3].w), _val2.columns[2]),
		dot(dvec4(_val1.columns[0].x, _val1.columns[1].x, _val1.columns[2].x, _val1.columns[3].x), _val2.columns[3]),
		dot(dvec4(_val1.columns[0].y, _val1.columns[1].y, _val1.columns[2].y, _val1.columns[3].y), _val2.columns[3]),
		dot(dvec4(_val1.columns[0].z, _val1.columns[1].z, _val1.columns[2].z, _val1.columns[3].z), _val2.columns[3]),
		dot(dvec4(_val1.columns[0].w, _val1.columns[1].w, _val1.columns[2].w, _val1.columns[3].w), _val2.columns[3])
	};
}

#pragma endregion

#pragma region matrix operators
// matrix operators
/**
 * @brief Overloaded addition operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat2 operator+(const dmat2& _val1, const dmat2& _val2)
{
	return {
		_val1.columns[0] + _val2.columns[0],
		_val1.columns[1] + _val2.columns[1]
	};
}

/**
 * @brief Overloaded subtraction operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat2 operator-(const dmat2& _val1, const dmat2& _val2)
{
	return {
		_val1.columns[0] - _val2.columns[0],
		_val1.columns[1] - _val2.columns[1]
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat2 operator*(const dmat2& _val1, const dmat2& _val2)
{
	return mul(_val1, _val2);
}

/**
 * @brief Overloaded addition-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat2 operator+=(dmat2& _val1, const dmat2& _val2)
{
	_val1 = _val1 + _val2;
	return _val1;
}

/**
 * @brief Overloaded subtraction-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat2 operator-=(dmat2& _val1, const dmat2& _val2)
{
	_val1 = _val1 - _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat2 operator*=(dmat2& _val1, const dmat2& _val2)
{
	_val1 = _val1 * _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline dmat2 operator*(const dmat2& _mat, const simddouble& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline dmat2 operator*(const simddouble& _scalar, const dmat2& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline dmat2 operator*(const dmat2& _mat, const double& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline dmat2 operator*(const double& _scalar, const dmat2& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar
	};
}

// matrix vector multiplication
/**
 * @brief Overloaded multiplication operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline dvec2 operator*(const dvec2& _vec, const dmat2& _mat)
{
	return mul(_vec, _mat);
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline dvec2 operator*(const dmat2& _mat, const dvec2& _vec)
{
	return mul(_mat, _vec);
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline dvec2 operator*=(dvec2& _vec, const dmat2& _mat)
{
	_vec = mul(_vec, _mat);
	return _vec;
}

// dmat3 multiplication
/**
 * @brief Overloaded addition operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat3 operator+(const dmat3& _val1, const dmat3& _val2)
{
	return {
		_val1.columns[0] + _val2.columns[0],
		_val1.columns[1] + _val2.columns[1],
		_val1.columns[2] + _val2.columns[2]
	};
}

/**
 * @brief Overloaded subtraction operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat3 operator-(const dmat3& _val1, const dmat3& _val2)
{
	return {
		_val1.columns[0] - _val2.columns[0],
		_val1.columns[1] - _val2.columns[1],
		_val1.columns[2] - _val2.columns[2]
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat3 operator*(const dmat3& _val1, const dmat3& _val2)
{
	return mul(_val1, _val2);
}

/**
 * @brief Overloaded addition-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat3 operator+=(dmat3& _val1, const dmat3& _val2)
{
	_val1 = _val1 + _val2;
	return _val1;
}

/**
 * @brief Overloaded subtraction-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat3 operator-=(dmat3& _val1, const dmat3& _val2)
{
	_val1 = _val1 - _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat3 operator*=(dmat3& _val1, const dmat3& _val2)
{
	_val1 = _val1 * _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline dmat3 operator*(const dmat3& _mat, const simddouble& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline dmat3 operator*(const simddouble& _scalar, const dmat3& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline dmat3 operator*(const dmat3& _mat, const double& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline dmat3 operator*(const double& _scalar, const dmat3& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar
	};
}

// matrix vector multiplication
/**
 * @brief Overloaded multiplication operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline dvec3 operator*(const dvec3& _vec, const dmat3& _mat)
{
	return mul(_vec, _mat);
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline dvec3 operator*(const dmat3& _mat, const dvec3& _vec)
{
	return mul(_mat, _vec);
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline dvec3 operator*=(dvec3& _vec, const dmat3& _mat)
{
	_vec = mul(_vec, _mat);
	return _vec;
}

// dmat4 multiplication
/**
 * @brief Overloaded addition operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat4 operator+(const dmat4& _val1, const dmat4& _val2)
{
	return {
		_val1.columns[0] + _val2.columns[0],
		_val1.columns[1] + _val2.columns[1],
		_val1.columns[2] + _val2.columns[2],
		_val1.columns[3] + _val2.columns[3]
	};
}

/**
 * @brief Overloaded subtraction operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat4 operator-(const dmat4& _val1, const dmat4& _val2)
{
	return {
		_val1.columns[0] - _val2.columns[0],
		_val1.columns[1] - _val2.columns[1],
		_val1.columns[2] - _val2.columns[2],
		_val1.columns[3] - _val2.columns[3]
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat4 operator*(const dmat4& _val1, const dmat4& _val2)
{
	return mul(_val1, _val2);
}

/**
 * @brief Overloaded addition-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat4 operator+=(dmat4& _val1, const dmat4& _val2)
{
	_val1 = _val1 + _val2;
	return _val1;
}

/**
 * @brief Overloaded subtraction-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat4 operator-=(dmat4& _val1, const dmat4& _val2)
{
	_val1 = _val1 - _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline dmat4 operator*=(dmat4& _val1, const dmat4& _val2)
{
	_val1 = _val1 * _val2;
	return _val1;
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline dmat4 operator*(const dmat4& _mat, const simddouble& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar,
		_mat.columns[3] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline dmat4 operator*(const simddouble& _scalar, const dmat4& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar,
		_mat.columns[3] * _scalar
	};
}

// matrix vector multiplication
/**
 * @brief Overloaded multiplication operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline dvec4 operator*(const dvec4& _vec, const dmat4& _mat)
{
	return mul(_vec, _mat);
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _vec The input vector.
 */
inline dvec4 operator*(const dmat4& _mat, const dvec4& _vec)
{
	return mul(_mat, _vec);
}

/**
 * @brief Overloaded multiplication-assignment operator.
 * @param _vec The input vector.
 * @param _mat The input matrix.
 */
inline dvec4 operator*=(dvec4& _vec, const dmat4& _mat)
{
	_vec = mul(_vec, _mat);
	return _vec;
}

/**
 * @brief Overloaded multiplication operator.
 * @param _mat The input matrix.
 * @param _scalar The scalar value.
 */
inline dmat4 operator*(const dmat4& _mat, const double& _scalar)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar,
		_mat.columns[3] * _scalar
	};
}

/**
 * @brief Overloaded multiplication operator.
 * @param _scalar The scalar value.
 * @param _mat The input matrix.
 */
inline dmat4 operator*(const double& _scalar, const dmat4& _mat)
{
	return {
		_mat.columns[0] * _scalar,
		_mat.columns[1] * _scalar,
		_mat.columns[2] * _scalar,
		_mat.columns[3] * _scalar
	};
}

// determinant for matrices
/**
 * @brief Computes the determinant of a matrix.
 * @param _mat The input matrix.
 */
inline simddouble determinant(const dmat2& _mat)
{
	return _mat.columns[0].x * _mat.columns[1].y - _mat.columns[0].y * _mat.columns[1].x;
}

/**
 * @brief Computes the determinant of a matrix.
 * @param _mat The input matrix.
 */
inline simddouble determinant(const dmat3& _mat)
{
	return _mat.columns[0].x * (_mat.columns[1].y * _mat.columns[2].z - _mat.columns[1].z * _mat.columns[2].y) -
		_mat.columns[0].y * (_mat.columns[1].x * _mat.columns[2].z - _mat.columns[1].z * _mat.columns[2].x) +
		_mat.columns[0].z * (_mat.columns[1].x * _mat.columns[2].y - _mat.columns[1].y * _mat.columns[2].x);
}

/**
 * @brief Computes the determinant of a matrix.
 * @param _mat The input matrix.
 */
inline simddouble determinant(const dmat4& _mat)
{
	return _mat.columns[0].x * (_mat.columns[1].y * (_mat.columns[2].z * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].z) -
		_mat.columns[1].z * (_mat.columns[2].y * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].y) +
		_mat.columns[1].w * (_mat.columns[2].y * _mat.columns[3].z - _mat.columns[2].z * _mat.columns[3].y)) -
		_mat.columns[0].y * (_mat.columns[1].x * (_mat.columns[2].z * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].z) -
			_mat.columns[1].z * (_mat.columns[2].x * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].x) +
			_mat.columns[1].w * (_mat.columns[2].x * _mat.columns[3].z - _mat.columns[2].z * _mat.columns[3].x)) +
		_mat.columns[0].z * (_mat.columns[1].x * (_mat.columns[2].y * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].y) -
			_mat.columns[1].y * (_mat.columns[2].x * _mat.columns[3].w - _mat.columns[2].w * _mat.columns[3].x) +
			_mat.columns[1].w * (_mat.columns[2].x * _mat.columns[3].y - _mat.columns[2].y * _mat.columns[3].x)) -
		_mat.columns[0].w * (_mat.columns[1].x * (_mat.columns[2].y * _mat.columns[3].z - _mat.columns[2].z * _mat.columns[3].y) -
			_mat.columns[1].y * (_mat.columns[2].x * _mat.columns[3].z - _mat.columns[2].z * _mat.columns[3].x) +
			_mat.columns[1].z * (_mat.columns[2].x * _mat.columns[3].y - _mat.columns[2].y * _mat.columns[3].x));
}

// inverse for matrices
/**
 * @brief Computes the inverse of a matrix.
 * @param _mat The input matrix.
 */
inline dmat2 inverse(const dmat2& _mat)
{
	return {
		dvec2(_mat.columns[1].y, -_mat.columns[0].y) / determinant(_mat),
		dvec2(-_mat.columns[1].x, _mat.columns[0].x) / determinant(_mat)
	};
}

/**
 * @brief Computes the inverse of a matrix.
 * @param _mat The input matrix.
 */
inline dmat3 inverse(const dmat3& _mat)
{
	return {
		dvec3(_mat.columns[1].y * _mat.columns[2].z - _mat.columns[1].z * _mat.columns[2].y, _mat.columns[0].z * _mat.columns[2].y - _mat.columns[0].y * _mat.columns[2].z, _mat.columns[0].y * _mat.columns[1].z - _mat.columns[0].z * _mat.columns[1].y) / determinant(_mat),
		dvec3(_mat.columns[1].z * _mat.columns[2].x - _mat.columns[1].x * _mat.columns[2].z, _mat.columns[0].x * _mat.columns[2].z - _mat.columns[0].z * _mat.columns[2].x, _mat.columns[0].z * _mat.columns[1].x - _mat.columns[0].x * _mat.columns[1].z) / determinant(_mat),
		dvec3(_mat.columns[1].x * _mat.columns[2].y - _mat.columns[1].y * _mat.columns[2].x, _mat.columns[0].y * _mat.columns[2].x - _mat.columns[0].x * _mat.columns[2].y, _mat.columns[0].x * _mat.columns[1].y - _mat.columns[0].y * _mat.columns[1].x) / determinant(_mat)
	};
}

/**
 * @brief Computes the inverse of a matrix.
 * @param _mat The input matrix.
 */
inline dmat4 inverse(const dmat4& _mat)
{
	return {
		dvec4(_mat.columns[1].y * _mat.columns[2].z * _mat.columns[3].w - _mat.columns[1].y * _mat.columns[2].w * _mat.columns[3].z - _mat.columns[1].z * _mat.columns[2].y * _mat.columns[3].w + _mat.columns[1].z * _mat.columns[2].w * _mat.columns[3].y + _mat.columns[1].w * _mat.columns[2].y * _mat.columns[3].z - _mat.columns[1].w * _mat.columns[2].z * _mat.columns[3].y, -_mat.columns[0].y * _mat.columns[2].z * _mat.columns[3].w + _mat.columns[0].y * _mat.columns[2].w * _mat.columns[3].z + _mat.columns[0].z * _mat.columns[2].y * _mat.columns[3].w - _mat.columns[0].z * _mat.columns[2].w * _mat.columns[3].y - _mat.columns[0].w * _mat.columns[2].y * _mat.columns[3].z + _mat.columns[0].w * _mat.columns[2].z * _mat.columns[3].y, _mat.columns[0].y * _mat.columns[1].z * _mat.columns[3].w - _mat.columns[0].y * _mat.columns[1].w * _mat.columns[3].z - _mat.columns[0].z * _mat.columns[1].y * _mat.columns[3].w + _mat.columns[0].z * _mat.columns[1].w * _mat.columns[3].y + _mat.columns[0].w * _mat.columns[1].y * _mat.columns[3].z - _mat.columns[0].w * _mat.columns[1].z * _mat.columns[3].y, -_mat.columns[0].y * _mat.columns[1].z * _mat.columns[2].w + _mat.columns[0].y * _mat.columns[1].w * _mat.columns[2].z + _mat.columns[0].z * _mat.columns[1].y * _mat.columns[2].w - _mat.columns[0].z * _mat.columns[1].w * _mat.columns[2].y - _mat.columns[0].w * _mat.columns[1].y * _mat.columns[2].z + _mat.columns[0].w * _mat.columns[1].z * _mat.columns[2].y) / determinant(_mat),
		dvec4(-_mat.columns[1].x * _mat.columns[2].z * _mat.columns[3].w + _mat.columns[1].x * _mat.columns[2].w * _mat.columns[3].z + _mat.columns[1].z * _mat.columns[2].x * _mat.columns[3].w - _mat.columns[1].z * _mat.columns[2].w * _mat.columns[3].x - _mat.columns[1].w * _mat.columns[2].x * _mat.columns[3].z + _mat.columns[1].w * _mat.columns[2].z * _mat.columns[3].x, _mat.columns[0].x * _mat.columns[2].z * _mat.columns[3].w - _mat.columns[0].x * _mat.columns[2].w * _mat.columns[3].z - _mat.columns[0].z * _mat.columns[2].x * _mat.columns[3].w + _mat.columns[0].z * _mat.columns[2].w * _mat.columns[3].x + _mat.columns[0].w * _mat.columns[2].x * _mat.columns[3].z - _mat.columns[0].w * _mat.columns[2].z * _mat.columns[3].x, -_mat.columns[0].x * _mat.columns[1].z * _mat.columns[3].w + _mat.columns[0].x * _mat.columns[1].w * _mat.columns[3].z + _mat.columns[0].z * _mat.columns[1].x * _mat.columns[3].w - _mat.columns[0].z * _mat.columns[1].w * _mat.columns[3].x - _mat.columns[0].w * _mat.columns[1].x * _mat.columns[3].z + _mat.columns[0].w * _mat.columns[1].z * _mat.columns[3].x, 	_mat.columns[0].x * _mat.columns[1].z * _mat.columns[2].w - _mat.columns[0].x * _mat.columns[1].w * _mat.columns[2].z - _mat.columns[0].z * _mat.columns[1].x * _mat.columns[2].w + _mat.columns[0].z * _mat.columns[1].w * _mat.columns[2].x + _mat.columns[0].w * _mat.columns[1].x * _mat.columns[2].z - _mat.columns[0].w * _mat.columns[1].z * _mat.columns[2].x) / determinant(_mat),
		dvec4(_mat.columns[1].x * _mat.columns[2].y * _mat.columns[3].w - _mat.columns[1].x * _mat.columns[2].w * _mat.columns[3].y - _mat.columns[1].y * _mat.columns[2].x * _mat.columns[3].w + _mat.columns[1].y * _mat.columns[2].w * _mat.columns[3].x + _mat.columns[1].w * _mat.columns[2].x * _mat.columns[3].y - _mat.columns[1].w * _mat.columns[2].y * _mat.columns[3].x, -_mat.columns[0].x * _mat.columns[2].y * _mat.columns[3].w + _mat.columns[0].x * _mat.columns[2].w * _mat.columns[3].y + _mat.columns[0].y * _mat.columns[2].x * _mat.columns[3].w - _mat.columns[0].y * _mat.columns[2].w * _mat.columns[3].x - _mat.columns[0].w * _mat.columns[2].x * _mat.columns[3].y + _mat.columns[0].w * _mat.columns[2].y * _mat.columns[3].x, 	_mat.columns[0].x * _mat.columns[1].y * _mat.columns[3].w - _mat.columns[0].x * _mat.columns[1].w * _mat.columns[3].y - _mat.columns[0].y * _mat.columns[1].x * _mat.columns[3].w + _mat.columns[0].y * _mat.columns[1].w * _mat.columns[3].x + _mat.columns[0].w * _mat.columns[1].x * _mat.columns[3].y - _mat.columns[0].w * _mat.columns[1].y * _mat.columns[3].x, 	-_mat.columns[0].x * _mat.columns[1].y * _mat.columns[2].w + _mat.columns[0].x * _mat.columns[1].w * _mat.columns[2].y + _mat.columns[0].y * _mat.columns[1].x * _mat.columns[2].w - _mat.columns[0].y * _mat.columns[1].w * _mat.columns[2].x - _mat.columns[0].w * _mat.columns[1].x * _mat.columns[2].y + _mat.columns[0].w * _mat.columns[1].y * _mat.columns[2].x) / determinant(_mat),
		dvec4(-_mat.columns[1].x * _mat.columns[2].y * _mat.columns[3].z + _mat.columns[1].x * _mat.columns[2].z * _mat.columns[3].y + _mat.columns[1].y * _mat.columns[2].x * _mat.columns[3].z - _mat.columns[1].y * _mat.columns[2].z * _mat.columns[3].x - _mat.columns[1].z * _mat.columns[2].x * _mat.columns[3].y + _mat.columns[1].z * _mat.columns[2].y * _mat.columns[3].x, 	_mat.columns[0].x * _mat.columns[2].y * _mat.columns[3].z - _mat.columns[0].x * _mat.columns[2].z * _mat.columns[3].y - _mat.columns[0].y * _mat.columns[2].x * _mat.columns[3].z + _mat.columns[0].y * _mat.columns[2].z * _mat.columns[3].x + _mat.columns[0].z * _mat.columns[2].x * _mat.columns[3].y - _mat.columns[0].z * _mat.columns[2].y * _mat.columns[3].x, 	-_mat.columns[0].x * _mat.columns[1].y * _mat.columns[3].z + _mat.columns[0].x * _mat.columns[1].z * _mat.columns[3].y + _mat.columns[0].y * _mat.columns[1].x * _mat.columns[3].z - _mat.columns[0].y * _mat.columns[1].z * _mat.columns[3].x - _mat.columns[0].z * _mat.columns[1].x * _mat.columns[3].y + _mat.columns[0].z * _mat.columns[1].y * _mat.columns[3].x, 	_mat.columns[0].x * _mat.columns[1].y * _mat.columns[2].z - _mat.columns[0].x * _mat.columns[1].z * _mat.columns[2].y - _mat.columns[0].y * _mat.columns[1].x * _mat.columns[2].z + _mat.columns[0].y * _mat.columns[1].z * _mat.columns[2].x + _mat.columns[0].z * _mat.columns[1].x * _mat.columns[2].y - _mat.columns[0].z * _mat.columns[1].y * _mat.columns[2].x) / determinant(_mat)
	};
}

// transpose for matrices
/**
 * @brief Computes the transpose of a matrix.
 * @param _mat The input matrix.
 */
inline dmat2 transpose(const dmat2& _mat)
{
	return {
		dvec2(_mat.columns[0].x, _mat.columns[1].x),
		dvec2(_mat.columns[0].y, _mat.columns[1].y)
	};
}

/**
 * @brief Computes the transpose of a matrix.
 * @param _mat The input matrix.
 */
inline dmat3 transpose(const dmat3& _mat)
{
	return {
		dvec3(_mat.columns[0].x, _mat.columns[1].x, _mat.columns[2].x),
		dvec3(_mat.columns[0].y, _mat.columns[1].y, _mat.columns[2].y),
		dvec3(_mat.columns[0].z, _mat.columns[1].z, _mat.columns[2].z)
	};
}

/**
 * @brief Computes the transpose of a matrix.
 * @param _mat The input matrix.
 */
inline dmat4 transpose(const dmat4& _mat)
{
	return {
		dvec4(_mat.columns[0].x, _mat.columns[1].x, _mat.columns[2].x, _mat.columns[3].x),
		dvec4(_mat.columns[0].y, _mat.columns[1].y, _mat.columns[2].y, _mat.columns[3].y),
		dvec4(_mat.columns[0].z, _mat.columns[1].z, _mat.columns[2].z, _mat.columns[3].z),
		dvec4(_mat.columns[0].w, _mat.columns[1].w, _mat.columns[2].w, _mat.columns[3].w)
	};
}

#pragma endregion

#pragma endregion double functions

#pragma region int32_t functions

// abs functions
/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline simdint abs(const simdint& _x)
{
	return simd_abs_int(_x);
}

/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline ivec2 abs(const ivec2& _x)
{
	return { abs(_x.x), abs(_x.y) };
}

/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline ivec3 abs(const ivec3& _x)
{
	return { abs(_x.x), abs(_x.y), abs(_x.z) };
}

/**
 * @brief Computes the absolute value of each component.
 * @param _x The input value or vector.
 */
inline ivec4 abs(const ivec4& _x)
{
	return { abs(_x.x), abs(_x.y), abs(_x.z), abs(_x.w) };
}

// blendv functions
/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simdint blendv(const simdint& _falseval, const simdint& _trueval, const simdimask& _mask)
{
#ifdef USE_AVX512
	return _mm512_mask_blend_epi32(_mask, _falseval, _trueval);
#else
	return simd_blendv_int(_falseval, _trueval, _mask);
#endif
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simdint blendv(const int32_t& _falseval, const int32_t& _trueval, const simdimask& _mask)
{
	return blendv(simd_set1_int(_falseval), simd_set1_int(_trueval), _mask);
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simdint blendv(const simdint& _falseval, const int32_t& _trueval, const simdimask& _mask)
{
	return blendv(_falseval, simd_set1_int(_trueval), _mask);
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline simdint blendv(const int32_t& _falseval, const simdint& _trueval, const simdimask& _mask)
{
	return blendv(simd_set1_int(_falseval), _trueval, _mask);
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline ivec2 blendv(const ivec2& _falseval, const ivec2& _trueval, const simdimask& _mask)
{
	return {
		blendv(_falseval.x, _trueval.x, _mask),
		blendv(_falseval.y, _trueval.y, _mask)
	};
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline ivec3 blendv(const ivec3& _falseval, const ivec3& _trueval, const simdimask& _mask)
{
	return {
		blendv(_falseval.x, _trueval.x, _mask),
		blendv(_falseval.y, _trueval.y, _mask),
		blendv(_falseval.z, _trueval.z, _mask)
	};
}

/**
 * @brief Blends two values based on a mask.
 * @param _falseval The value to use when the mask is false.
 * @param _trueval The value to use when the mask is true.
 * @param _mask The selection mask.
 */
inline ivec4 blendv(const ivec4& _falseval, const ivec4& _trueval, const simdimask& _mask)
{
	return {
		blendv(_falseval.x, _trueval.x, _mask),
		blendv(_falseval.y, _trueval.y, _mask),
		blendv(_falseval.z, _trueval.z, _mask),
		blendv(_falseval.w, _trueval.w, _mask)
	};
}

// max functions
/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdint max(const simdint& _val1, const simdint& _val2)
{
	return simd_max_int(_val1, _val2);
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdint max(const simdint& _val1, const int32_t& _val2)
{
	return max(_val1, simd_set1_int(_val2));
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdint max(const int32_t& _val1, const simdint& _val2)
{
	return max(simd_set1_int(_val1), _val2);
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdint max(const int32_t& _val1, const int32_t& _val2)
{
	return max(simd_set1_int(_val1), simd_set1_int(_val2));
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 max(const ivec2& _val1, const simdint& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 max(const simdint& _val1, const ivec2& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 max(const ivec2& _val1, const int32_t& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 max(const int32_t& _val1, const ivec2& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 max(const ivec2& _val1, const ivec2& _val2)
{
	return {
		max(_val1.x, _val2.x),
		max(_val1.y, _val2.y)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 max(const ivec3& _val1, const simdint& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 max(const simdint& _val1, const ivec3& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 max(const ivec3& _val1, const int32_t& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 max(const int32_t& _val1, const ivec3& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 max(const ivec3& _val1, const ivec3& _val2)
{
	return {
		max(_val1.x, _val2.x),
		max(_val1.y, _val2.y),
		max(_val1.z, _val2.z)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 max(const ivec4& _val1, const simdint& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2),
		max(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 max(const simdint& _val1, const ivec4& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z),
		max(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 max(const ivec4& _val1, const int32_t& _val2)
{
	return {
		max(_val1.x, _val2),
		max(_val1.y, _val2),
		max(_val1.z, _val2),
		max(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 max(const int32_t& _val1, const ivec4& _val2)
{
	return {
		max(_val1, _val2.x),
		max(_val1, _val2.y),
		max(_val1, _val2.z),
		max(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise maximum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 max(const ivec4& _val1, const ivec4& _val2)
{
	return {
		max(_val1.x, _val2.x),
		max(_val1.y, _val2.y),
		max(_val1.z, _val2.z),
		max(_val1.w, _val2.w)
	};
}

// min functions
/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdint min(const simdint& _val1, const simdint& _val2)
{
	return simd_min_int(_val1, _val2);
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdint min(const simdint& _val1, const int32_t& _val2)
{
	return min(_val1, simd_set1_int(_val2));
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdint min(const int32_t& _val1, const simdint& _val2)
{
	return min(simd_set1_int(_val1), _val2);
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline simdint min(const int32_t& _val1, const int32_t& _val2)
{
	return min(simd_set1_int(_val1), simd_set1_int(_val2));
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 min(const ivec2& _val1, const simdint& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 min(const simdint& _val1, const ivec2& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 min(const ivec2& _val1, const int32_t& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 min(const int32_t& _val1, const ivec2& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec2 min(const ivec2& _val1, const ivec2& _val2)
{
	return {
		min(_val1.x, _val2.x),
		min(_val1.y, _val2.y)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 min(const ivec3& _val1, const simdint& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 min(const simdint& _val1, const ivec3& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 min(const ivec3& _val1, const int32_t& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 min(const int32_t& _val1, const ivec3& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec3 min(const ivec3& _val1, const ivec3& _val2)
{
	return {
		min(_val1.x, _val2.x),
		min(_val1.y, _val2.y),
		min(_val1.z, _val2.z)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 min(const ivec4& _val1, const simdint& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2),
		min(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 min(const simdint& _val1, const ivec4& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z),
		min(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 min(const ivec4& _val1, const int32_t& _val2)
{
	return {
		min(_val1.x, _val2),
		min(_val1.y, _val2),
		min(_val1.z, _val2),
		min(_val1.w, _val2)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 min(const int32_t& _val1, const ivec4& _val2)
{
	return {
		min(_val1, _val2.x),
		min(_val1, _val2.y),
		min(_val1, _val2.z),
		min(_val1, _val2.w)
	};
}

/**
 * @brief Returns the component-wise minimum of two values.
 * @param _val1 The left-hand side operand.
 * @param _val2 The right-hand side operand.
 */
inline ivec4 min(const ivec4& _val1, const ivec4& _val2)
{
	return {
		min(_val1.x, _val2.x),
		min(_val1.y, _val2.y),
		min(_val1.z, _val2.z),
		min(_val1.w, _val2.w)
	};
}

// clamp functions
/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdint clamp(const simdint& _x, const simdint& _minval, const simdint& _maxval)
{
	return max(min(_x, _maxval), _minval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdint clamp(const int32_t& _x, const int32_t& _minval, const int32_t& _maxval)
{
	return clamp(simd_set1_int(_x), simd_set1_int(_minval), simd_set1_int(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdint clamp(const int32_t& _x, const int32_t& _minval, const simdint& _maxval)
{
	return clamp(simd_set1_int(_x), simd_set1_int(_minval), _maxval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdint clamp(const int32_t& _x, const simdint& _minval, const int32_t& _maxval)
{
	return clamp(simd_set1_int(_x), _minval, simd_set1_int(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdint clamp(const int32_t& _x, const simdint& _minval, const simdint& _maxval)
{
	return clamp(simd_set1_int(_x), _minval, _maxval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdint clamp(const simdint& _x, const int32_t& _minval, const int32_t& _maxval)
{
	return clamp(_x, simd_set1_int(_minval), simd_set1_int(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdint clamp(const simdint& _x, const int32_t& _minval, const simdint& _maxval)
{
	return clamp(_x, simd_set1_int(_minval), _maxval);
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline simdint clamp(const simdint& _x, const simdint& _minval, const int32_t& _maxval)
{
	return clamp(_x, _minval, simd_set1_int(_maxval));
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec2 clamp(const ivec2& _x, const simdint& _minval, const simdint& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec2 clamp(const ivec2& _x, const int32_t& _minval, const int32_t& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec2 clamp(const ivec2& _x, const simdint& _minval, const int32_t& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec2 clamp(const ivec2& _x, const int32_t& _minval, const simdint& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec2 clamp(const ivec2& _x, const ivec2& _minval, const ivec2& _maxval)
{
	return {
		clamp(_x.x, _minval.x, _maxval.x),
		clamp(_x.y, _minval.y, _maxval.y)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec3 clamp(const ivec3& _x, const simdint& _minval, const simdint& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec3 clamp(const ivec3& _x, const int32_t& _minval, const int32_t& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec3 clamp(const ivec3& _x, const simdint& _minval, const int32_t& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec3 clamp(const ivec3& _x, const int32_t& _minval, const simdint& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec3 clamp(const ivec3& _x, const ivec3& _minval, const ivec3& _maxval)
{
	return {
		clamp(_x.x, _minval.x, _maxval.x),
		clamp(_x.y, _minval.y, _maxval.y),
		clamp(_x.z, _minval.z, _maxval.z)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec4 clamp(const ivec4& _x, const simdint& _minval, const simdint& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec4 clamp(const ivec4& _x, const int32_t& _minval, const int32_t& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec4 clamp(const ivec4& _x, const simdint& _minval, const int32_t& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec4 clamp(const ivec4& _x, const int32_t& _minval, const simdint& _maxval)
{
	return {
		clamp(_x.x, _minval, _maxval),
		clamp(_x.y, _minval, _maxval),
		clamp(_x.z, _minval, _maxval),
		clamp(_x.w, _minval, _maxval)
	};
}

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param _x The input value or vector.
 * @param _minval The minimum value.
 * @param _maxval The maximum value.
 */
inline ivec4 clamp(const ivec4& _x, const ivec4& _minval, const ivec4& _maxval)
{
	return {
		clamp(_x.x, _minval.x, _maxval.x),
		clamp(_x.y, _minval.y, _maxval.y),
		clamp(_x.z, _minval.z, _maxval.z),
		clamp(_x.w, _minval.w, _maxval.w)
	};
}

// sign functions
/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline simdint sign(const simdint& _x)
{
	simdimask _maskPos = simd_cmpgt_int(_x, simd_set1_int(0));
	simdimask _maskZero = simd_cmpeq_int(_x, simd_set1_int(0));
	simdint final = blendv(simd_set1_int(-1), simd_set1_int(1), _maskPos);
	final = blendv(final, simd_set1_int(0), _maskZero);
	return final;
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline simdint sign(const int32_t& _x)
{
	return simd_set1_int(_x == 0 ? 0: (_x > 0? 1 : -1));
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline ivec2 sign(const ivec2& _x)
{
	return { sign(_x.x), sign(_x.y) };
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline ivec3 sign(const ivec3& _x)
{
	return { sign(_x.x), sign(_x.y), sign(_x.z) };
}

/**
 * @brief Extracts the sign of each component.
 * @param _x The input value or vector.
 */
inline ivec4 sign(const ivec4& _x)
{
	return { sign(_x.x), sign(_x.y), sign(_x.z), sign(_x.w) };
}

#pragma endregion int32_t functions

#pragma region testmask functions

#ifndef USE_AVX512 // For AVX2 and SSE
// float
/**
 * @brief Return 1 if every mask component is True, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskAll(const simdmask& _mask)
{
#ifdef USE_AVX2
	int32_t maxmask = 0xFF;
#elif defined(USE_NEON)
	int32_t maxmask = 0xF;
#elif defined(USE_PACKED_SCALAR)
	int32_t maxmask = (1 << SIMDWIDTH) - 1;
#elif defined(USE_SSE41) || defined (USE_SSE)
	int32_t maxmask = 0xF;
#elif defined(USE_SCALAR)
	int32_t maxmask = 1;
#endif

	if (simd_movemask_float(_mask) == maxmask)
		return 1;
	else
		return 0;
}

/**
 * @brief Return 1 if every mask component is False, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskNone(const simdmask& _mask)
{
	if (simd_movemask_float(_mask) == 0)
		return 1;
	else
		return 0;
}
// double
/**
 * @brief Return 1 if every mask component is True, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskAll(const simddmask& _mask)
{
#ifdef USE_AVX2
	int32_t maxmask = 0xF;
#elif defined(USE_NEON)
	int32_t maxmask = 0x3;
#elif defined(USE_PACKED_SCALAR)
	int32_t maxmask = (1 << HALFSIMDWIDTH) - 1;
#elif defined(USE_SSE41) || defined (USE_SSE)
	int32_t maxmask = 0x3;
#elif defined (USE_SCALAR)
	int32_t maxmask = 1;
#endif
	if (simd_movemask_double(_mask) == maxmask)
		return 1;
	else
		return 0;
}

/**
 * @brief Return 1 if every mask component is False, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskNone(const simddmask& _mask)
{
	if (simd_movemask_double(_mask) == 0)
		return 1;
	else
		return 0;
}

// int32_t
/**
 * @brief Return 1 if every mask component is True, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskAll(const simdimask& _mask)
{
#ifdef USE_AVX2
	int32_t maxmask = -1;
#elif defined(USE_NEON)
	int32_t maxmask = 0xF;
#elif defined(USE_PACKED_SCALAR)
	int32_t maxmask = (1 << SIMDWIDTH) - 1;
#elif defined(USE_SSE41) || defined (USE_SSE)
	int32_t maxmask = 0xFFFF;
#elif defined (USE_SCALAR)
	int32_t maxmask = 1;
#endif
	if (simd_movemask_epi8(_mask) == maxmask)
		return 1;
	else
		return 0;
}

/**
 * @brief Return 1 if every mask component is False, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskNone(const simdimask& _mask)
{
	if (simd_movemask_epi8(_mask) == 0)
		return 1;
	else
		return 0;
}
#else

/**
 * @brief Return 1 if every mask component is True, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskAll(const simdmask& _mask)
{
	if (static_cast<int32_t>(_mask) == 0xFFFF)
		return 1;
	else
		return 0;
}

/**
 * @brief Return 1 if every mask component is False, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskNone(const simdmask& _mask)
{
	if (static_cast<int32_t>(_mask) == 0x0000)
		return 1;
	else
		return 0;
}

/**
 * @brief Return 1 if every mask component is True, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskAll(const simddmask& _mask)
{
	if (static_cast<int32_t>(_mask) == 0xFF)
		return 1;
	else
		return 0;
}

/**
 * @brief Return 1 if every mask component is False, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskNone(const simddmask& _mask)
{
	if (static_cast<int32_t>(_mask) == 0x0000)
		return 1;
	else
		return 0;
}

/**
 * @brief Return 1 if every mask component is True, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskAll(const simdimask& _mask)
{
	if (static_cast<int32_t>(_mask) == 0xFFFF)
		return 1;
	else
		return 0;
}

/**
 * @brief Return 1 if every mask component is False, 0 otherwise.
 * @param _mask The selection mask.
 */
inline int32_t maskNone(const simdimask& _mask)
{
	if (static_cast<int32_t>(_mask) == 0x0000)
		return 1;
	else
		return 0;
}

#endif// USE_SCALAR

#pragma endregion testmask functions

#endif

