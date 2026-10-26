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
 
#ifndef SIMD_SWIZZLE_VEC3_H
#define SIMD_SWIZZLE_VEC3_H

#include "simd_vec2.h"
#include "simd_vec3.h"
#include "simd_vec4.h"
#include "simd_ivec3.h"

#pragma region vec3 swizzle implementations

// vec3 swizzle implementations
inline vec2 vec3::bb() const { return { b, b }; }
inline vec3 vec3::bbb() const { return { b, b, b }; }
inline vec4 vec3::bbbb() const { return { b, b, b, b }; }
inline vec4 vec3::bbbg() const { return { b, b, b, g }; }
inline vec4 vec3::bbbr() const { return { b, b, b, r }; }
inline vec3 vec3::bbg() const { return { b, b, g }; }
inline vec4 vec3::bbgb() const { return { b, b, g, b }; }
inline vec4 vec3::bbgg() const { return { b, b, g, g }; }
inline vec4 vec3::bbgr() const { return { b, b, g, r }; }
inline vec3 vec3::bbr() const { return { b, b, r }; }
inline vec4 vec3::bbrb() const { return { b, b, r, b }; }
inline vec4 vec3::bbrg() const { return { b, b, r, g }; }
inline vec4 vec3::bbrr() const { return { b, b, r, r }; }
inline vec2 vec3::bg() const { return { b, g }; }
inline vec3 vec3::bgb() const { return { b, g, b }; }
inline vec4 vec3::bgbb() const { return { b, g, b, b }; }
inline vec4 vec3::bgbg() const { return { b, g, b, g }; }
inline vec4 vec3::bgbr() const { return { b, g, b, r }; }
inline vec3 vec3::bgg() const { return { b, g, g }; }
inline vec4 vec3::bggb() const { return { b, g, g, b }; }
inline vec4 vec3::bggg() const { return { b, g, g, g }; }
inline vec4 vec3::bggr() const { return { b, g, g, r }; }
inline vec3 vec3::bgr() const { return { b, g, r }; }
inline vec4 vec3::bgrb() const { return { b, g, r, b }; }
inline vec4 vec3::bgrg() const { return { b, g, r, g }; }
inline vec4 vec3::bgrr() const { return { b, g, r, r }; }
inline vec2 vec3::br() const { return { b, r }; }
inline vec3 vec3::brb() const { return { b, r, b }; }
inline vec4 vec3::brbb() const { return { b, r, b, b }; }
inline vec4 vec3::brbg() const { return { b, r, b, g }; }
inline vec4 vec3::brbr() const { return { b, r, b, r }; }
inline vec3 vec3::brg() const { return { b, r, g }; }
inline vec4 vec3::brgb() const { return { b, r, g, b }; }
inline vec4 vec3::brgg() const { return { b, r, g, g }; }
inline vec4 vec3::brgr() const { return { b, r, g, r }; }
inline vec3 vec3::brr() const { return { b, r, r }; }
inline vec4 vec3::brrb() const { return { b, r, r, b }; }
inline vec4 vec3::brrg() const { return { b, r, r, g }; }
inline vec4 vec3::brrr() const { return { b, r, r, r }; }
inline vec2 vec3::gb() const { return { g, b }; }
inline vec3 vec3::gbb() const { return { g, b, b }; }
inline vec4 vec3::gbbb() const { return { g, b, b, b }; }
inline vec4 vec3::gbbg() const { return { g, b, b, g }; }
inline vec4 vec3::gbbr() const { return { g, b, b, r }; }
inline vec3 vec3::gbg() const { return { g, b, g }; }
inline vec4 vec3::gbgb() const { return { g, b, g, b }; }
inline vec4 vec3::gbgg() const { return { g, b, g, g }; }
inline vec4 vec3::gbgr() const { return { g, b, g, r }; }
inline vec3 vec3::gbr() const { return { g, b, r }; }
inline vec4 vec3::gbrb() const { return { g, b, r, b }; }
inline vec4 vec3::gbrg() const { return { g, b, r, g }; }
inline vec4 vec3::gbrr() const { return { g, b, r, r }; }
inline vec2 vec3::gg() const { return { g, g }; }
inline vec3 vec3::ggb() const { return { g, g, b }; }
inline vec4 vec3::ggbb() const { return { g, g, b, b }; }
inline vec4 vec3::ggbg() const { return { g, g, b, g }; }
inline vec4 vec3::ggbr() const { return { g, g, b, r }; }
inline vec3 vec3::ggg() const { return { g, g, g }; }
inline vec4 vec3::gggb() const { return { g, g, g, b }; }
inline vec4 vec3::gggg() const { return { g, g, g, g }; }
inline vec4 vec3::gggr() const { return { g, g, g, r }; }
inline vec3 vec3::ggr() const { return { g, g, r }; }
inline vec4 vec3::ggrb() const { return { g, g, r, b }; }
inline vec4 vec3::ggrg() const { return { g, g, r, g }; }
inline vec4 vec3::ggrr() const { return { g, g, r, r }; }
inline vec2 vec3::gr() const { return { g, r }; }
inline vec3 vec3::grb() const { return { g, r, b }; }
inline vec4 vec3::grbb() const { return { g, r, b, b }; }
inline vec4 vec3::grbg() const { return { g, r, b, g }; }
inline vec4 vec3::grbr() const { return { g, r, b, r }; }
inline vec3 vec3::grg() const { return { g, r, g }; }
inline vec4 vec3::grgb() const { return { g, r, g, b }; }
inline vec4 vec3::grgg() const { return { g, r, g, g }; }
inline vec4 vec3::grgr() const { return { g, r, g, r }; }
inline vec3 vec3::grr() const { return { g, r, r }; }
inline vec4 vec3::grrb() const { return { g, r, r, b }; }
inline vec4 vec3::grrg() const { return { g, r, r, g }; }
inline vec4 vec3::grrr() const { return { g, r, r, r }; }
inline vec2 vec3::rb() const { return { r, b }; }
inline vec3 vec3::rbb() const { return { r, b, b }; }
inline vec4 vec3::rbbb() const { return { r, b, b, b }; }
inline vec4 vec3::rbbg() const { return { r, b, b, g }; }
inline vec4 vec3::rbbr() const { return { r, b, b, r }; }
inline vec3 vec3::rbg() const { return { r, b, g }; }
inline vec4 vec3::rbgb() const { return { r, b, g, b }; }
inline vec4 vec3::rbgg() const { return { r, b, g, g }; }
inline vec4 vec3::rbgr() const { return { r, b, g, r }; }
inline vec3 vec3::rbr() const { return { r, b, r }; }
inline vec4 vec3::rbrb() const { return { r, b, r, b }; }
inline vec4 vec3::rbrg() const { return { r, b, r, g }; }
inline vec4 vec3::rbrr() const { return { r, b, r, r }; }
inline vec2 vec3::rg() const { return { r, g }; }
inline vec3 vec3::rgb() const { return { r, g, b }; }
inline vec4 vec3::rgbb() const { return { r, g, b, b }; }
inline vec4 vec3::rgbg() const { return { r, g, b, g }; }
inline vec4 vec3::rgbr() const { return { r, g, b, r }; }
inline vec3 vec3::rgg() const { return { r, g, g }; }
inline vec4 vec3::rggb() const { return { r, g, g, b }; }
inline vec4 vec3::rggg() const { return { r, g, g, g }; }
inline vec4 vec3::rggr() const { return { r, g, g, r }; }
inline vec3 vec3::rgr() const { return { r, g, r }; }
inline vec4 vec3::rgrb() const { return { r, g, r, b }; }
inline vec4 vec3::rgrg() const { return { r, g, r, g }; }
inline vec4 vec3::rgrr() const { return { r, g, r, r }; }
inline vec2 vec3::rr() const { return { r, r }; }
inline vec3 vec3::rrb() const { return { r, r, b }; }
inline vec4 vec3::rrbb() const { return { r, r, b, b }; }
inline vec4 vec3::rrbg() const { return { r, r, b, g }; }
inline vec4 vec3::rrbr() const { return { r, r, b, r }; }
inline vec3 vec3::rrg() const { return { r, r, g }; }
inline vec4 vec3::rrgb() const { return { r, r, g, b }; }
inline vec4 vec3::rrgg() const { return { r, r, g, g }; }
inline vec4 vec3::rrgr() const { return { r, r, g, r }; }
inline vec3 vec3::rrr() const { return { r, r, r }; }
inline vec4 vec3::rrrb() const { return { r, r, r, b }; }
inline vec4 vec3::rrrg() const { return { r, r, r, g }; }
inline vec4 vec3::rrrr() const { return { r, r, r, r }; }

