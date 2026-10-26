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
 
#ifndef SIMD_SWIZZLE_DVEC2_H
#define SIMD_SWIZZLE_DVEC2_H

#include "simd_dvec2.h"
#include "simd_dvec3.h"
#include "simd_dvec4.h"

#pragma region dvec2 swizzle implementations
// dvec2 swizzle implementations
inline dvec2 dvec2::gg() const { return { g, g }; }
inline dvec3 dvec2::ggg() const { return { g, g, g }; }
inline dvec4 dvec2::gggg() const { return { g, g, g, g }; }
inline dvec4 dvec2::gggr() const { return { g, g, g, r }; }
inline dvec3 dvec2::ggr() const { return { g, g, r }; }
inline dvec4 dvec2::ggrg() const { return { g, g, r, g }; }
inline dvec4 dvec2::ggrr() const { return { g, g, r, r }; }
inline dvec2 dvec2::gr() const { return { g, r }; }
inline dvec3 dvec2::grg() const { return { g, r, g }; }
inline dvec4 dvec2::grgg() const { return { g, r, g, g }; }
inline dvec4 dvec2::grgr() const { return { g, r, g, r }; }
inline dvec3 dvec2::grr() const { return { g, r, r }; }
inline dvec4 dvec2::grrg() const { return { g, r, r, g }; }
inline dvec4 dvec2::grrr() const { return { g, r, r, r }; }
inline dvec2 dvec2::rg() const { return { r, g }; }
inline dvec3 dvec2::rgg() const { return { r, g, g }; }
inline dvec4 dvec2::rggg() const { return { r, g, g, g }; }
inline dvec4 dvec2::rggr() const { return { r, g, g, r }; }
inline dvec3 dvec2::rgr() const { return { r, g, r }; }
inline dvec4 dvec2::rgrg() const { return { r, g, r, g }; }
inline dvec4 dvec2::rgrr() const { return { r, g, r, r }; }
inline dvec2 dvec2::rr() const { return { r, r }; }
inline dvec3 dvec2::rrg() const { return { r, r, g }; }
inline dvec4 dvec2::rrgg() const { return { r, r, g, g }; }
inline dvec4 dvec2::rrgr() const { return { r, r, g, r }; }
inline dvec3 dvec2::rrr() const { return { r, r, r }; }
inline dvec4 dvec2::rrrg() const { return { r, r, r, g }; }
inline dvec4 dvec2::rrrr() const { return { r, r, r, r }; }
inline dvec2 dvec2::ss() const { return { s, s }; }
inline dvec3 dvec2::sss() const { return { s, s, s }; }
inline dvec4 dvec2::ssss() const { return { s, s, s, s }; }
inline dvec4 dvec2::ssst() const { return { s, s, s, t }; }
inline dvec3 dvec2::sst() const { return { s, s, t }; }
inline dvec4 dvec2::ssts() const { return { s, s, t, s }; }
inline dvec4 dvec2::sstt() const { return { s, s, t, t }; }
inline dvec2 dvec2::st() const { return { s, t }; }
inline dvec3 dvec2::sts() const { return { s, t, s }; }
inline dvec4 dvec2::stss() const { return { s, t, s, s }; }
inline dvec4 dvec2::stst() const { return { s, t, s, t }; }
inline dvec3 dvec2::stt() const { return { s, t, t }; }
inline dvec4 dvec2::stts() const { return { s, t, t, s }; }
inline dvec4 dvec2::sttt() const { return { s, t, t, t }; }
inline dvec2 dvec2::ts() const { return { t, s }; }
inline dvec3 dvec2::tss() const { return { t, s, s }; }
inline dvec4 dvec2::tsss() const { return { t, s, s, s }; }
inline dvec4 dvec2::tsst() const { return { t, s, s, t }; }
inline dvec3 dvec2::tst() const { return { t, s, t }; }
inline dvec4 dvec2::tsts() const { return { t, s, t, s }; }
inline dvec4 dvec2::tstt() const { return { t, s, t, t }; }
inline dvec2 dvec2::tt() const { return { t, t }; }
inline dvec3 dvec2::tts() const { return { t, t, s }; }
inline dvec4 dvec2::ttss() const { return { t, t, s, s }; }
inline dvec4 dvec2::ttst() const { return { t, t, s, t }; }
inline dvec3 dvec2::ttt() const { return { t, t, t }; }
inline dvec4 dvec2::ttts() const { return { t, t, t, s }; }
inline dvec4 dvec2::tttt() const { return { t, t, t, t }; }
inline dvec2 dvec2::xx() const { return { x, x }; }
inline dvec3 dvec2::xxx() const { return { x, x, x }; }
inline dvec4 dvec2::xxxx() const { return { x, x, x, x }; }
inline dvec4 dvec2::xxxy() const { return { x, x, x, y }; }
inline dvec3 dvec2::xxy() const { return { x, x, y }; }
inline dvec4 dvec2::xxyx() const { return { x, x, y, x }; }
inline dvec4 dvec2::xxyy() const { return { x, x, y, y }; }
inline dvec2 dvec2::xy() const { return { x, y }; }
inline dvec3 dvec2::xyx() const { return { x, y, x }; }
inline dvec4 dvec2::xyxx() const { return { x, y, x, x }; }
inline dvec4 dvec2::xyxy() const { return { x, y, x, y }; }
inline dvec3 dvec2::xyy() const { return { x, y, y }; }
inline dvec4 dvec2::xyyx() const { return { x, y, y, x }; }
inline dvec4 dvec2::xyyy() const { return { x, y, y, y }; }
inline dvec2 dvec2::yx() const { return { y, x }; }
inline dvec3 dvec2::yxx() const { return { y, x, x }; }
inline dvec4 dvec2::yxxx() const { return { y, x, x, x }; }
inline dvec4 dvec2::yxxy() const { return { y, x, x, y }; }
inline dvec3 dvec2::yxy() const { return { y, x, y }; }
inline dvec4 dvec2::yxyx() const { return { y, x, y, x }; }
inline dvec4 dvec2::yxyy() const { return { y, x, y, y }; }
inline dvec2 dvec2::yy() const { return { y, y }; }
inline dvec3 dvec2::yyx() const { return { y, y, x }; }
inline dvec4 dvec2::yyxx() const { return { y, y, x, x }; }
inline dvec4 dvec2::yyxy() const { return { y, y, x, y }; }
inline dvec3 dvec2::yyy() const { return { y, y, y }; }
inline dvec4 dvec2::yyyx() const { return { y, y, y, x }; }
inline dvec4 dvec2::yyyy() const { return { y, y, y, y }; }
inline void dvec2::gr(const simddouble& _val0, const simddouble& _val1) { g = _val0; r = _val1; }
inline void dvec2::gr(const dvec2& _val) { g = _val.x; r = _val.y; }
inline void dvec2::gr(const simddouble& _val) { g = _val; r = _val; }
inline void dvec2::rg(const simddouble& _val0, const simddouble& _val1) { r = _val0; g = _val1; }
inline void dvec2::rg(const dvec2& _val) { r = _val.x; g = _val.y; }
inline void dvec2::rg(const simddouble& _val) { r = _val; g = _val; }
inline void dvec2::st(const simddouble& _val0, const simddouble& _val1) { s = _val0; t = _val1; }
inline void dvec2::st(const dvec2& _val) { s = _val.s; t = _val.t; }
inline void dvec2::st(const simddouble& _val) { s = _val; t = _val; }
inline void dvec2::ts(const simddouble& _val0, const simddouble& _val1) { t = _val0; s = _val1; }
inline void dvec2::ts(const dvec2& _val) { t = _val.s; s = _val.t; }
inline void dvec2::ts(const simddouble& _val) { t = _val; s = _val; }
inline void dvec2::xy(const simddouble& _val0, const simddouble& _val1) { x = _val0; y = _val1; }
inline void dvec2::xy(const dvec2& _val) { x = _val.x; y = _val.y; }
inline void dvec2::xy(const simddouble& _val) { x = _val; y = _val; }
inline void dvec2::yx(const simddouble& _val0, const simddouble& _val1) { y = _val0; x = _val1; }
inline void dvec2::yx(const dvec2& _val) { y = _val.x; x = _val.y; }
inline void dvec2::yx(const simddouble& _val) { y = _val; x = _val; }

#pragma endregion

inline dvec2 dvec2::operator=(const dvec3& _v) { x = _v.x; y = _v.y; return *this; }

inline dvec2 dvec2::operator=(const dvec4& _v) { x = _v.x; y = _v.y; return *this; }

// constructors for dvec2
inline dvec2::dvec2(const double& _f) { x = _f; y = _f; }

inline dvec2::dvec2(const simddouble& _f) { x = _f; y = _f; }

inline dvec2::dvec2(const simddouble& _x, const simddouble& _y) { x = _x; y = _y; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec3>, int>>
dvec2::dvec2(const simddouble& _x, const V& _v) { x = _x; y = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec4>, int>>
dvec2::dvec2(const simddouble& _x, const V& _v) { x = _x; y = _v.x; }


#endif



