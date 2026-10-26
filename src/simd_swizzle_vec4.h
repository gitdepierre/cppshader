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
 
#ifndef SIMD_SWIZZLE_VEC4_H
#define SIMD_SWIZZLE_VEC4_H

#include "simd_vec2.h"
#include "simd_vec3.h"
#include "simd_vec4.h"
#include "simd_ivec4.h"

#pragma region vec4 swizzle implementations

// vec4 swizzle implementations
inline vec2 vec4::aa() const { return { a, a }; }
inline vec3 vec4::aaa() const { return { a, a, a }; }
inline vec4 vec4::aaaa() const { return { a, a, a, a }; }
inline vec4 vec4::aaab() const { return { a, a, a, b }; }
inline vec4 vec4::aaag() const { return { a, a, a, g }; }
inline vec4 vec4::aaar() const { return { a, a, a, r }; }
inline vec3 vec4::aab() const { return { a, a, b }; }
inline vec4 vec4::aaba() const { return { a, a, b, a }; }
inline vec4 vec4::aabb() const { return { a, a, b, b }; }
inline vec4 vec4::aabg() const { return { a, a, b, g }; }
inline vec4 vec4::aabr() const { return { a, a, b, r }; }
inline vec3 vec4::aag() const { return { a, a, g }; }
inline vec4 vec4::aaga() const { return { a, a, g, a }; }
inline vec4 vec4::aagb() const { return { a, a, g, b }; }
inline vec4 vec4::aagg() const { return { a, a, g, g }; }
inline vec4 vec4::aagr() const { return { a, a, g, r }; }
inline vec3 vec4::aar() const { return { a, a, r }; }
inline vec4 vec4::aara() const { return { a, a, r, a }; }
inline vec4 vec4::aarb() const { return { a, a, r, b }; }
inline vec4 vec4::aarg() const { return { a, a, r, g }; }
inline vec4 vec4::aarr() const { return { a, a, r, r }; }
inline vec2 vec4::ab() const { return { a, b }; }
inline vec3 vec4::aba() const { return { a, b, a }; }
inline vec4 vec4::abaa() const { return { a, b, a, a }; }
inline vec4 vec4::abab() const { return { a, b, a, b }; }
inline vec4 vec4::abag() const { return { a, b, a, g }; }
inline vec4 vec4::abar() const { return { a, b, a, r }; }
inline vec3 vec4::abb() const { return { a, b, b }; }
inline vec4 vec4::abba() const { return { a, b, b, a }; }
inline vec4 vec4::abbb() const { return { a, b, b, b }; }
inline vec4 vec4::abbg() const { return { a, b, b, g }; }
inline vec4 vec4::abbr() const { return { a, b, b, r }; }
inline vec3 vec4::abg() const { return { a, b, g }; }
inline vec4 vec4::abga() const { return { a, b, g, a }; }
inline vec4 vec4::abgb() const { return { a, b, g, b }; }
inline vec4 vec4::abgg() const { return { a, b, g, g }; }
inline vec4 vec4::abgr() const { return { a, b, g, r }; }
inline vec3 vec4::abr() const { return { a, b, r }; }
inline vec4 vec4::abra() const { return { a, b, r, a }; }
inline vec4 vec4::abrb() const { return { a, b, r, b }; }
inline vec4 vec4::abrg() const { return { a, b, r, g }; }
inline vec4 vec4::abrr() const { return { a, b, r, r }; }
inline vec2 vec4::ag() const { return { a, g }; }
inline vec3 vec4::aga() const { return { a, g, a }; }
inline vec4 vec4::agaa() const { return { a, g, a, a }; }
inline vec4 vec4::agab() const { return { a, g, a, b }; }
inline vec4 vec4::agag() const { return { a, g, a, g }; }
inline vec4 vec4::agar() const { return { a, g, a, r }; }
inline vec3 vec4::agb() const { return { a, g, b }; }
inline vec4 vec4::agba() const { return { a, g, b, a }; }
inline vec4 vec4::agbb() const { return { a, g, b, b }; }
inline vec4 vec4::agbg() const { return { a, g, b, g }; }
inline vec4 vec4::agbr() const { return { a, g, b, r }; }
inline vec3 vec4::agg() const { return { a, g, g }; }
inline vec4 vec4::agga() const { return { a, g, g, a }; }
inline vec4 vec4::aggb() const { return { a, g, g, b }; }
inline vec4 vec4::aggg() const { return { a, g, g, g }; }
inline vec4 vec4::aggr() const { return { a, g, g, r }; }
inline vec3 vec4::agr() const { return { a, g, r }; }
inline vec4 vec4::agra() const { return { a, g, r, a }; }
inline vec4 vec4::agrb() const { return { a, g, r, b }; }
inline vec4 vec4::agrg() const { return { a, g, r, g }; }
inline vec4 vec4::agrr() const { return { a, g, r, r }; }
inline vec2 vec4::ar() const { return { a, r }; }
inline vec3 vec4::ara() const { return { a, r, a }; }
inline vec4 vec4::araa() const { return { a, r, a, a }; }
inline vec4 vec4::arab() const { return { a, r, a, b }; }
inline vec4 vec4::arag() const { return { a, r, a, g }; }
inline vec4 vec4::arar() const { return { a, r, a, r }; }
inline vec3 vec4::arb() const { return { a, r, b }; }
inline vec4 vec4::arba() const { return { a, r, b, a }; }
inline vec4 vec4::arbb() const { return { a, r, b, b }; }
inline vec4 vec4::arbg() const { return { a, r, b, g }; }
inline vec4 vec4::arbr() const { return { a, r, b, r }; }
inline vec3 vec4::arg() const { return { a, r, g }; }
inline vec4 vec4::arga() const { return { a, r, g, a }; }
inline vec4 vec4::argb() const { return { a, r, g, b }; }
inline vec4 vec4::argg() const { return { a, r, g, g }; }
inline vec4 vec4::argr() const { return { a, r, g, r }; }
inline vec3 vec4::arr() const { return { a, r, r }; }
inline vec4 vec4::arra() const { return { a, r, r, a }; }
inline vec4 vec4::arrb() const { return { a, r, r, b }; }
inline vec4 vec4::arrg() const { return { a, r, r, g }; }
inline vec4 vec4::arrr() const { return { a, r, r, r }; }
inline vec2 vec4::ba() const { return { b, a }; }
inline vec3 vec4::baa() const { return { b, a, a }; }
inline vec4 vec4::baaa() const { return { b, a, a, a }; }
inline vec4 vec4::baab() const { return { b, a, a, b }; }
inline vec4 vec4::baag() const { return { b, a, a, g }; }
inline vec4 vec4::baar() const { return { b, a, a, r }; }
inline vec3 vec4::bab() const { return { b, a, b }; }
inline vec4 vec4::baba() const { return { b, a, b, a }; }
inline vec4 vec4::babb() const { return { b, a, b, b }; }
inline vec4 vec4::babg() const { return { b, a, b, g }; }
inline vec4 vec4::babr() const { return { b, a, b, r }; }
inline vec3 vec4::bag() const { return { b, a, g }; }
inline vec4 vec4::baga() const { return { b, a, g, a }; }
inline vec4 vec4::bagb() const { return { b, a, g, b }; }
inline vec4 vec4::bagg() const { return { b, a, g, g }; }
inline vec4 vec4::bagr() const { return { b, a, g, r }; }
inline vec3 vec4::bar() const { return { b, a, r }; }
inline vec4 vec4::bara() const { return { b, a, r, a }; }
inline vec4 vec4::barb() const { return { b, a, r, b }; }
inline vec4 vec4::barg() const { return { b, a, r, g }; }
inline vec4 vec4::barr() const { return { b, a, r, r }; }
inline vec2 vec4::bb() const { return { b, b }; }
inline vec3 vec4::bba() const { return { b, b, a }; }
inline vec4 vec4::bbaa() const { return { b, b, a, a }; }
inline vec4 vec4::bbab() const { return { b, b, a, b }; }
inline vec4 vec4::bbag() const { return { b, b, a, g }; }
inline vec4 vec4::bbar() const { return { b, b, a, r }; }
inline vec3 vec4::bbb() const { return { b, b, b }; }
inline vec4 vec4::bbba() const { return { b, b, b, a }; }
inline vec4 vec4::bbbb() const { return { b, b, b, b }; }
inline vec4 vec4::bbbg() const { return { b, b, b, g }; }
inline vec4 vec4::bbbr() const { return { b, b, b, r }; }
inline vec3 vec4::bbg() const { return { b, b, g }; }
inline vec4 vec4::bbga() const { return { b, b, g, a }; }
inline vec4 vec4::bbgb() const { return { b, b, g, b }; }
inline vec4 vec4::bbgg() const { return { b, b, g, g }; }
inline vec4 vec4::bbgr() const { return { b, b, g, r }; }
inline vec3 vec4::bbr() const { return { b, b, r }; }
inline vec4 vec4::bbra() const { return { b, b, r, a }; }
inline vec4 vec4::bbrb() const { return { b, b, r, b }; }
inline vec4 vec4::bbrg() const { return { b, b, r, g }; }
inline vec4 vec4::bbrr() const { return { b, b, r, r }; }
inline vec2 vec4::bg() const { return { b, g }; }
inline vec3 vec4::bga() const { return { b, g, a }; }
inline vec4 vec4::bgaa() const { return { b, g, a, a }; }
inline vec4 vec4::bgab() const { return { b, g, a, b }; }
inline vec4 vec4::bgag() const { return { b, g, a, g }; }
inline vec4 vec4::bgar() const { return { b, g, a, r }; }
inline vec3 vec4::bgb() const { return { b, g, b }; }
inline vec4 vec4::bgba() const { return { b, g, b, a }; }
inline vec4 vec4::bgbb() const { return { b, g, b, b }; }
inline vec4 vec4::bgbg() const { return { b, g, b, g }; }
inline vec4 vec4::bgbr() const { return { b, g, b, r }; }
inline vec3 vec4::bgg() const { return { b, g, g }; }
inline vec4 vec4::bgga() const { return { b, g, g, a }; }
inline vec4 vec4::bggb() const { return { b, g, g, b }; }
inline vec4 vec4::bggg() const { return { b, g, g, g }; }
inline vec4 vec4::bggr() const { return { b, g, g, r }; }
inline vec3 vec4::bgr() const { return { b, g, r }; }
inline vec4 vec4::bgra() const { return { b, g, r, a }; }
inline vec4 vec4::bgrb() const { return { b, g, r, b }; }
inline vec4 vec4::bgrg() const { return { b, g, r, g }; }
inline vec4 vec4::bgrr() const { return { b, g, r, r }; }
inline vec2 vec4::br() const { return { b, r }; }
inline vec3 vec4::bra() const { return { b, r, a }; }
inline vec4 vec4::braa() const { return { b, r, a, a }; }
inline vec4 vec4::brab() const { return { b, r, a, b }; }
inline vec4 vec4::brag() const { return { b, r, a, g }; }
inline vec4 vec4::brar() const { return { b, r, a, r }; }
inline vec3 vec4::brb() const { return { b, r, b }; }
inline vec4 vec4::brba() const { return { b, r, b, a }; }
inline vec4 vec4::brbb() const { return { b, r, b, b }; }
inline vec4 vec4::brbg() const { return { b, r, b, g }; }
inline vec4 vec4::brbr() const { return { b, r, b, r }; }
inline vec3 vec4::brg() const { return { b, r, g }; }
inline vec4 vec4::brga() const { return { b, r, g, a }; }
inline vec4 vec4::brgb() const { return { b, r, g, b }; }
inline vec4 vec4::brgg() const { return { b, r, g, g }; }
inline vec4 vec4::brgr() const { return { b, r, g, r }; }
inline vec3 vec4::brr() const { return { b, r, r }; }
inline vec4 vec4::brra() const { return { b, r, r, a }; }
inline vec4 vec4::brrb() const { return { b, r, r, b }; }
inline vec4 vec4::brrg() const { return { b, r, r, g }; }
inline vec4 vec4::brrr() const { return { b, r, r, r }; }
inline vec2 vec4::ga() const { return { g, a }; }
inline vec3 vec4::gaa() const { return { g, a, a }; }
inline vec4 vec4::gaaa() const { return { g, a, a, a }; }
inline vec4 vec4::gaab() const { return { g, a, a, b }; }
inline vec4 vec4::gaag() const { return { g, a, a, g }; }
inline vec4 vec4::gaar() const { return { g, a, a, r }; }
inline vec3 vec4::gab() const { return { g, a, b }; }
inline vec4 vec4::gaba() const { return { g, a, b, a }; }
inline vec4 vec4::gabb() const { return { g, a, b, b }; }
inline vec4 vec4::gabg() const { return { g, a, b, g }; }
inline vec4 vec4::gabr() const { return { g, a, b, r }; }
inline vec3 vec4::gag() const { return { g, a, g }; }
inline vec4 vec4::gaga() const { return { g, a, g, a }; }
inline vec4 vec4::gagb() const { return { g, a, g, b }; }
inline vec4 vec4::gagg() const { return { g, a, g, g }; }
inline vec4 vec4::gagr() const { return { g, a, g, r }; }
inline vec3 vec4::gar() const { return { g, a, r }; }
inline vec4 vec4::gara() const { return { g, a, r, a }; }
inline vec4 vec4::garb() const { return { g, a, r, b }; }
inline vec4 vec4::garg() const { return { g, a, r, g }; }
inline vec4 vec4::garr() const { return { g, a, r, r }; }
inline vec2 vec4::gb() const { return { g, b }; }
inline vec3 vec4::gba() const { return { g, b, a }; }
inline vec4 vec4::gbaa() const { return { g, b, a, a }; }
inline vec4 vec4::gbab() const { return { g, b, a, b }; }
inline vec4 vec4::gbag() const { return { g, b, a, g }; }
inline vec4 vec4::gbar() const { return { g, b, a, r }; }
inline vec3 vec4::gbb() const { return { g, b, b }; }
inline vec4 vec4::gbba() const { return { g, b, b, a }; }
inline vec4 vec4::gbbb() const { return { g, b, b, b }; }
inline vec4 vec4::gbbg() const { return { g, b, b, g }; }
inline vec4 vec4::gbbr() const { return { g, b, b, r }; }
inline vec3 vec4::gbg() const { return { g, b, g }; }
inline vec4 vec4::gbga() const { return { g, b, g, a }; }
inline vec4 vec4::gbgb() const { return { g, b, g, b }; }
inline vec4 vec4::gbgg() const { return { g, b, g, g }; }
inline vec4 vec4::gbgr() const { return { g, b, g, r }; }
inline vec3 vec4::gbr() const { return { g, b, r }; }
inline vec4 vec4::gbra() const { return { g, b, r, a }; }
inline vec4 vec4::gbrb() const { return { g, b, r, b }; }
inline vec4 vec4::gbrg() const { return { g, b, r, g }; }
inline vec4 vec4::gbrr() const { return { g, b, r, r }; }
inline vec2 vec4::gg() const { return { g, g }; }
inline vec3 vec4::gga() const { return { g, g, a }; }
inline vec4 vec4::ggaa() const { return { g, g, a, a }; }
inline vec4 vec4::ggab() const { return { g, g, a, b }; }
inline vec4 vec4::ggag() const { return { g, g, a, g }; }
inline vec4 vec4::ggar() const { return { g, g, a, r }; }
inline vec3 vec4::ggb() const { return { g, g, b }; }
inline vec4 vec4::ggba() const { return { g, g, b, a }; }
inline vec4 vec4::ggbb() const { return { g, g, b, b }; }
inline vec4 vec4::ggbg() const { return { g, g, b, g }; }
inline vec4 vec4::ggbr() const { return { g, g, b, r }; }
inline vec3 vec4::ggg() const { return { g, g, g }; }
inline vec4 vec4::ggga() const { return { g, g, g, a }; }
inline vec4 vec4::gggb() const { return { g, g, g, b }; }
inline vec4 vec4::gggg() const { return { g, g, g, g }; }
inline vec4 vec4::gggr() const { return { g, g, g, r }; }
inline vec3 vec4::ggr() const { return { g, g, r }; }
inline vec4 vec4::ggra() const { return { g, g, r, a }; }
inline vec4 vec4::ggrb() const { return { g, g, r, b }; }
inline vec4 vec4::ggrg() const { return { g, g, r, g }; }
inline vec4 vec4::ggrr() const { return { g, g, r, r }; }
inline vec2 vec4::gr() const { return { g, r }; }
inline vec3 vec4::gra() const { return { g, r, a }; }
inline vec4 vec4::graa() const { return { g, r, a, a }; }
inline vec4 vec4::grab() const { return { g, r, a, b }; }
inline vec4 vec4::grag() const { return { g, r, a, g }; }
inline vec4 vec4::grar() const { return { g, r, a, r }; }
inline vec3 vec4::grb() const { return { g, r, b }; }
inline vec4 vec4::grba() const { return { g, r, b, a }; }
inline vec4 vec4::grbb() const { return { g, r, b, b }; }
inline vec4 vec4::grbg() const { return { g, r, b, g }; }
inline vec4 vec4::grbr() const { return { g, r, b, r }; }
inline vec3 vec4::grg() const { return { g, r, g }; }
inline vec4 vec4::grga() const { return { g, r, g, a }; }
inline vec4 vec4::grgb() const { return { g, r, g, b }; }
inline vec4 vec4::grgg() const { return { g, r, g, g }; }
inline vec4 vec4::grgr() const { return { g, r, g, r }; }
inline vec3 vec4::grr() const { return { g, r, r }; }
inline vec4 vec4::grra() const { return { g, r, r, a }; }
inline vec4 vec4::grrb() const { return { g, r, r, b }; }
inline vec4 vec4::grrg() const { return { g, r, r, g }; }
inline vec4 vec4::grrr() const { return { g, r, r, r }; }
inline vec2 vec4::ra() const { return { r, a }; }
inline vec3 vec4::raa() const { return { r, a, a }; }
inline vec4 vec4::raaa() const { return { r, a, a, a }; }
inline vec4 vec4::raab() const { return { r, a, a, b }; }
inline vec4 vec4::raag() const { return { r, a, a, g }; }
inline vec4 vec4::raar() const { return { r, a, a, r }; }
inline vec3 vec4::rab() const { return { r, a, b }; }
inline vec4 vec4::raba() const { return { r, a, b, a }; }
inline vec4 vec4::rabb() const { return { r, a, b, b }; }
inline vec4 vec4::rabg() const { return { r, a, b, g }; }
inline vec4 vec4::rabr() const { return { r, a, b, r }; }
inline vec3 vec4::rag() const { return { r, a, g }; }
inline vec4 vec4::raga() const { return { r, a, g, a }; }
inline vec4 vec4::ragb() const { return { r, a, g, b }; }
inline vec4 vec4::ragg() const { return { r, a, g, g }; }
inline vec4 vec4::ragr() const { return { r, a, g, r }; }
inline vec3 vec4::rar() const { return { r, a, r }; }
inline vec4 vec4::rara() const { return { r, a, r, a }; }
inline vec4 vec4::rarb() const { return { r, a, r, b }; }
inline vec4 vec4::rarg() const { return { r, a, r, g }; }
inline vec4 vec4::rarr() const { return { r, a, r, r }; }
inline vec2 vec4::rb() const { return { r, b }; }
inline vec3 vec4::rba() const { return { r, b, a }; }
inline vec4 vec4::rbaa() const { return { r, b, a, a }; }
inline vec4 vec4::rbab() const { return { r, b, a, b }; }
inline vec4 vec4::rbag() const { return { r, b, a, g }; }
inline vec4 vec4::rbar() const { return { r, b, a, r }; }
inline vec3 vec4::rbb() const { return { r, b, b }; }
inline vec4 vec4::rbba() const { return { r, b, b, a }; }
inline vec4 vec4::rbbb() const { return { r, b, b, b }; }
inline vec4 vec4::rbbg() const { return { r, b, b, g }; }
inline vec4 vec4::rbbr() const { return { r, b, b, r }; }
inline vec3 vec4::rbg() const { return { r, b, g }; }
inline vec4 vec4::rbga() const { return { r, b, g, a }; }
inline vec4 vec4::rbgb() const { return { r, b, g, b }; }
inline vec4 vec4::rbgg() const { return { r, b, g, g }; }
inline vec4 vec4::rbgr() const { return { r, b, g, r }; }
inline vec3 vec4::rbr() const { return { r, b, r }; }
inline vec4 vec4::rbra() const { return { r, b, r, a }; }
inline vec4 vec4::rbrb() const { return { r, b, r, b }; }
inline vec4 vec4::rbrg() const { return { r, b, r, g }; }
inline vec4 vec4::rbrr() const { return { r, b, r, r }; }
inline vec2 vec4::rg() const { return { r, g }; }
inline vec3 vec4::rga() const { return { r, g, a }; }
inline vec4 vec4::rgaa() const { return { r, g, a, a }; }
inline vec4 vec4::rgab() const { return { r, g, a, b }; }
inline vec4 vec4::rgag() const { return { r, g, a, g }; }
inline vec4 vec4::rgar() const { return { r, g, a, r }; }
inline vec3 vec4::rgb() const { return { r, g, b }; }
inline vec4 vec4::rgba() const { return { r, g, b, a }; }
inline vec4 vec4::rgbb() const { return { r, g, b, b }; }
inline vec4 vec4::rgbg() const { return { r, g, b, g }; }
inline vec4 vec4::rgbr() const { return { r, g, b, r }; }
inline vec3 vec4::rgg() const { return { r, g, g }; }
inline vec4 vec4::rgga() const { return { r, g, g, a }; }
inline vec4 vec4::rggb() const { return { r, g, g, b }; }
inline vec4 vec4::rggg() const { return { r, g, g, g }; }
inline vec4 vec4::rggr() const { return { r, g, g, r }; }
inline vec3 vec4::rgr() const { return { r, g, r }; }
inline vec4 vec4::rgra() const { return { r, g, r, a }; }
inline vec4 vec4::rgrb() const { return { r, g, r, b }; }
inline vec4 vec4::rgrg() const { return { r, g, r, g }; }
inline vec4 vec4::rgrr() const { return { r, g, r, r }; }
inline vec2 vec4::rr() const { return { r, r }; }
inline vec3 vec4::rra() const { return { r, r, a }; }
inline vec4 vec4::rraa() const { return { r, r, a, a }; }
inline vec4 vec4::rrab() const { return { r, r, a, b }; }
inline vec4 vec4::rrag() const { return { r, r, a, g }; }
inline vec4 vec4::rrar() const { return { r, r, a, r }; }
inline vec3 vec4::rrb() const { return { r, r, b }; }
inline vec4 vec4::rrba() const { return { r, r, b, a }; }
inline vec4 vec4::rrbb() const { return { r, r, b, b }; }
inline vec4 vec4::rrbg() const { return { r, r, b, g }; }
inline vec4 vec4::rrbr() const { return { r, r, b, r }; }
inline vec3 vec4::rrg() const { return { r, r, g }; }
inline vec4 vec4::rrga() const { return { r, r, g, a }; }
inline vec4 vec4::rrgb() const { return { r, r, g, b }; }
inline vec4 vec4::rrgg() const { return { r, r, g, g }; }
inline vec4 vec4::rrgr() const { return { r, r, g, r }; }
inline vec3 vec4::rrr() const { return { r, r, r }; }
inline vec4 vec4::rrra() const { return { r, r, r, a }; }
inline vec4 vec4::rrrb() const { return { r, r, r, b }; }
inline vec4 vec4::rrrg() const { return { r, r, r, g }; }
inline vec4 vec4::rrrr() const { return { r, r, r, r }; }
inline vec2 vec4::qq() const { return { q, q }; }
inline vec3 vec4::qqq() const { return { q, q, q }; }
inline vec4 vec4::qqqq() const { return { q, q, q, q }; }
inline vec4 vec4::qqqs() const { return { q, q, q, s }; }
inline vec4 vec4::qqqt() const { return { q, q, q, t }; }
inline vec4 vec4::qqqp() const { return { q, q, q, p }; }
inline vec3 vec4::qqs() const { return { q, q, s }; }
inline vec4 vec4::qqsq() const { return { q, q, s, q }; }
inline vec4 vec4::qqss() const { return { q, q, s, s }; }
inline vec4 vec4::qqst() const { return { q, q, s, t }; }
inline vec4 vec4::qqsp() const { return { q, q, s, p }; }
inline vec3 vec4::qqt() const { return { q, q, t }; }
inline vec4 vec4::qqtq() const { return { q, q, t, q }; }
inline vec4 vec4::qqts() const { return { q, q, t, s }; }
inline vec4 vec4::qqtt() const { return { q, q, t, t }; }
inline vec4 vec4::qqtp() const { return { q, q, t, p }; }
inline vec3 vec4::qqp() const { return { q, q, p }; }
inline vec4 vec4::qqpq() const { return { q, q, p, q }; }
inline vec4 vec4::qqps() const { return { q, q, p, s }; }
inline vec4 vec4::qqpt() const { return { q, q, p, t }; }
inline vec4 vec4::qqpp() const { return { q, q, p, p }; }
inline vec2 vec4::qs() const { return { q, s }; }
inline vec3 vec4::qsq() const { return { q, s, q }; }
inline vec4 vec4::qsqq() const { return { q, s, q, q }; }
inline vec4 vec4::qsqs() const { return { q, s, q, s }; }
inline vec4 vec4::qsqt() const { return { q, s, q, t }; }
inline vec4 vec4::qsqp() const { return { q, s, q, p }; }
inline vec3 vec4::qss() const { return { q, s, s }; }
inline vec4 vec4::qssq() const { return { q, s, s, q }; }
inline vec4 vec4::qsss() const { return { q, s, s, s }; }
inline vec4 vec4::qsst() const { return { q, s, s, t }; }
inline vec4 vec4::qssp() const { return { q, s, s, p }; }
inline vec3 vec4::qst() const { return { q, s, t }; }
inline vec4 vec4::qstq() const { return { q, s, t, q }; }
inline vec4 vec4::qsts() const { return { q, s, t, s }; }
inline vec4 vec4::qstt() const { return { q, s, t, t }; }
inline vec4 vec4::qstp() const { return { q, s, t, p }; }
inline vec3 vec4::qsp() const { return { q, s, p }; }
inline vec4 vec4::qspq() const { return { q, s, p, q }; }
inline vec4 vec4::qsps() const { return { q, s, p, s }; }
inline vec4 vec4::qspt() const { return { q, s, p, t }; }
inline vec4 vec4::qspp() const { return { q, s, p, p }; }
inline vec2 vec4::qt() const { return { q, t }; }
inline vec3 vec4::qtq() const { return { q, t, q }; }
inline vec4 vec4::qtqq() const { return { q, t, q, q }; }
inline vec4 vec4::qtqs() const { return { q, t, q, s }; }
inline vec4 vec4::qtqt() const { return { q, t, q, t }; }
inline vec4 vec4::qtqp() const { return { q, t, q, p }; }
inline vec3 vec4::qts() const { return { q, t, s }; }
inline vec4 vec4::qtsq() const { return { q, t, s, q }; }
inline vec4 vec4::qtss() const { return { q, t, s, s }; }
inline vec4 vec4::qtst() const { return { q, t, s, t }; }
inline vec4 vec4::qtsp() const { return { q, t, s, p }; }
inline vec3 vec4::qtt() const { return { q, t, t }; }
inline vec4 vec4::qttq() const { return { q, t, t, q }; }
inline vec4 vec4::qtts() const { return { q, t, t, s }; }
inline vec4 vec4::qttt() const { return { q, t, t, t }; }
inline vec4 vec4::qttp() const { return { q, t, t, p }; }
inline vec3 vec4::qtp() const { return { q, t, p }; }
inline vec4 vec4::qtpq() const { return { q, t, p, q }; }
inline vec4 vec4::qtps() const { return { q, t, p, s }; }
inline vec4 vec4::qtpt() const { return { q, t, p, t }; }
inline vec4 vec4::qtpp() const { return { q, t, p, p }; }
inline vec2 vec4::qp() const { return { q, p }; }
inline vec3 vec4::qpq() const { return { q, p, q }; }
inline vec4 vec4::qpqq() const { return { q, p, q, q }; }
inline vec4 vec4::qpqs() const { return { q, p, q, s }; }
inline vec4 vec4::qpqt() const { return { q, p, q, t }; }
inline vec4 vec4::qpqp() const { return { q, p, q, p }; }
inline vec3 vec4::qps() const { return { q, p, s }; }
inline vec4 vec4::qpsq() const { return { q, p, s, q }; }
inline vec4 vec4::qpss() const { return { q, p, s, s }; }
inline vec4 vec4::qpst() const { return { q, p, s, t }; }
inline vec4 vec4::qpsp() const { return { q, p, s, p }; }
inline vec3 vec4::qpt() const { return { q, p, t }; }
inline vec4 vec4::qptq() const { return { q, p, t, q }; }
inline vec4 vec4::qpts() const { return { q, p, t, s }; }
inline vec4 vec4::qptt() const { return { q, p, t, t }; }
inline vec4 vec4::qptp() const { return { q, p, t, p }; }
inline vec3 vec4::qpp() const { return { q, p, p }; }
inline vec4 vec4::qppq() const { return { q, p, p, q }; }
inline vec4 vec4::qpps() const { return { q, p, p, s }; }
inline vec4 vec4::qppt() const { return { q, p, p, t }; }
inline vec4 vec4::qppp() const { return { q, p, p, p }; }
inline vec2 vec4::sq() const { return { s, q }; }
inline vec3 vec4::sqq() const { return { s, q, q }; }
inline vec4 vec4::sqqq() const { return { s, q, q, q }; }
inline vec4 vec4::sqqs() const { return { s, q, q, s }; }
inline vec4 vec4::sqqt() const { return { s, q, q, t }; }
inline vec4 vec4::sqqp() const { return { s, q, q, p }; }
inline vec3 vec4::sqs() const { return { s, q, s }; }
inline vec4 vec4::sqsq() const { return { s, q, s, q }; }
inline vec4 vec4::sqss() const { return { s, q, s, s }; }
inline vec4 vec4::sqst() const { return { s, q, s, t }; }
inline vec4 vec4::sqsp() const { return { s, q, s, p }; }
inline vec3 vec4::sqt() const { return { s, q, t }; }
inline vec4 vec4::sqtq() const { return { s, q, t, q }; }
inline vec4 vec4::sqts() const { return { s, q, t, s }; }
inline vec4 vec4::sqtt() const { return { s, q, t, t }; }
inline vec4 vec4::sqtp() const { return { s, q, t, p }; }
inline vec3 vec4::sqp() const { return { s, q, p }; }
inline vec4 vec4::sqpq() const { return { s, q, p, q }; }
inline vec4 vec4::sqps() const { return { s, q, p, s }; }
inline vec4 vec4::sqpt() const { return { s, q, p, t }; }
inline vec4 vec4::sqpp() const { return { s, q, p, p }; }
inline vec2 vec4::ss() const { return { s, s }; }
inline vec3 vec4::ssq() const { return { s, s, q }; }
inline vec4 vec4::ssqq() const { return { s, s, q, q }; }
inline vec4 vec4::ssqs() const { return { s, s, q, s }; }
inline vec4 vec4::ssqt() const { return { s, s, q, t }; }
inline vec4 vec4::ssqp() const { return { s, s, q, p }; }
inline vec3 vec4::sss() const { return { s, s, s }; }
inline vec4 vec4::sssq() const { return { s, s, s, q }; }
inline vec4 vec4::ssss() const { return { s, s, s, s }; }
inline vec4 vec4::ssst() const { return { s, s, s, t }; }
inline vec4 vec4::sssp() const { return { s, s, s, p }; }
inline vec3 vec4::sst() const { return { s, s, t }; }
inline vec4 vec4::sstq() const { return { s, s, t, q }; }
inline vec4 vec4::ssts() const { return { s, s, t, s }; }
inline vec4 vec4::sstt() const { return { s, s, t, t }; }
inline vec4 vec4::sstp() const { return { s, s, t, p }; }
inline vec3 vec4::ssp() const { return { s, s, p }; }
inline vec4 vec4::sspq() const { return { s, s, p, q }; }
inline vec4 vec4::ssps() const { return { s, s, p, s }; }
inline vec4 vec4::sspt() const { return { s, s, p, t }; }
inline vec4 vec4::sspp() const { return { s, s, p, p }; }
inline vec2 vec4::st() const { return { s, t }; }
inline vec3 vec4::stq() const { return { s, t, q }; }
inline vec4 vec4::stqq() const { return { s, t, q, q }; }
inline vec4 vec4::stqs() const { return { s, t, q, s }; }
inline vec4 vec4::stqt() const { return { s, t, q, t }; }
inline vec4 vec4::stqp() const { return { s, t, q, p }; }
inline vec3 vec4::sts() const { return { s, t, s }; }
inline vec4 vec4::stsq() const { return { s, t, s, q }; }
inline vec4 vec4::stss() const { return { s, t, s, s }; }
inline vec4 vec4::stst() const { return { s, t, s, t }; }
inline vec4 vec4::stsp() const { return { s, t, s, p }; }
inline vec3 vec4::stt() const { return { s, t, t }; }
inline vec4 vec4::sttq() const { return { s, t, t, q }; }
inline vec4 vec4::stts() const { return { s, t, t, s }; }
inline vec4 vec4::sttt() const { return { s, t, t, t }; }
inline vec4 vec4::sttp() const { return { s, t, t, p }; }
inline vec3 vec4::stp() const { return { s, t, p }; }
inline vec4 vec4::stpq() const { return { s, t, p, q }; }
inline vec4 vec4::stps() const { return { s, t, p, s }; }
inline vec4 vec4::stpt() const { return { s, t, p, t }; }
inline vec4 vec4::stpp() const { return { s, t, p, p }; }
inline vec2 vec4::sp() const { return { s, p }; }
inline vec3 vec4::spq() const { return { s, p, q }; }
inline vec4 vec4::spqq() const { return { s, p, q, q }; }
inline vec4 vec4::spqs() const { return { s, p, q, s }; }
inline vec4 vec4::spqt() const { return { s, p, q, t }; }
inline vec4 vec4::spqp() const { return { s, p, q, p }; }
inline vec3 vec4::sps() const { return { s, p, s }; }
inline vec4 vec4::spsq() const { return { s, p, s, q }; }
inline vec4 vec4::spss() const { return { s, p, s, s }; }
inline vec4 vec4::spst() const { return { s, p, s, t }; }
inline vec4 vec4::spsp() const { return { s, p, s, p }; }
inline vec3 vec4::spt() const { return { s, p, t }; }
inline vec4 vec4::sptq() const { return { s, p, t, q }; }
inline vec4 vec4::spts() const { return { s, p, t, s }; }
inline vec4 vec4::sptt() const { return { s, p, t, t }; }
inline vec4 vec4::sptp() const { return { s, p, t, p }; }
inline vec3 vec4::spp() const { return { s, p, p }; }
inline vec4 vec4::sppq() const { return { s, p, p, q }; }
inline vec4 vec4::spps() const { return { s, p, p, s }; }
inline vec4 vec4::sppt() const { return { s, p, p, t }; }
inline vec4 vec4::sppp() const { return { s, p, p, p }; }
inline vec2 vec4::tq() const { return { t, q }; }
inline vec3 vec4::tqq() const { return { t, q, q }; }
inline vec4 vec4::tqqq() const { return { t, q, q, q }; }
inline vec4 vec4::tqqs() const { return { t, q, q, s }; }
inline vec4 vec4::tqqt() const { return { t, q, q, t }; }
inline vec4 vec4::tqqp() const { return { t, q, q, p }; }
inline vec3 vec4::tqs() const { return { t, q, s }; }
inline vec4 vec4::tqsq() const { return { t, q, s, q }; }
inline vec4 vec4::tqss() const { return { t, q, s, s }; }
inline vec4 vec4::tqst() const { return { t, q, s, t }; }
inline vec4 vec4::tqsp() const { return { t, q, s, p }; }
inline vec3 vec4::tqt() const { return { t, q, t }; }
inline vec4 vec4::tqtq() const { return { t, q, t, q }; }
inline vec4 vec4::tqts() const { return { t, q, t, s }; }
inline vec4 vec4::tqtt() const { return { t, q, t, t }; }
inline vec4 vec4::tqtp() const { return { t, q, t, p }; }
inline vec3 vec4::tqp() const { return { t, q, p }; }
inline vec4 vec4::tqpq() const { return { t, q, p, q }; }
inline vec4 vec4::tqps() const { return { t, q, p, s }; }
inline vec4 vec4::tqpt() const { return { t, q, p, t }; }
inline vec4 vec4::tqpp() const { return { t, q, p, p }; }
inline vec2 vec4::ts() const { return { t, s }; }
inline vec3 vec4::tsq() const { return { t, s, q }; }
inline vec4 vec4::tsqq() const { return { t, s, q, q }; }
inline vec4 vec4::tsqs() const { return { t, s, q, s }; }
inline vec4 vec4::tsqt() const { return { t, s, q, t }; }
inline vec4 vec4::tsqp() const { return { t, s, q, p }; }
inline vec3 vec4::tss() const { return { t, s, s }; }
inline vec4 vec4::tssq() const { return { t, s, s, q }; }
inline vec4 vec4::tsss() const { return { t, s, s, s }; }
inline vec4 vec4::tsst() const { return { t, s, s, t }; }
inline vec4 vec4::tssp() const { return { t, s, s, p }; }
inline vec3 vec4::tst() const { return { t, s, t }; }
inline vec4 vec4::tstq() const { return { t, s, t, q }; }
inline vec4 vec4::tsts() const { return { t, s, t, s }; }
inline vec4 vec4::tstt() const { return { t, s, t, t }; }
inline vec4 vec4::tstp() const { return { t, s, t, p }; }
inline vec3 vec4::tsp() const { return { t, s, p }; }
inline vec4 vec4::tspq() const { return { t, s, p, q }; }
inline vec4 vec4::tsps() const { return { t, s, p, s }; }
inline vec4 vec4::tspt() const { return { t, s, p, t }; }
inline vec4 vec4::tspp() const { return { t, s, p, p }; }
inline vec2 vec4::tt() const { return { t, t }; }
inline vec3 vec4::ttq() const { return { t, t, q }; }
inline vec4 vec4::ttqq() const { return { t, t, q, q }; }
inline vec4 vec4::ttqs() const { return { t, t, q, s }; }
inline vec4 vec4::ttqt() const { return { t, t, q, t }; }
inline vec4 vec4::ttqp() const { return { t, t, q, p }; }
inline vec3 vec4::tts() const { return { t, t, s }; }
inline vec4 vec4::ttsq() const { return { t, t, s, q }; }
inline vec4 vec4::ttss() const { return { t, t, s, s }; }
inline vec4 vec4::ttst() const { return { t, t, s, t }; }
inline vec4 vec4::ttsp() const { return { t, t, s, p }; }
inline vec3 vec4::ttt() const { return { t, t, t }; }
inline vec4 vec4::tttq() const { return { t, t, t, q }; }
inline vec4 vec4::ttts() const { return { t, t, t, s }; }
inline vec4 vec4::tttt() const { return { t, t, t, t }; }
inline vec4 vec4::tttp() const { return { t, t, t, p }; }
inline vec3 vec4::ttp() const { return { t, t, p }; }
inline vec4 vec4::ttpq() const { return { t, t, p, q }; }
inline vec4 vec4::ttps() const { return { t, t, p, s }; }
inline vec4 vec4::ttpt() const { return { t, t, p, t }; }
inline vec4 vec4::ttpp() const { return { t, t, p, p }; }
inline vec2 vec4::tp() const { return { t, p }; }
inline vec3 vec4::tpq() const { return { t, p, q }; }
inline vec4 vec4::tpqq() const { return { t, p, q, q }; }
inline vec4 vec4::tpqs() const { return { t, p, q, s }; }
inline vec4 vec4::tpqt() const { return { t, p, q, t }; }
inline vec4 vec4::tpqp() const { return { t, p, q, p }; }
inline vec3 vec4::tps() const { return { t, p, s }; }
inline vec4 vec4::tpsq() const { return { t, p, s, q }; }
inline vec4 vec4::tpss() const { return { t, p, s, s }; }
inline vec4 vec4::tpst() const { return { t, p, s, t }; }
inline vec4 vec4::tpsp() const { return { t, p, s, p }; }
inline vec3 vec4::tpt() const { return { t, p, t }; }
inline vec4 vec4::tptq() const { return { t, p, t, q }; }
inline vec4 vec4::tpts() const { return { t, p, t, s }; }
inline vec4 vec4::tptt() const { return { t, p, t, t }; }
inline vec4 vec4::tptp() const { return { t, p, t, p }; }
inline vec3 vec4::tpp() const { return { t, p, p }; }
inline vec4 vec4::tppq() const { return { t, p, p, q }; }
inline vec4 vec4::tpps() const { return { t, p, p, s }; }
inline vec4 vec4::tppt() const { return { t, p, p, t }; }
inline vec4 vec4::tppp() const { return { t, p, p, p }; }
inline vec2 vec4::pq() const { return { p, q }; }
inline vec3 vec4::pqq() const { return { p, q, q }; }
inline vec4 vec4::pqqq() const { return { p, q, q, q }; }
inline vec4 vec4::pqqs() const { return { p, q, q, s }; }
inline vec4 vec4::pqqt() const { return { p, q, q, t }; }
inline vec4 vec4::pqqp() const { return { p, q, q, p }; }
inline vec3 vec4::pqs() const { return { p, q, s }; }
inline vec4 vec4::pqsq() const { return { p, q, s, q }; }
inline vec4 vec4::pqss() const { return { p, q, s, s }; }
inline vec4 vec4::pqst() const { return { p, q, s, t }; }
inline vec4 vec4::pqsp() const { return { p, q, s, p }; }
inline vec3 vec4::pqt() const { return { p, q, t }; }
inline vec4 vec4::pqtq() const { return { p, q, t, q }; }
inline vec4 vec4::pqts() const { return { p, q, t, s }; }
inline vec4 vec4::pqtt() const { return { p, q, t, t }; }
inline vec4 vec4::pqtp() const { return { p, q, t, p }; }
inline vec3 vec4::pqp() const { return { p, q, p }; }
inline vec4 vec4::pqpq() const { return { p, q, p, q }; }
inline vec4 vec4::pqps() const { return { p, q, p, s }; }
inline vec4 vec4::pqpt() const { return { p, q, p, t }; }
inline vec4 vec4::pqpp() const { return { p, q, p, p }; }
inline vec2 vec4::ps() const { return { p, s }; }
inline vec3 vec4::psq() const { return { p, s, q }; }
inline vec4 vec4::psqq() const { return { p, s, q, q }; }
inline vec4 vec4::psqs() const { return { p, s, q, s }; }
inline vec4 vec4::psqt() const { return { p, s, q, t }; }
inline vec4 vec4::psqp() const { return { p, s, q, p }; }
inline vec3 vec4::pss() const { return { p, s, s }; }
inline vec4 vec4::pssq() const { return { p, s, s, q }; }
inline vec4 vec4::psss() const { return { p, s, s, s }; }
inline vec4 vec4::psst() const { return { p, s, s, t }; }
inline vec4 vec4::pssp() const { return { p, s, s, p }; }
inline vec3 vec4::pst() const { return { p, s, t }; }
inline vec4 vec4::pstq() const { return { p, s, t, q }; }
inline vec4 vec4::psts() const { return { p, s, t, s }; }
inline vec4 vec4::pstt() const { return { p, s, t, t }; }
inline vec4 vec4::pstp() const { return { p, s, t, p }; }
inline vec3 vec4::psp() const { return { p, s, p }; }
inline vec4 vec4::pspq() const { return { p, s, p, q }; }
inline vec4 vec4::psps() const { return { p, s, p, s }; }
inline vec4 vec4::pspt() const { return { p, s, p, t }; }
inline vec4 vec4::pspp() const { return { p, s, p, p }; }
inline vec2 vec4::pt() const { return { p, t }; }
inline vec3 vec4::ptq() const { return { p, t, q }; }
inline vec4 vec4::ptqq() const { return { p, t, q, q }; }
inline vec4 vec4::ptqs() const { return { p, t, q, s }; }
inline vec4 vec4::ptqt() const { return { p, t, q, t }; }
inline vec4 vec4::ptqp() const { return { p, t, q, p }; }
inline vec3 vec4::pts() const { return { p, t, s }; }
inline vec4 vec4::ptsq() const { return { p, t, s, q }; }
inline vec4 vec4::ptss() const { return { p, t, s, s }; }
inline vec4 vec4::ptst() const { return { p, t, s, t }; }
inline vec4 vec4::ptsp() const { return { p, t, s, p }; }
inline vec3 vec4::ptt() const { return { p, t, t }; }
inline vec4 vec4::pttq() const { return { p, t, t, q }; }
inline vec4 vec4::ptts() const { return { p, t, t, s }; }
inline vec4 vec4::pttt() const { return { p, t, t, t }; }
inline vec4 vec4::pttp() const { return { p, t, t, p }; }
inline vec3 vec4::ptp() const { return { p, t, p }; }
inline vec4 vec4::ptpq() const { return { p, t, p, q }; }
inline vec4 vec4::ptps() const { return { p, t, p, s }; }
inline vec4 vec4::ptpt() const { return { p, t, p, t }; }
inline vec4 vec4::ptpp() const { return { p, t, p, p }; }
inline vec2 vec4::pp() const { return { p, p }; }
inline vec3 vec4::ppq() const { return { p, p, q }; }
inline vec4 vec4::ppqq() const { return { p, p, q, q }; }
inline vec4 vec4::ppqs() const { return { p, p, q, s }; }
inline vec4 vec4::ppqt() const { return { p, p, q, t }; }
inline vec4 vec4::ppqp() const { return { p, p, q, p }; }
inline vec3 vec4::pps() const { return { p, p, s }; }
inline vec4 vec4::ppsq() const { return { p, p, s, q }; }
inline vec4 vec4::ppss() const { return { p, p, s, s }; }
inline vec4 vec4::ppst() const { return { p, p, s, t }; }
inline vec4 vec4::ppsp() const { return { p, p, s, p }; }
inline vec3 vec4::ppt() const { return { p, p, t }; }
inline vec4 vec4::pptq() const { return { p, p, t, q }; }
inline vec4 vec4::ppts() const { return { p, p, t, s }; }
inline vec4 vec4::pptt() const { return { p, p, t, t }; }
inline vec4 vec4::pptp() const { return { p, p, t, p }; }
inline vec3 vec4::ppp() const { return { p, p, p }; }
inline vec4 vec4::pppq() const { return { p, p, p, q }; }
inline vec4 vec4::ppps() const { return { p, p, p, s }; }
inline vec4 vec4::pppt() const { return { p, p, p, t }; }
inline vec4 vec4::pppp() const { return { p, p, p, p }; }
inline vec2 vec4::ww() const { return { w, w }; }
inline vec3 vec4::www() const { return { w, w, w }; }
inline vec4 vec4::wwww() const { return { w, w, w, w }; }
inline vec4 vec4::wwwx() const { return { w, w, w, x }; }
inline vec4 vec4::wwwy() const { return { w, w, w, y }; }
inline vec4 vec4::wwwz() const { return { w, w, w, z }; }
inline vec3 vec4::wwx() const { return { w, w, x }; }
inline vec4 vec4::wwxw() const { return { w, w, x, w }; }
inline vec4 vec4::wwxx() const { return { w, w, x, x }; }
inline vec4 vec4::wwxy() const { return { w, w, x, y }; }
inline vec4 vec4::wwxz() const { return { w, w, x, z }; }
inline vec3 vec4::wwy() const { return { w, w, y }; }
inline vec4 vec4::wwyw() const { return { w, w, y, w }; }
inline vec4 vec4::wwyx() const { return { w, w, y, x }; }
inline vec4 vec4::wwyy() const { return { w, w, y, y }; }
inline vec4 vec4::wwyz() const { return { w, w, y, z }; }
inline vec3 vec4::wwz() const { return { w, w, z }; }
inline vec4 vec4::wwzw() const { return { w, w, z, w }; }
inline vec4 vec4::wwzx() const { return { w, w, z, x }; }
inline vec4 vec4::wwzy() const { return { w, w, z, y }; }
inline vec4 vec4::wwzz() const { return { w, w, z, z }; }
inline vec2 vec4::wx() const { return { w, x }; }
inline vec3 vec4::wxw() const { return { w, x, w }; }
inline vec4 vec4::wxww() const { return { w, x, w, w }; }
inline vec4 vec4::wxwx() const { return { w, x, w, x }; }
inline vec4 vec4::wxwy() const { return { w, x, w, y }; }
inline vec4 vec4::wxwz() const { return { w, x, w, z }; }
inline vec3 vec4::wxx() const { return { w, x, x }; }
inline vec4 vec4::wxxw() const { return { w, x, x, w }; }
inline vec4 vec4::wxxx() const { return { w, x, x, x }; }
inline vec4 vec4::wxxy() const { return { w, x, x, y }; }
inline vec4 vec4::wxxz() const { return { w, x, x, z }; }
inline vec3 vec4::wxy() const { return { w, x, y }; }
inline vec4 vec4::wxyw() const { return { w, x, y, w }; }
inline vec4 vec4::wxyx() const { return { w, x, y, x }; }
inline vec4 vec4::wxyy() const { return { w, x, y, y }; }
inline vec4 vec4::wxyz() const { return { w, x, y, z }; }
inline vec3 vec4::wxz() const { return { w, x, z }; }
inline vec4 vec4::wxzw() const { return { w, x, z, w }; }
inline vec4 vec4::wxzx() const { return { w, x, z, x }; }
inline vec4 vec4::wxzy() const { return { w, x, z, y }; }
inline vec4 vec4::wxzz() const { return { w, x, z, z }; }
inline vec2 vec4::wy() const { return { w, y }; }
inline vec3 vec4::wyw() const { return { w, y, w }; }
inline vec4 vec4::wyww() const { return { w, y, w, w }; }
inline vec4 vec4::wywx() const { return { w, y, w, x }; }
inline vec4 vec4::wywy() const { return { w, y, w, y }; }
inline vec4 vec4::wywz() const { return { w, y, w, z }; }
inline vec3 vec4::wyx() const { return { w, y, x }; }
inline vec4 vec4::wyxw() const { return { w, y, x, w }; }
inline vec4 vec4::wyxx() const { return { w, y, x, x }; }
inline vec4 vec4::wyxy() const { return { w, y, x, y }; }
inline vec4 vec4::wyxz() const { return { w, y, x, z }; }
inline vec3 vec4::wyy() const { return { w, y, y }; }
inline vec4 vec4::wyyw() const { return { w, y, y, w }; }
inline vec4 vec4::wyyx() const { return { w, y, y, x }; }
inline vec4 vec4::wyyy() const { return { w, y, y, y }; }
inline vec4 vec4::wyyz() const { return { w, y, y, z }; }
inline vec3 vec4::wyz() const { return { w, y, z }; }
inline vec4 vec4::wyzw() const { return { w, y, z, w }; }
inline vec4 vec4::wyzx() const { return { w, y, z, x }; }
inline vec4 vec4::wyzy() const { return { w, y, z, y }; }
inline vec4 vec4::wyzz() const { return { w, y, z, z }; }
inline vec2 vec4::wz() const { return { w, z }; }
inline vec3 vec4::wzw() const { return { w, z, w }; }
inline vec4 vec4::wzww() const { return { w, z, w, w }; }
inline vec4 vec4::wzwx() const { return { w, z, w, x }; }
inline vec4 vec4::wzwy() const { return { w, z, w, y }; }
inline vec4 vec4::wzwz() const { return { w, z, w, z }; }
inline vec3 vec4::wzx() const { return { w, z, x }; }
inline vec4 vec4::wzxw() const { return { w, z, x, w }; }
inline vec4 vec4::wzxx() const { return { w, z, x, x }; }
inline vec4 vec4::wzxy() const { return { w, z, x, y }; }
inline vec4 vec4::wzxz() const { return { w, z, x, z }; }
inline vec3 vec4::wzy() const { return { w, z, y }; }
inline vec4 vec4::wzyw() const { return { w, z, y, w }; }
inline vec4 vec4::wzyx() const { return { w, z, y, x }; }
inline vec4 vec4::wzyy() const { return { w, z, y, y }; }
inline vec4 vec4::wzyz() const { return { w, z, y, z }; }
inline vec3 vec4::wzz() const { return { w, z, z }; }
inline vec4 vec4::wzzw() const { return { w, z, z, w }; }
inline vec4 vec4::wzzx() const { return { w, z, z, x }; }
inline vec4 vec4::wzzy() const { return { w, z, z, y }; }
inline vec4 vec4::wzzz() const { return { w, z, z, z }; }
inline vec2 vec4::xw() const { return { x, w }; }
inline vec3 vec4::xww() const { return { x, w, w }; }
inline vec4 vec4::xwww() const { return { x, w, w, w }; }
inline vec4 vec4::xwwx() const { return { x, w, w, x }; }
inline vec4 vec4::xwwy() const { return { x, w, w, y }; }
inline vec4 vec4::xwwz() const { return { x, w, w, z }; }
inline vec3 vec4::xwx() const { return { x, w, x }; }
inline vec4 vec4::xwxw() const { return { x, w, x, w }; }
inline vec4 vec4::xwxx() const { return { x, w, x, x }; }
inline vec4 vec4::xwxy() const { return { x, w, x, y }; }
inline vec4 vec4::xwxz() const { return { x, w, x, z }; }
inline vec3 vec4::xwy() const { return { x, w, y }; }
inline vec4 vec4::xwyw() const { return { x, w, y, w }; }
inline vec4 vec4::xwyx() const { return { x, w, y, x }; }
inline vec4 vec4::xwyy() const { return { x, w, y, y }; }
inline vec4 vec4::xwyz() const { return { x, w, y, z }; }
inline vec3 vec4::xwz() const { return { x, w, z }; }
inline vec4 vec4::xwzw() const { return { x, w, z, w }; }
inline vec4 vec4::xwzx() const { return { x, w, z, x }; }
inline vec4 vec4::xwzy() const { return { x, w, z, y }; }
inline vec4 vec4::xwzz() const { return { x, w, z, z }; }
inline vec2 vec4::xx() const { return { x, x }; }
inline vec3 vec4::xxw() const { return { x, x, w }; }
inline vec4 vec4::xxww() const { return { x, x, w, w }; }
inline vec4 vec4::xxwx() const { return { x, x, w, x }; }
inline vec4 vec4::xxwy() const { return { x, x, w, y }; }
inline vec4 vec4::xxwz() const { return { x, x, w, z }; }
inline vec3 vec4::xxx() const { return { x, x, x }; }
inline vec4 vec4::xxxw() const { return { x, x, x, w }; }
inline vec4 vec4::xxxx() const { return { x, x, x, x }; }
inline vec4 vec4::xxxy() const { return { x, x, x, y }; }
inline vec4 vec4::xxxz() const { return { x, x, x, z }; }
inline vec3 vec4::xxy() const { return { x, x, y }; }
inline vec4 vec4::xxyw() const { return { x, x, y, w }; }
inline vec4 vec4::xxyx() const { return { x, x, y, x }; }
inline vec4 vec4::xxyy() const { return { x, x, y, y }; }
inline vec4 vec4::xxyz() const { return { x, x, y, z }; }
inline vec3 vec4::xxz() const { return { x, x, z }; }
inline vec4 vec4::xxzw() const { return { x, x, z, w }; }
inline vec4 vec4::xxzx() const { return { x, x, z, x }; }
inline vec4 vec4::xxzy() const { return { x, x, z, y }; }
inline vec4 vec4::xxzz() const { return { x, x, z, z }; }
inline vec2 vec4::xy() const { return { x, y }; }
inline vec3 vec4::xyw() const { return { x, y, w }; }
inline vec4 vec4::xyww() const { return { x, y, w, w }; }
inline vec4 vec4::xywx() const { return { x, y, w, x }; }
inline vec4 vec4::xywy() const { return { x, y, w, y }; }
inline vec4 vec4::xywz() const { return { x, y, w, z }; }
inline vec3 vec4::xyx() const { return { x, y, x }; }
inline vec4 vec4::xyxw() const { return { x, y, x, w }; }
inline vec4 vec4::xyxx() const { return { x, y, x, x }; }
inline vec4 vec4::xyxy() const { return { x, y, x, y }; }
inline vec4 vec4::xyxz() const { return { x, y, x, z }; }
inline vec3 vec4::xyy() const { return { x, y, y }; }
inline vec4 vec4::xyyw() const { return { x, y, y, w }; }
inline vec4 vec4::xyyx() const { return { x, y, y, x }; }
inline vec4 vec4::xyyy() const { return { x, y, y, y }; }
inline vec4 vec4::xyyz() const { return { x, y, y, z }; }
inline vec3 vec4::xyz() const { return { x, y, z }; }
inline vec4 vec4::xyzw() const { return { x, y, z, w }; }
inline vec4 vec4::xyzx() const { return { x, y, z, x }; }
inline vec4 vec4::xyzy() const { return { x, y, z, y }; }
inline vec4 vec4::xyzz() const { return { x, y, z, z }; }
inline vec2 vec4::xz() const { return { x, z }; }
inline vec3 vec4::xzw() const { return { x, z, w }; }
inline vec4 vec4::xzww() const { return { x, z, w, w }; }
inline vec4 vec4::xzwx() const { return { x, z, w, x }; }
inline vec4 vec4::xzwy() const { return { x, z, w, y }; }
inline vec4 vec4::xzwz() const { return { x, z, w, z }; }
inline vec3 vec4::xzx() const { return { x, z, x }; }
inline vec4 vec4::xzxw() const { return { x, z, x, w }; }
inline vec4 vec4::xzxx() const { return { x, z, x, x }; }
inline vec4 vec4::xzxy() const { return { x, z, x, y }; }
inline vec4 vec4::xzxz() const { return { x, z, x, z }; }
inline vec3 vec4::xzy() const { return { x, z, y }; }
inline vec4 vec4::xzyw() const { return { x, z, y, w }; }
inline vec4 vec4::xzyx() const { return { x, z, y, x }; }
inline vec4 vec4::xzyy() const { return { x, z, y, y }; }
inline vec4 vec4::xzyz() const { return { x, z, y, z }; }
inline vec3 vec4::xzz() const { return { x, z, z }; }
inline vec4 vec4::xzzw() const { return { x, z, z, w }; }
inline vec4 vec4::xzzx() const { return { x, z, z, x }; }
inline vec4 vec4::xzzy() const { return { x, z, z, y }; }
inline vec4 vec4::xzzz() const { return { x, z, z, z }; }
inline vec2 vec4::yw() const { return { y, w }; }
inline vec3 vec4::yww() const { return { y, w, w }; }
inline vec4 vec4::ywww() const { return { y, w, w, w }; }
inline vec4 vec4::ywwx() const { return { y, w, w, x }; }
inline vec4 vec4::ywwy() const { return { y, w, w, y }; }
inline vec4 vec4::ywwz() const { return { y, w, w, z }; }
inline vec3 vec4::ywx() const { return { y, w, x }; }
inline vec4 vec4::ywxw() const { return { y, w, x, w }; }
inline vec4 vec4::ywxx() const { return { y, w, x, x }; }
inline vec4 vec4::ywxy() const { return { y, w, x, y }; }
inline vec4 vec4::ywxz() const { return { y, w, x, z }; }
inline vec3 vec4::ywy() const { return { y, w, y }; }
inline vec4 vec4::ywyw() const { return { y, w, y, w }; }
inline vec4 vec4::ywyx() const { return { y, w, y, x }; }
inline vec4 vec4::ywyy() const { return { y, w, y, y }; }
inline vec4 vec4::ywyz() const { return { y, w, y, z }; }
inline vec3 vec4::ywz() const { return { y, w, z }; }
inline vec4 vec4::ywzw() const { return { y, w, z, w }; }
inline vec4 vec4::ywzx() const { return { y, w, z, x }; }
inline vec4 vec4::ywzy() const { return { y, w, z, y }; }
inline vec4 vec4::ywzz() const { return { y, w, z, z }; }
inline vec2 vec4::yx() const { return { y, x }; }
inline vec3 vec4::yxw() const { return { y, x, w }; }
inline vec4 vec4::yxww() const { return { y, x, w, w }; }
inline vec4 vec4::yxwx() const { return { y, x, w, x }; }
inline vec4 vec4::yxwy() const { return { y, x, w, y }; }
inline vec4 vec4::yxwz() const { return { y, x, w, z }; }
inline vec3 vec4::yxx() const { return { y, x, x }; }
inline vec4 vec4::yxxw() const { return { y, x, x, w }; }
inline vec4 vec4::yxxx() const { return { y, x, x, x }; }
inline vec4 vec4::yxxy() const { return { y, x, x, y }; }
inline vec4 vec4::yxxz() const { return { y, x, x, z }; }
inline vec3 vec4::yxy() const { return { y, x, y }; }
inline vec4 vec4::yxyw() const { return { y, x, y, w }; }
inline vec4 vec4::yxyx() const { return { y, x, y, x }; }
inline vec4 vec4::yxyy() const { return { y, x, y, y }; }
inline vec4 vec4::yxyz() const { return { y, x, y, z }; }
inline vec3 vec4::yxz() const { return { y, x, z }; }
inline vec4 vec4::yxzw() const { return { y, x, z, w }; }
inline vec4 vec4::yxzx() const { return { y, x, z, x }; }
inline vec4 vec4::yxzy() const { return { y, x, z, y }; }
inline vec4 vec4::yxzz() const { return { y, x, z, z }; }
inline vec2 vec4::yy() const { return { y, y }; }
inline vec3 vec4::yyw() const { return { y, y, w }; }
inline vec4 vec4::yyww() const { return { y, y, w, w }; }
inline vec4 vec4::yywx() const { return { y, y, w, x }; }
inline vec4 vec4::yywy() const { return { y, y, w, y }; }
inline vec4 vec4::yywz() const { return { y, y, w, z }; }
inline vec3 vec4::yyx() const { return { y, y, x }; }
inline vec4 vec4::yyxw() const { return { y, y, x, w }; }
inline vec4 vec4::yyxx() const { return { y, y, x, x }; }
inline vec4 vec4::yyxy() const { return { y, y, x, y }; }
inline vec4 vec4::yyxz() const { return { y, y, x, z }; }
inline vec3 vec4::yyy() const { return { y, y, y }; }
inline vec4 vec4::yyyw() const { return { y, y, y, w }; }
inline vec4 vec4::yyyx() const { return { y, y, y, x }; }
inline vec4 vec4::yyyy() const { return { y, y, y, y }; }
inline vec4 vec4::yyyz() const { return { y, y, y, z }; }
inline vec3 vec4::yyz() const { return { y, y, z }; }
inline vec4 vec4::yyzw() const { return { y, y, z, w }; }
inline vec4 vec4::yyzx() const { return { y, y, z, x }; }
inline vec4 vec4::yyzy() const { return { y, y, z, y }; }
inline vec4 vec4::yyzz() const { return { y, y, z, z }; }
inline vec2 vec4::yz() const { return { y, z }; }
inline vec3 vec4::yzw() const { return { y, z, w }; }
inline vec4 vec4::yzww() const { return { y, z, w, w }; }
inline vec4 vec4::yzwx() const { return { y, z, w, x }; }
inline vec4 vec4::yzwy() const { return { y, z, w, y }; }
inline vec4 vec4::yzwz() const { return { y, z, w, z }; }
inline vec3 vec4::yzx() const { return { y, z, x }; }
inline vec4 vec4::yzxw() const { return { y, z, x, w }; }
inline vec4 vec4::yzxx() const { return { y, z, x, x }; }
inline vec4 vec4::yzxy() const { return { y, z, x, y }; }
inline vec4 vec4::yzxz() const { return { y, z, x, z }; }
inline vec3 vec4::yzy() const { return { y, z, y }; }
inline vec4 vec4::yzyw() const { return { y, z, y, w }; }
inline vec4 vec4::yzyx() const { return { y, z, y, x }; }
inline vec4 vec4::yzyy() const { return { y, z, y, y }; }
inline vec4 vec4::yzyz() const { return { y, z, y, z }; }
inline vec3 vec4::yzz() const { return { y, z, z }; }
inline vec4 vec4::yzzw() const { return { y, z, z, w }; }
inline vec4 vec4::yzzx() const { return { y, z, z, x }; }
inline vec4 vec4::yzzy() const { return { y, z, z, y }; }
inline vec4 vec4::yzzz() const { return { y, z, z, z }; }
inline vec2 vec4::zw() const { return { z, w }; }
inline vec3 vec4::zww() const { return { z, w, w }; }
inline vec4 vec4::zwww() const { return { z, w, w, w }; }
inline vec4 vec4::zwwx() const { return { z, w, w, x }; }
inline vec4 vec4::zwwy() const { return { z, w, w, y }; }
inline vec4 vec4::zwwz() const { return { z, w, w, z }; }
inline vec3 vec4::zwx() const { return { z, w, x }; }
inline vec4 vec4::zwxw() const { return { z, w, x, w }; }
inline vec4 vec4::zwxx() const { return { z, w, x, x }; }
inline vec4 vec4::zwxy() const { return { z, w, x, y }; }
inline vec4 vec4::zwxz() const { return { z, w, x, z }; }
inline vec3 vec4::zwy() const { return { z, w, y }; }
inline vec4 vec4::zwyw() const { return { z, w, y, w }; }
inline vec4 vec4::zwyx() const { return { z, w, y, x }; }
inline vec4 vec4::zwyy() const { return { z, w, y, y }; }
inline vec4 vec4::zwyz() const { return { z, w, y, z }; }
inline vec3 vec4::zwz() const { return { z, w, z }; }
inline vec4 vec4::zwzw() const { return { z, w, z, w }; }
inline vec4 vec4::zwzx() const { return { z, w, z, x }; }
inline vec4 vec4::zwzy() const { return { z, w, z, y }; }
inline vec4 vec4::zwzz() const { return { z, w, z, z }; }
inline vec2 vec4::zx() const { return { z, x }; }
inline vec3 vec4::zxw() const { return { z, x, w }; }
inline vec4 vec4::zxww() const { return { z, x, w, w }; }
inline vec4 vec4::zxwx() const { return { z, x, w, x }; }
inline vec4 vec4::zxwy() const { return { z, x, w, y }; }
inline vec4 vec4::zxwz() const { return { z, x, w, z }; }
inline vec3 vec4::zxx() const { return { z, x, x }; }
inline vec4 vec4::zxxw() const { return { z, x, x, w }; }
inline vec4 vec4::zxxx() const { return { z, x, x, x }; }
inline vec4 vec4::zxxy() const { return { z, x, x, y }; }
inline vec4 vec4::zxxz() const { return { z, x, x, z }; }
inline vec3 vec4::zxy() const { return { z, x, y }; }
inline vec4 vec4::zxyw() const { return { z, x, y, w }; }
inline vec4 vec4::zxyx() const { return { z, x, y, x }; }
inline vec4 vec4::zxyy() const { return { z, x, y, y }; }
inline vec4 vec4::zxyz() const { return { z, x, y, z }; }
inline vec3 vec4::zxz() const { return { z, x, z }; }
inline vec4 vec4::zxzw() const { return { z, x, z, w }; }
inline vec4 vec4::zxzx() const { return { z, x, z, x }; }
inline vec4 vec4::zxzy() const { return { z, x, z, y }; }
inline vec4 vec4::zxzz() const { return { z, x, z, z }; }
inline vec2 vec4::zy() const { return { z, y }; }
inline vec3 vec4::zyw() const { return { z, y, w }; }
inline vec4 vec4::zyww() const { return { z, y, w, w }; }
inline vec4 vec4::zywx() const { return { z, y, w, x }; }
inline vec4 vec4::zywy() const { return { z, y, w, y }; }
inline vec4 vec4::zywz() const { return { z, y, w, z }; }
inline vec3 vec4::zyx() const { return { z, y, x }; }
inline vec4 vec4::zyxw() const { return { z, y, x, w }; }
inline vec4 vec4::zyxx() const { return { z, y, x, x }; }
inline vec4 vec4::zyxy() const { return { z, y, x, y }; }
inline vec4 vec4::zyxz() const { return { z, y, x, z }; }
inline vec3 vec4::zyy() const { return { z, y, y }; }
inline vec4 vec4::zyyw() const { return { z, y, y, w }; }
inline vec4 vec4::zyyx() const { return { z, y, y, x }; }
inline vec4 vec4::zyyy() const { return { z, y, y, y }; }
inline vec4 vec4::zyyz() const { return { z, y, y, z }; }
inline vec3 vec4::zyz() const { return { z, y, z }; }
inline vec4 vec4::zyzw() const { return { z, y, z, w }; }
inline vec4 vec4::zyzx() const { return { z, y, z, x }; }
inline vec4 vec4::zyzy() const { return { z, y, z, y }; }
inline vec4 vec4::zyzz() const { return { z, y, z, z }; }
inline vec2 vec4::zz() const { return { z, z }; }
inline vec3 vec4::zzw() const { return { z, z, w }; }
inline vec4 vec4::zzww() const { return { z, z, w, w }; }
inline vec4 vec4::zzwx() const { return { z, z, w, x }; }
inline vec4 vec4::zzwy() const { return { z, z, w, y }; }
inline vec4 vec4::zzwz() const { return { z, z, w, z }; }
inline vec3 vec4::zzx() const { return { z, z, x }; }
inline vec4 vec4::zzxw() const { return { z, z, x, w }; }
inline vec4 vec4::zzxx() const { return { z, z, x, x }; }
inline vec4 vec4::zzxy() const { return { z, z, x, y }; }
inline vec4 vec4::zzxz() const { return { z, z, x, z }; }
inline vec3 vec4::zzy() const { return { z, z, y }; }
inline vec4 vec4::zzyw() const { return { z, z, y, w }; }
inline vec4 vec4::zzyx() const { return { z, z, y, x }; }
inline vec4 vec4::zzyy() const { return { z, z, y, y }; }
inline vec4 vec4::zzyz() const { return { z, z, y, z }; }
inline vec3 vec4::zzz() const { return { z, z, z }; }
inline vec4 vec4::zzzw() const { return { z, z, z, w }; }
inline vec4 vec4::zzzx() const { return { z, z, z, x }; }
inline vec4 vec4::zzzy() const { return { z, z, z, y }; }
inline vec4 vec4::zzzz() const { return { z, z, z, z }; }
inline void vec4::ab(const simdfloat& _val0, const simdfloat& _val1) { a = _val0; b = _val1; }
inline void vec4::ab(const vec2& _val) { a = _val.x; b = _val.y; }
inline void vec4::ab(const simdfloat& _val) { a = _val; b = _val; }
inline void vec4::abg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { a = _val0; b = _val1; g = _val2; }
inline void vec4::abg(const vec3& _val) { a = _val.x; b = _val.y; g = _val.z; }
inline void vec4::abg(const simdfloat& _val) { a = _val; b = _val; g = _val; }
inline void vec4::abgr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { a = _val0; b = _val1; g = _val2; r = _val3; }
inline void vec4::abgr(const vec4& _val) { a = _val.x; b = _val.y; g = _val.z; r = _val.w; }
inline void vec4::abgr(const simdfloat& _val) { a = _val; b = _val; g = _val; r = _val; }
inline void vec4::abr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { a = _val0; b = _val1; r = _val2; }
inline void vec4::abr(const vec3& _val) { a = _val.x; b = _val.y; r = _val.z; }
inline void vec4::abr(const simdfloat& _val) { a = _val; b = _val; r = _val; }
inline void vec4::abrg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { a = _val0; b = _val1; r = _val2; g = _val3; }
inline void vec4::abrg(const vec4& _val) { a = _val.x; b = _val.y; r = _val.z; g = _val.w; }
inline void vec4::abrg(const simdfloat& _val) { a = _val; b = _val; r = _val; g = _val; }
inline void vec4::ag(const simdfloat& _val0, const simdfloat& _val1) { a = _val0; g = _val1; }
inline void vec4::ag(const vec2& _val) { a = _val.x; g = _val.y; }
inline void vec4::ag(const simdfloat& _val) { a = _val; g = _val; }
inline void vec4::agb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { a = _val0; g = _val1; b = _val2; }
inline void vec4::agb(const vec3& _val) { a = _val.x; g = _val.y; b = _val.z; }
inline void vec4::agb(const simdfloat& _val) { a = _val; g = _val; b = _val; }
inline void vec4::agbr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { a = _val0; g = _val1; b = _val2; r = _val3; }
inline void vec4::agbr(const vec4& _val) { a = _val.x; g = _val.y; b = _val.z; r = _val.w; }
inline void vec4::agbr(const simdfloat& _val) { a = _val; g = _val; b = _val; r = _val; }
inline void vec4::agr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { a = _val0; g = _val1; r = _val2; }
inline void vec4::agr(const vec3& _val) { a = _val.x; g = _val.y; r = _val.z; }
inline void vec4::agr(const simdfloat& _val) { a = _val; g = _val; r = _val; }
inline void vec4::agrb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { a = _val0; g = _val1; r = _val2; b = _val3; }
inline void vec4::agrb(const vec4& _val) { a = _val.x; g = _val.y; r = _val.z; b = _val.w; }
inline void vec4::agrb(const simdfloat& _val) { a = _val; g = _val; r = _val; b = _val; }
inline void vec4::ar(const simdfloat& _val0, const simdfloat& _val1) { a = _val0; r = _val1; }
inline void vec4::ar(const vec2& _val) { a = _val.x; r = _val.y; }
inline void vec4::ar(const simdfloat& _val) { a = _val; r = _val; }
inline void vec4::arb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { a = _val0; r = _val1; b = _val2; }
inline void vec4::arb(const vec3& _val) { a = _val.x; r = _val.y; b = _val.z; }
inline void vec4::arb(const simdfloat& _val) { a = _val; r = _val; b = _val; }
inline void vec4::arbg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { a = _val0; r = _val1; b = _val2; g = _val3; }
inline void vec4::arbg(const vec4& _val) { a = _val.x; r = _val.y; b = _val.z; g = _val.w; }
inline void vec4::arbg(const simdfloat& _val) { a = _val; r = _val; b = _val; g = _val; }
inline void vec4::arg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { a = _val0; r = _val1; g = _val2; }
inline void vec4::arg(const vec3& _val) { a = _val.x; r = _val.y; g = _val.z; }
inline void vec4::arg(const simdfloat& _val) { a = _val; r = _val; g = _val; }
inline void vec4::argb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { a = _val0; r = _val1; g = _val2; b = _val3; }
inline void vec4::argb(const vec4& _val) { a = _val.x; r = _val.y; g = _val.z; b = _val.w; }
inline void vec4::argb(const simdfloat& _val) { a = _val; r = _val; g = _val; b = _val; }
inline void vec4::ba(const simdfloat& _val0, const simdfloat& _val1) { b = _val0; a = _val1; }
inline void vec4::ba(const vec2& _val) { b = _val.x; a = _val.y; }
inline void vec4::ba(const simdfloat& _val) { b = _val; a = _val; }
inline void vec4::bag(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { b = _val0; a = _val1; g = _val2; }
inline void vec4::bag(const vec3& _val) { b = _val.x; a = _val.y; g = _val.z; }
inline void vec4::bag(const simdfloat& _val) { b = _val; a = _val; g = _val; }
inline void vec4::bagr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { b = _val0; a = _val1; g = _val2; r = _val3; }
inline void vec4::bagr(const vec4& _val) { b = _val.x; a = _val.y; g = _val.z; r = _val.w; }
inline void vec4::bagr(const simdfloat& _val) { b = _val; a = _val; g = _val; r = _val; }
inline void vec4::bar(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { b = _val0; a = _val1; r = _val2; }
inline void vec4::bar(const vec3& _val) { b = _val.x; a = _val.y; r = _val.z; }
inline void vec4::bar(const simdfloat& _val) { b = _val; a = _val; r = _val; }
inline void vec4::barg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { b = _val0; a = _val1; r = _val2; g = _val3; }
inline void vec4::barg(const vec4& _val) { b = _val.x; a = _val.y; r = _val.z; g = _val.w; }
inline void vec4::barg(const simdfloat& _val) { b = _val; a = _val; r = _val; g = _val; }
inline void vec4::bg(const simdfloat& _val0, const simdfloat& _val1) { b = _val0; g = _val1; }
inline void vec4::bg(const vec2& _val) { b = _val.x; g = _val.y; }
inline void vec4::bg(const simdfloat& _val) { b = _val; g = _val; }
inline void vec4::bga(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { b = _val0; g = _val1; a = _val2; }
inline void vec4::bga(const vec3& _val) { b = _val.x; g = _val.y; a = _val.z; }
inline void vec4::bga(const simdfloat& _val) { b = _val; g = _val; a = _val; }
inline void vec4::bgar(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { b = _val0; g = _val1; a = _val2; r = _val3; }
inline void vec4::bgar(const vec4& _val) { b = _val.x; g = _val.y; a = _val.z; r = _val.w; }
inline void vec4::bgar(const simdfloat& _val) { b = _val; g = _val; a = _val; r = _val; }
inline void vec4::bgr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { b = _val0; g = _val1; r = _val2; }
inline void vec4::bgr(const vec3& _val) { b = _val.x; g = _val.y; r = _val.z; }
inline void vec4::bgr(const simdfloat& _val) { b = _val; g = _val; r = _val; }
inline void vec4::bgra(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { b = _val0; g = _val1; r = _val2; a = _val3; }
inline void vec4::bgra(const vec4& _val) { b = _val.x; g = _val.y; r = _val.z; a = _val.w; }
inline void vec4::bgra(const simdfloat& _val) { b = _val; g = _val; r = _val; a = _val; }
inline void vec4::br(const simdfloat& _val0, const simdfloat& _val1) { b = _val0; r = _val1; }
inline void vec4::br(const vec2& _val) { b = _val.x; r = _val.y; }
inline void vec4::br(const simdfloat& _val) { b = _val; r = _val; }
inline void vec4::bra(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { b = _val0; r = _val1; a = _val2; }
inline void vec4::bra(const vec3& _val) { b = _val.x; r = _val.y; a = _val.z; }
inline void vec4::bra(const simdfloat& _val) { b = _val; r = _val; a = _val; }
inline void vec4::brag(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { b = _val0; r = _val1; a = _val2; g = _val3; }
inline void vec4::brag(const vec4& _val) { b = _val.x; r = _val.y; a = _val.z; g = _val.w; }
inline void vec4::brag(const simdfloat& _val) { b = _val; r = _val; a = _val; g = _val; }
inline void vec4::brg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { b = _val0; r = _val1; g = _val2; }
inline void vec4::brg(const vec3& _val) { b = _val.x; r = _val.y; g = _val.z; }
inline void vec4::brg(const simdfloat& _val) { b = _val; r = _val; g = _val; }
inline void vec4::brga(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { b = _val0; r = _val1; g = _val2; a = _val3; }
inline void vec4::brga(const vec4& _val) { b = _val.x; r = _val.y; g = _val.z; a = _val.w; }
inline void vec4::brga(const simdfloat& _val) { b = _val; r = _val; g = _val; a = _val; }
inline void vec4::ga(const simdfloat& _val0, const simdfloat& _val1) { g = _val0; a = _val1; }
inline void vec4::ga(const vec2& _val) { g = _val.x; a = _val.y; }
inline void vec4::ga(const simdfloat& _val) { g = _val; a = _val; }
inline void vec4::gab(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { g = _val0; a = _val1; b = _val2; }
inline void vec4::gab(const vec3& _val) { g = _val.x; a = _val.y; b = _val.z; }
inline void vec4::gab(const simdfloat& _val) { g = _val; a = _val; b = _val; }
inline void vec4::gabr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { g = _val0; a = _val1; b = _val2; r = _val3; }
inline void vec4::gabr(const vec4& _val) { g = _val.x; a = _val.y; b = _val.z; r = _val.w; }
inline void vec4::gabr(const simdfloat& _val) { g = _val; a = _val; b = _val; r = _val; }
inline void vec4::gar(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { g = _val0; a = _val1; r = _val2; }
inline void vec4::gar(const vec3& _val) { g = _val.x; a = _val.y; r = _val.z; }
inline void vec4::gar(const simdfloat& _val) { g = _val; a = _val; r = _val; }
inline void vec4::garb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { g = _val0; a = _val1; r = _val2; b = _val3; }
inline void vec4::garb(const vec4& _val) { g = _val.x; a = _val.y; r = _val.z; b = _val.w; }
inline void vec4::garb(const simdfloat& _val) { g = _val; a = _val; r = _val; b = _val; }
inline void vec4::gb(const simdfloat& _val0, const simdfloat& _val1) { g = _val0; b = _val1; }
inline void vec4::gb(const vec2& _val) { g = _val.x; b = _val.y; }
inline void vec4::gb(const simdfloat& _val) { g = _val; b = _val; }
inline void vec4::gba(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { g = _val0; b = _val1; a = _val2; }
inline void vec4::gba(const vec3& _val) { g = _val.x; b = _val.y; a = _val.z; }
inline void vec4::gba(const simdfloat& _val) { g = _val; b = _val; a = _val; }
inline void vec4::gbar(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { g = _val0; b = _val1; a = _val2; r = _val3; }
inline void vec4::gbar(const vec4& _val) { g = _val.x; b = _val.y; a = _val.z; r = _val.w; }
inline void vec4::gbar(const simdfloat& _val) { g = _val; b = _val; a = _val; r = _val; }
inline void vec4::gbr(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { g = _val0; b = _val1; r = _val2; }
inline void vec4::gbr(const vec3& _val) { g = _val.x; b = _val.y; r = _val.z; }
inline void vec4::gbr(const simdfloat& _val) { g = _val; b = _val; r = _val; }
inline void vec4::gbra(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { g = _val0; b = _val1; r = _val2; a = _val3; }
inline void vec4::gbra(const vec4& _val) { g = _val.x; b = _val.y; r = _val.z; a = _val.w; }
inline void vec4::gbra(const simdfloat& _val) { g = _val; b = _val; r = _val; a = _val; }
inline void vec4::gr(const simdfloat& _val0, const simdfloat& _val1) { g = _val0; r = _val1; }
inline void vec4::gr(const vec2& _val) { g = _val.x; r = _val.y; }
inline void vec4::gr(const simdfloat& _val) { g = _val; r = _val; }
inline void vec4::gra(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { g = _val0; r = _val1; a = _val2; }
inline void vec4::gra(const vec3& _val) { g = _val.x; r = _val.y; a = _val.z; }
inline void vec4::gra(const simdfloat& _val) { g = _val; r = _val; a = _val; }
inline void vec4::grab(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { g = _val0; r = _val1; a = _val2; b = _val3; }
inline void vec4::grab(const vec4& _val) { g = _val.x; r = _val.y; a = _val.z; b = _val.w; }
inline void vec4::grab(const simdfloat& _val) { g = _val; r = _val; a = _val; b = _val; }
inline void vec4::grb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { g = _val0; r = _val1; b = _val2; }
inline void vec4::grb(const vec3& _val) { g = _val.x; r = _val.y; b = _val.z; }
inline void vec4::grb(const simdfloat& _val) { g = _val; r = _val; b = _val; }
inline void vec4::grba(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { g = _val0; r = _val1; b = _val2; a = _val3; }
inline void vec4::grba(const vec4& _val) { g = _val.x; r = _val.y; b = _val.z; a = _val.w; }
inline void vec4::grba(const simdfloat& _val) { g = _val; r = _val; b = _val; a = _val; }
inline void vec4::ra(const simdfloat& _val0, const simdfloat& _val1) { r = _val0; a = _val1; }
inline void vec4::ra(const vec2& _val) { r = _val.x; a = _val.y; }
inline void vec4::ra(const simdfloat& _val) { r = _val; a = _val; }
inline void vec4::rab(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { r = _val0; a = _val1; b = _val2; }
inline void vec4::rab(const vec3& _val) { r = _val.x; a = _val.y; b = _val.z; }
inline void vec4::rab(const simdfloat& _val) { r = _val; a = _val; b = _val; }
inline void vec4::rabg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { r = _val0; a = _val1; b = _val2; g = _val3; }
inline void vec4::rabg(const vec4& _val) { r = _val.x; a = _val.y; b = _val.z; g = _val.w; }
inline void vec4::rabg(const simdfloat& _val) { r = _val; a = _val; b = _val; g = _val; }
inline void vec4::rag(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { r = _val0; a = _val1; g = _val2; }
inline void vec4::rag(const vec3& _val) { r = _val.x; a = _val.y; g = _val.z; }
inline void vec4::rag(const simdfloat& _val) { r = _val; a = _val; g = _val; }
inline void vec4::ragb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { r = _val0; a = _val1; g = _val2; b = _val3; }
inline void vec4::ragb(const vec4& _val) { r = _val.x; a = _val.y; g = _val.z; b = _val.w; }
inline void vec4::ragb(const simdfloat& _val) { r = _val; a = _val; g = _val; b = _val; }
inline void vec4::rb(const simdfloat& _val0, const simdfloat& _val1) { r = _val0; b = _val1; }
inline void vec4::rb(const vec2& _val) { r = _val.x; b = _val.y; }
inline void vec4::rb(const simdfloat& _val) { r = _val; b = _val; }
inline void vec4::rba(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { r = _val0; b = _val1; a = _val2; }
inline void vec4::rba(const vec3& _val) { r = _val.x; b = _val.y; a = _val.z; }
inline void vec4::rba(const simdfloat& _val) { r = _val; b = _val; a = _val; }
inline void vec4::rbag(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { r = _val0; b = _val1; a = _val2; g = _val3; }
inline void vec4::rbag(const vec4& _val) { r = _val.x; b = _val.y; a = _val.z; g = _val.w; }
inline void vec4::rbag(const simdfloat& _val) { r = _val; b = _val; a = _val; g = _val; }
inline void vec4::rbg(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { r = _val0; b = _val1; g = _val2; }
inline void vec4::rbg(const vec3& _val) { r = _val.x; b = _val.y; g = _val.z; }
inline void vec4::rbg(const simdfloat& _val) { r = _val; b = _val; g = _val; }
inline void vec4::rbga(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { r = _val0; b = _val1; g = _val2; a = _val3; }
inline void vec4::rbga(const vec4& _val) { r = _val.x; b = _val.y; g = _val.z; a = _val.w; }
inline void vec4::rbga(const simdfloat& _val) { r = _val; b = _val; g = _val; a = _val; }
inline void vec4::rg(const simdfloat& _val0, const simdfloat& _val1) { r = _val0; g = _val1; }
inline void vec4::rg(const vec2& _val) { r = _val.x; g = _val.y; }
inline void vec4::rg(const simdfloat& _val) { r = _val; g = _val; }
inline void vec4::rga(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { r = _val0; g = _val1; a = _val2; }
inline void vec4::rga(const vec3& _val) { r = _val.x; g = _val.y; a = _val.z; }
inline void vec4::rga(const simdfloat& _val) { r = _val; g = _val; a = _val; }
inline void vec4::rgab(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { r = _val0; g = _val1; a = _val2; b = _val3; }
inline void vec4::rgab(const vec4& _val) { r = _val.x; g = _val.y; a = _val.z; b = _val.w; }
inline void vec4::rgab(const simdfloat& _val) { r = _val; g = _val; a = _val; b = _val; }
inline void vec4::rgb(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { r = _val0; g = _val1; b = _val2; }
inline void vec4::rgb(const vec3& _val) { r = _val.x; g = _val.y; b = _val.z; }
inline void vec4::rgb(const simdfloat& _val) { r = _val; g = _val; b = _val; }
inline void vec4::rgba(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { r = _val0; g = _val1; b = _val2; a = _val3; }
inline void vec4::rgba(const vec4& _val) { r = _val.x; g = _val.y; b = _val.z; a = _val.w; }
inline void vec4::rgba(const simdfloat& _val) { r = _val; g = _val; b = _val; a = _val; }
inline void vec4::qs(const simdfloat& _val0, const simdfloat& _val1) { q = _val0; s = _val1; }
inline void vec4::qs(const vec2& _val) { q = _val.s; s = _val.t; }
inline void vec4::qs(const simdfloat& _val) { q = _val; s = _val; }
inline void vec4::qst(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { q = _val0; s = _val1; t = _val2; }
inline void vec4::qst(const vec3& _val) { q = _val.s; s = _val.t; t = _val.p; }
inline void vec4::qst(const simdfloat& _val) { q = _val; s = _val; t = _val; }
inline void vec4::qstp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { q = _val0; s = _val1; t = _val2; p = _val3; }
inline void vec4::qstp(const vec4& _val) { q = _val.s; s = _val.t; t = _val.p; p = _val.q; }
inline void vec4::qstp(const simdfloat& _val) { q = _val; s = _val; t = _val; p = _val; }
inline void vec4::qsp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { q = _val0; s = _val1; p = _val2; }
inline void vec4::qsp(const vec3& _val) { q = _val.s; s = _val.t; p = _val.p; }
inline void vec4::qsp(const simdfloat& _val) { q = _val; s = _val; p = _val; }
inline void vec4::qspt(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { q = _val0; s = _val1; p = _val2; t = _val3; }
inline void vec4::qspt(const vec4& _val) { q = _val.s; s = _val.t; p = _val.p; t = _val.q; }
inline void vec4::qspt(const simdfloat& _val) { q = _val; s = _val; p = _val; t = _val; }
inline void vec4::qt(const simdfloat& _val0, const simdfloat& _val1) { q = _val0; t = _val1; }
inline void vec4::qt(const vec2& _val) { q = _val.s; t = _val.t; }
inline void vec4::qt(const simdfloat& _val) { q = _val; t = _val; }
inline void vec4::qts(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { q = _val0; t = _val1; s = _val2; }
inline void vec4::qts(const vec3& _val) { q = _val.s; t = _val.t; s = _val.p; }
inline void vec4::qts(const simdfloat& _val) { q = _val; t = _val; s = _val; }
inline void vec4::qtsp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { q = _val0; t = _val1; s = _val2; p = _val3; }
inline void vec4::qtsp(const vec4& _val) { q = _val.s; t = _val.t; s = _val.p; p = _val.q; }
inline void vec4::qtsp(const simdfloat& _val) { q = _val; t = _val; s = _val; p = _val; }
inline void vec4::qtp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { q = _val0; t = _val1; p = _val2; }
inline void vec4::qtp(const vec3& _val) { q = _val.s; t = _val.t; p = _val.p; }
inline void vec4::qtp(const simdfloat& _val) { q = _val; t = _val; p = _val; }
inline void vec4::qtps(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { q = _val0; t = _val1; p = _val2; s = _val3; }
inline void vec4::qtps(const vec4& _val) { q = _val.s; t = _val.t; p = _val.p; s = _val.q; }
inline void vec4::qtps(const simdfloat& _val) { q = _val; t = _val; p = _val; s = _val; }
inline void vec4::qp(const simdfloat& _val0, const simdfloat& _val1) { q = _val0; p = _val1; }
inline void vec4::qp(const vec2& _val) { q = _val.s; p = _val.t; }
inline void vec4::qp(const simdfloat& _val) { q = _val; p = _val; }
inline void vec4::qps(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { q = _val0; p = _val1; s = _val2; }
inline void vec4::qps(const vec3& _val) { q = _val.s; p = _val.t; s = _val.p; }
inline void vec4::qps(const simdfloat& _val) { q = _val; p = _val; s = _val; }
inline void vec4::qpst(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { q = _val0; p = _val1; s = _val2; t = _val3; }
inline void vec4::qpst(const vec4& _val) { q = _val.s; p = _val.t; s = _val.p; t = _val.q; }
inline void vec4::qpst(const simdfloat& _val) { q = _val; p = _val; s = _val; t = _val; }
inline void vec4::qpt(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { q = _val0; p = _val1; t = _val2; }
inline void vec4::qpt(const vec3& _val) { q = _val.s; p = _val.t; t = _val.p; }
inline void vec4::qpt(const simdfloat& _val) { q = _val; p = _val; t = _val; }
inline void vec4::qpts(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { q = _val0; p = _val1; t = _val2; s = _val3; }
inline void vec4::qpts(const vec4& _val) { q = _val.s; p = _val.t; t = _val.p; s = _val.q; }
inline void vec4::qpts(const simdfloat& _val) { q = _val; p = _val; t = _val; s = _val; }
inline void vec4::sq(const simdfloat& _val0, const simdfloat& _val1) { s = _val0; q = _val1; }
inline void vec4::sq(const vec2& _val) { s = _val.s; q = _val.t; }
inline void vec4::sq(const simdfloat& _val) { s = _val; q = _val; }
inline void vec4::sqt(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { s = _val0; q = _val1; t = _val2; }
inline void vec4::sqt(const vec3& _val) { s = _val.s; q = _val.t; t = _val.p; }
inline void vec4::sqt(const simdfloat& _val) { s = _val; q = _val; t = _val; }
inline void vec4::sqtp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { s = _val0; q = _val1; t = _val2; p = _val3; }
inline void vec4::sqtp(const vec4& _val) { s = _val.s; q = _val.t; t = _val.p; p = _val.q; }
inline void vec4::sqtp(const simdfloat& _val) { s = _val; q = _val; t = _val; p = _val; }
inline void vec4::sqp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { s = _val0; q = _val1; p = _val2; }
inline void vec4::sqp(const vec3& _val) { s = _val.s; q = _val.t; p = _val.p; }
inline void vec4::sqp(const simdfloat& _val) { s = _val; q = _val; p = _val; }
inline void vec4::sqpt(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { s = _val0; q = _val1; p = _val2; t = _val3; }
inline void vec4::sqpt(const vec4& _val) { s = _val.s; q = _val.t; p = _val.p; t = _val.q; }
inline void vec4::sqpt(const simdfloat& _val) { s = _val; q = _val; p = _val; t = _val; }
inline void vec4::st(const simdfloat& _val0, const simdfloat& _val1) { s = _val0; t = _val1; }
inline void vec4::st(const vec2& _val) { s = _val.s; t = _val.t; }
inline void vec4::st(const simdfloat& _val) { s = _val; t = _val; }
inline void vec4::stq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { s = _val0; t = _val1; q = _val2; }
inline void vec4::stq(const vec3& _val) { s = _val.s; t = _val.t; q = _val.p; }
inline void vec4::stq(const simdfloat& _val) { s = _val; t = _val; q = _val; }
inline void vec4::stqp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { s = _val0; t = _val1; q = _val2; p = _val3; }
inline void vec4::stqp(const vec4& _val) { s = _val.s; t = _val.t; q = _val.p; p = _val.q; }
inline void vec4::stqp(const simdfloat& _val) { s = _val; t = _val; q = _val; p = _val; }
inline void vec4::stp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { s = _val0; t = _val1; p = _val2; }
inline void vec4::stp(const vec3& _val) { s = _val.s; t = _val.t; p = _val.p; }
inline void vec4::stp(const simdfloat& _val) { s = _val; t = _val; p = _val; }
inline void vec4::stpq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { s = _val0; t = _val1; p = _val2; q = _val3; }
inline void vec4::stpq(const vec4& _val) { s = _val.s; t = _val.t; p = _val.p; q = _val.q; }
inline void vec4::stpq(const simdfloat& _val) { s = _val; t = _val; p = _val; q = _val; }
inline void vec4::sp(const simdfloat& _val0, const simdfloat& _val1) { s = _val0; p = _val1; }
inline void vec4::sp(const vec2& _val) { s = _val.s; p = _val.t; }
inline void vec4::sp(const simdfloat& _val) { s = _val; p = _val; }
inline void vec4::spq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { s = _val0; p = _val1; q = _val2; }
inline void vec4::spq(const vec3& _val) { s = _val.s; p = _val.t; q = _val.p; }
inline void vec4::spq(const simdfloat& _val) { s = _val; p = _val; q = _val; }
inline void vec4::spqt(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { s = _val0; p = _val1; q = _val2; t = _val3; }
inline void vec4::spqt(const vec4& _val) { s = _val.s; p = _val.t; q = _val.p; t = _val.q; }
inline void vec4::spqt(const simdfloat& _val) { s = _val; p = _val; q = _val; t = _val; }
inline void vec4::spt(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { s = _val0; p = _val1; t = _val2; }
inline void vec4::spt(const vec3& _val) { s = _val.s; p = _val.t; t = _val.p; }
inline void vec4::spt(const simdfloat& _val) { s = _val; p = _val; t = _val; }
inline void vec4::sptq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { s = _val0; p = _val1; t = _val2; q = _val3; }
inline void vec4::sptq(const vec4& _val) { s = _val.s; p = _val.t; t = _val.p; q = _val.q; }
inline void vec4::sptq(const simdfloat& _val) { s = _val; p = _val; t = _val; q = _val; }
inline void vec4::tq(const simdfloat& _val0, const simdfloat& _val1) { t = _val0; q = _val1; }
inline void vec4::tq(const vec2& _val) { t = _val.s; q = _val.t; }
inline void vec4::tq(const simdfloat& _val) { t = _val; q = _val; }
inline void vec4::tqs(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { t = _val0; q = _val1; s = _val2; }
inline void vec4::tqs(const vec3& _val) { t = _val.s; q = _val.t; s = _val.p; }
inline void vec4::tqs(const simdfloat& _val) { t = _val; q = _val; s = _val; }
inline void vec4::tqsp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { t = _val0; q = _val1; s = _val2; p = _val3; }
inline void vec4::tqsp(const vec4& _val) { t = _val.s; q = _val.t; s = _val.p; p = _val.q; }
inline void vec4::tqsp(const simdfloat& _val) { t = _val; q = _val; s = _val; p = _val; }
inline void vec4::tqp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { t = _val0; q = _val1; p = _val2; }
inline void vec4::tqp(const vec3& _val) { t = _val.s; q = _val.t; p = _val.p; }
inline void vec4::tqp(const simdfloat& _val) { t = _val; q = _val; p = _val; }
inline void vec4::tqps(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { t = _val0; q = _val1; p = _val2; s = _val3; }
inline void vec4::tqps(const vec4& _val) { t = _val.s; q = _val.t; p = _val.p; s = _val.q; }
inline void vec4::tqps(const simdfloat& _val) { t = _val; q = _val; p = _val; s = _val; }
inline void vec4::ts(const simdfloat& _val0, const simdfloat& _val1) { t = _val0; s = _val1; }
inline void vec4::ts(const vec2& _val) { t = _val.s; s = _val.t; }
inline void vec4::ts(const simdfloat& _val) { t = _val; s = _val; }
inline void vec4::tsq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { t = _val0; s = _val1; q = _val2; }
inline void vec4::tsq(const vec3& _val) { t = _val.s; s = _val.t; q = _val.p; }
inline void vec4::tsq(const simdfloat& _val) { t = _val; s = _val; q = _val; }
inline void vec4::tsqp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { t = _val0; s = _val1; q = _val2; p = _val3; }
inline void vec4::tsqp(const vec4& _val) { t = _val.s; s = _val.t; q = _val.p; p = _val.q; }
inline void vec4::tsqp(const simdfloat& _val) { t = _val; s = _val; q = _val; p = _val; }
inline void vec4::tsp(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { t = _val0; s = _val1; p = _val2; }
inline void vec4::tsp(const vec3& _val) { t = _val.s; s = _val.t; p = _val.p; }
inline void vec4::tsp(const simdfloat& _val) { t = _val; s = _val; p = _val; }
inline void vec4::tspq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { t = _val0; s = _val1; p = _val2; q = _val3; }
inline void vec4::tspq(const vec4& _val) { t = _val.s; s = _val.t; p = _val.p; q = _val.q; }
inline void vec4::tspq(const simdfloat& _val) { t = _val; s = _val; p = _val; q = _val; }
inline void vec4::tp(const simdfloat& _val0, const simdfloat& _val1) { t = _val0; p = _val1; }
inline void vec4::tp(const vec2& _val) { t = _val.s; p = _val.t; }
inline void vec4::tp(const simdfloat& _val) { t = _val; p = _val; }
inline void vec4::tpq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { t = _val0; p = _val1; q = _val2; }
inline void vec4::tpq(const vec3& _val) { t = _val.s; p = _val.t; q = _val.p; }
inline void vec4::tpq(const simdfloat& _val) { t = _val; p = _val; q = _val; }
inline void vec4::tpqs(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { t = _val0; p = _val1; q = _val2; s = _val3; }
inline void vec4::tpqs(const vec4& _val) { t = _val.s; p = _val.t; q = _val.p; s = _val.q; }
inline void vec4::tpqs(const simdfloat& _val) { t = _val; p = _val; q = _val; s = _val; }
inline void vec4::tps(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { t = _val0; p = _val1; s = _val2; }
inline void vec4::tps(const vec3& _val) { t = _val.s; p = _val.t; s = _val.p; }
inline void vec4::tps(const simdfloat& _val) { t = _val; p = _val; s = _val; }
inline void vec4::tpsq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { t = _val0; p = _val1; s = _val2; q = _val3; }
inline void vec4::tpsq(const vec4& _val) { t = _val.s; p = _val.t; s = _val.p; q = _val.q; }
inline void vec4::tpsq(const simdfloat& _val) { t = _val; p = _val; s = _val; q = _val; }
inline void vec4::pq(const simdfloat& _val0, const simdfloat& _val1) { p = _val0; q = _val1; }
inline void vec4::pq(const vec2& _val) { p = _val.s; q = _val.t; }
inline void vec4::pq(const simdfloat& _val) { p = _val; q = _val; }
inline void vec4::pqs(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { p = _val0; q = _val1; s = _val2; }
inline void vec4::pqs(const vec3& _val) { p = _val.s; q = _val.t; s = _val.p; }
inline void vec4::pqs(const simdfloat& _val) { p = _val; q = _val; s = _val; }
inline void vec4::pqst(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { p = _val0; q = _val1; s = _val2; t = _val3; }
inline void vec4::pqst(const vec4& _val) { p = _val.s; q = _val.t; s = _val.p; t = _val.q; }
inline void vec4::pqst(const simdfloat& _val) { p = _val; q = _val; s = _val; t = _val; }
inline void vec4::pqt(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { p = _val0; q = _val1; t = _val2; }
inline void vec4::pqt(const vec3& _val) { p = _val.s; q = _val.t; t = _val.p; }
inline void vec4::pqt(const simdfloat& _val) { p = _val; q = _val; t = _val; }
inline void vec4::pqts(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { p = _val0; q = _val1; t = _val2; s = _val3; }
inline void vec4::pqts(const vec4& _val) { p = _val.s; q = _val.t; t = _val.p; s = _val.q; }
inline void vec4::pqts(const simdfloat& _val) { p = _val; q = _val; t = _val; s = _val; }
inline void vec4::ps(const simdfloat& _val0, const simdfloat& _val1) { p = _val0; s = _val1; }
inline void vec4::ps(const vec2& _val) { p = _val.s; s = _val.t; }
inline void vec4::ps(const simdfloat& _val) { p = _val; s = _val; }
inline void vec4::psq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { p = _val0; s = _val1; q = _val2; }
inline void vec4::psq(const vec3& _val) { p = _val.s; s = _val.t; q = _val.p; }
inline void vec4::psq(const simdfloat& _val) { p = _val; s = _val; q = _val; }
inline void vec4::psqt(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { p = _val0; s = _val1; q = _val2; t = _val3; }
inline void vec4::psqt(const vec4& _val) { p = _val.s; s = _val.t; q = _val.p; t = _val.q; }
inline void vec4::psqt(const simdfloat& _val) { p = _val; s = _val; q = _val; t = _val; }
inline void vec4::pst(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { p = _val0; s = _val1; t = _val2; }
inline void vec4::pst(const vec3& _val) { p = _val.s; s = _val.t; t = _val.p; }
inline void vec4::pst(const simdfloat& _val) { p = _val; s = _val; t = _val; }
inline void vec4::pstq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { p = _val0; s = _val1; t = _val2; q = _val3; }
inline void vec4::pstq(const vec4& _val) { p = _val.s; s = _val.t; t = _val.p; q = _val.q; }
inline void vec4::pstq(const simdfloat& _val) { p = _val; s = _val; t = _val; q = _val; }
inline void vec4::pt(const simdfloat& _val0, const simdfloat& _val1) { p = _val0; t = _val1; }
inline void vec4::pt(const vec2& _val) { p = _val.s; t = _val.t; }
inline void vec4::pt(const simdfloat& _val) { p = _val; t = _val; }
inline void vec4::ptq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { p = _val0; t = _val1; q = _val2; }
inline void vec4::ptq(const vec3& _val) { p = _val.s; t = _val.t; q = _val.p; }
inline void vec4::ptq(const simdfloat& _val) { p = _val; t = _val; q = _val; }
inline void vec4::ptqs(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { p = _val0; t = _val1; q = _val2; s = _val3; }
inline void vec4::ptqs(const vec4& _val) { p = _val.s; t = _val.t; q = _val.p; s = _val.q; }
inline void vec4::ptqs(const simdfloat& _val) { p = _val; t = _val; q = _val; s = _val; }
inline void vec4::pts(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { p = _val0; t = _val1; s = _val2; }
inline void vec4::pts(const vec3& _val) { p = _val.s; t = _val.t; s = _val.p; }
inline void vec4::pts(const simdfloat& _val) { p = _val; t = _val; s = _val; }
inline void vec4::ptsq(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { p = _val0; t = _val1; s = _val2; q = _val3; }
inline void vec4::ptsq(const vec4& _val) { p = _val.s; t = _val.t; s = _val.p; q = _val.q; }
inline void vec4::ptsq(const simdfloat& _val) { p = _val; t = _val; s = _val; q = _val; }
inline void vec4::wx(const simdfloat& _val0, const simdfloat& _val1) { w = _val0; x = _val1; }
inline void vec4::wx(const vec2& _val) { w = _val.x; x = _val.y; }
inline void vec4::wx(const simdfloat& _val) { w = _val; x = _val; }
inline void vec4::wxy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { w = _val0; x = _val1; y = _val2; }
inline void vec4::wxy(const vec3& _val) { w = _val.x; x = _val.y; y = _val.z; }
inline void vec4::wxy(const simdfloat& _val) { w = _val; x = _val; y = _val; }
inline void vec4::wxyz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { w = _val0; x = _val1; y = _val2; z = _val3; }
inline void vec4::wxyz(const vec4& _val) { w = _val.x; x = _val.y; y = _val.z; z = _val.w; }
inline void vec4::wxyz(const simdfloat& _val) { w = _val; x = _val; y = _val; z = _val; }
inline void vec4::wxz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { w = _val0; x = _val1; z = _val2; }
inline void vec4::wxz(const vec3& _val) { w = _val.x; x = _val.y; z = _val.z; }
inline void vec4::wxz(const simdfloat& _val) { w = _val; x = _val; z = _val; }
inline void vec4::wxzy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { w = _val0; x = _val1; z = _val2; y = _val3; }
inline void vec4::wxzy(const vec4& _val) { w = _val.x; x = _val.y; z = _val.z; y = _val.w; }
inline void vec4::wxzy(const simdfloat& _val) { w = _val; x = _val; z = _val; y = _val; }
inline void vec4::wy(const simdfloat& _val0, const simdfloat& _val1) { w = _val0; y = _val1; }
inline void vec4::wy(const vec2& _val) { w = _val.x; y = _val.y; }
inline void vec4::wy(const simdfloat& _val) { w = _val; y = _val; }
inline void vec4::wyx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { w = _val0; y = _val1; x = _val2; }
inline void vec4::wyx(const vec3& _val) { w = _val.x; y = _val.y; x = _val.z; }
inline void vec4::wyx(const simdfloat& _val) { w = _val; y = _val; x = _val; }
inline void vec4::wyxz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { w = _val0; y = _val1; x = _val2; z = _val3; }
inline void vec4::wyxz(const vec4& _val) { w = _val.x; y = _val.y; x = _val.z; z = _val.w; }
inline void vec4::wyxz(const simdfloat& _val) { w = _val; y = _val; x = _val; z = _val; }
inline void vec4::wyz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { w = _val0; y = _val1; z = _val2; }
inline void vec4::wyz(const vec3& _val) { w = _val.x; y = _val.y; z = _val.z; }
inline void vec4::wyz(const simdfloat& _val) { w = _val; y = _val; z = _val; }
inline void vec4::wyzx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { w = _val0; y = _val1; z = _val2; x = _val3; }
inline void vec4::wyzx(const vec4& _val) { w = _val.x; y = _val.y; z = _val.z; x = _val.w; }
inline void vec4::wyzx(const simdfloat& _val) { w = _val; y = _val; z = _val; x = _val; }
inline void vec4::wz(const simdfloat& _val0, const simdfloat& _val1) { w = _val0; z = _val1; }
inline void vec4::wz(const vec2& _val) { w = _val.x; z = _val.y; }
inline void vec4::wz(const simdfloat& _val) { w = _val; z = _val; }
inline void vec4::wzx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { w = _val0; z = _val1; x = _val2; }
inline void vec4::wzx(const vec3& _val) { w = _val.x; z = _val.y; x = _val.z; }
inline void vec4::wzx(const simdfloat& _val) { w = _val; z = _val; x = _val; }
inline void vec4::wzxy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { w = _val0; z = _val1; x = _val2; y = _val3; }
inline void vec4::wzxy(const vec4& _val) { w = _val.x; z = _val.y; x = _val.z; y = _val.w; }
inline void vec4::wzxy(const simdfloat& _val) { w = _val; z = _val; x = _val; y = _val; }
inline void vec4::wzy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { w = _val0; z = _val1; y = _val2; }
inline void vec4::wzy(const vec3& _val) { w = _val.x; z = _val.y; y = _val.z; }
inline void vec4::wzy(const simdfloat& _val) { w = _val; z = _val; y = _val; }
inline void vec4::wzyx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { w = _val0; z = _val1; y = _val2; x = _val3; }
inline void vec4::wzyx(const vec4& _val) { w = _val.x; z = _val.y; y = _val.z; x = _val.w; }
inline void vec4::wzyx(const simdfloat& _val) { w = _val; z = _val; y = _val; x = _val; }
inline void vec4::xw(const simdfloat& _val0, const simdfloat& _val1) { x = _val0; w = _val1; }
inline void vec4::xw(const vec2& _val) { x = _val.x; w = _val.y; }
inline void vec4::xw(const simdfloat& _val) { x = _val; w = _val; }
inline void vec4::xwy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { x = _val0; w = _val1; y = _val2; }
inline void vec4::xwy(const vec3& _val) { x = _val.x; w = _val.y; y = _val.z; }
inline void vec4::xwy(const simdfloat& _val) { x = _val; w = _val; y = _val; }
inline void vec4::xwyz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { x = _val0; w = _val1; y = _val2; z = _val3; }
inline void vec4::xwyz(const vec4& _val) { x = _val.x; w = _val.y; y = _val.z; z = _val.w; }
inline void vec4::xwyz(const simdfloat& _val) { x = _val; w = _val; y = _val; z = _val; }
inline void vec4::xwz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { x = _val0; w = _val1; z = _val2; }
inline void vec4::xwz(const vec3& _val) { x = _val.x; w = _val.y; z = _val.z; }
inline void vec4::xwz(const simdfloat& _val) { x = _val; w = _val; z = _val; }
inline void vec4::xwzy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { x = _val0; w = _val1; z = _val2; y = _val3; }
inline void vec4::xwzy(const vec4& _val) { x = _val.x; w = _val.y; z = _val.z; y = _val.w; }
inline void vec4::xwzy(const simdfloat& _val) { x = _val; w = _val; z = _val; y = _val; }
inline void vec4::xy(const simdfloat& _val0, const simdfloat& _val1) { x = _val0; y = _val1; }
inline void vec4::xy(const vec2& _val) { x = _val.x; y = _val.y; }
inline void vec4::xy(const simdfloat& _val) { x = _val; y = _val; }
inline void vec4::xyw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { x = _val0; y = _val1; w = _val2; }
inline void vec4::xyw(const vec3& _val) { x = _val.x; y = _val.y; w = _val.z; }
inline void vec4::xyw(const simdfloat& _val) { x = _val; y = _val; w = _val; }
inline void vec4::xywz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { x = _val0; y = _val1; w = _val2; z = _val3; }
inline void vec4::xywz(const vec4& _val) { x = _val.x; y = _val.y; w = _val.z; z = _val.w; }
inline void vec4::xywz(const simdfloat& _val) { x = _val; y = _val; w = _val; z = _val; }
inline void vec4::xyz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { x = _val0; y = _val1; z = _val2; }
inline void vec4::xyz(const vec3& _val) { x = _val.x; y = _val.y; z = _val.z; }
inline void vec4::xyz(const simdfloat& _val) { x = _val; y = _val; z = _val; }
inline void vec4::xyzw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { x = _val0; y = _val1; z = _val2; w = _val3; }
inline void vec4::xyzw(const vec4& _val) { x = _val.x; y = _val.y; z = _val.z; w = _val.w; }
inline void vec4::xyzw(const simdfloat& _val) { x = _val; y = _val; z = _val; w = _val; }
inline void vec4::xz(const simdfloat& _val0, const simdfloat& _val1) { x = _val0; z = _val1; }
inline void vec4::xz(const vec2& _val) { x = _val.x; z = _val.y; }
inline void vec4::xz(const simdfloat& _val) { x = _val; z = _val; }
inline void vec4::xzw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { x = _val0; z = _val1; w = _val2; }
inline void vec4::xzw(const vec3& _val) { x = _val.x; z = _val.y; w = _val.z; }
inline void vec4::xzw(const simdfloat& _val) { x = _val; z = _val; w = _val; }
inline void vec4::xzwy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { x = _val0; z = _val1; w = _val2; y = _val3; }
inline void vec4::xzwy(const vec4& _val) { x = _val.x; z = _val.y; w = _val.z; y = _val.w; }
inline void vec4::xzwy(const simdfloat& _val) { x = _val; z = _val; w = _val; y = _val; }
inline void vec4::xzy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { x = _val0; z = _val1; y = _val2; }
inline void vec4::xzy(const vec3& _val) { x = _val.x; z = _val.y; y = _val.z; }
inline void vec4::xzy(const simdfloat& _val) { x = _val; z = _val; y = _val; }
inline void vec4::xzyw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { x = _val0; z = _val1; y = _val2; w = _val3; }
inline void vec4::xzyw(const vec4& _val) { x = _val.x; z = _val.y; y = _val.z; w = _val.w; }
inline void vec4::xzyw(const simdfloat& _val) { x = _val; z = _val; y = _val; w = _val; }
inline void vec4::yw(const simdfloat& _val0, const simdfloat& _val1) { y = _val0; w = _val1; }
inline void vec4::yw(const vec2& _val) { y = _val.x; w = _val.y; }
inline void vec4::yw(const simdfloat& _val) { y = _val; w = _val; }
inline void vec4::ywx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { y = _val0; w = _val1; x = _val2; }
inline void vec4::ywx(const vec3& _val) { y = _val.x; w = _val.y; x = _val.z; }
inline void vec4::ywx(const simdfloat& _val) { y = _val; w = _val; x = _val; }
inline void vec4::ywxz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { y = _val0; w = _val1; x = _val2; z = _val3; }
inline void vec4::ywxz(const vec4& _val) { y = _val.x; w = _val.y; x = _val.z; z = _val.w; }
inline void vec4::ywxz(const simdfloat& _val) { y = _val; w = _val; x = _val; z = _val; }
inline void vec4::ywz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { y = _val0; w = _val1; z = _val2; }
inline void vec4::ywz(const vec3& _val) { y = _val.x; w = _val.y; z = _val.z; }
inline void vec4::ywz(const simdfloat& _val) { y = _val; w = _val; z = _val; }
inline void vec4::ywzx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { y = _val0; w = _val1; z = _val2; x = _val3; }
inline void vec4::ywzx(const vec4& _val) { y = _val.x; w = _val.y; z = _val.z; x = _val.w; }
inline void vec4::ywzx(const simdfloat& _val) { y = _val; w = _val; z = _val; x = _val; }
inline void vec4::yx(const simdfloat& _val0, const simdfloat& _val1) { y = _val0; x = _val1; }
inline void vec4::yx(const vec2& _val) { y = _val.x; x = _val.y; }
inline void vec4::yx(const simdfloat& _val) { y = _val; x = _val; }
inline void vec4::yxw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { y = _val0; x = _val1; w = _val2; }
inline void vec4::yxw(const vec3& _val) { y = _val.x; x = _val.y; w = _val.z; }
inline void vec4::yxw(const simdfloat& _val) { y = _val; x = _val; w = _val; }
inline void vec4::yxwz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { y = _val0; x = _val1; w = _val2; z = _val3; }
inline void vec4::yxwz(const vec4& _val) { y = _val.x; x = _val.y; w = _val.z; z = _val.w; }
inline void vec4::yxwz(const simdfloat& _val) { y = _val; x = _val; w = _val; z = _val; }
inline void vec4::yxz(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { y = _val0; x = _val1; z = _val2; }
inline void vec4::yxz(const vec3& _val) { y = _val.x; x = _val.y; z = _val.z; }
inline void vec4::yxz(const simdfloat& _val) { y = _val; x = _val; z = _val; }
inline void vec4::yxzw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { y = _val0; x = _val1; z = _val2; w = _val3; }
inline void vec4::yxzw(const vec4& _val) { y = _val.x; x = _val.y; z = _val.z; w = _val.w; }
inline void vec4::yxzw(const simdfloat& _val) { y = _val; x = _val; z = _val; w = _val; }
inline void vec4::yz(const simdfloat& _val0, const simdfloat& _val1) { y = _val0; z = _val1; }
inline void vec4::yz(const vec2& _val) { y = _val.x; z = _val.y; }
inline void vec4::yz(const simdfloat& _val) { y = _val; z = _val; }
inline void vec4::yzw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { y = _val0; z = _val1; w = _val2; }
inline void vec4::yzw(const vec3& _val) { y = _val.x; z = _val.y; w = _val.z; }
inline void vec4::yzw(const simdfloat& _val) { y = _val; z = _val; w = _val; }
inline void vec4::yzwx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { y = _val0; z = _val1; w = _val2; x = _val3; }
inline void vec4::yzwx(const vec4& _val) { y = _val.x; z = _val.y; w = _val.z; x = _val.w; }
inline void vec4::yzwx(const simdfloat& _val) { y = _val; z = _val; w = _val; x = _val; }
inline void vec4::yzx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { y = _val0; z = _val1; x = _val2; }
inline void vec4::yzx(const vec3& _val) { y = _val.x; z = _val.y; x = _val.z; }
inline void vec4::yzx(const simdfloat& _val) { y = _val; z = _val; x = _val; }
inline void vec4::yzxw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { y = _val0; z = _val1; x = _val2; w = _val3; }
inline void vec4::yzxw(const vec4& _val) { y = _val.x; z = _val.y; x = _val.z; w = _val.w; }
inline void vec4::yzxw(const simdfloat& _val) { y = _val; z = _val; x = _val; w = _val; }
inline void vec4::zw(const simdfloat& _val0, const simdfloat& _val1) { z = _val0; w = _val1; }
inline void vec4::zw(const vec2& _val) { z = _val.x; w = _val.y; }
inline void vec4::zw(const simdfloat& _val) { z = _val; w = _val; }
inline void vec4::zwx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { z = _val0; w = _val1; x = _val2; }
inline void vec4::zwx(const vec3& _val) { z = _val.x; w = _val.y; x = _val.z; }
inline void vec4::zwx(const simdfloat& _val) { z = _val; w = _val; x = _val; }
inline void vec4::zwxy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { z = _val0; w = _val1; x = _val2; y = _val3; }
inline void vec4::zwxy(const vec4& _val) { z = _val.x; w = _val.y; x = _val.z; y = _val.w; }
inline void vec4::zwxy(const simdfloat& _val) { z = _val; w = _val; x = _val; y = _val; }
inline void vec4::zwy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { z = _val0; w = _val1; y = _val2; }
inline void vec4::zwy(const vec3& _val) { z = _val.x; w = _val.y; y = _val.z; }
inline void vec4::zwy(const simdfloat& _val) { z = _val; w = _val; y = _val; }
inline void vec4::zwyx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { z = _val0; w = _val1; y = _val2; x = _val3; }
inline void vec4::zwyx(const vec4& _val) { z = _val.x; w = _val.y; y = _val.z; x = _val.w; }
inline void vec4::zwyx(const simdfloat& _val) { z = _val; w = _val; y = _val; x = _val; }
inline void vec4::zx(const simdfloat& _val0, const simdfloat& _val1) { z = _val0; x = _val1; }
inline void vec4::zx(const vec2& _val) { z = _val.x; x = _val.y; }
inline void vec4::zx(const simdfloat& _val) { z = _val; x = _val; }
inline void vec4::zxw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { z = _val0; x = _val1; w = _val2; }
inline void vec4::zxw(const vec3& _val) { z = _val.x; x = _val.y; w = _val.z; }
inline void vec4::zxw(const simdfloat& _val) { z = _val; x = _val; w = _val; }
inline void vec4::zxwy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { z = _val0; x = _val1; w = _val2; y = _val3; }
inline void vec4::zxwy(const vec4& _val) { z = _val.x; x = _val.y; w = _val.z; y = _val.w; }
inline void vec4::zxwy(const simdfloat& _val) { z = _val; x = _val; w = _val; y = _val; }
inline void vec4::zxy(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { z = _val0; x = _val1; y = _val2; }
inline void vec4::zxy(const vec3& _val) { z = _val.x; x = _val.y; y = _val.z; }
inline void vec4::zxy(const simdfloat& _val) { z = _val; x = _val; y = _val; }
inline void vec4::zxyw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { z = _val0; x = _val1; y = _val2; w = _val3; }
inline void vec4::zxyw(const vec4& _val) { z = _val.x; x = _val.y; y = _val.z; w = _val.w; }
inline void vec4::zxyw(const simdfloat& _val) { z = _val; x = _val; y = _val; w = _val; }
inline void vec4::zy(const simdfloat& _val0, const simdfloat& _val1) { z = _val0; y = _val1; }
inline void vec4::zy(const vec2& _val) { z = _val.x; y = _val.y; }
inline void vec4::zy(const simdfloat& _val) { z = _val; y = _val; }
inline void vec4::zyw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { z = _val0; y = _val1; w = _val2; }
inline void vec4::zyw(const vec3& _val) { z = _val.x; y = _val.y; w = _val.z; }
inline void vec4::zyw(const simdfloat& _val) { z = _val; y = _val; w = _val; }
inline void vec4::zywx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { z = _val0; y = _val1; w = _val2; x = _val3; }
inline void vec4::zywx(const vec4& _val) { z = _val.x; y = _val.y; w = _val.z; x = _val.w; }
inline void vec4::zywx(const simdfloat& _val) { z = _val; y = _val; w = _val; x = _val; }
inline void vec4::zyx(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2) { z = _val0; y = _val1; x = _val2; }
inline void vec4::zyx(const vec3& _val) { z = _val.x; y = _val.y; x = _val.z; }
inline void vec4::zyx(const simdfloat& _val) { z = _val; y = _val; x = _val; }
inline void vec4::zyxw(const simdfloat& _val0, const simdfloat& _val1, const simdfloat& _val2, const simdfloat& _val3) { z = _val0; y = _val1; x = _val2; w = _val3; }
inline void vec4::zyxw(const vec4& _val) { z = _val.x; y = _val.y; x = _val.z; w = _val.w; }
inline void vec4::zyxw(const simdfloat& _val) { z = _val; y = _val; x = _val; w = _val; }

#pragma endregion

// cross-type assignment from ivec4 (components use simdfloat's own conversion operator)
inline vec4 vec4::operator=(const ivec4& _v) { x = _v.x; y = _v.y; z = _v.z; w = _v.w; return *this; }

// constructors for vec4
inline vec4::vec4(const float& _f) { x = _f; y = _f; z = _f; w = _f; }

inline vec4::vec4(const simdfloat& _f) { x = _f; y = _f; z = _f; w = _f; }

inline vec4::vec4(const ivec4& _v) { x = _v.x; y = _v.y; z = _v.z; w = _v.w; }

inline vec4::vec4(const simdfloat& _x, const simdfloat& _y, const simdfloat& _z, const simdfloat& _w) { x = _x; y = _y; z = _z; w = _w; }

inline vec4::vec4(const simdfloat& _x, const vec2& _y, const simdfloat& _w) { x = _x; y = _y.x; z = _y.y; w = _w; }

inline vec4::vec4(const simdfloat& _x, const simdfloat& _y, const vec2& _z) { x = _x; y = _y; z = _z.x; w = _z.y; }

inline vec4::vec4(const vec2& _x, const simdfloat& _z, const simdfloat& _w) { x = _x.x; y = _x.y; z = _z; w = _w; }

inline vec4::vec4(const vec3& _x, const simdfloat& _w) { x = _x.x; y = _x.y; z = _x.z; w = _w; }

inline vec4::vec4(const simdfloat& _x, const vec3& _y) { x = _x; y = _y.x; z = _y.y; w = _y.z; }

inline vec4::vec4(const vec2& _x, const vec2& _y) { x = _x.x; y = _x.y; z = _y.x; w = _y.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec4>, int>>
vec4::vec4(const simdfloat& _x, const V& _v) { x = _x; y = _v.x; z = _v.y; w = _v.z; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec3>, int>>
vec4::vec4(const simdfloat& _x, const simdfloat& _y, const V& _v) { x = _x; y = _y; z = _v.x; w = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec4>, int>>
vec4::vec4(const simdfloat& _x, const simdfloat& _y, const V& _v) { x = _x; y = _y; z = _v.x; w = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec2>, int>>
vec4::vec4(const simdfloat& _x, const simdfloat& _y, const simdfloat& _z, const V& _v) { x = _x; y = _y; z = _z; w = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec3>, int>>
vec4::vec4(const simdfloat& _x, const simdfloat& _y, const simdfloat& _z, const V& _v) { x = _x; y = _y; z = _z; w = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, vec4>, int>>
vec4::vec4(const simdfloat& _x, const simdfloat& _y, const simdfloat& _z, const V& _v) { x = _x; y = _y; z = _z; w = _v.x; }

#endif


