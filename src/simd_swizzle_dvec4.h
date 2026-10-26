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
 
#ifndef SIMD_SWIZZLE_DVEC4_H
#define SIMD_SWIZZLE_DVEC4_H

#include "simd_dvec2.h"
#include "simd_dvec3.h"
#include "simd_dvec4.h"

#pragma region dvec4 swizzle implementations

// dvec4 swizzle implementations
inline dvec2 dvec4::aa() const { return { a, a }; }
inline dvec3 dvec4::aaa() const { return { a, a, a }; }
inline dvec4 dvec4::aaaa() const { return { a, a, a, a }; }
inline dvec4 dvec4::aaab() const { return { a, a, a, b }; }
inline dvec4 dvec4::aaag() const { return { a, a, a, g }; }
inline dvec4 dvec4::aaar() const { return { a, a, a, r }; }
inline dvec3 dvec4::aab() const { return { a, a, b }; }
inline dvec4 dvec4::aaba() const { return { a, a, b, a }; }
inline dvec4 dvec4::aabb() const { return { a, a, b, b }; }
inline dvec4 dvec4::aabg() const { return { a, a, b, g }; }
inline dvec4 dvec4::aabr() const { return { a, a, b, r }; }
inline dvec3 dvec4::aag() const { return { a, a, g }; }
inline dvec4 dvec4::aaga() const { return { a, a, g, a }; }
inline dvec4 dvec4::aagb() const { return { a, a, g, b }; }
inline dvec4 dvec4::aagg() const { return { a, a, g, g }; }
inline dvec4 dvec4::aagr() const { return { a, a, g, r }; }
inline dvec3 dvec4::aar() const { return { a, a, r }; }
inline dvec4 dvec4::aara() const { return { a, a, r, a }; }
inline dvec4 dvec4::aarb() const { return { a, a, r, b }; }
inline dvec4 dvec4::aarg() const { return { a, a, r, g }; }
inline dvec4 dvec4::aarr() const { return { a, a, r, r }; }
inline dvec2 dvec4::ab() const { return { a, b }; }
inline dvec3 dvec4::aba() const { return { a, b, a }; }
inline dvec4 dvec4::abaa() const { return { a, b, a, a }; }
inline dvec4 dvec4::abab() const { return { a, b, a, b }; }
inline dvec4 dvec4::abag() const { return { a, b, a, g }; }
inline dvec4 dvec4::abar() const { return { a, b, a, r }; }
inline dvec3 dvec4::abb() const { return { a, b, b }; }
inline dvec4 dvec4::abba() const { return { a, b, b, a }; }
inline dvec4 dvec4::abbb() const { return { a, b, b, b }; }
inline dvec4 dvec4::abbg() const { return { a, b, b, g }; }
inline dvec4 dvec4::abbr() const { return { a, b, b, r }; }
inline dvec3 dvec4::abg() const { return { a, b, g }; }
inline dvec4 dvec4::abga() const { return { a, b, g, a }; }
inline dvec4 dvec4::abgb() const { return { a, b, g, b }; }
inline dvec4 dvec4::abgg() const { return { a, b, g, g }; }
inline dvec4 dvec4::abgr() const { return { a, b, g, r }; }
inline dvec3 dvec4::abr() const { return { a, b, r }; }
inline dvec4 dvec4::abra() const { return { a, b, r, a }; }
inline dvec4 dvec4::abrb() const { return { a, b, r, b }; }
inline dvec4 dvec4::abrg() const { return { a, b, r, g }; }
inline dvec4 dvec4::abrr() const { return { a, b, r, r }; }
inline dvec2 dvec4::ag() const { return { a, g }; }
inline dvec3 dvec4::aga() const { return { a, g, a }; }
inline dvec4 dvec4::agaa() const { return { a, g, a, a }; }
inline dvec4 dvec4::agab() const { return { a, g, a, b }; }
inline dvec4 dvec4::agag() const { return { a, g, a, g }; }
inline dvec4 dvec4::agar() const { return { a, g, a, r }; }
inline dvec3 dvec4::agb() const { return { a, g, b }; }
inline dvec4 dvec4::agba() const { return { a, g, b, a }; }
inline dvec4 dvec4::agbb() const { return { a, g, b, b }; }
inline dvec4 dvec4::agbg() const { return { a, g, b, g }; }
inline dvec4 dvec4::agbr() const { return { a, g, b, r }; }
inline dvec3 dvec4::agg() const { return { a, g, g }; }
inline dvec4 dvec4::agga() const { return { a, g, g, a }; }
inline dvec4 dvec4::aggb() const { return { a, g, g, b }; }
inline dvec4 dvec4::aggg() const { return { a, g, g, g }; }
inline dvec4 dvec4::aggr() const { return { a, g, g, r }; }
inline dvec3 dvec4::agr() const { return { a, g, r }; }
inline dvec4 dvec4::agra() const { return { a, g, r, a }; }
inline dvec4 dvec4::agrb() const { return { a, g, r, b }; }
inline dvec4 dvec4::agrg() const { return { a, g, r, g }; }
inline dvec4 dvec4::agrr() const { return { a, g, r, r }; }
inline dvec2 dvec4::ar() const { return { a, r }; }
inline dvec3 dvec4::ara() const { return { a, r, a }; }
inline dvec4 dvec4::araa() const { return { a, r, a, a }; }
inline dvec4 dvec4::arab() const { return { a, r, a, b }; }
inline dvec4 dvec4::arag() const { return { a, r, a, g }; }
inline dvec4 dvec4::arar() const { return { a, r, a, r }; }
inline dvec3 dvec4::arb() const { return { a, r, b }; }
inline dvec4 dvec4::arba() const { return { a, r, b, a }; }
inline dvec4 dvec4::arbb() const { return { a, r, b, b }; }
inline dvec4 dvec4::arbg() const { return { a, r, b, g }; }
inline dvec4 dvec4::arbr() const { return { a, r, b, r }; }
inline dvec3 dvec4::arg() const { return { a, r, g }; }
inline dvec4 dvec4::arga() const { return { a, r, g, a }; }
inline dvec4 dvec4::argb() const { return { a, r, g, b }; }
inline dvec4 dvec4::argg() const { return { a, r, g, g }; }
inline dvec4 dvec4::argr() const { return { a, r, g, r }; }
inline dvec3 dvec4::arr() const { return { a, r, r }; }
inline dvec4 dvec4::arra() const { return { a, r, r, a }; }
inline dvec4 dvec4::arrb() const { return { a, r, r, b }; }
inline dvec4 dvec4::arrg() const { return { a, r, r, g }; }
inline dvec4 dvec4::arrr() const { return { a, r, r, r }; }
inline dvec2 dvec4::ba() const { return { b, a }; }
inline dvec3 dvec4::baa() const { return { b, a, a }; }
inline dvec4 dvec4::baaa() const { return { b, a, a, a }; }
inline dvec4 dvec4::baab() const { return { b, a, a, b }; }
inline dvec4 dvec4::baag() const { return { b, a, a, g }; }
inline dvec4 dvec4::baar() const { return { b, a, a, r }; }
inline dvec3 dvec4::bab() const { return { b, a, b }; }
inline dvec4 dvec4::baba() const { return { b, a, b, a }; }
inline dvec4 dvec4::babb() const { return { b, a, b, b }; }
inline dvec4 dvec4::babg() const { return { b, a, b, g }; }
inline dvec4 dvec4::babr() const { return { b, a, b, r }; }
inline dvec3 dvec4::bag() const { return { b, a, g }; }
inline dvec4 dvec4::baga() const { return { b, a, g, a }; }
inline dvec4 dvec4::bagb() const { return { b, a, g, b }; }
inline dvec4 dvec4::bagg() const { return { b, a, g, g }; }
inline dvec4 dvec4::bagr() const { return { b, a, g, r }; }
inline dvec3 dvec4::bar() const { return { b, a, r }; }
inline dvec4 dvec4::bara() const { return { b, a, r, a }; }
inline dvec4 dvec4::barb() const { return { b, a, r, b }; }
inline dvec4 dvec4::barg() const { return { b, a, r, g }; }
inline dvec4 dvec4::barr() const { return { b, a, r, r }; }
inline dvec2 dvec4::bb() const { return { b, b }; }
inline dvec3 dvec4::bba() const { return { b, b, a }; }
inline dvec4 dvec4::bbaa() const { return { b, b, a, a }; }
inline dvec4 dvec4::bbab() const { return { b, b, a, b }; }
inline dvec4 dvec4::bbag() const { return { b, b, a, g }; }
inline dvec4 dvec4::bbar() const { return { b, b, a, r }; }
inline dvec3 dvec4::bbb() const { return { b, b, b }; }
inline dvec4 dvec4::bbba() const { return { b, b, b, a }; }
inline dvec4 dvec4::bbbb() const { return { b, b, b, b }; }
inline dvec4 dvec4::bbbg() const { return { b, b, b, g }; }
inline dvec4 dvec4::bbbr() const { return { b, b, b, r }; }
inline dvec3 dvec4::bbg() const { return { b, b, g }; }
inline dvec4 dvec4::bbga() const { return { b, b, g, a }; }
inline dvec4 dvec4::bbgb() const { return { b, b, g, b }; }
inline dvec4 dvec4::bbgg() const { return { b, b, g, g }; }
inline dvec4 dvec4::bbgr() const { return { b, b, g, r }; }
inline dvec3 dvec4::bbr() const { return { b, b, r }; }
inline dvec4 dvec4::bbra() const { return { b, b, r, a }; }
inline dvec4 dvec4::bbrb() const { return { b, b, r, b }; }
inline dvec4 dvec4::bbrg() const { return { b, b, r, g }; }
inline dvec4 dvec4::bbrr() const { return { b, b, r, r }; }
inline dvec2 dvec4::bg() const { return { b, g }; }
inline dvec3 dvec4::bga() const { return { b, g, a }; }
inline dvec4 dvec4::bgaa() const { return { b, g, a, a }; }
inline dvec4 dvec4::bgab() const { return { b, g, a, b }; }
inline dvec4 dvec4::bgag() const { return { b, g, a, g }; }
inline dvec4 dvec4::bgar() const { return { b, g, a, r }; }
inline dvec3 dvec4::bgb() const { return { b, g, b }; }
inline dvec4 dvec4::bgba() const { return { b, g, b, a }; }
inline dvec4 dvec4::bgbb() const { return { b, g, b, b }; }
inline dvec4 dvec4::bgbg() const { return { b, g, b, g }; }
inline dvec4 dvec4::bgbr() const { return { b, g, b, r }; }
inline dvec3 dvec4::bgg() const { return { b, g, g }; }
inline dvec4 dvec4::bgga() const { return { b, g, g, a }; }
inline dvec4 dvec4::bggb() const { return { b, g, g, b }; }
inline dvec4 dvec4::bggg() const { return { b, g, g, g }; }
inline dvec4 dvec4::bggr() const { return { b, g, g, r }; }
inline dvec3 dvec4::bgr() const { return { b, g, r }; }
inline dvec4 dvec4::bgra() const { return { b, g, r, a }; }
inline dvec4 dvec4::bgrb() const { return { b, g, r, b }; }
inline dvec4 dvec4::bgrg() const { return { b, g, r, g }; }
inline dvec4 dvec4::bgrr() const { return { b, g, r, r }; }
inline dvec2 dvec4::br() const { return { b, r }; }
inline dvec3 dvec4::bra() const { return { b, r, a }; }
inline dvec4 dvec4::braa() const { return { b, r, a, a }; }
inline dvec4 dvec4::brab() const { return { b, r, a, b }; }
inline dvec4 dvec4::brag() const { return { b, r, a, g }; }
inline dvec4 dvec4::brar() const { return { b, r, a, r }; }
inline dvec3 dvec4::brb() const { return { b, r, b }; }
inline dvec4 dvec4::brba() const { return { b, r, b, a }; }
inline dvec4 dvec4::brbb() const { return { b, r, b, b }; }
inline dvec4 dvec4::brbg() const { return { b, r, b, g }; }
inline dvec4 dvec4::brbr() const { return { b, r, b, r }; }
inline dvec3 dvec4::brg() const { return { b, r, g }; }
inline dvec4 dvec4::brga() const { return { b, r, g, a }; }
inline dvec4 dvec4::brgb() const { return { b, r, g, b }; }
inline dvec4 dvec4::brgg() const { return { b, r, g, g }; }
inline dvec4 dvec4::brgr() const { return { b, r, g, r }; }
inline dvec3 dvec4::brr() const { return { b, r, r }; }
inline dvec4 dvec4::brra() const { return { b, r, r, a }; }
inline dvec4 dvec4::brrb() const { return { b, r, r, b }; }
inline dvec4 dvec4::brrg() const { return { b, r, r, g }; }
inline dvec4 dvec4::brrr() const { return { b, r, r, r }; }
inline dvec2 dvec4::ga() const { return { g, a }; }
inline dvec3 dvec4::gaa() const { return { g, a, a }; }
inline dvec4 dvec4::gaaa() const { return { g, a, a, a }; }
inline dvec4 dvec4::gaab() const { return { g, a, a, b }; }
inline dvec4 dvec4::gaag() const { return { g, a, a, g }; }
inline dvec4 dvec4::gaar() const { return { g, a, a, r }; }
inline dvec3 dvec4::gab() const { return { g, a, b }; }
inline dvec4 dvec4::gaba() const { return { g, a, b, a }; }
inline dvec4 dvec4::gabb() const { return { g, a, b, b }; }
inline dvec4 dvec4::gabg() const { return { g, a, b, g }; }
inline dvec4 dvec4::gabr() const { return { g, a, b, r }; }
inline dvec3 dvec4::gag() const { return { g, a, g }; }
inline dvec4 dvec4::gaga() const { return { g, a, g, a }; }
inline dvec4 dvec4::gagb() const { return { g, a, g, b }; }
inline dvec4 dvec4::gagg() const { return { g, a, g, g }; }
inline dvec4 dvec4::gagr() const { return { g, a, g, r }; }
inline dvec3 dvec4::gar() const { return { g, a, r }; }
inline dvec4 dvec4::gara() const { return { g, a, r, a }; }
inline dvec4 dvec4::garb() const { return { g, a, r, b }; }
inline dvec4 dvec4::garg() const { return { g, a, r, g }; }
inline dvec4 dvec4::garr() const { return { g, a, r, r }; }
inline dvec2 dvec4::gb() const { return { g, b }; }
inline dvec3 dvec4::gba() const { return { g, b, a }; }
inline dvec4 dvec4::gbaa() const { return { g, b, a, a }; }
inline dvec4 dvec4::gbab() const { return { g, b, a, b }; }
inline dvec4 dvec4::gbag() const { return { g, b, a, g }; }
inline dvec4 dvec4::gbar() const { return { g, b, a, r }; }
inline dvec3 dvec4::gbb() const { return { g, b, b }; }
inline dvec4 dvec4::gbba() const { return { g, b, b, a }; }
inline dvec4 dvec4::gbbb() const { return { g, b, b, b }; }
inline dvec4 dvec4::gbbg() const { return { g, b, b, g }; }
inline dvec4 dvec4::gbbr() const { return { g, b, b, r }; }
inline dvec3 dvec4::gbg() const { return { g, b, g }; }
inline dvec4 dvec4::gbga() const { return { g, b, g, a }; }
inline dvec4 dvec4::gbgb() const { return { g, b, g, b }; }
inline dvec4 dvec4::gbgg() const { return { g, b, g, g }; }
inline dvec4 dvec4::gbgr() const { return { g, b, g, r }; }
inline dvec3 dvec4::gbr() const { return { g, b, r }; }
inline dvec4 dvec4::gbra() const { return { g, b, r, a }; }
inline dvec4 dvec4::gbrb() const { return { g, b, r, b }; }
inline dvec4 dvec4::gbrg() const { return { g, b, r, g }; }
inline dvec4 dvec4::gbrr() const { return { g, b, r, r }; }
inline dvec2 dvec4::gg() const { return { g, g }; }
inline dvec3 dvec4::gga() const { return { g, g, a }; }
inline dvec4 dvec4::ggaa() const { return { g, g, a, a }; }
inline dvec4 dvec4::ggab() const { return { g, g, a, b }; }
inline dvec4 dvec4::ggag() const { return { g, g, a, g }; }
inline dvec4 dvec4::ggar() const { return { g, g, a, r }; }
inline dvec3 dvec4::ggb() const { return { g, g, b }; }
inline dvec4 dvec4::ggba() const { return { g, g, b, a }; }
inline dvec4 dvec4::ggbb() const { return { g, g, b, b }; }
inline dvec4 dvec4::ggbg() const { return { g, g, b, g }; }
inline dvec4 dvec4::ggbr() const { return { g, g, b, r }; }
inline dvec3 dvec4::ggg() const { return { g, g, g }; }
inline dvec4 dvec4::ggga() const { return { g, g, g, a }; }
inline dvec4 dvec4::gggb() const { return { g, g, g, b }; }
inline dvec4 dvec4::gggg() const { return { g, g, g, g }; }
inline dvec4 dvec4::gggr() const { return { g, g, g, r }; }
inline dvec3 dvec4::ggr() const { return { g, g, r }; }
inline dvec4 dvec4::ggra() const { return { g, g, r, a }; }
inline dvec4 dvec4::ggrb() const { return { g, g, r, b }; }
inline dvec4 dvec4::ggrg() const { return { g, g, r, g }; }
inline dvec4 dvec4::ggrr() const { return { g, g, r, r }; }
inline dvec2 dvec4::gr() const { return { g, r }; }
inline dvec3 dvec4::gra() const { return { g, r, a }; }
inline dvec4 dvec4::graa() const { return { g, r, a, a }; }
inline dvec4 dvec4::grab() const { return { g, r, a, b }; }
inline dvec4 dvec4::grag() const { return { g, r, a, g }; }
inline dvec4 dvec4::grar() const { return { g, r, a, r }; }
inline dvec3 dvec4::grb() const { return { g, r, b }; }
inline dvec4 dvec4::grba() const { return { g, r, b, a }; }
inline dvec4 dvec4::grbb() const { return { g, r, b, b }; }
inline dvec4 dvec4::grbg() const { return { g, r, b, g }; }
inline dvec4 dvec4::grbr() const { return { g, r, b, r }; }
inline dvec3 dvec4::grg() const { return { g, r, g }; }
inline dvec4 dvec4::grga() const { return { g, r, g, a }; }
inline dvec4 dvec4::grgb() const { return { g, r, g, b }; }
inline dvec4 dvec4::grgg() const { return { g, r, g, g }; }
inline dvec4 dvec4::grgr() const { return { g, r, g, r }; }
inline dvec3 dvec4::grr() const { return { g, r, r }; }
inline dvec4 dvec4::grra() const { return { g, r, r, a }; }
inline dvec4 dvec4::grrb() const { return { g, r, r, b }; }
inline dvec4 dvec4::grrg() const { return { g, r, r, g }; }
inline dvec4 dvec4::grrr() const { return { g, r, r, r }; }
inline dvec2 dvec4::ra() const { return { r, a }; }
inline dvec3 dvec4::raa() const { return { r, a, a }; }
inline dvec4 dvec4::raaa() const { return { r, a, a, a }; }
inline dvec4 dvec4::raab() const { return { r, a, a, b }; }
inline dvec4 dvec4::raag() const { return { r, a, a, g }; }
inline dvec4 dvec4::raar() const { return { r, a, a, r }; }
inline dvec3 dvec4::rab() const { return { r, a, b }; }
inline dvec4 dvec4::raba() const { return { r, a, b, a }; }
inline dvec4 dvec4::rabb() const { return { r, a, b, b }; }
inline dvec4 dvec4::rabg() const { return { r, a, b, g }; }
inline dvec4 dvec4::rabr() const { return { r, a, b, r }; }
inline dvec3 dvec4::rag() const { return { r, a, g }; }
inline dvec4 dvec4::raga() const { return { r, a, g, a }; }
inline dvec4 dvec4::ragb() const { return { r, a, g, b }; }
inline dvec4 dvec4::ragg() const { return { r, a, g, g }; }
inline dvec4 dvec4::ragr() const { return { r, a, g, r }; }
inline dvec3 dvec4::rar() const { return { r, a, r }; }
inline dvec4 dvec4::rara() const { return { r, a, r, a }; }
inline dvec4 dvec4::rarb() const { return { r, a, r, b }; }
inline dvec4 dvec4::rarg() const { return { r, a, r, g }; }
inline dvec4 dvec4::rarr() const { return { r, a, r, r }; }
inline dvec2 dvec4::rb() const { return { r, b }; }
inline dvec3 dvec4::rba() const { return { r, b, a }; }
inline dvec4 dvec4::rbaa() const { return { r, b, a, a }; }
inline dvec4 dvec4::rbab() const { return { r, b, a, b }; }
inline dvec4 dvec4::rbag() const { return { r, b, a, g }; }
inline dvec4 dvec4::rbar() const { return { r, b, a, r }; }
inline dvec3 dvec4::rbb() const { return { r, b, b }; }
inline dvec4 dvec4::rbba() const { return { r, b, b, a }; }
inline dvec4 dvec4::rbbb() const { return { r, b, b, b }; }
inline dvec4 dvec4::rbbg() const { return { r, b, b, g }; }
inline dvec4 dvec4::rbbr() const { return { r, b, b, r }; }
inline dvec3 dvec4::rbg() const { return { r, b, g }; }
inline dvec4 dvec4::rbga() const { return { r, b, g, a }; }
inline dvec4 dvec4::rbgb() const { return { r, b, g, b }; }
inline dvec4 dvec4::rbgg() const { return { r, b, g, g }; }
inline dvec4 dvec4::rbgr() const { return { r, b, g, r }; }
inline dvec3 dvec4::rbr() const { return { r, b, r }; }
inline dvec4 dvec4::rbra() const { return { r, b, r, a }; }
inline dvec4 dvec4::rbrb() const { return { r, b, r, b }; }
inline dvec4 dvec4::rbrg() const { return { r, b, r, g }; }
inline dvec4 dvec4::rbrr() const { return { r, b, r, r }; }
inline dvec2 dvec4::rg() const { return { r, g }; }
inline dvec3 dvec4::rga() const { return { r, g, a }; }
inline dvec4 dvec4::rgaa() const { return { r, g, a, a }; }
inline dvec4 dvec4::rgab() const { return { r, g, a, b }; }
inline dvec4 dvec4::rgag() const { return { r, g, a, g }; }
inline dvec4 dvec4::rgar() const { return { r, g, a, r }; }
inline dvec3 dvec4::rgb() const { return { r, g, b }; }
inline dvec4 dvec4::rgba() const { return { r, g, b, a }; }
inline dvec4 dvec4::rgbb() const { return { r, g, b, b }; }
inline dvec4 dvec4::rgbg() const { return { r, g, b, g }; }
inline dvec4 dvec4::rgbr() const { return { r, g, b, r }; }
inline dvec3 dvec4::rgg() const { return { r, g, g }; }
inline dvec4 dvec4::rgga() const { return { r, g, g, a }; }
inline dvec4 dvec4::rggb() const { return { r, g, g, b }; }
inline dvec4 dvec4::rggg() const { return { r, g, g, g }; }
inline dvec4 dvec4::rggr() const { return { r, g, g, r }; }
inline dvec3 dvec4::rgr() const { return { r, g, r }; }
inline dvec4 dvec4::rgra() const { return { r, g, r, a }; }
inline dvec4 dvec4::rgrb() const { return { r, g, r, b }; }
inline dvec4 dvec4::rgrg() const { return { r, g, r, g }; }
inline dvec4 dvec4::rgrr() const { return { r, g, r, r }; }
inline dvec2 dvec4::rr() const { return { r, r }; }
inline dvec3 dvec4::rra() const { return { r, r, a }; }
inline dvec4 dvec4::rraa() const { return { r, r, a, a }; }
inline dvec4 dvec4::rrab() const { return { r, r, a, b }; }
inline dvec4 dvec4::rrag() const { return { r, r, a, g }; }
inline dvec4 dvec4::rrar() const { return { r, r, a, r }; }
inline dvec3 dvec4::rrb() const { return { r, r, b }; }
inline dvec4 dvec4::rrba() const { return { r, r, b, a }; }
inline dvec4 dvec4::rrbb() const { return { r, r, b, b }; }
inline dvec4 dvec4::rrbg() const { return { r, r, b, g }; }
inline dvec4 dvec4::rrbr() const { return { r, r, b, r }; }
inline dvec3 dvec4::rrg() const { return { r, r, g }; }
inline dvec4 dvec4::rrga() const { return { r, r, g, a }; }
inline dvec4 dvec4::rrgb() const { return { r, r, g, b }; }
inline dvec4 dvec4::rrgg() const { return { r, r, g, g }; }
inline dvec4 dvec4::rrgr() const { return { r, r, g, r }; }
inline dvec3 dvec4::rrr() const { return { r, r, r }; }
inline dvec4 dvec4::rrra() const { return { r, r, r, a }; }
inline dvec4 dvec4::rrrb() const { return { r, r, r, b }; }
inline dvec4 dvec4::rrrg() const { return { r, r, r, g }; }
inline dvec4 dvec4::rrrr() const { return { r, r, r, r }; }
inline dvec2 dvec4::qq() const { return { q, q }; }
inline dvec3 dvec4::qqq() const { return { q, q, q }; }
inline dvec4 dvec4::qqqq() const { return { q, q, q, q }; }
inline dvec4 dvec4::qqqs() const { return { q, q, q, s }; }
inline dvec4 dvec4::qqqt() const { return { q, q, q, t }; }
inline dvec4 dvec4::qqqp() const { return { q, q, q, p }; }
inline dvec3 dvec4::qqs() const { return { q, q, s }; }
inline dvec4 dvec4::qqsq() const { return { q, q, s, q }; }
inline dvec4 dvec4::qqss() const { return { q, q, s, s }; }
inline dvec4 dvec4::qqst() const { return { q, q, s, t }; }
inline dvec4 dvec4::qqsp() const { return { q, q, s, p }; }
inline dvec3 dvec4::qqt() const { return { q, q, t }; }
inline dvec4 dvec4::qqtq() const { return { q, q, t, q }; }
inline dvec4 dvec4::qqts() const { return { q, q, t, s }; }
inline dvec4 dvec4::qqtt() const { return { q, q, t, t }; }
inline dvec4 dvec4::qqtp() const { return { q, q, t, p }; }
inline dvec3 dvec4::qqp() const { return { q, q, p }; }
inline dvec4 dvec4::qqpq() const { return { q, q, p, q }; }
inline dvec4 dvec4::qqps() const { return { q, q, p, s }; }
inline dvec4 dvec4::qqpt() const { return { q, q, p, t }; }
inline dvec4 dvec4::qqpp() const { return { q, q, p, p }; }
inline dvec2 dvec4::qs() const { return { q, s }; }
inline dvec3 dvec4::qsq() const { return { q, s, q }; }
inline dvec4 dvec4::qsqq() const { return { q, s, q, q }; }
inline dvec4 dvec4::qsqs() const { return { q, s, q, s }; }
inline dvec4 dvec4::qsqt() const { return { q, s, q, t }; }
inline dvec4 dvec4::qsqp() const { return { q, s, q, p }; }
inline dvec3 dvec4::qss() const { return { q, s, s }; }
inline dvec4 dvec4::qssq() const { return { q, s, s, q }; }
inline dvec4 dvec4::qsss() const { return { q, s, s, s }; }
inline dvec4 dvec4::qsst() const { return { q, s, s, t }; }
inline dvec4 dvec4::qssp() const { return { q, s, s, p }; }
inline dvec3 dvec4::qst() const { return { q, s, t }; }
inline dvec4 dvec4::qstq() const { return { q, s, t, q }; }
inline dvec4 dvec4::qsts() const { return { q, s, t, s }; }
inline dvec4 dvec4::qstt() const { return { q, s, t, t }; }
inline dvec4 dvec4::qstp() const { return { q, s, t, p }; }
inline dvec3 dvec4::qsp() const { return { q, s, p }; }
inline dvec4 dvec4::qspq() const { return { q, s, p, q }; }
inline dvec4 dvec4::qsps() const { return { q, s, p, s }; }
inline dvec4 dvec4::qspt() const { return { q, s, p, t }; }
inline dvec4 dvec4::qspp() const { return { q, s, p, p }; }
inline dvec2 dvec4::qt() const { return { q, t }; }
inline dvec3 dvec4::qtq() const { return { q, t, q }; }
inline dvec4 dvec4::qtqq() const { return { q, t, q, q }; }
inline dvec4 dvec4::qtqs() const { return { q, t, q, s }; }
inline dvec4 dvec4::qtqt() const { return { q, t, q, t }; }
inline dvec4 dvec4::qtqp() const { return { q, t, q, p }; }
inline dvec3 dvec4::qts() const { return { q, t, s }; }
inline dvec4 dvec4::qtsq() const { return { q, t, s, q }; }
inline dvec4 dvec4::qtss() const { return { q, t, s, s }; }
inline dvec4 dvec4::qtst() const { return { q, t, s, t }; }
inline dvec4 dvec4::qtsp() const { return { q, t, s, p }; }
inline dvec3 dvec4::qtt() const { return { q, t, t }; }
inline dvec4 dvec4::qttq() const { return { q, t, t, q }; }
inline dvec4 dvec4::qtts() const { return { q, t, t, s }; }
inline dvec4 dvec4::qttt() const { return { q, t, t, t }; }
inline dvec4 dvec4::qttp() const { return { q, t, t, p }; }
inline dvec3 dvec4::qtp() const { return { q, t, p }; }
inline dvec4 dvec4::qtpq() const { return { q, t, p, q }; }
inline dvec4 dvec4::qtps() const { return { q, t, p, s }; }
inline dvec4 dvec4::qtpt() const { return { q, t, p, t }; }
inline dvec4 dvec4::qtpp() const { return { q, t, p, p }; }
inline dvec2 dvec4::qp() const { return { q, p }; }
inline dvec3 dvec4::qpq() const { return { q, p, q }; }
inline dvec4 dvec4::qpqq() const { return { q, p, q, q }; }
inline dvec4 dvec4::qpqs() const { return { q, p, q, s }; }
inline dvec4 dvec4::qpqt() const { return { q, p, q, t }; }
inline dvec4 dvec4::qpqp() const { return { q, p, q, p }; }
inline dvec3 dvec4::qps() const { return { q, p, s }; }
inline dvec4 dvec4::qpsq() const { return { q, p, s, q }; }
inline dvec4 dvec4::qpss() const { return { q, p, s, s }; }
inline dvec4 dvec4::qpst() const { return { q, p, s, t }; }
inline dvec4 dvec4::qpsp() const { return { q, p, s, p }; }
inline dvec3 dvec4::qpt() const { return { q, p, t }; }
inline dvec4 dvec4::qptq() const { return { q, p, t, q }; }
inline dvec4 dvec4::qpts() const { return { q, p, t, s }; }
inline dvec4 dvec4::qptt() const { return { q, p, t, t }; }
inline dvec4 dvec4::qptp() const { return { q, p, t, p }; }
inline dvec3 dvec4::qpp() const { return { q, p, p }; }
inline dvec4 dvec4::qppq() const { return { q, p, p, q }; }
inline dvec4 dvec4::qpps() const { return { q, p, p, s }; }
inline dvec4 dvec4::qppt() const { return { q, p, p, t }; }
inline dvec4 dvec4::qppp() const { return { q, p, p, p }; }
inline dvec2 dvec4::sq() const { return { s, q }; }
inline dvec3 dvec4::sqq() const { return { s, q, q }; }
inline dvec4 dvec4::sqqq() const { return { s, q, q, q }; }
inline dvec4 dvec4::sqqs() const { return { s, q, q, s }; }
inline dvec4 dvec4::sqqt() const { return { s, q, q, t }; }
inline dvec4 dvec4::sqqp() const { return { s, q, q, p }; }
inline dvec3 dvec4::sqs() const { return { s, q, s }; }
inline dvec4 dvec4::sqsq() const { return { s, q, s, q }; }
inline dvec4 dvec4::sqss() const { return { s, q, s, s }; }
inline dvec4 dvec4::sqst() const { return { s, q, s, t }; }
inline dvec4 dvec4::sqsp() const { return { s, q, s, p }; }
inline dvec3 dvec4::sqt() const { return { s, q, t }; }
inline dvec4 dvec4::sqtq() const { return { s, q, t, q }; }
inline dvec4 dvec4::sqts() const { return { s, q, t, s }; }
inline dvec4 dvec4::sqtt() const { return { s, q, t, t }; }
inline dvec4 dvec4::sqtp() const { return { s, q, t, p }; }
inline dvec3 dvec4::sqp() const { return { s, q, p }; }
inline dvec4 dvec4::sqpq() const { return { s, q, p, q }; }
inline dvec4 dvec4::sqps() const { return { s, q, p, s }; }
inline dvec4 dvec4::sqpt() const { return { s, q, p, t }; }
inline dvec4 dvec4::sqpp() const { return { s, q, p, p }; }
inline dvec2 dvec4::ss() const { return { s, s }; }
inline dvec3 dvec4::ssq() const { return { s, s, q }; }
inline dvec4 dvec4::ssqq() const { return { s, s, q, q }; }
inline dvec4 dvec4::ssqs() const { return { s, s, q, s }; }
inline dvec4 dvec4::ssqt() const { return { s, s, q, t }; }
inline dvec4 dvec4::ssqp() const { return { s, s, q, p }; }
inline dvec3 dvec4::sss() const { return { s, s, s }; }
inline dvec4 dvec4::sssq() const { return { s, s, s, q }; }
inline dvec4 dvec4::ssss() const { return { s, s, s, s }; }
inline dvec4 dvec4::ssst() const { return { s, s, s, t }; }
inline dvec4 dvec4::sssp() const { return { s, s, s, p }; }
inline dvec3 dvec4::sst() const { return { s, s, t }; }
inline dvec4 dvec4::sstq() const { return { s, s, t, q }; }
inline dvec4 dvec4::ssts() const { return { s, s, t, s }; }
inline dvec4 dvec4::sstt() const { return { s, s, t, t }; }
inline dvec4 dvec4::sstp() const { return { s, s, t, p }; }
inline dvec3 dvec4::ssp() const { return { s, s, p }; }
inline dvec4 dvec4::sspq() const { return { s, s, p, q }; }
inline dvec4 dvec4::ssps() const { return { s, s, p, s }; }
inline dvec4 dvec4::sspt() const { return { s, s, p, t }; }
inline dvec4 dvec4::sspp() const { return { s, s, p, p }; }
inline dvec2 dvec4::st() const { return { s, t }; }
inline dvec3 dvec4::stq() const { return { s, t, q }; }
inline dvec4 dvec4::stqq() const { return { s, t, q, q }; }
inline dvec4 dvec4::stqs() const { return { s, t, q, s }; }
inline dvec4 dvec4::stqt() const { return { s, t, q, t }; }
inline dvec4 dvec4::stqp() const { return { s, t, q, p }; }
inline dvec3 dvec4::sts() const { return { s, t, s }; }
inline dvec4 dvec4::stsq() const { return { s, t, s, q }; }
inline dvec4 dvec4::stss() const { return { s, t, s, s }; }
inline dvec4 dvec4::stst() const { return { s, t, s, t }; }
inline dvec4 dvec4::stsp() const { return { s, t, s, p }; }
inline dvec3 dvec4::stt() const { return { s, t, t }; }
inline dvec4 dvec4::sttq() const { return { s, t, t, q }; }
inline dvec4 dvec4::stts() const { return { s, t, t, s }; }
inline dvec4 dvec4::sttt() const { return { s, t, t, t }; }
inline dvec4 dvec4::sttp() const { return { s, t, t, p }; }
inline dvec3 dvec4::stp() const { return { s, t, p }; }
inline dvec4 dvec4::stpq() const { return { s, t, p, q }; }
inline dvec4 dvec4::stps() const { return { s, t, p, s }; }
inline dvec4 dvec4::stpt() const { return { s, t, p, t }; }
inline dvec4 dvec4::stpp() const { return { s, t, p, p }; }
inline dvec2 dvec4::sp() const { return { s, p }; }
inline dvec3 dvec4::spq() const { return { s, p, q }; }
inline dvec4 dvec4::spqq() const { return { s, p, q, q }; }
inline dvec4 dvec4::spqs() const { return { s, p, q, s }; }
inline dvec4 dvec4::spqt() const { return { s, p, q, t }; }
inline dvec4 dvec4::spqp() const { return { s, p, q, p }; }
inline dvec3 dvec4::sps() const { return { s, p, s }; }
inline dvec4 dvec4::spsq() const { return { s, p, s, q }; }
inline dvec4 dvec4::spss() const { return { s, p, s, s }; }
inline dvec4 dvec4::spst() const { return { s, p, s, t }; }
inline dvec4 dvec4::spsp() const { return { s, p, s, p }; }
inline dvec3 dvec4::spt() const { return { s, p, t }; }
inline dvec4 dvec4::sptq() const { return { s, p, t, q }; }
inline dvec4 dvec4::spts() const { return { s, p, t, s }; }
inline dvec4 dvec4::sptt() const { return { s, p, t, t }; }
inline dvec4 dvec4::sptp() const { return { s, p, t, p }; }
inline dvec3 dvec4::spp() const { return { s, p, p }; }
inline dvec4 dvec4::sppq() const { return { s, p, p, q }; }
inline dvec4 dvec4::spps() const { return { s, p, p, s }; }
inline dvec4 dvec4::sppt() const { return { s, p, p, t }; }
inline dvec4 dvec4::sppp() const { return { s, p, p, p }; }
inline dvec2 dvec4::tq() const { return { t, q }; }
inline dvec3 dvec4::tqq() const { return { t, q, q }; }
inline dvec4 dvec4::tqqq() const { return { t, q, q, q }; }
inline dvec4 dvec4::tqqs() const { return { t, q, q, s }; }
inline dvec4 dvec4::tqqt() const { return { t, q, q, t }; }
inline dvec4 dvec4::tqqp() const { return { t, q, q, p }; }
inline dvec3 dvec4::tqs() const { return { t, q, s }; }
inline dvec4 dvec4::tqsq() const { return { t, q, s, q }; }
inline dvec4 dvec4::tqss() const { return { t, q, s, s }; }
inline dvec4 dvec4::tqst() const { return { t, q, s, t }; }
inline dvec4 dvec4::tqsp() const { return { t, q, s, p }; }
inline dvec3 dvec4::tqt() const { return { t, q, t }; }
inline dvec4 dvec4::tqtq() const { return { t, q, t, q }; }
inline dvec4 dvec4::tqts() const { return { t, q, t, s }; }
inline dvec4 dvec4::tqtt() const { return { t, q, t, t }; }
inline dvec4 dvec4::tqtp() const { return { t, q, t, p }; }
inline dvec3 dvec4::tqp() const { return { t, q, p }; }
inline dvec4 dvec4::tqpq() const { return { t, q, p, q }; }
inline dvec4 dvec4::tqps() const { return { t, q, p, s }; }
inline dvec4 dvec4::tqpt() const { return { t, q, p, t }; }
inline dvec4 dvec4::tqpp() const { return { t, q, p, p }; }
inline dvec2 dvec4::ts() const { return { t, s }; }
inline dvec3 dvec4::tsq() const { return { t, s, q }; }
inline dvec4 dvec4::tsqq() const { return { t, s, q, q }; }
inline dvec4 dvec4::tsqs() const { return { t, s, q, s }; }
inline dvec4 dvec4::tsqt() const { return { t, s, q, t }; }
inline dvec4 dvec4::tsqp() const { return { t, s, q, p }; }
inline dvec3 dvec4::tss() const { return { t, s, s }; }
inline dvec4 dvec4::tssq() const { return { t, s, s, q }; }
inline dvec4 dvec4::tsss() const { return { t, s, s, s }; }
inline dvec4 dvec4::tsst() const { return { t, s, s, t }; }
inline dvec4 dvec4::tssp() const { return { t, s, s, p }; }
inline dvec3 dvec4::tst() const { return { t, s, t }; }
inline dvec4 dvec4::tstq() const { return { t, s, t, q }; }
inline dvec4 dvec4::tsts() const { return { t, s, t, s }; }
inline dvec4 dvec4::tstt() const { return { t, s, t, t }; }
inline dvec4 dvec4::tstp() const { return { t, s, t, p }; }
inline dvec3 dvec4::tsp() const { return { t, s, p }; }
inline dvec4 dvec4::tspq() const { return { t, s, p, q }; }
inline dvec4 dvec4::tsps() const { return { t, s, p, s }; }
inline dvec4 dvec4::tspt() const { return { t, s, p, t }; }
inline dvec4 dvec4::tspp() const { return { t, s, p, p }; }
inline dvec2 dvec4::tt() const { return { t, t }; }
inline dvec3 dvec4::ttq() const { return { t, t, q }; }
inline dvec4 dvec4::ttqq() const { return { t, t, q, q }; }
inline dvec4 dvec4::ttqs() const { return { t, t, q, s }; }
inline dvec4 dvec4::ttqt() const { return { t, t, q, t }; }
inline dvec4 dvec4::ttqp() const { return { t, t, q, p }; }
inline dvec3 dvec4::tts() const { return { t, t, s }; }
inline dvec4 dvec4::ttsq() const { return { t, t, s, q }; }
inline dvec4 dvec4::ttss() const { return { t, t, s, s }; }
inline dvec4 dvec4::ttst() const { return { t, t, s, t }; }
inline dvec4 dvec4::ttsp() const { return { t, t, s, p }; }
inline dvec3 dvec4::ttt() const { return { t, t, t }; }
inline dvec4 dvec4::tttq() const { return { t, t, t, q }; }
inline dvec4 dvec4::ttts() const { return { t, t, t, s }; }
inline dvec4 dvec4::tttt() const { return { t, t, t, t }; }
inline dvec4 dvec4::tttp() const { return { t, t, t, p }; }
inline dvec3 dvec4::ttp() const { return { t, t, p }; }
inline dvec4 dvec4::ttpq() const { return { t, t, p, q }; }
inline dvec4 dvec4::ttps() const { return { t, t, p, s }; }
inline dvec4 dvec4::ttpt() const { return { t, t, p, t }; }
inline dvec4 dvec4::ttpp() const { return { t, t, p, p }; }
inline dvec2 dvec4::tp() const { return { t, p }; }
inline dvec3 dvec4::tpq() const { return { t, p, q }; }
inline dvec4 dvec4::tpqq() const { return { t, p, q, q }; }
inline dvec4 dvec4::tpqs() const { return { t, p, q, s }; }
inline dvec4 dvec4::tpqt() const { return { t, p, q, t }; }
inline dvec4 dvec4::tpqp() const { return { t, p, q, p }; }
inline dvec3 dvec4::tps() const { return { t, p, s }; }
inline dvec4 dvec4::tpsq() const { return { t, p, s, q }; }
inline dvec4 dvec4::tpss() const { return { t, p, s, s }; }
inline dvec4 dvec4::tpst() const { return { t, p, s, t }; }
inline dvec4 dvec4::tpsp() const { return { t, p, s, p }; }
inline dvec3 dvec4::tpt() const { return { t, p, t }; }
inline dvec4 dvec4::tptq() const { return { t, p, t, q }; }
inline dvec4 dvec4::tpts() const { return { t, p, t, s }; }
inline dvec4 dvec4::tptt() const { return { t, p, t, t }; }
inline dvec4 dvec4::tptp() const { return { t, p, t, p }; }
inline dvec3 dvec4::tpp() const { return { t, p, p }; }
inline dvec4 dvec4::tppq() const { return { t, p, p, q }; }
inline dvec4 dvec4::tpps() const { return { t, p, p, s }; }
inline dvec4 dvec4::tppt() const { return { t, p, p, t }; }
inline dvec4 dvec4::tppp() const { return { t, p, p, p }; }
inline dvec2 dvec4::pq() const { return { p, q }; }
inline dvec3 dvec4::pqq() const { return { p, q, q }; }
inline dvec4 dvec4::pqqq() const { return { p, q, q, q }; }
inline dvec4 dvec4::pqqs() const { return { p, q, q, s }; }
inline dvec4 dvec4::pqqt() const { return { p, q, q, t }; }
inline dvec4 dvec4::pqqp() const { return { p, q, q, p }; }
inline dvec3 dvec4::pqs() const { return { p, q, s }; }
inline dvec4 dvec4::pqsq() const { return { p, q, s, q }; }
inline dvec4 dvec4::pqss() const { return { p, q, s, s }; }
inline dvec4 dvec4::pqst() const { return { p, q, s, t }; }
inline dvec4 dvec4::pqsp() const { return { p, q, s, p }; }
inline dvec3 dvec4::pqt() const { return { p, q, t }; }
inline dvec4 dvec4::pqtq() const { return { p, q, t, q }; }
inline dvec4 dvec4::pqts() const { return { p, q, t, s }; }
inline dvec4 dvec4::pqtt() const { return { p, q, t, t }; }
inline dvec4 dvec4::pqtp() const { return { p, q, t, p }; }
inline dvec3 dvec4::pqp() const { return { p, q, p }; }
inline dvec4 dvec4::pqpq() const { return { p, q, p, q }; }
inline dvec4 dvec4::pqps() const { return { p, q, p, s }; }
inline dvec4 dvec4::pqpt() const { return { p, q, p, t }; }
inline dvec4 dvec4::pqpp() const { return { p, q, p, p }; }
inline dvec2 dvec4::ps() const { return { p, s }; }
inline dvec3 dvec4::psq() const { return { p, s, q }; }
inline dvec4 dvec4::psqq() const { return { p, s, q, q }; }
inline dvec4 dvec4::psqs() const { return { p, s, q, s }; }
inline dvec4 dvec4::psqt() const { return { p, s, q, t }; }
inline dvec4 dvec4::psqp() const { return { p, s, q, p }; }
inline dvec3 dvec4::pss() const { return { p, s, s }; }
inline dvec4 dvec4::pssq() const { return { p, s, s, q }; }
inline dvec4 dvec4::psss() const { return { p, s, s, s }; }
inline dvec4 dvec4::psst() const { return { p, s, s, t }; }
inline dvec4 dvec4::pssp() const { return { p, s, s, p }; }
inline dvec3 dvec4::pst() const { return { p, s, t }; }
inline dvec4 dvec4::pstq() const { return { p, s, t, q }; }
inline dvec4 dvec4::psts() const { return { p, s, t, s }; }
inline dvec4 dvec4::pstt() const { return { p, s, t, t }; }
inline dvec4 dvec4::pstp() const { return { p, s, t, p }; }
inline dvec3 dvec4::psp() const { return { p, s, p }; }
inline dvec4 dvec4::pspq() const { return { p, s, p, q }; }
inline dvec4 dvec4::psps() const { return { p, s, p, s }; }
inline dvec4 dvec4::pspt() const { return { p, s, p, t }; }
inline dvec4 dvec4::pspp() const { return { p, s, p, p }; }
inline dvec2 dvec4::pt() const { return { p, t }; }
inline dvec3 dvec4::ptq() const { return { p, t, q }; }
inline dvec4 dvec4::ptqq() const { return { p, t, q, q }; }
inline dvec4 dvec4::ptqs() const { return { p, t, q, s }; }
inline dvec4 dvec4::ptqt() const { return { p, t, q, t }; }
inline dvec4 dvec4::ptqp() const { return { p, t, q, p }; }
inline dvec3 dvec4::pts() const { return { p, t, s }; }
inline dvec4 dvec4::ptsq() const { return { p, t, s, q }; }
inline dvec4 dvec4::ptss() const { return { p, t, s, s }; }
inline dvec4 dvec4::ptst() const { return { p, t, s, t }; }
inline dvec4 dvec4::ptsp() const { return { p, t, s, p }; }
inline dvec3 dvec4::ptt() const { return { p, t, t }; }
inline dvec4 dvec4::pttq() const { return { p, t, t, q }; }
inline dvec4 dvec4::ptts() const { return { p, t, t, s }; }
inline dvec4 dvec4::pttt() const { return { p, t, t, t }; }
inline dvec4 dvec4::pttp() const { return { p, t, t, p }; }
inline dvec3 dvec4::ptp() const { return { p, t, p }; }
inline dvec4 dvec4::ptpq() const { return { p, t, p, q }; }
inline dvec4 dvec4::ptps() const { return { p, t, p, s }; }
inline dvec4 dvec4::ptpt() const { return { p, t, p, t }; }
inline dvec4 dvec4::ptpp() const { return { p, t, p, p }; }
inline dvec2 dvec4::pp() const { return { p, p }; }
inline dvec3 dvec4::ppq() const { return { p, p, q }; }
inline dvec4 dvec4::ppqq() const { return { p, p, q, q }; }
inline dvec4 dvec4::ppqs() const { return { p, p, q, s }; }
inline dvec4 dvec4::ppqt() const { return { p, p, q, t }; }
inline dvec4 dvec4::ppqp() const { return { p, p, q, p }; }
inline dvec3 dvec4::pps() const { return { p, p, s }; }
inline dvec4 dvec4::ppsq() const { return { p, p, s, q }; }
inline dvec4 dvec4::ppss() const { return { p, p, s, s }; }
inline dvec4 dvec4::ppst() const { return { p, p, s, t }; }
inline dvec4 dvec4::ppsp() const { return { p, p, s, p }; }
inline dvec3 dvec4::ppt() const { return { p, p, t }; }
inline dvec4 dvec4::pptq() const { return { p, p, t, q }; }
inline dvec4 dvec4::ppts() const { return { p, p, t, s }; }
inline dvec4 dvec4::pptt() const { return { p, p, t, t }; }
inline dvec4 dvec4::pptp() const { return { p, p, t, p }; }
inline dvec3 dvec4::ppp() const { return { p, p, p }; }
inline dvec4 dvec4::pppq() const { return { p, p, p, q }; }
inline dvec4 dvec4::ppps() const { return { p, p, p, s }; }
inline dvec4 dvec4::pppt() const { return { p, p, p, t }; }
inline dvec4 dvec4::pppp() const { return { p, p, p, p }; }
inline dvec2 dvec4::ww() const { return { w, w }; }
inline dvec3 dvec4::www() const { return { w, w, w }; }
inline dvec4 dvec4::wwww() const { return { w, w, w, w }; }
inline dvec4 dvec4::wwwx() const { return { w, w, w, x }; }
inline dvec4 dvec4::wwwy() const { return { w, w, w, y }; }
inline dvec4 dvec4::wwwz() const { return { w, w, w, z }; }
inline dvec3 dvec4::wwx() const { return { w, w, x }; }
inline dvec4 dvec4::wwxw() const { return { w, w, x, w }; }
inline dvec4 dvec4::wwxx() const { return { w, w, x, x }; }
inline dvec4 dvec4::wwxy() const { return { w, w, x, y }; }
inline dvec4 dvec4::wwxz() const { return { w, w, x, z }; }
inline dvec3 dvec4::wwy() const { return { w, w, y }; }
inline dvec4 dvec4::wwyw() const { return { w, w, y, w }; }
inline dvec4 dvec4::wwyx() const { return { w, w, y, x }; }
inline dvec4 dvec4::wwyy() const { return { w, w, y, y }; }
inline dvec4 dvec4::wwyz() const { return { w, w, y, z }; }
inline dvec3 dvec4::wwz() const { return { w, w, z }; }
inline dvec4 dvec4::wwzw() const { return { w, w, z, w }; }
inline dvec4 dvec4::wwzx() const { return { w, w, z, x }; }
inline dvec4 dvec4::wwzy() const { return { w, w, z, y }; }
inline dvec4 dvec4::wwzz() const { return { w, w, z, z }; }
inline dvec2 dvec4::wx() const { return { w, x }; }
inline dvec3 dvec4::wxw() const { return { w, x, w }; }
inline dvec4 dvec4::wxww() const { return { w, x, w, w }; }
inline dvec4 dvec4::wxwx() const { return { w, x, w, x }; }
inline dvec4 dvec4::wxwy() const { return { w, x, w, y }; }
inline dvec4 dvec4::wxwz() const { return { w, x, w, z }; }
inline dvec3 dvec4::wxx() const { return { w, x, x }; }
inline dvec4 dvec4::wxxw() const { return { w, x, x, w }; }
inline dvec4 dvec4::wxxx() const { return { w, x, x, x }; }
inline dvec4 dvec4::wxxy() const { return { w, x, x, y }; }
inline dvec4 dvec4::wxxz() const { return { w, x, x, z }; }
inline dvec3 dvec4::wxy() const { return { w, x, y }; }
inline dvec4 dvec4::wxyw() const { return { w, x, y, w }; }
inline dvec4 dvec4::wxyx() const { return { w, x, y, x }; }
inline dvec4 dvec4::wxyy() const { return { w, x, y, y }; }
inline dvec4 dvec4::wxyz() const { return { w, x, y, z }; }
inline dvec3 dvec4::wxz() const { return { w, x, z }; }
inline dvec4 dvec4::wxzw() const { return { w, x, z, w }; }
inline dvec4 dvec4::wxzx() const { return { w, x, z, x }; }
inline dvec4 dvec4::wxzy() const { return { w, x, z, y }; }
inline dvec4 dvec4::wxzz() const { return { w, x, z, z }; }
inline dvec2 dvec4::wy() const { return { w, y }; }
inline dvec3 dvec4::wyw() const { return { w, y, w }; }
inline dvec4 dvec4::wyww() const { return { w, y, w, w }; }
inline dvec4 dvec4::wywx() const { return { w, y, w, x }; }
inline dvec4 dvec4::wywy() const { return { w, y, w, y }; }
inline dvec4 dvec4::wywz() const { return { w, y, w, z }; }
inline dvec3 dvec4::wyx() const { return { w, y, x }; }
inline dvec4 dvec4::wyxw() const { return { w, y, x, w }; }
inline dvec4 dvec4::wyxx() const { return { w, y, x, x }; }
inline dvec4 dvec4::wyxy() const { return { w, y, x, y }; }
inline dvec4 dvec4::wyxz() const { return { w, y, x, z }; }
inline dvec3 dvec4::wyy() const { return { w, y, y }; }
inline dvec4 dvec4::wyyw() const { return { w, y, y, w }; }
inline dvec4 dvec4::wyyx() const { return { w, y, y, x }; }
inline dvec4 dvec4::wyyy() const { return { w, y, y, y }; }
inline dvec4 dvec4::wyyz() const { return { w, y, y, z }; }
inline dvec3 dvec4::wyz() const { return { w, y, z }; }
inline dvec4 dvec4::wyzw() const { return { w, y, z, w }; }
inline dvec4 dvec4::wyzx() const { return { w, y, z, x }; }
inline dvec4 dvec4::wyzy() const { return { w, y, z, y }; }
inline dvec4 dvec4::wyzz() const { return { w, y, z, z }; }
inline dvec2 dvec4::wz() const { return { w, z }; }
inline dvec3 dvec4::wzw() const { return { w, z, w }; }
inline dvec4 dvec4::wzww() const { return { w, z, w, w }; }
inline dvec4 dvec4::wzwx() const { return { w, z, w, x }; }
inline dvec4 dvec4::wzwy() const { return { w, z, w, y }; }
inline dvec4 dvec4::wzwz() const { return { w, z, w, z }; }
inline dvec3 dvec4::wzx() const { return { w, z, x }; }
inline dvec4 dvec4::wzxw() const { return { w, z, x, w }; }
inline dvec4 dvec4::wzxx() const { return { w, z, x, x }; }
inline dvec4 dvec4::wzxy() const { return { w, z, x, y }; }
inline dvec4 dvec4::wzxz() const { return { w, z, x, z }; }
inline dvec3 dvec4::wzy() const { return { w, z, y }; }
inline dvec4 dvec4::wzyw() const { return { w, z, y, w }; }
inline dvec4 dvec4::wzyx() const { return { w, z, y, x }; }
inline dvec4 dvec4::wzyy() const { return { w, z, y, y }; }
inline dvec4 dvec4::wzyz() const { return { w, z, y, z }; }
inline dvec3 dvec4::wzz() const { return { w, z, z }; }
inline dvec4 dvec4::wzzw() const { return { w, z, z, w }; }
inline dvec4 dvec4::wzzx() const { return { w, z, z, x }; }
inline dvec4 dvec4::wzzy() const { return { w, z, z, y }; }
inline dvec4 dvec4::wzzz() const { return { w, z, z, z }; }
inline dvec2 dvec4::xw() const { return { x, w }; }
inline dvec3 dvec4::xww() const { return { x, w, w }; }
inline dvec4 dvec4::xwww() const { return { x, w, w, w }; }
inline dvec4 dvec4::xwwx() const { return { x, w, w, x }; }
inline dvec4 dvec4::xwwy() const { return { x, w, w, y }; }
inline dvec4 dvec4::xwwz() const { return { x, w, w, z }; }
inline dvec3 dvec4::xwx() const { return { x, w, x }; }
inline dvec4 dvec4::xwxw() const { return { x, w, x, w }; }
inline dvec4 dvec4::xwxx() const { return { x, w, x, x }; }
inline dvec4 dvec4::xwxy() const { return { x, w, x, y }; }
inline dvec4 dvec4::xwxz() const { return { x, w, x, z }; }
inline dvec3 dvec4::xwy() const { return { x, w, y }; }
inline dvec4 dvec4::xwyw() const { return { x, w, y, w }; }
inline dvec4 dvec4::xwyx() const { return { x, w, y, x }; }
inline dvec4 dvec4::xwyy() const { return { x, w, y, y }; }
inline dvec4 dvec4::xwyz() const { return { x, w, y, z }; }
inline dvec3 dvec4::xwz() const { return { x, w, z }; }
inline dvec4 dvec4::xwzw() const { return { x, w, z, w }; }
inline dvec4 dvec4::xwzx() const { return { x, w, z, x }; }
inline dvec4 dvec4::xwzy() const { return { x, w, z, y }; }
inline dvec4 dvec4::xwzz() const { return { x, w, z, z }; }
inline dvec2 dvec4::xx() const { return { x, x }; }
inline dvec3 dvec4::xxw() const { return { x, x, w }; }
inline dvec4 dvec4::xxww() const { return { x, x, w, w }; }
inline dvec4 dvec4::xxwx() const { return { x, x, w, x }; }
inline dvec4 dvec4::xxwy() const { return { x, x, w, y }; }
inline dvec4 dvec4::xxwz() const { return { x, x, w, z }; }
inline dvec3 dvec4::xxx() const { return { x, x, x }; }
inline dvec4 dvec4::xxxw() const { return { x, x, x, w }; }
inline dvec4 dvec4::xxxx() const { return { x, x, x, x }; }
inline dvec4 dvec4::xxxy() const { return { x, x, x, y }; }
inline dvec4 dvec4::xxxz() const { return { x, x, x, z }; }
inline dvec3 dvec4::xxy() const { return { x, x, y }; }
inline dvec4 dvec4::xxyw() const { return { x, x, y, w }; }
inline dvec4 dvec4::xxyx() const { return { x, x, y, x }; }
inline dvec4 dvec4::xxyy() const { return { x, x, y, y }; }
inline dvec4 dvec4::xxyz() const { return { x, x, y, z }; }
inline dvec3 dvec4::xxz() const { return { x, x, z }; }
inline dvec4 dvec4::xxzw() const { return { x, x, z, w }; }
inline dvec4 dvec4::xxzx() const { return { x, x, z, x }; }
inline dvec4 dvec4::xxzy() const { return { x, x, z, y }; }
inline dvec4 dvec4::xxzz() const { return { x, x, z, z }; }
inline dvec2 dvec4::xy() const { return { x, y }; }
inline dvec3 dvec4::xyw() const { return { x, y, w }; }
inline dvec4 dvec4::xyww() const { return { x, y, w, w }; }
inline dvec4 dvec4::xywx() const { return { x, y, w, x }; }
inline dvec4 dvec4::xywy() const { return { x, y, w, y }; }
inline dvec4 dvec4::xywz() const { return { x, y, w, z }; }
inline dvec3 dvec4::xyx() const { return { x, y, x }; }
inline dvec4 dvec4::xyxw() const { return { x, y, x, w }; }
inline dvec4 dvec4::xyxx() const { return { x, y, x, x }; }
inline dvec4 dvec4::xyxy() const { return { x, y, x, y }; }
inline dvec4 dvec4::xyxz() const { return { x, y, x, z }; }
inline dvec3 dvec4::xyy() const { return { x, y, y }; }
inline dvec4 dvec4::xyyw() const { return { x, y, y, w }; }
inline dvec4 dvec4::xyyx() const { return { x, y, y, x }; }
inline dvec4 dvec4::xyyy() const { return { x, y, y, y }; }
inline dvec4 dvec4::xyyz() const { return { x, y, y, z }; }
inline dvec3 dvec4::xyz() const { return { x, y, z }; }
inline dvec4 dvec4::xyzw() const { return { x, y, z, w }; }
inline dvec4 dvec4::xyzx() const { return { x, y, z, x }; }
inline dvec4 dvec4::xyzy() const { return { x, y, z, y }; }
inline dvec4 dvec4::xyzz() const { return { x, y, z, z }; }
inline dvec2 dvec4::xz() const { return { x, z }; }
inline dvec3 dvec4::xzw() const { return { x, z, w }; }
inline dvec4 dvec4::xzww() const { return { x, z, w, w }; }
inline dvec4 dvec4::xzwx() const { return { x, z, w, x }; }
inline dvec4 dvec4::xzwy() const { return { x, z, w, y }; }
inline dvec4 dvec4::xzwz() const { return { x, z, w, z }; }
inline dvec3 dvec4::xzx() const { return { x, z, x }; }
inline dvec4 dvec4::xzxw() const { return { x, z, x, w }; }
inline dvec4 dvec4::xzxx() const { return { x, z, x, x }; }
inline dvec4 dvec4::xzxy() const { return { x, z, x, y }; }
inline dvec4 dvec4::xzxz() const { return { x, z, x, z }; }
inline dvec3 dvec4::xzy() const { return { x, z, y }; }
inline dvec4 dvec4::xzyw() const { return { x, z, y, w }; }
inline dvec4 dvec4::xzyx() const { return { x, z, y, x }; }
inline dvec4 dvec4::xzyy() const { return { x, z, y, y }; }
inline dvec4 dvec4::xzyz() const { return { x, z, y, z }; }
inline dvec3 dvec4::xzz() const { return { x, z, z }; }
inline dvec4 dvec4::xzzw() const { return { x, z, z, w }; }
inline dvec4 dvec4::xzzx() const { return { x, z, z, x }; }
inline dvec4 dvec4::xzzy() const { return { x, z, z, y }; }
inline dvec4 dvec4::xzzz() const { return { x, z, z, z }; }
inline dvec2 dvec4::yw() const { return { y, w }; }
inline dvec3 dvec4::yww() const { return { y, w, w }; }
inline dvec4 dvec4::ywww() const { return { y, w, w, w }; }
inline dvec4 dvec4::ywwx() const { return { y, w, w, x }; }
inline dvec4 dvec4::ywwy() const { return { y, w, w, y }; }
inline dvec4 dvec4::ywwz() const { return { y, w, w, z }; }
inline dvec3 dvec4::ywx() const { return { y, w, x }; }
inline dvec4 dvec4::ywxw() const { return { y, w, x, w }; }
inline dvec4 dvec4::ywxx() const { return { y, w, x, x }; }
inline dvec4 dvec4::ywxy() const { return { y, w, x, y }; }
inline dvec4 dvec4::ywxz() const { return { y, w, x, z }; }
inline dvec3 dvec4::ywy() const { return { y, w, y }; }
inline dvec4 dvec4::ywyw() const { return { y, w, y, w }; }
inline dvec4 dvec4::ywyx() const { return { y, w, y, x }; }
inline dvec4 dvec4::ywyy() const { return { y, w, y, y }; }
inline dvec4 dvec4::ywyz() const { return { y, w, y, z }; }
inline dvec3 dvec4::ywz() const { return { y, w, z }; }
inline dvec4 dvec4::ywzw() const { return { y, w, z, w }; }
inline dvec4 dvec4::ywzx() const { return { y, w, z, x }; }
inline dvec4 dvec4::ywzy() const { return { y, w, z, y }; }
inline dvec4 dvec4::ywzz() const { return { y, w, z, z }; }
inline dvec2 dvec4::yx() const { return { y, x }; }
inline dvec3 dvec4::yxw() const { return { y, x, w }; }
inline dvec4 dvec4::yxww() const { return { y, x, w, w }; }
inline dvec4 dvec4::yxwx() const { return { y, x, w, x }; }
inline dvec4 dvec4::yxwy() const { return { y, x, w, y }; }
inline dvec4 dvec4::yxwz() const { return { y, x, w, z }; }
inline dvec3 dvec4::yxx() const { return { y, x, x }; }
inline dvec4 dvec4::yxxw() const { return { y, x, x, w }; }
inline dvec4 dvec4::yxxx() const { return { y, x, x, x }; }
inline dvec4 dvec4::yxxy() const { return { y, x, x, y }; }
inline dvec4 dvec4::yxxz() const { return { y, x, x, z }; }
inline dvec3 dvec4::yxy() const { return { y, x, y }; }
inline dvec4 dvec4::yxyw() const { return { y, x, y, w }; }
inline dvec4 dvec4::yxyx() const { return { y, x, y, x }; }
inline dvec4 dvec4::yxyy() const { return { y, x, y, y }; }
inline dvec4 dvec4::yxyz() const { return { y, x, y, z }; }
inline dvec3 dvec4::yxz() const { return { y, x, z }; }
inline dvec4 dvec4::yxzw() const { return { y, x, z, w }; }
inline dvec4 dvec4::yxzx() const { return { y, x, z, x }; }
inline dvec4 dvec4::yxzy() const { return { y, x, z, y }; }
inline dvec4 dvec4::yxzz() const { return { y, x, z, z }; }
inline dvec2 dvec4::yy() const { return { y, y }; }
inline dvec3 dvec4::yyw() const { return { y, y, w }; }
inline dvec4 dvec4::yyww() const { return { y, y, w, w }; }
inline dvec4 dvec4::yywx() const { return { y, y, w, x }; }
inline dvec4 dvec4::yywy() const { return { y, y, w, y }; }
inline dvec4 dvec4::yywz() const { return { y, y, w, z }; }
inline dvec3 dvec4::yyx() const { return { y, y, x }; }
inline dvec4 dvec4::yyxw() const { return { y, y, x, w }; }
inline dvec4 dvec4::yyxx() const { return { y, y, x, x }; }
inline dvec4 dvec4::yyxy() const { return { y, y, x, y }; }
inline dvec4 dvec4::yyxz() const { return { y, y, x, z }; }
inline dvec3 dvec4::yyy() const { return { y, y, y }; }
inline dvec4 dvec4::yyyw() const { return { y, y, y, w }; }
inline dvec4 dvec4::yyyx() const { return { y, y, y, x }; }
inline dvec4 dvec4::yyyy() const { return { y, y, y, y }; }
inline dvec4 dvec4::yyyz() const { return { y, y, y, z }; }
inline dvec3 dvec4::yyz() const { return { y, y, z }; }
inline dvec4 dvec4::yyzw() const { return { y, y, z, w }; }
inline dvec4 dvec4::yyzx() const { return { y, y, z, x }; }
inline dvec4 dvec4::yyzy() const { return { y, y, z, y }; }
inline dvec4 dvec4::yyzz() const { return { y, y, z, z }; }
inline dvec2 dvec4::yz() const { return { y, z }; }
inline dvec3 dvec4::yzw() const { return { y, z, w }; }
inline dvec4 dvec4::yzww() const { return { y, z, w, w }; }
inline dvec4 dvec4::yzwx() const { return { y, z, w, x }; }
inline dvec4 dvec4::yzwy() const { return { y, z, w, y }; }
inline dvec4 dvec4::yzwz() const { return { y, z, w, z }; }
inline dvec3 dvec4::yzx() const { return { y, z, x }; }
inline dvec4 dvec4::yzxw() const { return { y, z, x, w }; }
inline dvec4 dvec4::yzxx() const { return { y, z, x, x }; }
inline dvec4 dvec4::yzxy() const { return { y, z, x, y }; }
inline dvec4 dvec4::yzxz() const { return { y, z, x, z }; }
inline dvec3 dvec4::yzy() const { return { y, z, y }; }
inline dvec4 dvec4::yzyw() const { return { y, z, y, w }; }
inline dvec4 dvec4::yzyx() const { return { y, z, y, x }; }
inline dvec4 dvec4::yzyy() const { return { y, z, y, y }; }
inline dvec4 dvec4::yzyz() const { return { y, z, y, z }; }
inline dvec3 dvec4::yzz() const { return { y, z, z }; }
inline dvec4 dvec4::yzzw() const { return { y, z, z, w }; }
inline dvec4 dvec4::yzzx() const { return { y, z, z, x }; }
inline dvec4 dvec4::yzzy() const { return { y, z, z, y }; }
inline dvec4 dvec4::yzzz() const { return { y, z, z, z }; }
inline dvec2 dvec4::zw() const { return { z, w }; }
inline dvec3 dvec4::zww() const { return { z, w, w }; }
inline dvec4 dvec4::zwww() const { return { z, w, w, w }; }
inline dvec4 dvec4::zwwx() const { return { z, w, w, x }; }
inline dvec4 dvec4::zwwy() const { return { z, w, w, y }; }
inline dvec4 dvec4::zwwz() const { return { z, w, w, z }; }
inline dvec3 dvec4::zwx() const { return { z, w, x }; }
inline dvec4 dvec4::zwxw() const { return { z, w, x, w }; }
inline dvec4 dvec4::zwxx() const { return { z, w, x, x }; }
inline dvec4 dvec4::zwxy() const { return { z, w, x, y }; }
inline dvec4 dvec4::zwxz() const { return { z, w, x, z }; }
inline dvec3 dvec4::zwy() const { return { z, w, y }; }
inline dvec4 dvec4::zwyw() const { return { z, w, y, w }; }
inline dvec4 dvec4::zwyx() const { return { z, w, y, x }; }
inline dvec4 dvec4::zwyy() const { return { z, w, y, y }; }
inline dvec4 dvec4::zwyz() const { return { z, w, y, z }; }
inline dvec3 dvec4::zwz() const { return { z, w, z }; }
inline dvec4 dvec4::zwzw() const { return { z, w, z, w }; }
inline dvec4 dvec4::zwzx() const { return { z, w, z, x }; }
inline dvec4 dvec4::zwzy() const { return { z, w, z, y }; }
inline dvec4 dvec4::zwzz() const { return { z, w, z, z }; }
inline dvec2 dvec4::zx() const { return { z, x }; }
inline dvec3 dvec4::zxw() const { return { z, x, w }; }
inline dvec4 dvec4::zxww() const { return { z, x, w, w }; }
inline dvec4 dvec4::zxwx() const { return { z, x, w, x }; }
inline dvec4 dvec4::zxwy() const { return { z, x, w, y }; }
inline dvec4 dvec4::zxwz() const { return { z, x, w, z }; }
inline dvec3 dvec4::zxx() const { return { z, x, x }; }
inline dvec4 dvec4::zxxw() const { return { z, x, x, w }; }
inline dvec4 dvec4::zxxx() const { return { z, x, x, x }; }
inline dvec4 dvec4::zxxy() const { return { z, x, x, y }; }
inline dvec4 dvec4::zxxz() const { return { z, x, x, z }; }
inline dvec3 dvec4::zxy() const { return { z, x, y }; }
inline dvec4 dvec4::zxyw() const { return { z, x, y, w }; }
inline dvec4 dvec4::zxyx() const { return { z, x, y, x }; }
inline dvec4 dvec4::zxyy() const { return { z, x, y, y }; }
inline dvec4 dvec4::zxyz() const { return { z, x, y, z }; }
inline dvec3 dvec4::zxz() const { return { z, x, z }; }
inline dvec4 dvec4::zxzw() const { return { z, x, z, w }; }
inline dvec4 dvec4::zxzx() const { return { z, x, z, x }; }
inline dvec4 dvec4::zxzy() const { return { z, x, z, y }; }
inline dvec4 dvec4::zxzz() const { return { z, x, z, z }; }
inline dvec2 dvec4::zy() const { return { z, y }; }
inline dvec3 dvec4::zyw() const { return { z, y, w }; }
inline dvec4 dvec4::zyww() const { return { z, y, w, w }; }
inline dvec4 dvec4::zywx() const { return { z, y, w, x }; }
inline dvec4 dvec4::zywy() const { return { z, y, w, y }; }
inline dvec4 dvec4::zywz() const { return { z, y, w, z }; }
inline dvec3 dvec4::zyx() const { return { z, y, x }; }
inline dvec4 dvec4::zyxw() const { return { z, y, x, w }; }
inline dvec4 dvec4::zyxx() const { return { z, y, x, x }; }
inline dvec4 dvec4::zyxy() const { return { z, y, x, y }; }
inline dvec4 dvec4::zyxz() const { return { z, y, x, z }; }
inline dvec3 dvec4::zyy() const { return { z, y, y }; }
inline dvec4 dvec4::zyyw() const { return { z, y, y, w }; }
inline dvec4 dvec4::zyyx() const { return { z, y, y, x }; }
inline dvec4 dvec4::zyyy() const { return { z, y, y, y }; }
inline dvec4 dvec4::zyyz() const { return { z, y, y, z }; }
inline dvec3 dvec4::zyz() const { return { z, y, z }; }
inline dvec4 dvec4::zyzw() const { return { z, y, z, w }; }
inline dvec4 dvec4::zyzx() const { return { z, y, z, x }; }
inline dvec4 dvec4::zyzy() const { return { z, y, z, y }; }
inline dvec4 dvec4::zyzz() const { return { z, y, z, z }; }
inline dvec2 dvec4::zz() const { return { z, z }; }
inline dvec3 dvec4::zzw() const { return { z, z, w }; }
inline dvec4 dvec4::zzww() const { return { z, z, w, w }; }
inline dvec4 dvec4::zzwx() const { return { z, z, w, x }; }
inline dvec4 dvec4::zzwy() const { return { z, z, w, y }; }
inline dvec4 dvec4::zzwz() const { return { z, z, w, z }; }
inline dvec3 dvec4::zzx() const { return { z, z, x }; }
inline dvec4 dvec4::zzxw() const { return { z, z, x, w }; }
inline dvec4 dvec4::zzxx() const { return { z, z, x, x }; }
inline dvec4 dvec4::zzxy() const { return { z, z, x, y }; }
inline dvec4 dvec4::zzxz() const { return { z, z, x, z }; }
inline dvec3 dvec4::zzy() const { return { z, z, y }; }
inline dvec4 dvec4::zzyw() const { return { z, z, y, w }; }
inline dvec4 dvec4::zzyx() const { return { z, z, y, x }; }
inline dvec4 dvec4::zzyy() const { return { z, z, y, y }; }
inline dvec4 dvec4::zzyz() const { return { z, z, y, z }; }
inline dvec3 dvec4::zzz() const { return { z, z, z }; }
inline dvec4 dvec4::zzzw() const { return { z, z, z, w }; }
inline dvec4 dvec4::zzzx() const { return { z, z, z, x }; }
inline dvec4 dvec4::zzzy() const { return { z, z, z, y }; }
inline dvec4 dvec4::zzzz() const { return { z, z, z, z }; }
inline void dvec4::ab(const simddouble& _val0, const simddouble& _val1) { a = _val0; b = _val1; }
inline void dvec4::ab(const dvec2& _val) { a = _val.x; b = _val.y; }
inline void dvec4::ab(const simddouble& _val) { a = _val; b = _val; }
inline void dvec4::abg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { a = _val0; b = _val1; g = _val2; }
inline void dvec4::abg(const dvec3& _val) { a = _val.x; b = _val.y; g = _val.z; }
inline void dvec4::abg(const simddouble& _val) { a = _val; b = _val; g = _val; }
inline void dvec4::abgr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { a = _val0; b = _val1; g = _val2; r = _val3; }
inline void dvec4::abgr(const dvec4& _val) { a = _val.x; b = _val.y; g = _val.z; r = _val.w; }
inline void dvec4::abgr(const simddouble& _val) { a = _val; b = _val; g = _val; r = _val; }
inline void dvec4::abr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { a = _val0; b = _val1; r = _val2; }
inline void dvec4::abr(const dvec3& _val) { a = _val.x; b = _val.y; r = _val.z; }
inline void dvec4::abr(const simddouble& _val) { a = _val; b = _val; r = _val; }
inline void dvec4::abrg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { a = _val0; b = _val1; r = _val2; g = _val3; }
inline void dvec4::abrg(const dvec4& _val) { a = _val.x; b = _val.y; r = _val.z; g = _val.w; }
inline void dvec4::abrg(const simddouble& _val) { a = _val; b = _val; r = _val; g = _val; }
inline void dvec4::ag(const simddouble& _val0, const simddouble& _val1) { a = _val0; g = _val1; }
inline void dvec4::ag(const dvec2& _val) { a = _val.x; g = _val.y; }
inline void dvec4::ag(const simddouble& _val) { a = _val; g = _val; }
inline void dvec4::agb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { a = _val0; g = _val1; b = _val2; }
inline void dvec4::agb(const dvec3& _val) { a = _val.x; g = _val.y; b = _val.z; }
inline void dvec4::agb(const simddouble& _val) { a = _val; g = _val; b = _val; }
inline void dvec4::agbr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { a = _val0; g = _val1; b = _val2; r = _val3; }
inline void dvec4::agbr(const dvec4& _val) { a = _val.x; g = _val.y; b = _val.z; r = _val.w; }
inline void dvec4::agbr(const simddouble& _val) { a = _val; g = _val; b = _val; r = _val; }
inline void dvec4::agr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { a = _val0; g = _val1; r = _val2; }
inline void dvec4::agr(const dvec3& _val) { a = _val.x; g = _val.y; r = _val.z; }
inline void dvec4::agr(const simddouble& _val) { a = _val; g = _val; r = _val; }
inline void dvec4::agrb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { a = _val0; g = _val1; r = _val2; b = _val3; }
inline void dvec4::agrb(const dvec4& _val) { a = _val.x; g = _val.y; r = _val.z; b = _val.w; }
inline void dvec4::agrb(const simddouble& _val) { a = _val; g = _val; r = _val; b = _val; }
inline void dvec4::ar(const simddouble& _val0, const simddouble& _val1) { a = _val0; r = _val1; }
inline void dvec4::ar(const dvec2& _val) { a = _val.x; r = _val.y; }
inline void dvec4::ar(const simddouble& _val) { a = _val; r = _val; }
inline void dvec4::arb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { a = _val0; r = _val1; b = _val2; }
inline void dvec4::arb(const dvec3& _val) { a = _val.x; r = _val.y; b = _val.z; }
inline void dvec4::arb(const simddouble& _val) { a = _val; r = _val; b = _val; }
inline void dvec4::arbg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { a = _val0; r = _val1; b = _val2; g = _val3; }
inline void dvec4::arbg(const dvec4& _val) { a = _val.x; r = _val.y; b = _val.z; g = _val.w; }
inline void dvec4::arbg(const simddouble& _val) { a = _val; r = _val; b = _val; g = _val; }
inline void dvec4::arg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { a = _val0; r = _val1; g = _val2; }
inline void dvec4::arg(const dvec3& _val) { a = _val.x; r = _val.y; g = _val.z; }
inline void dvec4::arg(const simddouble& _val) { a = _val; r = _val; g = _val; }
inline void dvec4::argb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { a = _val0; r = _val1; g = _val2; b = _val3; }
inline void dvec4::argb(const dvec4& _val) { a = _val.x; r = _val.y; g = _val.z; b = _val.w; }
inline void dvec4::argb(const simddouble& _val) { a = _val; r = _val; g = _val; b = _val; }
inline void dvec4::ba(const simddouble& _val0, const simddouble& _val1) { b = _val0; a = _val1; }
inline void dvec4::ba(const dvec2& _val) { b = _val.x; a = _val.y; }
inline void dvec4::ba(const simddouble& _val) { b = _val; a = _val; }
inline void dvec4::bag(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { b = _val0; a = _val1; g = _val2; }
inline void dvec4::bag(const dvec3& _val) { b = _val.x; a = _val.y; g = _val.z; }
inline void dvec4::bag(const simddouble& _val) { b = _val; a = _val; g = _val; }
inline void dvec4::bagr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { b = _val0; a = _val1; g = _val2; r = _val3; }
inline void dvec4::bagr(const dvec4& _val) { b = _val.x; a = _val.y; g = _val.z; r = _val.w; }
inline void dvec4::bagr(const simddouble& _val) { b = _val; a = _val; g = _val; r = _val; }
inline void dvec4::bar(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { b = _val0; a = _val1; r = _val2; }
inline void dvec4::bar(const dvec3& _val) { b = _val.x; a = _val.y; r = _val.z; }
inline void dvec4::bar(const simddouble& _val) { b = _val; a = _val; r = _val; }
inline void dvec4::barg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { b = _val0; a = _val1; r = _val2; g = _val3; }
inline void dvec4::barg(const dvec4& _val) { b = _val.x; a = _val.y; r = _val.z; g = _val.w; }
inline void dvec4::barg(const simddouble& _val) { b = _val; a = _val; r = _val; g = _val; }
inline void dvec4::bg(const simddouble& _val0, const simddouble& _val1) { b = _val0; g = _val1; }
inline void dvec4::bg(const dvec2& _val) { b = _val.x; g = _val.y; }
inline void dvec4::bg(const simddouble& _val) { b = _val; g = _val; }
inline void dvec4::bga(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { b = _val0; g = _val1; a = _val2; }
inline void dvec4::bga(const dvec3& _val) { b = _val.x; g = _val.y; a = _val.z; }
inline void dvec4::bga(const simddouble& _val) { b = _val; g = _val; a = _val; }
inline void dvec4::bgar(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { b = _val0; g = _val1; a = _val2; r = _val3; }
inline void dvec4::bgar(const dvec4& _val) { b = _val.x; g = _val.y; a = _val.z; r = _val.w; }
inline void dvec4::bgar(const simddouble& _val) { b = _val; g = _val; a = _val; r = _val; }
inline void dvec4::bgr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { b = _val0; g = _val1; r = _val2; }
inline void dvec4::bgr(const dvec3& _val) { b = _val.x; g = _val.y; r = _val.z; }
inline void dvec4::bgr(const simddouble& _val) { b = _val; g = _val; r = _val; }
inline void dvec4::bgra(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { b = _val0; g = _val1; r = _val2; a = _val3; }
inline void dvec4::bgra(const dvec4& _val) { b = _val.x; g = _val.y; r = _val.z; a = _val.w; }
inline void dvec4::bgra(const simddouble& _val) { b = _val; g = _val; r = _val; a = _val; }
inline void dvec4::br(const simddouble& _val0, const simddouble& _val1) { b = _val0; r = _val1; }
inline void dvec4::br(const dvec2& _val) { b = _val.x; r = _val.y; }
inline void dvec4::br(const simddouble& _val) { b = _val; r = _val; }
inline void dvec4::bra(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { b = _val0; r = _val1; a = _val2; }
inline void dvec4::bra(const dvec3& _val) { b = _val.x; r = _val.y; a = _val.z; }
inline void dvec4::bra(const simddouble& _val) { b = _val; r = _val; a = _val; }
inline void dvec4::brag(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { b = _val0; r = _val1; a = _val2; g = _val3; }
inline void dvec4::brag(const dvec4& _val) { b = _val.x; r = _val.y; a = _val.z; g = _val.w; }
inline void dvec4::brag(const simddouble& _val) { b = _val; r = _val; a = _val; g = _val; }
inline void dvec4::brg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { b = _val0; r = _val1; g = _val2; }
inline void dvec4::brg(const dvec3& _val) { b = _val.x; r = _val.y; g = _val.z; }
inline void dvec4::brg(const simddouble& _val) { b = _val; r = _val; g = _val; }
inline void dvec4::brga(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { b = _val0; r = _val1; g = _val2; a = _val3; }
inline void dvec4::brga(const dvec4& _val) { b = _val.x; r = _val.y; g = _val.z; a = _val.w; }
inline void dvec4::brga(const simddouble& _val) { b = _val; r = _val; g = _val; a = _val; }
inline void dvec4::ga(const simddouble& _val0, const simddouble& _val1) { g = _val0; a = _val1; }
inline void dvec4::ga(const dvec2& _val) { g = _val.x; a = _val.y; }
inline void dvec4::ga(const simddouble& _val) { g = _val; a = _val; }
inline void dvec4::gab(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { g = _val0; a = _val1; b = _val2; }
inline void dvec4::gab(const dvec3& _val) { g = _val.x; a = _val.y; b = _val.z; }
inline void dvec4::gab(const simddouble& _val) { g = _val; a = _val; b = _val; }
inline void dvec4::gabr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { g = _val0; a = _val1; b = _val2; r = _val3; }
inline void dvec4::gabr(const dvec4& _val) { g = _val.x; a = _val.y; b = _val.z; r = _val.w; }
inline void dvec4::gabr(const simddouble& _val) { g = _val; a = _val; b = _val; r = _val; }
inline void dvec4::gar(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { g = _val0; a = _val1; r = _val2; }
inline void dvec4::gar(const dvec3& _val) { g = _val.x; a = _val.y; r = _val.z; }
inline void dvec4::gar(const simddouble& _val) { g = _val; a = _val; r = _val; }
inline void dvec4::garb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { g = _val0; a = _val1; r = _val2; b = _val3; }
inline void dvec4::garb(const dvec4& _val) { g = _val.x; a = _val.y; r = _val.z; b = _val.w; }
inline void dvec4::garb(const simddouble& _val) { g = _val; a = _val; r = _val; b = _val; }
inline void dvec4::gb(const simddouble& _val0, const simddouble& _val1) { g = _val0; b = _val1; }
inline void dvec4::gb(const dvec2& _val) { g = _val.x; b = _val.y; }
inline void dvec4::gb(const simddouble& _val) { g = _val; b = _val; }
inline void dvec4::gba(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { g = _val0; b = _val1; a = _val2; }
inline void dvec4::gba(const dvec3& _val) { g = _val.x; b = _val.y; a = _val.z; }
inline void dvec4::gba(const simddouble& _val) { g = _val; b = _val; a = _val; }
inline void dvec4::gbar(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { g = _val0; b = _val1; a = _val2; r = _val3; }
inline void dvec4::gbar(const dvec4& _val) { g = _val.x; b = _val.y; a = _val.z; r = _val.w; }
inline void dvec4::gbar(const simddouble& _val) { g = _val; b = _val; a = _val; r = _val; }
inline void dvec4::gbr(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { g = _val0; b = _val1; r = _val2; }
inline void dvec4::gbr(const dvec3& _val) { g = _val.x; b = _val.y; r = _val.z; }
inline void dvec4::gbr(const simddouble& _val) { g = _val; b = _val; r = _val; }
inline void dvec4::gbra(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { g = _val0; b = _val1; r = _val2; a = _val3; }
inline void dvec4::gbra(const dvec4& _val) { g = _val.x; b = _val.y; r = _val.z; a = _val.w; }
inline void dvec4::gbra(const simddouble& _val) { g = _val; b = _val; r = _val; a = _val; }
inline void dvec4::gr(const simddouble& _val0, const simddouble& _val1) { g = _val0; r = _val1; }
inline void dvec4::gr(const dvec2& _val) { g = _val.x; r = _val.y; }
inline void dvec4::gr(const simddouble& _val) { g = _val; r = _val; }
inline void dvec4::gra(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { g = _val0; r = _val1; a = _val2; }
inline void dvec4::gra(const dvec3& _val) { g = _val.x; r = _val.y; a = _val.z; }
inline void dvec4::gra(const simddouble& _val) { g = _val; r = _val; a = _val; }
inline void dvec4::grab(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { g = _val0; r = _val1; a = _val2; b = _val3; }
inline void dvec4::grab(const dvec4& _val) { g = _val.x; r = _val.y; a = _val.z; b = _val.w; }
inline void dvec4::grab(const simddouble& _val) { g = _val; r = _val; a = _val; b = _val; }
inline void dvec4::grb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { g = _val0; r = _val1; b = _val2; }
inline void dvec4::grb(const dvec3& _val) { g = _val.x; r = _val.y; b = _val.z; }
inline void dvec4::grb(const simddouble& _val) { g = _val; r = _val; b = _val; }
inline void dvec4::grba(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { g = _val0; r = _val1; b = _val2; a = _val3; }
inline void dvec4::grba(const dvec4& _val) { g = _val.x; r = _val.y; b = _val.z; a = _val.w; }
inline void dvec4::grba(const simddouble& _val) { g = _val; r = _val; b = _val; a = _val; }
inline void dvec4::ra(const simddouble& _val0, const simddouble& _val1) { r = _val0; a = _val1; }
inline void dvec4::ra(const dvec2& _val) { r = _val.x; a = _val.y; }
inline void dvec4::ra(const simddouble& _val) { r = _val; a = _val; }
inline void dvec4::rab(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { r = _val0; a = _val1; b = _val2; }
inline void dvec4::rab(const dvec3& _val) { r = _val.x; a = _val.y; b = _val.z; }
inline void dvec4::rab(const simddouble& _val) { r = _val; a = _val; b = _val; }
inline void dvec4::rabg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { r = _val0; a = _val1; b = _val2; g = _val3; }
inline void dvec4::rabg(const dvec4& _val) { r = _val.x; a = _val.y; b = _val.z; g = _val.w; }
inline void dvec4::rabg(const simddouble& _val) { r = _val; a = _val; b = _val; g = _val; }
inline void dvec4::rag(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { r = _val0; a = _val1; g = _val2; }
inline void dvec4::rag(const dvec3& _val) { r = _val.x; a = _val.y; g = _val.z; }
inline void dvec4::rag(const simddouble& _val) { r = _val; a = _val; g = _val; }
inline void dvec4::ragb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { r = _val0; a = _val1; g = _val2; b = _val3; }
inline void dvec4::ragb(const dvec4& _val) { r = _val.x; a = _val.y; g = _val.z; b = _val.w; }
inline void dvec4::ragb(const simddouble& _val) { r = _val; a = _val; g = _val; b = _val; }
inline void dvec4::rb(const simddouble& _val0, const simddouble& _val1) { r = _val0; b = _val1; }
inline void dvec4::rb(const dvec2& _val) { r = _val.x; b = _val.y; }
inline void dvec4::rb(const simddouble& _val) { r = _val; b = _val; }
inline void dvec4::rba(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { r = _val0; b = _val1; a = _val2; }
inline void dvec4::rba(const dvec3& _val) { r = _val.x; b = _val.y; a = _val.z; }
inline void dvec4::rba(const simddouble& _val) { r = _val; b = _val; a = _val; }
inline void dvec4::rbag(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { r = _val0; b = _val1; a = _val2; g = _val3; }
inline void dvec4::rbag(const dvec4& _val) { r = _val.x; b = _val.y; a = _val.z; g = _val.w; }
inline void dvec4::rbag(const simddouble& _val) { r = _val; b = _val; a = _val; g = _val; }
inline void dvec4::rbg(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { r = _val0; b = _val1; g = _val2; }
inline void dvec4::rbg(const dvec3& _val) { r = _val.x; b = _val.y; g = _val.z; }
inline void dvec4::rbg(const simddouble& _val) { r = _val; b = _val; g = _val; }
inline void dvec4::rbga(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { r = _val0; b = _val1; g = _val2; a = _val3; }
inline void dvec4::rbga(const dvec4& _val) { r = _val.x; b = _val.y; g = _val.z; a = _val.w; }
inline void dvec4::rbga(const simddouble& _val) { r = _val; b = _val; g = _val; a = _val; }
inline void dvec4::rg(const simddouble& _val0, const simddouble& _val1) { r = _val0; g = _val1; }
inline void dvec4::rg(const dvec2& _val) { r = _val.x; g = _val.y; }
inline void dvec4::rg(const simddouble& _val) { r = _val; g = _val; }
inline void dvec4::rga(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { r = _val0; g = _val1; a = _val2; }
inline void dvec4::rga(const dvec3& _val) { r = _val.x; g = _val.y; a = _val.z; }
inline void dvec4::rga(const simddouble& _val) { r = _val; g = _val; a = _val; }
inline void dvec4::rgab(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { r = _val0; g = _val1; a = _val2; b = _val3; }
inline void dvec4::rgab(const dvec4& _val) { r = _val.x; g = _val.y; a = _val.z; b = _val.w; }
inline void dvec4::rgab(const simddouble& _val) { r = _val; g = _val; a = _val; b = _val; }
inline void dvec4::rgb(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { r = _val0; g = _val1; b = _val2; }
inline void dvec4::rgb(const dvec3& _val) { r = _val.x; g = _val.y; b = _val.z; }
inline void dvec4::rgb(const simddouble& _val) { r = _val; g = _val; b = _val; }
inline void dvec4::rgba(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { r = _val0; g = _val1; b = _val2; a = _val3; }
inline void dvec4::rgba(const dvec4& _val) { r = _val.x; g = _val.y; b = _val.z; a = _val.w; }
inline void dvec4::rgba(const simddouble& _val) { r = _val; g = _val; b = _val; a = _val; }
inline void dvec4::qs(const simddouble& _val0, const simddouble& _val1) { q = _val0; s = _val1; }
inline void dvec4::qs(const dvec2& _val) { q = _val.s; s = _val.t; }
inline void dvec4::qs(const simddouble& _val) { q = _val; s = _val; }
inline void dvec4::qst(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { q = _val0; s = _val1; t = _val2; }
inline void dvec4::qst(const dvec3& _val) { q = _val.s; s = _val.t; t = _val.p; }
inline void dvec4::qst(const simddouble& _val) { q = _val; s = _val; t = _val; }
inline void dvec4::qstp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { q = _val0; s = _val1; t = _val2; p = _val3; }
inline void dvec4::qstp(const dvec4& _val) { q = _val.s; s = _val.t; t = _val.p; p = _val.q; }
inline void dvec4::qstp(const simddouble& _val) { q = _val; s = _val; t = _val; p = _val; }
inline void dvec4::qsp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { q = _val0; s = _val1; p = _val2; }
inline void dvec4::qsp(const dvec3& _val) { q = _val.s; s = _val.t; p = _val.p; }
inline void dvec4::qsp(const simddouble& _val) { q = _val; s = _val; p = _val; }
inline void dvec4::qspt(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { q = _val0; s = _val1; p = _val2; t = _val3; }
inline void dvec4::qspt(const dvec4& _val) { q = _val.s; s = _val.t; p = _val.p; t = _val.q; }
inline void dvec4::qspt(const simddouble& _val) { q = _val; s = _val; p = _val; t = _val; }
inline void dvec4::qt(const simddouble& _val0, const simddouble& _val1) { q = _val0; t = _val1; }
inline void dvec4::qt(const dvec2& _val) { q = _val.s; t = _val.t; }
inline void dvec4::qt(const simddouble& _val) { q = _val; t = _val; }
inline void dvec4::qts(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { q = _val0; t = _val1; s = _val2; }
inline void dvec4::qts(const dvec3& _val) { q = _val.s; t = _val.t; s = _val.p; }
inline void dvec4::qts(const simddouble& _val) { q = _val; t = _val; s = _val; }
inline void dvec4::qtsp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { q = _val0; t = _val1; s = _val2; p = _val3; }
inline void dvec4::qtsp(const dvec4& _val) { q = _val.s; t = _val.t; s = _val.p; p = _val.q; }
inline void dvec4::qtsp(const simddouble& _val) { q = _val; t = _val; s = _val; p = _val; }
inline void dvec4::qtp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { q = _val0; t = _val1; p = _val2; }
inline void dvec4::qtp(const dvec3& _val) { q = _val.s; t = _val.t; p = _val.p; }
inline void dvec4::qtp(const simddouble& _val) { q = _val; t = _val; p = _val; }
inline void dvec4::qtps(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { q = _val0; t = _val1; p = _val2; s = _val3; }
inline void dvec4::qtps(const dvec4& _val) { q = _val.s; t = _val.t; p = _val.p; s = _val.q; }
inline void dvec4::qtps(const simddouble& _val) { q = _val; t = _val; p = _val; s = _val; }
inline void dvec4::qp(const simddouble& _val0, const simddouble& _val1) { q = _val0; p = _val1; }
inline void dvec4::qp(const dvec2& _val) { q = _val.s; p = _val.t; }
inline void dvec4::qp(const simddouble& _val) { q = _val; p = _val; }
inline void dvec4::qps(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { q = _val0; p = _val1; s = _val2; }
inline void dvec4::qps(const dvec3& _val) { q = _val.s; p = _val.t; s = _val.p; }
inline void dvec4::qps(const simddouble& _val) { q = _val; p = _val; s = _val; }
inline void dvec4::qpst(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { q = _val0; p = _val1; s = _val2; t = _val3; }
inline void dvec4::qpst(const dvec4& _val) { q = _val.s; p = _val.t; s = _val.p; t = _val.q; }
inline void dvec4::qpst(const simddouble& _val) { q = _val; p = _val; s = _val; t = _val; }
inline void dvec4::qpt(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { q = _val0; p = _val1; t = _val2; }
inline void dvec4::qpt(const dvec3& _val) { q = _val.s; p = _val.t; t = _val.p; }
inline void dvec4::qpt(const simddouble& _val) { q = _val; p = _val; t = _val; }
inline void dvec4::qpts(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { q = _val0; p = _val1; t = _val2; s = _val3; }
inline void dvec4::qpts(const dvec4& _val) { q = _val.s; p = _val.t; t = _val.p; s = _val.q; }
inline void dvec4::qpts(const simddouble& _val) { q = _val; p = _val; t = _val; s = _val; }
inline void dvec4::sq(const simddouble& _val0, const simddouble& _val1) { s = _val0; q = _val1; }
inline void dvec4::sq(const dvec2& _val) { s = _val.s; q = _val.t; }
inline void dvec4::sq(const simddouble& _val) { s = _val; q = _val; }
inline void dvec4::sqt(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { s = _val0; q = _val1; t = _val2; }
inline void dvec4::sqt(const dvec3& _val) { s = _val.s; q = _val.t; t = _val.p; }
inline void dvec4::sqt(const simddouble& _val) { s = _val; q = _val; t = _val; }
inline void dvec4::sqtp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { s = _val0; q = _val1; t = _val2; p = _val3; }
inline void dvec4::sqtp(const dvec4& _val) { s = _val.s; q = _val.t; t = _val.p; p = _val.q; }
inline void dvec4::sqtp(const simddouble& _val) { s = _val; q = _val; t = _val; p = _val; }
inline void dvec4::sqp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { s = _val0; q = _val1; p = _val2; }
inline void dvec4::sqp(const dvec3& _val) { s = _val.s; q = _val.t; p = _val.p; }
inline void dvec4::sqp(const simddouble& _val) { s = _val; q = _val; p = _val; }
inline void dvec4::sqpt(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { s = _val0; q = _val1; p = _val2; t = _val3; }
inline void dvec4::sqpt(const dvec4& _val) { s = _val.s; q = _val.t; p = _val.p; t = _val.q; }
inline void dvec4::sqpt(const simddouble& _val) { s = _val; q = _val; p = _val; t = _val; }
inline void dvec4::st(const simddouble& _val0, const simddouble& _val1) { s = _val0; t = _val1; }
inline void dvec4::st(const dvec2& _val) { s = _val.s; t = _val.t; }
inline void dvec4::st(const simddouble& _val) { s = _val; t = _val; }
inline void dvec4::stq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { s = _val0; t = _val1; q = _val2; }
inline void dvec4::stq(const dvec3& _val) { s = _val.s; t = _val.t; q = _val.p; }
inline void dvec4::stq(const simddouble& _val) { s = _val; t = _val; q = _val; }
inline void dvec4::stqp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { s = _val0; t = _val1; q = _val2; p = _val3; }
inline void dvec4::stqp(const dvec4& _val) { s = _val.s; t = _val.t; q = _val.p; p = _val.q; }
inline void dvec4::stqp(const simddouble& _val) { s = _val; t = _val; q = _val; p = _val; }
inline void dvec4::stp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { s = _val0; t = _val1; p = _val2; }
inline void dvec4::stp(const dvec3& _val) { s = _val.s; t = _val.t; p = _val.p; }
inline void dvec4::stp(const simddouble& _val) { s = _val; t = _val; p = _val; }
inline void dvec4::stpq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { s = _val0; t = _val1; p = _val2; q = _val3; }
inline void dvec4::stpq(const dvec4& _val) { s = _val.s; t = _val.t; p = _val.p; q = _val.q; }
inline void dvec4::stpq(const simddouble& _val) { s = _val; t = _val; p = _val; q = _val; }
inline void dvec4::sp(const simddouble& _val0, const simddouble& _val1) { s = _val0; p = _val1; }
inline void dvec4::sp(const dvec2& _val) { s = _val.s; p = _val.t; }
inline void dvec4::sp(const simddouble& _val) { s = _val; p = _val; }
inline void dvec4::spq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { s = _val0; p = _val1; q = _val2; }
inline void dvec4::spq(const dvec3& _val) { s = _val.s; p = _val.t; q = _val.p; }
inline void dvec4::spq(const simddouble& _val) { s = _val; p = _val; q = _val; }
inline void dvec4::spqt(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { s = _val0; p = _val1; q = _val2; t = _val3; }
inline void dvec4::spqt(const dvec4& _val) { s = _val.s; p = _val.t; q = _val.p; t = _val.q; }
inline void dvec4::spqt(const simddouble& _val) { s = _val; p = _val; q = _val; t = _val; }
inline void dvec4::spt(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { s = _val0; p = _val1; t = _val2; }
inline void dvec4::spt(const dvec3& _val) { s = _val.s; p = _val.t; t = _val.p; }
inline void dvec4::spt(const simddouble& _val) { s = _val; p = _val; t = _val; }
inline void dvec4::sptq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { s = _val0; p = _val1; t = _val2; q = _val3; }
inline void dvec4::sptq(const dvec4& _val) { s = _val.s; p = _val.t; t = _val.p; q = _val.q; }
inline void dvec4::sptq(const simddouble& _val) { s = _val; p = _val; t = _val; q = _val; }
inline void dvec4::tq(const simddouble& _val0, const simddouble& _val1) { t = _val0; q = _val1; }
inline void dvec4::tq(const dvec2& _val) { t = _val.s; q = _val.t; }
inline void dvec4::tq(const simddouble& _val) { t = _val; q = _val; }
inline void dvec4::tqs(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { t = _val0; q = _val1; s = _val2; }
inline void dvec4::tqs(const dvec3& _val) { t = _val.s; q = _val.t; s = _val.p; }
inline void dvec4::tqs(const simddouble& _val) { t = _val; q = _val; s = _val; }
inline void dvec4::tqsp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { t = _val0; q = _val1; s = _val2; p = _val3; }
inline void dvec4::tqsp(const dvec4& _val) { t = _val.s; q = _val.t; s = _val.p; p = _val.q; }
inline void dvec4::tqsp(const simddouble& _val) { t = _val; q = _val; s = _val; p = _val; }
inline void dvec4::tqp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { t = _val0; q = _val1; p = _val2; }
inline void dvec4::tqp(const dvec3& _val) { t = _val.s; q = _val.t; p = _val.p; }
inline void dvec4::tqp(const simddouble& _val) { t = _val; q = _val; p = _val; }
inline void dvec4::tqps(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { t = _val0; q = _val1; p = _val2; s = _val3; }
inline void dvec4::tqps(const dvec4& _val) { t = _val.s; q = _val.t; p = _val.p; s = _val.q; }
inline void dvec4::tqps(const simddouble& _val) { t = _val; q = _val; p = _val; s = _val; }
inline void dvec4::ts(const simddouble& _val0, const simddouble& _val1) { t = _val0; s = _val1; }
inline void dvec4::ts(const dvec2& _val) { t = _val.s; s = _val.t; }
inline void dvec4::ts(const simddouble& _val) { t = _val; s = _val; }
inline void dvec4::tsq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { t = _val0; s = _val1; q = _val2; }
inline void dvec4::tsq(const dvec3& _val) { t = _val.s; s = _val.t; q = _val.p; }
inline void dvec4::tsq(const simddouble& _val) { t = _val; s = _val; q = _val; }
inline void dvec4::tsqp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { t = _val0; s = _val1; q = _val2; p = _val3; }
inline void dvec4::tsqp(const dvec4& _val) { t = _val.s; s = _val.t; q = _val.p; p = _val.q; }
inline void dvec4::tsqp(const simddouble& _val) { t = _val; s = _val; q = _val; p = _val; }
inline void dvec4::tsp(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { t = _val0; s = _val1; p = _val2; }
inline void dvec4::tsp(const dvec3& _val) { t = _val.s; s = _val.t; p = _val.p; }
inline void dvec4::tsp(const simddouble& _val) { t = _val; s = _val; p = _val; }
inline void dvec4::tspq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { t = _val0; s = _val1; p = _val2; q = _val3; }
inline void dvec4::tspq(const dvec4& _val) { t = _val.s; s = _val.t; p = _val.p; q = _val.q; }
inline void dvec4::tspq(const simddouble& _val) { t = _val; s = _val; p = _val; q = _val; }
inline void dvec4::tp(const simddouble& _val0, const simddouble& _val1) { t = _val0; p = _val1; }
inline void dvec4::tp(const dvec2& _val) { t = _val.s; p = _val.t; }
inline void dvec4::tp(const simddouble& _val) { t = _val; p = _val; }
inline void dvec4::tpq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { t = _val0; p = _val1; q = _val2; }
inline void dvec4::tpq(const dvec3& _val) { t = _val.s; p = _val.t; q = _val.p; }
inline void dvec4::tpq(const simddouble& _val) { t = _val; p = _val; q = _val; }
inline void dvec4::tpqs(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { t = _val0; p = _val1; q = _val2; s = _val3; }
inline void dvec4::tpqs(const dvec4& _val) { t = _val.s; p = _val.t; q = _val.p; s = _val.q; }
inline void dvec4::tpqs(const simddouble& _val) { t = _val; p = _val; q = _val; s = _val; }
inline void dvec4::tps(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { t = _val0; p = _val1; s = _val2; }
inline void dvec4::tps(const dvec3& _val) { t = _val.s; p = _val.t; s = _val.p; }
inline void dvec4::tps(const simddouble& _val) { t = _val; p = _val; s = _val; }
inline void dvec4::tpsq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { t = _val0; p = _val1; s = _val2; q = _val3; }
inline void dvec4::tpsq(const dvec4& _val) { t = _val.s; p = _val.t; s = _val.p; q = _val.q; }
inline void dvec4::tpsq(const simddouble& _val) { t = _val; p = _val; s = _val; q = _val; }
inline void dvec4::pq(const simddouble& _val0, const simddouble& _val1) { p = _val0; q = _val1; }
inline void dvec4::pq(const dvec2& _val) { p = _val.s; q = _val.t; }
inline void dvec4::pq(const simddouble& _val) { p = _val; q = _val; }
inline void dvec4::pqs(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { p = _val0; q = _val1; s = _val2; }
inline void dvec4::pqs(const dvec3& _val) { p = _val.s; q = _val.t; s = _val.p; }
inline void dvec4::pqs(const simddouble& _val) { p = _val; q = _val; s = _val; }
inline void dvec4::pqst(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { p = _val0; q = _val1; s = _val2; t = _val3; }
inline void dvec4::pqst(const dvec4& _val) { p = _val.s; q = _val.t; s = _val.p; t = _val.q; }
inline void dvec4::pqst(const simddouble& _val) { p = _val; q = _val; s = _val; t = _val; }
inline void dvec4::pqt(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { p = _val0; q = _val1; t = _val2; }
inline void dvec4::pqt(const dvec3& _val) { p = _val.s; q = _val.t; t = _val.p; }
inline void dvec4::pqt(const simddouble& _val) { p = _val; q = _val; t = _val; }
inline void dvec4::pqts(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { p = _val0; q = _val1; t = _val2; s = _val3; }
inline void dvec4::pqts(const dvec4& _val) { p = _val.s; q = _val.t; t = _val.p; s = _val.q; }
inline void dvec4::pqts(const simddouble& _val) { p = _val; q = _val; t = _val; s = _val; }
inline void dvec4::ps(const simddouble& _val0, const simddouble& _val1) { p = _val0; s = _val1; }
inline void dvec4::ps(const dvec2& _val) { p = _val.s; s = _val.t; }
inline void dvec4::ps(const simddouble& _val) { p = _val; s = _val; }
inline void dvec4::psq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { p = _val0; s = _val1; q = _val2; }
inline void dvec4::psq(const dvec3& _val) { p = _val.s; s = _val.t; q = _val.p; }
inline void dvec4::psq(const simddouble& _val) { p = _val; s = _val; q = _val; }
inline void dvec4::psqt(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { p = _val0; s = _val1; q = _val2; t = _val3; }
inline void dvec4::psqt(const dvec4& _val) { p = _val.s; s = _val.t; q = _val.p; t = _val.q; }
inline void dvec4::psqt(const simddouble& _val) { p = _val; s = _val; q = _val; t = _val; }
inline void dvec4::pst(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { p = _val0; s = _val1; t = _val2; }
inline void dvec4::pst(const dvec3& _val) { p = _val.s; s = _val.t; t = _val.p; }
inline void dvec4::pst(const simddouble& _val) { p = _val; s = _val; t = _val; }
inline void dvec4::pstq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { p = _val0; s = _val1; t = _val2; q = _val3; }
inline void dvec4::pstq(const dvec4& _val) { p = _val.s; s = _val.t; t = _val.p; q = _val.q; }
inline void dvec4::pstq(const simddouble& _val) { p = _val; s = _val; t = _val; q = _val; }
inline void dvec4::pt(const simddouble& _val0, const simddouble& _val1) { p = _val0; t = _val1; }
inline void dvec4::pt(const dvec2& _val) { p = _val.s; t = _val.t; }
inline void dvec4::pt(const simddouble& _val) { p = _val; t = _val; }
inline void dvec4::ptq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { p = _val0; t = _val1; q = _val2; }
inline void dvec4::ptq(const dvec3& _val) { p = _val.s; t = _val.t; q = _val.p; }
inline void dvec4::ptq(const simddouble& _val) { p = _val; t = _val; q = _val; }
inline void dvec4::ptqs(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { p = _val0; t = _val1; q = _val2; s = _val3; }
inline void dvec4::ptqs(const dvec4& _val) { p = _val.s; t = _val.t; q = _val.p; s = _val.q; }
inline void dvec4::ptqs(const simddouble& _val) { p = _val; t = _val; q = _val; s = _val; }
inline void dvec4::pts(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { p = _val0; t = _val1; s = _val2; }
inline void dvec4::pts(const dvec3& _val) { p = _val.s; t = _val.t; s = _val.p; }
inline void dvec4::pts(const simddouble& _val) { p = _val; t = _val; s = _val; }
inline void dvec4::ptsq(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { p = _val0; t = _val1; s = _val2; q = _val3; }
inline void dvec4::ptsq(const dvec4& _val) { p = _val.s; t = _val.t; s = _val.p; q = _val.q; }
inline void dvec4::ptsq(const simddouble& _val) { p = _val; t = _val; s = _val; q = _val; }
inline void dvec4::wx(const simddouble& _val0, const simddouble& _val1) { w = _val0; x = _val1; }
inline void dvec4::wx(const dvec2& _val) { w = _val.x; x = _val.y; }
inline void dvec4::wx(const simddouble& _val) { w = _val; x = _val; }
inline void dvec4::wxy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { w = _val0; x = _val1; y = _val2; }
inline void dvec4::wxy(const dvec3& _val) { w = _val.x; x = _val.y; y = _val.z; }
inline void dvec4::wxy(const simddouble& _val) { w = _val; x = _val; y = _val; }
inline void dvec4::wxyz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { w = _val0; x = _val1; y = _val2; z = _val3; }
inline void dvec4::wxyz(const dvec4& _val) { w = _val.x; x = _val.y; y = _val.z; z = _val.w; }
inline void dvec4::wxyz(const simddouble& _val) { w = _val; x = _val; y = _val; z = _val; }
inline void dvec4::wxz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { w = _val0; x = _val1; z = _val2; }
inline void dvec4::wxz(const dvec3& _val) { w = _val.x; x = _val.y; z = _val.z; }
inline void dvec4::wxz(const simddouble& _val) { w = _val; x = _val; z = _val; }
inline void dvec4::wxzy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { w = _val0; x = _val1; z = _val2; y = _val3; }
inline void dvec4::wxzy(const dvec4& _val) { w = _val.x; x = _val.y; z = _val.z; y = _val.w; }
inline void dvec4::wxzy(const simddouble& _val) { w = _val; x = _val; z = _val; y = _val; }
inline void dvec4::wy(const simddouble& _val0, const simddouble& _val1) { w = _val0; y = _val1; }
inline void dvec4::wy(const dvec2& _val) { w = _val.x; y = _val.y; }
inline void dvec4::wy(const simddouble& _val) { w = _val; y = _val; }
inline void dvec4::wyx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { w = _val0; y = _val1; x = _val2; }
inline void dvec4::wyx(const dvec3& _val) { w = _val.x; y = _val.y; x = _val.z; }
inline void dvec4::wyx(const simddouble& _val) { w = _val; y = _val; x = _val; }
inline void dvec4::wyxz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { w = _val0; y = _val1; x = _val2; z = _val3; }
inline void dvec4::wyxz(const dvec4& _val) { w = _val.x; y = _val.y; x = _val.z; z = _val.w; }
inline void dvec4::wyxz(const simddouble& _val) { w = _val; y = _val; x = _val; z = _val; }
inline void dvec4::wyz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { w = _val0; y = _val1; z = _val2; }
inline void dvec4::wyz(const dvec3& _val) { w = _val.x; y = _val.y; z = _val.z; }
inline void dvec4::wyz(const simddouble& _val) { w = _val; y = _val; z = _val; }
inline void dvec4::wyzx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { w = _val0; y = _val1; z = _val2; x = _val3; }
inline void dvec4::wyzx(const dvec4& _val) { w = _val.x; y = _val.y; z = _val.z; x = _val.w; }
inline void dvec4::wyzx(const simddouble& _val) { w = _val; y = _val; z = _val; x = _val; }
inline void dvec4::wz(const simddouble& _val0, const simddouble& _val1) { w = _val0; z = _val1; }
inline void dvec4::wz(const dvec2& _val) { w = _val.x; z = _val.y; }
inline void dvec4::wz(const simddouble& _val) { w = _val; z = _val; }
inline void dvec4::wzx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { w = _val0; z = _val1; x = _val2; }
inline void dvec4::wzx(const dvec3& _val) { w = _val.x; z = _val.y; x = _val.z; }
inline void dvec4::wzx(const simddouble& _val) { w = _val; z = _val; x = _val; }
inline void dvec4::wzxy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { w = _val0; z = _val1; x = _val2; y = _val3; }
inline void dvec4::wzxy(const dvec4& _val) { w = _val.x; z = _val.y; x = _val.z; y = _val.w; }
inline void dvec4::wzxy(const simddouble& _val) { w = _val; z = _val; x = _val; y = _val; }
inline void dvec4::wzy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { w = _val0; z = _val1; y = _val2; }
inline void dvec4::wzy(const dvec3& _val) { w = _val.x; z = _val.y; y = _val.z; }
inline void dvec4::wzy(const simddouble& _val) { w = _val; z = _val; y = _val; }
inline void dvec4::wzyx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { w = _val0; z = _val1; y = _val2; x = _val3; }
inline void dvec4::wzyx(const dvec4& _val) { w = _val.x; z = _val.y; y = _val.z; x = _val.w; }
inline void dvec4::wzyx(const simddouble& _val) { w = _val; z = _val; y = _val; x = _val; }
inline void dvec4::xw(const simddouble& _val0, const simddouble& _val1) { x = _val0; w = _val1; }
inline void dvec4::xw(const dvec2& _val) { x = _val.x; w = _val.y; }
inline void dvec4::xw(const simddouble& _val) { x = _val; w = _val; }
inline void dvec4::xwy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { x = _val0; w = _val1; y = _val2; }
inline void dvec4::xwy(const dvec3& _val) { x = _val.x; w = _val.y; y = _val.z; }
inline void dvec4::xwy(const simddouble& _val) { x = _val; w = _val; y = _val; }
inline void dvec4::xwyz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { x = _val0; w = _val1; y = _val2; z = _val3; }
inline void dvec4::xwyz(const dvec4& _val) { x = _val.x; w = _val.y; y = _val.z; z = _val.w; }
inline void dvec4::xwyz(const simddouble& _val) { x = _val; w = _val; y = _val; z = _val; }
inline void dvec4::xwz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { x = _val0; w = _val1; z = _val2; }
inline void dvec4::xwz(const dvec3& _val) { x = _val.x; w = _val.y; z = _val.z; }
inline void dvec4::xwz(const simddouble& _val) { x = _val; w = _val; z = _val; }
inline void dvec4::xwzy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { x = _val0; w = _val1; z = _val2; y = _val3; }
inline void dvec4::xwzy(const dvec4& _val) { x = _val.x; w = _val.y; z = _val.z; y = _val.w; }
inline void dvec4::xwzy(const simddouble& _val) { x = _val; w = _val; z = _val; y = _val; }
inline void dvec4::xy(const simddouble& _val0, const simddouble& _val1) { x = _val0; y = _val1; }
inline void dvec4::xy(const dvec2& _val) { x = _val.x; y = _val.y; }
inline void dvec4::xy(const simddouble& _val) { x = _val; y = _val; }
inline void dvec4::xyw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { x = _val0; y = _val1; w = _val2; }
inline void dvec4::xyw(const dvec3& _val) { x = _val.x; y = _val.y; w = _val.z; }
inline void dvec4::xyw(const simddouble& _val) { x = _val; y = _val; w = _val; }
inline void dvec4::xywz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { x = _val0; y = _val1; w = _val2; z = _val3; }
inline void dvec4::xywz(const dvec4& _val) { x = _val.x; y = _val.y; w = _val.z; z = _val.w; }
inline void dvec4::xywz(const simddouble& _val) { x = _val; y = _val; w = _val; z = _val; }
inline void dvec4::xyz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { x = _val0; y = _val1; z = _val2; }
inline void dvec4::xyz(const dvec3& _val) { x = _val.x; y = _val.y; z = _val.z; }
inline void dvec4::xyz(const simddouble& _val) { x = _val; y = _val; z = _val; }
inline void dvec4::xyzw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { x = _val0; y = _val1; z = _val2; w = _val3; }
inline void dvec4::xyzw(const dvec4& _val) { x = _val.x; y = _val.y; z = _val.z; w = _val.w; }
inline void dvec4::xyzw(const simddouble& _val) { x = _val; y = _val; z = _val; w = _val; }
inline void dvec4::xz(const simddouble& _val0, const simddouble& _val1) { x = _val0; z = _val1; }
inline void dvec4::xz(const dvec2& _val) { x = _val.x; z = _val.y; }
inline void dvec4::xz(const simddouble& _val) { x = _val; z = _val; }
inline void dvec4::xzw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { x = _val0; z = _val1; w = _val2; }
inline void dvec4::xzw(const dvec3& _val) { x = _val.x; z = _val.y; w = _val.z; }
inline void dvec4::xzw(const simddouble& _val) { x = _val; z = _val; w = _val; }
inline void dvec4::xzwy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { x = _val0; z = _val1; w = _val2; y = _val3; }
inline void dvec4::xzwy(const dvec4& _val) { x = _val.x; z = _val.y; w = _val.z; y = _val.w; }
inline void dvec4::xzwy(const simddouble& _val) { x = _val; z = _val; w = _val; y = _val; }
inline void dvec4::xzy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { x = _val0; z = _val1; y = _val2; }
inline void dvec4::xzy(const dvec3& _val) { x = _val.x; z = _val.y; y = _val.z; }
inline void dvec4::xzy(const simddouble& _val) { x = _val; z = _val; y = _val; }
inline void dvec4::xzyw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { x = _val0; z = _val1; y = _val2; w = _val3; }
inline void dvec4::xzyw(const dvec4& _val) { x = _val.x; z = _val.y; y = _val.z; w = _val.w; }
inline void dvec4::xzyw(const simddouble& _val) { x = _val; z = _val; y = _val; w = _val; }
inline void dvec4::yw(const simddouble& _val0, const simddouble& _val1) { y = _val0; w = _val1; }
inline void dvec4::yw(const dvec2& _val) { y = _val.x; w = _val.y; }
inline void dvec4::yw(const simddouble& _val) { y = _val; w = _val; }
inline void dvec4::ywx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { y = _val0; w = _val1; x = _val2; }
inline void dvec4::ywx(const dvec3& _val) { y = _val.x; w = _val.y; x = _val.z; }
inline void dvec4::ywx(const simddouble& _val) { y = _val; w = _val; x = _val; }
inline void dvec4::ywxz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { y = _val0; w = _val1; x = _val2; z = _val3; }
inline void dvec4::ywxz(const dvec4& _val) { y = _val.x; w = _val.y; x = _val.z; z = _val.w; }
inline void dvec4::ywxz(const simddouble& _val) { y = _val; w = _val; x = _val; z = _val; }
inline void dvec4::ywz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { y = _val0; w = _val1; z = _val2; }
inline void dvec4::ywz(const dvec3& _val) { y = _val.x; w = _val.y; z = _val.z; }
inline void dvec4::ywz(const simddouble& _val) { y = _val; w = _val; z = _val; }
inline void dvec4::ywzx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { y = _val0; w = _val1; z = _val2; x = _val3; }
inline void dvec4::ywzx(const dvec4& _val) { y = _val.x; w = _val.y; z = _val.z; x = _val.w; }
inline void dvec4::ywzx(const simddouble& _val) { y = _val; w = _val; z = _val; x = _val; }
inline void dvec4::yx(const simddouble& _val0, const simddouble& _val1) { y = _val0; x = _val1; }
inline void dvec4::yx(const dvec2& _val) { y = _val.x; x = _val.y; }
inline void dvec4::yx(const simddouble& _val) { y = _val; x = _val; }
inline void dvec4::yxw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { y = _val0; x = _val1; w = _val2; }
inline void dvec4::yxw(const dvec3& _val) { y = _val.x; x = _val.y; w = _val.z; }
inline void dvec4::yxw(const simddouble& _val) { y = _val; x = _val; w = _val; }
inline void dvec4::yxwz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { y = _val0; x = _val1; w = _val2; z = _val3; }
inline void dvec4::yxwz(const dvec4& _val) { y = _val.x; x = _val.y; w = _val.z; z = _val.w; }
inline void dvec4::yxwz(const simddouble& _val) { y = _val; x = _val; w = _val; z = _val; }
inline void dvec4::yxz(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { y = _val0; x = _val1; z = _val2; }
inline void dvec4::yxz(const dvec3& _val) { y = _val.x; x = _val.y; z = _val.z; }
inline void dvec4::yxz(const simddouble& _val) { y = _val; x = _val; z = _val; }
inline void dvec4::yxzw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { y = _val0; x = _val1; z = _val2; w = _val3; }
inline void dvec4::yxzw(const dvec4& _val) { y = _val.x; x = _val.y; z = _val.z; w = _val.w; }
inline void dvec4::yxzw(const simddouble& _val) { y = _val; x = _val; z = _val; w = _val; }
inline void dvec4::yz(const simddouble& _val0, const simddouble& _val1) { y = _val0; z = _val1; }
inline void dvec4::yz(const dvec2& _val) { y = _val.x; z = _val.y; }
inline void dvec4::yz(const simddouble& _val) { y = _val; z = _val; }
inline void dvec4::yzw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { y = _val0; z = _val1; w = _val2; }
inline void dvec4::yzw(const dvec3& _val) { y = _val.x; z = _val.y; w = _val.z; }
inline void dvec4::yzw(const simddouble& _val) { y = _val; z = _val; w = _val; }
inline void dvec4::yzwx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { y = _val0; z = _val1; w = _val2; x = _val3; }
inline void dvec4::yzwx(const dvec4& _val) { y = _val.x; z = _val.y; w = _val.z; x = _val.w; }
inline void dvec4::yzwx(const simddouble& _val) { y = _val; z = _val; w = _val; x = _val; }
inline void dvec4::yzx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { y = _val0; z = _val1; x = _val2; }
inline void dvec4::yzx(const dvec3& _val) { y = _val.x; z = _val.y; x = _val.z; }
inline void dvec4::yzx(const simddouble& _val) { y = _val; z = _val; x = _val; }
inline void dvec4::yzxw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { y = _val0; z = _val1; x = _val2; w = _val3; }
inline void dvec4::yzxw(const dvec4& _val) { y = _val.x; z = _val.y; x = _val.z; w = _val.w; }
inline void dvec4::yzxw(const simddouble& _val) { y = _val; z = _val; x = _val; w = _val; }
inline void dvec4::zw(const simddouble& _val0, const simddouble& _val1) { z = _val0; w = _val1; }
inline void dvec4::zw(const dvec2& _val) { z = _val.x; w = _val.y; }
inline void dvec4::zw(const simddouble& _val) { z = _val; w = _val; }
inline void dvec4::zwx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { z = _val0; w = _val1; x = _val2; }
inline void dvec4::zwx(const dvec3& _val) { z = _val.x; w = _val.y; x = _val.z; }
inline void dvec4::zwx(const simddouble& _val) { z = _val; w = _val; x = _val; }
inline void dvec4::zwxy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { z = _val0; w = _val1; x = _val2; y = _val3; }
inline void dvec4::zwxy(const dvec4& _val) { z = _val.x; w = _val.y; x = _val.z; y = _val.w; }
inline void dvec4::zwxy(const simddouble& _val) { z = _val; w = _val; x = _val; y = _val; }
inline void dvec4::zwy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { z = _val0; w = _val1; y = _val2; }
inline void dvec4::zwy(const dvec3& _val) { z = _val.x; w = _val.y; y = _val.z; }
inline void dvec4::zwy(const simddouble& _val) { z = _val; w = _val; y = _val; }
inline void dvec4::zwyx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { z = _val0; w = _val1; y = _val2; x = _val3; }
inline void dvec4::zwyx(const dvec4& _val) { z = _val.x; w = _val.y; y = _val.z; x = _val.w; }
inline void dvec4::zwyx(const simddouble& _val) { z = _val; w = _val; y = _val; x = _val; }
inline void dvec4::zx(const simddouble& _val0, const simddouble& _val1) { z = _val0; x = _val1; }
inline void dvec4::zx(const dvec2& _val) { z = _val.x; x = _val.y; }
inline void dvec4::zx(const simddouble& _val) { z = _val; x = _val; }
inline void dvec4::zxw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { z = _val0; x = _val1; w = _val2; }
inline void dvec4::zxw(const dvec3& _val) { z = _val.x; x = _val.y; w = _val.z; }
inline void dvec4::zxw(const simddouble& _val) { z = _val; x = _val; w = _val; }
inline void dvec4::zxwy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { z = _val0; x = _val1; w = _val2; y = _val3; }
inline void dvec4::zxwy(const dvec4& _val) { z = _val.x; x = _val.y; w = _val.z; y = _val.w; }
inline void dvec4::zxwy(const simddouble& _val) { z = _val; x = _val; w = _val; y = _val; }
inline void dvec4::zxy(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { z = _val0; x = _val1; y = _val2; }
inline void dvec4::zxy(const dvec3& _val) { z = _val.x; x = _val.y; y = _val.z; }
inline void dvec4::zxy(const simddouble& _val) { z = _val; x = _val; y = _val; }
inline void dvec4::zxyw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { z = _val0; x = _val1; y = _val2; w = _val3; }
inline void dvec4::zxyw(const dvec4& _val) { z = _val.x; x = _val.y; y = _val.z; w = _val.w; }
inline void dvec4::zxyw(const simddouble& _val) { z = _val; x = _val; y = _val; w = _val; }
inline void dvec4::zy(const simddouble& _val0, const simddouble& _val1) { z = _val0; y = _val1; }
inline void dvec4::zy(const dvec2& _val) { z = _val.x; y = _val.y; }
inline void dvec4::zy(const simddouble& _val) { z = _val; y = _val; }
inline void dvec4::zyw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { z = _val0; y = _val1; w = _val2; }
inline void dvec4::zyw(const dvec3& _val) { z = _val.x; y = _val.y; w = _val.z; }
inline void dvec4::zyw(const simddouble& _val) { z = _val; y = _val; w = _val; }
inline void dvec4::zywx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { z = _val0; y = _val1; w = _val2; x = _val3; }
inline void dvec4::zywx(const dvec4& _val) { z = _val.x; y = _val.y; w = _val.z; x = _val.w; }
inline void dvec4::zywx(const simddouble& _val) { z = _val; y = _val; w = _val; x = _val; }
inline void dvec4::zyx(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2) { z = _val0; y = _val1; x = _val2; }
inline void dvec4::zyx(const dvec3& _val) { z = _val.x; y = _val.y; x = _val.z; }
inline void dvec4::zyx(const simddouble& _val) { z = _val; y = _val; x = _val; }
inline void dvec4::zyxw(const simddouble& _val0, const simddouble& _val1, const simddouble& _val2, const simddouble& _val3) { z = _val0; y = _val1; x = _val2; w = _val3; }
inline void dvec4::zyxw(const dvec4& _val) { z = _val.x; y = _val.y; x = _val.z; w = _val.w; }
inline void dvec4::zyxw(const simddouble& _val) { z = _val; y = _val; x = _val; w = _val; }

#pragma endregion


// constructors for dvec4
inline dvec4::dvec4(const double& _f) { x = _f; y = _f; z = _f; w = _f; }

inline dvec4::dvec4(const simddouble& _f) { x = _f; y = _f; z = _f; w = _f; }

inline dvec4::dvec4(const simddouble& _x, const simddouble& _y, const simddouble& _z, const simddouble& _w) { x = _x; y = _y; z = _z; w = _w; }

inline dvec4::dvec4(const simddouble& _x, const dvec2& _y, const simddouble& _w) { x = _x; y = _y.x; z = _y.y; w = _w; }

inline dvec4::dvec4(const simddouble& _x, const simddouble& _y, const dvec2& _z) { x = _x; y = _y; z = _z.x; w = _z.y; }

inline dvec4::dvec4(const dvec2& _x, const simddouble& _z, const simddouble& _w) { x = _x.x; y = _x.y; z = _z; w = _w; }

inline dvec4::dvec4(const dvec3& _x, const simddouble& _w) { x = _x.x; y = _x.y; z = _x.z; w = _w; }

inline dvec4::dvec4(const simddouble& _x, const dvec3& _y) { x = _x; y = _y.x; z = _y.y; w = _y.z; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec4>, int>>
dvec4::dvec4(const simddouble& _x, const V& _v) { x = _x; y = _v.x; z = _v.y; w = _v.z; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec3>, int>>
dvec4::dvec4(const simddouble& _x, const simddouble& _y, const V& _v) { x = _x; y = _y; z = _v.x; w = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec4>, int>>
dvec4::dvec4(const simddouble& _x, const simddouble& _y, const V& _v) { x = _x; y = _y; z = _v.x; w = _v.y; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec2>, int>>
dvec4::dvec4(const simddouble& _x, const simddouble& _y, const simddouble& _z, const V& _v) { x = _x; y = _y; z = _z; w = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec3>, int>>
dvec4::dvec4(const simddouble& _x, const simddouble& _y, const simddouble& _z, const V& _v) { x = _x; y = _y; z = _z; w = _v.x; }

template<typename V, std::enable_if_t<std::is_same_v<V, dvec4>, int>>
dvec4::dvec4(const simddouble& _x, const simddouble& _y, const simddouble& _z, const V& _v) { x = _x; y = _y; z = _z; w = _v.x; }

#endif



