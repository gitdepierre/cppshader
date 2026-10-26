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

#ifndef SIMD_DEFINITIONS
#define SIMD_DEFINITIONS

// uncomment or define one of those to choose your SIMD backend
//#define USE_NEON			// 4 lanes (4 floats/ints, 2 doubles), requires ARM NEON (available on Apple Silicon)
//#define USE_AVX512		// 16 lanes (16 floats/ints, 8 doubles), requires AVX512F
//#define USE_AVX2			// 8 lanes (8 floats/ints, 4 doubles), requires AVX2
//#define USE_SSE41			// 4 lanes (4 floats/ints, 2 doubles), requires SSE4.1
//#define USE_SSE			// 4 lanes (4 floats/ints, 2 doubles), requires SSE. Slower multiplications, max, min, blendv, round, trunc, floor, and ceil.
//#define USE_PACKED_SCALAR // no intrinsic, but 4 packed floats/ints or 2 doubles.
//#define USE_SCALAR		// no intrinsic. No packing. Not really useful except for debugging purpose

// USE_PACKED_SCALAR defined by default
#if !defined(USE_NEON) && !defined(USE_AVX512) && !defined(USE_AVX2) && !defined(USE_SSE41) && !defined(USE_SSE) && !defined(USE_PACKED_SCALAR) && !defined(USE_SCALAR)
#define USE_PACKED_SCALAR
#endif

#include <iostream>
#include <cmath>
#include <functional>
#include <type_traits>

#if !defined(USE_SCALAR) && !defined(USE_PACKED_SCALAR)
#if defined(_WIN32) || defined(_WIN64)
// Windows (x86/x64)
#include <immintrin.h>
#elif defined(__linux__)
// Linux
#if defined(__x86_64__) || defined(__i386__)
#include <immintrin.h>
#elif defined(__aarch64__) || defined(__arm__)
#include <arm_neon.h>
#endif
#elif defined(__APPLE__)
// macOS (or iOS)
#include <TargetConditionals.h>
#if defined(__x86_64__) || defined(__i386__)
// macOS on Intel
#include <immintrin.h>
#elif defined(__aarch64__) || defined(__arm64__)
// macOS on Apple Silicon
#include <arm_neon.h>
#else
#error "Unsupported Apple architecture"
#endif
#else
#error "Unsupported platform"
#endif
#endif // !USE_SCALAR && !USE_PACKED_SCALAR

#ifdef USE_AVX512
#define SIMDWIDTH 16
#define HALFSIMDWIDTH 8
#define simdfloat_internal __m512
#define simddouble_internal __m512d
#define simdint_internal __m512i

// float functions
#define simd_set1_float _mm512_set1_ps
#define simd_toint_float _mm512_cvtps_epi32
#define simd_add_float _mm512_add_ps
#define simd_sub_float _mm512_sub_ps
#define simd_mul_float _mm512_mul_ps
#define simd_div_float _mm512_div_ps
#define simd_cmp_float _mm512_cmp_ps_mask
#define simd_store_float _mm512_store_ps
#define simd_load_float _mm512_load_ps
#define simd_and_float _mm512_and_ps
#define simd_or_float _mm512_or_ps
#define simd_andnot_float _mm512_andnot_ps
#define simd_castsi_float _mm512_castsi512_ps
#define simd_set1_int _mm512_set1_epi32
#define simd_acos_float _mm512_acos_ps
#define simd_acosh_float _mm512_acosh_ps
#define simd_asin_float _mm512_asin_ps
#define simd_asinh_float _mm512_asinh_ps
#define simd_atan_float _mm512_atan_ps
#define simd_atan2_float _mm512_atan2_ps
#define simd_atanh_float _mm512_atanh_ps
#define simd_ceil_float _mm512_ceil_ps
#define simd_cos_float _mm512_cos_ps
#define simd_cosh_float _mm512_cosh_ps
#define simd_exp_float _mm512_exp_ps
#define simd_exp2_float _mm512_exp2_ps
#define simd_floor_float _mm512_floor_ps
#define simd_fma_float _mm512_fmadd_ps
#define simd_log_float _mm512_log_ps
#define simd_log2_float _mm512_log2_ps
#define simd_max_float _mm512_max_ps
#define simd_min_float _mm512_min_ps
#define simd_mod_float _mm512_fmod_ps
#define simd_pow_float _mm512_pow_ps
#define simd_sin_float _mm512_sin_ps
#define simd_sinh_float _mm512_sinh_ps
#define simd_sqrt_float _mm512_sqrt_ps
#define simd_tan_float _mm512_tan_ps
#define simd_tanh_float _mm512_tanh_ps

// double functions
#define simd_set1_double _mm512_set1_pd
#define simd_add_double _mm512_add_pd
#define simd_sub_double _mm512_sub_pd
#define simd_mul_double _mm512_mul_pd
#define simd_div_double _mm512_div_pd
#define simd_cmp_double _mm512_cmp_pd_mask
#define simd_store_double _mm512_store_pd
#define simd_load_double _mm512_load_pd
#define simd_and_double _mm512_and_pd
#define simd_or_double _mm512_or_pd
#define simd_andnot_double _mm512_andnot_pd
#define simd_castsi_double _mm512_castsi512_pd
#define simd_set1_int _mm512_set1_epi32
#define simd_acos_double _mm512_acos_pd
#define simd_acosh_double _mm512_acosh_pd
#define simd_asin_double _mm512_asin_pd
#define simd_asinh_double _mm512_asinh_pd
#define simd_atan_double _mm512_atan_pd
#define simd_atan2_double _mm512_atan2_pd
#define simd_atanh_double _mm512_atanh_pd
#define simd_ceil_double _mm512_ceil_pd
#define simd_cos_double _mm512_cos_pd
#define simd_cosh_double _mm512_cosh_pd
#define simd_exp_double _mm512_exp_pd
#define simd_exp2_double _mm512_exp2_pd
#define simd_floor_double _mm512_floor_pd
#define simd_fma_double _mm512_fmadd_pd
#define simd_log_double _mm512_log_pd
#define simd_log2_double _mm512_log2_pd
#define simd_max_double _mm512_max_pd
#define simd_min_double _mm512_min_pd
#define simd_mod_double _mm512_fmod_pd
#define simd_pow_double _mm512_pow_pd
#define simd_sin_double _mm512_sin_pd
#define simd_sinh_double _mm512_sinh_pd
#define simd_sqrt_double _mm512_sqrt_pd
#define simd_tan_double _mm512_tan_pd
#define simd_tanh_double _mm512_tanh_pd

// integer functions
#define simd_set1_int _mm512_set1_epi32
#define simd_tofloat_int _mm512_cvtepi32_ps
#define simd_add_int _mm512_add_epi32
#define simd_sub_int _mm512_sub_epi32
#define simd_mul_int _mm512_mullo_epi32
#define simd_min_int _mm512_min_epi32
#define simd_max_int _mm512_max_epi32
#define simd_abs_int _mm512_abs_epi32
#define simd_cvtps_int _mm512_cvtps_epi32
#define simd_cvtepi32_float _mm512_cvtepi32_ps
#define simd_and_si512 _mm512_and_si512
#define simd_i32gather_float _mm512_i32gather_ps
#define simd_castps_si _mm512_castps_si512
#define simd_and_int _mm512_and_si512
#define simd_or_int _mm512_or_si512
#define simd_xor_int _mm512_xor_si512
#define simd_andnot_int _mm512_andnot_si512
#define simd_slli_int _mm512_slli_epi32
#define simd_srli_int _mm512_srli_epi32
#define simd_srai_int _mm512_srai_epi32
#define simd_cmpeq_int _mm512_cmpeq_epi32_mask
#define simd_cmplt_int _mm512_cmplt_epi32_mask
#define simd_cmpgt_int _mm512_cmpgt_epi32_mask
#define simd_load_int avx512_load_int
#define simd_store_int avx512_store_int
#define simd_abs_int _mm512_abs_epi32

inline const void avx512_store_int(int32_t* _ptr, __m512i _value) { _mm512_store_si512(reinterpret_cast<__m512i*>(_ptr), _value); }
inline __m512i avx512_load_int(const int32_t* _ptr) { return _mm512_load_si512(reinterpret_cast<const __m512i*>(_ptr)); }

struct simdmask
{
	__mmask16 value;

	simdmask() : value(0) {}
	simdmask(const __mmask16& _m) : value(_m) {}
	simdmask(const int32_t& _i) : value(static_cast<__mmask16>(_i)) {}
	simdmask(const float& _f) : value(static_cast<__mmask16>(_f)) {}
	simdmask(const double& _d) : value(static_cast<__mmask16>(_d)) {}

	simdmask& operator=(const __mmask16& _m) { value = _m; return *this; }
	simdmask& operator=(const int32_t& _i) { value = static_cast<__mmask16>(_i); return *this; }

	operator __mmask16() const { return value; }
};

struct simddmask
{
	__mmask8 value;

	simddmask() : value(0) {}
	simddmask(const __mmask8& _m) : value(_m) {}
	simddmask(const int32_t& _i) : value(static_cast<__mmask8>(_i)) {}
	simddmask(const float& _f) : value(static_cast<__mmask8>(_f)) {}
	simddmask(const double& _d) : value(static_cast<__mmask8>(_d)) {}

	simddmask& operator=(const __mmask8& _m) { value = _m; return *this; }
	simddmask& operator=(const int32_t& _i) { value = static_cast<__mmask8>(_i); return *this; }

