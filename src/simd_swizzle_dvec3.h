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
 
#ifndef SIMD_SWIZZLE_DVEC3_H
#define SIMD_SWIZZLE_DVEC3_H

#include "simd_dvec2.h"
#include "simd_dvec3.h"
#include "simd_dvec4.h"

#pragma region dvec3 swizzle implementations

// dvec3 swizzle implementations
inline dvec2 dvec3::bb() const { return { b, b }; }
inline dvec3 dvec3::bbb() const { return { b, b, b }; }
inline dvec4 dvec3::bbbb() const { return { b, b, b, b }; }
inline dvec4 dvec3::bbbg() const { return { b, b, b, g }; }
inline dvec4 dvec3::bbbr() const { return { b, b, b, r }; }
inline dvec3 dvec3::bbg() const { return { b, b, g }; }
inline dvec4 dvec3::bbgb() const { return { b, b, g, b }; }
inline dvec4 dvec3::bbgg() const { return { b, b, g, g }; }
inline dvec4 dvec3::bbgr() const { return { b, b, g, r }; }
inline dvec3 dvec3::bbr() const { return { b, b, r }; }
inline dvec4 dvec3::bbrb() const { return { b, b, r, b }; }
inline dvec4 dvec3::bbrg() const { return { b, b, r, g }; }
inline dvec4 dvec3::bbrr() const { return { b, b, r, r }; }
inline dvec2 dvec3::bg() const { return { b, g }; }
inline dvec3 dvec3::bgb() const { return { b, g, b }; }
inline dvec4 dvec3::bgbb() const { return { b, g, b, b }; }
inline dvec4 dvec3::bgbg() const { return { b, g, b, g }; }
inline dvec4 dvec3::bgbr() const { return { b, g, b, r }; }
inline dvec3 dvec3::bgg() const { return { b, g, g }; }
inline dvec4 dvec3::bggb() const { return { b, g, g, b }; }
inline dvec4 dvec3::bggg() const { return { b, g, g, g }; }
inline dvec4 dvec3::bggr() const { return { b, g, g, r }; }
inline dvec3 dvec3::bgr() const { return { b, g, r }; }
inline dvec4 dvec3::bgrb() const { return { b, g, r, b }; }
inline dvec4 dvec3::bgrg() const { return { b, g, r, g }; }
inline dvec4 dvec3::bgrr() const { return { b, g, r, r }; }
inline dvec2 dvec3::br() const { return { b, r }; }
inline dvec3 dvec3::brb() const { return { b, r, b }; }
inline dvec4 dvec3::brbb() const { return { b, r, b, b }; }
inline dvec4 dvec3::brbg() const { return { b, r, b, g }; }
inline dvec4 dvec3::brbr() const { return { b, r, b, r }; }
inline dvec3 dvec3::brg() const { return { b, r, g }; }
inline dvec4 dvec3::brgb() const { return { b, r, g, b }; }
inline dvec4 dvec3::brgg() const { return { b, r, g, g }; }
inline dvec4 dvec3::brgr() const { return { b, r, g, r }; }
inline dvec3 dvec3::brr() const { return { b, r, r }; }
inline dvec4 dvec3::brrb() const { return { b, r, r, b }; }
inline dvec4 dvec3::brrg() const { return { b, r, r, g }; }
inline dvec4 dvec3::brrr() const { return { b, r, r, r }; }
inline dvec2 dvec3::gb() const { return { g, b }; }
inline dvec3 dvec3::gbb() const { return { g, b, b }; }
inline dvec4 dvec3::gbbb() const { return { g, b, b, b }; }
inline dvec4 dvec3::gbbg() const { return { g, b, b, g }; }
inline dvec4 dvec3::gbbr() const { return { g, b, b, r }; }
inline dvec3 dvec3::gbg() const { return { g, b, g }; }
inline dvec4 dvec3::gbgb() const { return { g, b, g, b }; }
inline dvec4 dvec3::gbgg() const { return { g, b, g, g }; }
inline dvec4 dvec3::gbgr() const { return { g, b, g, r }; }
inline dvec3 dvec3::gbr() const { return { g, b, r }; }
inline dvec4 dvec3::gbrb() const { return { g, b, r, b }; }
inline dvec4 dvec3::gbrg() const { return { g, b, r, g }; }
inline dvec4 dvec3::gbrr() const { return { g, b, r, r }; }
inline dvec2 dvec3::gg() const { return { g, g }; }
inline dvec3 dvec3::ggb() const { return { g, g, b }; }
inline dvec4 dvec3::ggbb() const { return { g, g, b, b }; }
inline dvec4 dvec3::ggbg() const { return { g, g, b, g }; }
inline dvec4 dvec3::ggbr() const { return { g, g, b, r }; }
inline dvec3 dvec3::ggg() const { return { g, g, g }; }
inline dvec4 dvec3::gggb() const { return { g, g, g, b }; }
inline dvec4 dvec3::gggg() const { return { g, g, g, g }; }
inline dvec4 dvec3::gggr() const { return { g, g, g, r }; }
inline dvec3 dvec3::ggr() const { return { g, g, r }; }
inline dvec4 dvec3::ggrb() const { return { g, g, r, b }; }
inline dvec4 dvec3::ggrg() const { return { g, g, r, g }; }
inline dvec4 dvec3::ggrr() const { return { g, g, r, r }; }
inline dvec2 dvec3::gr() const { return { g, r }; }
inline dvec3 dvec3::grb() const { return { g, r, b }; }
inline dvec4 dvec3::grbb() const { return { g, r, b, b }; }
inline dvec4 dvec3::grbg() const { return { g, r, b, g }; }
inline dvec4 dvec3::grbr() const { return { g, r, b, r }; }
inline dvec3 dvec3::grg() const { return { g, r, g }; }
inline dvec4 dvec3::grgb() const { return { g, r, g, b }; }
inline dvec4 dvec3::grgg() const { return { g, r, g, g }; }
inline dvec4 dvec3::grgr() const { return { g, r, g, r }; }
inline dvec3 dvec3::grr() const { return { g, r, r }; }
inline dvec4 dvec3::grrb() const { return { g, r, r, b }; }
inline dvec4 dvec3::grrg() const { return { g, r, r, g }; }
inline dvec4 dvec3::grrr() const { return { g, r, r, r }; }
inline dvec2 dvec3::rb() const { return { r, b }; }
inline dvec3 dvec3::rbb() const { return { r, b, b }; }
inline dvec4 dvec3::rbbb() const { return { r, b, b, b }; }
inline dvec4 dvec3::rbbg() const { return { r, b, b, g }; }
inline dvec4 dvec3::rbbr() const { return { r, b, b, r }; }
inline dvec3 dvec3::rbg() const { return { r, b, g }; }
inline dvec4 dvec3::rbgb() const { return { r, b, g, b }; }
inline dvec4 dvec3::rbgg() const { return { r, b, g, g }; }
inline dvec4 dvec3::rbgr() const { return { r, b, g, r }; }
inline dvec3 dvec3::rbr() const { return { r, b, r }; }
inline dvec4 dvec3::rbrb() const { return { r, b, r, b }; }
inline dvec4 dvec3::rbrg() const { return { r, b, r, g }; }
inline dvec4 dvec3::rbrr() const { return { r, b, r, r }; }
inline dvec2 dvec3::rg() const { return { r, g }; }
inline dvec3 dvec3::rgb() const { return { r, g, b }; }
inline dvec4 dvec3::rgbb() const { return { r, g, b, b }; }
inline dvec4 dvec3::rgbg() const { return { r, g, b, g }; }
inline dvec4 dvec3::rgbr() const { return { r, g, b, r }; }
inline dvec3 dvec3::rgg() const { return { r, g, g }; }
inline dvec4 dvec3::rggb() const { return { r, g, g, b }; }
inline dvec4 dvec3::rggg() const { return { r, g, g, g }; }
inline dvec4 dvec3::rggr() const { return { r, g, g, r }; }
inline dvec3 dvec3::rgr() const { return { r, g, r }; }
inline dvec4 dvec3::rgrb() const { return { r, g, r, b }; }
inline dvec4 dvec3::rgrg() const { return { r, g, r, g }; }
inline dvec4 dvec3::rgrr() const { return { r, g, r, r }; }
inline dvec2 dvec3::rr() const { return { r, r }; }
inline dvec3 dvec3::rrb() const { return { r, r, b }; }
inline dvec4 dvec3::rrbb() const { return { r, r, b, b }; }
inline dvec4 dvec3::rrbg() const { return { r, r, b, g }; }
inline dvec4 dvec3::rrbr() const { return { r, r, b, r }; }
inline dvec3 dvec3::rrg() const { return { r, r, g }; }
inline dvec4 dvec3::rrgb() const { return { r, r, g, b }; }
inline dvec4 dvec3::rrgg() const { return { r, r, g, g }; }
inline dvec4 dvec3::rrgr() const { return { r, r, g, r }; }
inline dvec3 dvec3::rrr() const { return { r, r, r }; }
inline dvec4 dvec3::rrrb() const { return { r, r, r, b }; }
inline dvec4 dvec3::rrrg() const { return { r, r, r, g }; }
inline dvec4 dvec3::rrrr() const { return { r, r, r, r }; }
inline dvec2 dvec3::ss() const { return { s, s }; }
inline dvec3 dvec3::sss() const { return { s, s, s }; }
inline dvec4 dvec3::ssss() const { return { s, s, s, s }; }
inline dvec4 dvec3::ssst() const { return { s, s, s, t }; }
inline dvec4 dvec3::sssp() const { return { s, s, s, p }; }
inline dvec3 dvec3::sst() const { return { s, s, t }; }
inline dvec4 dvec3::ssts() const { return { s, s, t, s }; }
inline dvec4 dvec3::sstt() const { return { s, s, t, t }; }
inline dvec4 dvec3::sstp() const { return { s, s, t, p }; }
inline dvec3 dvec3::ssp() const { return { s, s, p }; }
inline dvec4 dvec3::ssps() const { return { s, s, p, s }; }
inline dvec4 dvec3::sspt() const { return { s, s, p, t }; }
inline dvec4 dvec3::sspp() const { return { s, s, p, p }; }
inline dvec2 dvec3::st() const { return { s, t }; }
inline dvec3 dvec3::sts() const { return { s, t, s }; }
inline dvec4 dvec3::stss() const { return { s, t, s, s }; }
inline dvec4 dvec3::stst() const { return { s, t, s, t }; }
inline dvec4 dvec3::stsp() const { return { s, t, s, p }; }
inline dvec3 dvec3::stt() const { return { s, t, t }; }
inline dvec4 dvec3::stts() const { return { s, t, t, s }; }
inline dvec4 dvec3::sttt() const { return { s, t, t, t }; }
inline dvec4 dvec3::sttp() const { return { s, t, t, p }; }
inline dvec3 dvec3::stp() const { return { s, t, p }; }
inline dvec4 dvec3::stps() const { return { s, t, p, s }; }
inline dvec4 dvec3::stpt() const { return { s, t, p, t }; }
inline dvec4 dvec3::stpp() const { return { s, t, p, p }; }
inline dvec2 dvec3::sp() const { return { s, p }; }
inline dvec3 dvec3::sps() const { return { s, p, s }; }
inline dvec4 dvec3::spss() const { return { s, p, s, s }; }
inline dvec4 dvec3::spst() const { return { s, p, s, t }; }
inline dvec4 dvec3::spsp() const { return { s, p, s, p }; }
inline dvec3 dvec3::spt() const { return { s, p, t }; }
inline dvec4 dvec3::spts() const { return { s, p, t, s }; }
inline dvec4 dvec3::sptt() const { return { s, p, t, t }; }
inline dvec4 dvec3::sptp() const { return { s, p, t, p }; }
inline dvec3 dvec3::spp() const { return { s, p, p }; }
inline dvec4 dvec3::spps() const { return { s, p, p, s }; }
inline dvec4 dvec3::sppt() const { return { s, p, p, t }; }
inline dvec4 dvec3::sppp() const { return { s, p, p, p }; }
inline dvec2 dvec3::ts() const { return { t, s }; }
inline dvec3 dvec3::tss() const { return { t, s, s }; }
inline dvec4 dvec3::tsss() const { return { t, s, s, s }; }
inline dvec4 dvec3::tsst() const { return { t, s, s, t }; }
inline dvec4 dvec3::tssp() const { return { t, s, s, p }; }
inline dvec3 dvec3::tst() const { return { t, s, t }; }
inline dvec4 dvec3::tsts() const { return { t, s, t, s }; }
inline dvec4 dvec3::tstt() const { return { t, s, t, t }; }
inline dvec4 dvec3::tstp() const { return { t, s, t, p }; }
inline dvec3 dvec3::tsp() const { return { t, s, p }; }
inline dvec4 dvec3::tsps() const { return { t, s, p, s }; }
inline dvec4 dvec3::tspt() const { return { t, s, p, t }; }
inline dvec4 dvec3::tspp() const { return { t, s, p, p }; }
inline dvec2 dvec3::tt() const { return { t, t }; }
inline dvec3 dvec3::tts() const { return { t, t, s }; }
inline dvec4 dvec3::ttss() const { return { t, t, s, s }; }
inline dvec4 dvec3::ttst() const { return { t, t, s, t }; }
inline dvec4 dvec3::ttsp() const { return { t, t, s, p }; }
inline dvec3 dvec3::ttt() const { return { t, t, t }; }
inline dvec4 dvec3::ttts() const { return { t, t, t, s }; }
inline dvec4 dvec3::tttt() const { return { t, t, t, t }; }
inline dvec4 dvec3::tttp() const { return { t, t, t, p }; }
inline dvec3 dvec3::ttp() const { return { t, t, p }; }
inline dvec4 dvec3::ttps() const { return { t, t, p, s }; }
inline dvec4 dvec3::ttpt() const { return { t, t, p, t }; }
inline dvec4 dvec3::ttpp() const { return { t, t, p, p }; }
inline dvec2 dvec3::tp() const { return { t, p }; }
inline dvec3 dvec3::tps() const { return { t, p, s }; }
inline dvec4 dvec3::tpss() const { return { t, p, s, s }; }
inline dvec4 dvec3::tpst() const { return { t, p, s, t }; }
inline dvec4 dvec3::tpsp() const { return { t, p, s, p }; }
inline dvec3 dvec3::tpt() const { return { t, p, t }; }
inline dvec4 dvec3::tpts() const { return { t, p, t, s }; }
inline dvec4 dvec3::tptt() const { return { t, p, t, t }; }
inline dvec4 dvec3::tptp() const { return { t, p, t, p }; }
inline dvec3 dvec3::tpp() const { return { t, p, p }; }
inline dvec4 dvec3::tpps() const { return { t, p, p, s }; }
inline dvec4 dvec3::tppt() const { return { t, p, p, t }; }
inline dvec4 dvec3::tppp() const { return { t, p, p, p }; }
inline dvec2 dvec3::ps() const { return { p, s }; }
inline dvec3 dvec3::pss() const { return { p, s, s }; }
inline dvec4 dvec3::psss() const { return { p, s, s, s }; }
inline dvec4 dvec3::psst() const { return { p, s, s, t }; }
inline dvec4 dvec3::pssp() const { return { p, s, s, p }; }
inline dvec3 dvec3::pst() const { return { p, s, t }; }
inline dvec4 dvec3::psts() const { return { p, s, t, s }; }
inline dvec4 dvec3::pstt() const { return { p, s, t, t }; }
inline dvec4 dvec3::pstp() const { return { p, s, t, p }; }
inline dvec3 dvec3::psp() const { return { p, s, p }; }
inline dvec4 dvec3::psps() const { return { p, s, p, s }; }
inline dvec4 dvec3::pspt() const { return { p, s, p, t }; }
inline dvec4 dvec3::pspp() const { return { p, s, p, p }; }
inline dvec2 dvec3::pt() const { return { p, t }; }
inline dvec3 dvec3::pts() const { return { p, t, s }; }
inline dvec4 dvec3::ptss() const { return { p, t, s, s }; }
inline dvec4 dvec3::ptst() const { return { p, t, s, t }; }
inline dvec4 dvec3::ptsp() const { return { p, t, s, p }; }
inline dvec3 dvec3::ptt() const { return { p, t, t }; }
inline dvec4 dvec3::ptts() const { return { p, t, t, s }; }
inline dvec4 dvec3::pttt() const { return { p, t, t, t }; }
inline dvec4 dvec3::pttp() const { return { p, t, t, p }; }
inline dvec3 dvec3::ptp() const { return { p, t, p }; }
inline dvec4 dvec3::ptps() const { return { p, t, p, s }; }
inline dvec4 dvec3::ptpt() const { return { p, t, p, t }; }
inline dvec4 dvec3::ptpp() const { return { p, t, p, p }; }
inline dvec2 dvec3::pp() const { return { p, p }; }
inline dvec3 dvec3::pps() const { return { p, p, s }; }
inline dvec4 dvec3::ppss() const { return { p, p, s, s }; }
inline dvec4 dvec3::ppst() const { return { p, p, s, t }; }
inline dvec4 dvec3::ppsp() const { return { p, p, s, p }; }
inline dvec3 dvec3::ppt() const { return { p, p, t }; }
inline dvec4 dvec3::ppts() const { return { p, p, t, s }; }
inline dvec4 dvec3::pptt() const { return { p, p, t, t }; }
inline dvec4 dvec3::pptp() const { return { p, p, t, p }; }
inline dvec3 dvec3::ppp() const { return { p, p, p }; }
inline dvec4 dvec3::ppps() const { return { p, p, p, s }; }
inline dvec4 dvec3::pppt() const { return { p, p, p, t }; }
inline dvec4 dvec3::pppp() const { return { p, p, p, p }; }
inline dvec2 dvec3::xx() const { return { x, x }; }
inline dvec3 dvec3::xxx() const { return { x, x, x }; }
inline dvec4 dvec3::xxxx() const { return { x, x, x, x }; }
inline dvec4 dvec3::xxxy() const { return { x, x, x, y }; }
inline dvec4 dvec3::xxxz() const { return { x, x, x, z }; }
inline dvec3 dvec3::xxy() const { return { x, x, y }; }
inline dvec4 dvec3::xxyx() const { return { x, x, y, x }; }
inline dvec4 dvec3::xxyy() const { return { x, x, y, y }; }
inline dvec4 dvec3::xxyz() const { return { x, x, y, z }; }
inline dvec3 dvec3::xxz() const { return { x, x, z }; }
inline dvec4 dvec3::xxzx() const { return { x, x, z, x }; }
inline dvec4 dvec3::xxzy() const { return { x, x, z, y }; }
inline dvec4 dvec3::xxzz() const { return { x, x, z, z }; }
inline dvec2 dvec3::xy() const { return { x, y }; }
inline dvec3 dvec3::xyx() const { return { x, y, x }; }
inline dvec4 dvec3::xyxx() const { return { x, y, x, x }; }
inline dvec4 dvec3::xyxy() const { return { x, y, x, y }; }
inline dvec4 dvec3::xyxz() const { return { x, y, x, z }; }
inline dvec3 dvec3::xyy() const { return { x, y, y }; }
inline dvec4 dvec3::xyyx() const { return { x, y, y, x }; }
inline dvec4 dvec3::xyyy() const { return { x, y, y, y }; }
inline dvec4 dvec3::xyyz() const { return { x, y, y, z }; }
inline dvec3 dvec3::xyz() const { return { x, y, z }; }
inline dvec4 dvec3::xyzx() const { return { x, y, z, x }; }
inline dvec4 dvec3::xyzy() const { return { x, y, z, y }; }
inline dvec4 dvec3::xyzz() const { return { x, y, z, z }; }
inline dvec2 dvec3::xz() const { return { x, z }; }
inline dvec3 dvec3::xzx() const { return { x, z, x }; }
inline dvec4 dvec3::xzxx() const { return { x, z, x, x }; }
inline dvec4 dvec3::xzxy() const { return { x, z, x, y }; }
inline dvec4 dvec3::xzxz() const { return { x, z, x, z }; }
inline dvec3 dvec3::xzy() const { return { x, z, y }; }
inline dvec4 dvec3::xzyx() const { return { x, z, y, x }; }
inline dvec4 dvec3::xzyy() const { return { x, z, y, y }; }
inline dvec4 dvec3::xzyz() const { return { x, z, y, z }; }
inline dvec3 dvec3::xzz() const { return { x, z, z }; }
inline dvec4 dvec3::xzzx() const { return { x, z, z, x }; }
inline dvec4 dvec3::xzzy() const { return { x, z, z, y }; }
inline dvec4 dvec3::xzzz() const { return { x, z, z, z }; }
inline dvec2 dvec3::yx() const { return { y, x }; }
inline dvec3 dvec3::yxx() const { return { y, x, x }; }
inline dvec4 dvec3::yxxx() const { return { y, x, x, x }; }
inline dvec4 dvec3::yxxy() const { return { y, x, x, y }; }
inline dvec4 dvec3::yxxz() const { return { y, x, x, z }; }
inline dvec3 dvec3::yxy() const { return { y, x, y }; }
inline dvec4 dvec3::yxyx() const { return { y, x, y, x }; }
inline dvec4 dvec3::yxyy() const { return { y, x, y, y }; }
inline dvec4 dvec3::yxyz() const { return { y, x, y, z }; }
inline dvec3 dvec3::yxz() const { return { y, x, z }; }
inline dvec4 dvec3::yxzx() const { return { y, x, z, x }; }
inline dvec4 dvec3::yxzy() const { return { y, x, z, y }; }
inline dvec4 dvec3::yxzz() const { return { y, x, z, z }; }
inline dvec2 dvec3::yy() const { return { y, y }; }
inline dvec3 dvec3::yyx() const { return { y, y, x }; }
inline dvec4 dvec3::yyxx() const { return { y, y, x, x }; }
inline dvec4 dvec3::yyxy() const { return { y, y, x, y }; }
inline dvec4 dvec3::yyxz() const { return { y, y, x, z }; }
inline dvec3 dvec3::yyy() const { return { y, y, y }; }
inline dvec4 dvec3::yyyx() const { return { y, y, y, x }; }
inline dvec4 dvec3::yyyy() const { return { y, y, y, y }; }
inline dvec4 dvec3::yyyz() const { return { y, y, y, z }; }
inline dvec3 dvec3::yyz() const { return { y, y, z }; }
inline dvec4 dvec3::yyzx() const { return { y, y, z, x }; }
inline dvec4 dvec3::yyzy() const { return { y, y, z, y }; }
inline dvec4 dvec3::yyzz() const { return { y, y, z, z }; }
inline dvec2 dvec3::yz() const { return { y, z }; }
inline dvec3 dvec3::yzx() const { return { y, z, x }; }
inline dvec4 dvec3::yzxx() const { return { y, z, x, x }; }
inline dvec4 dvec3::yzxy() const { return { y, z, x, y }; }
inline dvec4 dvec3::yzxz() const { return { y, z, x, z }; }
inline dvec3 dvec3::yzy() const { return { y, z, y }; }
inline dvec4 dvec3::yzyx() const { return { y, z, y, x }; }
inline dvec4 dvec3::yzyy() const { return { y, z, y, y }; }
inline dvec4 dvec3::yzyz() const { return { y, z, y, z }; }
inline dvec3 dvec3::yzz() const { return { y, z, z }; }
inline dvec4 dvec3::yzzx() const { return { y, z, z, x }; }
inline dvec4 dvec3::yzzy() const { return { y, z, z, y }; }
inline dvec4 dvec3::yzzz() const { return { y, z, z, z }; }
inline dvec2 dvec3::zx() const { return { z, x }; }
inline dvec3 dvec3::zxx() const { return { z, x, x }; }
inline dvec4 dvec3::zxxx() const { return { z, x, x, x }; }
inline dvec4 dvec3::zxxy() const { return { z, x, x, y }; }
inline dvec4 dvec3::zxxz() const { return { z, x, x, z }; }
inline dvec3 dvec3::zxy() const { return { z, x, y }; }
inline dvec4 dvec3::zxyx() const { return { z, x, y, x }; }
inline dvec4 dvec3::zxyy() const { return { z, x, y, y }; }
inline dvec4 dvec3::zxyz() const { return { z, x, y, z }; }
inline dvec3 dvec3::zxz() const { return { z, x, z }; }
inline dvec4 dvec3::zxzx() const { return { z, x, z, x }; }
inline dvec4 dvec3::zxzy() const { return { z, x, z, y }; }
inline dvec4 dvec3::zxzz() const { return { z, x, z, z }; }
inline dvec2 dvec3::zy() const { return { z, y }; }
inline dvec3 dvec3::zyx() const { return { z, y, x }; }
inline dvec4 dvec3::zyxx() const { return { z, y, x, x }; }
inline dvec4 dvec3::zyxy() const { return { z, y, x, y }; }
inline dvec4 dvec3::zyxz() const { return { z, y, x, z }; }
inline dvec3 dvec3::zyy() const { return { z, y, y }; }
inline dvec4 dvec3::zyyx() const { return { z, y, y, x }; }
inline dvec4 dvec3::zyyy() const { return { z, y, y, y }; }
inline dvec4 dvec3::zyyz() const { return { z, y, y, z }; }
inline dvec3 dvec3::zyz() const { return { z, y, z }; }
inline dvec4 dvec3::zyzx() const { return { z, y, z, x }; }
inline dvec4 dvec3::zyzy() const { return { z, y, z, y }; }
inline dvec4 dvec3::zyzz() const { return { z, y, z, z }; }
inline dvec2 dvec3::zz() const { return { z, z }; }
inline dvec3 dvec3::zzx() const { return { z, z, x }; }
inline dvec4 dvec3::zzxx() const { return { z, z, x, x }; }
inline dvec4 dvec3::zzxy() const { return { z, z, x, y }; }
inline dvec4 dvec3::zzxz() const { return { z, z, x, z }; }
inline dvec3 dvec3::zzy() const { return { z, z, y }; }
inline dvec4 dvec3::zzyx() const { return { z, z, y, x }; }
inline dvec4 dvec3::zzyy() const { return { z, z, y, y }; }
inline dvec4 dvec3::zzyz() const { return { z, z, y, z }; }
inline dvec3 dvec3::zzz() const { return { z, z, z }; }
inline dvec4 dvec3::zzzx() const { return { z, z, z, x }; }
inline dvec4 dvec3::zzzy() const { return { z, z, z, y }; }
inline dvec4 dvec3::zzzz() const { return { z, z, z, z }; }
inline void dvec3::bg(const simddouble& _val0, const simddouble& _val1) { b = _val0; g = _val1; }
inline void dvec3::bg(const dvec2& _val) { b = _val.x; g = _val.y; }
inline void dvec3::bg(const simddouble& _val) { b = _val; g = _val; }
inline void dvec3::bgr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { b = _val0; g = _val1; r = _val2; }
inline void dvec3::bgr(const dvec3& _val) { b = _val.x; g = _val.y; r = _val.z; }
inline void dvec3::bgr(const simddouble& _val) { b = _val; g = _val; r = _val; }
inline void dvec3::br(const simddouble& _val0, const simddouble& _val1) { b = _val0; r = _val1; }
inline void dvec3::br(const dvec2& _val) { b = _val.x; r = _val.y; }
inline void dvec3::br(const simddouble& _val) { b = _val; r = _val; }
inline void dvec3::brg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { b = _val0; r = _val1; g = _val2; }
inline void dvec3::brg(const dvec3& _val) { b = _val.x; r = _val.y; g = _val.z; }
inline void dvec3::brg(const simddouble& _val) { b = _val; r = _val; g = _val; }
inline void dvec3::gb(const simddouble& _val0, const simddouble& _val1) { g = _val0; b = _val1; }
inline void dvec3::gb(const dvec2& _val) { g = _val.x; b = _val.y; }
inline void dvec3::gb(const simddouble& _val) { g = _val; b = _val; }
inline void dvec3::gbr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { g = _val0; b = _val1; r = _val2; }
inline void dvec3::gbr(const dvec3& _val) { g = _val.x; b = _val.y; r = _val.z; }
inline void dvec3::gbr(const simddouble& _val) { g = _val; b = _val; r = _val; }
inline void dvec3::gr(const simddouble& _val0, const simddouble& _val1) { g = _val0; r = _val1; }
inline void dvec3::gr(const dvec2& _val) { g = _val.x; r = _val.y; }
inline void dvec3::gr(const simddouble& _val) { g = _val; r = _val; }
inline void dvec3::grb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { g = _val0; r = _val1; b = _val2; }
inline void dvec3::grb(const dvec3& _val) { g = _val.x; r = _val.y; b = _val.z; }
inline void dvec3::grb(const simddouble& _val) { g = _val; r = _val; b = _val; }
inline void dvec3::rb(const simddouble& _val0, const simddouble& _val1) { r = _val0; b = _val1; }
inline void dvec3::rb(const dvec2& _val) { r = _val.x; b = _val.y; }
inline void dvec3::rb(const simddouble& _val) { r = _val; b = _val; }
inline void dvec3::rbg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { r = _val0; b = _val1; g = _val2; }
inline void dvec3::rbg(const dvec3& _val) { r = _val.x; b = _val.y; g = _val.z; }
inline void dvec3::rbg(const simddouble& _val) { r = _val; b = _val; g = _val; }
inline void dvec3::rg(const simddouble& _val0, const simddouble& _val1) { r = _val0; g = _val1; }
inline void dvec3::rg(const dvec2& _val) { r = _val.x; g = _val.y; }
inline void dvec3::rg(const simddouble& _val) { r = _val; g = _val; }
inline void dvec3::rgb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { r = _val0; g = _val1; b = _val2; }
inline void dvec3::rgb(const dvec3& _val) { r = _val.x; g = _val.y; b = _val.z; }
inline void dvec3::rgb(const simddouble& _val) { r = _val; g = _val; b = _val; }
inline void dvec3::st(const simddouble& _val0, const simddouble& _val1) { s = _val0; t = _val1; }
inline void dvec3::st(const dvec2& _val) { s = _val.s; t = _val.t; }
inline void dvec3::st(const simddouble& _val) { s = _val; t = _val; }
inline void dvec3::stp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { s = _val0; t = _val1; p = _val2; }
inline void dvec3::stp(const dvec3& _val) { s = _val.s; t = _val.t; p = _val.p; }
inline void dvec3::stp(const simddouble& _val) { s = _val; t = _val; p = _val; }
inline void dvec3::sp(const simddouble& _val0, const simddouble& _val1) { s = _val0; p = _val1; }
inline void dvec3::sp(const dvec2& _val) { s = _val.s; p = _val.t; }
inline void dvec3::sp(const simddouble& _val) { s = _val; p = _val; }
inline void dvec3::spt(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { s = _val0; p = _val1; t = _val2; }
inline void dvec3::spt(const dvec3& _val) { s = _val.s; p = _val.t; t = _val.p; }
inline void dvec3::spt(const simddouble& _val) { s = _val; p = _val; t = _val; }
inline void dvec3::ts(const simddouble& _val0, const simddouble& _val1) { t = _val0; s = _val1; }
inline void dvec3::ts(const dvec2& _val) { t = _val.s; s = _val.t; }
inline void dvec3::ts(const simddouble& _val) { t = _val; s = _val; }
inline void dvec3::tsp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { t = _val0; s = _val1; p = _val2; }
inline void dvec3::tsp(const dvec3& _val) { t = _val.s; s = _val.t; p = _val.p; }
inline void dvec3::tsp(const simddouble& _val) { t = _val; s = _val; p = _val; }
inline void dvec3::tp(const simddouble& _val0, const simddouble& _val1) { t = _val0; p = _val1; }
inline void dvec3::tp(const dvec2& _val) { t = _val.s; p = _val.t; }
inline void dvec3::tp(const simddouble& _val) { t = _val; p = _val; }
inline void dvec3::tps(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { t = _val0; p = _val1; s = _val2; }
inline void dvec3::tps(const dvec3& _val) { t = _val.s; p = _val.t; s = _val.p; }
inline void dvec3::tps(const simddouble& _val) { t = _val; p = _val; s = _val; }
inline void dvec3::ps(const simddouble& _val0, const simddouble& _val1) { p = _val0; s = _val1; }
inline void dvec3::ps(const dvec2& _val) { p = _val.s; s = _val.t; }
inline void dvec3::ps(const simddouble& _val) { p = _val; s = _val; }
inline void dvec3::pst(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { p = _val0; s = _val1; t = _val2; }
inline void dvec3::pst(const dvec3& _val) { p = _val.s; s = _val.t; t = _val.p; }
inline void dvec3::pst(const simddouble& _val) { p = _val; s = _val; t = _val; }
inline void dvec3::pt(const simddouble& _val0, const simddouble& _val1) { p = _val0; t = _val1; }
inline void dvec3::pt(const dvec2& _val) { p = _val.s; t = _val.t; }
inline void dvec3::pt(const simddouble& _val) { p = _val; t = _val; }
inline void dvec3::pts(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { p = _val0; t = _val1; s = _val2; }
inline void dvec3::pts(const dvec3& _val) { p = _val.s; t = _val.t; s = _val.p; }
inline void dvec3::pts(const simddouble& _val) { p = _val; t = _val; s = _val; }
inline void dvec3::xy(const simddouble& _val0, const simddouble& _val1) { x = _val0; y = _val1; }
inline void dvec3::xy(const dvec2& _val) { x = _val.x; y = _val.y; }
inline void dvec3::xy(const simddouble& _val) { x = _val; y = _val; }
inline void dvec3::xyz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { x = _val0; y = _val1; z = _val2; }
inline void dvec3::xyz(const dvec3& _val) { x = _val.x; y = _val.y; z = _val.z; }
inline void dvec3::xyz(const simddouble& _val) { x = _val; y = _val; z = _val; }
inline void dvec3::xz(const simddouble& _val0, const simddouble& _val1) { x = _val0; z = _val1; }
inline void dvec3::xz(const dvec2& _val) { x = _val.x; z = _val.y; }
inline void dvec3::xz(const simddouble& _val) { x = _val; z = _val; }
inline void dvec3::xzy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { x = _val0; z = _val1; y = _val2; }
inline void dvec3::xzy(const dvec3& _val) { x = _val.x; z = _val.y; y = _val.z; }
inline void dvec3::xzy(const simddouble& _val) { x = _val; z = _val; y = _val; }
inline void dvec3::yx(const simddouble& _val0, const simddouble& _val1) { y = _val0; x = _val1; }
inline void dvec3::yx(const dvec2& _val) { y = _val.x; x = _val.y; }
inline void dvec3::yx(const simddouble& _val) { y = _val; x = _val; }
inline void dvec3::yxz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { y = _val0; x = _val1; z = _val2; }
inline void dvec3::yxz(const dvec3& _val) { y = _val.x; x = _val.y; z = _val.z; }
inline void dvec3::yxz(const simddouble& _val) { y = _val; x = _val; z = _val; }
inline void dvec3::yz(const simddouble& _val0, const simddouble& _val1) { y = _val0; z = _val1; }
inline void dvec3::yz(const dvec2& _val) { y = _val.x; z = _val.y; }
inline void dvec3::yz(const simddouble& _val) { y = _val; z = _val; }
inline void dvec3::yzx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { y = _val0; z = _val1; x = _val2; }
inline void dvec3::yzx(const dvec3& _val) { y = _val.x; z = _val.y; x = _val.z; }
inline void dvec3::yzx(const simddouble& _val) { y = _val; z = _val; x = _val; }
inline void dvec3::zx(const simddouble& _val0, const simddouble& _val1) { z = _val0; x = _val1; }
inline void dvec3::zx(const dvec2& _val) { z = _val.x; x = _val.y; }
inline void dvec3::zx(const simddouble& _val) { z = _val; x = _val; }
inline void dvec3::zxy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { z = _val0; x = _val1; y = _val2; }
inline void dvec3::zxy(const dvec3& _val) { z = _val.x; x = _val.y; y = _val.z; }
inline void dvec3::zxy(const simddouble& _val) { z = _val; x = _val; y = _val; }
inline void dvec3::zy(const simddouble& _val0, const simddouble& _val1) { z = _val0; y = _val1; }
inline void dvec3::zy(const dvec2& _val) { z = _val.x; y = _val.y; }
inline void dvec3::zy(const simddouble& _val) { z = _val; y = _val; }
inline void dvec3::zyx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { z = _val0; y = _val1; x = _val2; }
inline void dvec3::zyx(const dvec3& _val) { z = _val.x; y = _val.y; x = _val.z; }
inline void dvec3::zyx(const simddouble& _val) { z = _val; y = _val; x = _val; }

#pragma endregion

inline dvec3 dvec3::operator=(const dvec4& _v) { x = _v.x; y = _v.y; z = _v.z; return *this; }

// constructors for dvec3
inline dvec3::dvec3(const double& _f) { x = _f; y = _f; z = _f; }

inline dvec3::dvec3(const simddouble& _f) { x = _f; y = _f; z = _f; }

inline dvec3::dvec3(const simddouble& _x, const simddouble& _y, const simddouble& _z) { x = _x; y = _y; z = _z; }

inline dvec3::dvec3(const simddouble& _x, const dvec2& _y) { x = _x; y = _y.x; z = _y.y; }

inline dvec3::dvec3(const dvec2& _x, const simddouble& _z) { x = _x.x; y = _x.y; z = _z; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec3>, int>>
dvec3::dvec3(const simddouble& _x, const V& _v) { x = _x; y = _v.x; z = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec4>, int>>
dvec3::dvec3(const simddouble& _x, const V& _v) { x = _x; y = _v.x; z = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec2>, int>>
dvec3::dvec3(const simddouble& _x, const simddouble& _y, const V& _v) { x = _x; y = _y; z = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec3>, int>>
dvec3::dvec3(const simddouble& _x, const simddouble& _y, const V& _v) { x = _x; y = _y; z = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec4>, int>>
dvec3::dvec3(const simddouble& _x, const simddouble& _y, const V& _v) { x = _x; y = _y; z = _v.x; }


#endif



