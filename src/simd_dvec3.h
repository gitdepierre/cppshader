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
 
#ifndef SIMD_DVEC3_H
#define SIMD_DVEC3_H

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

struct dvec3
{
	simddouble x, y, z;
	simddouble& r = x;
	simddouble& g = y;
	simddouble& b = z;
	simddouble& s = x;
	simddouble& t = y;
	simddouble& p = z;

	dvec3() { x = (0.0); y = (0.0); z = (0.0); }
	dvec3(const dvec3& other) = default;

	dvec3(const double& _f);

	dvec3(const simddouble& _f);

	dvec3(const simddouble& _x, const simddouble& _y, const simddouble& _z);

	dvec3(const simddouble& _x, const dvec2& _y);

	dvec3(const dvec2& _x, const simddouble& _z);

	template<typename V, std::enable_if_t<std::is_same_v<V, dvec3>, int> = 0>
	dvec3(const simddouble& _x, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, dvec4>, int> = 0>
	dvec3(const simddouble& _x, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, dvec2>, int> = 0>
	dvec3(const simddouble& _x, const simddouble& _y, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, dvec3>, int> = 0>
	dvec3(const simddouble& _x, const simddouble& _y, const V& _v);

	template<typename V, std::enable_if_t<std::is_same_v<V, dvec4>, int> = 0>
	dvec3(const simddouble& _x, const simddouble& _y, const V& _v);

	inline dvec2 bb() const;
	inline dvec3 bbb() const;
	inline dvec4 bbbb() const;
	inline dvec4 bbbg() const;
	inline dvec4 bbbr() const;
	inline dvec3 bbg() const;
	inline dvec4 bbgb() const;
	inline dvec4 bbgg() const;
	inline dvec4 bbgr() const;
	inline dvec3 bbr() const;
	inline dvec4 bbrb() const;
	inline dvec4 bbrg() const;
	inline dvec4 bbrr() const;
	inline dvec2 bg() const;
	inline dvec3 bgb() const;
	inline dvec4 bgbb() const;
	inline dvec4 bgbg() const;
	inline dvec4 bgbr() const;
	inline dvec3 bgg() const;
	inline dvec4 bggb() const;
	inline dvec4 bggg() const;
	inline dvec4 bggr() const;
	inline dvec3 bgr() const;
	inline dvec4 bgrb() const;
	inline dvec4 bgrg() const;
	inline dvec4 bgrr() const;
	inline dvec2 br() const;
	inline dvec3 brb() const;
	inline dvec4 brbb() const;
	inline dvec4 brbg() const;
	inline dvec4 brbr() const;
	inline dvec3 brg() const;
	inline dvec4 brgb() const;
	inline dvec4 brgg() const;
	inline dvec4 brgr() const;
	inline dvec3 brr() const;
	inline dvec4 brrb() const;
	inline dvec4 brrg() const;
	inline dvec4 brrr() const;
	inline dvec2 gb() const;
	inline dvec3 gbb() const;
	inline dvec4 gbbb() const;
	inline dvec4 gbbg() const;
	inline dvec4 gbbr() const;
	inline dvec3 gbg() const;
	inline dvec4 gbgb() const;
	inline dvec4 gbgg() const;
	inline dvec4 gbgr() const;
	inline dvec3 gbr() const;
	inline dvec4 gbrb() const;
	inline dvec4 gbrg() const;
	inline dvec4 gbrr() const;
	inline dvec2 gg() const;
	inline dvec3 ggb() const;
	inline dvec4 ggbb() const;
	inline dvec4 ggbg() const;
	inline dvec4 ggbr() const;
	inline dvec3 ggg() const;
	inline dvec4 gggb() const;
	inline dvec4 gggg() const;
	inline dvec4 gggr() const;
	inline dvec3 ggr() const;
	inline dvec4 ggrb() const;
	inline dvec4 ggrg() const;
	inline dvec4 ggrr() const;
	inline dvec2 gr() const;
	inline dvec3 grb() const;
	inline dvec4 grbb() const;
	inline dvec4 grbg() const;
	inline dvec4 grbr() const;
	inline dvec3 grg() const;
	inline dvec4 grgb() const;
	inline dvec4 grgg() const;
	inline dvec4 grgr() const;
	inline dvec3 grr() const;
	inline dvec4 grrb() const;
	inline dvec4 grrg() const;
	inline dvec4 grrr() const;
	inline dvec2 rb() const;
	inline dvec3 rbb() const;
	inline dvec4 rbbb() const;
	inline dvec4 rbbg() const;
	inline dvec4 rbbr() const;
	inline dvec3 rbg() const;
	inline dvec4 rbgb() const;
	inline dvec4 rbgg() const;
	inline dvec4 rbgr() const;
	inline dvec3 rbr() const;
	inline dvec4 rbrb() const;
	inline dvec4 rbrg() const;
	inline dvec4 rbrr() const;
	inline dvec2 rg() const;
	inline dvec3 rgb() const;
	inline dvec4 rgbb() const;
	inline dvec4 rgbg() const;
	inline dvec4 rgbr() const;
	inline dvec3 rgg() const;
	inline dvec4 rggb() const;
	inline dvec4 rggg() const;
	inline dvec4 rggr() const;
	inline dvec3 rgr() const;
	inline dvec4 rgrb() const;
	inline dvec4 rgrg() const;
	inline dvec4 rgrr() const;
	inline dvec2 rr() const;
	inline dvec3 rrb() const;
	inline dvec4 rrbb() const;
	inline dvec4 rrbg() const;
	inline dvec4 rrbr() const;
	inline dvec3 rrg() const;
	inline dvec4 rrgb() const;
	inline dvec4 rrgg() const;
	inline dvec4 rrgr() const;
	inline dvec3 rrr() const;
	inline dvec4 rrrb() const;
	inline dvec4 rrrg() const;
	inline dvec4 rrrr() const;

	inline dvec2 ss() const;
	inline dvec3 sss() const;
	inline dvec4 ssss() const;
	inline dvec4 ssst() const;
	inline dvec4 sssp() const;
	inline dvec3 sst() const;
	inline dvec4 ssts() const;
	inline dvec4 sstt() const;
	inline dvec4 sstp() const;
	inline dvec3 ssp() const;
	inline dvec4 ssps() const;
	inline dvec4 sspt() const;
	inline dvec4 sspp() const;
	inline dvec2 st() const;
	inline dvec3 sts() const;
	inline dvec4 stss() const;
	inline dvec4 stst() const;
	inline dvec4 stsp() const;
	inline dvec3 stt() const;
	inline dvec4 stts() const;
	inline dvec4 sttt() const;
	inline dvec4 sttp() const;
	inline dvec3 stp() const;
	inline dvec4 stps() const;
	inline dvec4 stpt() const;
	inline dvec4 stpp() const;
	inline dvec2 sp() const;
	inline dvec3 sps() const;
	inline dvec4 spss() const;
	inline dvec4 spst() const;
	inline dvec4 spsp() const;
	inline dvec3 spt() const;
	inline dvec4 spts() const;
	inline dvec4 sptt() const;
	inline dvec4 sptp() const;
	inline dvec3 spp() const;
	inline dvec4 spps() const;
	inline dvec4 sppt() const;
	inline dvec4 sppp() const;
	inline dvec2 ts() const;
	inline dvec3 tss() const;
	inline dvec4 tsss() const;
	inline dvec4 tsst() const;
	inline dvec4 tssp() const;
	inline dvec3 tst() const;
	inline dvec4 tsts() const;
	inline dvec4 tstt() const;
	inline dvec4 tstp() const;
	inline dvec3 tsp() const;
	inline dvec4 tsps() const;
	inline dvec4 tspt() const;
	inline dvec4 tspp() const;
	inline dvec2 tt() const;
	inline dvec3 tts() const;
	inline dvec4 ttss() const;
	inline dvec4 ttst() const;
	inline dvec4 ttsp() const;
	inline dvec3 ttt() const;
	inline dvec4 ttts() const;
	inline dvec4 tttt() const;
	inline dvec4 tttp() const;
	inline dvec3 ttp() const;
	inline dvec4 ttps() const;
	inline dvec4 ttpt() const;
	inline dvec4 ttpp() const;
	inline dvec2 tp() const;
	inline dvec3 tps() const;
	inline dvec4 tpss() const;
	inline dvec4 tpst() const;
	inline dvec4 tpsp() const;
	inline dvec3 tpt() const;
	inline dvec4 tpts() const;
	inline dvec4 tptt() const;
	inline dvec4 tptp() const;
	inline dvec3 tpp() const;
	inline dvec4 tpps() const;
	inline dvec4 tppt() const;
	inline dvec4 tppp() const;
	inline dvec2 ps() const;
	inline dvec3 pss() const;
	inline dvec4 psss() const;
	inline dvec4 psst() const;
	inline dvec4 pssp() const;
	inline dvec3 pst() const;
	inline dvec4 psts() const;
	inline dvec4 pstt() const;
	inline dvec4 pstp() const;
	inline dvec3 psp() const;
	inline dvec4 psps() const;
	inline dvec4 pspt() const;
	inline dvec4 pspp() const;
	inline dvec2 pt() const;
	inline dvec3 pts() const;
	inline dvec4 ptss() const;
	inline dvec4 ptst() const;
	inline dvec4 ptsp() const;
	inline dvec3 ptt() const;
	inline dvec4 ptts() const;
	inline dvec4 pttt() const;
	inline dvec4 pttp() const;
	inline dvec3 ptp() const;
	inline dvec4 ptps() const;
	inline dvec4 ptpt() const;
	inline dvec4 ptpp() const;
	inline dvec2 pp() const;
	inline dvec3 pps() const;
	inline dvec4 ppss() const;
	inline dvec4 ppst() const;
	inline dvec4 ppsp() const;
	inline dvec3 ppt() const;
	inline dvec4 ppts() const;
	inline dvec4 pptt() const;
	inline dvec4 pptp() const;
	inline dvec3 ppp() const;
	inline dvec4 ppps() const;
	inline dvec4 pppt() const;
	inline dvec4 pppp() const;
	inline dvec2 xx() const;
	inline dvec3 xxx() const;
	inline dvec4 xxxx() const;
	inline dvec4 xxxy() const;
	inline dvec4 xxxz() const;
	inline dvec3 xxy() const;
	inline dvec4 xxyx() const;
	inline dvec4 xxyy() const;
	inline dvec4 xxyz() const;
	inline dvec3 xxz() const;
	inline dvec4 xxzx() const;
	inline dvec4 xxzy() const;
	inline dvec4 xxzz() const;
	inline dvec2 xy() const;
	inline dvec3 xyx() const;
	inline dvec4 xyxx() const;
	inline dvec4 xyxy() const;
	inline dvec4 xyxz() const;
	inline dvec3 xyy() const;
	inline dvec4 xyyx() const;
	inline dvec4 xyyy() const;
	inline dvec4 xyyz() const;
	inline dvec3 xyz() const;
	inline dvec4 xyzx() const;
	inline dvec4 xyzy() const;
	inline dvec4 xyzz() const;
	inline dvec2 xz() const;
	inline dvec3 xzx() const;
	inline dvec4 xzxx() const;
	inline dvec4 xzxy() const;
	inline dvec4 xzxz() const;
	inline dvec3 xzy() const;
	inline dvec4 xzyx() const;
	inline dvec4 xzyy() const;
	inline dvec4 xzyz() const;
	inline dvec3 xzz() const;
	inline dvec4 xzzx() const;
	inline dvec4 xzzy() const;
	inline dvec4 xzzz() const;
	inline dvec2 yx() const;
	inline dvec3 yxx() const;
	inline dvec4 yxxx() const;
	inline dvec4 yxxy() const;
	inline dvec4 yxxz() const;
	inline dvec3 yxy() const;
	inline dvec4 yxyx() const;
	inline dvec4 yxyy() const;
	inline dvec4 yxyz() const;
	inline dvec3 yxz() const;
	inline dvec4 yxzx() const;
	inline dvec4 yxzy() const;
	inline dvec4 yxzz() const;
	inline dvec2 yy() const;
	inline dvec3 yyx() const;
	inline dvec4 yyxx() const;
	inline dvec4 yyxy() const;
	inline dvec4 yyxz() const;
	inline dvec3 yyy() const;
	inline dvec4 yyyx() const;
	inline dvec4 yyyy() const;
	inline dvec4 yyyz() const;
	inline dvec3 yyz() const;
	inline dvec4 yyzx() const;
	inline dvec4 yyzy() const;
	inline dvec4 yyzz() const;
	inline dvec2 yz() const;
	inline dvec3 yzx() const;
	inline dvec4 yzxx() const;
	inline dvec4 yzxy() const;
	inline dvec4 yzxz() const;
	inline dvec3 yzy() const;
	inline dvec4 yzyx() const;
	inline dvec4 yzyy() const;
	inline dvec4 yzyz() const;
	inline dvec3 yzz() const;
	inline dvec4 yzzx() const;
	inline dvec4 yzzy() const;
	inline dvec4 yzzz() const;
	inline dvec2 zx() const;
	inline dvec3 zxx() const;
	inline dvec4 zxxx() const;
	inline dvec4 zxxy() const;
	inline dvec4 zxxz() const;
	inline dvec3 zxy() const;
	inline dvec4 zxyx() const;
	inline dvec4 zxyy() const;
	inline dvec4 zxyz() const;
	inline dvec3 zxz() const;
	inline dvec4 zxzx() const;
	inline dvec4 zxzy() const;
	inline dvec4 zxzz() const;
	inline dvec2 zy() const;
	inline dvec3 zyx() const;
	inline dvec4 zyxx() const;
	inline dvec4 zyxy() const;
	inline dvec4 zyxz() const;
	inline dvec3 zyy() const;
	inline dvec4 zyyx() const;
	inline dvec4 zyyy() const;
	inline dvec4 zyyz() const;
	inline dvec3 zyz() const;
	inline dvec4 zyzx() const;
	inline dvec4 zyzy() const;
	inline dvec4 zyzz() const;
	inline dvec2 zz() const;
	inline dvec3 zzx() const;
	inline dvec4 zzxx() const;
	inline dvec4 zzxy() const;
	inline dvec4 zzxz() const;
	inline dvec3 zzy() const;
	inline dvec4 zzyx() const;
	inline dvec4 zzyy() const;
	inline dvec4 zzyz() const;
	inline dvec3 zzz() const;
	inline dvec4 zzzx() const;
	inline dvec4 zzzy() const;
	inline dvec4 zzzz() const;
	inline void bg(const simddouble&, const simddouble&);
	inline void bg(const dvec2&);
	inline void bg(const simddouble&);
	inline void bgr(const simddouble&, const simddouble&, const simddouble&);
	inline void bgr(const dvec3&);
	inline void bgr(const simddouble&);
	inline void br(const simddouble&, const simddouble&);
	inline void br(const dvec2&);
	inline void br(const simddouble&);
	inline void brg(const simddouble&, const simddouble&, const simddouble&);
	inline void brg(const dvec3&);
	inline void brg(const simddouble&);
	inline void gb(const simddouble&, const simddouble&);
	inline void gb(const dvec2&);
	inline void gb(const simddouble&);
	inline void gbr(const simddouble&, const simddouble&, const simddouble&);
	inline void gbr(const dvec3&);
	inline void gbr(const simddouble&);
	inline void gr(const simddouble&, const simddouble&);
	inline void gr(const dvec2&);
	inline void gr(const simddouble&);
	inline void grb(const simddouble&, const simddouble&, const simddouble&);
	inline void grb(const dvec3&);
	inline void grb(const simddouble&);
	inline void rb(const simddouble&, const simddouble&);
	inline void rb(const dvec2&);
	inline void rb(const simddouble&);
	inline void rbg(const simddouble&, const simddouble&, const simddouble&);
	inline void rbg(const dvec3&);
	inline void rbg(const simddouble&);
	inline void rg(const simddouble&, const simddouble&);
	inline void rg(const dvec2&);
	inline void rg(const simddouble&);
	inline void rgb(const simddouble&, const simddouble&, const simddouble&);
	inline void rgb(const dvec3&);
	inline void rgb(const simddouble&);
	inline void st(const simddouble&, const simddouble&);
	inline void st(const dvec2&);
	inline void st(const simddouble&);
	inline void stp(const simddouble&, const simddouble&, const simddouble&);
	inline void stp(const dvec3&);
	inline void stp(const simddouble&);
	inline void sp(const simddouble&, const simddouble&);
	inline void sp(const dvec2&);
	inline void sp(const simddouble&);
	inline void spt(const simddouble&, const simddouble&, const simddouble&);
	inline void spt(const dvec3&);
	inline void spt(const simddouble&);
	inline void ts(const simddouble&, const simddouble&);
	inline void ts(const dvec2&);
	inline void ts(const simddouble&);
	inline void tsp(const simddouble&, const simddouble&, const simddouble&);
	inline void tsp(const dvec3&);
	inline void tsp(const simddouble&);
	inline void tp(const simddouble&, const simddouble&);
	inline void tp(const dvec2&);
	inline void tp(const simddouble&);
	inline void tps(const simddouble&, const simddouble&, const simddouble&);
	inline void tps(const dvec3&);
	inline void tps(const simddouble&);
	inline void ps(const simddouble&, const simddouble&);
	inline void ps(const dvec2&);
	inline void ps(const simddouble&);
	inline void pst(const simddouble&, const simddouble&, const simddouble&);
	inline void pst(const dvec3&);
	inline void pst(const simddouble&);
	inline void pt(const simddouble&, const simddouble&);
	inline void pt(const dvec2&);
	inline void pt(const simddouble&);
	inline void pts(const simddouble&, const simddouble&, const simddouble&);
	inline void pts(const dvec3&);
	inline void pts(const simddouble&);
	inline void xy(const simddouble&, const simddouble&);
	inline void xy(const dvec2&);
	inline void xy(const simddouble&);
	inline void xyz(const simddouble&, const simddouble&, const simddouble&);
	inline void xyz(const dvec3&);
	inline void xyz(const simddouble&);
	inline void xz(const simddouble&, const simddouble&);
	inline void xz(const dvec2&);
	inline void xz(const simddouble&);
	inline void xzy(const simddouble&, const simddouble&, const simddouble&);
	inline void xzy(const dvec3&);
	inline void xzy(const simddouble&);
	inline void yx(const simddouble&, const simddouble&);
	inline void yx(const dvec2&);
	inline void yx(const simddouble&);
	inline void yxz(const simddouble&, const simddouble&, const simddouble&);
	inline void yxz(const dvec3&);
	inline void yxz(const simddouble&);
	inline void yz(const simddouble&, const simddouble&);
	inline void yz(const dvec2&);
	inline void yz(const simddouble&);
	inline void yzx(const simddouble&, const simddouble&, const simddouble&);
	inline void yzx(const dvec3&);
	inline void yzx(const simddouble&);
	inline void zx(const simddouble&, const simddouble&);
	inline void zx(const dvec2&);
	inline void zx(const simddouble&);
	inline void zxy(const simddouble&, const simddouble&, const simddouble&);
	inline void zxy(const dvec3&);
	inline void zxy(const simddouble&);
	inline void zy(const simddouble&, const simddouble&);
	inline void zy(const dvec2&);
	inline void zy(const simddouble&);
	inline void zyx(const simddouble&, const simddouble&, const simddouble&);
	inline void zyx(const dvec3&);
	inline void zyx(const simddouble&);

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
		case 2:
			return z;
		default:
			throw std::out_of_range("_index out of range");
		}
	}

	inline dvec3 operator=(const dvec4& _v);

	inline dvec3 operator=(const dvec3& _f)
	{
		x = _f.x;
		y = _f.y;
		z = _f.z;
		return *this;
	}

    inline dvec3 operator=(const double& _d)
	{
		x = _d;
		y = _d;
		z = _d;
		return *this;
	}

	inline dvec3 operator=(const simddouble_internal& _v)
	{
		x = _v;
		y = _v;
		z = _v;
        return *this;
	}
};

#endif