	operator __mmask8() const { return value; }
};

struct simdimask
{
	__mmask16 value;

	simdimask() : value(0) {}
	simdimask(const __mmask16& _m) : value(_m) {}
	simdimask(const int32_t& _i) : value(static_cast<__mmask16>(_i)) {}
	simdimask(const float& _f) : value(static_cast<__mmask16>(_f)) {}
	simdimask(const double& _d) : value(static_cast<__mmask16>(_d)) {}
	simdimask& operator=(const __mmask16& _m) { value = _m; return *this; }
	simdimask& operator=(const int32_t& _i) { value = static_cast<__mmask16>(_i); return *this; }

	operator __mmask16() const { return value; }
};

#elif defined(USE_AVX2)

#define SIMDWIDTH 8
#define HALFSIMDWIDTH 4
#define simdfloat_internal __m256
#define simddouble_internal __m256d
#define simdint_internal __m256i
#define simdmask_internal __m256
#define simddmask_internal __m256d
#define simdimask_internal __m256i

// float functions
#define simd_set1_float _mm256_set1_ps
#define simd_toint_float _mm256_cvtps_epi32
#define simd_add_float _mm256_add_ps
#define simd_sub_float _mm256_sub_ps
#define simd_mul_float _mm256_mul_ps
#define simd_div_float _mm256_div_ps
#define simd_cmp_float _mm256_cmp_ps
#define simd_blendv_float _mm256_blendv_ps
#define simd_store_float _mm256_store_ps
#define simd_load_float _mm256_load_ps
#define simd_and_float _mm256_and_ps
#define simd_or_float _mm256_or_ps
#define simd_andnot_float _mm256_andnot_ps
#define simd_movemask_float _mm256_movemask_ps
#define simd_castsi_float _mm256_castsi256_ps
#define simd_set1_int _mm256_set1_epi32
#define simd_acos_float _mm256_acos_ps
#define simd_acosh_float _mm256_acosh_ps
#define simd_asin_float _mm256_asin_ps
#define simd_asinh_float _mm256_asinh_ps
#define simd_atan_float _mm256_atan_ps
#define simd_atan2_float _mm256_atan2_ps
#define simd_atanh_float _mm256_atanh_ps
#define simd_ceil_float _mm256_ceil_ps
#define simd_cos_float _mm256_cos_ps
#define simd_cosh_float _mm256_cosh_ps
#define simd_exp_float _mm256_exp_ps
#define simd_exp2_float _mm256_exp2_ps
#define simd_floor_float _mm256_floor_ps
#define simd_fma_float _mm256_fmadd_ps
#define simd_rsqrt_float _mm256_rsqrt_ps
#define simd_log_float _mm256_log_ps
#define simd_log2_float _mm256_log2_ps
#define simd_max_float _mm256_max_ps
#define simd_min_float _mm256_min_ps
#define simd_mod_float _mm256_fmod_ps
#define simd_pow_float _mm256_pow_ps
#define simd_round_float _mm256_round_ps
#define simd_sin_float _mm256_sin_ps
#define simd_sinh_float _mm256_sinh_ps
#define simd_sqrt_float _mm256_sqrt_ps
#define simd_tan_float _mm256_tan_ps
#define simd_tanh_float _mm256_tanh_ps

// double functions
#define simd_set1_double _mm256_set1_pd
#define simd_add_double _mm256_add_pd
#define simd_sub_double _mm256_sub_pd
#define simd_mul_double _mm256_mul_pd
#define simd_div_double _mm256_div_pd
#define simd_cmp_double _mm256_cmp_pd
#define simd_blendv_double _mm256_blendv_pd
#define simd_store_double _mm256_store_pd
#define simd_load_double _mm256_load_pd
#define simd_and_double _mm256_and_pd
#define simd_or_double _mm256_or_pd
#define simd_andnot_double _mm256_andnot_pd
#define simd_movemask_double _mm256_movemask_pd
#define simd_castsi_double _mm256_castsi256_pd
#define simd_set1_int _mm256_set1_epi32
#define simd_acos_double _mm256_acos_pd
#define simd_acosh_double _mm256_acosh_pd
#define simd_asin_double _mm256_asin_pd
#define simd_asinh_double _mm256_asinh_pd
#define simd_atan_double _mm256_atan_pd
#define simd_atan2_double _mm256_atan2_pd
#define simd_atanh_double _mm256_atanh_pd
#define simd_ceil_double _mm256_ceil_pd
#define simd_cos_double _mm256_cos_pd
#define simd_cosh_double _mm256_cosh_pd
#define simd_exp_double _mm256_exp_pd
#define simd_exp2_double _mm256_exp2_pd
#define simd_floor_double _mm256_floor_pd
#define simd_fma_double _mm256_fmadd_pd
#define simd_log_double _mm256_log_pd
#define simd_log2_double _mm256_log2_pd
#define simd_max_double _mm256_max_pd
#define simd_min_double _mm256_min_pd
#define simd_mod_double _mm256_fmod_pd
#define simd_pow_double _mm256_pow_pd
#define simd_round_double _mm256_round_pd
#define simd_sin_double _mm256_sin_pd
#define simd_sinh_double _mm256_sinh_pd
#define simd_sqrt_double _mm256_sqrt_pd
#define simd_tan_double _mm256_tan_pd
#define simd_tanh_double _mm256_tanh_pd

// integer functions
#define simd_tofloat_int _mm256_cvtepi32_ps
#define simd_set1_int _mm256_set1_epi32
#define simd_add_int _mm256_add_epi32
#define simd_sub_int _mm256_sub_epi32
#define simd_mul_int _mm256_mullo_epi32
#define simd_min_int _mm256_min_epi32
#define simd_max_int _mm256_max_epi32
#define simd_blendv_int _mm256_blendv_epi8
#define simd_abs_int _mm256_abs_epi32
#define simd_cvtps_int _mm256_cvtps_epi32
#define simd_and_si256 _mm256_and_si256
#define simd_i32gather_float _mm256_i32gather_ps
#define simd_castps_si _mm256_castps_si256
#define simd_and_int _mm256_and_si256
#define simd_or_int _mm256_or_si256
#define simd_xor_int _mm256_xor_si256
#define simd_andnot_int _mm256_andnot_si256
#define simd_slli_int _mm256_slli_epi32
#define simd_srli_int _mm256_srli_epi32
#define simd_srai_int _mm256_srai_epi32
#define simd_cmpeq_int _mm256_cmpeq_epi32
#define simd_cmpgt_int _mm256_cmpgt_epi32
#define simd_load_int avx_load_int
#define simd_store_int avx_store_int
#define simd_abs_int _mm256_abs_epi32
#define simd_movemask_epi8 _mm256_movemask_epi8

inline const void avx_store_int(int32_t* _ptr, __m256i _value) { _mm256_store_si256((__m256i*)_ptr, _value); }
inline __m256i avx_load_int(const int32_t* _ptr) { return _mm256_load_si256((__m256i*)_ptr); }

#elif defined(USE_SSE) || defined (USE_SSE41)
#define simdfloat_internal __m128
#define simddouble_internal __m128d
#define simdint_internal __m128i
#define simdmask_internal __m128
#define simddmask_internal __m128d
#define simdimask_internal __m128i
#define SIMDWIDTH 4
#define HALFSIMDWIDTH 2

// float functions
#define simd_set1_float _mm_set1_ps
#define simd_toint_float _mm_cvtps_epi32
#define simd_add_float _mm_add_ps
#define simd_sub_float _mm_sub_ps
#define simd_mul_float _mm_mul_ps
#define simd_div_float _mm_div_ps
#define simd_cmp_float sse_cmp_float
#define simd_store_float _mm_store_ps
#define simd_load_float _mm_load_ps
#define simd_and_float _mm_and_ps
#define simd_or_float _mm_or_ps
#define simd_andnot_float _mm_andnot_ps
#define simd_movemask_float _mm_movemask_ps
#define simd_castsi_float _mm_castsi128_ps
#define simd_set1_int _mm_set1_epi32
#define simd_acos_float _mm_acos_ps
#define simd_acosh_float _mm_acosh_ps
#define simd_asin_float _mm_asin_ps
#define simd_asinh_float _mm_asinh_ps
#define simd_atan_float _mm_atan_ps
#define simd_atan2_float _mm_atan2_ps
#define simd_atanh_float _mm_atanh_ps

#define simd_cos_float _mm_cos_ps
#define simd_cosh_float _mm_cosh_ps
#define simd_exp_float _mm_exp_ps
#define simd_exp2_float _mm_exp2_ps
#ifdef USE_SSE41
#define simd_blendv_float _mm_blendv_ps
#define simd_floor_float _mm_floor_ps
#define simd_ceil_float _mm_ceil_ps
#else
#define simd_blendv_float(_a,_b,mask) _mm_or_ps(_mm_and_ps(mask, _b), _mm_andnot_ps(mask, _a))
#define simd_floor_float(_a)_mm_sub_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(_a)),	_mm_and_ps(	_mm_set1_ps(1.0f), _mm_cmplt_ps(_a, _mm_cvtepi32_ps(_mm_cvttps_epi32(_a)))	))
#define simd_ceil_float(_a) simd_blendv_float(simd_floor_float(_a), _mm_add_ps(simd_floor_float(_a), _mm_set1_ps(1.0f)), _mm_cmpgt_ps(_a, simd_floor_float(_a)))
#endif // USE_SSE41
#define simd_fma_float _mm_fmadd_ps
#define simd_rsqrt_float _mm_rsqrt_ps
#define simd_log_float _mm_log_ps
#define simd_log2_float _mm_log2_ps
#define simd_max_float _mm_max_ps
#define simd_min_float _mm_min_ps
#define simd_mod_float _mm_fmod_ps
#define simd_pow_float _mm_pow_ps
#ifdef USE_SSE41
#define simd_round_float _mm_round_ps // SSE 4.1
#endif
#define simd_sin_float _mm_sin_ps
#define simd_sinh_float _mm_sinh_ps
#define simd_sqrt_float _mm_sqrt_ps
#define simd_tan_float _mm_tan_ps
#define simd_tanh_float _mm_tanh_ps

