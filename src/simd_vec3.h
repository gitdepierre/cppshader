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
 
#ifndef SIMD_VEC3_H
#define SIMD_VEC3_H

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

struct vec3
{
	simdfloat x, y, z;
	simdfloat& r = x;
	simdfloat& g = y;
	simdfloat& b = z;
	simdfloat& s = x;
	simdfloat& t = y;
	simdfloat& p = z;

	vec3() { x = (0.0f); y = (0.0f); z = (0.0f); }
	vec3(const vec3& other) = default;

	vec3(const float& _f);

	vec3(const simdfloat& _f);

	explicit vec3(const ivec3& _v);

	vec3(const simdfloat& _x, const simdfloat& _y, const simdfloat& _z);

	vec3(const simdfloat& _x, const vec2& _y);

	vec3(const vec2& _x, const simdfloat& _z);

	template<typename V, std::enable_if_t<std::is_same_v<V, vec3>, int> = 0>
	vec3(const simdfloat& _x, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, vec4>, int> = 0>
	vec3(const simdfloat& _x, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, vec2>, int> = 0>
	vec3(const simdfloat& _x, const simdfloat& _y, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, vec3>, int> = 0>
	vec3(const simdfloat& _x, const simdfloat& _y, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, vec4>, int> = 0>
	vec3(const simdfloat& _x, const simdfloat& _y, const V& _v);

	inline vec2 bb() const;
	inline vec3 bbb() const;
	inline vec4 bbbb() const;
	inline vec4 bbbg() const;
	inline vec4 bbbr() const;
	inline vec3 bbg() const;
	inline vec4 bbgb() const;
	inline vec4 bbgg() const;
	inline vec4 bbgr() const;
	inline vec3 bbr() const;
	inline vec4 bbrb() const;
	inline vec4 bbrg() const;
	inline vec4 bbrr() const;
	inline vec2 bg() const;
	inline vec3 bgb() const;
	inline vec4 bgbb() const;
	inline vec4 bgbg() const;
	inline vec4 bgbr() const;
	inline vec3 bgg() const;
	inline vec4 bggb() const;
	inline vec4 bggg() const;
	inline vec4 bggr() const;
	inline vec3 bgr() const;
	inline vec4 bgrb() const;
	inline vec4 bgrg() const;
	inline vec4 bgrr() const;
	inline vec2 br() const;
	inline vec3 brb() const;
	inline vec4 brbb() const;
	inline vec4 brbg() const;
	inline vec4 brbr() const;
	inline vec3 brg() const;
	inline vec4 brgb() const;
	inline vec4 brgg() const;
	inline vec4 brgr() const;
	inline vec3 brr() const;
	inline vec4 brrb() const;
	inline vec4 brrg() const;
	inline vec4 brrr() const;
	inline vec2 gb() const;
	inline vec3 gbb() const;
	inline vec4 gbbb() const;
	inline vec4 gbbg() const;
	inline vec4 gbbr() const;
	inline vec3 gbg() const;
	inline vec4 gbgb() const;
	inline vec4 gbgg() const;
	inline vec4 gbgr() const;
	inline vec3 gbr() const;
	inline vec4 gbrb() const;
	inline vec4 gbrg() const;
	inline vec4 gbrr() const;
	inline vec2 gg() const;
	inline vec3 ggb() const;
	inline vec4 ggbb() const;
	inline vec4 ggbg() const;
	inline vec4 ggbr() const;
	inline vec3 ggg() const;
	inline vec4 gggb() const;
	inline vec4 gggg() const;
	inline vec4 gggr() const;
	inline vec3 ggr() const;
	inline vec4 ggrb() const;
	inline vec4 ggrg() const;
	inline vec4 ggrr() const;
	inline vec2 gr() const;
	inline vec3 grb() const;
	inline vec4 grbb() const;
	inline vec4 grbg() const;
	inline vec4 grbr() const;
	inline vec3 grg() const;
	inline vec4 grgb() const;
	inline vec4 grgg() const;
	inline vec4 grgr() const;
	inline vec3 grr() const;
	inline vec4 grrb() const;
	inline vec4 grrg() const;
	inline vec4 grrr() const;
	inline vec2 rb() const;
	inline vec3 rbb() const;
	inline vec4 rbbb() const;
	inline vec4 rbbg() const;
	inline vec4 rbbr() const;
	inline vec3 rbg() const;
	inline vec4 rbgb() const;
	inline vec4 rbgg() const;
	inline vec4 rbgr() const;
	inline vec3 rbr() const;
	inline vec4 rbrb() const;
	inline vec4 rbrg() const;
	inline vec4 rbrr() const;
	inline vec2 rg() const;
	inline vec3 rgb() const;
	inline vec4 rgbb() const;
	inline vec4 rgbg() const;
	inline vec4 rgbr() const;
	inline vec3 rgg() const;
	inline vec4 rggb() const;
	inline vec4 rggg() const;
	inline vec4 rggr() const;
	inline vec3 rgr() const;
	inline vec4 rgrb() const;
	inline vec4 rgrg() const;
	inline vec4 rgrr() const;
	inline vec2 rr() const;
	inline vec3 rrb() const;
	inline vec4 rrbb() const;
	inline vec4 rrbg() const;
	inline vec4 rrbr() const;
	inline vec3 rrg() const;
	inline vec4 rrgb() const;
	inline vec4 rrgg() const;
	inline vec4 rrgr() const;
	inline vec3 rrr() const;
	inline vec4 rrrb() const;
	inline vec4 rrrg() const;
	inline vec4 rrrr() const;

	inline vec2 ss() const;
	inline vec3 sss() const;
	inline vec4 ssss() const;
	inline vec4 ssst() const;
	inline vec4 sssp() const;
	inline vec3 sst() const;
	inline vec4 ssts() const;
	inline vec4 sstt() const;
	inline vec4 sstp() const;
	inline vec3 ssp() const;
	inline vec4 ssps() const;
	inline vec4 sspt() const;
	inline vec4 sspp() const;
	inline vec2 st() const;
	inline vec3 sts() const;
	inline vec4 stss() const;
	inline vec4 stst() const;
	inline vec4 stsp() const;
	inline vec3 stt() const;
	inline vec4 stts() const;
	inline vec4 sttt() const;
	inline vec4 sttp() const;
	inline vec3 stp() const;
	inline vec4 stps() const;
	inline vec4 stpt() const;
	inline vec4 stpp() const;
	inline vec2 sp() const;
	inline vec3 sps() const;
	inline vec4 spss() const;
	inline vec4 spst() const;
	inline vec4 spsp() const;
	inline vec3 spt() const;
	inline vec4 spts() const;
	inline vec4 sptt() const;
	inline vec4 sptp() const;
	inline vec3 spp() const;
	inline vec4 spps() const;
	inline vec4 sppt() const;
	inline vec4 sppp() const;
	inline vec2 ts() const;
	inline vec3 tss() const;
	inline vec4 tsss() const;
	inline vec4 tsst() const;
	inline vec4 tssp() const;
	inline vec3 tst() const;
	inline vec4 tsts() const;
	inline vec4 tstt() const;
	inline vec4 tstp() const;
	inline vec3 tsp() const;
	inline vec4 tsps() const;
	inline vec4 tspt() const;
	inline vec4 tspp() const;
	inline vec2 tt() const;
	inline vec3 tts() const;
	inline vec4 ttss() const;
	inline vec4 ttst() const;
	inline vec4 ttsp() const;
	inline vec3 ttt() const;
	inline vec4 ttts() const;
	inline vec4 tttt() const;
	inline vec4 tttp() const;
	inline vec3 ttp() const;
	inline vec4 ttps() const;
	inline vec4 ttpt() const;
	inline vec4 ttpp() const;
	inline vec2 tp() const;
	inline vec3 tps() const;
	inline vec4 tpss() const;
	inline vec4 tpst() const;
	inline vec4 tpsp() const;
	inline vec3 tpt() const;
	inline vec4 tpts() const;
	inline vec4 tptt() const;
	inline vec4 tptp() const;
	inline vec3 tpp() const;
	inline vec4 tpps() const;
	inline vec4 tppt() const;
	inline vec4 tppp() const;
	inline vec2 ps() const;
	inline vec3 pss() const;
	inline vec4 psss() const;
	inline vec4 psst() const;
	inline vec4 pssp() const;
	inline vec3 pst() const;
	inline vec4 psts() const;
	inline vec4 pstt() const;
	inline vec4 pstp() const;
	inline vec3 psp() const;
	inline vec4 psps() const;
	inline vec4 pspt() const;
	inline vec4 pspp() const;
	inline vec2 pt() const;
	inline vec3 pts() const;
	inline vec4 ptss() const;
	inline vec4 ptst() const;
	inline vec4 ptsp() const;
	inline vec3 ptt() const;
	inline vec4 ptts() const;
	inline vec4 pttt() const;
	inline vec4 pttp() const;
	inline vec3 ptp() const;
	inline vec4 ptps() const;
	inline vec4 ptpt() const;
	inline vec4 ptpp() const;
	inline vec2 pp() const;
	inline vec3 pps() const;
	inline vec4 ppss() const;
	inline vec4 ppst() const;
	inline vec4 ppsp() const;
	inline vec3 ppt() const;
	inline vec4 ppts() const;
	inline vec4 pptt() const;
	inline vec4 pptp() const;
	inline vec3 ppp() const;
	inline vec4 ppps() const;
	inline vec4 pppt() const;
	inline vec4 pppp() const;
	inline vec2 xx() const;
	inline vec3 xxx() const;
	inline vec4 xxxx() const;
	inline vec4 xxxy() const;
	inline vec4 xxxz() const;
	inline vec3 xxy() const;
	inline vec4 xxyx() const;
	inline vec4 xxyy() const;
	inline vec4 xxyz() const;
	inline vec3 xxz() const;
	inline vec4 xxzx() const;
	inline vec4 xxzy() const;
	inline vec4 xxzz() const;
	inline vec2 xy() const;
	inline vec3 xyx() const;
	inline vec4 xyxx() const;
	inline vec4 xyxy() const;
	inline vec4 xyxz() const;
	inline vec3 xyy() const;
	inline vec4 xyyx() const;
	inline vec4 xyyy() const;
	inline vec4 xyyz() const;
	inline vec3 xyz() const;
	inline vec4 xyzx() const;
	inline vec4 xyzy() const;
	inline vec4 xyzz() const;
	inline vec2 xz() const;
	inline vec3 xzx() const;
	inline vec4 xzxx() const;
	inline vec4 xzxy() const;
	inline vec4 xzxz() const;
	inline vec3 xzy() const;
	inline vec4 xzyx() const;
	inline vec4 xzyy() const;
	inline vec4 xzyz() const;
	inline vec3 xzz() const;
	inline vec4 xzzx() const;
	inline vec4 xzzy() const;
	inline vec4 xzzz() const;
	inline vec2 yx() const;
	inline vec3 yxx() const;
	inline vec4 yxxx() const;
	inline vec4 yxxy() const;
	inline vec4 yxxz() const;
	inline vec3 yxy() const;
	inline vec4 yxyx() const;
	inline vec4 yxyy() const;
	inline vec4 yxyz() const;
	inline vec3 yxz() const;
	inline vec4 yxzx() const;
	inline vec4 yxzy() const;
	inline vec4 yxzz() const;
	inline vec2 yy() const;
	inline vec3 yyx() const;
	inline vec4 yyxx() const;
	inline vec4 yyxy() const;
	inline vec4 yyxz() const;
	inline vec3 yyy() const;
	inline vec4 yyyx() const;
	inline vec4 yyyy() const;
	inline vec4 yyyz() const;
	inline vec3 yyz() const;
	inline vec4 yyzx() const;
	inline vec4 yyzy() const;
	inline vec4 yyzz() const;
	inline vec2 yz() const;
	inline vec3 yzx() const;
	inline vec4 yzxx() const;
	inline vec4 yzxy() const;
	inline vec4 yzxz() const;
	inline vec3 yzy() const;
	inline vec4 yzyx() const;
	inline vec4 yzyy() const;
	inline vec4 yzyz() const;
	inline vec3 yzz() const;
	inline vec4 yzzx() const;
	inline vec4 yzzy() const;
	inline vec4 yzzz() const;
	inline vec2 zx() const;
	inline vec3 zxx() const;
	inline vec4 zxxx() const;
	inline vec4 zxxy() const;
	inline vec4 zxxz() const;
	inline vec3 zxy() const;
	inline vec4 zxyx() const;
	inline vec4 zxyy() const;
	inline vec4 zxyz() const;
	inline vec3 zxz() const;
	inline vec4 zxzx() const;
	inline vec4 zxzy() const;
	inline vec4 zxzz() const;
	inline vec2 zy() const;
	inline vec3 zyx() const;
	inline vec4 zyxx() const;
	inline vec4 zyxy() const;
	inline vec4 zyxz() const;
	inline vec3 zyy() const;
	inline vec4 zyyx() const;
	inline vec4 zyyy() const;
	inline vec4 zyyz() const;
	inline vec3 zyz() const;
	inline vec4 zyzx() const;
	inline vec4 zyzy() const;
	inline vec4 zyzz() const;
	inline vec2 zz() const;
	inline vec3 zzx() const;
	inline vec4 zzxx() const;
	inline vec4 zzxy() const;
	inline vec4 zzxz() const;
	inline vec3 zzy() const;
	inline vec4 zzyx() const;
	inline vec4 zzyy() const;
	inline vec4 zzyz() const;
	inline vec3 zzz() const;
	inline vec4 zzzx() const;
	inline vec4 zzzy() const;
	inline vec4 zzzz() const;
	inline void bg(const simdfloat&, const simdfloat&);
	inline void bg(const vec2&);
	inline void bg(const simdfloat&);
	inline void bgr(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void bgr(const vec3&);
	inline void bgr(const simdfloat&);
	inline void br(const simdfloat&, const simdfloat&);
	inline void br(const vec2&);
	inline void br(const simdfloat&);
	inline void brg(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void brg(const vec3&);
	inline void brg(const simdfloat&);
	inline void gb(const simdfloat&, const simdfloat&);
	inline void gb(const vec2&);
	inline void gb(const simdfloat&);
	inline void gbr(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void gbr(const vec3&);
	inline void gbr(const simdfloat&);
	inline void gr(const simdfloat&, const simdfloat&);
	inline void gr(const vec2&);
	inline void gr(const simdfloat&);
	inline void grb(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void grb(const vec3&);
	inline void grb(const simdfloat&);
	inline void rb(const simdfloat&, const simdfloat&);
	inline void rb(const vec2&);
	inline void rb(const simdfloat&);
	inline void rbg(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void rbg(const vec3&);
	inline void rbg(const simdfloat&);
	inline void rg(const simdfloat&, const simdfloat&);
	inline void rg(const vec2&);
	inline void rg(const simdfloat&);
	inline void rgb(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void rgb(const vec3&);
	inline void rgb(const simdfloat&);
	inline void st(const simdfloat&, const simdfloat&);
	inline void st(const vec2&);
	inline void st(const simdfloat&);
	inline void stp(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void stp(const vec3&);
	inline void stp(const simdfloat&);
	inline void sp(const simdfloat&, const simdfloat&);
	inline void sp(const vec2&);
	inline void sp(const simdfloat&);
	inline void spt(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void spt(const vec3&);
	inline void spt(const simdfloat&);
	inline void ts(const simdfloat&, const simdfloat&);
	inline void ts(const vec2&);
	inline void ts(const simdfloat&);
	inline void tsp(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void tsp(const vec3&);
	inline void tsp(const simdfloat&);
	inline void tp(const simdfloat&, const simdfloat&);
	inline void tp(const vec2&);
	inline void tp(const simdfloat&);
	inline void tps(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void tps(const vec3&);
	inline void tps(const simdfloat&);
	inline void ps(const simdfloat&, const simdfloat&);
	inline void ps(const vec2&);
	inline void ps(const simdfloat&);
	inline void pst(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void pst(const vec3&);
	inline void pst(const simdfloat&);
	inline void pt(const simdfloat&, const simdfloat&);
	inline void pt(const vec2&);
	inline void pt(const simdfloat&);
	inline void pts(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void pts(const vec3&);
	inline void pts(const simdfloat&);
	inline void xy(const simdfloat&, const simdfloat&);
	inline void xy(const vec2&);
	inline void xy(const simdfloat&);
	inline void xyz(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void xyz(const vec3&);
	inline void xyz(const simdfloat&);
	inline void xz(const simdfloat&, const simdfloat&);
	inline void xz(const vec2&);
	inline void xz(const simdfloat&);
	inline void xzy(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void xzy(const vec3&);
	inline void xzy(const simdfloat&);
	inline void yx(const simdfloat&, const simdfloat&);
	inline void yx(const vec2&);
	inline void yx(const simdfloat&);
	inline void yxz(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void yxz(const vec3&);
	inline void yxz(const simdfloat&);
	inline void yz(const simdfloat&, const simdfloat&);
	inline void yz(const vec2&);
	inline void yz(const simdfloat&);
	inline void yzx(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void yzx(const vec3&);
	inline void yzx(const simdfloat&);
	inline void zx(const simdfloat&, const simdfloat&);
	inline void zx(const vec2&);
	inline void zx(const simdfloat&);
	inline void zxy(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void zxy(const vec3&);
	inline void zxy(const simdfloat&);
	inline void zy(const simdfloat&, const simdfloat&);
	inline void zy(const vec2&);
	inline void zy(const simdfloat&);
	inline void zyx(const simdfloat&, const simdfloat&, const simdfloat&);
	inline void zyx(const vec3&);
	inline void zyx(const simdfloat&);

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
		case 2:
			return z;
		default:
			throw std::out_of_range("_index out of range");
		}
	}

	inline vec3 operator=(const ivec3& _v);
	inline vec3 operator=(const vec4& _v);
	inline vec3 operator=(const float& _f)
	{
		x = _f;
		y = _f;
		z = _f;
		return *this;
	}

	inline vec3 operator=(const vec3& _f)
	{
		x = _f.x;
		y = _f.y;
		z = _f.z;
		return *this;
	}

    inline vec3 operator=(const simdfloat_internal& _v)
	{
        x = _v;
        y = _v;
        z = _v;
        return *this;
	}
};

#endif

