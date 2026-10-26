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
 
#ifndef SIMD_SWIZZLE_IVEC3_H
#define SIMD_SWIZZLE_IVEC3_H

#include "simd_ivec2.h"
#include "simd_ivec3.h"
#include "simd_ivec4.h"
#include "simd_vec3.h"

#pragma region ivec3 swizzle implementations

// ivec3 swizzle implementations
inline ivec2 ivec3::bb() const { return { b, b }; }
inline ivec3 ivec3::bbb() const { return { b, b, b }; }
inline ivec4 ivec3::bbbb() const { return { b, b, b, b }; }
inline ivec4 ivec3::bbbg() const { return { b, b, b, g }; }
inline ivec4 ivec3::bbbr() const { return { b, b, b, r }; }
inline ivec3 ivec3::bbg() const { return { b, b, g }; }
inline ivec4 ivec3::bbgb() const { return { b, b, g, b }; }
inline ivec4 ivec3::bbgg() const { return { b, b, g, g }; }
inline ivec4 ivec3::bbgr() const { return { b, b, g, r }; }
inline ivec3 ivec3::bbr() const { return { b, b, r }; }
inline ivec4 ivec3::bbrb() const { return { b, b, r, b }; }
inline ivec4 ivec3::bbrg() const { return { b, b, r, g }; }
inline ivec4 ivec3::bbrr() const { return { b, b, r, r }; }
inline ivec2 ivec3::bg() const { return { b, g }; }
inline ivec3 ivec3::bgb() const { return { b, g, b }; }
inline ivec4 ivec3::bgbb() const { return { b, g, b, b }; }
inline ivec4 ivec3::bgbg() const { return { b, g, b, g }; }
inline ivec4 ivec3::bgbr() const { return { b, g, b, r }; }
inline ivec3 ivec3::bgg() const { return { b, g, g }; }
inline ivec4 ivec3::bggb() const { return { b, g, g, b }; }
inline ivec4 ivec3::bggg() const { return { b, g, g, g }; }
inline ivec4 ivec3::bggr() const { return { b, g, g, r }; }
inline ivec3 ivec3::bgr() const { return { b, g, r }; }
inline ivec4 ivec3::bgrb() const { return { b, g, r, b }; }
inline ivec4 ivec3::bgrg() const { return { b, g, r, g }; }
inline ivec4 ivec3::bgrr() const { return { b, g, r, r }; }
inline ivec2 ivec3::br() const { return { b, r }; }
inline ivec3 ivec3::brb() const { return { b, r, b }; }
inline ivec4 ivec3::brbb() const { return { b, r, b, b }; }
inline ivec4 ivec3::brbg() const { return { b, r, b, g }; }
inline ivec4 ivec3::brbr() const { return { b, r, b, r }; }
inline ivec3 ivec3::brg() const { return { b, r, g }; }
inline ivec4 ivec3::brgb() const { return { b, r, g, b }; }
inline ivec4 ivec3::brgg() const { return { b, r, g, g }; }
inline ivec4 ivec3::brgr() const { return { b, r, g, r }; }
inline ivec3 ivec3::brr() const { return { b, r, r }; }
inline ivec4 ivec3::brrb() const { return { b, r, r, b }; }
inline ivec4 ivec3::brrg() const { return { b, r, r, g }; }
inline ivec4 ivec3::brrr() const { return { b, r, r, r }; }
inline ivec2 ivec3::gb() const { return { g, b }; }
inline ivec3 ivec3::gbb() const { return { g, b, b }; }
inline ivec4 ivec3::gbbb() const { return { g, b, b, b }; }
inline ivec4 ivec3::gbbg() const { return { g, b, b, g }; }
inline ivec4 ivec3::gbbr() const { return { g, b, b, r }; }
inline ivec3 ivec3::gbg() const { return { g, b, g }; }
inline ivec4 ivec3::gbgb() const { return { g, b, g, b }; }
inline ivec4 ivec3::gbgg() const { return { g, b, g, g }; }
inline ivec4 ivec3::gbgr() const { return { g, b, g, r }; }
inline ivec3 ivec3::gbr() const { return { g, b, r }; }
inline ivec4 ivec3::gbrb() const { return { g, b, r, b }; }
inline ivec4 ivec3::gbrg() const { return { g, b, r, g }; }
inline ivec4 ivec3::gbrr() const { return { g, b, r, r }; }
inline ivec2 ivec3::gg() const { return { g, g }; }
inline ivec3 ivec3::ggb() const { return { g, g, b }; }
inline ivec4 ivec3::ggbb() const { return { g, g, b, b }; }
inline ivec4 ivec3::ggbg() const { return { g, g, b, g }; }
inline ivec4 ivec3::ggbr() const { return { g, g, b, r }; }
inline ivec3 ivec3::ggg() const { return { g, g, g }; }
inline ivec4 ivec3::gggb() const { return { g, g, g, b }; }
inline ivec4 ivec3::gggg() const { return { g, g, g, g }; }
inline ivec4 ivec3::gggr() const { return { g, g, g, r }; }
inline ivec3 ivec3::ggr() const { return { g, g, r }; }
inline ivec4 ivec3::ggrb() const { return { g, g, r, b }; }
inline ivec4 ivec3::ggrg() const { return { g, g, r, g }; }
inline ivec4 ivec3::ggrr() const { return { g, g, r, r }; }
inline ivec2 ivec3::gr() const { return { g, r }; }
inline ivec3 ivec3::grb() const { return { g, r, b }; }
inline ivec4 ivec3::grbb() const { return { g, r, b, b }; }
inline ivec4 ivec3::grbg() const { return { g, r, b, g }; }
inline ivec4 ivec3::grbr() const { return { g, r, b, r }; }
inline ivec3 ivec3::grg() const { return { g, r, g }; }
inline ivec4 ivec3::grgb() const { return { g, r, g, b }; }
inline ivec4 ivec3::grgg() const { return { g, r, g, g }; }
inline ivec4 ivec3::grgr() const { return { g, r, g, r }; }
inline ivec3 ivec3::grr() const { return { g, r, r }; }
inline ivec4 ivec3::grrb() const { return { g, r, r, b }; }
inline ivec4 ivec3::grrg() const { return { g, r, r, g }; }
inline ivec4 ivec3::grrr() const { return { g, r, r, r }; }
inline ivec2 ivec3::rb() const { return { r, b }; }
inline ivec3 ivec3::rbb() const { return { r, b, b }; }
inline ivec4 ivec3::rbbb() const { return { r, b, b, b }; }
inline ivec4 ivec3::rbbg() const { return { r, b, b, g }; }
inline ivec4 ivec3::rbbr() const { return { r, b, b, r }; }
inline ivec3 ivec3::rbg() const { return { r, b, g }; }
inline ivec4 ivec3::rbgb() const { return { r, b, g, b }; }
inline ivec4 ivec3::rbgg() const { return { r, b, g, g }; }
inline ivec4 ivec3::rbgr() const { return { r, b, g, r }; }
inline ivec3 ivec3::rbr() const { return { r, b, r }; }
inline ivec4 ivec3::rbrb() const { return { r, b, r, b }; }
inline ivec4 ivec3::rbrg() const { return { r, b, r, g }; }
inline ivec4 ivec3::rbrr() const { return { r, b, r, r }; }
inline ivec2 ivec3::rg() const { return { r, g }; }
inline ivec3 ivec3::rgb() const { return { r, g, b }; }
inline ivec4 ivec3::rgbb() const { return { r, g, b, b }; }
inline ivec4 ivec3::rgbg() const { return { r, g, b, g }; }
inline ivec4 ivec3::rgbr() const { return { r, g, b, r }; }
inline ivec3 ivec3::rgg() const { return { r, g, g }; }
inline ivec4 ivec3::rggb() const { return { r, g, g, b }; }
inline ivec4 ivec3::rggg() const { return { r, g, g, g }; }
inline ivec4 ivec3::rggr() const { return { r, g, g, r }; }
inline ivec3 ivec3::rgr() const { return { r, g, r }; }
inline ivec4 ivec3::rgrb() const { return { r, g, r, b }; }
inline ivec4 ivec3::rgrg() const { return { r, g, r, g }; }
inline ivec4 ivec3::rgrr() const { return { r, g, r, r }; }
inline ivec2 ivec3::rr() const { return { r, r }; }
inline ivec3 ivec3::rrb() const { return { r, r, b }; }
inline ivec4 ivec3::rrbb() const { return { r, r, b, b }; }
inline ivec4 ivec3::rrbg() const { return { r, r, b, g }; }
inline ivec4 ivec3::rrbr() const { return { r, r, b, r }; }
inline ivec3 ivec3::rrg() const { return { r, r, g }; }
inline ivec4 ivec3::rrgb() const { return { r, r, g, b }; }
inline ivec4 ivec3::rrgg() const { return { r, r, g, g }; }
inline ivec4 ivec3::rrgr() const { return { r, r, g, r }; }
inline ivec3 ivec3::rrr() const { return { r, r, r }; }
inline ivec4 ivec3::rrrb() const { return { r, r, r, b }; }
inline ivec4 ivec3::rrrg() const { return { r, r, r, g }; }
inline ivec4 ivec3::rrrr() const { return { r, r, r, r }; }
inline ivec2 ivec3::ss() const { return { s, s }; }
inline ivec3 ivec3::sss() const { return { s, s, s }; }
inline ivec4 ivec3::ssss() const { return { s, s, s, s }; }
inline ivec4 ivec3::ssst() const { return { s, s, s, t }; }
inline ivec4 ivec3::sssp() const { return { s, s, s, p }; }
inline ivec3 ivec3::sst() const { return { s, s, t }; }
inline ivec4 ivec3::ssts() const { return { s, s, t, s }; }
inline ivec4 ivec3::sstt() const { return { s, s, t, t }; }
inline ivec4 ivec3::sstp() const { return { s, s, t, p }; }
inline ivec3 ivec3::ssp() const { return { s, s, p }; }
inline ivec4 ivec3::ssps() const { return { s, s, p, s }; }
inline ivec4 ivec3::sspt() const { return { s, s, p, t }; }
inline ivec4 ivec3::sspp() const { return { s, s, p, p }; }
inline ivec2 ivec3::st() const { return { s, t }; }
inline ivec3 ivec3::sts() const { return { s, t, s }; }
inline ivec4 ivec3::stss() const { return { s, t, s, s }; }
inline ivec4 ivec3::stst() const { return { s, t, s, t }; }
inline ivec4 ivec3::stsp() const { return { s, t, s, p }; }
inline ivec3 ivec3::stt() const { return { s, t, t }; }
inline ivec4 ivec3::stts() const { return { s, t, t, s }; }
inline ivec4 ivec3::sttt() const { return { s, t, t, t }; }
inline ivec4 ivec3::sttp() const { return { s, t, t, p }; }
inline ivec3 ivec3::stp() const { return { s, t, p }; }
inline ivec4 ivec3::stps() const { return { s, t, p, s }; }
inline ivec4 ivec3::stpt() const { return { s, t, p, t }; }
inline ivec4 ivec3::stpp() const { return { s, t, p, p }; }
inline ivec2 ivec3::sp() const { return { s, p }; }
inline ivec3 ivec3::sps() const { return { s, p, s }; }
inline ivec4 ivec3::spss() const { return { s, p, s, s }; }
inline ivec4 ivec3::spst() const { return { s, p, s, t }; }
inline ivec4 ivec3::spsp() const { return { s, p, s, p }; }
inline ivec3 ivec3::spt() const { return { s, p, t }; }
inline ivec4 ivec3::spts() const { return { s, p, t, s }; }
inline ivec4 ivec3::sptt() const { return { s, p, t, t }; }
inline ivec4 ivec3::sptp() const { return { s, p, t, p }; }
inline ivec3 ivec3::spp() const { return { s, p, p }; }
inline ivec4 ivec3::spps() const { return { s, p, p, s }; }
inline ivec4 ivec3::sppt() const { return { s, p, p, t }; }
inline ivec4 ivec3::sppp() const { return { s, p, p, p }; }
inline ivec2 ivec3::ts() const { return { t, s }; }
inline ivec3 ivec3::tss() const { return { t, s, s }; }
inline ivec4 ivec3::tsss() const { return { t, s, s, s }; }
inline ivec4 ivec3::tsst() const { return { t, s, s, t }; }
inline ivec4 ivec3::tssp() const { return { t, s, s, p }; }
inline ivec3 ivec3::tst() const { return { t, s, t }; }
inline ivec4 ivec3::tsts() const { return { t, s, t, s }; }
inline ivec4 ivec3::tstt() const { return { t, s, t, t }; }
inline ivec4 ivec3::tstp() const { return { t, s, t, p }; }
inline ivec3 ivec3::tsp() const { return { t, s, p }; }
inline ivec4 ivec3::tsps() const { return { t, s, p, s }; }
inline ivec4 ivec3::tspt() const { return { t, s, p, t }; }
inline ivec4 ivec3::tspp() const { return { t, s, p, p }; }
inline ivec2 ivec3::tt() const { return { t, t }; }
inline ivec3 ivec3::tts() const { return { t, t, s }; }
inline ivec4 ivec3::ttss() const { return { t, t, s, s }; }
inline ivec4 ivec3::ttst() const { return { t, t, s, t }; }
inline ivec4 ivec3::ttsp() const { return { t, t, s, p }; }
inline ivec3 ivec3::ttt() const { return { t, t, t }; }
inline ivec4 ivec3::ttts() const { return { t, t, t, s }; }
inline ivec4 ivec3::tttt() const { return { t, t, t, t }; }
inline ivec4 ivec3::tttp() const { return { t, t, t, p }; }
inline ivec3 ivec3::ttp() const { return { t, t, p }; }
inline ivec4 ivec3::ttps() const { return { t, t, p, s }; }
inline ivec4 ivec3::ttpt() const { return { t, t, p, t }; }
inline ivec4 ivec3::ttpp() const { return { t, t, p, p }; }
inline ivec2 ivec3::tp() const { return { t, p }; }
inline ivec3 ivec3::tps() const { return { t, p, s }; }
inline ivec4 ivec3::tpss() const { return { t, p, s, s }; }
inline ivec4 ivec3::tpst() const { return { t, p, s, t }; }
inline ivec4 ivec3::tpsp() const { return { t, p, s, p }; }
inline ivec3 ivec3::tpt() const { return { t, p, t }; }
inline ivec4 ivec3::tpts() const { return { t, p, t, s }; }
inline ivec4 ivec3::tptt() const { return { t, p, t, t }; }
inline ivec4 ivec3::tptp() const { return { t, p, t, p }; }
inline ivec3 ivec3::tpp() const { return { t, p, p }; }
inline ivec4 ivec3::tpps() const { return { t, p, p, s }; }
inline ivec4 ivec3::tppt() const { return { t, p, p, t }; }
inline ivec4 ivec3::tppp() const { return { t, p, p, p }; }
inline ivec2 ivec3::ps() const { return { p, s }; }
inline ivec3 ivec3::pss() const { return { p, s, s }; }
inline ivec4 ivec3::psss() const { return { p, s, s, s }; }
inline ivec4 ivec3::psst() const { return { p, s, s, t }; }
inline ivec4 ivec3::pssp() const { return { p, s, s, p }; }
inline ivec3 ivec3::pst() const { return { p, s, t }; }
inline ivec4 ivec3::psts() const { return { p, s, t, s }; }
inline ivec4 ivec3::pstt() const { return { p, s, t, t }; }
inline ivec4 ivec3::pstp() const { return { p, s, t, p }; }
inline ivec3 ivec3::psp() const { return { p, s, p }; }
inline ivec4 ivec3::psps() const { return { p, s, p, s }; }
inline ivec4 ivec3::pspt() const { return { p, s, p, t }; }
inline ivec4 ivec3::pspp() const { return { p, s, p, p }; }
inline ivec2 ivec3::pt() const { return { p, t }; }
inline ivec3 ivec3::pts() const { return { p, t, s }; }
inline ivec4 ivec3::ptss() const { return { p, t, s, s }; }
inline ivec4 ivec3::ptst() const { return { p, t, s, t }; }
inline ivec4 ivec3::ptsp() const { return { p, t, s, p }; }
inline ivec3 ivec3::ptt() const { return { p, t, t }; }
inline ivec4 ivec3::ptts() const { return { p, t, t, s }; }
inline ivec4 ivec3::pttt() const { return { p, t, t, t }; }
inline ivec4 ivec3::pttp() const { return { p, t, t, p }; }
inline ivec3 ivec3::ptp() const { return { p, t, p }; }
inline ivec4 ivec3::ptps() const { return { p, t, p, s }; }
inline ivec4 ivec3::ptpt() const { return { p, t, p, t }; }
inline ivec4 ivec3::ptpp() const { return { p, t, p, p }; }
inline ivec2 ivec3::pp() const { return { p, p }; }
inline ivec3 ivec3::pps() const { return { p, p, s }; }
inline ivec4 ivec3::ppss() const { return { p, p, s, s }; }
inline ivec4 ivec3::ppst() const { return { p, p, s, t }; }
inline ivec4 ivec3::ppsp() const { return { p, p, s, p }; }
inline ivec3 ivec3::ppt() const { return { p, p, t }; }
inline ivec4 ivec3::ppts() const { return { p, p, t, s }; }
inline ivec4 ivec3::pptt() const { return { p, p, t, t }; }
inline ivec4 ivec3::pptp() const { return { p, p, t, p }; }
inline ivec3 ivec3::ppp() const { return { p, p, p }; }
inline ivec4 ivec3::ppps() const { return { p, p, p, s }; }
inline ivec4 ivec3::pppt() const { return { p, p, p, t }; }
inline ivec4 ivec3::pppp() const { return { p, p, p, p }; }
inline ivec2 ivec3::xx() const { return { x, x }; }
inline ivec3 ivec3::xxx() const { return { x, x, x }; }
inline ivec4 ivec3::xxxx() const { return { x, x, x, x }; }
inline ivec4 ivec3::xxxy() const { return { x, x, x, y }; }
inline ivec4 ivec3::xxxz() const { return { x, x, x, z }; }
inline ivec3 ivec3::xxy() const { return { x, x, y }; }
inline ivec4 ivec3::xxyx() const { return { x, x, y, x }; }
inline ivec4 ivec3::xxyy() const { return { x, x, y, y }; }
inline ivec4 ivec3::xxyz() const { return { x, x, y, z }; }
inline ivec3 ivec3::xxz() const { return { x, x, z }; }
inline ivec4 ivec3::xxzx() const { return { x, x, z, x }; }
inline ivec4 ivec3::xxzy() const { return { x, x, z, y }; }
inline ivec4 ivec3::xxzz() const { return { x, x, z, z }; }
inline ivec2 ivec3::xy() const { return { x, y }; }
inline ivec3 ivec3::xyx() const { return { x, y, x }; }
inline ivec4 ivec3::xyxx() const { return { x, y, x, x }; }
inline ivec4 ivec3::xyxy() const { return { x, y, x, y }; }
inline ivec4 ivec3::xyxz() const { return { x, y, x, z }; }
inline ivec3 ivec3::xyy() const { return { x, y, y }; }
inline ivec4 ivec3::xyyx() const { return { x, y, y, x }; }
inline ivec4 ivec3::xyyy() const { return { x, y, y, y }; }
inline ivec4 ivec3::xyyz() const { return { x, y, y, z }; }
inline ivec3 ivec3::xyz() const { return { x, y, z }; }
inline ivec4 ivec3::xyzx() const { return { x, y, z, x }; }
inline ivec4 ivec3::xyzy() const { return { x, y, z, y }; }
inline ivec4 ivec3::xyzz() const { return { x, y, z, z }; }
inline ivec2 ivec3::xz() const { return { x, z }; }
inline ivec3 ivec3::xzx() const { return { x, z, x }; }
inline ivec4 ivec3::xzxx() const { return { x, z, x, x }; }
inline ivec4 ivec3::xzxy() const { return { x, z, x, y }; }
inline ivec4 ivec3::xzxz() const { return { x, z, x, z }; }
inline ivec3 ivec3::xzy() const { return { x, z, y }; }
inline ivec4 ivec3::xzyx() const { return { x, z, y, x }; }
inline ivec4 ivec3::xzyy() const { return { x, z, y, y }; }
inline ivec4 ivec3::xzyz() const { return { x, z, y, z }; }
inline ivec3 ivec3::xzz() const { return { x, z, z }; }
inline ivec4 ivec3::xzzx() const { return { x, z, z, x }; }
inline ivec4 ivec3::xzzy() const { return { x, z, z, y }; }
inline ivec4 ivec3::xzzz() const { return { x, z, z, z }; }
inline ivec2 ivec3::yx() const { return { y, x }; }
inline ivec3 ivec3::yxx() const { return { y, x, x }; }
inline ivec4 ivec3::yxxx() const { return { y, x, x, x }; }
inline ivec4 ivec3::yxxy() const { return { y, x, x, y }; }
inline ivec4 ivec3::yxxz() const { return { y, x, x, z }; }
inline ivec3 ivec3::yxy() const { return { y, x, y }; }
inline ivec4 ivec3::yxyx() const { return { y, x, y, x }; }
inline ivec4 ivec3::yxyy() const { return { y, x, y, y }; }
inline ivec4 ivec3::yxyz() const { return { y, x, y, z }; }
inline ivec3 ivec3::yxz() const { return { y, x, z }; }
inline ivec4 ivec3::yxzx() const { return { y, x, z, x }; }
inline ivec4 ivec3::yxzy() const { return { y, x, z, y }; }
inline ivec4 ivec3::yxzz() const { return { y, x, z, z }; }
inline ivec2 ivec3::yy() const { return { y, y }; }
inline ivec3 ivec3::yyx() const { return { y, y, x }; }
inline ivec4 ivec3::yyxx() const { return { y, y, x, x }; }
inline ivec4 ivec3::yyxy() const { return { y, y, x, y }; }
inline ivec4 ivec3::yyxz() const { return { y, y, x, z }; }
inline ivec3 ivec3::yyy() const { return { y, y, y }; }
inline ivec4 ivec3::yyyx() const { return { y, y, y, x }; }
inline ivec4 ivec3::yyyy() const { return { y, y, y, y }; }
inline ivec4 ivec3::yyyz() const { return { y, y, y, z }; }
inline ivec3 ivec3::yyz() const { return { y, y, z }; }
inline ivec4 ivec3::yyzx() const { return { y, y, z, x }; }
inline ivec4 ivec3::yyzy() const { return { y, y, z, y }; }
inline ivec4 ivec3::yyzz() const { return { y, y, z, z }; }
inline ivec2 ivec3::yz() const { return { y, z }; }
inline ivec3 ivec3::yzx() const { return { y, z, x }; }
inline ivec4 ivec3::yzxx() const { return { y, z, x, x }; }
inline ivec4 ivec3::yzxy() const { return { y, z, x, y }; }
inline ivec4 ivec3::yzxz() const { return { y, z, x, z }; }
inline ivec3 ivec3::yzy() const { return { y, z, y }; }
inline ivec4 ivec3::yzyx() const { return { y, z, y, x }; }
inline ivec4 ivec3::yzyy() const { return { y, z, y, y }; }
inline ivec4 ivec3::yzyz() const { return { y, z, y, z }; }
inline ivec3 ivec3::yzz() const { return { y, z, z }; }
inline ivec4 ivec3::yzzx() const { return { y, z, z, x }; }
inline ivec4 ivec3::yzzy() const { return { y, z, z, y }; }
inline ivec4 ivec3::yzzz() const { return { y, z, z, z }; }
inline ivec2 ivec3::zx() const { return { z, x }; }
inline ivec3 ivec3::zxx() const { return { z, x, x }; }
inline ivec4 ivec3::zxxx() const { return { z, x, x, x }; }
inline ivec4 ivec3::zxxy() const { return { z, x, x, y }; }
inline ivec4 ivec3::zxxz() const { return { z, x, x, z }; }
inline ivec3 ivec3::zxy() const { return { z, x, y }; }
inline ivec4 ivec3::zxyx() const { return { z, x, y, x }; }
inline ivec4 ivec3::zxyy() const { return { z, x, y, y }; }
inline ivec4 ivec3::zxyz() const { return { z, x, y, z }; }
inline ivec3 ivec3::zxz() const { return { z, x, z }; }
inline ivec4 ivec3::zxzx() const { return { z, x, z, x }; }
inline ivec4 ivec3::zxzy() const { return { z, x, z, y }; }
inline ivec4 ivec3::zxzz() const { return { z, x, z, z }; }
inline ivec2 ivec3::zy() const { return { z, y }; }
inline ivec3 ivec3::zyx() const { return { z, y, x }; }
inline ivec4 ivec3::zyxx() const { return { z, y, x, x }; }
inline ivec4 ivec3::zyxy() const { return { z, y, x, y }; }
inline ivec4 ivec3::zyxz() const { return { z, y, x, z }; }
inline ivec3 ivec3::zyy() const { return { z, y, y }; }
inline ivec4 ivec3::zyyx() const { return { z, y, y, x }; }
inline ivec4 ivec3::zyyy() const { return { z, y, y, y }; }
inline ivec4 ivec3::zyyz() const { return { z, y, y, z }; }
inline ivec3 ivec3::zyz() const { return { z, y, z }; }
inline ivec4 ivec3::zyzx() const { return { z, y, z, x }; }
inline ivec4 ivec3::zyzy() const { return { z, y, z, y }; }
inline ivec4 ivec3::zyzz() const { return { z, y, z, z }; }
inline ivec2 ivec3::zz() const { return { z, z }; }
inline ivec3 ivec3::zzx() const { return { z, z, x }; }
inline ivec4 ivec3::zzxx() const { return { z, z, x, x }; }
inline ivec4 ivec3::zzxy() const { return { z, z, x, y }; }
inline ivec4 ivec3::zzxz() const { return { z, z, x, z }; }
inline ivec3 ivec3::zzy() const { return { z, z, y }; }
inline ivec4 ivec3::zzyx() const { return { z, z, y, x }; }
inline ivec4 ivec3::zzyy() const { return { z, z, y, y }; }
inline ivec4 ivec3::zzyz() const { return { z, z, y, z }; }
inline ivec3 ivec3::zzz() const { return { z, z, z }; }
inline ivec4 ivec3::zzzx() const { return { z, z, z, x }; }
inline ivec4 ivec3::zzzy() const { return { z, z, z, y }; }
inline ivec4 ivec3::zzzz() const { return { z, z, z, z }; }
inline void ivec3::bg(const simdint& _val0, const simdint& _val1) { b = _val0; g = _val1; }
inline void ivec3::bg(const ivec2& _val) { b = _val.x; g = _val.y; }
inline void ivec3::bg(const simdint& _val) { b = _val; g = _val; }
inline void ivec3::bgr(const simdint& _val0, const simdint& _val1, const simdint& _val2) { b = _val0; g = _val1; r = _val2; }
inline void ivec3::bgr(const ivec3& _val) { b = _val.x; g = _val.y; r = _val.z; }
inline void ivec3::bgr(const simdint& _val) { b = _val; g = _val; r = _val; }
inline void ivec3::br(const simdint& _val0, const simdint& _val1) { b = _val0; r = _val1; }
inline void ivec3::br(const ivec2& _val) { b = _val.x; r = _val.y; }
inline void ivec3::br(const simdint& _val) { b = _val; r = _val; }
inline void ivec3::brg(const simdint& _val0, const simdint& _val1, const simdint& _val2) { b = _val0; r = _val1; g = _val2; }
inline void ivec3::brg(const ivec3& _val) { b = _val.x; r = _val.y; g = _val.z; }
inline void ivec3::brg(const simdint& _val) { b = _val; r = _val; g = _val; }
inline void ivec3::gb(const simdint& _val0, const simdint& _val1) { g = _val0; b = _val1; }
inline void ivec3::gb(const ivec2& _val) { g = _val.x; b = _val.y; }
inline void ivec3::gb(const simdint& _val) { g = _val; b = _val; }
inline void ivec3::gbr(const simdint& _val0, const simdint& _val1, const simdint& _val2) { g = _val0; b = _val1; r = _val2; }
inline void ivec3::gbr(const ivec3& _val) { g = _val.x; b = _val.y; r = _val.z; }
inline void ivec3::gbr(const simdint& _val) { g = _val; b = _val; r = _val; }
inline void ivec3::gr(const simdint& _val0, const simdint& _val1) { g = _val0; r = _val1; }
inline void ivec3::gr(const ivec2& _val) { g = _val.x; r = _val.y; }
inline void ivec3::gr(const simdint& _val) { g = _val; r = _val; }
inline void ivec3::grb(const simdint& _val0, const simdint& _val1, const simdint& _val2) { g = _val0; r = _val1; b = _val2; }
inline void ivec3::grb(const ivec3& _val) { g = _val.x; r = _val.y; b = _val.z; }
inline void ivec3::grb(const simdint& _val) { g = _val; r = _val; b = _val; }
inline void ivec3::rb(const simdint& _val0, const simdint& _val1) { r = _val0; b = _val1; }
inline void ivec3::rb(const ivec2& _val) { r = _val.x; b = _val.y; }
inline void ivec3::rb(const simdint& _val) { r = _val; b = _val; }
inline void ivec3::rbg(const simdint& _val0, const simdint& _val1, const simdint& _val2) { r = _val0; b = _val1; g = _val2; }
inline void ivec3::rbg(const ivec3& _val) { r = _val.x; b = _val.y; g = _val.z; }
inline void ivec3::rbg(const simdint& _val) { r = _val; b = _val; g = _val; }
inline void ivec3::rg(const simdint& _val0, const simdint& _val1) { r = _val0; g = _val1; }
inline void ivec3::rg(const ivec2& _val) { r = _val.x; g = _val.y; }
inline void ivec3::rg(const simdint& _val) { r = _val; g = _val; }
inline void ivec3::rgb(const simdint& _val0, const simdint& _val1, const simdint& _val2) { r = _val0; g = _val1; b = _val2; }
inline void ivec3::rgb(const ivec3& _val) { r = _val.x; g = _val.y; b = _val.z; }
inline void ivec3::rgb(const simdint& _val) { r = _val; g = _val; b = _val; }
inline void ivec3::st(const simdint& _val0, const simdint& _val1) { s = _val0; t = _val1; }
inline void ivec3::st(const ivec2& _val) { s = _val.s; t = _val.t; }
inline void ivec3::st(const simdint& _val) { s = _val; t = _val; }
inline void ivec3::stp(const simdint& _val0, const simdint& _val1, const simdint& _val2) { s = _val0; t = _val1; p = _val2; }
inline void ivec3::stp(const ivec3& _val) { s = _val.s; t = _val.t; p = _val.p; }
inline void ivec3::stp(const simdint& _val) { s = _val; t = _val; p = _val; }
inline void ivec3::sp(const simdint& _val0, const simdint& _val1) { s = _val0; p = _val1; }
inline void ivec3::sp(const ivec2& _val) { s = _val.s; p = _val.t; }
inline void ivec3::sp(const simdint& _val) { s = _val; p = _val; }
inline void ivec3::spt(const simdint& _val0, const simdint& _val1, const simdint& _val2) { s = _val0; p = _val1; t = _val2; }
inline void ivec3::spt(const ivec3& _val) { s = _val.s; p = _val.t; t = _val.p; }
inline void ivec3::spt(const simdint& _val) { s = _val; p = _val; t = _val; }
inline void ivec3::ts(const simdint& _val0, const simdint& _val1) { t = _val0; s = _val1; }
inline void ivec3::ts(const ivec2& _val) { t = _val.s; s = _val.t; }
inline void ivec3::ts(const simdint& _val) { t = _val; s = _val; }
inline void ivec3::tsp(const simdint& _val0, const simdint& _val1, const simdint& _val2) { t = _val0; s = _val1; p = _val2; }
inline void ivec3::tsp(const ivec3& _val) { t = _val.s; s = _val.t; p = _val.p; }
inline void ivec3::tsp(const simdint& _val) { t = _val; s = _val; p = _val; }
inline void ivec3::tp(const simdint& _val0, const simdint& _val1) { t = _val0; p = _val1; }
inline void ivec3::tp(const ivec2& _val) { t = _val.s; p = _val.t; }
inline void ivec3::tp(const simdint& _val) { t = _val; p = _val; }
inline void ivec3::tps(const simdint& _val0, const simdint& _val1, const simdint& _val2) { t = _val0; p = _val1; s = _val2; }
inline void ivec3::tps(const ivec3& _val) { t = _val.s; p = _val.t; s = _val.p; }
inline void ivec3::tps(const simdint& _val) { t = _val; p = _val; s = _val; }
inline void ivec3::ps(const simdint& _val0, const simdint& _val1) { p = _val0; s = _val1; }
inline void ivec3::ps(const ivec2& _val) { p = _val.s; s = _val.t; }
inline void ivec3::ps(const simdint& _val) { p = _val; s = _val; }
inline void ivec3::pst(const simdint& _val0, const simdint& _val1, const simdint& _val2) { p = _val0; s = _val1; t = _val2; }
inline void ivec3::pst(const ivec3& _val) { p = _val.s; s = _val.t; t = _val.p; }
inline void ivec3::pst(const simdint& _val) { p = _val; s = _val; t = _val; }
inline void ivec3::pt(const simdint& _val0, const simdint& _val1) { p = _val0; t = _val1; }
inline void ivec3::pt(const ivec2& _val) { p = _val.s; t = _val.t; }
inline void ivec3::pt(const simdint& _val) { p = _val; t = _val; }
inline void ivec3::pts(const simdint& _val0, const simdint& _val1, const simdint& _val2) { p = _val0; t = _val1; s = _val2; }
inline void ivec3::pts(const ivec3& _val) { p = _val.s; t = _val.t; s = _val.p; }
inline void ivec3::pts(const simdint& _val) { p = _val; t = _val; s = _val; }
inline void ivec3::xy(const simdint& _val0, const simdint& _val1) { x = _val0; y = _val1; }
inline void ivec3::xy(const ivec2& _val) { x = _val.x; y = _val.y; }
inline void ivec3::xy(const simdint& _val) { x = _val; y = _val; }
inline void ivec3::xyz(const simdint& _val0, const simdint& _val1, const simdint& _val2) { x = _val0; y = _val1; z = _val2; }
inline void ivec3::xyz(const ivec3& _val) { x = _val.x; y = _val.y; z = _val.z; }
inline void ivec3::xyz(const simdint& _val) { x = _val; y = _val; z = _val; }
inline void ivec3::xz(const simdint& _val0, const simdint& _val1) { x = _val0; z = _val1; }
inline void ivec3::xz(const ivec2& _val) { x = _val.x; z = _val.y; }
inline void ivec3::xz(const simdint& _val) { x = _val; z = _val; }
inline void ivec3::xzy(const simdint& _val0, const simdint& _val1, const simdint& _val2) { x = _val0; z = _val1; y = _val2; }
inline void ivec3::xzy(const ivec3& _val) { x = _val.x; z = _val.y; y = _val.z; }
inline void ivec3::xzy(const simdint& _val) { x = _val; z = _val; y = _val; }
inline void ivec3::yx(const simdint& _val0, const simdint& _val1) { y = _val0; x = _val1; }
inline void ivec3::yx(const ivec2& _val) { y = _val.x; x = _val.y; }
inline void ivec3::yx(const simdint& _val) { y = _val; x = _val; }
inline void ivec3::yxz(const simdint& _val0, const simdint& _val1, const simdint& _val2) { y = _val0; x = _val1; z = _val2; }
inline void ivec3::yxz(const ivec3& _val) { y = _val.x; x = _val.y; z = _val.z; }
inline void ivec3::yxz(const simdint& _val) { y = _val; x = _val; z = _val; }
inline void ivec3::yz(const simdint& _val0, const simdint& _val1) { y = _val0; z = _val1; }
inline void ivec3::yz(const ivec2& _val) { y = _val.x; z = _val.y; }
inline void ivec3::yz(const simdint& _val) { y = _val; z = _val; }
inline void ivec3::yzx(const simdint& _val0, const simdint& _val1, const simdint& _val2) { y = _val0; z = _val1; x = _val2; }
inline void ivec3::yzx(const ivec3& _val) { y = _val.x; z = _val.y; x = _val.z; }
inline void ivec3::yzx(const simdint& _val) { y = _val; z = _val; x = _val; }
inline void ivec3::zx(const simdint& _val0, const simdint& _val1) { z = _val0; x = _val1; }
inline void ivec3::zx(const ivec2& _val) { z = _val.x; x = _val.y; }
inline void ivec3::zx(const simdint& _val) { z = _val; x = _val; }
inline void ivec3::zxy(const simdint& _val0, const simdint& _val1, const simdint& _val2) { z = _val0; x = _val1; y = _val2; }
inline void ivec3::zxy(const ivec3& _val) { z = _val.x; x = _val.y; y = _val.z; }
inline void ivec3::zxy(const simdint& _val) { z = _val; x = _val; y = _val; }
inline void ivec3::zy(const simdint& _val0, const simdint& _val1) { z = _val0; y = _val1; }
inline void ivec3::zy(const ivec2& _val) { z = _val.x; y = _val.y; }
inline void ivec3::zy(const simdint& _val) { z = _val; y = _val; }
inline void ivec3::zyx(const simdint& _val0, const simdint& _val1, const simdint& _val2) { z = _val0; y = _val1; x = _val2; }
inline void ivec3::zyx(const ivec3& _val) { z = _val.x; y = _val.y; x = _val.z; }
inline void ivec3::zyx(const simdint& _val) { z = _val; y = _val; x = _val; }