// double functions
#define simd_set1_double _mm_set1_pd
#define simd_add_double _mm_add_pd
#define simd_sub_double _mm_sub_pd
#define simd_mul_double _mm_mul_pd
#define simd_div_double _mm_div_pd
#define simd_cmp_double sse_cmp_double // _mm_cmp_pd // aVX

#define simd_store_double _mm_store_pd
#define simd_load_double _mm_load_pd
#define simd_and_double _mm_and_pd
#define simd_or_double _mm_or_pd
#define simd_andnot_double _mm_andnot_pd
#define simd_movemask_double _mm_movemask_pd
#define simd_castsi_double _mm_castsi128_pd
#define simd_set1_int _mm_set1_epi32
#define simd_acos_double _mm_acos_pd
#define simd_acosh_double _mm_acosh_pd
#define simd_asin_double _mm_asin_pd
#define simd_asinh_double _mm_asinh_pd
#define simd_atan_double _mm_atan_pd
#define simd_atan2_double _mm_atan2_pd
#define simd_atanh_double _mm_atanh_pd
#ifdef USE_SSE41
#define simd_blendv_double _mm_blendv_pd
#define simd_floor_double _mm_floor_pd
#define simd_ceil_double _mm_ceil_pd
#else
#define simd_blendv_double(_a,_b,mask) _mm_or_pd(_mm_and_pd(mask, _b), _mm_andnot_pd(mask,_a))
#define simd_floor_double(_a) _mm_sub_pd(	_mm_cvtepi32_pd(_mm_cvttpd_epi32(_a)), _mm_and_pd(_mm_and_pd(_mm_cmplt_pd(_a, _mm_setzero_pd()),	_mm_cmpneq_pd(	_mm_sub_pd(_a, _mm_cvtepi32_pd(_mm_cvttpd_epi32(_a))),_mm_setzero_pd())),	_mm_set1_pd(1.0)))
#define simd_ceil_double(_a) simd_blendv_double(simd_floor_double(_a), _mm_add_pd(simd_floor_double(_a), _mm_set1_pd(1.0)), _mm_cmpgt_pd(_a, simd_floor_double(_a)))
#endif
#define simd_cos_double _mm_cos_pd
#define simd_cosh_double _mm_cosh_pd
#define simd_exp_double _mm_exp_pd
#define simd_exp2_double _mm_exp2_pd
#define simd_fma_double _mm_fmadd_pd
// #define simd_rsqrt_double _mm_rsqrt_double // Doesn't exist
#define simd_log_double _mm_log_pd
#define simd_log2_double _mm_log2_pd
#define simd_max_double _mm_max_pd
#define simd_min_double _mm_min_pd
#define simd_mod_double _mm_fmod_pd
#define simd_pow_double _mm_pow_pd
#ifdef USE_SSE41
#define simd_round_double _mm_round_pd // SSE4.1
#endif
#define simd_sin_double _mm_sin_pd
#define simd_sinh_double _mm_sinh_pd
#define simd_sqrt_double _mm_sqrt_pd
#define simd_tan_double _mm_tan_pd
#define simd_tanh_double _mm_tanh_pd

// integer functions
#define simd_tofloat_int _mm_cvtepi32_ps
#define simd_add_int _mm_add_epi32
#define simd_sub_int _mm_sub_epi32
#ifdef USE_SSE41
#define simd_mul_int _mm_mullo_epi32
#define simd_blendv_int _mm_blendv_epi8
#define simd_abs_int _mm_abs_epi32
#define simd_max_int _mm_max_epi32
#define simd_min_int _mm_min_epi32

#else
#define simd_mul_int(_a,_b) _mm_cvtps_epi32(_mm_mul_ps(_mm_cvtepi32_ps(_a), _mm_cvtepi32_ps(_b)))
#define simd_blendv_int(_a,_b,mask) _mm_or_si128(_mm_and_si128(mask, _b), _mm_andnot_si128(mask, _a))
#define simd_abs_int(_a) _mm_sub_epi32(_mm_xor_si128(_a, _mm_srai_epi32(_a, 31)), _mm_srai_epi32(_a, 31))
#define simd_max_int(_a,_b) _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_a,_b), _a), _mm_andnot_si128(_mm_cmpgt_epi32(_a,_b), _b))
#define simd_min_int(_a,_b) _mm_or_si128(_mm_and_si128(_mm_cmplt_epi32(_a,_b), _a), _mm_andnot_si128(_mm_cmplt_epi32(_a,_b), _b))
#endif // USE_SSE41
#define simd_set1_int _mm_set1_epi32
#define simd_cvtps_int _mm_cvtps_epi32
#define simd_cvtepi32_float _mm_cvtepi32_ps
#define simd_and_si256 _mm_and_si128
#define simd_i32gather_float _mm_i32gather_ps
#define simd_castps_si _mm_castps_si128
#define simd_and_int _mm_and_si128
#define simd_or_int _mm_or_si128
#define simd_xor_int _mm_xor_si128
#define simd_andnot_int _mm_andnot_si128
#define simd_slli_int _mm_slli_epi32
#define simd_srli_int _mm_srli_epi32
#define simd_srai_int _mm_srai_epi32
#define simd_cmpeq_int _mm_cmpeq_epi32
#define simd_cmpgt_int _mm_cmpgt_epi32
#define simd_load_int sse_load_int
#define simd_store_int sse_store_int
#define simd_movemask_epi8 _mm_movemask_epi8

inline const void sse_store_int(int32_t* _ptr, __m128i _value) { _mm_store_si128((__m128i*)_ptr, _value); }
inline __m128i sse_load_int(const int32_t* _ptr) { return _mm_load_si128((__m128i*)_ptr); }

#elif defined(USE_NEON)
#define SIMDWIDTH 4
#define HALFSIMDWIDTH 2

// i need to define this because of various NEON quirks, 
// especially provided operators which will make ambiguous calls between NEON types and simd* types
struct neon_f32x4
{
	float32x4_t _val;
	neon_f32x4() = default;
	neon_f32x4(const float32x4_t& _v) : _val(_v) {}
	operator float32x4_t() const { return _val; }
};

struct neon_i32x4
{
	int32x4_t _val;
	neon_i32x4() = default;
	neon_i32x4(const int32x4_t& _v) : _val(_v) {}
	operator int32x4_t() const { return _val; }
};

struct neon_f64x2
{
	float64x2_t _val;
	neon_f64x2() = default;
	neon_f64x2(const float64x2_t& _v) : _val(_v) {}
	operator float64x2_t() const { return _val; }
};
#define simdfloat_internal neon_f32x4
#define simddouble_internal neon_f64x2
#define simdint_internal neon_i32x4
#define simdmask_internal uint32x4_t
#define simddmask_internal uint64x2_t
#define simdimask_internal uint32x4_t

#define _CMP_GT_OQ 0x1
#define _CMP_LT_OQ 0x2
#define _CMP_GE_OQ 0x5
#define _CMP_LE_OQ 0x4
#define _CMP_EQ_OQ 0x0
#define _MM_FROUND_TO_NEAREST_INT 0x00
#define _MM_FROUND_TO_ZERO 0x03
#define _MM_FROUND_NO_EXC 0x08

inline const uint32x4_t neon_mask_from_float(float value) { return vdupq_n_u32(value != 0.0f ? ~0u : 0u); }
inline const uint64x2_t neon_mask_from_double(double value) { return vdupq_n_u64(value != 0.0 ? ~0ull : 0ull); }

// float functions
inline const simdfloat_internal simd_set1_float(const float& _val) { return vdupq_n_f32(_val); }
inline const simdint_internal simd_toint_float(const simdfloat_internal& _val) { return vcvtq_s32_f32(_val); }
inline const simdfloat_internal simd_add_float(simdfloat_internal _a, simdfloat_internal _b) { return vaddq_f32(_a, _b); }
inline const simdfloat_internal simd_sub_float(simdfloat_internal _a, simdfloat_internal _b) { return vsubq_f32(_a, _b); }
inline const simdfloat_internal simd_mul_float(simdfloat_internal _a, simdfloat_internal _b) { return vmulq_f32(_a, _b); }
inline const simdfloat_internal simd_div_float(simdfloat_internal _a, simdfloat_internal _b) {
	float na[SIMDWIDTH], nb[SIMDWIDTH];
	vst1q_f32(na, _a);
	vst1q_f32(nb, _b);
	for (int32_t i = 0; i < SIMDWIDTH; ++i) na[i] /= nb[i];
	return vld1q_f32(na);
}
inline const void simd_store_float(float* ptr, simdfloat_internal _a) { vst1q_f32(ptr, _a); }
inline const void simd_store_float(float* ptr, simdmask_internal _a) { vst1q_f32(ptr, vreinterpretq_f32_u32(_a)); }
inline const simdfloat_internal simd_load_float(const float* ptr) { return vld1q_f32(ptr); }
inline const simdfloat_internal simd_ceil_float(simdfloat_internal _a) { return vrndpq_f32(_a); }
inline const simdfloat_internal simd_floor_float(simdfloat_internal _a) { return vrndmq_f32(_a); }
inline const simdfloat_internal simd_round_float(simdfloat_internal _a, int32_t _mode) {
	return (_mode & 0x07) == _MM_FROUND_TO_ZERO ? vrndq_f32(_a) : vrndnq_f32(_a);
}

