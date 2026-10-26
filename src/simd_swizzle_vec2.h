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
 
#ifndef SIMD_SWIZZLE_VEC2_H
#define SIMD_SWIZZLE_VEC2_H

#include "simd_vec2.h"
#include "simd_vec3.h"
#include "simd_vec4.h"
#include "simd_ivec2.h"

#pragma region vec2 swizzle implementations
// vec2 swizzle implementations
inline vec2 vec2::gg() const { return { g, g }; }
inline vec3 vec2::ggg() const { return { g, g, g }; }
inline vec4 vec2::gggg() const { return { g, g, g, g }; }
inline vec4 vec2::gggr() const { return { g, g, g, r }; }
inline vec3 vec2::ggr() const { return { g, g, r }; }
inline vec4 vec2::ggrg() const { return { g, g, r, g }; }
inline vec4 vec2::ggrr() const { return { g, g, r, r }; }
inline vec2 vec2::gr() const { return { g, r }; }
inline vec3 vec2::grg() const { return { g, r, g }; }
inline vec4 vec2::grgg() const { return { g, r, g, g }; }
inline vec4 vec2::grgr() const { return { g, r, g, r }; }
inline vec3 vec2::grr() const { return { g, r, r }; }
inline vec4 vec2::grrg() const { return { g, r, r, g }; }
inline vec4 vec2::grrr() const { return { g, r, r, r }; }
inline vec2 vec2::rg() const { return { r, g }; }
inline vec3 vec2::rgg() const { return { r, g, g }; }
inline vec4 vec2::rggg() const { return { r, g, g, g }; }
inline vec4 vec2::rggr() const { return { r, g, g, r }; }
inline vec3 vec2::rgr() const { return { r, g, r }; }
inline vec4 vec2::rgrg() const { return { r, g, r, g }; }
inline vec4 vec2::rgrr() const { return { r, g, r, r }; }
inline vec2 vec2::rr() const { return { r, r }; }
inline vec3 vec2::rrg() const { return { r, r, g }; }
inline vec4 vec2::rrgg() const { return { r, r, g, g }; }
inline vec4 vec2::rrgr() const { return { r, r, g, r }; }
inline vec3 vec2::rrr() const { return { r, r, r }; }
inline vec4 vec2::rrrg() const { return { r, r, r, g }; }
inline vec4 vec2::rrrr() const { return { r, r, r, r }; }
inline vec2 vec2::ss() const { return { s, s }; }
inline vec3 vec2::sss() const { return { s, s, s }; }
inline vec4 vec2::ssss() const { return { s, s, s, s }; }
inline vec4 vec2::ssst() const { return { s, s, s, t }; }
inline vec3 vec2::sst() const { return { s, s, t }; }
inline vec4 vec2::ssts() const { return { s, s, t, s }; }
inline vec4 vec2::sstt() const { return { s, s, t, t }; }
inline vec2 vec2::st() const { return { s, t }; }
inline vec3 vec2::sts() const { return { s, t, s }; }
inline vec4 vec2::stss() const { return { s, t, s, s }; }
inline vec4 vec2::stst() const { return { s, t, s, t }; }
inline vec3 vec2::stt() const { return { s, t, t }; }
inline vec4 vec2::stts() const { return { s, t, t, s }; }
inline vec4 vec2::sttt() const { return { s, t, t, t }; }
inline vec2 vec2::ts() const { return { t, s }; }
inline vec3 vec2::tss() const { return { t, s, s }; }
inline vec4 vec2::tsss() const { return { t, s, s, s }; }
inline vec4 vec2::tsst() const { return { t, s, s, t }; }
inline vec3 vec2::tst() const { return { t, s, t }; }
inline vec4 vec2::tsts() const { return { t, s, t, s }; }
inline vec4 vec2::tstt() const { return { t, s, t, t }; }
inline vec2 vec2::tt() const { return { t, t }; }
inline vec3 vec2::tts() const { return { t, t, s }; }
inline vec4 vec2::ttss() const { return { t, t, s, s }; }
inline vec4 vec2::ttst() const { return { t, t, s, t }; }
inline vec3 vec2::ttt() const { return { t, t, t }; }
inline vec4 vec2::ttts() const { return { t, t, t, s }; }
inline vec4 vec2::tttt() const { return { t, t, t, t }; }
inline vec2 vec2::xx() const { return { x, x }; }
inline vec3 vec2::xxx() const { return { x, x, x }; }
inline vec4 vec2::xxxx() const { return { x, x, x, x }; }
inline vec4 vec2::xxxy() const { return { x, x, x, y }; }
inline vec3 vec2::xxy() const { return { x, x, y }; }
inline vec4 vec2::xxyx() const { return { x, x, y, x }; }
inline vec4 vec2::xxyy() const { return { x, x, y, y }; }
inline vec2 vec2::xy() const { return { x, y }; }
inline vec3 vec2::xyx() const { return { x, y, x }; }
inline vec4 vec2::xyxx() const { return { x, y, x, x }; }
inline vec4 vec2::xyxy() const { return { x, y, x, y }; }
inline vec3 vec2::xyy() const { return { x, y, y }; }
inline vec4 vec2::xyyx() const { return { x, y, y, x }; }
inline vec4 vec2::xyyy() const { return { x, y, y, y }; }
inline vec2 vec2::yx() const { return { y, x }; }
inline vec3 vec2::yxx() const { return { y, x, x }; }
inline vec4 vec2::yxxx() const { return { y, x, x, x }; }
inline vec4 vec2::yxxy() const { return { y, x, x, y }; }
inline vec3 vec2::yxy() const { return { y, x, y }; }
inline vec4 vec2::yxyx() const { return { y, x, y, x }; }
inline vec4 vec2::yxyy() const { return { y, x, y, y }; }
inline vec2 vec2::yy() const { return { y, y }; }
inline vec3 vec2::yyx() const { return { y, y, x }; }
inline vec4 vec2::yyxx() const { return { y, y, x, x }; }
inline vec4 vec2::yyxy() const { return { y, y, x, y }; }
inline vec3 vec2::yyy() const { return { y, y, y }; }
inline vec4 vec2::yyyx() const { return { y, y, y, x }; }
inline vec4 vec2::yyyy() const { return { y, y, y, y }; }
inline void vec2::gr(const simdfloat& _val0, const simdfloat& _val1) { g = _val0; r = _val1; }
inline void vec2::gr(const vec2& _val) { g = _val.x; r = _val.y; }
inline void vec2::gr(const simdfloat& _val) { g = _val; r = _val; }
inline void vec2::rg(const simdfloat& _val0, const simdfloat& _val1) { r = _val0; g = _val1; }
inline void vec2::rg(const vec2& _val) { r = _val.x; g = _val.y; }
inline void vec2::rg(const simdfloat& _val) { r = _val; g = _val; }
inline void vec2::st(const simdfloat& _val0, const simdfloat& _val1) { s = _val0; t = _val1; }
inline void vec2::st(const vec2& _val) { s = _val.s; t = _val.t; }
inline void vec2::st(const simdfloat& _val) { s = _val; t = _val; }
inline void vec2::ts(const simdfloat& _val0, const simdfloat& _val1) { t = _val0; s = _val1; }
inline void vec2::ts(const vec2& _val) { t = _val.s; s = _val.t; }
inline void vec2::ts(const simdfloat& _val) { t = _val; s = _val; }
inline void vec2::xy(const simdfloat& _val0, const simdfloat& _val1) { x = _val0; y = _val1; }
inline void vec2::xy(const vec2& _val) { x = _val.x; y = _val.y; }
inline void vec2::xy(const simdfloat& _val) { x = _val; y = _val; }
inline void vec2::yx(const simdfloat& _val0, const simdfloat& _val1) { y = _val0; x = _val1; }
inline void vec2::yx(const vec2& _val) { y = _val.x; x = _val.y; }
inline void vec2::yx(const simdfloat& _val) { y = _val; x = _val; }

#pragma endregion

// cross-type assignment from ivec2 (components use simdfloat's own conversion operator)
inline vec2 vec2::operator=(const ivec2& _v) { x = _v.x; y = _v.y; return *this; }

inline vec2 vec2::operator=(const vec3& _v) { x = _v.x; y = _v.y; return *this; }

inline vec2 vec2::operator=(const vec4& _v) { x = _v.x; y = _v.y; return *this; }

// constructors for vec2
inline vec2::vec2(const float& _f) { x = _f; y = _f; }

inline vec2::vec2(const simdfloat& _f) { x = _f; y = _f; }

inline vec2::vec2(const ivec2& _v) { x = _v.x; y = _v.y; }

inline vec2::vec2(const simdfloat& _x, const simdfloat& _y) { x = _x; y = _y; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec3>, int>>
vec2::vec2(const simdfloat& _x, const V& _v) { x = _x; y = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec4>, int>>
vec2::vec2(const simdfloat& _x, const V& _v) { x = _x; y = _v.x; }

#endif