#pragma endregion

// cross-type assignment from vec3 (components use simdint's own conversion operator)
inline ivec3 ivec3::operator=(const vec3& _v) { x = _v.x; y = _v.y; z = _v.z; return *this; }

inline ivec3 ivec3::operator=(const ivec4& _v) { x = _v.x; y = _v.y; z = _v.z; return *this; }

// constructors for ivec3
inline ivec3::ivec3(const int32_t& _f) { x = _f; y = _f; z = _f; }

inline ivec3::ivec3(const simdint& _f) { x = _f; y = _f; z = _f; }

inline ivec3::ivec3(const vec3& _v) { x = _v.x; y = _v.y; z = _v.z; }

inline ivec3::ivec3(const simdint& _x, const simdint& _y, const simdint& _z) { x = _x; y = _y; z = _z; }

inline ivec3::ivec3(const simdint& _x, const ivec2& _y) { x = _x; y = _y.x; z = _y.y; }

inline ivec3::ivec3(const ivec2& _x, const simdint& _z) { x = _x.x; y = _x.y; z = _z; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec3>, int>>
ivec3::ivec3(const simdint& _x, const V& _v) { x = _x; y = _v.x; z = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec4>, int>>
ivec3::ivec3(const simdint& _x, const V& _v) { x = _x; y = _v.x; z = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec2>, int>>
ivec3::ivec3(const simdint& _x, const simdint& _y, const V& _v) { x = _x; y = _y; z = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec3>, int>>
ivec3::ivec3(const simdint& _x, const simdint& _y, const V& _v) { x = _x; y = _y; z = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec4>, int>>
ivec3::ivec3(const simdint& _x, const simdint& _y, const V& _v) { x = _x; y = _y; z = _v.x; }

#endif



