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
 
#ifndef SIMD_MAT2
#define SIMD_MAT2

#include "simd_definitions.h"
#include "simd_traits.h"
#include "simd_vectors.h"
#include "simd_swizzle.h"

struct mat2
{
	vec2 columns[2];
	mat2() = default;
	mat2(const mat2& other) = default;

	// splat a scalar onto the diagonal.
	template<typename S, typename = std::enable_if_t<is_any_of<S, float, double, int32_t, simdfloat>::value>>
	mat2(const S& _val)
	{
		const simdfloat_internal s = make_simdfloat_internal(_val);
		const simdfloat_internal z = make_simdfloat_internal(0);
		columns[0] = vec2(s, z);
		columns[1] = vec2(z, s);
	}

	explicit mat2(const simdfloat_internal& _val)
	{
		const simdfloat_internal z = make_simdfloat_internal(0);
		columns[0] = vec2(_val, z);
		columns[1] = vec2(z, _val);
	}

	// four scalars (all elements, column-major).
	template<typename X, typename Y, typename Z, typename W, typename = std::enable_if_t<is_any_of<X, float, double, int32_t, simdfloat>::value && is_any_of<Y, float, double, int32_t, simdfloat>::value && is_any_of<Z, float, double, int32_t, simdfloat>::value && is_any_of<W, float, double, int32_t, simdfloat>::value>>
	mat2(const X& _val0, const Y& _val1, const Z& _val2, const W& _val3)
	{
		columns[0] = vec2(make_simdfloat_internal(_val0), make_simdfloat_internal(_val1));
		columns[1] = vec2(make_simdfloat_internal(_val2), make_simdfloat_internal(_val3));
	}

	mat2(const vec2& column0, const vec2& column1)
	{
		columns[0] = column0;
		columns[1] = column1;
	}

	mat2(const vec2& _val)
	{
		columns[0] = _val;
		columns[1] = _val;
	}

	mat2(const vec4& _val)
	{
		columns[0] = vec2(_val.x, _val.y);
		columns[1] = vec2(_val.z, _val.w);
	}

	// operator [] to access columns
	vec2& operator[](int32_t _index)
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
	mat2& operator=(const S& _val) { *this = mat2(_val); return *this; }

	mat2& operator=(const simdfloat_internal& _val) { *this = mat2(_val); return *this; }

	mat2& operator=(const vec2& _val) { *this = mat2(_val); return *this; }

	mat2& operator=(const vec4& _val) { *this = mat2(_val); return *this; }
};

#endif

