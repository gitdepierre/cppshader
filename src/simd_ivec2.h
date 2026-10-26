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
 
#ifndef SIMD_IVEC2_H
#define SIMD_IVEC2_H

#include "simd_definitions.h"
#include "simd_traits.h"

struct vec2;
struct vec3;
struct vec4;
struct dvec2;
struct dvec3;
struct dvec4;
struct ivec2;
struct ivec3;
struct ivec4;

struct ivec2
{
	simdint x, y;
	simdint& r = x;
	simdint& g = y;
	simdint& s = x;
	simdint& t = y;

	ivec2() { x = (0);	y = (0); }
	ivec2(const ivec2& other) = default;

	ivec2(const int32_t& _f);

	ivec2(const simdint& _f);

	explicit ivec2(const vec2& _v);

	ivec2(const simdint& _x, const simdint& _y);

	template<typename V, std::enable_if_t<std::is_same_v<V, ivec3>, int> = 0>
	ivec2(const simdint& _x, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, ivec4>, int> = 0>
	ivec2(const simdint& _x, const V& _v);

	// swizzle methods
	inline ivec2 gg() const;
	inline ivec3 ggg() const;
	inline ivec4 gggg() const;
	inline ivec4 gggr() const;
	inline ivec3 ggr() const;
	inline ivec4 ggrg() const;
	inline ivec4 ggrr() const;
	inline ivec2 gr() const;
	inline ivec3 grg() const;
	inline ivec4 grgg() const;
	inline ivec4 grgr() const;
	inline ivec3 grr() const;
	inline ivec4 grrg() const;
	inline ivec4 grrr() const;
	inline ivec2 rg() const;
	inline ivec3 rgg() const;
	inline ivec4 rggg() const;
	inline ivec4 rggr() const;
	inline ivec3 rgr() const;
	inline ivec4 rgrg() const;
	inline ivec4 rgrr() const;
	inline ivec2 rr() const;
	inline ivec3 rrg() const;
	inline ivec4 rrgg() const;
	inline ivec4 rrgr() const;
	inline ivec3 rrr() const;
	inline ivec4 rrrg() const;
	inline ivec4 rrrr() const;
	inline ivec2 ss() const;
	inline ivec3 sss() const;
	inline ivec4 ssss() const;
	inline ivec4 ssst() const;
	inline ivec3 sst() const;
	inline ivec4 ssts() const;
	inline ivec4 sstt() const;
	inline ivec2 st() const;
	inline ivec3 sts() const;
	inline ivec4 stss() const;
	inline ivec4 stst() const;
	inline ivec3 stt() const;
	inline ivec4 stts() const;
	inline ivec4 sttt() const;
	inline ivec2 ts() const;
	inline ivec3 tss() const;
	inline ivec4 tsss() const;
	inline ivec4 tsst() const;
	inline ivec3 tst() const;
	inline ivec4 tsts() const;
	inline ivec4 tstt() const;
	inline ivec2 tt() const;
	inline ivec3 tts() const;
	inline ivec4 ttss() const;
	inline ivec4 ttst() const;
	inline ivec3 ttt() const;
	inline ivec4 ttts() const;
	inline ivec4 tttt() const;
	inline ivec2 xx() const;
	inline ivec3 xxx() const;
	inline ivec4 xxxx() const;
	inline ivec4 xxxy() const;
	inline ivec3 xxy() const;
	inline ivec4 xxyx() const;
	inline ivec4 xxyy() const;
	inline ivec2 xy() const;
	inline ivec3 xyx() const;
	inline ivec4 xyxx() const;
	inline ivec4 xyxy() const;
	inline ivec3 xyy() const;
	inline ivec4 xyyx() const;
	inline ivec4 xyyy() const;
	inline ivec2 yx() const;
	inline ivec3 yxx() const;
	inline ivec4 yxxx() const;
	inline ivec4 yxxy() const;
	inline ivec3 yxy() const;
	inline ivec4 yxyx() const;
	inline ivec4 yxyy() const;
	inline ivec2 yy() const;
	inline ivec3 yyx() const;
	inline ivec4 yyxx() const;
	inline ivec4 yyxy() const;
	inline ivec3 yyy() const;
	inline ivec4 yyyx() const;
	inline ivec4 yyyy() const;
	inline void gr(const simdint&, const simdint&);
	inline void gr(const ivec2&);
	inline void gr(const simdint&);
	inline void rg(const simdint&, const simdint&);
	inline void rg(const ivec2&);
	inline void rg(const simdint&);
	inline void st(const simdint&, const simdint&);
	inline void st(const ivec2&);
	inline void st(const simdint&);
	inline void ts(const simdint&, const simdint&);
	inline void ts(const ivec2&);
	inline void ts(const simdint&);
	inline void xy(const simdint&, const simdint&);
	inline void xy(const ivec2&);
	inline void xy(const simdint&);
	inline void yx(const simdint&, const simdint&);
	inline void yx(const ivec2&);
	inline void yx(const simdint&);

	// operator to access elements like an array
	inline simdint& operator[](int32_t _index)
	{
		// use a switch to return the correct element
		switch (_index)
		{
		case 0:
			return x;
		case 1:
			return y;
		default:
			throw std::out_of_range("_index out of range");
		}
	}

	inline ivec2 operator=(const vec2& _v);
	inline ivec2 operator=(const ivec3& _v);
	inline ivec2 operator=(const ivec4& _v);
	inline ivec2 operator=(const int32_t& _i)
	{
		x = _i;
		y = _i;
		return *this;
	}

	inline ivec2 operator=(const ivec2& _f)
	{
		x = _f.x;
		y = _f.y;
		return *this;
	}

	inline ivec2 operator=(const simdint_internal& _v)
	{
		x = _v;
		y = _v;
        return *this;
	}
};

#endif