#ifdef __ARM_FEATURE_FMA
inline const simdfloat_internal simd_fma_float(simdfloat_internal _a, simdfloat_internal _b, simdfloat_internal c) { return vfmaq_f32(c, _a, _b); }
#else
inline const simdfloat_internal simd_fma_float(simdfloat_internal _a, simdfloat_internal _b, simdfloat_internal c) { return vaddq_f32(vmulq_f32(static_cast<float32x4_t>(_a), _b), c); }
#endif

inline const simdfloat_internal simd_rsqrt_float(simdfloat_internal _a)
{
	float na[SIMDWIDTH];
	vst1q_f32(na, _a);
	for (int32_t i = 0; i < SIMDWIDTH; ++i) na[i] = 1.0f / std::sqrt(na[i]);
	return vld1q_f32(na);
}

inline const simdfloat_internal simd_max_float(simdfloat_internal _a, simdfloat_internal _b) { return vmaxq_f32(_a, _b); }
inline const simdfloat_internal simd_min_float(simdfloat_internal _a, simdfloat_internal _b) { return vminq_f32(_a, _b); }

// need to compute math manually because a lot of math functions are missing on Apple Silicon
#define NEON_F32_UNARY_MATH(_name, _func) \
inline const simdfloat_internal _name(simdfloat_internal _a)  \
{ \
	float in[SIMDWIDTH], out[SIMDWIDTH]; \
	vst1q_f32(in, _a); \
	_Pragma("unroll") \
	for (int32_t i = 0; i < SIMDWIDTH; ++i)  { out[i] = _func(in[i]); } \
	return vld1q_f32(out); \
}

#define NEON_F32_BINARY_MATH(_name, _func) \
inline const simdfloat_internal _name(simdfloat_internal _a, simdfloat_internal _b)  \
{ \
	float ina[SIMDWIDTH], inb[SIMDWIDTH], out[SIMDWIDTH]; \
	vst1q_f32(ina, _a); \
	vst1q_f32(inb, _b); \
	_Pragma("unroll") \
	for (int32_t i = 0; i < SIMDWIDTH; ++i)  { out[i] = _func(ina[i], inb[i]); } \
	return vld1q_f32(out); \
}

NEON_F32_UNARY_MATH(simd_sqrt_float, std::sqrt)
NEON_F32_UNARY_MATH(simd_exp_float, std::expf)
NEON_F32_UNARY_MATH(simd_exp2_float, std::exp2f)
NEON_F32_UNARY_MATH(simd_log_float, std::logf)
NEON_F32_UNARY_MATH(simd_log2_float, std::log2f)

NEON_F32_UNARY_MATH(simd_sin_float, std::sinf)
NEON_F32_UNARY_MATH(simd_cos_float, std::cosf)
NEON_F32_UNARY_MATH(simd_tan_float, std::tanf)

NEON_F32_UNARY_MATH(simd_sinh_float, std::sinhf)
NEON_F32_UNARY_MATH(simd_cosh_float, std::coshf)
NEON_F32_UNARY_MATH(simd_tanh_float, std::tanhf)

NEON_F32_UNARY_MATH(simd_asin_float, std::asinf)
NEON_F32_UNARY_MATH(simd_acos_float, std::acosf)
NEON_F32_UNARY_MATH(simd_atan_float, std::atanf)
NEON_F32_UNARY_MATH(simd_atanh_float, std::atanhf)
NEON_F32_UNARY_MATH(simd_asinh_float, std::asinhf)
NEON_F32_UNARY_MATH(simd_acosh_float, std::acoshf)

NEON_F32_BINARY_MATH(simd_pow_float, std::powf)
NEON_F32_BINARY_MATH(simd_atan2_float, std::atan2f)

#undef NEON_F32_UNARY_MATH
#undef NEON_F32_BINARY_MATH

inline const simdmask_internal simd_and_float(simdmask_internal _a, simdmask_internal _b) { return vandq_u32(_a, _b); }
inline const simdmask_internal simd_or_float(simdmask_internal _a, simdmask_internal _b) { return vorrq_u32(_a, _b); }
inline const simdmask_internal simd_andnot_float(simdmask_internal _a, simdmask_internal _b) { return vbicq_u32(_b, _a); }
inline const simdfloat_internal simd_castsi_float(int32x4_t _a) { return vreinterpretq_f32_s32(_a); }
inline const simdmask_internal simd_cmp_float(simdfloat_internal _a, simdfloat_internal _b, const int32_t _imm) {
	switch (_imm)  {
	case _CMP_EQ_OQ: return vceqq_f32(_a, _b);
	case _CMP_LT_OQ: return vcltq_f32(_a, _b);
	case _CMP_LE_OQ: return vcleq_f32(_a, _b);
	case _CMP_GT_OQ: return vcgtq_f32(_a, _b);
	case _CMP_GE_OQ: return vcgeq_f32(_a, _b);
	default: return vceqq_f32(_a, _b); }
}

inline const simdfloat_internal simd_blendv_float(simdfloat_internal _a, simdfloat_internal _b, simdmask_internal mask) { return vbslq_f32(mask, _b, _a);}

// double functions
inline const simddouble_internal simd_set1_double(double _val) { return vdupq_n_f64(_val); }
inline const simddouble_internal simd_add_double(simddouble_internal _a, simddouble_internal _b) { return vaddq_f64(_a, _b); }
inline const simddouble_internal simd_sub_double(simddouble_internal _a, simddouble_internal _b) { return vsubq_f64(_a, _b); }
inline const simddouble_internal simd_mul_double(simddouble_internal _a, simddouble_internal _b) { return vmulq_f64(_a, _b); }
inline const simddouble_internal simd_div_double(simddouble_internal _a, simddouble_internal _b) {
	double na[HALFSIMDWIDTH], nb[HALFSIMDWIDTH];
	vst1q_f64(na, _a);
	vst1q_f64(nb, _b);
	for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) na[i] /= nb[i];
	return vld1q_f64(na);
}
inline const void simd_store_double(double* ptr, simddouble_internal _a) { vst1q_f64(ptr, _a); }
inline const void simd_store_double(double* ptr, simddmask_internal _a) { vst1q_f64(ptr, vreinterpretq_f64_u64(_a)); }
inline const simddouble_internal simd_load_double(const double* ptr) { return vld1q_f64(ptr); }
inline const simddouble_internal simd_and_double(simddouble_internal _a, simddouble_internal _b) {
	return vreinterpretq_f64_u64(vandq_u64(vreinterpretq_u64_f64(_a), vreinterpretq_u64_f64(_b)));
}
inline const simddouble_internal simd_or_double(simddouble_internal _a, simddouble_internal _b) {
	return vreinterpretq_f64_u64(vorrq_u64(vreinterpretq_u64_f64(_a), vreinterpretq_u64_f64(_b)));
}
inline const simddouble_internal simd_andnot_double(simddouble_internal _a, simddouble_internal _b) {
	return vreinterpretq_f64_u64(vbicq_u64(vreinterpretq_u64_f64(_b), vreinterpretq_u64_f64(_a)));
}
inline const simddmask_internal simd_and_double(simddmask_internal _a, simddmask_internal _b) { return vandq_u64(_a, _b); }
inline const simddmask_internal simd_or_double(simddmask_internal _a, simddmask_internal _b) { return vorrq_u64(_a, _b); }
inline const simddouble_internal simd_castsi_double(int64x2_t _a) { return vreinterpretq_f64_s64(_a); }
inline const simddmask_internal simd_cmp_double(simddouble_internal _a, simddouble_internal _b, const int32_t _imm) {
	switch (_imm) {
	case _CMP_EQ_OQ: return vceqq_f64(_a, _b);
	case _CMP_LT_OQ: return vcltq_f64(_a, _b);
	case _CMP_LE_OQ: return vcleq_f64(_a, _b);
	case _CMP_GT_OQ: return vcgtq_f64(_a, _b);
	case _CMP_GE_OQ: return vcgeq_f64(_a, _b);
	default: return vceqq_f64(_a, _b); }
}
inline const simddouble_internal simd_ceil_double(simddouble_internal _a) { return vrndpq_f64(_a); }
inline const simddouble_internal simd_floor_double(simddouble_internal _a) { return vrndmq_f64(_a); }
inline const simddouble_internal simd_round_double(simddouble_internal _a, int32_t _mode) {
	return (_mode & 0x07) == _MM_FROUND_TO_ZERO ? vrndq_f64(_a) : vrndnq_f64(_a);
}
inline const simddouble_internal simd_max_double(simddouble_internal _a, simddouble_internal _b) { return vmaxq_f64(_a, _b); }
inline const simddouble_internal simd_min_double(simddouble_internal _a, simddouble_internal _b) { return vminq_f64(_a, _b); }
inline const simddouble_internal simd_sqrt_double(simddouble_internal _a) { return vsqrtq_f64(_a); }
inline const simddouble_internal simd_blendv_double(simddouble_internal _a, simddouble_internal _b, simddmask_internal mask) {
	return vbslq_f64(mask, _b, _a);
}
inline const simdint_internal simd_blendv_int(simdint_internal _a, simdint_internal _b, simdimask_internal mask) {
	return vreinterpretq_s32_u32(vbslq_u32(mask, vreinterpretq_u32_s32(_b), vreinterpretq_u32_s32(_a)));
}
inline const int32_t simd_movemask_float(simdmask_internal mask) {
	uint32_t lanes[SIMDWIDTH];
	vst1q_u32(lanes, mask);
	int32_t result = 0;
	for (int32_t i = 0; i < SIMDWIDTH; ++i) result |= static_cast<int32_t>((lanes[i] >> 31) & 1u) << i;
	return result;
}
inline const int32_t simd_movemask_double(simddmask_internal mask) {
	uint64_t lanes[HALFSIMDWIDTH];
	vst1q_u64(lanes, mask);
	int32_t result = 0;
	for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) result |= static_cast<int32_t>((lanes[i] >> 63) & 1u) << i;
	return result;
}
inline const int32_t simd_movemask_epi8(simdimask_internal mask) {
	return simd_movemask_float(mask);
}
#ifdef __ARM_FEATURE_FMA
inline const simddouble_internal simd_fma_double(simddouble_internal _a, simddouble_internal _b, simddouble_internal c) { return vfmaq_f64(c, _a, _b); }
#else
inline const simddouble_internal simd_fma_double(simddouble_internal _a, simddouble_internal _b, simddouble_internal c) { return vaddq_f64(vmulq_f64(_a, _b), c); }
#endif

