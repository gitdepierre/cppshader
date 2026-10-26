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
 
#ifndef SIMD_MAT3
#define SIMD_MAT3

#include "simd_definitions.h"
#include "simd_traits.h"
#include "simd_vectors.h"
#include "simd_swizzle.h"

struct mat3
{
	vec3 columns[3];

	mat3() = default;
	mat3(const mat3& other) = default;

	// splat a scalar onto the diagonal.
	template<typename S, typename = std::enable_if_t<is_any_of<S, float, double, int32_t, simdfloat>::value>>
	mat3(const S& _val)
	{
		const simdfloat_internal s = make_simdfloat_internal(_val);
		const simdfloat_internal z = make_simdfloat_internal(0);
		columns[0] = vec3(s, z, z);
		columns[1] = vec3(z, s, z);
		columns[2] = vec3(z, z, s);
	}

	explicit mat3(const simdfloat_internal& _val)
	{
		const simdfloat_internal z = make_simdfloat_internal(0);
		columns[0] = vec3(_val, z, z);
		columns[1] = vec3(z, _val, z);
		columns[2] = vec3(z, z, _val);
	}

	// Nine scalars (all elements, column-major).
	template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7, typename X8,
		typename = std::enable_if_t<is_any_of<X0, float, double, int32_t, simdfloat>::value && is_any_of<X1, float, double, int32_t, simdfloat>::value && is_any_of<X2, float, double, int32_t, simdfloat>::value
			&& is_any_of<X3, float, double, int32_t, simdfloat>::value && is_any_of<X4, float, double, int32_t, simdfloat>::value && is_any_of<X5, float, double, int32_t, simdfloat>::value
			&& is_any_of<X6, float, double, int32_t, simdfloat>::value && is_any_of<X7, float, double, int32_t, simdfloat>::value && is_any_of<X8, float, double, int32_t, simdfloat>::value>>
	mat3(const X0& _val0, const X1& _val1, const X2& _val2,
		const X3& _val3, const X4& _val4, const X5& _val5,
		const X6& _val6, const X7& _val7, const X8& _val8)
	{
		columns[0] = vec3(make_simdfloat_internal(_val0), make_simdfloat_internal(_val1), make_simdfloat_internal(_val2));
		columns[1] = vec3(make_simdfloat_internal(_val3), make_simdfloat_internal(_val4), make_simdfloat_internal(_val5));
		columns[2] = vec3(make_simdfloat_internal(_val6), make_simdfloat_internal(_val7), make_simdfloat_internal(_val8));
	}

	mat3(const vec3& column0, const vec3& column1, const vec3& column2)
	{
		columns[0] = column0;
		columns[1] = column1;
		columns[2] = column2;
	}

	// operator [] to access columns
	vec3& operator[](int32_t _index)
	{
		return columns[_index];
	}

	// operator [][] to access elements
	simdfloat& operator()(int32_t _row, int32_t _col)
	{
		return columns[_col][_row];
	}

	// assignments mirror the constructors above
	template<typename S, typename = std::enable_if_t<is_any_of<S, float, double, int32_t, simdfloat>::value>>
	mat3& operator=(const S& _val) { *this = mat3(_val); return *this; }

	mat3& operator=(const simdfloat_internal& _val) { *this = mat3(_val); return *this; }
};

#endif

