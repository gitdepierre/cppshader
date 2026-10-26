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
 
#ifndef SIMD_SWIZZLE_IVEC4_H
#define SIMD_SWIZZLE_IVEC4_H

#include "simd_ivec2.h"
#include "simd_ivec3.h"
#include "simd_ivec4.h"
#include "simd_vec4.h"

#pragma region ivec4 swizzle implementations

// ivec4 swizzle implementations
inline ivec2 ivec4::aa() const { return { a, a }; }
inline ivec3 ivec4::aaa() const { return { a, a, a }; }
inline ivec4 ivec4::aaaa() const { return { a, a, a, a }; }
inline ivec4 ivec4::aaab() const { return { a, a, a, b }; }
inline ivec4 ivec4::aaag() const { return { a, a, a, g }; }
inline ivec4 ivec4::aaar() const { return { a, a, a, r }; }
inline ivec3 ivec4::aab() const { return { a, a, b }; }
inline ivec4 ivec4::aaba() const { return { a, a, b, a }; }
inline ivec4 ivec4::aabb() const { return { a, a, b, b }; }
inline ivec4 ivec4::aabg() const { return { a, a, b, g }; }
inline ivec4 ivec4::aabr() const { return { a, a, b, r }; }
inline ivec3 ivec4::aag() const { return { a, a, g }; }
inline ivec4 ivec4::aaga() const { return { a, a, g, a }; }
inline ivec4 ivec4::aagb() const { return { a, a, g, b }; }
inline ivec4 ivec4::aagg() const { return { a, a, g, g }; }
inline ivec4 ivec4::aagr() const { return { a, a, g, r }; }
inline ivec3 ivec4::aar() const { return { a, a, r }; }
inline ivec4 ivec4::aara() const { return { a, a, r, a }; }
inline ivec4 ivec4::aarb() const { return { a, a, r, b }; }
inline ivec4 ivec4::aarg() const { return { a, a, r, g }; }
inline ivec4 ivec4::aarr() const { return { a, a, r, r }; }
inline ivec2 ivec4::ab() const { return { a, b }; }
inline ivec3 ivec4::aba() const { return { a, b, a }; }
inline ivec4 ivec4::abaa() const { return { a, b, a, a }; }
inline ivec4 ivec4::abab() const { return { a, b, a, b }; }
inline ivec4 ivec4::abag() const { return { a, b, a, g }; }
inline ivec4 ivec4::abar() const { return { a, b, a, r }; }
inline ivec3 ivec4::abb() const { return { a, b, b }; }
inline ivec4 ivec4::abba() const { return { a, b, b, a }; }
inline ivec4 ivec4::abbb() const { return { a, b, b, b }; }
inline ivec4 ivec4::abbg() const { return { a, b, b, g }; }
inline ivec4 ivec4::abbr() const { return { a, b, b, r }; }
inline ivec3 ivec4::abg() const { return { a, b, g }; }
inline ivec4 ivec4::abga() const { return { a, b, g, a }; }
inline ivec4 ivec4::abgb() const { return { a, b, g, b }; }
inline ivec4 ivec4::abgg() const { return { a, b, g, g }; }
inline ivec4 ivec4::abgr() const { return { a, b, g, r }; }
inline ivec3 ivec4::abr() const { return { a, b, r }; }
inline ivec4 ivec4::abra() const { return { a, b, r, a }; }
inline ivec4 ivec4::abrb() const { return { a, b, r, b }; }
inline ivec4 ivec4::abrg() const { return { a, b, r, g }; }
inline ivec4 ivec4::abrr() const { return { a, b, r, r }; }
inline ivec2 ivec4::ag() const { return { a, g }; }
inline ivec3 ivec4::aga() const { return { a, g, a }; }
inline ivec4 ivec4::agaa() const { return { a, g, a, a }; }
inline ivec4 ivec4::agab() const { return { a, g, a, b }; }
inline ivec4 ivec4::agag() const { return { a, g, a, g }; }
inline ivec4 ivec4::agar() const { return { a, g, a, r }; }
inline ivec3 ivec4::agb() const { return { a, g, b }; }
inline ivec4 ivec4::agba() const { return { a, g, b, a }; }
inline ivec4 ivec4::agbb() const { return { a, g, b, b }; }
inline ivec4 ivec4::agbg() const { return { a, g, b, g }; }
inline ivec4 ivec4::agbr() const { return { a, g, b, r }; }
inline ivec3 ivec4::agg() const { return { a, g, g }; }
inline ivec4 ivec4::agga() const { return { a, g, g, a }; }
inline ivec4 ivec4::aggb() const { return { a, g, g, b }; }
inline ivec4 ivec4::aggg() const { return { a, g, g, g }; }
inline ivec4 ivec4::aggr() const { return { a, g, g, r }; }
inline ivec3 ivec4::agr() const { return { a, g, r }; }
inline ivec4 ivec4::agra() const { return { a, g, r, a }; }
inline ivec4 ivec4::agrb() const { return { a, g, r, b }; }
inline ivec4 ivec4::agrg() const { return { a, g, r, g }; }
inline ivec4 ivec4::agrr() const { return { a, g, r, r }; }
inline ivec2 ivec4::ar() const { return { a, r }; }
inline ivec3 ivec4::ara() const { return { a, r, a }; }
inline ivec4 ivec4::araa() const { return { a, r, a, a }; }
inline ivec4 ivec4::arab() const { return { a, r, a, b }; }
inline ivec4 ivec4::arag() const { return { a, r, a, g }; }
inline ivec4 ivec4::arar() const { return { a, r, a, r }; }
inline ivec3 ivec4::arb() const { return { a, r, b }; }
inline ivec4 ivec4::arba() const { return { a, r, b, a }; }
inline ivec4 ivec4::arbb() const { return { a, r, b, b }; }
inline ivec4 ivec4::arbg() const { return { a, r, b, g }; }
inline ivec4 ivec4::arbr() const { return { a, r, b, r }; }
inline ivec3 ivec4::arg() const { return { a, r, g }; }
inline ivec4 ivec4::arga() const { return { a, r, g, a }; }
inline ivec4 ivec4::argb() const { return { a, r, g, b }; }
inline ivec4 ivec4::argg() const { return { a, r, g, g }; }
inline ivec4 ivec4::argr() const { return { a, r, g, r }; }
inline ivec3 ivec4::arr() const { return { a, r, r }; }
inline ivec4 ivec4::arra() const { return { a, r, r, a }; }
inline ivec4 ivec4::arrb() const { return { a, r, r, b }; }
inline ivec4 ivec4::arrg() const { return { a, r, r, g }; }
inline ivec4 ivec4::arrr() const { return { a, r, r, r }; }
inline ivec2 ivec4::ba() const { return { b, a }; }
inline ivec3 ivec4::baa() const { return { b, a, a }; }
inline ivec4 ivec4::baaa() const { return { b, a, a, a }; }
inline ivec4 ivec4::baab() const { return { b, a, a, b }; }
inline ivec4 ivec4::baag() const { return { b, a, a, g }; }
inline ivec4 ivec4::baar() const { return { b, a, a, r }; }
inline ivec3 ivec4::bab() const { return { b, a, b }; }
inline ivec4 ivec4::baba() const { return { b, a, b, a }; }
inline ivec4 ivec4::babb() const { return { b, a, b, b }; }
inline ivec4 ivec4::babg() const { return { b, a, b, g }; }
inline ivec4 ivec4::babr() const { return { b, a, b, r }; }
inline ivec3 ivec4::bag() const { return { b, a, g }; }
inline ivec4 ivec4::baga() const { return { b, a, g, a }; }
inline ivec4 ivec4::bagb() const { return { b, a, g, b }; }
inline ivec4 ivec4::bagg() const { return { b, a, g, g }; }
inline ivec4 ivec4::bagr() const { return { b, a, g, r }; }
inline ivec3 ivec4::bar() const { return { b, a, r }; }
inline ivec4 ivec4::bara() const { return { b, a, r, a }; }
inline ivec4 ivec4::barb() const { return { b, a, r, b }; }
inline ivec4 ivec4::barg() const { return { b, a, r, g }; }
inline ivec4 ivec4::barr() const { return { b, a, r, r }; }
inline ivec2 ivec4::bb() const { return { b, b }; }
inline ivec3 ivec4::bba() const { return { b, b, a }; }
inline ivec4 ivec4::bbaa() const { return { b, b, a, a }; }
inline ivec4 ivec4::bbab() const { return { b, b, a, b }; }
inline ivec4 ivec4::bbag() const { return { b, b, a, g }; }
inline ivec4 ivec4::bbar() const { return { b, b, a, r }; }
inline ivec3 ivec4::bbb() const { return { b, b, b }; }
inline ivec4 ivec4::bbba() const { return { b, b, b, a }; }
inline ivec4 ivec4::bbbb() const { return { b, b, b, b }; }
inline ivec4 ivec4::bbbg() const { return { b, b, b, g }; }
inline ivec4 ivec4::bbbr() const { return { b, b, b, r }; }
inline ivec3 ivec4::bbg() const { return { b, b, g }; }
inline ivec4 ivec4::bbga() const { return { b, b, g, a }; }
inline ivec4 ivec4::bbgb() const { return { b, b, g, b }; }
inline ivec4 ivec4::bbgg() const { return { b, b, g, g }; }
inline ivec4 ivec4::bbgr() const { return { b, b, g, r }; }
inline ivec3 ivec4::bbr() const { return { b, b, r }; }
inline ivec4 ivec4::bbra() const { return { b, b, r, a }; }
inline ivec4 ivec4::bbrb() const { return { b, b, r, b }; }
inline ivec4 ivec4::bbrg() const { return { b, b, r, g }; }
inline ivec4 ivec4::bbrr() const { return { b, b, r, r }; }
inline ivec2 ivec4::bg() const { return { b, g }; }
inline ivec3 ivec4::bga() const { return { b, g, a }; }
inline ivec4 ivec4::bgaa() const { return { b, g, a, a }; }
inline ivec4 ivec4::bgab() const { return { b, g, a, b }; }
inline ivec4 ivec4::bgag() const { return { b, g, a, g }; }
inline ivec4 ivec4::bgar() const { return { b, g, a, r }; }
inline ivec3 ivec4::bgb() const { return { b, g, b }; }
inline ivec4 ivec4::bgba() const { return { b, g, b, a }; }
inline ivec4 ivec4::bgbb() const { return { b, g, b, b }; }
inline ivec4 ivec4::bgbg() const { return { b, g, b, g }; }
inline ivec4 ivec4::bgbr() const { return { b, g, b, r }; }
inline ivec3 ivec4::bgg() const { return { b, g, g }; }
inline ivec4 ivec4::bgga() const { return { b, g, g, a }; }
inline ivec4 ivec4::bggb() const { return { b, g, g, b }; }
inline ivec4 ivec4::bggg() const { return { b, g, g, g }; }
inline ivec4 ivec4::bggr() const { return { b, g, g, r }; }
inline ivec3 ivec4::bgr() const { return { b, g, r }; }
inline ivec4 ivec4::bgra() const { return { b, g, r, a }; }
inline ivec4 ivec4::bgrb() const { return { b, g, r, b }; }
inline ivec4 ivec4::bgrg() const { return { b, g, r, g }; }
inline ivec4 ivec4::bgrr() const { return { b, g, r, r }; }
inline ivec2 ivec4::br() const { return { b, r }; }
inline ivec3 ivec4::bra() const { return { b, r, a }; }
inline ivec4 ivec4::braa() const { return { b, r, a, a }; }
inline ivec4 ivec4::brab() const { return { b, r, a, b }; }
inline ivec4 ivec4::brag() const { return { b, r, a, g }; }
inline ivec4 ivec4::brar() const { return { b, r, a, r }; }
inline ivec3 ivec4::brb() const { return { b, r, b }; }
inline ivec4 ivec4::brba() const { return { b, r, b, a }; }
inline ivec4 ivec4::brbb() const { return { b, r, b, b }; }
inline ivec4 ivec4::brbg() const { return { b, r, b, g }; }
inline ivec4 ivec4::brbr() const { return { b, r, b, r }; }
inline ivec3 ivec4::brg() const { return { b, r, g }; }
inline ivec4 ivec4::brga() const { return { b, r, g, a }; }
inline ivec4 ivec4::brgb() const { return { b, r, g, b }; }
inline ivec4 ivec4::brgg() const { return { b, r, g, g }; }
inline ivec4 ivec4::brgr() const { return { b, r, g, r }; }
inline ivec3 ivec4::brr() const { return { b, r, r }; }
inline ivec4 ivec4::brra() const { return { b, r, r, a }; }
inline ivec4 ivec4::brrb() const { return { b, r, r, b }; }
inline ivec4 ivec4::brrg() const { return { b, r, r, g }; }
inline ivec4 ivec4::brrr() const { return { b, r, r, r }; }
inline ivec2 ivec4::ga() const { return { g, a }; }
inline ivec3 ivec4::gaa() const { return { g, a, a }; }
inline ivec4 ivec4::gaaa() const { return { g, a, a, a }; }
inline ivec4 ivec4::gaab() const { return { g, a, a, b }; }
inline ivec4 ivec4::gaag() const { return { g, a, a, g }; }
inline ivec4 ivec4::gaar() const { return { g, a, a, r }; }
inline ivec3 ivec4::gab() const { return { g, a, b }; }
inline ivec4 ivec4::gaba() const { return { g, a, b, a }; }
inline ivec4 ivec4::gabb() const { return { g, a, b, b }; }
inline ivec4 ivec4::gabg() const { return { g, a, b, g }; }
inline ivec4 ivec4::gabr() const { return { g, a, b, r }; }
inline ivec3 ivec4::gag() const { return { g, a, g }; }
inline ivec4 ivec4::gaga() const { return { g, a, g, a }; }
inline ivec4 ivec4::gagb() const { return { g, a, g, b }; }
inline ivec4 ivec4::gagg() const { return { g, a, g, g }; }
inline ivec4 ivec4::gagr() const { return { g, a, g, r }; }
inline ivec3 ivec4::gar() const { return { g, a, r }; }
inline ivec4 ivec4::gara() const { return { g, a, r, a }; }
inline ivec4 ivec4::garb() const { return { g, a, r, b }; }
inline ivec4 ivec4::garg() const { return { g, a, r, g }; }
inline ivec4 ivec4::garr() const { return { g, a, r, r }; }
inline ivec2 ivec4::gb() const { return { g, b }; }
inline ivec3 ivec4::gba() const { return { g, b, a }; }
inline ivec4 ivec4::gbaa() const { return { g, b, a, a }; }
inline ivec4 ivec4::gbab() const { return { g, b, a, b }; }
inline ivec4 ivec4::gbag() const { return { g, b, a, g }; }
inline ivec4 ivec4::gbar() const { return { g, b, a, r }; }
inline ivec3 ivec4::gbb() const { return { g, b, b }; }
inline ivec4 ivec4::gbba() const { return { g, b, b, a }; }
inline ivec4 ivec4::gbbb() const { return { g, b, b, b }; }
inline ivec4 ivec4::gbbg() const { return { g, b, b, g }; }
inline ivec4 ivec4::gbbr() const { return { g, b, b, r }; }
inline ivec3 ivec4::gbg() const { return { g, b, g }; }
inline ivec4 ivec4::gbga() const { return { g, b, g, a }; }
inline ivec4 ivec4::gbgb() const { return { g, b, g, b }; }
inline ivec4 ivec4::gbgg() const { return { g, b, g, g }; }
inline ivec4 ivec4::gbgr() const { return { g, b, g, r }; }
inline ivec3 ivec4::gbr() const { return { g, b, r }; }
inline ivec4 ivec4::gbra() const { return { g, b, r, a }; }
inline ivec4 ivec4::gbrb() const { return { g, b, r, b }; }
inline ivec4 ivec4::gbrg() const { return { g, b, r, g }; }
inline ivec4 ivec4::gbrr() const { return { g, b, r, r }; }
inline ivec2 ivec4::gg() const { return { g, g }; }
inline ivec3 ivec4::gga() const { return { g, g, a }; }
inline ivec4 ivec4::ggaa() const { return { g, g, a, a }; }
inline ivec4 ivec4::ggab() const { return { g, g, a, b }; }
inline ivec4 ivec4::ggag() const { return { g, g, a, g }; }
inline ivec4 ivec4::ggar() const { return { g, g, a, r }; }
inline ivec3 ivec4::ggb() const { return { g, g, b }; }
inline ivec4 ivec4::ggba() const { return { g, g, b, a }; }
inline ivec4 ivec4::ggbb() const { return { g, g, b, b }; }
inline ivec4 ivec4::ggbg() const { return { g, g, b, g }; }
inline ivec4 ivec4::ggbr() const { return { g, g, b, r }; }
inline ivec3 ivec4::ggg() const { return { g, g, g }; }
inline ivec4 ivec4::ggga() const { return { g, g, g, a }; }
inline ivec4 ivec4::gggb() const { return { g, g, g, b }; }
inline ivec4 ivec4::gggg() const { return { g, g, g, g }; }
inline ivec4 ivec4::gggr() const { return { g, g, g, r }; }
inline ivec3 ivec4::ggr() const { return { g, g, r }; }
inline ivec4 ivec4::ggra() const { return { g, g, r, a }; }
inline ivec4 ivec4::ggrb() const { return { g, g, r, b }; }
inline ivec4 ivec4::ggrg() const { return { g, g, r, g }; }
inline ivec4 ivec4::ggrr() const { return { g, g, r, r }; }
inline ivec2 ivec4::gr() const { return { g, r }; }
inline ivec3 ivec4::gra() const { return { g, r, a }; }
inline ivec4 ivec4::graa() const { return { g, r, a, a }; }
inline ivec4 ivec4::grab() const { return { g, r, a, b }; }
inline ivec4 ivec4::grag() const { return { g, r, a, g }; }
inline ivec4 ivec4::grar() const { return { g, r, a, r }; }
inline ivec3 ivec4::grb() const { return { g, r, b }; }
inline ivec4 ivec4::grba() const { return { g, r, b, a }; }
inline ivec4 ivec4::grbb() const { return { g, r, b, b }; }
inline ivec4 ivec4::grbg() const { return { g, r, b, g }; }
inline ivec4 ivec4::grbr() const { return { g, r, b, r }; }
inline ivec3 ivec4::grg() const { return { g, r, g }; }
inline ivec4 ivec4::grga() const { return { g, r, g, a }; }
inline ivec4 ivec4::grgb() const { return { g, r, g, b }; }
inline ivec4 ivec4::grgg() const { return { g, r, g, g }; }
inline ivec4 ivec4::grgr() const { return { g, r, g, r }; }
inline ivec3 ivec4::grr() const { return { g, r, r }; }
inline ivec4 ivec4::grra() const { return { g, r, r, a }; }
inline ivec4 ivec4::grrb() const { return { g, r, r, b }; }
inline ivec4 ivec4::grrg() const { return { g, r, r, g }; }
inline ivec4 ivec4::grrr() const { return { g, r, r, r }; }
inline ivec2 ivec4::ra() const { return { r, a }; }
inline ivec3 ivec4::raa() const { return { r, a, a }; }
inline ivec4 ivec4::raaa() const { return { r, a, a, a }; }
inline ivec4 ivec4::raab() const { return { r, a, a, b }; }
inline ivec4 ivec4::raag() const { return { r, a, a, g }; }
inline ivec4 ivec4::raar() const { return { r, a, a, r }; }
inline ivec3 ivec4::rab() const { return { r, a, b }; }
inline ivec4 ivec4::raba() const { return { r, a, b, a }; }
inline ivec4 ivec4::rabb() const { return { r, a, b, b }; }
inline ivec4 ivec4::rabg() const { return { r, a, b, g }; }
inline ivec4 ivec4::rabr() const { return { r, a, b, r }; }
inline ivec3 ivec4::rag() const { return { r, a, g }; }
inline ivec4 ivec4::raga() const { return { r, a, g, a }; }
inline ivec4 ivec4::ragb() const { return { r, a, g, b }; }
inline ivec4 ivec4::ragg() const { return { r, a, g, g }; }
inline ivec4 ivec4::ragr() const { return { r, a, g, r }; }
inline ivec3 ivec4::rar() const { return { r, a, r }; }
inline ivec4 ivec4::rara() const { return { r, a, r, a }; }
inline ivec4 ivec4::rarb() const { return { r, a, r, b }; }
inline ivec4 ivec4::rarg() const { return { r, a, r, g }; }
inline ivec4 ivec4::rarr() const { return { r, a, r, r }; }
inline ivec2 ivec4::rb() const { return { r, b }; }
inline ivec3 ivec4::rba() const { return { r, b, a }; }
inline ivec4 ivec4::rbaa() const { return { r, b, a, a }; }
inline ivec4 ivec4::rbab() const { return { r, b, a, b }; }
inline ivec4 ivec4::rbag() const { return { r, b, a, g }; }
inline ivec4 ivec4::rbar() const { return { r, b, a, r }; }
inline ivec3 ivec4::rbb() const { return { r, b, b }; }
inline ivec4 ivec4::rbba() const { return { r, b, b, a }; }
inline ivec4 ivec4::rbbb() const { return { r, b, b, b }; }
inline ivec4 ivec4::rbbg() const { return { r, b, b, g }; }
inline ivec4 ivec4::rbbr() const { return { r, b, b, r }; }
inline ivec3 ivec4::rbg() const { return { r, b, g }; }
inline ivec4 ivec4::rbga() const { return { r, b, g, a }; }
inline ivec4 ivec4::rbgb() const { return { r, b, g, b }; }
inline ivec4 ivec4::rbgg() const { return { r, b, g, g }; }
inline ivec4 ivec4::rbgr() const { return { r, b, g, r }; }
inline ivec3 ivec4::rbr() const { return { r, b, r }; }
inline ivec4 ivec4::rbra() const { return { r, b, r, a }; }
inline ivec4 ivec4::rbrb() const { return { r, b, r, b }; }
inline ivec4 ivec4::rbrg() const { return { r, b, r, g }; }
inline ivec4 ivec4::rbrr() const { return { r, b, r, r }; }
inline ivec2 ivec4::rg() const { return { r, g }; }
inline ivec3 ivec4::rga() const { return { r, g, a }; }
inline ivec4 ivec4::rgaa() const { return { r, g, a, a }; }
inline ivec4 ivec4::rgab() const { return { r, g, a, b }; }
inline ivec4 ivec4::rgag() const { return { r, g, a, g }; }
inline ivec4 ivec4::rgar() const { return { r, g, a, r }; }
inline ivec3 ivec4::rgb() const { return { r, g, b }; }
inline ivec4 ivec4::rgba() const { return { r, g, b, a }; }
inline ivec4 ivec4::rgbb() const { return { r, g, b, b }; }
inline ivec4 ivec4::rgbg() const { return { r, g, b, g }; }
inline ivec4 ivec4::rgbr() const { return { r, g, b, r }; }
inline ivec3 ivec4::rgg() const { return { r, g, g }; }
inline ivec4 ivec4::rgga() const { return { r, g, g, a }; }
inline ivec4 ivec4::rggb() const { return { r, g, g, b }; }
inline ivec4 ivec4::rggg() const { return { r, g, g, g }; }
inline ivec4 ivec4::rggr() const { return { r, g, g, r }; }
inline ivec3 ivec4::rgr() const { return { r, g, r }; }
inline ivec4 ivec4::rgra() const { return { r, g, r, a }; }
inline ivec4 ivec4::rgrb() const { return { r, g, r, b }; }
inline ivec4 ivec4::rgrg() const { return { r, g, r, g }; }
inline ivec4 ivec4::rgrr() const { return { r, g, r, r }; }
inline ivec2 ivec4::rr() const { return { r, r }; }
inline ivec3 ivec4::rra() const { return { r, r, a }; }
inline ivec4 ivec4::rraa() const { return { r, r, a, a }; }
inline ivec4 ivec4::rrab() const { return { r, r, a, b }; }
inline ivec4 ivec4::rrag() const { return { r, r, a, g }; }
inline ivec4 ivec4::rrar() const { return { r, r, a, r }; }
inline ivec3 ivec4::rrb() const { return { r, r, b }; }
inline ivec4 ivec4::rrba() const { return { r, r, b, a }; }
inline ivec4 ivec4::rrbb() const { return { r, r, b, b }; }
inline ivec4 ivec4::rrbg() const { return { r, r, b, g }; }
inline ivec4 ivec4::rrbr() const { return { r, r, b, r }; }
inline ivec3 ivec4::rrg() const { return { r, r, g }; }
inline ivec4 ivec4::rrga() const { return { r, r, g, a }; }
inline ivec4 ivec4::rrgb() const { return { r, r, g, b }; }
inline ivec4 ivec4::rrgg() const { return { r, r, g, g }; }
inline ivec4 ivec4::rrgr() const { return { r, r, g, r }; }
inline ivec3 ivec4::rrr() const { return { r, r, r }; }
inline ivec4 ivec4::rrra() const { return { r, r, r, a }; }
inline ivec4 ivec4::rrrb() const { return { r, r, r, b }; }
inline ivec4 ivec4::rrrg() const { return { r, r, r, g }; }
inline ivec4 ivec4::rrrr() const { return { r, r, r, r }; }
inline ivec2 ivec4::qq() const { return { q, q }; }
inline ivec3 ivec4::qqq() const { return { q, q, q }; }
inline ivec4 ivec4::qqqq() const { return { q, q, q, q }; }
inline ivec4 ivec4::qqqs() const { return { q, q, q, s }; }
inline ivec4 ivec4::qqqt() const { return { q, q, q, t }; }
inline ivec4 ivec4::qqqp() const { return { q, q, q, p }; }
inline ivec3 ivec4::qqs() const { return { q, q, s }; }
inline ivec4 ivec4::qqsq() const { return { q, q, s, q }; }
inline ivec4 ivec4::qqss() const { return { q, q, s, s }; }
inline ivec4 ivec4::qqst() const { return { q, q, s, t }; }
inline ivec4 ivec4::qqsp() const { return { q, q, s, p }; }
inline ivec3 ivec4::qqt() const { return { q, q, t }; }
inline ivec4 ivec4::qqtq() const { return { q, q, t, q }; }
inline ivec4 ivec4::qqts() const { return { q, q, t, s }; }
inline ivec4 ivec4::qqtt() const { return { q, q, t, t }; }
inline ivec4 ivec4::qqtp() const { return { q, q, t, p }; }
inline ivec3 ivec4::qqp() const { return { q, q, p }; }
inline ivec4 ivec4::qqpq() const { return { q, q, p, q }; }
inline ivec4 ivec4::qqps() const { return { q, q, p, s }; }
inline ivec4 ivec4::qqpt() const { return { q, q, p, t }; }
inline ivec4 ivec4::qqpp() const { return { q, q, p, p }; }
inline ivec2 ivec4::qs() const { return { q, s }; }
inline ivec3 ivec4::qsq() const { return { q, s, q }; }
inline ivec4 ivec4::qsqq() const { return { q, s, q, q }; }
inline ivec4 ivec4::qsqs() const { return { q, s, q, s }; }
inline ivec4 ivec4::qsqt() const { return { q, s, q, t }; }
inline ivec4 ivec4::qsqp() const { return { q, s, q, p }; }
inline ivec3 ivec4::qss() const { return { q, s, s }; }
inline ivec4 ivec4::qssq() const { return { q, s, s, q }; }
inline ivec4 ivec4::qsss() const { return { q, s, s, s }; }
inline ivec4 ivec4::qsst() const { return { q, s, s, t }; }
inline ivec4 ivec4::qssp() const { return { q, s, s, p }; }
inline ivec3 ivec4::qst() const { return { q, s, t }; }
inline ivec4 ivec4::qstq() const { return { q, s, t, q }; }
inline ivec4 ivec4::qsts() const { return { q, s, t, s }; }
inline ivec4 ivec4::qstt() const { return { q, s, t, t }; }
inline ivec4 ivec4::qstp() const { return { q, s, t, p }; }
inline ivec3 ivec4::qsp() const { return { q, s, p }; }
inline ivec4 ivec4::qspq() const { return { q, s, p, q }; }
inline ivec4 ivec4::qsps() const { return { q, s, p, s }; }
inline ivec4 ivec4::qspt() const { return { q, s, p, t }; }
inline ivec4 ivec4::qspp() const { return { q, s, p, p }; }
inline ivec2 ivec4::qt() const { return { q, t }; }
inline ivec3 ivec4::qtq() const { return { q, t, q }; }
inline ivec4 ivec4::qtqq() const { return { q, t, q, q }; }
inline ivec4 ivec4::qtqs() const { return { q, t, q, s }; }
inline ivec4 ivec4::qtqt() const { return { q, t, q, t }; }
inline ivec4 ivec4::qtqp() const { return { q, t, q, p }; }
inline ivec3 ivec4::qts() const { return { q, t, s }; }
inline ivec4 ivec4::qtsq() const { return { q, t, s, q }; }
inline ivec4 ivec4::qtss() const { return { q, t, s, s }; }
inline ivec4 ivec4::qtst() const { return { q, t, s, t }; }
inline ivec4 ivec4::qtsp() const { return { q, t, s, p }; }
inline ivec3 ivec4::qtt() const { return { q, t, t }; }
inline ivec4 ivec4::qttq() const { return { q, t, t, q }; }
inline ivec4 ivec4::qtts() const { return { q, t, t, s }; }
inline ivec4 ivec4::qttt() const { return { q, t, t, t }; }
inline ivec4 ivec4::qttp() const { return { q, t, t, p }; }
inline ivec3 ivec4::qtp() const { return { q, t, p }; }
inline ivec4 ivec4::qtpq() const { return { q, t, p, q }; }
inline ivec4 ivec4::qtps() const { return { q, t, p, s }; }
inline ivec4 ivec4::qtpt() const { return { q, t, p, t }; }
inline ivec4 ivec4::qtpp() const { return { q, t, p, p }; }
inline ivec2 ivec4::qp() const { return { q, p }; }
inline ivec3 ivec4::qpq() const { return { q, p, q }; }
inline ivec4 ivec4::qpqq() const { return { q, p, q, q }; }
inline ivec4 ivec4::qpqs() const { return { q, p, q, s }; }
inline ivec4 ivec4::qpqt() const { return { q, p, q, t }; }
inline ivec4 ivec4::qpqp() const { return { q, p, q, p }; }
inline ivec3 ivec4::qps() const { return { q, p, s }; }
inline ivec4 ivec4::qpsq() const { return { q, p, s, q }; }
inline ivec4 ivec4::qpss() const { return { q, p, s, s }; }
inline ivec4 ivec4::qpst() const { return { q, p, s, t }; }
inline ivec4 ivec4::qpsp() const { return { q, p, s, p }; }
inline ivec3 ivec4::qpt() const { return { q, p, t }; }
inline ivec4 ivec4::qptq() const { return { q, p, t, q }; }
inline ivec4 ivec4::qpts() const { return { q, p, t, s }; }
inline ivec4 ivec4::qptt() const { return { q, p, t, t }; }
inline ivec4 ivec4::qptp() const { return { q, p, t, p }; }
inline ivec3 ivec4::qpp() const { return { q, p, p }; }
inline ivec4 ivec4::qppq() const { return { q, p, p, q }; }
inline ivec4 ivec4::qpps() const { return { q, p, p, s }; }
inline ivec4 ivec4::qppt() const { return { q, p, p, t }; }
inline ivec4 ivec4::qppp() const { return { q, p, p, p }; }
inline ivec2 ivec4::sq() const { return { s, q }; }
inline ivec3 ivec4::sqq() const { return { s, q, q }; }
inline ivec4 ivec4::sqqq() const { return { s, q, q, q }; }
inline ivec4 ivec4::sqqs() const { return { s, q, q, s }; }
inline ivec4 ivec4::sqqt() const { return { s, q, q, t }; }
inline ivec4 ivec4::sqqp() const { return { s, q, q, p }; }
inline ivec3 ivec4::sqs() const { return { s, q, s }; }
inline ivec4 ivec4::sqsq() const { return { s, q, s, q }; }
inline ivec4 ivec4::sqss() const { return { s, q, s, s }; }
inline ivec4 ivec4::sqst() const { return { s, q, s, t }; }
inline ivec4 ivec4::sqsp() const { return { s, q, s, p }; }
inline ivec3 ivec4::sqt() const { return { s, q, t }; }
inline ivec4 ivec4::sqtq() const { return { s, q, t, q }; }
inline ivec4 ivec4::sqts() const { return { s, q, t, s }; }
inline ivec4 ivec4::sqtt() const { return { s, q, t, t }; }
inline ivec4 ivec4::sqtp() const { return { s, q, t, p }; }
inline ivec3 ivec4::sqp() const { return { s, q, p }; }
inline ivec4 ivec4::sqpq() const { return { s, q, p, q }; }
inline ivec4 ivec4::sqps() const { return { s, q, p, s }; }
inline ivec4 ivec4::sqpt() const { return { s, q, p, t }; }
inline ivec4 ivec4::sqpp() const { return { s, q, p, p }; }
inline ivec2 ivec4::ss() const { return { s, s }; }
inline ivec3 ivec4::ssq() const { return { s, s, q }; }
inline ivec4 ivec4::ssqq() const { return { s, s, q, q }; }
inline ivec4 ivec4::ssqs() const { return { s, s, q, s }; }
inline ivec4 ivec4::ssqt() const { return { s, s, q, t }; }
inline ivec4 ivec4::ssqp() const { return { s, s, q, p }; }
inline ivec3 ivec4::sss() const { return { s, s, s }; }
inline ivec4 ivec4::sssq() const { return { s, s, s, q }; }
inline ivec4 ivec4::ssss() const { return { s, s, s, s }; }
inline ivec4 ivec4::ssst() const { return { s, s, s, t }; }
inline ivec4 ivec4::sssp() const { return { s, s, s, p }; }
inline ivec3 ivec4::sst() const { return { s, s, t }; }
inline ivec4 ivec4::sstq() const { return { s, s, t, q }; }
inline ivec4 ivec4::ssts() const { return { s, s, t, s }; }
inline ivec4 ivec4::sstt() const { return { s, s, t, t }; }
inline ivec4 ivec4::sstp() const { return { s, s, t, p }; }
inline ivec3 ivec4::ssp() const { return { s, s, p }; }
inline ivec4 ivec4::sspq() const { return { s, s, p, q }; }
inline ivec4 ivec4::ssps() const { return { s, s, p, s }; }
inline ivec4 ivec4::sspt() const { return { s, s, p, t }; }
inline ivec4 ivec4::sspp() const { return { s, s, p, p }; }
inline ivec2 ivec4::st() const { return { s, t }; }
inline ivec3 ivec4::stq() const { return { s, t, q }; }
inline ivec4 ivec4::stqq() const { return { s, t, q, q }; }
inline ivec4 ivec4::stqs() const { return { s, t, q, s }; }
inline ivec4 ivec4::stqt() const { return { s, t, q, t }; }
inline ivec4 ivec4::stqp() const { return { s, t, q, p }; }
inline ivec3 ivec4::sts() const { return { s, t, s }; }
inline ivec4 ivec4::stsq() const { return { s, t, s, q }; }
inline ivec4 ivec4::stss() const { return { s, t, s, s }; }
inline ivec4 ivec4::stst() const { return { s, t, s, t }; }
inline ivec4 ivec4::stsp() const { return { s, t, s, p }; }
inline ivec3 ivec4::stt() const { return { s, t, t }; }
inline ivec4 ivec4::sttq() const { return { s, t, t, q }; }
inline ivec4 ivec4::stts() const { return { s, t, t, s }; }
inline ivec4 ivec4::sttt() const { return { s, t, t, t }; }
inline ivec4 ivec4::sttp() const { return { s, t, t, p }; }
inline ivec3 ivec4::stp() const { return { s, t, p }; }
inline ivec4 ivec4::stpq() const { return { s, t, p, q }; }
inline ivec4 ivec4::stps() const { return { s, t, p, s }; }
inline ivec4 ivec4::stpt() const { return { s, t, p, t }; }
inline ivec4 ivec4::stpp() const { return { s, t, p, p }; }
inline ivec2 ivec4::sp() const { return { s, p }; }
inline ivec3 ivec4::spq() const { return { s, p, q }; }
inline ivec4 ivec4::spqq() const { return { s, p, q, q }; }
inline ivec4 ivec4::spqs() const { return { s, p, q, s }; }
inline ivec4 ivec4::spqt() const { return { s, p, q, t }; }
inline ivec4 ivec4::spqp() const { return { s, p, q, p }; }
inline ivec3 ivec4::sps() const { return { s, p, s }; }
inline ivec4 ivec4::spsq() const { return { s, p, s, q }; }
inline ivec4 ivec4::spss() const { return { s, p, s, s }; }
inline ivec4 ivec4::spst() const { return { s, p, s, t }; }
inline ivec4 ivec4::spsp() const { return { s, p, s, p }; }
inline ivec3 ivec4::spt() const { return { s, p, t }; }
inline ivec4 ivec4::sptq() const { return { s, p, t, q }; }
inline ivec4 ivec4::spts() const { return { s, p, t, s }; }
inline ivec4 ivec4::sptt() const { return { s, p, t, t }; }
inline ivec4 ivec4::sptp() const { return { s, p, t, p }; }
inline ivec3 ivec4::spp() const { return { s, p, p }; }
inline ivec4 ivec4::sppq() const { return { s, p, p, q }; }
inline ivec4 ivec4::spps() const { return { s, p, p, s }; }
inline ivec4 ivec4::sppt() const { return { s, p, p, t }; }
inline ivec4 ivec4::sppp() const { return { s, p, p, p }; }
inline ivec2 ivec4::tq() const { return { t, q }; }
inline ivec3 ivec4::tqq() const { return { t, q, q }; }
inline ivec4 ivec4::tqqq() const { return { t, q, q, q }; }
inline ivec4 ivec4::tqqs() const { return { t, q, q, s }; }
inline ivec4 ivec4::tqqt() const { return { t, q, q, t }; }
inline ivec4 ivec4::tqqp() const { return { t, q, q, p }; }
inline ivec3 ivec4::tqs() const { return { t, q, s }; }
inline ivec4 ivec4::tqsq() const { return { t, q, s, q }; }
inline ivec4 ivec4::tqss() const { return { t, q, s, s }; }
inline ivec4 ivec4::tqst() const { return { t, q, s, t }; }
inline ivec4 ivec4::tqsp() const { return { t, q, s, p }; }
inline ivec3 ivec4::tqt() const { return { t, q, t }; }
inline ivec4 ivec4::tqtq() const { return { t, q, t, q }; }
inline ivec4 ivec4::tqts() const { return { t, q, t, s }; }
inline ivec4 ivec4::tqtt() const { return { t, q, t, t }; }
inline ivec4 ivec4::tqtp() const { return { t, q, t, p }; }
inline ivec3 ivec4::tqp() const { return { t, q, p }; }
inline ivec4 ivec4::tqpq() const { return { t, q, p, q }; }
inline ivec4 ivec4::tqps() const { return { t, q, p, s }; }
inline ivec4 ivec4::tqpt() const { return { t, q, p, t }; }
inline ivec4 ivec4::tqpp() const { return { t, q, p, p }; }
inline ivec2 ivec4::ts() const { return { t, s }; }
inline ivec3 ivec4::tsq() const { return { t, s, q }; }
inline ivec4 ivec4::tsqq() const { return { t, s, q, q }; }
inline ivec4 ivec4::tsqs() const { return { t, s, q, s }; }
inline ivec4 ivec4::tsqt() const { return { t, s, q, t }; }
inline ivec4 ivec4::tsqp() const { return { t, s, q, p }; }
inline ivec3 ivec4::tss() const { return { t, s, s }; }
inline ivec4 ivec4::tssq() const { return { t, s, s, q }; }
inline ivec4 ivec4::tsss() const { return { t, s, s, s }; }
inline ivec4 ivec4::tsst() const { return { t, s, s, t }; }
inline ivec4 ivec4::tssp() const { return { t, s, s, p }; }
inline ivec3 ivec4::tst() const { return { t, s, t }; }
inline ivec4 ivec4::tstq() const { return { t, s, t, q }; }
inline ivec4 ivec4::tsts() const { return { t, s, t, s }; }
inline ivec4 ivec4::tstt() const { return { t, s, t, t }; }
inline ivec4 ivec4::tstp() const { return { t, s, t, p }; }
inline ivec3 ivec4::tsp() const { return { t, s, p }; }
inline ivec4 ivec4::tspq() const { return { t, s, p, q }; }
inline ivec4 ivec4::tsps() const { return { t, s, p, s }; }
inline ivec4 ivec4::tspt() const { return { t, s, p, t }; }
inline ivec4 ivec4::tspp() const { return { t, s, p, p }; }
inline ivec2 ivec4::tt() const { return { t, t }; }
inline ivec3 ivec4::ttq() const { return { t, t, q }; }
inline ivec4 ivec4::ttqq() const { return { t, t, q, q }; }
inline ivec4 ivec4::ttqs() const { return { t, t, q, s }; }
inline ivec4 ivec4::ttqt() const { return { t, t, q, t }; }
inline ivec4 ivec4::ttqp() const { return { t, t, q, p }; }
inline ivec3 ivec4::tts() const { return { t, t, s }; }
inline ivec4 ivec4::ttsq() const { return { t, t, s, q }; }
inline ivec4 ivec4::ttss() const { return { t, t, s, s }; }
inline ivec4 ivec4::ttst() const { return { t, t, s, t }; }
inline ivec4 ivec4::ttsp() const { return { t, t, s, p }; }
inline ivec3 ivec4::ttt() const { return { t, t, t }; }
inline ivec4 ivec4::tttq() const { return { t, t, t, q }; }
inline ivec4 ivec4::ttts() const { return { t, t, t, s }; }
inline ivec4 ivec4::tttt() const { return { t, t, t, t }; }
inline ivec4 ivec4::tttp() const { return { t, t, t, p }; }
inline ivec3 ivec4::ttp() const { return { t, t, p }; }
inline ivec4 ivec4::ttpq() const { return { t, t, p, q }; }
inline ivec4 ivec4::ttps() const { return { t, t, p, s }; }
inline ivec4 ivec4::ttpt() const { return { t, t, p, t }; }
inline ivec4 ivec4::ttpp() const { return { t, t, p, p }; }
inline ivec2 ivec4::tp() const { return { t, p }; }
inline ivec3 ivec4::tpq() const { return { t, p, q }; }
inline ivec4 ivec4::tpqq() const { return { t, p, q, q }; }
inline ivec4 ivec4::tpqs() const { return { t, p, q, s }; }
inline ivec4 ivec4::tpqt() const { return { t, p, q, t }; }
inline ivec4 ivec4::tpqp() const { return { t, p, q, p }; }
inline ivec3 ivec4::tps() const { return { t, p, s }; }
inline ivec4 ivec4::tpsq() const { return { t, p, s, q }; }
inline ivec4 ivec4::tpss() const { return { t, p, s, s }; }
inline ivec4 ivec4::tpst() const { return { t, p, s, t }; }
inline ivec4 ivec4::tpsp() const { return { t, p, s, p }; }
inline ivec3 ivec4::tpt() const { return { t, p, t }; }
inline ivec4 ivec4::tptq() const { return { t, p, t, q }; }
inline ivec4 ivec4::tpts() const { return { t, p, t, s }; }
inline ivec4 ivec4::tptt() const { return { t, p, t, t }; }
inline ivec4 ivec4::tptp() const { return { t, p, t, p }; }
inline ivec3 ivec4::tpp() const { return { t, p, p }; }
inline ivec4 ivec4::tppq() const { return { t, p, p, q }; }
inline ivec4 ivec4::tpps() const { return { t, p, p, s }; }
inline ivec4 ivec4::tppt() const { return { t, p, p, t }; }
inline ivec4 ivec4::tppp() const { return { t, p, p, p }; }
inline ivec2 ivec4::pq() const { return { p, q }; }
inline ivec3 ivec4::pqq() const { return { p, q, q }; }
inline ivec4 ivec4::pqqq() const { return { p, q, q, q }; }
inline ivec4 ivec4::pqqs() const { return { p, q, q, s }; }
inline ivec4 ivec4::pqqt() const { return { p, q, q, t }; }
inline ivec4 ivec4::pqqp() const { return { p, q, q, p }; }
inline ivec3 ivec4::pqs() const { return { p, q, s }; }
inline ivec4 ivec4::pqsq() const { return { p, q, s, q }; }
inline ivec4 ivec4::pqss() const { return { p, q, s, s }; }
inline ivec4 ivec4::pqst() const { return { p, q, s, t }; }
inline ivec4 ivec4::pqsp() const { return { p, q, s, p }; }
inline ivec3 ivec4::pqt() const { return { p, q, t }; }
inline ivec4 ivec4::pqtq() const { return { p, q, t, q }; }
inline ivec4 ivec4::pqts() const { return { p, q, t, s }; }
inline ivec4 ivec4::pqtt() const { return { p, q, t, t }; }
inline ivec4 ivec4::pqtp() const { return { p, q, t, p }; }
inline ivec3 ivec4::pqp() const { return { p, q, p }; }
inline ivec4 ivec4::pqpq() const { return { p, q, p, q }; }
inline ivec4 ivec4::pqps() const { return { p, q, p, s }; }
inline ivec4 ivec4::pqpt() const { return { p, q, p, t }; }
inline ivec4 ivec4::pqpp() const { return { p, q, p, p }; }
inline ivec2 ivec4::ps() const { return { p, s }; }
inline ivec3 ivec4::psq() const { return { p, s, q }; }
inline ivec4 ivec4::psqq() const { return { p, s, q, q }; }
inline ivec4 ivec4::psqs() const { return { p, s, q, s }; }
inline ivec4 ivec4::psqt() const { return { p, s, q, t }; }
inline ivec4 ivec4::psqp() const { return { p, s, q, p }; }
inline ivec3 ivec4::pss() const { return { p, s, s }; }
inline ivec4 ivec4::pssq() const { return { p, s, s, q }; }
inline ivec4 ivec4::psss() const { return { p, s, s, s }; }
inline ivec4 ivec4::psst() const { return { p, s, s, t }; }
inline ivec4 ivec4::pssp() const { return { p, s, s, p }; }
inline ivec3 ivec4::pst() const { return { p, s, t }; }
inline ivec4 ivec4::pstq() const { return { p, s, t, q }; }
inline ivec4 ivec4::psts() const { return { p, s, t, s }; }
inline ivec4 ivec4::pstt() const { return { p, s, t, t }; }
inline ivec4 ivec4::pstp() const { return { p, s, t, p }; }
inline ivec3 ivec4::psp() const { return { p, s, p }; }
inline ivec4 ivec4::pspq() const { return { p, s, p, q }; }
inline ivec4 ivec4::psps() const { return { p, s, p, s }; }
inline ivec4 ivec4::pspt() const { return { p, s, p, t }; }
inline ivec4 ivec4::pspp() const { return { p, s, p, p }; }
inline ivec2 ivec4::pt() const { return { p, t }; }
inline ivec3 ivec4::ptq() const { return { p, t, q }; }
inline ivec4 ivec4::ptqq() const { return { p, t, q, q }; }
inline ivec4 ivec4::ptqs() const { return { p, t, q, s }; }
inline ivec4 ivec4::ptqt() const { return { p, t, q, t }; }
inline ivec4 ivec4::ptqp() const { return { p, t, q, p }; }
inline ivec3 ivec4::pts() const { return { p, t, s }; }
inline ivec4 ivec4::ptsq() const { return { p, t, s, q }; }
inline ivec4 ivec4::ptss() const { return { p, t, s, s }; }
inline ivec4 ivec4::ptst() const { return { p, t, s, t }; }
inline ivec4 ivec4::ptsp() const { return { p, t, s, p }; }
inline ivec3 ivec4::ptt() const { return { p, t, t }; }
inline ivec4 ivec4::pttq() const { return { p, t, t, q }; }
inline ivec4 ivec4::ptts() const { return { p, t, t, s }; }
inline ivec4 ivec4::pttt() const { return { p, t, t, t }; }
inline ivec4 ivec4::pttp() const { return { p, t, t, p }; }
inline ivec3 ivec4::ptp() const { return { p, t, p }; }
inline ivec4 ivec4::ptpq() const { return { p, t, p, q }; }
inline ivec4 ivec4::ptps() const { return { p, t, p, s }; }
inline ivec4 ivec4::ptpt() const { return { p, t, p, t }; }
inline ivec4 ivec4::ptpp() const { return { p, t, p, p }; }
inline ivec2 ivec4::pp() const { return { p, p }; }
inline ivec3 ivec4::ppq() const { return { p, p, q }; }
inline ivec4 ivec4::ppqq() const { return { p, p, q, q }; }
inline ivec4 ivec4::ppqs() const { return { p, p, q, s }; }
inline ivec4 ivec4::ppqt() const { return { p, p, q, t }; }
inline ivec4 ivec4::ppqp() const { return { p, p, q, p }; }
inline ivec3 ivec4::pps() const { return { p, p, s }; }
inline ivec4 ivec4::ppsq() const { return { p, p, s, q }; }
inline ivec4 ivec4::ppss() const { return { p, p, s, s }; }
inline ivec4 ivec4::ppst() const { return { p, p, s, t }; }
inline ivec4 ivec4::ppsp() const { return { p, p, s, p }; }
inline ivec3 ivec4::ppt() const { return { p, p, t }; }
inline ivec4 ivec4::pptq() const { return { p, p, t, q }; }
inline ivec4 ivec4::ppts() const { return { p, p, t, s }; }
inline ivec4 ivec4::pptt() const { return { p, p, t, t }; }
inline ivec4 ivec4::pptp() const { return { p, p, t, p }; }
inline ivec3 ivec4::ppp() const { return { p, p, p }; }
inline ivec4 ivec4::pppq() const { return { p, p, p, q }; }
inline ivec4 ivec4::ppps() const { return { p, p, p, s }; }
inline ivec4 ivec4::pppt() const { return { p, p, p, t }; }
inline ivec4 ivec4::pppp() const { return { p, p, p, p }; }
inline ivec2 ivec4::ww() const { return { w, w }; }
inline ivec3 ivec4::www() const { return { w, w, w }; }
inline ivec4 ivec4::wwww() const { return { w, w, w, w }; }
inline ivec4 ivec4::wwwx() const { return { w, w, w, x }; }
inline ivec4 ivec4::wwwy() const { return { w, w, w, y }; }
inline ivec4 ivec4::wwwz() const { return { w, w, w, z }; }
inline ivec3 ivec4::wwx() const { return { w, w, x }; }
inline ivec4 ivec4::wwxw() const { return { w, w, x, w }; }
inline ivec4 ivec4::wwxx() const { return { w, w, x, x }; }
inline ivec4 ivec4::wwxy() const { return { w, w, x, y }; }
inline ivec4 ivec4::wwxz() const { return { w, w, x, z }; }
inline ivec3 ivec4::wwy() const { return { w, w, y }; }
inline ivec4 ivec4::wwyw() const { return { w, w, y, w }; }
inline ivec4 ivec4::wwyx() const { return { w, w, y, x }; }
inline ivec4 ivec4::wwyy() const { return { w, w, y, y }; }
inline ivec4 ivec4::wwyz() const { return { w, w, y, z }; }
inline ivec3 ivec4::wwz() const { return { w, w, z }; }
inline ivec4 ivec4::wwzw() const { return { w, w, z, w }; }
inline ivec4 ivec4::wwzx() const { return { w, w, z, x }; }
inline ivec4 ivec4::wwzy() const { return { w, w, z, y }; }
inline ivec4 ivec4::wwzz() const { return { w, w, z, z }; }
inline ivec2 ivec4::wx() const { return { w, x }; }
inline ivec3 ivec4::wxw() const { return { w, x, w }; }
inline ivec4 ivec4::wxww() const { return { w, x, w, w }; }
inline ivec4 ivec4::wxwx() const { return { w, x, w, x }; }
inline ivec4 ivec4::wxwy() const { return { w, x, w, y }; }
inline ivec4 ivec4::wxwz() const { return { w, x, w, z }; }
inline ivec3 ivec4::wxx() const { return { w, x, x }; }
inline ivec4 ivec4::wxxw() const { return { w, x, x, w }; }
inline ivec4 ivec4::wxxx() const { return { w, x, x, x }; }
inline ivec4 ivec4::wxxy() const { return { w, x, x, y }; }
inline ivec4 ivec4::wxxz() const { return { w, x, x, z }; }
inline ivec3 ivec4::wxy() const { return { w, x, y }; }
inline ivec4 ivec4::wxyw() const { return { w, x, y, w }; }
inline ivec4 ivec4::wxyx() const { return { w, x, y, x }; }
inline ivec4 ivec4::wxyy() const { return { w, x, y, y }; }
inline ivec4 ivec4::wxyz() const { return { w, x, y, z }; }
inline ivec3 ivec4::wxz() const { return { w, x, z }; }
inline ivec4 ivec4::wxzw() const { return { w, x, z, w }; }
inline ivec4 ivec4::wxzx() const { return { w, x, z, x }; }
inline ivec4 ivec4::wxzy() const { return { w, x, z, y }; }
inline ivec4 ivec4::wxzz() const { return { w, x, z, z }; }
inline ivec2 ivec4::wy() const { return { w, y }; }
inline ivec3 ivec4::wyw() const { return { w, y, w }; }
inline ivec4 ivec4::wyww() const { return { w, y, w, w }; }
inline ivec4 ivec4::wywx() const { return { w, y, w, x }; }
inline ivec4 ivec4::wywy() const { return { w, y, w, y }; }
inline ivec4 ivec4::wywz() const { return { w, y, w, z }; }
inline ivec3 ivec4::wyx() const { return { w, y, x }; }
inline ivec4 ivec4::wyxw() const { return { w, y, x, w }; }
inline ivec4 ivec4::wyxx() const { return { w, y, x, x }; }
inline ivec4 ivec4::wyxy() const { return { w, y, x, y }; }
inline ivec4 ivec4::wyxz() const { return { w, y, x, z }; }
inline ivec3 ivec4::wyy() const { return { w, y, y }; }
inline ivec4 ivec4::wyyw() const { return { w, y, y, w }; }
inline ivec4 ivec4::wyyx() const { return { w, y, y, x }; }
inline ivec4 ivec4::wyyy() const { return { w, y, y, y }; }
inline ivec4 ivec4::wyyz() const { return { w, y, y, z }; }
inline ivec3 ivec4::wyz() const { return { w, y, z }; }
inline ivec4 ivec4::wyzw() const { return { w, y, z, w }; }
inline ivec4 ivec4::wyzx() const { return { w, y, z, x }; }
inline ivec4 ivec4::wyzy() const { return { w, y, z, y }; }
inline ivec4 ivec4::wyzz() const { return { w, y, z, z }; }
inline ivec2 ivec4::wz() const { return { w, z }; }
inline ivec3 ivec4::wzw() const { return { w, z, w }; }
inline ivec4 ivec4::wzww() const { return { w, z, w, w }; }
inline ivec4 ivec4::wzwx() const { return { w, z, w, x }; }
inline ivec4 ivec4::wzwy() const { return { w, z, w, y }; }
inline ivec4 ivec4::wzwz() const { return { w, z, w, z }; }
inline ivec3 ivec4::wzx() const { return { w, z, x }; }
inline ivec4 ivec4::wzxw() const { return { w, z, x, w }; }
inline ivec4 ivec4::wzxx() const { return { w, z, x, x }; }
inline ivec4 ivec4::wzxy() const { return { w, z, x, y }; }
inline ivec4 ivec4::wzxz() const { return { w, z, x, z }; }
inline ivec3 ivec4::wzy() const { return { w, z, y }; }
inline ivec4 ivec4::wzyw() const { return { w, z, y, w }; }
inline ivec4 ivec4::wzyx() const { return { w, z, y, x }; }
inline ivec4 ivec4::wzyy() const { return { w, z, y, y }; }
inline ivec4 ivec4::wzyz() const { return { w, z, y, z }; }
inline ivec3 ivec4::wzz() const { return { w, z, z }; }
inline ivec4 ivec4::wzzw() const { return { w, z, z, w }; }
inline ivec4 ivec4::wzzx() const { return { w, z, z, x }; }
inline ivec4 ivec4::wzzy() const { return { w, z, z, y }; }
inline ivec4 ivec4::wzzz() const { return { w, z, z, z }; }
inline ivec2 ivec4::xw() const { return { x, w }; }
inline ivec3 ivec4::xww() const { return { x, w, w }; }
inline ivec4 ivec4::xwww() const { return { x, w, w, w }; }
inline ivec4 ivec4::xwwx() const { return { x, w, w, x }; }
inline ivec4 ivec4::xwwy() const { return { x, w, w, y }; }
inline ivec4 ivec4::xwwz() const { return { x, w, w, z }; }
inline ivec3 ivec4::xwx() const { return { x, w, x }; }
inline ivec4 ivec4::xwxw() const { return { x, w, x, w }; }
inline ivec4 ivec4::xwxx() const { return { x, w, x, x }; }
inline ivec4 ivec4::xwxy() const { return { x, w, x, y }; }
inline ivec4 ivec4::xwxz() const { return { x, w, x, z }; }
inline ivec3 ivec4::xwy() const { return { x, w, y }; }
inline ivec4 ivec4::xwyw() const { return { x, w, y, w }; }
inline ivec4 ivec4::xwyx() const { return { x, w, y, x }; }
inline ivec4 ivec4::xwyy() const { return { x, w, y, y }; }
inline ivec4 ivec4::xwyz() const { return { x, w, y, z }; }
inline ivec3 ivec4::xwz() const { return { x, w, z }; }
inline ivec4 ivec4::xwzw() const { return { x, w, z, w }; }
inline ivec4 ivec4::xwzx() const { return { x, w, z, x }; }
inline ivec4 ivec4::xwzy() const { return { x, w, z, y }; }
inline ivec4 ivec4::xwzz() const { return { x, w, z, z }; }
inline ivec2 ivec4::xx() const { return { x, x }; }
inline ivec3 ivec4::xxw() const { return { x, x, w }; }
inline ivec4 ivec4::xxww() const { return { x, x, w, w }; }
inline ivec4 ivec4::xxwx() const { return { x, x, w, x }; }
inline ivec4 ivec4::xxwy() const { return { x, x, w, y }; }
inline ivec4 ivec4::xxwz() const { return { x, x, w, z }; }
inline ivec3 ivec4::xxx() const { return { x, x, x }; }
inline ivec4 ivec4::xxxw() const { return { x, x, x, w }; }
inline ivec4 ivec4::xxxx() const { return { x, x, x, x }; }
inline ivec4 ivec4::xxxy() const { return { x, x, x, y }; }
inline ivec4 ivec4::xxxz() const { return { x, x, x, z }; }
inline ivec3 ivec4::xxy() const { return { x, x, y }; }
inline ivec4 ivec4::xxyw() const { return { x, x, y, w }; }
inline ivec4 ivec4::xxyx() const { return { x, x, y, x }; }
inline ivec4 ivec4::xxyy() const { return { x, x, y, y }; }
inline ivec4 ivec4::xxyz() const { return { x, x, y, z }; }
inline ivec3 ivec4::xxz() const { return { x, x, z }; }
inline ivec4 ivec4::xxzw() const { return { x, x, z, w }; }
inline ivec4 ivec4::xxzx() const { return { x, x, z, x }; }
inline ivec4 ivec4::xxzy() const { return { x, x, z, y }; }
inline ivec4 ivec4::xxzz() const { return { x, x, z, z }; }
inline ivec2 ivec4::xy() const { return { x, y }; }
inline ivec3 ivec4::xyw() const { return { x, y, w }; }
inline ivec4 ivec4::xyww() const { return { x, y, w, w }; }
inline ivec4 ivec4::xywx() const { return { x, y, w, x }; }
inline ivec4 ivec4::xywy() const { return { x, y, w, y }; }
inline ivec4 ivec4::xywz() const { return { x, y, w, z }; }
inline ivec3 ivec4::xyx() const { return { x, y, x }; }
inline ivec4 ivec4::xyxw() const { return { x, y, x, w }; }
inline ivec4 ivec4::xyxx() const { return { x, y, x, x }; }
inline ivec4 ivec4::xyxy() const { return { x, y, x, y }; }
inline ivec4 ivec4::xyxz() const { return { x, y, x, z }; }
inline ivec3 ivec4::xyy() const { return { x, y, y }; }
inline ivec4 ivec4::xyyw() const { return { x, y, y, w }; }
inline ivec4 ivec4::xyyx() const { return { x, y, y, x }; }
inline ivec4 ivec4::xyyy() const { return { x, y, y, y }; }
inline ivec4 ivec4::xyyz() const { return { x, y, y, z }; }
inline ivec3 ivec4::xyz() const { return { x, y, z }; }
inline ivec4 ivec4::xyzw() const { return { x, y, z, w }; }
inline ivec4 ivec4::xyzx() const { return { x, y, z, x }; }
inline ivec4 ivec4::xyzy() const { return { x, y, z, y }; }
inline ivec4 ivec4::xyzz() const { return { x, y, z, z }; }
inline ivec2 ivec4::xz() const { return { x, z }; }
inline ivec3 ivec4::xzw() const { return { x, z, w }; }
inline ivec4 ivec4::xzww() const { return { x, z, w, w }; }
inline ivec4 ivec4::xzwx() const { return { x, z, w, x }; }
inline ivec4 ivec4::xzwy() const { return { x, z, w, y }; }
inline ivec4 ivec4::xzwz() const { return { x, z, w, z }; }
inline ivec3 ivec4::xzx() const { return { x, z, x }; }
inline ivec4 ivec4::xzxw() const { return { x, z, x, w }; }
inline ivec4 ivec4::xzxx() const { return { x, z, x, x }; }
inline ivec4 ivec4::xzxy() const { return { x, z, x, y }; }
inline ivec4 ivec4::xzxz() const { return { x, z, x, z }; }
inline ivec3 ivec4::xzy() const { return { x, z, y }; }
inline ivec4 ivec4::xzyw() const { return { x, z, y, w }; }
inline ivec4 ivec4::xzyx() const { return { x, z, y, x }; }
inline ivec4 ivec4::xzyy() const { return { x, z, y, y }; }
inline ivec4 ivec4::xzyz() const { return { x, z, y, z }; }
inline ivec3 ivec4::xzz() const { return { x, z, z }; }
inline ivec4 ivec4::xzzw() const { return { x, z, z, w }; }
inline ivec4 ivec4::xzzx() const { return { x, z, z, x }; }
inline ivec4 ivec4::xzzy() const { return { x, z, z, y }; }
inline ivec4 ivec4::xzzz() const { return { x, z, z, z }; }
inline ivec2 ivec4::yw() const { return { y, w }; }
inline ivec3 ivec4::yww() const { return { y, w, w }; }
inline ivec4 ivec4::ywww() const { return { y, w, w, w }; }
inline ivec4 ivec4::ywwx() const { return { y, w, w, x }; }
inline ivec4 ivec4::ywwy() const { return { y, w, w, y }; }
inline ivec4 ivec4::ywwz() const { return { y, w, w, z }; }
inline ivec3 ivec4::ywx() const { return { y, w, x }; }
inline ivec4 ivec4::ywxw() const { return { y, w, x, w }; }
inline ivec4 ivec4::ywxx() const { return { y, w, x, x }; }
inline ivec4 ivec4::ywxy() const { return { y, w, x, y }; }
inline ivec4 ivec4::ywxz() const { return { y, w, x, z }; }
inline ivec3 ivec4::ywy() const { return { y, w, y }; }
inline ivec4 ivec4::ywyw() const { return { y, w, y, w }; }
inline ivec4 ivec4::ywyx() const { return { y, w, y, x }; }
inline ivec4 ivec4::ywyy() const { return { y, w, y, y }; }
inline ivec4 ivec4::ywyz() const { return { y, w, y, z }; }
inline ivec3 ivec4::ywz() const { return { y, w, z }; }
inline ivec4 ivec4::ywzw() const { return { y, w, z, w }; }
inline ivec4 ivec4::ywzx() const { return { y, w, z, x }; }
inline ivec4 ivec4::ywzy() const { return { y, w, z, y }; }
inline ivec4 ivec4::ywzz() const { return { y, w, z, z }; }
inline ivec2 ivec4::yx() const { return { y, x }; }
inline ivec3 ivec4::yxw() const { return { y, x, w }; }
inline ivec4 ivec4::yxww() const { return { y, x, w, w }; }
inline ivec4 ivec4::yxwx() const { return { y, x, w, x }; }
inline ivec4 ivec4::yxwy() const { return { y, x, w, y }; }
inline ivec4 ivec4::yxwz() const { return { y, x, w, z }; }
inline ivec3 ivec4::yxx() const { return { y, x, x }; }
inline ivec4 ivec4::yxxw() const { return { y, x, x, w }; }
inline ivec4 ivec4::yxxx() const { return { y, x, x, x }; }
inline ivec4 ivec4::yxxy() const { return { y, x, x, y }; }
inline ivec4 ivec4::yxxz() const { return { y, x, x, z }; }
inline ivec3 ivec4::yxy() const { return { y, x, y }; }
inline ivec4 ivec4::yxyw() const { return { y, x, y, w }; }
inline ivec4 ivec4::yxyx() const { return { y, x, y, x }; }
inline ivec4 ivec4::yxyy() const { return { y, x, y, y }; }
inline ivec4 ivec4::yxyz() const { return { y, x, y, z }; }
inline ivec3 ivec4::yxz() const { return { y, x, z }; }
inline ivec4 ivec4::yxzw() const { return { y, x, z, w }; }
inline ivec4 ivec4::yxzx() const { return { y, x, z, x }; }
inline ivec4 ivec4::yxzy() const { return { y, x, z, y }; }
inline ivec4 ivec4::yxzz() const { return { y, x, z, z }; }
inline ivec2 ivec4::yy() const { return { y, y }; }
inline ivec3 ivec4::yyw() const { return { y, y, w }; }
inline ivec4 ivec4::yyww() const { return { y, y, w, w }; }
inline ivec4 ivec4::yywx() const { return { y, y, w, x }; }
inline ivec4 ivec4::yywy() const { return { y, y, w, y }; }
inline ivec4 ivec4::yywz() const { return { y, y, w, z }; }
inline ivec3 ivec4::yyx() const { return { y, y, x }; }
inline ivec4 ivec4::yyxw() const { return { y, y, x, w }; }
inline ivec4 ivec4::yyxx() const { return { y, y, x, x }; }
inline ivec4 ivec4::yyxy() const { return { y, y, x, y }; }
inline ivec4 ivec4::yyxz() const { return { y, y, x, z }; }
inline ivec3 ivec4::yyy() const { return { y, y, y }; }
inline ivec4 ivec4::yyyw() const { return { y, y, y, w }; }
inline ivec4 ivec4::yyyx() const { return { y, y, y, x }; }
inline ivec4 ivec4::yyyy() const { return { y, y, y, y }; }
inline ivec4 ivec4::yyyz() const { return { y, y, y, z }; }
inline ivec3 ivec4::yyz() const { return { y, y, z }; }
inline ivec4 ivec4::yyzw() const { return { y, y, z, w }; }
inline ivec4 ivec4::yyzx() const { return { y, y, z, x }; }
inline ivec4 ivec4::yyzy() const { return { y, y, z, y }; }
inline ivec4 ivec4::yyzz() const { return { y, y, z, z }; }
inline ivec2 ivec4::yz() const { return { y, z }; }
inline ivec3 ivec4::yzw() const { return { y, z, w }; }
inline ivec4 ivec4::yzww() const { return { y, z, w, w }; }
inline ivec4 ivec4::yzwx() const { return { y, z, w, x }; }
inline ivec4 ivec4::yzwy() const { return { y, z, w, y }; }
inline ivec4 ivec4::yzwz() const { return { y, z, w, z }; }
inline ivec3 ivec4::yzx() const { return { y, z, x }; }
inline ivec4 ivec4::yzxw() const { return { y, z, x, w }; }
inline ivec4 ivec4::yzxx() const { return { y, z, x, x }; }
inline ivec4 ivec4::yzxy() const { return { y, z, x, y }; }
inline ivec4 ivec4::yzxz() const { return { y, z, x, z }; }
inline ivec3 ivec4::yzy() const { return { y, z, y }; }
inline ivec4 ivec4::yzyw() const { return { y, z, y, w }; }
inline ivec4 ivec4::yzyx() const { return { y, z, y, x }; }
inline ivec4 ivec4::yzyy() const { return { y, z, y, y }; }
inline ivec4 ivec4::yzyz() const { return { y, z, y, z }; }
inline ivec3 ivec4::yzz() const { return { y, z, z }; }
inline ivec4 ivec4::yzzw() const { return { y, z, z, w }; }
inline ivec4 ivec4::yzzx() const { return { y, z, z, x }; }
inline ivec4 ivec4::yzzy() const { return { y, z, z, y }; }
inline ivec4 ivec4::yzzz() const { return { y, z, z, z }; }
inline ivec2 ivec4::zw() const { return { z, w }; }
inline ivec3 ivec4::zww() const { return { z, w, w }; }
inline ivec4 ivec4::zwww() const { return { z, w, w, w }; }
inline ivec4 ivec4::zwwx() const { return { z, w, w, x }; }
inline ivec4 ivec4::zwwy() const { return { z, w, w, y }; }
inline ivec4 ivec4::zwwz() const { return { z, w, w, z }; }
inline ivec3 ivec4::zwx() const { return { z, w, x }; }
inline ivec4 ivec4::zwxw() const { return { z, w, x, w }; }
inline ivec4 ivec4::zwxx() const { return { z, w, x, x }; }
inline ivec4 ivec4::zwxy() const { return { z, w, x, y }; }
inline ivec4 ivec4::zwxz() const { return { z, w, x, z }; }
inline ivec3 ivec4::zwy() const { return { z, w, y }; }
inline ivec4 ivec4::zwyw() const { return { z, w, y, w }; }
inline ivec4 ivec4::zwyx() const { return { z, w, y, x }; }
inline ivec4 ivec4::zwyy() const { return { z, w, y, y }; }
inline ivec4 ivec4::zwyz() const { return { z, w, y, z }; }
inline ivec3 ivec4::zwz() const { return { z, w, z }; }
inline ivec4 ivec4::zwzw() const { return { z, w, z, w }; }
inline ivec4 ivec4::zwzx() const { return { z, w, z, x }; }
inline ivec4 ivec4::zwzy() const { return { z, w, z, y }; }
inline ivec4 ivec4::zwzz() const { return { z, w, z, z }; }
inline ivec2 ivec4::zx() const { return { z, x }; }
inline ivec3 ivec4::zxw() const { return { z, x, w }; }
inline ivec4 ivec4::zxww() const { return { z, x, w, w }; }
inline ivec4 ivec4::zxwx() const { return { z, x, w, x }; }
inline ivec4 ivec4::zxwy() const { return { z, x, w, y }; }
inline ivec4 ivec4::zxwz() const { return { z, x, w, z }; }
inline ivec3 ivec4::zxx() const { return { z, x, x }; }
inline ivec4 ivec4::zxxw() const { return { z, x, x, w }; }
inline ivec4 ivec4::zxxx() const { return { z, x, x, x }; }
inline ivec4 ivec4::zxxy() const { return { z, x, x, y }; }
inline ivec4 ivec4::zxxz() const { return { z, x, x, z }; }
inline ivec3 ivec4::zxy() const { return { z, x, y }; }
inline ivec4 ivec4::zxyw() const { return { z, x, y, w }; }
inline ivec4 ivec4::zxyx() const { return { z, x, y, x }; }
inline ivec4 ivec4::zxyy() const { return { z, x, y, y }; }
inline ivec4 ivec4::zxyz() const { return { z, x, y, z }; }
inline ivec3 ivec4::zxz() const { return { z, x, z }; }
inline ivec4 ivec4::zxzw() const { return { z, x, z, w }; }
inline ivec4 ivec4::zxzx() const { return { z, x, z, x }; }
inline ivec4 ivec4::zxzy() const { return { z, x, z, y }; }
inline ivec4 ivec4::zxzz() const { return { z, x, z, z }; }
inline ivec2 ivec4::zy() const { return { z, y }; }
inline ivec3 ivec4::zyw() const { return { z, y, w }; }
inline ivec4 ivec4::zyww() const { return { z, y, w, w }; }
inline ivec4 ivec4::zywx() const { return { z, y, w, x }; }
inline ivec4 ivec4::zywy() const { return { z, y, w, y }; }
inline ivec4 ivec4::zywz() const { return { z, y, w, z }; }
inline ivec3 ivec4::zyx() const { return { z, y, x }; }
inline ivec4 ivec4::zyxw() const { return { z, y, x, w }; }
inline ivec4 ivec4::zyxx() const { return { z, y, x, x }; }
inline ivec4 ivec4::zyxy() const { return { z, y, x, y }; }
inline ivec4 ivec4::zyxz() const { return { z, y, x, z }; }
inline ivec3 ivec4::zyy() const { return { z, y, y }; }
inline ivec4 ivec4::zyyw() const { return { z, y, y, w }; }
inline ivec4 ivec4::zyyx() const { return { z, y, y, x }; }
inline ivec4 ivec4::zyyy() const { return { z, y, y, y }; }
inline ivec4 ivec4::zyyz() const { return { z, y, y, z }; }
inline ivec3 ivec4::zyz() const { return { z, y, z }; }
inline ivec4 ivec4::zyzw() const { return { z, y, z, w }; }
inline ivec4 ivec4::zyzx() const { return { z, y, z, x }; }
inline ivec4 ivec4::zyzy() const { return { z, y, z, y }; }
inline ivec4 ivec4::zyzz() const { return { z, y, z, z }; }
inline ivec2 ivec4::zz() const { return { z, z }; }
inline ivec3 ivec4::zzw() const { return { z, z, w }; }
inline ivec4 ivec4::zzww() const { return { z, z, w, w }; }
inline ivec4 ivec4::zzwx() const { return { z, z, w, x }; }
inline ivec4 ivec4::zzwy() const { return { z, z, w, y }; }
inline ivec4 ivec4::zzwz() const { return { z, z, w, z }; }
inline ivec3 ivec4::zzx() const { return { z, z, x }; }
inline ivec4 ivec4::zzxw() const { return { z, z, x, w }; }
inline ivec4 ivec4::zzxx() const { return { z, z, x, x }; }
inline ivec4 ivec4::zzxy() const { return { z, z, x, y }; }
inline ivec4 ivec4::zzxz() const { return { z, z, x, z }; }
inline ivec3 ivec4::zzy() const { return { z, z, y }; }
inline ivec4 ivec4::zzyw() const { return { z, z, y, w }; }
inline ivec4 ivec4::zzyx() const { return { z, z, y, x }; }
inline ivec4 ivec4::zzyy() const { return { z, z, y, y }; }
inline ivec4 ivec4::zzyz() const { return { z, z, y, z }; }
inline ivec3 ivec4::zzz() const { return { z, z, z }; }
inline ivec4 ivec4::zzzw() const { return { z, z, z, w }; }
inline ivec4 ivec4::zzzx() const { return { z, z, z, x }; }
inline ivec4 ivec4::zzzy() const { return { z, z, z, y }; }
inline ivec4 ivec4::zzzz() const { return { z, z, z, z }; }
inline void ivec4::ab(const simdint& _val0, const simdint& _val1) { a = _val0; b = _val1; }
inline void ivec4::ab(const ivec2& _val) { a = _val.x; b = _val.y; }
inline void ivec4::ab(const simdint& _val) { a = _val; b = _val; }
inline void ivec4::abg(const simdint& _val0, const simdint& _val1, const simdint& _val2) { a = _val0; b = _val1; g = _val2; }
inline void ivec4::abg(const ivec3& _val) { a = _val.x; b = _val.y; g = _val.z; }
inline void ivec4::abg(const simdint& _val) { a = _val; b = _val; g = _val; }
inline void ivec4::abgr(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { a = _val0; b = _val1; g = _val2; r = _val3; }
inline void ivec4::abgr(const ivec4& _val) { a = _val.x; b = _val.y; g = _val.z; r = _val.w; }
inline void ivec4::abgr(const simdint& _val) { a = _val; b = _val; g = _val; r = _val; }
inline void ivec4::abr(const simdint& _val0, const simdint& _val1, const simdint& _val2) { a = _val0; b = _val1; r = _val2; }
inline void ivec4::abr(const ivec3& _val) { a = _val.x; b = _val.y; r = _val.z; }
inline void ivec4::abr(const simdint& _val) { a = _val; b = _val; r = _val; }
inline void ivec4::abrg(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { a = _val0; b = _val1; r = _val2; g = _val3; }
inline void ivec4::abrg(const ivec4& _val) { a = _val.x; b = _val.y; r = _val.z; g = _val.w; }
inline void ivec4::abrg(const simdint& _val) { a = _val; b = _val; r = _val; g = _val; }
inline void ivec4::ag(const simdint& _val0, const simdint& _val1) { a = _val0; g = _val1; }
inline void ivec4::ag(const ivec2& _val) { a = _val.x; g = _val.y; }
inline void ivec4::ag(const simdint& _val) { a = _val; g = _val; }
inline void ivec4::agb(const simdint& _val0, const simdint& _val1, const simdint& _val2) { a = _val0; g = _val1; b = _val2; }
inline void ivec4::agb(const ivec3& _val) { a = _val.x; g = _val.y; b = _val.z; }
inline void ivec4::agb(const simdint& _val) { a = _val; g = _val; b = _val; }
inline void ivec4::agbr(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { a = _val0; g = _val1; b = _val2; r = _val3; }
inline void ivec4::agbr(const ivec4& _val) { a = _val.x; g = _val.y; b = _val.z; r = _val.w; }
inline void ivec4::agbr(const simdint& _val) { a = _val; g = _val; b = _val; r = _val; }
inline void ivec4::agr(const simdint& _val0, const simdint& _val1, const simdint& _val2) { a = _val0; g = _val1; r = _val2; }
inline void ivec4::agr(const ivec3& _val) { a = _val.x; g = _val.y; r = _val.z; }
inline void ivec4::agr(const simdint& _val) { a = _val; g = _val; r = _val; }
inline void ivec4::agrb(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { a = _val0; g = _val1; r = _val2; b = _val3; }
inline void ivec4::agrb(const ivec4& _val) { a = _val.x; g = _val.y; r = _val.z; b = _val.w; }
inline void ivec4::agrb(const simdint& _val) { a = _val; g = _val; r = _val; b = _val; }
inline void ivec4::ar(const simdint& _val0, const simdint& _val1) { a = _val0; r = _val1; }
inline void ivec4::ar(const ivec2& _val) { a = _val.x; r = _val.y; }
inline void ivec4::ar(const simdint& _val) { a = _val; r = _val; }
inline void ivec4::arb(const simdint& _val0, const simdint& _val1, const simdint& _val2) { a = _val0; r = _val1; b = _val2; }
inline void ivec4::arb(const ivec3& _val) { a = _val.x; r = _val.y; b = _val.z; }
inline void ivec4::arb(const simdint& _val) { a = _val; r = _val; b = _val; }
inline void ivec4::arbg(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { a = _val0; r = _val1; b = _val2; g = _val3; }
inline void ivec4::arbg(const ivec4& _val) { a = _val.x; r = _val.y; b = _val.z; g = _val.w; }
inline void ivec4::arbg(const simdint& _val) { a = _val; r = _val; b = _val; g = _val; }
inline void ivec4::arg(const simdint& _val0, const simdint& _val1, const simdint& _val2) { a = _val0; r = _val1; g = _val2; }
inline void ivec4::arg(const ivec3& _val) { a = _val.x; r = _val.y; g = _val.z; }
inline void ivec4::arg(const simdint& _val) { a = _val; r = _val; g = _val; }
inline void ivec4::argb(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { a = _val0; r = _val1; g = _val2; b = _val3; }
inline void ivec4::argb(const ivec4& _val) { a = _val.x; r = _val.y; g = _val.z; b = _val.w; }
inline void ivec4::argb(const simdint& _val) { a = _val; r = _val; g = _val; b = _val; }
inline void ivec4::ba(const simdint& _val0, const simdint& _val1) { b = _val0; a = _val1; }
inline void ivec4::ba(const ivec2& _val) { b = _val.x; a = _val.y; }
inline void ivec4::ba(const simdint& _val) { b = _val; a = _val; }
inline void ivec4::bag(const simdint& _val0, const simdint& _val1, const simdint& _val2) { b = _val0; a = _val1; g = _val2; }
inline void ivec4::bag(const ivec3& _val) { b = _val.x; a = _val.y; g = _val.z; }
inline void ivec4::bag(const simdint& _val) { b = _val; a = _val; g = _val; }
inline void ivec4::bagr(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { b = _val0; a = _val1; g = _val2; r = _val3; }
inline void ivec4::bagr(const ivec4& _val) { b = _val.x; a = _val.y; g = _val.z; r = _val.w; }
inline void ivec4::bagr(const simdint& _val) { b = _val; a = _val; g = _val; r = _val; }
inline void ivec4::bar(const simdint& _val0, const simdint& _val1, const simdint& _val2) { b = _val0; a = _val1; r = _val2; }
inline void ivec4::bar(const ivec3& _val) { b = _val.x; a = _val.y; r = _val.z; }
inline void ivec4::bar(const simdint& _val) { b = _val; a = _val; r = _val; }
inline void ivec4::barg(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { b = _val0; a = _val1; r = _val2; g = _val3; }
inline void ivec4::barg(const ivec4& _val) { b = _val.x; a = _val.y; r = _val.z; g = _val.w; }
inline void ivec4::barg(const simdint& _val) { b = _val; a = _val; r = _val; g = _val; }
inline void ivec4::bg(const simdint& _val0, const simdint& _val1) { b = _val0; g = _val1; }
inline void ivec4::bg(const ivec2& _val) { b = _val.x; g = _val.y; }
inline void ivec4::bg(const simdint& _val) { b = _val; g = _val; }
inline void ivec4::bga(const simdint& _val0, const simdint& _val1, const simdint& _val2) { b = _val0; g = _val1; a = _val2; }
inline void ivec4::bga(const ivec3& _val) { b = _val.x; g = _val.y; a = _val.z; }
inline void ivec4::bga(const simdint& _val) { b = _val; g = _val; a = _val; }
inline void ivec4::bgar(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { b = _val0; g = _val1; a = _val2; r = _val3; }
inline void ivec4::bgar(const ivec4& _val) { b = _val.x; g = _val.y; a = _val.z; r = _val.w; }
inline void ivec4::bgar(const simdint& _val) { b = _val; g = _val; a = _val; r = _val; }
inline void ivec4::bgr(const simdint& _val0, const simdint& _val1, const simdint& _val2) { b = _val0; g = _val1; r = _val2; }
inline void ivec4::bgr(const ivec3& _val) { b = _val.x; g = _val.y; r = _val.z; }
inline void ivec4::bgr(const simdint& _val) { b = _val; g = _val; r = _val; }
inline void ivec4::bgra(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { b = _val0; g = _val1; r = _val2; a = _val3; }
inline void ivec4::bgra(const ivec4& _val) { b = _val.x; g = _val.y; r = _val.z; a = _val.w; }
inline void ivec4::bgra(const simdint& _val) { b = _val; g = _val; r = _val; a = _val; }
inline void ivec4::br(const simdint& _val0, const simdint& _val1) { b = _val0; r = _val1; }
inline void ivec4::br(const ivec2& _val) { b = _val.x; r = _val.y; }
inline void ivec4::br(const simdint& _val) { b = _val; r = _val; }
inline void ivec4::bra(const simdint& _val0, const simdint& _val1, const simdint& _val2) { b = _val0; r = _val1; a = _val2; }
inline void ivec4::bra(const ivec3& _val) { b = _val.x; r = _val.y; a = _val.z; }
inline void ivec4::bra(const simdint& _val) { b = _val; r = _val; a = _val; }
inline void ivec4::brag(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { b = _val0; r = _val1; a = _val2; g = _val3; }
inline void ivec4::brag(const ivec4& _val) { b = _val.x; r = _val.y; a = _val.z; g = _val.w; }
inline void ivec4::brag(const simdint& _val) { b = _val; r = _val; a = _val; g = _val; }
inline void ivec4::brg(const simdint& _val0, const simdint& _val1, const simdint& _val2) { b = _val0; r = _val1; g = _val2; }
inline void ivec4::brg(const ivec3& _val) { b = _val.x; r = _val.y; g = _val.z; }
inline void ivec4::brg(const simdint& _val) { b = _val; r = _val; g = _val; }
inline void ivec4::brga(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { b = _val0; r = _val1; g = _val2; a = _val3; }
inline void ivec4::brga(const ivec4& _val) { b = _val.x; r = _val.y; g = _val.z; a = _val.w; }
inline void ivec4::brga(const simdint& _val) { b = _val; r = _val; g = _val; a = _val; }
inline void ivec4::ga(const simdint& _val0, const simdint& _val1) { g = _val0; a = _val1; }
inline void ivec4::ga(const ivec2& _val) { g = _val.x; a = _val.y; }
inline void ivec4::ga(const simdint& _val) { g = _val; a = _val; }
inline void ivec4::gab(const simdint& _val0, const simdint& _val1, const simdint& _val2) { g = _val0; a = _val1; b = _val2; }
inline void ivec4::gab(const ivec3& _val) { g = _val.x; a = _val.y; b = _val.z; }
inline void ivec4::gab(const simdint& _val) { g = _val; a = _val; b = _val; }
inline void ivec4::gabr(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { g = _val0; a = _val1; b = _val2; r = _val3; }
inline void ivec4::gabr(const ivec4& _val) { g = _val.x; a = _val.y; b = _val.z; r = _val.w; }
inline void ivec4::gabr(const simdint& _val) { g = _val; a = _val; b = _val; r = _val; }
inline void ivec4::gar(const simdint& _val0, const simdint& _val1, const simdint& _val2) { g = _val0; a = _val1; r = _val2; }
inline void ivec4::gar(const ivec3& _val) { g = _val.x; a = _val.y; r = _val.z; }
inline void ivec4::gar(const simdint& _val) { g = _val; a = _val; r = _val; }
inline void ivec4::garb(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { g = _val0; a = _val1; r = _val2; b = _val3; }
inline void ivec4::garb(const ivec4& _val) { g = _val.x; a = _val.y; r = _val.z; b = _val.w; }
inline void ivec4::garb(const simdint& _val) { g = _val; a = _val; r = _val; b = _val; }
inline void ivec4::gb(const simdint& _val0, const simdint& _val1) { g = _val0; b = _val1; }
inline void ivec4::gb(const ivec2& _val) { g = _val.x; b = _val.y; }
inline void ivec4::gb(const simdint& _val) { g = _val; b = _val; }
inline void ivec4::gba(const simdint& _val0, const simdint& _val1, const simdint& _val2) { g = _val0; b = _val1; a = _val2; }
inline void ivec4::gba(const ivec3& _val) { g = _val.x; b = _val.y; a = _val.z; }
inline void ivec4::gba(const simdint& _val) { g = _val; b = _val; a = _val; }
inline void ivec4::gbar(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { g = _val0; b = _val1; a = _val2; r = _val3; }
inline void ivec4::gbar(const ivec4& _val) { g = _val.x; b = _val.y; a = _val.z; r = _val.w; }
inline void ivec4::gbar(const simdint& _val) { g = _val; b = _val; a = _val; r = _val; }
inline void ivec4::gbr(const simdint& _val0, const simdint& _val1, const simdint& _val2) { g = _val0; b = _val1; r = _val2; }
inline void ivec4::gbr(const ivec3& _val) { g = _val.x; b = _val.y; r = _val.z; }
inline void ivec4::gbr(const simdint& _val) { g = _val; b = _val; r = _val; }
inline void ivec4::gbra(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { g = _val0; b = _val1; r = _val2; a = _val3; }
inline void ivec4::gbra(const ivec4& _val) { g = _val.x; b = _val.y; r = _val.z; a = _val.w; }
inline void ivec4::gbra(const simdint& _val) { g = _val; b = _val; r = _val; a = _val; }
inline void ivec4::gr(const simdint& _val0, const simdint& _val1) { g = _val0; r = _val1; }
inline void ivec4::gr(const ivec2& _val) { g = _val.x; r = _val.y; }
inline void ivec4::gr(const simdint& _val) { g = _val; r = _val; }
inline void ivec4::gra(const simdint& _val0, const simdint& _val1, const simdint& _val2) { g = _val0; r = _val1; a = _val2; }
inline void ivec4::gra(const ivec3& _val) { g = _val.x; r = _val.y; a = _val.z; }
inline void ivec4::gra(const simdint& _val) { g = _val; r = _val; a = _val; }
inline void ivec4::grab(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { g = _val0; r = _val1; a = _val2; b = _val3; }
inline void ivec4::grab(const ivec4& _val) { g = _val.x; r = _val.y; a = _val.z; b = _val.w; }
inline void ivec4::grab(const simdint& _val) { g = _val; r = _val; a = _val; b = _val; }
inline void ivec4::grb(const simdint& _val0, const simdint& _val1, const simdint& _val2) { g = _val0; r = _val1; b = _val2; }
inline void ivec4::grb(const ivec3& _val) { g = _val.x; r = _val.y; b = _val.z; }
inline void ivec4::grb(const simdint& _val) { g = _val; r = _val; b = _val; }
inline void ivec4::grba(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { g = _val0; r = _val1; b = _val2; a = _val3; }
inline void ivec4::grba(const ivec4& _val) { g = _val.x; r = _val.y; b = _val.z; a = _val.w; }
inline void ivec4::grba(const simdint& _val) { g = _val; r = _val; b = _val; a = _val; }
inline void ivec4::ra(const simdint& _val0, const simdint& _val1) { r = _val0; a = _val1; }
inline void ivec4::ra(const ivec2& _val) { r = _val.x; a = _val.y; }
inline void ivec4::ra(const simdint& _val) { r = _val; a = _val; }
inline void ivec4::rab(const simdint& _val0, const simdint& _val1, const simdint& _val2) { r = _val0; a = _val1; b = _val2; }
inline void ivec4::rab(const ivec3& _val) { r = _val.x; a = _val.y; b = _val.z; }
inline void ivec4::rab(const simdint& _val) { r = _val; a = _val; b = _val; }
inline void ivec4::rabg(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { r = _val0; a = _val1; b = _val2; g = _val3; }
inline void ivec4::rabg(const ivec4& _val) { r = _val.x; a = _val.y; b = _val.z; g = _val.w; }
inline void ivec4::rabg(const simdint& _val) { r = _val; a = _val; b = _val; g = _val; }
inline void ivec4::rag(const simdint& _val0, const simdint& _val1, const simdint& _val2) { r = _val0; a = _val1; g = _val2; }
inline void ivec4::rag(const ivec3& _val) { r = _val.x; a = _val.y; g = _val.z; }
inline void ivec4::rag(const simdint& _val) { r = _val; a = _val; g = _val; }
inline void ivec4::ragb(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { r = _val0; a = _val1; g = _val2; b = _val3; }
inline void ivec4::ragb(const ivec4& _val) { r = _val.x; a = _val.y; g = _val.z; b = _val.w; }
inline void ivec4::ragb(const simdint& _val) { r = _val; a = _val; g = _val; b = _val; }
inline void ivec4::rb(const simdint& _val0, const simdint& _val1) { r = _val0; b = _val1; }
inline void ivec4::rb(const ivec2& _val) { r = _val.x; b = _val.y; }
inline void ivec4::rb(const simdint& _val) { r = _val; b = _val; }
inline void ivec4::rba(const simdint& _val0, const simdint& _val1, const simdint& _val2) { r = _val0; b = _val1; a = _val2; }
inline void ivec4::rba(const ivec3& _val) { r = _val.x; b = _val.y; a = _val.z; }
inline void ivec4::rba(const simdint& _val) { r = _val; b = _val; a = _val; }
inline void ivec4::rbag(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { r = _val0; b = _val1; a = _val2; g = _val3; }
inline void ivec4::rbag(const ivec4& _val) { r = _val.x; b = _val.y; a = _val.z; g = _val.w; }
inline void ivec4::rbag(const simdint& _val) { r = _val; b = _val; a = _val; g = _val; }
inline void ivec4::rbg(const simdint& _val0, const simdint& _val1, const simdint& _val2) { r = _val0; b = _val1; g = _val2; }
inline void ivec4::rbg(const ivec3& _val) { r = _val.x; b = _val.y; g = _val.z; }
inline void ivec4::rbg(const simdint& _val) { r = _val; b = _val; g = _val; }
inline void ivec4::rbga(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { r = _val0; b = _val1; g = _val2; a = _val3; }
inline void ivec4::rbga(const ivec4& _val) { r = _val.x; b = _val.y; g = _val.z; a = _val.w; }
inline void ivec4::rbga(const simdint& _val) { r = _val; b = _val; g = _val; a = _val; }
inline void ivec4::rg(const simdint& _val0, const simdint& _val1) { r = _val0; g = _val1; }
inline void ivec4::rg(const ivec2& _val) { r = _val.x; g = _val.y; }
inline void ivec4::rg(const simdint& _val) { r = _val; g = _val; }
inline void ivec4::rga(const simdint& _val0, const simdint& _val1, const simdint& _val2) { r = _val0; g = _val1; a = _val2; }
inline void ivec4::rga(const ivec3& _val) { r = _val.x; g = _val.y; a = _val.z; }
inline void ivec4::rga(const simdint& _val) { r = _val; g = _val; a = _val; }
inline void ivec4::rgab(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { r = _val0; g = _val1; a = _val2; b = _val3; }
inline void ivec4::rgab(const ivec4& _val) { r = _val.x; g = _val.y; a = _val.z; b = _val.w; }
inline void ivec4::rgab(const simdint& _val) { r = _val; g = _val; a = _val; b = _val; }
inline void ivec4::rgb(const simdint& _val0, const simdint& _val1, const simdint& _val2) { r = _val0; g = _val1; b = _val2; }
inline void ivec4::rgb(const ivec3& _val) { r = _val.x; g = _val.y; b = _val.z; }
inline void ivec4::rgb(const simdint& _val) { r = _val; g = _val; b = _val; }
inline void ivec4::rgba(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { r = _val0; g = _val1; b = _val2; a = _val3; }
inline void ivec4::rgba(const ivec4& _val) { r = _val.x; g = _val.y; b = _val.z; a = _val.w; }
inline void ivec4::rgba(const simdint& _val) { r = _val; g = _val; b = _val; a = _val; }
inline void ivec4::qs(const simdint& _val0, const simdint& _val1) { q = _val0; s = _val1; }
inline void ivec4::qs(const ivec2& _val) { q = _val.s; s = _val.t; }
inline void ivec4::qs(const simdint& _val) { q = _val; s = _val; }
inline void ivec4::qst(const simdint& _val0, const simdint& _val1, const simdint& _val2) { q = _val0; s = _val1; t = _val2; }
inline void ivec4::qst(const ivec3& _val) { q = _val.s; s = _val.t; t = _val.p; }
inline void ivec4::qst(const simdint& _val) { q = _val; s = _val; t = _val; }
inline void ivec4::qstp(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { q = _val0; s = _val1; t = _val2; p = _val3; }
inline void ivec4::qstp(const ivec4& _val) { q = _val.s; s = _val.t; t = _val.p; p = _val.q; }
inline void ivec4::qstp(const simdint& _val) { q = _val; s = _val; t = _val; p = _val; }
inline void ivec4::qsp(const simdint& _val0, const simdint& _val1, const simdint& _val2) { q = _val0; s = _val1; p = _val2; }
inline void ivec4::qsp(const ivec3& _val) { q = _val.s; s = _val.t; p = _val.p; }
inline void ivec4::qsp(const simdint& _val) { q = _val; s = _val; p = _val; }
inline void ivec4::qspt(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { q = _val0; s = _val1; p = _val2; t = _val3; }
inline void ivec4::qspt(const ivec4& _val) { q = _val.s; s = _val.t; p = _val.p; t = _val.q; }
inline void ivec4::qspt(const simdint& _val) { q = _val; s = _val; p = _val; t = _val; }
inline void ivec4::qt(const simdint& _val0, const simdint& _val1) { q = _val0; t = _val1; }
inline void ivec4::qt(const ivec2& _val) { q = _val.s; t = _val.t; }
inline void ivec4::qt(const simdint& _val) { q = _val; t = _val; }
inline void ivec4::qts(const simdint& _val0, const simdint& _val1, const simdint& _val2) { q = _val0; t = _val1; s = _val2; }
inline void ivec4::qts(const ivec3& _val) { q = _val.s; t = _val.t; s = _val.p; }
inline void ivec4::qts(const simdint& _val) { q = _val; t = _val; s = _val; }
inline void ivec4::qtsp(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { q = _val0; t = _val1; s = _val2; p = _val3; }
inline void ivec4::qtsp(const ivec4& _val) { q = _val.s; t = _val.t; s = _val.p; p = _val.q; }
inline void ivec4::qtsp(const simdint& _val) { q = _val; t = _val; s = _val; p = _val; }
inline void ivec4::qtp(const simdint& _val0, const simdint& _val1, const simdint& _val2) { q = _val0; t = _val1; p = _val2; }
inline void ivec4::qtp(const ivec3& _val) { q = _val.s; t = _val.t; p = _val.p; }
inline void ivec4::qtp(const simdint& _val) { q = _val; t = _val; p = _val; }
inline void ivec4::qtps(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { q = _val0; t = _val1; p = _val2; s = _val3; }
inline void ivec4::qtps(const ivec4& _val) { q = _val.s; t = _val.t; p = _val.p; s = _val.q; }
inline void ivec4::qtps(const simdint& _val) { q = _val; t = _val; p = _val; s = _val; }
inline void ivec4::qp(const simdint& _val0, const simdint& _val1) { q = _val0; p = _val1; }
inline void ivec4::qp(const ivec2& _val) { q = _val.s; p = _val.t; }
inline void ivec4::qp(const simdint& _val) { q = _val; p = _val; }
inline void ivec4::qps(const simdint& _val0, const simdint& _val1, const simdint& _val2) { q = _val0; p = _val1; s = _val2; }
inline void ivec4::qps(const ivec3& _val) { q = _val.s; p = _val.t; s = _val.p; }
inline void ivec4::qps(const simdint& _val) { q = _val; p = _val; s = _val; }
inline void ivec4::qpst(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { q = _val0; p = _val1; s = _val2; t = _val3; }
inline void ivec4::qpst(const ivec4& _val) { q = _val.s; p = _val.t; s = _val.p; t = _val.q; }
inline void ivec4::qpst(const simdint& _val) { q = _val; p = _val; s = _val; t = _val; }
inline void ivec4::qpt(const simdint& _val0, const simdint& _val1, const simdint& _val2) { q = _val0; p = _val1; t = _val2; }
inline void ivec4::qpt(const ivec3& _val) { q = _val.s; p = _val.t; t = _val.p; }
inline void ivec4::qpt(const simdint& _val) { q = _val; p = _val; t = _val; }
inline void ivec4::qpts(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { q = _val0; p = _val1; t = _val2; s = _val3; }
inline void ivec4::qpts(const ivec4& _val) { q = _val.s; p = _val.t; t = _val.p; s = _val.q; }
inline void ivec4::qpts(const simdint& _val) { q = _val; p = _val; t = _val; s = _val; }
inline void ivec4::sq(const simdint& _val0, const simdint& _val1) { s = _val0; q = _val1; }
inline void ivec4::sq(const ivec2& _val) { s = _val.s; q = _val.t; }
inline void ivec4::sq(const simdint& _val) { s = _val; q = _val; }
inline void ivec4::sqt(const simdint& _val0, const simdint& _val1, const simdint& _val2) { s = _val0; q = _val1; t = _val2; }
inline void ivec4::sqt(const ivec3& _val) { s = _val.s; q = _val.t; t = _val.p; }
inline void ivec4::sqt(const simdint& _val) { s = _val; q = _val; t = _val; }
inline void ivec4::sqtp(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { s = _val0; q = _val1; t = _val2; p = _val3; }
inline void ivec4::sqtp(const ivec4& _val) { s = _val.s; q = _val.t; t = _val.p; p = _val.q; }
inline void ivec4::sqtp(const simdint& _val) { s = _val; q = _val; t = _val; p = _val; }
inline void ivec4::sqp(const simdint& _val0, const simdint& _val1, const simdint& _val2) { s = _val0; q = _val1; p = _val2; }
inline void ivec4::sqp(const ivec3& _val) { s = _val.s; q = _val.t; p = _val.p; }
inline void ivec4::sqp(const simdint& _val) { s = _val; q = _val; p = _val; }
inline void ivec4::sqpt(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { s = _val0; q = _val1; p = _val2; t = _val3; }
inline void ivec4::sqpt(const ivec4& _val) { s = _val.s; q = _val.t; p = _val.p; t = _val.q; }
inline void ivec4::sqpt(const simdint& _val) { s = _val; q = _val; p = _val; t = _val; }
inline void ivec4::st(const simdint& _val0, const simdint& _val1) { s = _val0; t = _val1; }
inline void ivec4::st(const ivec2& _val) { s = _val.s; t = _val.t; }
inline void ivec4::st(const simdint& _val) { s = _val; t = _val; }
inline void ivec4::stq(const simdint& _val0, const simdint& _val1, const simdint& _val2) { s = _val0; t = _val1; q = _val2; }
inline void ivec4::stq(const ivec3& _val) { s = _val.s; t = _val.t; q = _val.p; }
inline void ivec4::stq(const simdint& _val) { s = _val; t = _val; q = _val; }
inline void ivec4::stqp(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { s = _val0; t = _val1; q = _val2; p = _val3; }
inline void ivec4::stqp(const ivec4& _val) { s = _val.s; t = _val.t; q = _val.p; p = _val.q; }
inline void ivec4::stqp(const simdint& _val) { s = _val; t = _val; q = _val; p = _val; }
inline void ivec4::stp(const simdint& _val0, const simdint& _val1, const simdint& _val2) { s = _val0; t = _val1; p = _val2; }
inline void ivec4::stp(const ivec3& _val) { s = _val.s; t = _val.t; p = _val.p; }
inline void ivec4::stp(const simdint& _val) { s = _val; t = _val; p = _val; }
inline void ivec4::stpq(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { s = _val0; t = _val1; p = _val2; q = _val3; }
inline void ivec4::stpq(const ivec4& _val) { s = _val.s; t = _val.t; p = _val.p; q = _val.q; }
inline void ivec4::stpq(const simdint& _val) { s = _val; t = _val; p = _val; q = _val; }
inline void ivec4::sp(const simdint& _val0, const simdint& _val1) { s = _val0; p = _val1; }
inline void ivec4::sp(const ivec2& _val) { s = _val.s; p = _val.t; }
inline void ivec4::sp(const simdint& _val) { s = _val; p = _val; }
inline void ivec4::spq(const simdint& _val0, const simdint& _val1, const simdint& _val2) { s = _val0; p = _val1; q = _val2; }
inline void ivec4::spq(const ivec3& _val) { s = _val.s; p = _val.t; q = _val.p; }
inline void ivec4::spq(const simdint& _val) { s = _val; p = _val; q = _val; }
inline void ivec4::spqt(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { s = _val0; p = _val1; q = _val2; t = _val3; }
inline void ivec4::spqt(const ivec4& _val) { s = _val.s; p = _val.t; q = _val.p; t = _val.q; }
inline void ivec4::spqt(const simdint& _val) { s = _val; p = _val; q = _val; t = _val; }
inline void ivec4::spt(const simdint& _val0, const simdint& _val1, const simdint& _val2) { s = _val0; p = _val1; t = _val2; }
inline void ivec4::spt(const ivec3& _val) { s = _val.s; p = _val.t; t = _val.p; }
inline void ivec4::spt(const simdint& _val) { s = _val; p = _val; t = _val; }
inline void ivec4::sptq(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { s = _val0; p = _val1; t = _val2; q = _val3; }
inline void ivec4::sptq(const ivec4& _val) { s = _val.s; p = _val.t; t = _val.p; q = _val.q; }
inline void ivec4::sptq(const simdint& _val) { s = _val; p = _val; t = _val; q = _val; }
inline void ivec4::tq(const simdint& _val0, const simdint& _val1) { t = _val0; q = _val1; }
inline void ivec4::tq(const ivec2& _val) { t = _val.s; q = _val.t; }
inline void ivec4::tq(const simdint& _val) { t = _val; q = _val; }
inline void ivec4::tqs(const simdint& _val0, const simdint& _val1, const simdint& _val2) { t = _val0; q = _val1; s = _val2; }
inline void ivec4::tqs(const ivec3& _val) { t = _val.s; q = _val.t; s = _val.p; }
inline void ivec4::tqs(const simdint& _val) { t = _val; q = _val; s = _val; }
inline void ivec4::tqsp(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { t = _val0; q = _val1; s = _val2; p = _val3; }
inline void ivec4::tqsp(const ivec4& _val) { t = _val.s; q = _val.t; s = _val.p; p = _val.q; }
inline void ivec4::tqsp(const simdint& _val) { t = _val; q = _val; s = _val; p = _val; }
inline void ivec4::tqp(const simdint& _val0, const simdint& _val1, const simdint& _val2) { t = _val0; q = _val1; p = _val2; }
inline void ivec4::tqp(const ivec3& _val) { t = _val.s; q = _val.t; p = _val.p; }
inline void ivec4::tqp(const simdint& _val) { t = _val; q = _val; p = _val; }
inline void ivec4::tqps(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { t = _val0; q = _val1; p = _val2; s = _val3; }
inline void ivec4::tqps(const ivec4& _val) { t = _val.s; q = _val.t; p = _val.p; s = _val.q; }
inline void ivec4::tqps(const simdint& _val) { t = _val; q = _val; p = _val; s = _val; }
inline void ivec4::ts(const simdint& _val0, const simdint& _val1) { t = _val0; s = _val1; }
inline void ivec4::ts(const ivec2& _val) { t = _val.s; s = _val.t; }
inline void ivec4::ts(const simdint& _val) { t = _val; s = _val; }
inline void ivec4::tsq(const simdint& _val0, const simdint& _val1, const simdint& _val2) { t = _val0; s = _val1; q = _val2; }
inline void ivec4::tsq(const ivec3& _val) { t = _val.s; s = _val.t; q = _val.p; }
inline void ivec4::tsq(const simdint& _val) { t = _val; s = _val; q = _val; }
inline void ivec4::tsqp(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { t = _val0; s = _val1; q = _val2; p = _val3; }
inline void ivec4::tsqp(const ivec4& _val) { t = _val.s; s = _val.t; q = _val.p; p = _val.q; }
inline void ivec4::tsqp(const simdint& _val) { t = _val; s = _val; q = _val; p = _val; }
inline void ivec4::tsp(const simdint& _val0, const simdint& _val1, const simdint& _val2) { t = _val0; s = _val1; p = _val2; }
inline void ivec4::tsp(const ivec3& _val) { t = _val.s; s = _val.t; p = _val.p; }
inline void ivec4::tsp(const simdint& _val) { t = _val; s = _val; p = _val; }
inline void ivec4::tspq(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { t = _val0; s = _val1; p = _val2; q = _val3; }
inline void ivec4::tspq(const ivec4& _val) { t = _val.s; s = _val.t; p = _val.p; q = _val.q; }
inline void ivec4::tspq(const simdint& _val) { t = _val; s = _val; p = _val; q = _val; }
inline void ivec4::tp(const simdint& _val0, const simdint& _val1) { t = _val0; p = _val1; }
inline void ivec4::tp(const ivec2& _val) { t = _val.s; p = _val.t; }
inline void ivec4::tp(const simdint& _val) { t = _val; p = _val; }
inline void ivec4::tpq(const simdint& _val0, const simdint& _val1, const simdint& _val2) { t = _val0; p = _val1; q = _val2; }
inline void ivec4::tpq(const ivec3& _val) { t = _val.s; p = _val.t; q = _val.p; }
inline void ivec4::tpq(const simdint& _val) { t = _val; p = _val; q = _val; }
inline void ivec4::tpqs(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { t = _val0; p = _val1; q = _val2; s = _val3; }
inline void ivec4::tpqs(const ivec4& _val) { t = _val.s; p = _val.t; q = _val.p; s = _val.q; }
inline void ivec4::tpqs(const simdint& _val) { t = _val; p = _val; q = _val; s = _val; }
inline void ivec4::tps(const simdint& _val0, const simdint& _val1, const simdint& _val2) { t = _val0; p = _val1; s = _val2; }
inline void ivec4::tps(const ivec3& _val) { t = _val.s; p = _val.t; s = _val.p; }
inline void ivec4::tps(const simdint& _val) { t = _val; p = _val; s = _val; }
inline void ivec4::tpsq(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { t = _val0; p = _val1; s = _val2; q = _val3; }
inline void ivec4::tpsq(const ivec4& _val) { t = _val.s; p = _val.t; s = _val.p; q = _val.q; }
inline void ivec4::tpsq(const simdint& _val) { t = _val; p = _val; s = _val; q = _val; }
inline void ivec4::pq(const simdint& _val0, const simdint& _val1) { p = _val0; q = _val1; }
inline void ivec4::pq(const ivec2& _val) { p = _val.s; q = _val.t; }
inline void ivec4::pq(const simdint& _val) { p = _val; q = _val; }
inline void ivec4::pqs(const simdint& _val0, const simdint& _val1, const simdint& _val2) { p = _val0; q = _val1; s = _val2; }
inline void ivec4::pqs(const ivec3& _val) { p = _val.s; q = _val.t; s = _val.p; }
inline void ivec4::pqs(const simdint& _val) { p = _val; q = _val; s = _val; }
inline void ivec4::pqst(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { p = _val0; q = _val1; s = _val2; t = _val3; }
inline void ivec4::pqst(const ivec4& _val) { p = _val.s; q = _val.t; s = _val.p; t = _val.q; }
inline void ivec4::pqst(const simdint& _val) { p = _val; q = _val; s = _val; t = _val; }
inline void ivec4::pqt(const simdint& _val0, const simdint& _val1, const simdint& _val2) { p = _val0; q = _val1; t = _val2; }
inline void ivec4::pqt(const ivec3& _val) { p = _val.s; q = _val.t; t = _val.p; }
inline void ivec4::pqt(const simdint& _val) { p = _val; q = _val; t = _val; }
inline void ivec4::pqts(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { p = _val0; q = _val1; t = _val2; s = _val3; }
inline void ivec4::pqts(const ivec4& _val) { p = _val.s; q = _val.t; t = _val.p; s = _val.q; }
inline void ivec4::pqts(const simdint& _val) { p = _val; q = _val; t = _val; s = _val; }
inline void ivec4::ps(const simdint& _val0, const simdint& _val1) { p = _val0; s = _val1; }
inline void ivec4::ps(const ivec2& _val) { p = _val.s; s = _val.t; }
inline void ivec4::ps(const simdint& _val) { p = _val; s = _val; }
inline void ivec4::psq(const simdint& _val0, const simdint& _val1, const simdint& _val2) { p = _val0; s = _val1; q = _val2; }
inline void ivec4::psq(const ivec3& _val) { p = _val.s; s = _val.t; q = _val.p; }
inline void ivec4::psq(const simdint& _val) { p = _val; s = _val; q = _val; }
inline void ivec4::psqt(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { p = _val0; s = _val1; q = _val2; t = _val3; }
inline void ivec4::psqt(const ivec4& _val) { p = _val.s; s = _val.t; q = _val.p; t = _val.q; }
inline void ivec4::psqt(const simdint& _val) { p = _val; s = _val; q = _val; t = _val; }
inline void ivec4::pst(const simdint& _val0, const simdint& _val1, const simdint& _val2) { p = _val0; s = _val1; t = _val2; }
inline void ivec4::pst(const ivec3& _val) { p = _val.s; s = _val.t; t = _val.p; }
inline void ivec4::pst(const simdint& _val) { p = _val; s = _val; t = _val; }
inline void ivec4::pstq(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { p = _val0; s = _val1; t = _val2; q = _val3; }
inline void ivec4::pstq(const ivec4& _val) { p = _val.s; s = _val.t; t = _val.p; q = _val.q; }
inline void ivec4::pstq(const simdint& _val) { p = _val; s = _val; t = _val; q = _val; }
inline void ivec4::pt(const simdint& _val0, const simdint& _val1) { p = _val0; t = _val1; }
inline void ivec4::pt(const ivec2& _val) { p = _val.s; t = _val.t; }
inline void ivec4::pt(const simdint& _val) { p = _val; t = _val; }
inline void ivec4::ptq(const simdint& _val0, const simdint& _val1, const simdint& _val2) { p = _val0; t = _val1; q = _val2; }
inline void ivec4::ptq(const ivec3& _val) { p = _val.s; t = _val.t; q = _val.p; }
inline void ivec4::ptq(const simdint& _val) { p = _val; t = _val; q = _val; }
inline void ivec4::ptqs(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { p = _val0; t = _val1; q = _val2; s = _val3; }
inline void ivec4::ptqs(const ivec4& _val) { p = _val.s; t = _val.t; q = _val.p; s = _val.q; }
inline void ivec4::ptqs(const simdint& _val) { p = _val; t = _val; q = _val; s = _val; }
inline void ivec4::pts(const simdint& _val0, const simdint& _val1, const simdint& _val2) { p = _val0; t = _val1; s = _val2; }
inline void ivec4::pts(const ivec3& _val) { p = _val.s; t = _val.t; s = _val.p; }
inline void ivec4::pts(const simdint& _val) { p = _val; t = _val; s = _val; }
inline void ivec4::ptsq(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { p = _val0; t = _val1; s = _val2; q = _val3; }
inline void ivec4::ptsq(const ivec4& _val) { p = _val.s; t = _val.t; s = _val.p; q = _val.q; }
inline void ivec4::ptsq(const simdint& _val) { p = _val; t = _val; s = _val; q = _val; }
inline void ivec4::wx(const simdint& _val0, const simdint& _val1) { w = _val0; x = _val1; }
inline void ivec4::wx(const ivec2& _val) { w = _val.x; x = _val.y; }
inline void ivec4::wx(const simdint& _val) { w = _val; x = _val; }
inline void ivec4::wxy(const simdint& _val0, const simdint& _val1, const simdint& _val2) { w = _val0; x = _val1; y = _val2; }
inline void ivec4::wxy(const ivec3& _val) { w = _val.x; x = _val.y; y = _val.z; }
inline void ivec4::wxy(const simdint& _val) { w = _val; x = _val; y = _val; }
inline void ivec4::wxyz(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { w = _val0; x = _val1; y = _val2; z = _val3; }
inline void ivec4::wxyz(const ivec4& _val) { w = _val.x; x = _val.y; y = _val.z; z = _val.w; }
inline void ivec4::wxyz(const simdint& _val) { w = _val; x = _val; y = _val; z = _val; }
inline void ivec4::wxz(const simdint& _val0, const simdint& _val1, const simdint& _val2) { w = _val0; x = _val1; z = _val2; }
inline void ivec4::wxz(const ivec3& _val) { w = _val.x; x = _val.y; z = _val.z; }
inline void ivec4::wxz(const simdint& _val) { w = _val; x = _val; z = _val; }
inline void ivec4::wxzy(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { w = _val0; x = _val1; z = _val2; y = _val3; }
inline void ivec4::wxzy(const ivec4& _val) { w = _val.x; x = _val.y; z = _val.z; y = _val.w; }
inline void ivec4::wxzy(const simdint& _val) { w = _val; x = _val; z = _val; y = _val; }
inline void ivec4::wy(const simdint& _val0, const simdint& _val1) { w = _val0; y = _val1; }
inline void ivec4::wy(const ivec2& _val) { w = _val.x; y = _val.y; }
inline void ivec4::wy(const simdint& _val) { w = _val; y = _val; }
inline void ivec4::wyx(const simdint& _val0, const simdint& _val1, const simdint& _val2) { w = _val0; y = _val1; x = _val2; }
inline void ivec4::wyx(const ivec3& _val) { w = _val.x; y = _val.y; x = _val.z; }
inline void ivec4::wyx(const simdint& _val) { w = _val; y = _val; x = _val; }
inline void ivec4::wyxz(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { w = _val0; y = _val1; x = _val2; z = _val3; }
inline void ivec4::wyxz(const ivec4& _val) { w = _val.x; y = _val.y; x = _val.z; z = _val.w; }
inline void ivec4::wyxz(const simdint& _val) { w = _val; y = _val; x = _val; z = _val; }
inline void ivec4::wyz(const simdint& _val0, const simdint& _val1, const simdint& _val2) { w = _val0; y = _val1; z = _val2; }
inline void ivec4::wyz(const ivec3& _val) { w = _val.x; y = _val.y; z = _val.z; }
inline void ivec4::wyz(const simdint& _val) { w = _val; y = _val; z = _val; }
inline void ivec4::wyzx(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { w = _val0; y = _val1; z = _val2; x = _val3; }
inline void ivec4::wyzx(const ivec4& _val) { w = _val.x; y = _val.y; z = _val.z; x = _val.w; }
inline void ivec4::wyzx(const simdint& _val) { w = _val; y = _val; z = _val; x = _val; }
inline void ivec4::wz(const simdint& _val0, const simdint& _val1) { w = _val0; z = _val1; }
inline void ivec4::wz(const ivec2& _val) { w = _val.x; z = _val.y; }
inline void ivec4::wz(const simdint& _val) { w = _val; z = _val; }
inline void ivec4::wzx(const simdint& _val0, const simdint& _val1, const simdint& _val2) { w = _val0; z = _val1; x = _val2; }
inline void ivec4::wzx(const ivec3& _val) { w = _val.x; z = _val.y; x = _val.z; }
inline void ivec4::wzx(const simdint& _val) { w = _val; z = _val; x = _val; }
inline void ivec4::wzxy(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { w = _val0; z = _val1; x = _val2; y = _val3; }
inline void ivec4::wzxy(const ivec4& _val) { w = _val.x; z = _val.y; x = _val.z; y = _val.w; }
inline void ivec4::wzxy(const simdint& _val) { w = _val; z = _val; x = _val; y = _val; }
inline void ivec4::wzy(const simdint& _val0, const simdint& _val1, const simdint& _val2) { w = _val0; z = _val1; y = _val2; }
inline void ivec4::wzy(const ivec3& _val) { w = _val.x; z = _val.y; y = _val.z; }
inline void ivec4::wzy(const simdint& _val) { w = _val; z = _val; y = _val; }
inline void ivec4::wzyx(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { w = _val0; z = _val1; y = _val2; x = _val3; }
inline void ivec4::wzyx(const ivec4& _val) { w = _val.x; z = _val.y; y = _val.z; x = _val.w; }
inline void ivec4::wzyx(const simdint& _val) { w = _val; z = _val; y = _val; x = _val; }
inline void ivec4::xw(const simdint& _val0, const simdint& _val1) { x = _val0; w = _val1; }
inline void ivec4::xw(const ivec2& _val) { x = _val.x; w = _val.y; }
inline void ivec4::xw(const simdint& _val) { x = _val; w = _val; }
inline void ivec4::xwy(const simdint& _val0, const simdint& _val1, const simdint& _val2) { x = _val0; w = _val1; y = _val2; }
inline void ivec4::xwy(const ivec3& _val) { x = _val.x; w = _val.y; y = _val.z; }
inline void ivec4::xwy(const simdint& _val) { x = _val; w = _val; y = _val; }
inline void ivec4::xwyz(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { x = _val0; w = _val1; y = _val2; z = _val3; }
inline void ivec4::xwyz(const ivec4& _val) { x = _val.x; w = _val.y; y = _val.z; z = _val.w; }
inline void ivec4::xwyz(const simdint& _val) { x = _val; w = _val; y = _val; z = _val; }
inline void ivec4::xwz(const simdint& _val0, const simdint& _val1, const simdint& _val2) { x = _val0; w = _val1; z = _val2; }
inline void ivec4::xwz(const ivec3& _val) { x = _val.x; w = _val.y; z = _val.z; }
inline void ivec4::xwz(const simdint& _val) { x = _val; w = _val; z = _val; }
inline void ivec4::xwzy(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { x = _val0; w = _val1; z = _val2; y = _val3; }
inline void ivec4::xwzy(const ivec4& _val) { x = _val.x; w = _val.y; z = _val.z; y = _val.w; }
inline void ivec4::xwzy(const simdint& _val) { x = _val; w = _val; z = _val; y = _val; }
inline void ivec4::xy(const simdint& _val0, const simdint& _val1) { x = _val0; y = _val1; }
inline void ivec4::xy(const ivec2& _val) { x = _val.x; y = _val.y; }
inline void ivec4::xy(const simdint& _val) { x = _val; y = _val; }
inline void ivec4::xyw(const simdint& _val0, const simdint& _val1, const simdint& _val2) { x = _val0; y = _val1; w = _val2; }
inline void ivec4::xyw(const ivec3& _val) { x = _val.x; y = _val.y; w = _val.z; }
inline void ivec4::xyw(const simdint& _val) { x = _val; y = _val; w = _val; }
inline void ivec4::xywz(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { x = _val0; y = _val1; w = _val2; z = _val3; }
inline void ivec4::xywz(const ivec4& _val) { x = _val.x; y = _val.y; w = _val.z; z = _val.w; }
inline void ivec4::xywz(const simdint& _val) { x = _val; y = _val; w = _val; z = _val; }
inline void ivec4::xyz(const simdint& _val0, const simdint& _val1, const simdint& _val2) { x = _val0; y = _val1; z = _val2; }
inline void ivec4::xyz(const ivec3& _val) { x = _val.x; y = _val.y; z = _val.z; }
inline void ivec4::xyz(const simdint& _val) { x = _val; y = _val; z = _val; }
inline void ivec4::xyzw(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { x = _val0; y = _val1; z = _val2; w = _val3; }
inline void ivec4::xyzw(const ivec4& _val) { x = _val.x; y = _val.y; z = _val.z; w = _val.w; }
inline void ivec4::xyzw(const simdint& _val) { x = _val; y = _val; z = _val; w = _val; }
inline void ivec4::xz(const simdint& _val0, const simdint& _val1) { x = _val0; z = _val1; }
inline void ivec4::xz(const ivec2& _val) { x = _val.x; z = _val.y; }
inline void ivec4::xz(const simdint& _val) { x = _val; z = _val; }
inline void ivec4::xzw(const simdint& _val0, const simdint& _val1, const simdint& _val2) { x = _val0; z = _val1; w = _val2; }
inline void ivec4::xzw(const ivec3& _val) { x = _val.x; z = _val.y; w = _val.z; }
inline void ivec4::xzw(const simdint& _val) { x = _val; z = _val; w = _val; }
inline void ivec4::xzwy(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { x = _val0; z = _val1; w = _val2; y = _val3; }
inline void ivec4::xzwy(const ivec4& _val) { x = _val.x; z = _val.y; w = _val.z; y = _val.w; }
inline void ivec4::xzwy(const simdint& _val) { x = _val; z = _val; w = _val; y = _val; }
inline void ivec4::xzy(const simdint& _val0, const simdint& _val1, const simdint& _val2) { x = _val0; z = _val1; y = _val2; }
inline void ivec4::xzy(const ivec3& _val) { x = _val.x; z = _val.y; y = _val.z; }
inline void ivec4::xzy(const simdint& _val) { x = _val; z = _val; y = _val; }
inline void ivec4::xzyw(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { x = _val0; z = _val1; y = _val2; w = _val3; }
inline void ivec4::xzyw(const ivec4& _val) { x = _val.x; z = _val.y; y = _val.z; w = _val.w; }
inline void ivec4::xzyw(const simdint& _val) { x = _val; z = _val; y = _val; w = _val; }
inline void ivec4::yw(const simdint& _val0, const simdint& _val1) { y = _val0; w = _val1; }
inline void ivec4::yw(const ivec2& _val) { y = _val.x; w = _val.y; }
inline void ivec4::yw(const simdint& _val) { y = _val; w = _val; }
inline void ivec4::ywx(const simdint& _val0, const simdint& _val1, const simdint& _val2) { y = _val0; w = _val1; x = _val2; }
inline void ivec4::ywx(const ivec3& _val) { y = _val.x; w = _val.y; x = _val.z; }
inline void ivec4::ywx(const simdint& _val) { y = _val; w = _val; x = _val; }
inline void ivec4::ywxz(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { y = _val0; w = _val1; x = _val2; z = _val3; }
inline void ivec4::ywxz(const ivec4& _val) { y = _val.x; w = _val.y; x = _val.z; z = _val.w; }
inline void ivec4::ywxz(const simdint& _val) { y = _val; w = _val; x = _val; z = _val; }
inline void ivec4::ywz(const simdint& _val0, const simdint& _val1, const simdint& _val2) { y = _val0; w = _val1; z = _val2; }
inline void ivec4::ywz(const ivec3& _val) { y = _val.x; w = _val.y; z = _val.z; }
inline void ivec4::ywz(const simdint& _val) { y = _val; w = _val; z = _val; }
inline void ivec4::ywzx(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { y = _val0; w = _val1; z = _val2; x = _val3; }
inline void ivec4::ywzx(const ivec4& _val) { y = _val.x; w = _val.y; z = _val.z; x = _val.w; }
inline void ivec4::ywzx(const simdint& _val) { y = _val; w = _val; z = _val; x = _val; }
inline void ivec4::yx(const simdint& _val0, const simdint& _val1) { y = _val0; x = _val1; }
inline void ivec4::yx(const ivec2& _val) { y = _val.x; x = _val.y; }
inline void ivec4::yx(const simdint& _val) { y = _val; x = _val; }
inline void ivec4::yxw(const simdint& _val0, const simdint& _val1, const simdint& _val2) { y = _val0; x = _val1; w = _val2; }
inline void ivec4::yxw(const ivec3& _val) { y = _val.x; x = _val.y; w = _val.z; }
inline void ivec4::yxw(const simdint& _val) { y = _val; x = _val; w = _val; }
inline void ivec4::yxwz(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { y = _val0; x = _val1; w = _val2; z = _val3; }
inline void ivec4::yxwz(const ivec4& _val) { y = _val.x; x = _val.y; w = _val.z; z = _val.w; }
inline void ivec4::yxwz(const simdint& _val) { y = _val; x = _val; w = _val; z = _val; }
inline void ivec4::yxz(const simdint& _val0, const simdint& _val1, const simdint& _val2) { y = _val0; x = _val1; z = _val2; }
inline void ivec4::yxz(const ivec3& _val) { y = _val.x; x = _val.y; z = _val.z; }
inline void ivec4::yxz(const simdint& _val) { y = _val; x = _val; z = _val; }
inline void ivec4::yxzw(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { y = _val0; x = _val1; z = _val2; w = _val3; }
inline void ivec4::yxzw(const ivec4& _val) { y = _val.x; x = _val.y; z = _val.z; w = _val.w; }
inline void ivec4::yxzw(const simdint& _val) { y = _val; x = _val; z = _val; w = _val; }
inline void ivec4::yz(const simdint& _val0, const simdint& _val1) { y = _val0; z = _val1; }
inline void ivec4::yz(const ivec2& _val) { y = _val.x; z = _val.y; }
inline void ivec4::yz(const simdint& _val) { y = _val; z = _val; }
inline void ivec4::yzw(const simdint& _val0, const simdint& _val1, const simdint& _val2) { y = _val0; z = _val1; w = _val2; }
inline void ivec4::yzw(const ivec3& _val) { y = _val.x; z = _val.y; w = _val.z; }
inline void ivec4::yzw(const simdint& _val) { y = _val; z = _val; w = _val; }
inline void ivec4::yzwx(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { y = _val0; z = _val1; w = _val2; x = _val3; }
inline void ivec4::yzwx(const ivec4& _val) { y = _val.x; z = _val.y; w = _val.z; x = _val.w; }
inline void ivec4::yzwx(const simdint& _val) { y = _val; z = _val; w = _val; x = _val; }
inline void ivec4::yzx(const simdint& _val0, const simdint& _val1, const simdint& _val2) { y = _val0; z = _val1; x = _val2; }
inline void ivec4::yzx(const ivec3& _val) { y = _val.x; z = _val.y; x = _val.z; }
inline void ivec4::yzx(const simdint& _val) { y = _val; z = _val; x = _val; }
inline void ivec4::yzxw(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { y = _val0; z = _val1; x = _val2; w = _val3; }
inline void ivec4::yzxw(const ivec4& _val) { y = _val.x; z = _val.y; x = _val.z; w = _val.w; }
inline void ivec4::yzxw(const simdint& _val) { y = _val; z = _val; x = _val; w = _val; }
inline void ivec4::zw(const simdint& _val0, const simdint& _val1) { z = _val0; w = _val1; }
inline void ivec4::zw(const ivec2& _val) { z = _val.x; w = _val.y; }
inline void ivec4::zw(const simdint& _val) { z = _val; w = _val; }
inline void ivec4::zwx(const simdint& _val0, const simdint& _val1, const simdint& _val2) { z = _val0; w = _val1; x = _val2; }
inline void ivec4::zwx(const ivec3& _val) { z = _val.x; w = _val.y; x = _val.z; }
inline void ivec4::zwx(const simdint& _val) { z = _val; w = _val; x = _val; }
inline void ivec4::zwxy(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { z = _val0; w = _val1; x = _val2; y = _val3; }
inline void ivec4::zwxy(const ivec4& _val) { z = _val.x; w = _val.y; x = _val.z; y = _val.w; }
inline void ivec4::zwxy(const simdint& _val) { z = _val; w = _val; x = _val; y = _val; }
inline void ivec4::zwy(const simdint& _val0, const simdint& _val1, const simdint& _val2) { z = _val0; w = _val1; y = _val2; }
inline void ivec4::zwy(const ivec3& _val) { z = _val.x; w = _val.y; y = _val.z; }
inline void ivec4::zwy(const simdint& _val) { z = _val; w = _val; y = _val; }
inline void ivec4::zwyx(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { z = _val0; w = _val1; y = _val2; x = _val3; }
inline void ivec4::zwyx(const ivec4& _val) { z = _val.x; w = _val.y; y = _val.z; x = _val.w; }
inline void ivec4::zwyx(const simdint& _val) { z = _val; w = _val; y = _val; x = _val; }
inline void ivec4::zx(const simdint& _val0, const simdint& _val1) { z = _val0; x = _val1; }
inline void ivec4::zx(const ivec2& _val) { z = _val.x; x = _val.y; }
inline void ivec4::zx(const simdint& _val) { z = _val; x = _val; }
inline void ivec4::zxw(const simdint& _val0, const simdint& _val1, const simdint& _val2) { z = _val0; x = _val1; w = _val2; }
inline void ivec4::zxw(const ivec3& _val) { z = _val.x; x = _val.y; w = _val.z; }
inline void ivec4::zxw(const simdint& _val) { z = _val; x = _val; w = _val; }
inline void ivec4::zxwy(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { z = _val0; x = _val1; w = _val2; y = _val3; }
inline void ivec4::zxwy(const ivec4& _val) { z = _val.x; x = _val.y; w = _val.z; y = _val.w; }
inline void ivec4::zxwy(const simdint& _val) { z = _val; x = _val; w = _val; y = _val; }
inline void ivec4::zxy(const simdint& _val0, const simdint& _val1, const simdint& _val2) { z = _val0; x = _val1; y = _val2; }
inline void ivec4::zxy(const ivec3& _val) { z = _val.x; x = _val.y; y = _val.z; }
inline void ivec4::zxy(const simdint& _val) { z = _val; x = _val; y = _val; }
inline void ivec4::zxyw(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { z = _val0; x = _val1; y = _val2; w = _val3; }
inline void ivec4::zxyw(const ivec4& _val) { z = _val.x; x = _val.y; y = _val.z; w = _val.w; }
inline void ivec4::zxyw(const simdint& _val) { z = _val; x = _val; y = _val; w = _val; }
inline void ivec4::zy(const simdint& _val0, const simdint& _val1) { z = _val0; y = _val1; }
inline void ivec4::zy(const ivec2& _val) { z = _val.x; y = _val.y; }
inline void ivec4::zy(const simdint& _val) { z = _val; y = _val; }
inline void ivec4::zyw(const simdint& _val0, const simdint& _val1, const simdint& _val2) { z = _val0; y = _val1; w = _val2; }
inline void ivec4::zyw(const ivec3& _val) { z = _val.x; y = _val.y; w = _val.z; }
inline void ivec4::zyw(const simdint& _val) { z = _val; y = _val; w = _val; }
inline void ivec4::zywx(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { z = _val0; y = _val1; w = _val2; x = _val3; }
inline void ivec4::zywx(const ivec4& _val) { z = _val.x; y = _val.y; w = _val.z; x = _val.w; }
inline void ivec4::zywx(const simdint& _val) { z = _val; y = _val; w = _val; x = _val; }
inline void ivec4::zyx(const simdint& _val0, const simdint& _val1, const simdint& _val2) { z = _val0; y = _val1; x = _val2; }
inline void ivec4::zyx(const ivec3& _val) { z = _val.x; y = _val.y; x = _val.z; }
inline void ivec4::zyx(const simdint& _val) { z = _val; y = _val; x = _val; }
inline void ivec4::zyxw(const simdint& _val0, const simdint& _val1, const simdint& _val2, const simdint& _val3) { z = _val0; y = _val1; x = _val2; w = _val3; }
inline void ivec4::zyxw(const ivec4& _val) { z = _val.x; y = _val.y; x = _val.z; w = _val.w; }
inline void ivec4::zyxw(const simdint& _val) { z = _val; y = _val; x = _val; w = _val; }

#pragma endregion

// cross-type assignment from vec4 (components use simdint's own conversion operator)
inline ivec4 ivec4::operator=(const vec4& _v) { x = _v.x; y = _v.y; z = _v.z; w = _v.w; return *this; }

// constructors for ivec4
inline ivec4::ivec4(const int32_t& _f) { x = _f; y = _f; z = _f; w = _f; }

inline ivec4::ivec4(const simdint& _f) { x = _f; y = _f; z = _f; w = _f; }

inline ivec4::ivec4(const vec4& _v) { x = _v.x; y = _v.y; z = _v.z; w = _v.w; }

inline ivec4::ivec4(const simdint& _x, const simdint& _y, const simdint& _z, const simdint& _w) { x = _x; y = _y; z = _z; w = _w; }

inline ivec4::ivec4(const simdint& _x, const ivec2& _y, const simdint& _w) { x = _x; y = _y.x; z = _y.y; w = _w; }

inline ivec4::ivec4(const simdint& _x, const simdint& _y, const ivec2& _z) { x = _x; y = _y; z = _z.x; w = _z.y; }

inline ivec4::ivec4(const ivec2& _x, const simdint& _z, const simdint& _w) { x = _x.x; y = _x.y; z = _z; w = _w; }

inline ivec4::ivec4(const ivec3& _x, const simdint& _w) { x = _x.x; y = _x.y; z = _x.z; w = _w; }

inline ivec4::ivec4(const simdint& _x, const ivec3& _y) { x = _x; y = _y.x; z = _y.y; w = _y.z; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec4>, int>>
ivec4::ivec4(const simdint& _x, const V& _v) { x = _x; y = _v.x; z = _v.y; w = _v.z; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec3>, int>>
ivec4::ivec4(const simdint& _x, const simdint& _y, const V& _v) { x = _x; y = _y; z = _v.x; w = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec4>, int>>
ivec4::ivec4(const simdint& _x, const simdint& _y, const V& _v) { x = _x; y = _y; z = _v.x; w = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec2>, int>>
ivec4::ivec4(const simdint& _x, const simdint& _y, const simdint& _z, const V& _v) { x = _x; y = _y; z = _z; w = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec3>, int>>
ivec4::ivec4(const simdint& _x, const simdint& _y, const simdint& _z, const V& _v) { x = _x; y = _y; z = _z; w = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, ivec4>, int>>
ivec4::ivec4(const simdint& _x, const simdint& _y, const simdint& _z, const V& _v) { x = _x; y = _y; z = _z; w = _v.x; }

#endif