// integer functions
inline const simdint_internal simd_set1_int(int32_t _val) { return vdupq_n_s32(_val); }
inline const simdfloat_internal simd_tofloat_int(const simdint_internal& _val) { return vcvtq_f32_s32(_val); }

inline const simdint_internal simd_add_int(simdint_internal _a, simdint_internal _b) { return vaddq_s32(_a, _b); }
inline const simdint_internal simd_sub_int(simdint_internal _a, simdint_internal _b) { return vsubq_s32(_a, _b); }
inline const simdint_internal simd_mul_int(simdint_internal _a, simdint_internal _b) { return vmulq_s32(_a, _b); }
inline const simdint_internal simd_min_int(simdint_internal _a, simdint_internal _b) { return vminq_s32(_a, _b); }
inline const simdint_internal simd_max_int(simdint_internal _a, simdint_internal _b) { return vmaxq_s32(_a, _b); }
inline const simdint_internal simd_abs_int(simdint_internal _a) { return vabsq_s32(_a); }
inline const simdint_internal simd_cvtps_int(simdfloat_internal _a) { return vcvtq_s32_f32(_a); }
inline const simdfloat_internal simd_cvtepi32_float(simdint_internal _a) { return vcvtq_f32_s32(_a); }
inline const simdint_internal simd_and_int(simdint_internal _a, simdint_internal _b) { return vandq_s32(_a, _b); }
inline const simdimask_internal simd_and_int(simdimask_internal _a, simdimask_internal _b) { return vandq_u32(_a, _b); }
inline const simdint_internal simd_or_int(simdint_internal _a, simdint_internal _b) { return vorrq_s32(_a, _b); }
inline const simdimask_internal simd_or_int(simdimask_internal _a, simdimask_internal _b) { return vorrq_u32(_a, _b); }
inline const simdint_internal simd_xor_int(simdint_internal _a, simdint_internal _b) { return veorq_s32(_a, _b); }
inline const simdimask_internal simd_xor_int(simdimask_internal _a, simdimask_internal _b) { return veorq_u32(_a, _b); }
inline const simdint_internal simd_andnot_int(simdint_internal _a, simdint_internal _b) { return vbicq_s32(_b, _a); }
inline const simdint_internal simd_slli_int(simdint_internal _a, int32_t _imm) { return vshlq_s32(_a, vdupq_n_s32(_imm)); }
inline const simdint_internal simd_srli_int(simdint_internal _a, int32_t _imm) { return vreinterpretq_s32_u32(vshlq_u32(vreinterpretq_u32_s32(static_cast<int32x4_t>(_a)), vdupq_n_s32(-_imm)));}
inline const simdint_internal simd_srai_int(simdint_internal _a, int32_t _imm) { return vshlq_s32(_a, vdupq_n_s32(-_imm)); }
inline const simdimask_internal simd_cmpeq_int(simdint_internal _a, simdint_internal _b) { return vceqq_s32(_a, _b); }
inline const simdimask_internal simd_cmpgt_int(simdint_internal _a, simdint_internal _b) { return vcgtq_s32(_a, _b); }
inline const simdint_internal simd_load_int(const int32_t* ptr) { return vld1q_s32(ptr); }
inline const void simd_store_int(int32_t* ptr, simdint_internal _a) { vst1q_s32(ptr, _a); }
inline const void simd_store_int(int32_t* ptr, simdimask_internal _a) { vst1q_s32(ptr, vreinterpretq_s32_u32(_a)); }

#elif (defined(USE_PACKED_SCALAR) || defined (USE_SCALAR))
#ifdef USE_PACKED_SCALAR
#define SIMDWIDTH 4
#define HALFSIMDWIDTH 2
#else
#define SIMDWIDTH 1
#define HALFSIMDWIDTH 1
#endif

struct simdfloat;
struct simdint;

struct simdfloat {
	alignas(SIMDWIDTH * 4) float value[SIMDWIDTH];
	simdfloat() : value{} {}
	simdfloat(const float& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = _val; }
	simdfloat(const simdint& _val);
	simdfloat& operator=(const float& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = _val; return *this; }
	simdfloat& operator=(const int32_t& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = static_cast<float>(_val); return *this; }
	simdfloat& operator=(const double& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = static_cast<float>(_val); return *this; }
	simdfloat& operator=(const simdfloat& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = _val.value[i]; return *this; }
	simdfloat& operator=(const simdint& _val);
};

struct simddouble {
	alignas(HALFSIMDWIDTH * 8) double value[HALFSIMDWIDTH];
	simddouble() : value{} {}
	simddouble(const double& _val) { for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) value[i] = _val; }
	simddouble& operator=(const double& _val) { for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) value[i] = _val; return *this; }
	simddouble& operator=(const simddouble& _val) { for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) value[i] = _val.value[i]; return *this; }
};

struct simdint {
	alignas(SIMDWIDTH * 4) int32_t value[SIMDWIDTH];
	simdint() : value{} {}
	simdint(const int32_t& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = _val; }
	simdint(const simdfloat& _val);
	simdint& operator=(const int32_t& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = _val; return *this; }
	simdint& operator=(const simdint& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = _val.value[i]; return *this; }
    simdint& operator=(const simdfloat& _val);

};

struct simdmask {
	alignas(SIMDWIDTH * 4) int32_t value[SIMDWIDTH];
	simdmask() : value{} {}
	simdmask(const int32_t& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = _val != 0; }
	explicit operator int32_t() const { return value[0]; }
};

struct simddmask {
	alignas(SIMDWIDTH * 4) int32_t value[HALFSIMDWIDTH];
	simddmask() : value{} {}
	simddmask(const int32_t& _val) { for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) value[i] = _val != 0; }
	explicit operator int32_t() const { return value[0]; }
};

struct simdimask {
	alignas(SIMDWIDTH * 4) int32_t value[SIMDWIDTH];
	simdimask() : value{} {}
	simdimask(const int32_t& _val) { for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = _val != 0; }
	explicit operator int32_t() const { return value[0]; }
};



#define simdfloat simdfloat
#define simddouble simddouble
#define simdint simdint
#define simdfloat_internal simdfloat
#define simddouble_internal simddouble
#define simdint_internal simdint
#define simdmask simdmask
#define simddmask simddmask
#define simdimask simdimask
#define simdmask_internal simdmask
#define simddmask_internal simddmask
#define simdimask_internal simdimask

#define _CMP_EQ_OQ 0x00
#define _CMP_LT_OQ 0x11
#define _CMP_LE_OQ 0x12
#define _CMP_GT_OQ 0x1E
#define _CMP_GE_OQ 0x1D

#ifndef _MM_FROUND_TO_NEAREST_INT
#define _MM_FROUND_TO_NEAREST_INT 0x00
#endif
#ifndef _MM_FROUND_TO_ZERO
#define _MM_FROUND_TO_ZERO 0x03
#endif
#ifndef _MM_FROUND_NO_EXC
#define _MM_FROUND_NO_EXC 0x08
#endif
#define _MM_FROUND_TO_NEAREST_INT 0x00
#define _MM_FROUND_TO_ZERO 0x03
#define _MM_FROUND_NO_EXC 0x08

#define PACKED_F32_UNARY_MATH(_name, _func) \
inline const simdfloat _name(const simdfloat& _a) \
{ \
	simdfloat r; \
	for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _func(_a.value[i]); \
	return r; \
}

#define PACKED_F32_BINARY_MATH(_name, _func) \
inline const simdfloat _name(const simdfloat& _a, const simdfloat& _b) \
{ \
	simdfloat r; \
	for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _func(_a.value[i], _b.value[i]); \
	return r; \
}

#define PACKED_F64_UNARY_MATH(_name, _func) \
inline const simddouble _name(const simddouble& _a) \
{ \
	 simddouble r; \
	for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _func(_a.value[i]); \
	return r; \
}

#define PACKED_F64_BINARY_MATH(_name, _func) \
inline const simddouble _name(const simddouble& _a, const simddouble& _b) \
{ \
	 simddouble r; \
	for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _func(_a.value[i], _b.value[i]); \
	return r; \
}

