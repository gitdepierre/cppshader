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
 
#ifndef SIMD_DMAT2
#define SIMD_DMAT2

#include "simd_definitions.h"
#include "simd_traits.h"
#include "simd_vectors.h"
#include "simd_swizzle.h"

struct dmat2
{
	dvec2 columns[2];
	dmat2() = default;
	dmat2(const dmat2& other) = default;

	// splat a scalar onto the diagonal.
	template<typename S, typename = std::enable_if_t<is_any_of<S, float, double, int32_t, simddouble>::value>>
	dmat2(const S& _val)
	{
		const simddouble_internal s = make_simddouble_internal(_val);
		const simddouble_internal z = make_simddouble_internal(0);
		columns[0] = dvec2(s, z);
		columns[1] = dvec2(z, s);
	}

	explicit dmat2(const simddouble_internal& _val)
	{
		const simddouble_internal z = make_simddouble_internal(0);
		columns[0] = dvec2(_val, z);
		columns[1] = dvec2(z, _val);
	}

	// four scalars (all elements, column-major).
	template<typename X, typename Y, typename Z, typename W, typename = std::enable_if_t<is_any_of<X, float, double, int32_t, simddouble>::value && is_any_of<Y, float, double, int32_t, simddouble>::value && is_any_of<Z, float, double, int32_t, simddouble>::value && is_any_of<W, float, double, int32_t, simddouble>::value>>
	dmat2(const X& _val0, const Y& _val1, const Z& _val2, const W& _val3)
	{
		columns[0] = dvec2(make_simddouble_internal(_val0), make_simddouble_internal(_val1));
		columns[1] = dvec2(make_simddouble_internal(_val2), make_simddouble_internal(_val3));
	}

	dmat2(const dvec2& column0, const dvec2& column1)
	{
		columns[0] = column0;
		columns[1] = column1;
	}

	dmat2(const dvec2& _val)
	{
		columns[0] = _val;
		columns[1] = _val;
	}

	dmat2(const dvec4& _val)
	{
		columns[0] = dvec2(_val.x, _val.y);
		columns[1] = dvec2(_val.z, _val.w);
	}

	// operator [] to access columns
	dvec2& operator[](int32_t _index)
	{
		return columns[_index];
	}
	// operator [][] to access elements
	simddouble& operator()(int32_t _row, int32_t _col)
	{
		return columns[_col][_row];
	}

// assignments mirror the constructors above
	template<typename S, typename = std::enable_if_t<is_any_of<S, float, double, int32_t, simddouble>::value>>
	dmat2& operator=(const S& _val) { *this = dmat2(_val); return *this; }

	dmat2& operator=(const simddouble_internal& _val) { *this = dmat2(_val); return *this; }

	dmat2& operator=(const dvec2& _val) { *this = dmat2(_val); return *this; }

	dmat2& operator=(const dvec4& _val) { *this = dmat2(_val); return *this; }
};

#endif

