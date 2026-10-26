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
 
#ifndef SIMD_IVEC3_H
#define SIMD_IVEC3_H

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

struct ivec3
{
	simdint x, y, z;
	simdint& r = x;
	simdint& g = y;
	simdint& b = z;
	simdint& s = x;
	simdint& t = y;
	simdint& p = z;

	ivec3() { x = (0); y = (0); z = (0); }
	ivec3(const ivec3& other) = default;

	ivec3(const int32_t& _f);

	ivec3(const simdint& _f);

	explicit ivec3(const vec3& _v);

	ivec3(const simdint& _x, const simdint& _y, const simdint& _z);

	ivec3(const simdint& _x, const ivec2& _y);

	ivec3(const ivec2& _x, const simdint& _z);

	template<typename V, std::enable_if_t<std::is_same_v<V, ivec3>, int> = 0>
	ivec3(const simdint& _x, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, ivec4>, int> = 0>
	ivec3(const simdint& _x, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, ivec2>, int> = 0>
	ivec3(const simdint& _x, const simdint& _y, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, ivec3>, int> = 0>
	ivec3(const simdint& _x, const simdint& _y, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, ivec4>, int> = 0>
	ivec3(const simdint& _x, const simdint& _y, const V& _v);

	inline ivec2 bb() const;
	inline ivec3 bbb() const;
	inline ivec4 bbbb() const;
	inline ivec4 bbbg() const;
	inline ivec4 bbbr() const;
	inline ivec3 bbg() const;
	inline ivec4 bbgb() const;
	inline ivec4 bbgg() const;
	inline ivec4 bbgr() const;
	inline ivec3 bbr() const;
	inline ivec4 bbrb() const;
	inline ivec4 bbrg() const;
	inline ivec4 bbrr() const;
	inline ivec2 bg() const;
	inline ivec3 bgb() const;
	inline ivec4 bgbb() const;
	inline ivec4 bgbg() const;
	inline ivec4 bgbr() const;
	inline ivec3 bgg() const;
	inline ivec4 bggb() const;
	inline ivec4 bggg() const;
	inline ivec4 bggr() const;
	inline ivec3 bgr() const;
	inline ivec4 bgrb() const;
	inline ivec4 bgrg() const;
	inline ivec4 bgrr() const;
	inline ivec2 br() const;
	inline ivec3 brb() const;
	inline ivec4 brbb() const;
	inline ivec4 brbg() const;
	inline ivec4 brbr() const;
	inline ivec3 brg() const;
	inline ivec4 brgb() const;
	inline ivec4 brgg() const;
	inline ivec4 brgr() const;
	inline ivec3 brr() const;
	inline ivec4 brrb() const;
	inline ivec4 brrg() const;
	inline ivec4 brrr() const;
	inline ivec2 gb() const;
	inline ivec3 gbb() const;
	inline ivec4 gbbb() const;
	inline ivec4 gbbg() const;
	inline ivec4 gbbr() const;
	inline ivec3 gbg() const;
	inline ivec4 gbgb() const;
	inline ivec4 gbgg() const;
	inline ivec4 gbgr() const;
	inline ivec3 gbr() const;
	inline ivec4 gbrb() const;
	inline ivec4 gbrg() const;
	inline ivec4 gbrr() const;
	inline ivec2 gg() const;
	inline ivec3 ggb() const;
	inline ivec4 ggbb() const;
	inline ivec4 ggbg() const;
	inline ivec4 ggbr() const;
	inline ivec3 ggg() const;
	inline ivec4 gggb() const;
	inline ivec4 gggg() const;
	inline ivec4 gggr() const;
	inline ivec3 ggr() const;
	inline ivec4 ggrb() const;
	inline ivec4 ggrg() const;
	inline ivec4 ggrr() const;
	inline ivec2 gr() const;
	inline ivec3 grb() const;
	inline ivec4 grbb() const;
	inline ivec4 grbg() const;
	inline ivec4 grbr() const;
	inline ivec3 grg() const;
	inline ivec4 grgb() const;
	inline ivec4 grgg() const;
	inline ivec4 grgr() const;
	inline ivec3 grr() const;
	inline ivec4 grrb() const;
	inline ivec4 grrg() const;
	inline ivec4 grrr() const;
	inline ivec2 rb() const;
	inline ivec3 rbb() const;
	inline ivec4 rbbb() const;
	inline ivec4 rbbg() const;
	inline ivec4 rbbr() const;
	inline ivec3 rbg() const;
	inline ivec4 rbgb() const;
	inline ivec4 rbgg() const;
	inline ivec4 rbgr() const;
	inline ivec3 rbr() const;
	inline ivec4 rbrb() const;
	inline ivec4 rbrg() const;
	inline ivec4 rbrr() const;
	inline ivec2 rg() const;
	inline ivec3 rgb() const;
	inline ivec4 rgbb() const;
	inline ivec4 rgbg() const;
	inline ivec4 rgbr() const;
	inline ivec3 rgg() const;
	inline ivec4 rggb() const;
	inline ivec4 rggg() const;
	inline ivec4 rggr() const;
	inline ivec3 rgr() const;
	inline ivec4 rgrb() const;
	inline ivec4 rgrg() const;
	inline ivec4 rgrr() const;
	inline ivec2 rr() const;
	inline ivec3 rrb() const;
	inline ivec4 rrbb() const;
	inline ivec4 rrbg() const;
	inline ivec4 rrbr() const;
	inline ivec3 rrg() const;
	inline ivec4 rrgb() const;
	inline ivec4 rrgg() const;
	inline ivec4 rrgr() const;
	inline ivec3 rrr() const;
	inline ivec4 rrrb() const;
	inline ivec4 rrrg() const;
	inline ivec4 rrrr() const;

	inline ivec2 ss() const;
	inline ivec3 sss() const;
	inline ivec4 ssss() const;
	inline ivec4 ssst() const;
	inline ivec4 sssp() const;
	inline ivec3 sst() const;
	inline ivec4 ssts() const;
	inline ivec4 sstt() const;
	inline ivec4 sstp() const;
	inline ivec3 ssp() const;
	inline ivec4 ssps() const;
	inline ivec4 sspt() const;
	inline ivec4 sspp() const;
	inline ivec2 st() const;
	inline ivec3 sts() const;
	inline ivec4 stss() const;
	inline ivec4 stst() const;
	inline ivec4 stsp() const;
	inline ivec3 stt() const;
	inline ivec4 stts() const;
	inline ivec4 sttt() const;
	inline ivec4 sttp() const;
	inline ivec3 stp() const;
	inline ivec4 stps() const;
	inline ivec4 stpt() const;
	inline ivec4 stpp() const;
	inline ivec2 sp() const;
	inline ivec3 sps() const;
	inline ivec4 spss() const;
	inline ivec4 spst() const;
	inline ivec4 spsp() const;
	inline ivec3 spt() const;
	inline ivec4 spts() const;
	inline ivec4 sptt() const;
	inline ivec4 sptp() const;
	inline ivec3 spp() const;
	inline ivec4 spps() const;
	inline ivec4 sppt() const;
	inline ivec4 sppp() const;
	inline ivec2 ts() const;
	inline ivec3 tss() const;
	inline ivec4 tsss() const;
	inline ivec4 tsst() const;
	inline ivec4 tssp() const;
	inline ivec3 tst() const;
	inline ivec4 tsts() const;
	inline ivec4 tstt() const;
	inline ivec4 tstp() const;
	inline ivec3 tsp() const;
	inline ivec4 tsps() const;
	inline ivec4 tspt() const;
	inline ivec4 tspp() const;
	inline ivec2 tt() const;
	inline ivec3 tts() const;
	inline ivec4 ttss() const;
	inline ivec4 ttst() const;
	inline ivec4 ttsp() const;
	inline ivec3 ttt() const;
	inline ivec4 ttts() const;
	inline ivec4 tttt() const;
	inline ivec4 tttp() const;
	inline ivec3 ttp() const;
	inline ivec4 ttps() const;
	inline ivec4 ttpt() const;
	inline ivec4 ttpp() const;
	inline ivec2 tp() const;
	inline ivec3 tps() const;
	inline ivec4 tpss() const;
	inline ivec4 tpst() const;
	inline ivec4 tpsp() const;
	inline ivec3 tpt() const;
	inline ivec4 tpts() const;
	inline ivec4 tptt() const;
	inline ivec4 tptp() const;
	inline ivec3 tpp() const;
	inline ivec4 tpps() const;
	inline ivec4 tppt() const;
	inline ivec4 tppp() const;
	inline ivec2 ps() const;
	inline ivec3 pss() const;
	inline ivec4 psss() const;
	inline ivec4 psst() const;
	inline ivec4 pssp() const;
	inline ivec3 pst() const;
	inline ivec4 psts() const;
	inline ivec4 pstt() const;
	inline ivec4 pstp() const;
	inline ivec3 psp() const;
	inline ivec4 psps() const;
	inline ivec4 pspt() const;
	inline ivec4 pspp() const;
	inline ivec2 pt() const;
	inline ivec3 pts() const;
	inline ivec4 ptss() const;
	inline ivec4 ptst() const;
	inline ivec4 ptsp() const;
	inline ivec3 ptt() const;
	inline ivec4 ptts() const;
	inline ivec4 pttt() const;
	inline ivec4 pttp() const;
	inline ivec3 ptp() const;
	inline ivec4 ptps() const;
	inline ivec4 ptpt() const;
	inline ivec4 ptpp() const;
	inline ivec2 pp() const;
	inline ivec3 pps() const;
	inline ivec4 ppss() const;
	inline ivec4 ppst() const;
	inline ivec4 ppsp() const;
	inline ivec3 ppt() const;
	inline ivec4 ppts() const;
	inline ivec4 pptt() const;
	inline ivec4 pptp() const;
	inline ivec3 ppp() const;
	inline ivec4 ppps() const;
	inline ivec4 pppt() const;
	inline ivec4 pppp() const;
	inline ivec2 xx() const;
	inline ivec3 xxx() const;
	inline ivec4 xxxx() const;
	inline ivec4 xxxy() const;
	inline ivec4 xxxz() const;
	inline ivec3 xxy() const;
	inline ivec4 xxyx() const;
	inline ivec4 xxyy() const;
	inline ivec4 xxyz() const;
	inline ivec3 xxz() const;
	inline ivec4 xxzx() const;
	inline ivec4 xxzy() const;
	inline ivec4 xxzz() const;
	inline ivec2 xy() const;
	inline ivec3 xyx() const;
	inline ivec4 xyxx() const;
	inline ivec4 xyxy() const;
	inline ivec4 xyxz() const;
	inline ivec3 xyy() const;
	inline ivec4 xyyx() const;
	inline ivec4 xyyy() const;
	inline ivec4 xyyz() const;
	inline ivec3 xyz() const;
	inline ivec4 xyzx() const;
	inline ivec4 xyzy() const;
	inline ivec4 xyzz() const;
	inline ivec2 xz() const;
	inline ivec3 xzx() const;
	inline ivec4 xzxx() const;
	inline ivec4 xzxy() const;
	inline ivec4 xzxz() const;
	inline ivec3 xzy() const;
	inline ivec4 xzyx() const;
	inline ivec4 xzyy() const;
	inline ivec4 xzyz() const;
	inline ivec3 xzz() const;
	inline ivec4 xzzx() const;
	inline ivec4 xzzy() const;
	inline ivec4 xzzz() const;
	inline ivec2 yx() const;
	inline ivec3 yxx() const;
	inline ivec4 yxxx() const;
	inline ivec4 yxxy() const;
	inline ivec4 yxxz() const;
	inline ivec3 yxy() const;
	inline ivec4 yxyx() const;
	inline ivec4 yxyy() const;
	inline ivec4 yxyz() const;
	inline ivec3 yxz() const;
	inline ivec4 yxzx() const;
	inline ivec4 yxzy() const;
	inline ivec4 yxzz() const;
	inline ivec2 yy() const;
	inline ivec3 yyx() const;
	inline ivec4 yyxx() const;
	inline ivec4 yyxy() const;
	inline ivec4 yyxz() const;
	inline ivec3 yyy() const;
	inline ivec4 yyyx() const;
	inline ivec4 yyyy() const;
	inline ivec4 yyyz() const;
	inline ivec3 yyz() const;
	inline ivec4 yyzx() const;
	inline ivec4 yyzy() const;
	inline ivec4 yyzz() const;
	inline ivec2 yz() const;
	inline ivec3 yzx() const;
	inline ivec4 yzxx() const;
	inline ivec4 yzxy() const;
	inline ivec4 yzxz() const;
	inline ivec3 yzy() const;
	inline ivec4 yzyx() const;
	inline ivec4 yzyy() const;
	inline ivec4 yzyz() const;
	inline ivec3 yzz() const;
	inline ivec4 yzzx() const;
	inline ivec4 yzzy() const;
	inline ivec4 yzzz() const;
	inline ivec2 zx() const;
	inline ivec3 zxx() const;
	inline ivec4 zxxx() const;
	inline ivec4 zxxy() const;
	inline ivec4 zxxz() const;
	inline ivec3 zxy() const;
	inline ivec4 zxyx() const;
	inline ivec4 zxyy() const;
	inline ivec4 zxyz() const;
	inline ivec3 zxz() const;
	inline ivec4 zxzx() const;
	inline ivec4 zxzy() const;
	inline ivec4 zxzz() const;
	inline ivec2 zy() const;
	inline ivec3 zyx() const;
	inline ivec4 zyxx() const;
	inline ivec4 zyxy() const;
	inline ivec4 zyxz() const;
	inline ivec3 zyy() const;
	inline ivec4 zyyx() const;
	inline ivec4 zyyy() const;
	inline ivec4 zyyz() const;
	inline ivec3 zyz() const;
	inline ivec4 zyzx() const;
	inline ivec4 zyzy() const;
	inline ivec4 zyzz() const;
	inline ivec2 zz() const;
	inline ivec3 zzx() const;
	inline ivec4 zzxx() const;
	inline ivec4 zzxy() const;
	inline ivec4 zzxz() const;
	inline ivec3 zzy() const;
	inline ivec4 zzyx() const;
	inline ivec4 zzyy() const;
	inline ivec4 zzyz() const;
	inline ivec3 zzz() const;
	inline ivec4 zzzx() const;
	inline ivec4 zzzy() const;
	inline ivec4 zzzz() const;
	inline void bg(const simdint&, const simdint&);
	inline void bg(const ivec2&);
	inline void bg(const simdint&);
	inline void bgr(const simdint&, const simdint&, const simdint&);
	inline void bgr(const ivec3&);
	inline void bgr(const simdint&);
	inline void br(const simdint&, const simdint&);
	inline void br(const ivec2&);
	inline void br(const simdint&);
	inline void brg(const simdint&, const simdint&, const simdint&);
	inline void brg(const ivec3&);
	inline void brg(const simdint&);
	inline void gb(const simdint&, const simdint&);
	inline void gb(const ivec2&);
	inline void gb(const simdint&);
	inline void gbr(const simdint&, const simdint&, const simdint&);
	inline void gbr(const ivec3&);
	inline void gbr(const simdint&);
	inline void gr(const simdint&, const simdint&);
	inline void gr(const ivec2&);
	inline void gr(const simdint&);
	inline void grb(const simdint&, const simdint&, const simdint&);
	inline void grb(const ivec3&);
	inline void grb(const simdint&);
	inline void rb(const simdint&, const simdint&);
	inline void rb(const ivec2&);
	inline void rb(const simdint&);
	inline void rbg(const simdint&, const simdint&, const simdint&);
	inline void rbg(const ivec3&);
	inline void rbg(const simdint&);
	inline void rg(const simdint&, const simdint&);
	inline void rg(const ivec2&);
	inline void rg(const simdint&);
	inline void rgb(const simdint&, const simdint&, const simdint&);
	inline void rgb(const ivec3&);
	inline void rgb(const simdint&);
	inline void st(const simdint&, const simdint&);
	inline void st(const ivec2&);
	inline void st(const simdint&);
	inline void stp(const simdint&, const simdint&, const simdint&);
	inline void stp(const ivec3&);
	inline void stp(const simdint&);
	inline void sp(const simdint&, const simdint&);
	inline void sp(const ivec2&);
	inline void sp(const simdint&);
	inline void spt(const simdint&, const simdint&, const simdint&);
	inline void spt(const ivec3&);
	inline void spt(const simdint&);
	inline void ts(const simdint&, const simdint&);
	inline void ts(const ivec2&);
	inline void ts(const simdint&);
	inline void tsp(const simdint&, const simdint&, const simdint&);
	inline void tsp(const ivec3&);
	inline void tsp(const simdint&);
	inline void tp(const simdint&, const simdint&);
	inline void tp(const ivec2&);
	inline void tp(const simdint&);
	inline void tps(const simdint&, const simdint&, const simdint&);
	inline void tps(const ivec3&);
	inline void tps(const simdint&);
	inline void ps(const simdint&, const simdint&);
	inline void ps(const ivec2&);
	inline void ps(const simdint&);
	inline void pst(const simdint&, const simdint&, const simdint&);
	inline void pst(const ivec3&);
	inline void pst(const simdint&);
	inline void pt(const simdint&, const simdint&);
	inline void pt(const ivec2&);
	inline void pt(const simdint&);
	inline void pts(const simdint&, const simdint&, const simdint&);
	inline void pts(const ivec3&);
	inline void pts(const simdint&);
	inline void xy(const simdint&, const simdint&);
	inline void xy(const ivec2&);
	inline void xy(const simdint&);
	inline void xyz(const simdint&, const simdint&, const simdint&);
	inline void xyz(const ivec3&);
	inline void xyz(const simdint&);
	inline void xz(const simdint&, const simdint&);
	inline void xz(const ivec2&);
	inline void xz(const simdint&);
	inline void xzy(const simdint&, const simdint&, const simdint&);
	inline void xzy(const ivec3&);
	inline void xzy(const simdint&);
	inline void yx(const simdint&, const simdint&);
	inline void yx(const ivec2&);
	inline void yx(const simdint&);
	inline void yxz(const simdint&, const simdint&, const simdint&);
	inline void yxz(const ivec3&);
	inline void yxz(const simdint&);
	inline void yz(const simdint&, const simdint&);
	inline void yz(const ivec2&);
	inline void yz(const simdint&);
	inline void yzx(const simdint&, const simdint&, const simdint&);
	inline void yzx(const ivec3&);
	inline void yzx(const simdint&);
	inline void zx(const simdint&, const simdint&);
	inline void zx(const ivec2&);
	inline void zx(const simdint&);
	inline void zxy(const simdint&, const simdint&, const simdint&);
	inline void zxy(const ivec3&);
	inline void zxy(const simdint&);
	inline void zy(const simdint&, const simdint&);
	inline void zy(const ivec2&);
	inline void zy(const simdint&);
	inline void zyx(const simdint&, const simdint&, const simdint&);
	inline void zyx(const ivec3&);
	inline void zyx(const simdint&);

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
		case 2:
			return z;
		default:
			throw std::out_of_range("_index out of range");
		}
	}

	inline ivec3 operator=(const vec3& _v);
	inline ivec3 operator=(const ivec4& _v);
	inline ivec3 operator=(const int32_t& _i)
	{
		x = _i;
		y = _i;
		z = _i;
		return *this;
	}

	inline ivec3 operator=(const ivec3& _f)
	{
		x = _f.x;
		y = _f.y;
		z = _f.z;
		return *this;
	}

	inline ivec3 operator=(const simdint_internal& _v)
	{
		x = _v;
		y = _v;
		z = _v;
        return *this;
	}
};

#endif