// float
inline const simdfloat simd_set1_float(const float& _val) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _val; return r; }
inline const simdint simd_toint_float(const simdfloat& _val) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = static_cast<int32_t>(_val.value[i]); return r; }
inline const simdfloat simd_add_float(const simdfloat& _a, const simdfloat& _b) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] + _b.value[i]; return r; }
inline const simdfloat simd_sub_float(const simdfloat& _a, const simdfloat& _b) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] - _b.value[i]; return r; }
inline const simdfloat simd_mul_float(const simdfloat& _a, const simdfloat& _b) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] * _b.value[i]; return r; }
inline const simdfloat simd_div_float(const simdfloat& _a, const simdfloat& _b) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] / _b.value[i]; return r; }
PACKED_F32_UNARY_MATH(simd_floor_float, std::floorf)
PACKED_F32_UNARY_MATH(simd_ceil_float, std::ceilf)
PACKED_F32_UNARY_MATH(simd_sin_float, std::sinf)
PACKED_F32_UNARY_MATH(simd_cos_float, std::cosf)
PACKED_F32_UNARY_MATH(simd_tan_float, std::tanf)
PACKED_F32_UNARY_MATH(simd_sinh_float, std::sinhf)
PACKED_F32_UNARY_MATH(simd_cosh_float, std::coshf)
PACKED_F32_UNARY_MATH(simd_tanh_float, std::tanhf)
PACKED_F32_UNARY_MATH(simd_asin_float, std::asinf)
PACKED_F32_UNARY_MATH(simd_acos_float, std::acosf)
PACKED_F32_UNARY_MATH(simd_atan_float, std::atanf)
PACKED_F32_UNARY_MATH(simd_asinh_float, std::asinhf)
PACKED_F32_UNARY_MATH(simd_acosh_float, std::acoshf)
PACKED_F32_UNARY_MATH(simd_atanh_float, std::atanhf)
PACKED_F32_UNARY_MATH(simd_exp_float, std::expf)
PACKED_F32_UNARY_MATH(simd_exp2_float, std::exp2f)
PACKED_F32_UNARY_MATH(simd_log_float, std::logf)
PACKED_F32_UNARY_MATH(simd_log2_float, std::log2f)
PACKED_F32_UNARY_MATH(simd_sqrt_float, std::sqrtf)
PACKED_F32_UNARY_MATH(simd_round_float, std::roundf)
inline const simdfloat simd_rsqrt_float(const simdfloat& _a) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = 1.0f / std::sqrtf(_a.value[i]); return r; }
inline const simdfloat simd_round_float(const simdfloat& _a, int32_t _mode) { if ((_mode & 0x07) != _MM_FROUND_TO_ZERO) return simd_round_float(_a); simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = std::trunc(_a.value[i]); return r;}
PACKED_F32_BINARY_MATH(simd_pow_float, std::powf)
PACKED_F32_BINARY_MATH(simd_atan2_float, std::atan2f)
inline const simdfloat simd_max_float(const simdfloat& _a, const simdfloat& _b) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] > _b.value[i] ? _a.value[i] : _b.value[i]; return r; }
inline const simdfloat simd_min_float(const simdfloat& _a, const simdfloat& _b) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] < _b.value[i] ? _a.value[i] : _b.value[i]; return r; }
PACKED_F32_BINARY_MATH(simd_mod_float, std::fmodf)
inline const simdfloat simd_fma_float(const simdfloat& _a, const simdfloat& _b, const simdfloat& c) { return simd_add_float(simd_mul_float(_a, _b), c); }
inline const simdfloat simd_load_float(const float* p) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = p[i]; return r; }
inline const void simd_store_float(float* p, const simdfloat& _a) { for (int32_t i = 0; i < SIMDWIDTH; ++i) p[i] = _a.value[i]; }
inline const void simd_store_float(float* p, const simdmask& _a) { for (int32_t i = 0; i < SIMDWIDTH; ++i) p[i] = static_cast<float>(_a.value[i]); }
inline const simdfloat simd_blendv_float(const simdfloat& _a, const simdfloat& _b, const simdmask& m) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = m.value[i] ? _b.value[i] : _a.value[i]; return r; }
inline const int32_t simd_movemask_float(const simdmask& m) { int32_t r = 0; for (int32_t i = 0; i < SIMDWIDTH; ++i) r |= (m.value[i] == 1 ? 1 : 0) << i; return r; }
inline const simdmask simd_and_float(const simdmask& _a, const simdmask& _b) { simdmask r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] && _b.value[i]; return r; }
inline const simdmask simd_or_float(const simdmask& _a, const simdmask& _b) { simdmask r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] || _b.value[i]; return r; }
inline const simdmask simd_cmp_float(const simdfloat& _a, const simdfloat& _b, int32_t op)
{
	simdmask r;
	for (int32_t i = 0; i < SIMDWIDTH; ++i) { switch (op) { case _CMP_EQ_OQ: 	r.value[i] = (_a.value[i] == _b.value[i] ? 1 : 0); break; case _CMP_LT_OQ: 	r.value[i] = (_a.value[i] < _b.value[i] ? 1 : 0); break; case _CMP_LE_OQ: 	r.value[i] = (_a.value[i] <= _b.value[i] ? 1 : 0); break; case _CMP_GT_OQ: 	r.value[i] = (_a.value[i] > _b.value[i] ? 1 : 0); break; case _CMP_GE_OQ: 	r.value[i] = (_a.value[i] >= _b.value[i] ? 1 : 0); break; default: 	throw std::invalid_argument("Invalid comparison _mode"); } }
	return r;
}

// double
inline const simddouble simd_set1_double(double _val) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _val; return r; }
inline const simddouble simd_add_double(const simddouble& _a, const simddouble& _b) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _a.value[i] + _b.value[i]; return r; }
inline const simddouble simd_sub_double(const simddouble& _a, const simddouble& _b) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _a.value[i] - _b.value[i]; return r; }
inline const simddouble simd_mul_double(const simddouble& _a, const simddouble& _b) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _a.value[i] * _b.value[i]; return r; }
inline const simddouble simd_div_double(const simddouble& _a, const simddouble& _b) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _a.value[i] / _b.value[i]; return r; }
PACKED_F64_UNARY_MATH(simd_floor_double, std::floor)
PACKED_F64_UNARY_MATH(simd_ceil_double, std::ceil)
PACKED_F64_UNARY_MATH(simd_sin_double, std::sin)
PACKED_F64_UNARY_MATH(simd_cos_double, std::cos)
PACKED_F64_UNARY_MATH(simd_tan_double, std::tan)
PACKED_F64_UNARY_MATH(simd_sinh_double, std::sinh)
PACKED_F64_UNARY_MATH(simd_cosh_double, std::cosh)
PACKED_F64_UNARY_MATH(simd_tanh_double, std::tanh)
PACKED_F64_UNARY_MATH(simd_asin_double, std::asin)
PACKED_F64_UNARY_MATH(simd_acos_double, std::acos)
PACKED_F64_UNARY_MATH(simd_atan_double, std::atan)
PACKED_F64_UNARY_MATH(simd_asinh_double, std::asinh)
PACKED_F64_UNARY_MATH(simd_acosh_double, std::acosh)
PACKED_F64_UNARY_MATH(simd_atanh_double, std::atanh)
PACKED_F64_UNARY_MATH(simd_exp_double, std::exp)
PACKED_F64_UNARY_MATH(simd_exp2_double, std::exp2)
PACKED_F64_UNARY_MATH(simd_log_double, std::log)
PACKED_F64_UNARY_MATH(simd_log2_double, std::log2)
PACKED_F64_UNARY_MATH(simd_sqrt_double, std::sqrt)
PACKED_F64_UNARY_MATH(simd_round_double, std::round)
inline const simddouble simd_rsqrt_double(const simddouble& _a) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = 1.0 / std::sqrt(_a.value[i]); return r; }
inline const simddouble simd_round_double(const simddouble& _a, int32_t _mode) { if ((_mode & 0x07) != _MM_FROUND_TO_ZERO) return simd_round_double(_a); simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = std::trunc(_a.value[i]); return r;}
PACKED_F64_BINARY_MATH(simd_pow_double, std::pow)
PACKED_F64_BINARY_MATH(simd_atan2_double, std::atan2)
inline const simddouble simd_max_double(const simddouble& _a, const simddouble& _b) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _a.value[i] > _b.value[i] ? _a.value[i] : _b.value[i]; return r; }
inline const simddouble simd_min_double(const simddouble& _a, const simddouble& _b) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _a.value[i] < _b.value[i] ? _a.value[i] : _b.value[i]; return r; }
PACKED_F64_BINARY_MATH(simd_mod_double, std::fmod)
inline const simddouble simd_fma_double(const simddouble& _a, const simddouble& _b, const simddouble& c) { return simd_add_double(simd_mul_double(_a, _b), c); }
inline const simddouble simd_load_double(const double* p) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = p[i]; return r; }
inline const void simd_store_double(double* p, const simddouble& _a) { for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) p[i] = _a.value[i]; }
inline const void simd_store_double(double* p, const simddmask& _a) { for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) p[i] = (_a.value[i]); }
inline const simddouble simd_blendv_double(const simddouble& _a, const simddouble& _b, const simddmask& m) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = m.value[i] ? _b.value[i] : _a.value[i]; return r; }
inline const int32_t simd_movemask_double(const simddmask& m) { int32_t r = 0; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r |= (m.value[i] == 1 ? 1 : 0) << i; return r; }
inline const simddmask simd_and_double(const simddmask& _a, const simddmask& _b) { simddmask r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _a.value[i] && _b.value[i]; return r; }
inline const simddmask simd_or_double(const simddmask& _a, const simddmask& _b) { simddmask r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = _a.value[i] || _b.value[i]; return r; }
inline const simddmask simd_cmp_double(const simddouble& _a, const simddouble& _b, int32_t op)
{
	simddmask r;
	for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) { switch (op) { case _CMP_EQ_OQ: 	r.value[i] = (_a.value[i] == _b.value[i] ? 1 : 0); break; case _CMP_LT_OQ: 	r.value[i] = (_a.value[i] < _b.value[i] ? 1 : 0); break; case _CMP_LE_OQ: 	r.value[i] = (_a.value[i] <= _b.value[i] ? 1 : 0); break; case _CMP_GT_OQ: 	r.value[i] = (_a.value[i] > _b.value[i] ? 1 : 0); break; case _CMP_GE_OQ: 	r.value[i] = (_a.value[i] >= _b.value[i] ? 1 : 0); break; default: 	throw std::invalid_argument("Invalid comparison _mode"); } }
	return r;
}

