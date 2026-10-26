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
 
#ifndef SIMD_DMAT4
#define SIMD_DMAT4

#include "simd_definitions.h"
#include "simd_traits.h"
#include "simd_vectors.h"
#include "simd_swizzle.h"

struct dmat4
{
	dvec4 columns[4];

	dmat4() = default;
	dmat4(const dmat4& other) = default;

	// splat a scalar onto the diagonal.
	template<typename S, typename = std::enable_if_t<is_any_of<S, float, double, int32_t, simddouble>::value>>
	dmat4(const S& _val)
	{
		const simddouble_internal s = make_simddouble_internal(_val);
		const simddouble_internal z = make_simddouble_internal(0);
		columns[0] = dvec4(s, z, z, z);
		columns[1] = dvec4(z, s, z, z);
		columns[2] = dvec4(z, z, s, z);
		columns[3] = dvec4(z, z, z, s);
	}

	explicit dmat4(const simddouble_internal& _val)
	{
		const simddouble_internal z = make_simddouble_internal(0);
		columns[0] = dvec4(_val, z, z, z);
		columns[1] = dvec4(z, _val, z, z);
		columns[2] = dvec4(z, z, _val, z);
		columns[3] = dvec4(z, z, z, _val);
	}

	// sixteen scalars (all elements, column-major).
	template<typename X0, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename X7,
		typename X8, typename X9, typename X10, typename X11, typename X12, typename X13, typename X14, typename X15,
		typename = std::enable_if_t<is_any_of<X0, float, double, int32_t, simddouble>::value && is_any_of<X1, float, double, int32_t, simddouble>::value && is_any_of<X2, float, double, int32_t, simddouble>::value && is_any_of<X3, float, double, int32_t, simddouble>::value
			&& is_any_of<X4, float, double, int32_t, simddouble>::value && is_any_of<X5, float, double, int32_t, simddouble>::value && is_any_of<X6, float, double, int32_t, simddouble>::value && is_any_of<X7, float, double, int32_t, simddouble>::value
			&& is_any_of<X8, float, double, int32_t, simddouble>::value && is_any_of<X9, float, double, int32_t, simddouble>::value && is_any_of<X10, float, double, int32_t, simddouble>::value && is_any_of<X11, float, double, int32_t, simddouble>::value
			&& is_any_of<X12, float, double, int32_t, simddouble>::value && is_any_of<X13, float, double, int32_t, simddouble>::value && is_any_of<X14, float, double, int32_t, simddouble>::value && is_any_of<X15, float, double, int32_t, simddouble>::value>>
	dmat4(const X0& _val0, const X1& _val1, const X2& _val2, const X3& _val3,
		const X4& _val4, const X5& _val5, const X6& _val6, const X7& _val7,
		const X8& _val8, const X9& _val9, const X10& _val10, const X11& _val11,
		const X12& _val12, const X13& _val13, const X14& _val14, const X15& _val15)
	{
		columns[0] = dvec4(make_simddouble_internal(_val0), make_simddouble_internal(_val1), make_simddouble_internal(_val2), make_simddouble_internal(_val3));
		columns[1] = dvec4(make_simddouble_internal(_val4), make_simddouble_internal(_val5), make_simddouble_internal(_val6), make_simddouble_internal(_val7));
		columns[2] = dvec4(make_simddouble_internal(_val8), make_simddouble_internal(_val9), make_simddouble_internal(_val10), make_simddouble_internal(_val11));
		columns[3] = dvec4(make_simddouble_internal(_val12), make_simddouble_internal(_val13), make_simddouble_internal(_val14), make_simddouble_internal(_val15));
	}

	dmat4(const dvec4& _col0, const dvec4& _col1, const dvec4& _col2, const dvec4& _col3)
	{
		columns[0] = _col0;
		columns[1] = _col1;
		columns[2] = _col2;
		columns[3] = _col3;
	}

	// operator [] to access columns
	dvec4& operator[](int32_t _index)
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
	dmat4& operator=(const S& _val) { *this = dmat4(_val); return *this; }

	dmat4& operator=(const simddouble_internal& _val) { *this = dmat4(_val); return *this; }
};

#endif
