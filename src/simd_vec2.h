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
 
#ifndef SIMD_VEC2_H
#define SIMD_VEC2_H

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

struct vec2
{
	simdfloat x, y;
	simdfloat& r = x;
	simdfloat& g = y;
	simdfloat& s = x;
	simdfloat& t = y;

	vec2() { x = (0.0f);	y = (0.0f); }
	vec2(const vec2& other) = default;

	vec2(const float& _f);

	vec2(const simdfloat& _f);

	explicit vec2(const ivec2& _v);

	vec2(const simdfloat& _x, const simdfloat& _y);

	template<typename V, std::enable_if_t<std::is_same_v<V, vec3>, int> = 0>
	vec2(const simdfloat& _x, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, vec4>, int> = 0>
	vec2(const simdfloat& _x, const V& _v);

	// swizzle methods
	inline vec2 gg() const;
	inline vec3 ggg() const;
	inline vec4 gggg() const;
	inline vec4 gggr() const;
	inline vec3 ggr() const;
	inline vec4 ggrg() const;
	inline vec4 ggrr() const;
	inline vec2 gr() const;
	inline vec3 grg() const;
	inline vec4 grgg() const;
	inline vec4 grgr() const;
	inline vec3 grr() const;
	inline vec4 grrg() const;
	inline vec4 grrr() const;
	inline vec2 rg() const;
	inline vec3 rgg() const;
	inline vec4 rggg() const;
	inline vec4 rggr() const;
	inline vec3 rgr() const;
	inline vec4 rgrg() const;
	inline vec4 rgrr() const;
	inline vec2 rr() const;
	inline vec3 rrg() const;
	inline vec4 rrgg() const;
	inline vec4 rrgr() const;
	inline vec3 rrr() const;
	inline vec4 rrrg() const;
	inline vec4 rrrr() const;
	inline vec2 ss() const;
	inline vec3 sss() const;
	inline vec4 ssss() const;
	inline vec4 ssst() const;
	inline vec3 sst() const;
	inline vec4 ssts() const;
	inline vec4 sstt() const;
	inline vec2 st() const;
	inline vec3 sts() const;
	inline vec4 stss() const;
	inline vec4 stst() const;
	inline vec3 stt() const;
	inline vec4 stts() const;
	inline vec4 sttt() const;
	inline vec2 ts() const;
	inline vec3 tss() const;
	inline vec4 tsss() const;
	inline vec4 tsst() const;
	inline vec3 tst() const;
	inline vec4 tsts() const;
	inline vec4 tstt() const;
	inline vec2 tt() const;
	inline vec3 tts() const;
	inline vec4 ttss() const;
	inline vec4 ttst() const;
	inline vec3 ttt() const;
	inline vec4 ttts() const;
	inline vec4 tttt() const;
	inline vec2 xx() const;
	inline vec3 xxx() const;
	inline vec4 xxxx() const;
	inline vec4 xxxy() const;
	inline vec3 xxy() const;
	inline vec4 xxyx() const;
	inline vec4 xxyy() const;
	inline vec2 xy() const;
	inline vec3 xyx() const;
	inline vec4 xyxx() const;
	inline vec4 xyxy() const;
	inline vec3 xyy() const;
	inline vec4 xyyx() const;
	inline vec4 xyyy() const;
	inline vec2 yx() const;
	inline vec3 yxx() const;
	inline vec4 yxxx() const;
	inline vec4 yxxy() const;
	inline vec3 yxy() const;
	inline vec4 yxyx() const;
	inline vec4 yxyy() const;
	inline vec2 yy() const;
	inline vec3 yyx() const;
	inline vec4 yyxx() const;
	inline vec4 yyxy() const;
	inline vec3 yyy() const;
	inline vec4 yyyx() const;
	inline vec4 yyyy() const;
	inline void gr(const simdfloat&, const simdfloat&);
	inline void gr(const vec2&);
	inline void gr(const simdfloat&);
	inline void rg(const simdfloat&, const simdfloat&);
	inline void rg(const vec2&);
	inline void rg(const simdfloat&);
	inline void st(const simdfloat&, const simdfloat&);
	inline void st(const vec2&);
	inline void st(const simdfloat&);
	inline void ts(const simdfloat&, const simdfloat&);
	inline void ts(const vec2&);
	inline void ts(const simdfloat&);
	inline void xy(const simdfloat&, const simdfloat&);
	inline void xy(const vec2&);
	inline void xy(const simdfloat&);
	inline void yx(const simdfloat&, const simdfloat&);
	inline void yx(const vec2&);
	inline void yx(const simdfloat&);

	// operator to access elements like an array
	inline simdfloat& operator[](int32_t _index)
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

	inline vec2 operator=(const ivec2& _v);
	inline vec2 operator=(const vec3& _v);
	inline vec2 operator=(const vec4& _v);
	inline vec2 operator=(const float& _f)
	{
		x = _f;
		y = _f;
		return *this;
	}

	inline vec2 operator=(const int32_t& _f)
	{
		x = _f;
		y = _f;
		return *this;
	}

	inline vec2 operator=(const vec2& _f)
	{
		x = _f.x;
		y = _f.y;
		return *this;
	}

	inline vec2 operator=(const simdfloat_internal& _v)
	{
        x = _v;
        y = _v;
        return *this;
	}
};

#endif