// int32_t
inline const simdint simd_set1_int(int32_t _val) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _val; return r; }
inline const simdfloat simd_tofloat_int(const simdint& _val) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = static_cast<float>(_val.value[i]); return r;  }
inline const simdint simd_add_int(const simdint& _a, const simdint& _b) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] + _b.value[i]; return r; }
inline const simdint simd_sub_int(const simdint& _a, const simdint& _b) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] - _b.value[i]; return r; }
inline const simdint simd_mul_int(const simdint& _a, const simdint& _b) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] * _b.value[i]; return r; }
inline const simdint simd_min_int(const simdint& _a, const simdint& _b) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] < _b.value[i] ? _a.value[i] : _b.value[i]; return r; }
inline const simdint simd_max_int(const simdint& _a, const simdint& _b) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] > _b.value[i] ? _a.value[i] : _b.value[i]; return r; }
inline const simdint simd_abs_int(const simdint& _a) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = std::abs(_a.value[i]); return r; }
inline const simdint simd_blendv_int(const simdint& _a, const simdint& _b, const simdimask& m) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = m.value[i] ? _b.value[i] : _a.value[i]; return r; }
inline const simdint simd_and_int(const simdint& _a, const simdint& _b) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] & _b.value[i]; return r; }
inline const simdint simd_or_int(const simdint& _a, const simdint& _b) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] | _b.value[i]; return r; }
inline const simdint simd_xor_int(const simdint& _a, const simdint& _b) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] ^ _b.value[i]; return r; }
inline const simdint simd_andnot_int(const simdint& _a, const simdint& _b) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = (~_a.value[i]) & _b.value[i]; return r; }
inline const simdimask simd_cmpeq_int(const simdint& _a, const simdint& _b) { simdimask r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] == _b.value[i]; return r; }
inline const simdimask simd_cmpgt_int(const simdint& _a, const simdint& _b) { simdimask r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] > _b.value[i]; return r; }
inline const simdimask simd_and_int(const simdimask& _a, const simdimask& _b) { simdimask r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] && _b.value[i]; return r; }
inline const simdimask simd_or_int(const simdimask& _a, const simdimask& _b) { simdimask r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] || _b.value[i]; return r; }
inline const simdint simd_load_int(const int32_t* p) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = p[i]; return r; }
inline const void simd_store_int(int32_t* p, const simdint& _a) { for (int32_t i = 0; i < SIMDWIDTH; ++i) p[i] = _a.value[i]; }
inline const void simd_store_int(int32_t* p, const simdimask& _a) { for (int32_t i = 0; i < SIMDWIDTH; ++i) p[i] = _a.value[i]; }
inline const int32_t simd_movemask_epi8(const simdimask& m) { int32_t r = 0; for (int32_t i = 0; i < SIMDWIDTH; ++i) r |= (m.value[i] == 1 ? 1 : 0) << i; return r; }
inline const simdint simd_slli_int(const simdint& _a, int32_t n) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] << n; return r; }
inline const simdint simd_srli_int(const simdint& _a, int32_t n) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = (_a.value[i]) >> n; return r; }
inline const simdint simd_srai_int(const simdint& _a, int32_t n) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = _a.value[i] >> n; return r; }
inline const simdfloat simd_castsi_float(const simdint& _a) { simdfloat r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = static_cast<float>(_a.value[i]); return r; }
inline const simddouble simd_castsi_double(const simdint& _a) {  simddouble r; for (int32_t i = 0; i < HALFSIMDWIDTH; ++i) r.value[i] = (_a.value[i]); return r; }
inline const simdint simd_cvtps_int(const simdfloat& _a) { simdint r; for (int32_t i = 0; i < SIMDWIDTH; ++i) r.value[i] = static_cast<int32_t>(_a.value[i]); return r; }
inline const simdfloat simd_cvtepi32_float(const simdint& _a) { return simd_castsi_float(_a); }

inline simdfloat::simdfloat(const simdint& _val) { simdfloat r = simd_tofloat_int(_val); for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = (r.value[i]); }
inline simdfloat& simdfloat::operator=(const simdint& _val) { simdfloat r = simd_tofloat_int(_val); for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = r.value[i]; return *this; }
inline simdint::simdint(const simdfloat& _val) { simdint r = simd_toint_float(_val); for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = r.value[i]; }
inline simdint& simdint::operator=(const simdfloat& _val) { simdint r = simd_toint_float(_val); for (int32_t i = 0; i < SIMDWIDTH; ++i) value[i] = r.value[i]; return *this; }


#undef PACKED_F64_BINARY_MATH
#undef PACKED_F64_UNARY_MATH
#undef PACKED_F32_BINARY_MATH
#undef PACKED_F32_UNARY_MATH

#endif // USE_SCALAR

#if !defined(USE_SCALAR) && !defined (USE_PACKED_SCALAR)

struct simdfloat;
struct simdint;

struct simdfloat
{
	simdfloat_internal value;

	simdfloat() { value = simd_set1_float(0.0f); }
	simdfloat(const int32_t& _i) : value(simd_set1_float(static_cast<float>(_i))) {}
	simdfloat(const float& _f) : value(simd_set1_float(_f)) {}
	simdfloat(const double& _d) : value(simd_set1_float(static_cast<float>(_d))) {}
	simdfloat(const simdfloat_internal& _sv) : value(_sv) {}
	simdfloat(const simdint& _sv);

	simdfloat& operator=(const int32_t& _i) { value = simd_set1_float(static_cast<float>(_i)); return *this; }
	simdfloat& operator=(const float& _f) { value = simd_set1_float(_f); return *this; }
	simdfloat& operator=(const double& _d) { value = simd_set1_float(static_cast<float>(_d)); return *this; }
	simdfloat& operator=(const simdfloat& _sv) { value = _sv.value; return *this; }
	simdfloat& operator=(const simdint& _v);

	simdfloat& operator=(const simdfloat_internal& _sv) { value = _sv; return *this; }
	operator simdfloat_internal() const { return value; }
};

struct simddouble
{
	simddouble_internal value;

	simddouble() { value = simd_set1_double(0.0); }
	simddouble(const int32_t& _i) : value(simd_set1_double((_i))) {}
	simddouble(const float& _f) : value(simd_set1_double((_f))) {}
	simddouble(const double& _d) : value(simd_set1_double(_d)) {}
	simddouble(const simddouble_internal& _sv) : value(_sv) {}

	simddouble& operator=(const int32_t& _i) { value = simd_set1_double((_i)); return *this; }
	simddouble& operator=(const float& _f) { value = simd_set1_double((_f)); return *this; }
	simddouble& operator=(const double& _d) { value = simd_set1_double(_d); return *this; }
	simddouble& operator=(const simddouble& _sv) { value = _sv.value; return *this; }

	simddouble& operator=(const simddouble_internal& _sv) { value = _sv; return *this; }
	operator simddouble_internal() const { return value; }
};

struct simdint
{
	simdint_internal value;

	simdint() { value = simd_set1_int(0); }
	simdint(const int32_t& _i) : value(simd_set1_int(_i)) {}
	simdint(const float& _f) : value(simd_set1_int(static_cast<int32_t>(_f))) {}
	simdint(const double& _d) : value(simd_set1_int(static_cast<int32_t>(_d))) {}
	simdint(const simdint_internal& _sv) : value(_sv) {}
	simdint(const simdfloat& _sv);

	simdint& operator=(const int32_t& _i) { value = simd_set1_int(_i); return *this; }
	simdint& operator=(const float& _f) { value = simd_set1_int(static_cast<int32_t>(_f)); return *this; }
	simdint& operator=(const double& _d) { value = simd_set1_int(static_cast<int32_t>(_d)); return *this; }
	simdint& operator=(const simdint& _sv) { value = _sv.value; return *this; }
	simdint& operator=(const simdfloat& _v);

	simdint& operator=(const simdint_internal& _sv) { value = _sv; return *this; }
	operator simdint_internal() const { return value; }
};

inline simdfloat& simdfloat::operator=(const simdint& _v) { value = simd_tofloat_int(_v.value); return *this; }
inline simdfloat::simdfloat(const simdint& _v) { value = simd_tofloat_int(_v.value);}
inline simdint& simdint::operator=(const simdfloat& _v) { value = simd_toint_float(_v.value); return *this; }
inline simdint::simdint(const simdfloat& _v) { value = simd_toint_float(_v.value); }