inline vec2 vec3::ss() const { return { s, s }; }
inline vec3 vec3::sss() const { return { s, s, s }; }
inline vec4 vec3::ssss() const { return { s, s, s, s }; }
inline vec4 vec3::ssst() const { return { s, s, s, t }; }
inline vec4 vec3::sssp() const { return { s, s, s, p }; }
inline vec3 vec3::sst() const { return { s, s, t }; }
inline vec4 vec3::ssts() const { return { s, s, t, s }; }
inline vec4 vec3::sstt() const { return { s, s, t, t }; }
inline vec4 vec3::sstp() const { return { s, s, t, p }; }
inline vec3 vec3::ssp() const { return { s, s, p }; }
inline vec4 vec3::ssps() const { return { s, s, p, s }; }
inline vec4 vec3::sspt() const { return { s, s, p, t }; }
inline vec4 vec3::sspp() const { return { s, s, p, p }; }
inline vec2 vec3::st() const { return { s, t }; }
inline vec3 vec3::sts() const { return { s, t, s }; }
inline vec4 vec3::stss() const { return { s, t, s, s }; }
inline vec4 vec3::stst() const { return { s, t, s, t }; }
inline vec4 vec3::stsp() const { return { s, t, s, p }; }
inline vec3 vec3::stt() const { return { s, t, t }; }
inline vec4 vec3::stts() const { return { s, t, t, s }; }
inline vec4 vec3::sttt() const { return { s, t, t, t }; }
inline vec4 vec3::sttp() const { return { s, t, t, p }; }
inline vec3 vec3::stp() const { return { s, t, p }; }
inline vec4 vec3::stps() const { return { s, t, p, s }; }
inline vec4 vec3::stpt() const { return { s, t, p, t }; }
inline vec4 vec3::stpp() const { return { s, t, p, p }; }
inline vec2 vec3::sp() const { return { s, p }; }
inline vec3 vec3::sps() const { return { s, p, s }; }
inline vec4 vec3::spss() const { return { s, p, s, s }; }
inline vec4 vec3::spst() const { return { s, p, s, t }; }
inline vec4 vec3::spsp() const { return { s, p, s, p }; }
inline vec3 vec3::spt() const { return { s, p, t }; }
inline vec4 vec3::spts() const { return { s, p, t, s }; }
inline vec4 vec3::sptt() const { return { s, p, t, t }; }
inline vec4 vec3::sptp() const { return { s, p, t, p }; }
inline vec3 vec3::spp() const { return { s, p, p }; }
inline vec4 vec3::spps() const { return { s, p, p, s }; }
inline vec4 vec3::sppt() const { return { s, p, p, t }; }
inline vec4 vec3::sppp() const { return { s, p, p, p }; }
inline vec2 vec3::ts() const { return { t, s }; }
inline vec3 vec3::tss() const { return { t, s, s }; }
inline vec4 vec3::tsss() const { return { t, s, s, s }; }
inline vec4 vec3::tsst() const { return { t, s, s, t }; }
inline vec4 vec3::tssp() const { return { t, s, s, p }; }
inline vec3 vec3::tst() const { return { t, s, t }; }
inline vec4 vec3::tsts() const { return { t, s, t, s }; }
inline vec4 vec3::tstt() const { return { t, s, t, t }; }
inline vec4 vec3::tstp() const { return { t, s, t, p }; }
inline vec3 vec3::tsp() const { return { t, s, p }; }
inline vec4 vec3::tsps() const { return { t, s, p, s }; }
inline vec4 vec3::tspt() const { return { t, s, p, t }; }
inline vec4 vec3::tspp() const { return { t, s, p, p }; }
inline vec2 vec3::tt() const { return { t, t }; }
inline vec3 vec3::tts() const { return { t, t, s }; }
inline vec4 vec3::ttss() const { return { t, t, s, s }; }
inline vec4 vec3::ttst() const { return { t, t, s, t }; }
inline vec4 vec3::ttsp() const { return { t, t, s, p }; }
inline vec3 vec3::ttt() const { return { t, t, t }; }
inline vec4 vec3::ttts() const { return { t, t, t, s }; }
inline vec4 vec3::tttt() const { return { t, t, t, t }; }
inline vec4 vec3::tttp() const { return { t, t, t, p }; }
inline vec3 vec3::ttp() const { return { t, t, p }; }
inline vec4 vec3::ttps() const { return { t, t, p, s }; }
inline vec4 vec3::ttpt() const { return { t, t, p, t }; }
inline vec4 vec3::ttpp() const { return { t, t, p, p }; }
inline vec2 vec3::tp() const { return { t, p }; }
inline vec3 vec3::tps() const { return { t, p, s }; }
inline vec4 vec3::tpss() const { return { t, p, s, s }; }
inline vec4 vec3::tpst() const { return { t, p, s, t }; }
inline vec4 vec3::tpsp() const { return { t, p, s, p }; }
inline vec3 vec3::tpt() const { return { t, p, t }; }
inline vec4 vec3::tpts() const { return { t, p, t, s }; }
inline vec4 vec3::tptt() const { return { t, p, t, t }; }
inline vec4 vec3::tptp() const { return { t, p, t, p }; }
inline vec3 vec3::tpp() const { return { t, p, p }; }
inline vec4 vec3::tpps() const { return { t, p, p, s }; }
inline vec4 vec3::tppt() const { return { t, p, p, t }; }
inline vec4 vec3::tppp() const { return { t, p, p, p }; }
inline vec2 vec3::ps() const { return { p, s }; }
inline vec3 vec3::pss() const { return { p, s, s }; }
inline vec4 vec3::psss() const { return { p, s, s, s }; }
inline vec4 vec3::psst() const { return { p, s, s, t }; }
inline vec4 vec3::pssp() const { return { p, s, s, p }; }
inline vec3 vec3::pst() const { return { p, s, t }; }
inline vec4 vec3::psts() const { return { p, s, t, s }; }
inline vec4 vec3::pstt() const { return { p, s, t, t }; }
inline vec4 vec3::pstp() const { return { p, s, t, p }; }
inline vec3 vec3::psp() const { return { p, s, p }; }
inline vec4 vec3::psps() const { return { p, s, p, s }; }
inline vec4 vec3::pspt() const { return { p, s, p, t }; }
inline vec4 vec3::pspp() const { return { p, s, p, p }; }
inline vec2 vec3::pt() const { return { p, t }; }
inline vec3 vec3::pts() const { return { p, t, s }; }
inline vec4 vec3::ptss() const { return { p, t, s, s }; }
inline vec4 vec3::ptst() const { return { p, t, s, t }; }
inline vec4 vec3::ptsp() const { return { p, t, s, p }; }
inline vec3 vec3::ptt() const { return { p, t, t }; }
inline vec4 vec3::ptts() const { return { p, t, t, s }; }
inline vec4 vec3::pttt() const { return { p, t, t, t }; }
inline vec4 vec3::pttp() const { return { p, t, t, p }; }
inline vec3 vec3::ptp() const { return { p, t, p }; }
inline vec4 vec3::ptps() const { return { p, t, p, s }; }
inline vec4 vec3::ptpt() const { return { p, t, p, t }; }
inline vec4 vec3::ptpp() const { return { p, t, p, p }; }
inline vec2 vec3::pp() const { return { p, p }; }
inline vec3 vec3::pps() const { return { p, p, s }; }
inline vec4 vec3::ppss() const { return { p, p, s, s }; }
inline vec4 vec3::ppst() const { return { p, p, s, t }; }
inline vec4 vec3::ppsp() const { return { p, p, s, p }; }
inline vec3 vec3::ppt() const { return { p, p, t }; }
inline vec4 vec3::ppts() const { return { p, p, t, s }; }
inline vec4 vec3::pptt() const { return { p, p, t, t }; }
inline vec4 vec3::pptp() const { return { p, p, t, p }; }
inline vec3 vec3::ppp() const { return { p, p, p }; }
inline vec4 vec3::ppps() const { return { p, p, p, s }; }
inline vec4 vec3::pppt() const { return { p, p, p, t }; }
inline vec4 vec3::pppp() const { return { p, p, p, p }; }
inline vec2 vec3::xx() const { return { x, x }; }
inline vec3 vec3::xxx() const { return { x, x, x }; }
inline vec4 vec3::xxxx() const { return { x, x, x, x }; }
inline vec4 vec3::xxxy() const { return { x, x, x, y }; }
inline vec4 vec3::xxxz() const { return { x, x, x, z }; }
inline vec3 vec3::xxy() const { return { x, x, y }; }
inline vec4 vec3::xxyx() const { return { x, x, y, x }; }
inline vec4 vec3::xxyy() const { return { x, x, y, y }; }
inline vec4 vec3::xxyz() const { return { x, x, y, z }; }
inline vec3 vec3::xxz() const { return { x, x, z }; }
inline vec4 vec3::xxzx() const { return { x, x, z, x }; }
inline vec4 vec3::xxzy() const { return { x, x, z, y }; }
inline vec4 vec3::xxzz() const { return { x, x, z, z }; }
inline vec2 vec3::xy() const { return { x, y }; }
inline vec3 vec3::xyx() const { return { x, y, x }; }
inline vec4 vec3::xyxx() const { return { x, y, x, x }; }
inline vec4 vec3::xyxy() const { return { x, y, x, y }; }
inline vec4 vec3::xyxz() const { return { x, y, x, z }; }
inline vec3 vec3::xyy() const { return { x, y, y }; }
inline vec4 vec3::xyyx() const { return { x, y, y, x }; }
inline vec4 vec3::xyyy() const { return { x, y, y, y }; }
inline vec4 vec3::xyyz() const { return { x, y, y, z }; }
inline vec3 vec3::xyz() const { return { x, y, z }; }
inline vec4 vec3::xyzx() const { return { x, y, z, x }; }
inline vec4 vec3::xyzy() const { return { x, y, z, y }; }
inline vec4 vec3::xyzz() const { return { x, y, z, z }; }
inline vec2 vec3::xz() const { return { x, z }; }
inline vec3 vec3::xzx() const { return { x, z, x }; }
inline vec4 vec3::xzxx() const { return { x, z, x, x }; }
inline vec4 vec3::xzxy() const { return { x, z, x, y }; }
inline vec4 vec3::xzxz() const { return { x, z, x, z }; }
inline vec3 vec3::xzy() const { return { x, z, y }; }
inline vec4 vec3::xzyx() const { return { x, z, y, x }; }
inline vec4 vec3::xzyy() const { return { x, z, y, y }; }
inline vec4 vec3::xzyz() const { return { x, z, y, z }; }
inline vec3 vec3::xzz() const { return { x, z, z }; }
inline vec4 vec3::xzzx() const { return { x, z, z, x }; }
inline vec4 vec3::xzzy() const { return { x, z, z, y }; }
inline vec4 vec3::xzzz() const { return { x, z, z, z }; }
inline vec2 vec3::yx() const { return { y, x }; }
inline vec3 vec3::yxx() const { return { y, x, x }; }
inline vec4 vec3::yxxx() const { return { y, x, x, x }; }
inline vec4 vec3::yxxy() const { return { y, x, x, y }; }
inline vec4 vec3::yxxz() const { return { y, x, x, z }; }
inline vec3 vec3::yxy() const { return { y, x, y }; }
inline vec4 vec3::yxyx() const { return { y, x, y, x }; }
inline vec4 vec3::yxyy() const { return { y, x, y, y }; }
inline vec4 vec3::yxyz() const { return { y, x, y, z }; }
inline vec3 vec3::yxz() const { return { y, x, z }; }
inline vec4 vec3::yxzx() const { return { y, x, z, x }; }
inline vec4 vec3::yxzy() const { return { y, x, z, y }; }
inline vec4 vec3::yxzz() const { return { y, x, z, z }; }
inline vec2 vec3::yy() const { return { y, y }; }
inline vec3 vec3::yyx() const { return { y, y, x }; }
inline vec4 vec3::yyxx() const { return { y, y, x, x }; }
inline vec4 vec3::yyxy() const { return { y, y, x, y }; }
inline vec4 vec3::yyxz() const { return { y, y, x, z }; }
inline vec3 vec3::yyy() const { return { y, y, y }; }
inline vec4 vec3::yyyx() const { return { y, y, y, x }; }
inline vec4 vec3::yyyy() const { return { y, y, y, y }; }
inline vec4 vec3::yyyz() const { return { y, y, y, z }; }
inline vec3 vec3::yyz() const { return { y, y, z }; }
inline vec4 vec3::yyzx() const { return { y, y, z, x }; }
inline vec4 vec3::yyzy() const { return { y, y, z, y }; }
inline vec4 vec3::yyzz() const { return { y, y, z, z }; }
inline vec2 vec3::yz() const { return { y, z }; }
inline vec3 vec3::yzx() const { return { y, z, x }; }
inline vec4 vec3::yzxx() const { return { y, z, x, x }; }
inline vec4 vec3::yzxy() const { return { y, z, x, y }; }
inline vec4 vec3::yzxz() const { return { y, z, x, z }; }
inline vec3 vec3::yzy() const { return { y, z, y }; }
inline vec4 vec3::yzyx() const { return { y, z, y, x }; }
inline vec4 vec3::yzyy() const { return { y, z, y, y }; }
inline vec4 vec3::yzyz() const { return { y, z, y, z }; }
inline vec3 vec3::yzz() const { return { y, z, z }; }
inline vec4 vec3::yzzx() const { return { y, z, z, x }; }
inline vec4 vec3::yzzy() const { return { y, z, z, y }; }
inline vec4 vec3::yzzz() const { return { y, z, z, z }; }
inline vec2 vec3::zx() const { return { z, x }; }
inline vec3 vec3::zxx() const { return { z, x, x }; }
inline vec4 vec3::zxxx() const { return { z, x, x, x }; }
inline vec4 vec3::zxxy() const { return { z, x, x, y }; }
inline vec4 vec3::zxxz() const { return { z, x, x, z }; }
inline vec3 vec3::zxy() const { return { z, x, y }; }
inline vec4 vec3::zxyx() const { return { z, x, y, x }; }
inline vec4 vec3::zxyy() const { return { z, x, y, y }; }
inline vec4 vec3::zxyz() const { return { z, x, y, z }; }
inline vec3 vec3::zxz() const { return { z, x, z }; }
inline vec4 vec3::zxzx() const { return { z, x, z, x }; }
inline vec4 vec3::zxzy() const { return { z, x, z, y }; }
inline vec4 vec3::zxzz() const { return { z, x, z, z }; }
inline vec2 vec3::zy() const { return { z, y }; }
inline vec3 vec3::zyx() const { return { z, y, x }; }
inline vec4 vec3::zyxx() const { return { z, y, x, x }; }
inline vec4 vec3::zyxy() const { return { z, y, x, y }; }
inline vec4 vec3::zyxz() const { return { z, y, x, z }; }
inline vec3 vec3::zyy() const { return { z, y, y }; }
inline vec4 vec3::zyyx() const { return { z, y, y, x }; }
inline vec4 vec3::zyyy() const { return { z, y, y, y }; }
inline vec4 vec3::zyyz() const { return { z, y, y, z }; }
inline vec3 vec3::zyz() const { return { z, y, z }; }
inline vec4 vec3::zyzx() const { return { z, y, z, x }; }
inline vec4 vec3::zyzy() const { return { z, y, z, y }; }
inline vec4 vec3::zyzz() const { return { z, y, z, z }; }
inline vec2 vec3::zz() const { return { z, z }; }
inline vec3 vec3::zzx() const { return { z, z, x }; }
inline vec4 vec3::zzxx() const { return { z, z, x, x }; }
inline vec4 vec3::zzxy() const { return { z, z, x, y }; }
inline vec4 vec3::zzxz() const { return { z, z, x, z }; }
inline vec3 vec3::zzy() const { return { z, z, y }; }
inline vec4 vec3::zzyx() const { return { z, z, y, x }; }
inline vec4 vec3::zzyy() const { return { z, z, y, y }; }
inline vec4 vec3::zzyz() const { return { z, z, y, z }; }
inline vec3 vec3::zzz() const { return { z, z, z }; }
inline vec4 vec3::zzzx() const { return { z, z, z, x }; }
inline vec4 vec3::zzzy() const { return { z, z, z, y }; }
inline vec4 vec3::zzzz() const { return { z, z, z, z }; }
inline void vec3::bg(const simdfloat& _val0, const simdfloat& _val1) { b = _val0; g = _val1; }
inline void vec3::bg(const vec2& _val) { b = _val.x; g = _val.y; }
inline void vec3::bg(const simdfloat& _val) { b = _val; g = _val; }
inline void vec3::bgr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { b = _val0; g = _val1; r = _val2; }
inline void vec3::bgr(const vec3& _val) { b = _val.x; g = _val.y; r = _val.z; }
inline void vec3::bgr(const simdfloat& _val) { b = _val; g = _val; r = _val; }
inline void vec3::br(const simdfloat& _val0, const simdfloat& _val1) { b = _val0; r = _val1; }
inline void vec3::br(const vec2& _val) { b = _val.x; r = _val.y; }
inline void vec3::br(const simdfloat& _val) { b = _val; r = _val; }
inline void vec3::brg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { b = _val0; r = _val1; g = _val2; }
inline void vec3::brg(const vec3& _val) { b = _val.x; r = _val.y; g = _val.z; }
inline void vec3::brg(const simdfloat& _val) { b = _val; r = _val; g = _val; }
inline void vec3::gb(const simdfloat& _val0, const simdfloat& _val1) { g = _val0; b = _val1; }
inline void vec3::gb(const vec2& _val) { g = _val.x; b = _val.y; }
inline void vec3::gb(const simdfloat& _val) { g = _val; b = _val; }
inline void vec3::gbr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { g = _val0; b = _val1; r = _val2; }
inline void vec3::gbr(const vec3& _val) { g = _val.x; b = _val.y; r = _val.z; }
inline void vec3::gbr(const simdfloat& _val) { g = _val; b = _val; r = _val; }
inline void vec3::gr(const simdfloat& _val0, const simdfloat& _val1) { g = _val0; r = _val1; }
inline void vec3::gr(const vec2& _val) { g = _val.x; r = _val.y; }
inline void vec3::gr(const simdfloat& _val) { g = _val; r = _val; }
inline void vec3::grb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { g = _val0; r = _val1; b = _val2; }
inline void vec3::grb(const vec3& _val) { g = _val.x; r = _val.y; b = _val.z; }
inline void vec3::grb(const simdfloat& _val) { g = _val; r = _val; b = _val; }
inline void vec3::rb(const simdfloat& _val0, const simdfloat& _val1) { r = _val0; b = _val1; }
inline void vec3::rb(const vec2& _val) { r = _val.x; b = _val.y; }
inline void vec3::rb(const simdfloat& _val) { r = _val; b = _val; }
inline void vec3::rbg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { r = _val0; b = _val1; g = _val2; }
inline void vec3::rbg(const vec3& _val) { r = _val.x; b = _val.y; g = _val.z; }
inline void vec3::rbg(const simdfloat& _val) { r = _val; b = _val; g = _val; }
inline void vec3::rg(const simdfloat& _val0, const simdfloat& _val1) { r = _val0; g = _val1; }
inline void vec3::rg(const vec2& _val) { r = _val.x; g = _val.y; }
inline void vec3::rg(const simdfloat& _val) { r = _val; g = _val; }
inline void vec3::rgb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { r = _val0; g = _val1; b = _val2; }
inline void vec3::rgb(const vec3& _val) { r = _val.x; g = _val.y; b = _val.z; }
inline void vec3::rgb(const simdfloat& _val) { r = _val; g = _val; b = _val; }
inline void vec3::st(const simdfloat& _val0, const simdfloat& _val1) { s = _val0; t = _val1; }
inline void vec3::st(const vec2& _val) { s = _val.s; t = _val.t; }
inline void vec3::st(const simdfloat& _val) { s = _val; t = _val; }
inline void vec3::stp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { s = _val0; t = _val1; p = _val2; }
inline void vec3::stp(const vec3& _val) { s = _val.s; t = _val.t; p = _val.p; }
inline void vec3::stp(const simdfloat& _val) { s = _val; t = _val; p = _val; }
inline void vec3::sp(const simdfloat& _val0, const simdfloat& _val1) { s = _val0; p = _val1; }
inline void vec3::sp(const vec2& _val) { s = _val.s; p = _val.t; }
inline void vec3::sp(const simdfloat& _val) { s = _val; p = _val; }
inline void vec3::spt(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { s = _val0; p = _val1; t = _val2; }
inline void vec3::spt(const vec3& _val) { s = _val.s; p = _val.t; t = _val.p; }
inline void vec3::spt(const simdfloat& _val) { s = _val; p = _val; t = _val; }
inline void vec3::ts(const simdfloat& _val0, const simdfloat& _val1) { t = _val0; s = _val1; }
inline void vec3::ts(const vec2& _val) { t = _val.s; s = _val.t; }
inline void vec3::ts(const simdfloat& _val) { t = _val; s = _val; }
inline void vec3::tsp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { t = _val0; s = _val1; p = _val2; }
inline void vec3::tsp(const vec3& _val) { t = _val.s; s = _val.t; p = _val.p; }
inline void vec3::tsp(const simdfloat& _val) { t = _val; s = _val; p = _val; }
inline void vec3::tp(const simdfloat& _val0, const simdfloat& _val1) { t = _val0; p = _val1; }
inline void vec3::tp(const vec2& _val) { t = _val.s; p = _val.t; }
inline void vec3::tp(const simdfloat& _val) { t = _val; p = _val; }
inline void vec3::tps(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { t = _val0; p = _val1; s = _val2; }
inline void vec3::tps(const vec3& _val) { t = _val.s; p = _val.t; s = _val.p; }
inline void vec3::tps(const simdfloat& _val) { t = _val; p = _val; s = _val; }
inline void vec3::ps(const simdfloat& _val0, const simdfloat& _val1) { p = _val0; s = _val1; }
inline void vec3::ps(const vec2& _val) { p = _val.s; s = _val.t; }
inline void vec3::ps(const simdfloat& _val) { p = _val; s = _val; }
inline void vec3::pst(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { p = _val0; s = _val1; t = _val2; }
inline void vec3::pst(const vec3& _val) { p = _val.s; s = _val.t; t = _val.p; }
inline void vec3::pst(const simdfloat& _val) { p = _val; s = _val; t = _val; }
inline void vec3::pt(const simdfloat& _val0, const simdfloat& _val1) { p = _val0; t = _val1; }
inline void vec3::pt(const vec2& _val) { p = _val.s; t = _val.t; }
inline void vec3::pt(const simdfloat& _val) { p = _val; t = _val; }
inline void vec3::pts(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { p = _val0; t = _val1; s = _val2; }
inline void vec3::pts(const vec3& _val) { p = _val.s; t = _val.t; s = _val.p; }
inline void vec3::pts(const simdfloat& _val) { p = _val; t = _val; s = _val; }

inline void vec3::xy(const simdfloat& _val0, const simdfloat& _val1) { x = _val0; y = _val1; }
inline void vec3::xy(const vec2& _val) { x = _val.x; y = _val.y; }
inline void vec3::xy(const simdfloat& _val) { x = _val; y = _val; }
inline void vec3::xyz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { x = _val0; y = _val1; z = _val2; }
inline void vec3::xyz(const vec3& _val) { x = _val.x; y = _val.y; z = _val.z; }
inline void vec3::xyz(const simdfloat& _val) { x = _val; y = _val; z = _val; }
inline void vec3::xz(const simdfloat& _val0, const simdfloat& _val1) { x = _val0; z = _val1; }
inline void vec3::xz(const vec2& _val) { x = _val.x; z = _val.y; }
inline void vec3::xz(const simdfloat& _val) { x = _val; z = _val; }
inline void vec3::xzy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { x = _val0; z = _val1; y = _val2; }
inline void vec3::xzy(const vec3& _val) { x = _val.x; z = _val.y; y = _val.z; }
inline void vec3::xzy(const simdfloat& _val) { x = _val; z = _val; y = _val; }
inline void vec3::yx(const simdfloat& _val0, const simdfloat& _val1) { y = _val0; x = _val1; }
inline void vec3::yx(const vec2& _val) { y = _val.x; x = _val.y; }
inline void vec3::yx(const simdfloat& _val) { y = _val; x = _val; }
inline void vec3::yxz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { y = _val0; x = _val1; z = _val2; }
inline void vec3::yxz(const vec3& _val) { y = _val.x; x = _val.y; z = _val.z; }
inline void vec3::yxz(const simdfloat& _val) { y = _val; x = _val; z = _val; }
inline void vec3::yz(const simdfloat& _val0, const simdfloat& _val1) { y = _val0; z = _val1; }
inline void vec3::yz(const vec2& _val) { y = _val.x; z = _val.y; }
inline void vec3::yz(const simdfloat& _val) { y = _val; z = _val; }
inline void vec3::yzx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { y = _val0; z = _val1; x = _val2; }
inline void vec3::yzx(const vec3& _val) { y = _val.x; z = _val.y; x = _val.z; }
inline void vec3::yzx(const simdfloat& _val) { y = _val; z = _val; x = _val; }
inline void vec3::zx(const simdfloat& _val0, const simdfloat& _val1) { z = _val0; x = _val1; }
inline void vec3::zx(const vec2& _val) { z = _val.x; x = _val.y; }
inline void vec3::zx(const simdfloat& _val) { z = _val; x = _val; }
inline void vec3::zxy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { z = _val0; x = _val1; y = _val2; }
inline void vec3::zxy(const vec3& _val) { z = _val.x; x = _val.y; y = _val.z; }
inline void vec3::zxy(const simdfloat& _val) { z = _val; x = _val; y = _val; }
inline void vec3::zy(const simdfloat& _val0, const simdfloat& _val1) { z = _val0; y = _val1; }
inline void vec3::zy(const vec2& _val) { z = _val.x; y = _val.y; }
inline void vec3::zy(const simdfloat& _val) { z = _val; y = _val; }
inline void vec3::zyx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { z = _val0; y = _val1; x = _val2; }
inline void vec3::zyx(const vec3& _val) { z = _val.x; y = _val.y; x = _val.z; }
inline void vec3::zyx(const simdfloat& _val) { z = _val; y = _val; x = _val; }

#pragma endregion


// cross-type assignment from ivec3 (components use simdfloat's own conversion operator)
inline vec3 vec3::operator=(const ivec3& _v) { x = _v.x; y = _v.y; z = _v.z; return *this; }

inline vec3 vec3::operator=(const vec4& _v) { x = _v.x; y = _v.y; z = _v.z; return *this; }

// constructors for vec3
inline vec3::vec3(const float& _f) { x = _f; y = _f; z = _f; }

inline vec3::vec3(const simdfloat& _f) { x = _f; y = _f; z = _f; }

inline vec3::vec3(const ivec3& _v) { x = _v.x; y = _v.y; z = _v.z; }

inline vec3::vec3(const simdfloat& _x, const simdfloat& _y, const simdfloat& _z) { x = _x; y = _y; z = _z; }

inline vec3::vec3(const simdfloat& _x, const vec2& _y) { x = _x; y = _y.x; z = _y.y; }

inline vec3::vec3(const vec2& _x, const simdfloat& _z) { x = _x.x; y = _x.y; z = _z; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec3>, int>>
vec3::vec3(const simdfloat& _x, const V& _v) { x = _x; y = _v.x; z = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec4>, int>>
vec3::vec3(const simdfloat& _x, const V& _v) { x = _x; y = _v.x; z = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec2>, int>>
vec3::vec3(const simdfloat& _x, const simdfloat& _y, const V& _v) { x = _x; y = _y; z = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec3>, int>>
vec3::vec3(const simdfloat& _x, const simdfloat& _y, const V& _v) { x = _x; y = _y; z = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec4>, int>>
vec3::vec3(const simdfloat& _x, const simdfloat& _y, const V& _v) { x = _x; y = _y; z = _v.x; }

#endif

