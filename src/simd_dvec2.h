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
 
#ifndef SIMD_DVEC2_H
#define SIMD_DVEC2_H

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

struct dvec2
{
	simddouble x, y;
	simddouble& r = x;
	simddouble& g = y;
	simddouble& s = x;
	simddouble& t = y;

	dvec2() { x = (0.0);	y = (0.0); }
	dvec2(const dvec2& other) = default;

	dvec2(const double& _f);

	// splat a simddouble_internal into both components.
	dvec2(const simddouble& _f);

	// two scalars 
	dvec2(const simddouble& _x, const simddouble& _y);

	template<typename V, std::enable_if_t<std::is_same_v<V, dvec3>, int> = 0>
	dvec2(const simddouble& _x, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, dvec4>, int> = 0>
	dvec2(const simddouble& _x, const V& _v);


	// swizzle methods
	inline dvec2 gg() const;
	inline dvec3 ggg() const;
	inline dvec4 gggg() const;
	inline dvec4 gggr() const;
	inline dvec3 ggr() const;
	inline dvec4 ggrg() const;
	inline dvec4 ggrr() const;
	inline dvec2 gr() const;
	inline dvec3 grg() const;
	inline dvec4 grgg() const;
	inline dvec4 grgr() const;
	inline dvec3 grr() const;
	inline dvec4 grrg() const;
	inline dvec4 grrr() const;
	inline dvec2 rg() const;
	inline dvec3 rgg() const;
	inline dvec4 rggg() const;
	inline dvec4 rggr() const;
	inline dvec3 rgr() const;
	inline dvec4 rgrg() const;
	inline dvec4 rgrr() const;
	inline dvec2 rr() const;
	inline dvec3 rrg() const;
	inline dvec4 rrgg() const;
	inline dvec4 rrgr() const;
	inline dvec3 rrr() const;
	inline dvec4 rrrg() const;
	inline dvec4 rrrr() const;
	inline dvec2 ss() const;
	inline dvec3 sss() const;
	inline dvec4 ssss() const;
	inline dvec4 ssst() const;
	inline dvec3 sst() const;
	inline dvec4 ssts() const;
	inline dvec4 sstt() const;
	inline dvec2 st() const;
	inline dvec3 sts() const;
	inline dvec4 stss() const;
	inline dvec4 stst() const;
	inline dvec3 stt() const;
	inline dvec4 stts() const;
	inline dvec4 sttt() const;
	inline dvec2 ts() const;
	inline dvec3 tss() const;
	inline dvec4 tsss() const;
	inline dvec4 tsst() const;
	inline dvec3 tst() const;
	inline dvec4 tsts() const;
	inline dvec4 tstt() const;
	inline dvec2 tt() const;
	inline dvec3 tts() const;
	inline dvec4 ttss() const;
	inline dvec4 ttst() const;
	inline dvec3 ttt() const;
	inline dvec4 ttts() const;
	inline dvec4 tttt() const;
	inline dvec2 xx() const;
	inline dvec3 xxx() const;
	inline dvec4 xxxx() const;
	inline dvec4 xxxy() const;
	inline dvec3 xxy() const;
	inline dvec4 xxyx() const;
	inline dvec4 xxyy() const;
	inline dvec2 xy() const;
	inline dvec3 xyx() const;
	inline dvec4 xyxx() const;
	inline dvec4 xyxy() const;
	inline dvec3 xyy() const;
	inline dvec4 xyyx() const;
	inline dvec4 xyyy() const;
	inline dvec2 yx() const;
	inline dvec3 yxx() const;
	inline dvec4 yxxx() const;
	inline dvec4 yxxy() const;
	inline dvec3 yxy() const;
	inline dvec4 yxyx() const;
	inline dvec4 yxyy() const;
	inline dvec2 yy() const;
	inline dvec3 yyx() const;
	inline dvec4 yyxx() const;
	inline dvec4 yyxy() const;
	inline dvec3 yyy() const;
	inline dvec4 yyyx() const;
	inline dvec4 yyyy() const;
	inline void gr(const simddouble&, const simddouble&);
	inline void gr(const dvec2&);
	inline void gr(const simddouble&);
	inline void rg(const simddouble&, const simddouble&);
	inline void rg(const dvec2&);
	inline void rg(const simddouble&);
	inline void st(const simddouble&, const simddouble&);
	inline void st(const dvec2&);
	inline void st(const simddouble&);
	inline void ts(const simddouble&, const simddouble&);
	inline void ts(const dvec2&);
	inline void ts(const simddouble&);
	inline void xy(const simddouble&, const simddouble&);
	inline void xy(const dvec2&);
	inline void xy(const simddouble&);
	inline void yx(const simddouble&, const simddouble&);
	inline void yx(const dvec2&);
	inline void yx(const simddouble&);

	// operator to access elements like an array
	inline simddouble& operator[](int32_t _index)
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

	inline dvec2 operator=(const dvec3& _v);
	inline dvec2 operator=(const dvec4& _v);

	inline dvec2 operator=(const dvec2& _f)
	{
		x = _f.x;
		y = _f.y;
		return *this;
	}

	inline dvec2 operator=(const double& _d)
	{
		x = _d;
		y = _d;
		return *this;
	}

	inline dvec2 operator=(const simddouble_internal& _v)
	{
		x = _v;
		y = _v;
        return *this;
	}
};

#endif