#ifndef USE_AVX512
#ifdef USE_NEON
struct simdmask
{
	simdmask_internal value;

	simdmask() { value = neon_mask_from_float(0.0f);
 }
	simdmask(const int32_t& _i) : value( neon_mask_from_float(static_cast<float>(_i))) { }
	simdmask(const float& _f) : value( neon_mask_from_float(_f)) { }
	simdmask(const double& _d) : value( neon_mask_from_float(static_cast<float>(_d))) { }
	simdmask(const simdmask_internal& _sv) : value(_sv) {}

	simdmask& operator=(const int32_t& _i) { value = neon_mask_from_float(static_cast<float>(_i)); return *this; }
	simdmask& operator=(const float& _f) { value = neon_mask_from_float(_f); return *this; }
	simdmask& operator=(const double& _d) { value = neon_mask_from_float(static_cast<float>(_d)); return *this; }
	simdmask& operator=(const simdfloat& _sv) { value = _sv.value; return *this; }

	simdmask& operator=(const simdmask_internal& _sv) { value = _sv; return *this; }
	operator simdmask_internal() const { return value; }
};

struct simddmask
{
	simddmask_internal value;

	simddmask() { value = neon_mask_from_double(0.0);
 }
	simddmask(const int32_t& _i) : value( neon_mask_from_double((_i))) { }
	simddmask(const float& _f) : value( neon_mask_from_double((_f))) { }
	simddmask(const double& _d) : value( neon_mask_from_double(_d)) { }
	simddmask(const simddmask_internal& _sv) : value(_sv) {}

	simddmask& operator=(const int32_t& _i) { value = neon_mask_from_double((_i)); return *this; }
	simddmask& operator=(const float& _f) { value = neon_mask_from_double((_f)); return *this; }
	simddmask& operator=(const double& _d) { value = neon_mask_from_double(_d); return *this; }
	simddmask& operator=(const simddmask& _sv) { value = _sv.value; return *this; }

	simddmask& operator=(const simddmask_internal& _sv) { value = _sv; return *this; }
	operator simddmask_internal() const { return value; }
};

struct simdimask
{
	simdimask_internal value;

	simdimask() { value = vdupq_n_u32(0);
 }
	simdimask(const int32_t& _i) : value( vdupq_n_u32(_i != 0 ? ~0u : 0u)) { }
	simdimask(const float& _f) : value( vdupq_n_u32(_f != 0.0f ? ~0u : 0u)) { }
	simdimask(const double& _d) : value( vdupq_n_u32(_d != 0.0 ? ~0u : 0u)) { }
	simdimask(const simdimask_internal& _sv) : value(_sv) {}

	simdimask& operator=(const int32_t& _i) { value = vdupq_n_u32(_i != 0 ? ~0u : 0u); return *this; }
	simdimask& operator=(const float& _f) { value = vdupq_n_u32(_f != 0.0f ? ~0u : 0u); return *this; }
	simdimask& operator=(const double& _d) { value = vdupq_n_u32(_d != 0.0 ? ~0u : 0u); return *this; }
	simdimask& operator=(const simdint& _sv) { value = _sv.value; return *this; }

	simdimask& operator=(const simdimask_internal& _sv) { value = _sv; return *this; }
	operator simdimask_internal() const { return value; }
};
#else // USE_NEON

struct simdmask
{
	simdmask_internal value;

	simdmask() { value = simd_set1_float(0.0f); }
	simdmask(const int32_t& _i) : value( simd_set1_float(static_cast<float>(_i)) ) { }
	simdmask(const float& _f) : value( simd_set1_float(_f) ) { }
	simdmask(const double& _d) : value( simd_set1_float(static_cast<float>(_d)) ) { }
	simdmask(const simdmask_internal& _sv) : value(_sv) {}

	simdmask& operator=(const int32_t& _i) { value = simd_set1_float(static_cast<float>(_i)); return *this; }
	simdmask& operator=(const float& _f) { value = simd_set1_float(_f); return *this; }
	simdmask& operator=(const double& _d) { value = simd_set1_float(static_cast<float>(_d)); return *this; }
	simdmask& operator=(const simdfloat& _sv) { value = _sv.value; return *this; }

	simdmask& operator=(const simdmask_internal& _sv) { value = _sv; return *this; }
	operator simdmask_internal() const { return value; }
};

struct simddmask
{
	simddmask_internal value;

	simddmask() { value = simd_set1_double(0.0); }
	simddmask(const int32_t& _i) : value( simd_set1_double((_i)) ) { }
	simddmask(const float& _f) : value( simd_set1_double((_f)) ) { }
	simddmask(const double& _d) : value( simd_set1_double(_d) ) { }
	simddmask(const simddmask_internal& _sv) : value(_sv) {}

	simddmask& operator=(const int32_t& _i) { value = simd_set1_double((_i)); return *this; }
	simddmask& operator=(const float& _f) { value = simd_set1_double((_f)); return *this; }
	simddmask& operator=(const double& _d) { value = simd_set1_double(_d); return *this; }
	simddmask& operator=(const simddmask& _sv) { value = _sv.value; return *this; }

	simddmask& operator=(const simddmask_internal& _sv) { value = _sv; return *this; }
	operator simddmask_internal() const { return value; }
};

struct simdimask
{
	simdimask_internal value;

	simdimask() { value = simd_set1_int(0); }
	simdimask(const int32_t& _i) : value( simd_set1_int(_i) ) { }
	simdimask(const float& _f) : value( simd_set1_int(static_cast<int32_t>(_f)) ) { }
	simdimask(const double& _d) : value( simd_set1_int(static_cast<int32_t>(_d)) ) { }
	simdimask(const simdimask_internal& _sv) : value(_sv) {}

	simdimask& operator=(const int32_t& _i) { value = simd_set1_int(_i); return *this; }
	simdimask& operator=(const float& _f) { value = simd_set1_int(static_cast<int32_t>(_f)); return *this; }
	simdimask& operator=(const double& _d) { value = simd_set1_int(static_cast<int32_t>(_d)); return *this; }
	simdimask& operator=(const simdint& _sv) { value = _sv.value; return *this; }

	simdimask& operator=(const simdimask_internal& _sv) { value = _sv; return *this; }
	operator simdimask_internal() const { return value; }
};

#endif // USE_NEON
#endif // USE_AVX512
#endif // !defined(USE_SCALAR) && !defined (USE_PACKED_SCALAR)

#if defined(USE_SSE41) || defined (USE_SSE)
inline const simdmask_internal sse_cmp_float(const simdfloat& _a, const simdfloat& _b, const int32_t& flag)
{
	switch (flag) {
	case _CMP_EQ_OQ: return _mm_cmpeq_ps(_a, _b);
	case _CMP_LT_OQ: return _mm_cmplt_ps(_a, _b);
	case _CMP_LE_OQ: return _mm_cmple_ps(_a, _b);
	case _CMP_GT_OQ: return _mm_cmpgt_ps(_a, _b);
	case _CMP_GE_OQ: return _mm_cmpge_ps(_a, _b);
	default: return _mm_cmpeq_ps(_a, _b); }
}

inline const simddmask_internal sse_cmp_double(const simddouble& _a, const simddouble& _b, const int32_t& flag)
{
	switch (flag) {
	case _CMP_EQ_OQ: return _mm_cmpeq_pd(_a, _b);
	case _CMP_LT_OQ: return _mm_cmplt_pd(_a, _b);
	case _CMP_LE_OQ: return _mm_cmple_pd(_a, _b);
	case _CMP_GT_OQ: return _mm_cmpgt_pd(_a, _b);
	case _CMP_GE_OQ: return _mm_cmpge_pd(_a, _b);
	default: return _mm_cmpeq_pd(_a, _b); }
}
#endif // defined(USE_SSE41) || defined (USE_SSE)

// Scalar (or wrapper) to backend raw type. Raw intrinsic types (__m128, __m256, __m512, ...) have no
// constructor from scalars, so the conversion goes through the wrapper struct which has one.
// For packed/scalar backends the raw type is the wrapper itself, so this is a plain construction.
template<typename T> inline simdfloat_internal make_simdfloat_internal(const T& _val) { return simdfloat(_val); }
template<typename T> inline simddouble_internal make_simddouble_internal(const T& _val) { return simddouble(_val); }
template<typename T> inline simdint_internal make_simdint_internal(const T& _val) { return simdint(_val); }

// Some useful constants
static const simdfloat SIMDZERO = 0.0f;
static const simdfloat SIMDONE = 1.0f;
static const simdfloat SIMDTWO = 2.0f;
static const simdfloat SIMDHALF = 0.5f;
static const simdfloat SIMDPI = 3.1415927f;
static const simdfloat SIMDTWOPI = 6.2831855f;
static const simdfloat SIMDHALFPI = 1.5707964f;

static const simddouble SIMDDZERO = 0.0;
static const simddouble SIMDDONE = 1.0;
static const simddouble SIMDDTWO = 2.0;
static const simddouble SIMDDHALF = 0.5;
static const simddouble SIMDDPI = 3.141592653589793;
static const simddouble SIMDDTWOPI = 6.283185307179586;
static const simddouble SIMDDHALFPI = 1.5707963267948966;

static const simdint SIMDIZERO = 0;
static const simdint SIMDIONE = 1;
static const simdint SIMDITWO = 2;






#endif // SIMD_DEFINITIONS_H

