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
 
#ifndef SIMD_OPERATORS
#define SIMD_OPERATORS

#include "simd_definitions.h"
#include "simd_vectors.h"
#include "simd_matrix.h"

#pragma region float operators
#pragma region simd comparison operators
inline simdmask operator>(const simdfloat& _a, const simdfloat& _b) {
	return simd_cmp_float(_a, _b, _CMP_GT_OQ);
}

inline simdmask operator>(const simdfloat& _a, const float& _b) {
	return simd_cmp_float(_a, simd_set1_float(_b), _CMP_GT_OQ);
}

inline simdmask operator>(const float& _a, const simdfloat& _b) {
	return simd_cmp_float(simd_set1_float(_a), _b, _CMP_GT_OQ);
}

inline simdmask operator<(const simdfloat& _a, const simdfloat& _b) {
	return simd_cmp_float(_a, _b, _CMP_LT_OQ);
}

inline simdmask operator<(const simdfloat& _a, const float& _b) {
	return simd_cmp_float(_a, simd_set1_float(_b), _CMP_LT_OQ);
}

inline simdmask operator<(const float& _a, const simdfloat& _b) {
	return simd_cmp_float(simd_set1_float(_a), _b, _CMP_LT_OQ);
}

inline simdmask operator>=(const simdfloat& _a, const simdfloat& _b) {
	return simd_cmp_float(_a, _b, _CMP_GE_OQ);
}

inline simdmask operator>=(const simdfloat& _a, const float& _b) {
	return simd_cmp_float(_a, simd_set1_float(_b), _CMP_GE_OQ);
}

inline simdmask operator<=(const simdfloat& _a, const simdfloat& _b) {
	return simd_cmp_float(_a, _b, _CMP_LE_OQ);
}

inline simdmask operator<=(const simdfloat& _a, const float& _b) {
	return simd_cmp_float(_a, simd_set1_float(_b), _CMP_LE_OQ);
}

inline simdmask operator==(const simdfloat& _a, const simdfloat& _b) {
	return simd_cmp_float(_a, _b, _CMP_EQ_OQ);
}

inline simdmask operator==(const simdfloat& _a, const float& _b) {
	return simd_cmp_float(_a, simd_set1_float(_b), _CMP_EQ_OQ);
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdmask operator==(const simdfloat& _a, const T& _b) {
	return simd_cmp_float(_a, simd_set1_float(static_cast<float>(_b)), _CMP_EQ_OQ);
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdmask operator<(const simdfloat& _a, const T& _b) {
	return simd_cmp_float(_a, simd_set1_float(static_cast<float>(_b)), _CMP_LT_OQ);
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdmask operator<(const T& _a, const simdfloat& _b) {
	return simd_cmp_float(simd_set1_float(static_cast<float>(_a)), _b, _CMP_LT_OQ);
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdmask operator>(const simdfloat& _a, const T& _b) {
	return simd_cmp_float(_a, simd_set1_float(static_cast<float>(_b)), _CMP_GT_OQ);
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdmask operator>(const T& _a, const simdfloat& _b) {
	return simd_cmp_float(simd_set1_float(static_cast<float>(_a)), _b, _CMP_GT_OQ);
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdmask operator<=(const simdfloat& _a, const T& _b) {
	return simd_cmp_float(_a, simd_set1_float(static_cast<float>(_b)), _CMP_LE_OQ);
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdmask operator>=(const simdfloat& _a, const T& _b) {
	return simd_cmp_float(_a, simd_set1_float(static_cast<float>(_b)), _CMP_GE_OQ);
}

inline simdmask operator&&(const simdmask& _a, const simdmask& _b) {
#ifdef USE_AVX512
	return simdmask(_a.value & _b.value);
#else
	return simd_and_float(_a, _b);
#endif
}

inline simdmask operator||(const simdmask& _a, const simdmask& _b) {
#ifdef USE_AVX512
	return simdmask(_a.value | _b.value);
#else
	return simd_or_float(_a, _b);
#endif
}

#pragma endregion simd comparison operators

#pragma region vector operators

// arithmetic scalar operands; exact float overloads still win over these templates
template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdfloat operator+(const simdfloat& _a, const T& _b)
{
	return simd_add_float(_a, simd_set1_float(static_cast<float>(_b)));
}
template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdfloat operator-(const simdfloat& _a, const T& _b)
{
	return simd_sub_float(_a, simd_set1_float(static_cast<float>(_b)));
}
template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdfloat operator*(const simdfloat& _a, const T& _b)
{
	return simd_mul_float(_a, simd_set1_float(static_cast<float>(_b)));
}
template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdfloat operator/(const simdfloat& _a, const T& _b)
{
	return simd_div_float(_a, simd_set1_float(static_cast<float>(_b)));
}

template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdfloat operator+(const T& _a, const simdfloat& _b)
{
	return simd_add_float(simd_set1_float(static_cast<float>(_a)), _b);
}
template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdfloat operator-(const T& _a, const simdfloat& _b)
{
	return simd_sub_float(simd_set1_float(static_cast<float>(_a)), _b);
}
template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdfloat operator*(const T& _a, const simdfloat& _b)
{
	return simd_mul_float(simd_set1_float(static_cast<float>(_a)), _b);
}
template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
inline simdfloat operator/(const T& _a, const simdfloat& _b)
{
	return simd_div_float(simd_set1_float(static_cast<float>(_a)), _b);
}

// unary negation
inline simdfloat operator-(const simdfloat& _a)
{
	return simd_sub_float(simd_set1_float(0.0f), _a);
}

// pre-increment operator for simdfloat with proper return _value
inline simdfloat& operator++(simdfloat& _a)
{
	simdfloat one = simd_set1_float(1.0f);
	_a = simd_add_float(_a, one);
	return _a;
}

inline simdfloat& operator--(simdfloat& _a)
{
	simdfloat one = simd_set1_float(-1.0f);
	_a = simd_add_float(_a, one);
	return _a;
}

// post-increment operator for simdfloat with proper return _value
inline simdfloat operator++(simdfloat& _a, int32_t)
{
	simdfloat temp = _a;
	_a = simd_add_float(_a, simd_set1_float(1.0f));
	return temp;
}
inline simdfloat operator--(simdfloat& _a, int32_t)
{
	simdfloat temp = _a;
	_a = simd_add_float(_a, simd_set1_float(-1.0f));
	return temp;
}

// common math operators for AVX types
inline simdfloat operator+(const simdfloat& _a, const simdfloat& _b)
{
	return simd_add_float(_a, _b);
}
inline simdfloat operator-(const simdfloat& _a, const simdfloat& _b)
{
	return simd_sub_float(_a, _b);
}
inline simdfloat operator*(const simdfloat& _a, const simdfloat& _b)
{
	return simd_mul_float(_a, _b);
}
inline simdfloat operator/(const simdfloat& _a, const simdfloat& _b)
{
	return simd_div_float(_a, _b);
}

inline simdfloat operator+=(simdfloat& _a, const simdfloat& _b)
{
	_a = simd_add_float(_a, _b);
	return _a;
}
inline simdfloat operator-=(simdfloat& _a, const simdfloat& _b)
{
	_a = simd_sub_float(_a, _b);
	return _a;
}
inline simdfloat operator*=(simdfloat& _a, const simdfloat& _b)
{
	_a = simd_mul_float(_a, _b);
	return _a;
}
inline simdfloat operator/=(simdfloat& _a, const simdfloat& _b)
{
	_a = simd_div_float(_a, _b);
	return _a;
}

inline simdfloat operator+(const simdfloat& _a, const float& _b)
{
	return simd_add_float(_a, simd_set1_float(_b));
}
inline simdfloat operator-(const simdfloat& _a, const float& _b)
{
	return simd_sub_float(_a, simd_set1_float(_b));
}
inline simdfloat operator*(const simdfloat& _a, const float& _b)
{
	return simd_mul_float(_a, simd_set1_float(_b));
}
inline simdfloat operator/(const simdfloat& _a, const float& _b)
{
	return simd_div_float(_a, simd_set1_float(_b));
}

inline simdfloat operator+=(simdfloat& _a, const float& _b)
{
	_a += simd_set1_float(_b);
	return _a;
}
inline simdfloat operator-=(simdfloat& _a, const float& _b)
{
	_a -= simd_set1_float(_b);
	return _a;
}
inline simdfloat operator*=(simdfloat& _a, const float& _b)
{
	_a *= simd_set1_float(_b);
	return _a;
}
inline simdfloat operator/=(simdfloat& _a, const float& _b)
{
	_a /= simd_set1_float(_b);
	return _a;
}

inline simdfloat operator+(const float& _a, const simdfloat& _b)
{
	return simd_add_float(simd_set1_float(_a), _b);
}
inline simdfloat operator-(const float& _a, const simdfloat& _b)
{
	return simd_sub_float(simd_set1_float(_a), _b);
}
inline simdfloat operator*(const float& _a, const simdfloat& _b)
{
	return simd_mul_float(simd_set1_float(_a), _b);
}
inline simdfloat operator/(const float& _a, const simdfloat& _b)
{
	return simd_div_float(simd_set1_float(_a), _b);
}

// Vec2 operators
inline vec2 operator-(const vec2& _a)
{
	return { -_a.x, -_a.y };
}

inline vec2 operator+(const vec2& _a, const float& _b)
{
	return { _a.x + _b, _a.y + _b };
}
inline vec2 operator-(const vec2& _a, const float& _b)
{
	return { _a.x - _b, _a.y - _b };
}
inline vec2 operator*(const vec2& _a, const float& _b)
{
	return { _a.x * _b, _a.y * _b };
}
inline vec2 operator/(const vec2& _a, const float& _b)
{
	return { _a.x / _b, _a.y / _b };
}

inline vec2 operator+(const float& _a, const vec2& _b)
{
	return { _a + _b.x, _a + _b.y };
}
inline vec2 operator-(const float& _a, const vec2& _b)
{
	return { _a - _b.x, _a - _b.y };
}
inline vec2 operator*(const float& _a, const vec2& _b)
{
	return { _a * _b.x, _a * _b.y };
}
inline vec2 operator/(const float& _a, const vec2& _b)
{
	return { _a / _b.x, _a / _b.y };
}

inline vec2 operator+=(vec2& _a, const float& _b)
{
	_a.x += _b;
	_a.y += _b;
	return _a;
}
inline vec2 operator-=(vec2& _a, const float& _b)
{
	_a.x -= _b;
	_a.y -= _b;
	return _a;
}
inline vec2 operator*=(vec2& _a, const float& _b)
{
	_a.x *= _b;
	_a.y *= _b;
	return _a;
}
inline vec2 operator/=(vec2& _a, const float& _b)
{
	_a.x /= _b;
	_a.y /= _b;
	return _a;
}

// vec2 and simdfloat
inline vec2 operator+(const vec2& _a, const simdfloat& _b)
{
	return { _a.x + _b, _a.y + _b };
}
inline vec2 operator-(const vec2& _a, const simdfloat& _b)
{
	return { _a.x - _b, _a.y - _b };
}
inline vec2 operator*(const vec2& _a, const simdfloat& _b)
{
	return { _a.x * _b, _a.y * _b };
}
inline vec2 operator/(const vec2& _a, const simdfloat& _b)
{
	return { _a.x / _b, _a.y / _b };
}

inline vec2 operator+(const simdfloat& _a, const vec2& _b)
{
	return { _a + _b.x, _a + _b.y };
}
inline vec2 operator-(const simdfloat& _a, const vec2& _b)
{
	return { _a - _b.x, _a - _b.y };
}
inline vec2 operator*(const simdfloat& _a, const vec2& _b)
{
	return { _a * _b.x, _a * _b.y };
}
inline vec2 operator/(const simdfloat& _a, const vec2& _b)
{
	return { _a / _b.x, _a / _b.y };
}

inline vec2 operator+=(vec2& _a, const simdfloat& _b)
{
	_a = _a + _b;
	return _a;
}
inline vec2 operator-=(vec2& _a, const simdfloat& _b)
{
	_a = _a - _b;
	return _a;
}
inline vec2 operator*=(vec2& _a, const simdfloat& _b)
{
	_a = _a * _b;
	return _a;
}
inline vec2 operator/=(vec2& _a, const simdfloat& _b)
{
	_a = _a / _b;
	return _a;
}

// vec2 and vec2
inline vec2 operator+(const vec2& _a, const vec2& _b)
{
	return { _a.x + _b.x, _a.y + _b.y };
}
inline vec2 operator-(const vec2& _a, const vec2& _b)
{
	return { _a.x - _b.x, _a.y - _b.y };
}
inline vec2 operator*(const vec2& _a, const vec2& _b)
{
	return { _a.x * _b.x, _a.y * _b.y };
}
inline vec2 operator/(const vec2& _a, const vec2& _b)
{
	return { _a.x / _b.x, _a.y / _b.y };
}

inline vec2 operator+=(vec2& _a, const vec2& _b)
{
	_a = _a + _b;
	return _a;
}
inline vec2 operator-=(vec2& _a, const vec2& _b)
{
	_a = _a - _b;
	return _a;
}
inline vec2 operator*=(vec2& _a, const vec2& _b)
{
	_a = _a * _b;
	return _a;
}
inline vec2 operator/=(vec2& _a, const vec2& _b)
{
	_a = _a / _b;
	return _a;
}

// Vec3 operators
inline vec3 operator-(const vec3& _a)
{
	return { -_a.x, -_a.y, -_a.z };
}

inline vec3 operator+(const vec3& _a, const float& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b };
}
inline vec3 operator-(const vec3& _a, const float& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b };
}
inline vec3 operator*(const vec3& _a, const float& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b };
}
inline vec3 operator/(const vec3& _a, const float& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b };
}

inline vec3 operator+(const float& _a, const vec3& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z };
}
inline vec3 operator-(const float& _a, const vec3& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z };
}
inline vec3 operator*(const float& _a, const vec3& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z };
}
inline vec3 operator/(const float& _a, const vec3& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z };
}

inline vec3 operator+=(vec3& _a, const float& _b)
{
	_a = _a + _b;
	return _a;
}
inline vec3 operator-=(vec3& _a, const float& _b)
{
	_a = _a - _b;
	return _a;
}
inline vec3 operator*=(vec3& _a, const float& _b)
{
	_a = _a * _b;
	return _a;
}
inline vec3 operator/=(vec3& _a, const float& _b)
{
	_a = _a / _b;
	return _a;
}

// vec3 and simdfloat
inline vec3 operator+(const vec3& _a, const simdfloat& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b };
}
inline vec3 operator-(const vec3& _a, const simdfloat& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b };
}
inline vec3 operator*(const vec3& _a, const simdfloat& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b };
}
inline vec3 operator/(const vec3& _a, const simdfloat& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b };
}

inline vec3 operator+(const simdfloat& _a, const vec3& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z };
}
inline vec3 operator-(const simdfloat& _a, const vec3& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z };
}
inline vec3 operator*(const simdfloat& _a, const vec3& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z };
}
inline vec3 operator/(const simdfloat& _a, const vec3& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z };
}

inline vec3 operator+=(vec3& _a, const simdfloat& _b)
{
	_a = _a + _b;
	return _a;
}
inline vec3 operator-=(vec3& _a, const simdfloat& _b)
{
	_a = _a - _b;
	return _a;
}
inline vec3 operator*=(vec3& _a, const simdfloat& _b)
{
	_a = _a * _b;
	return _a;
}
inline vec3 operator/=(vec3& _a, const simdfloat& _b)
{
	_a = _a / _b;
	return _a;
}

// vec3 and vec3
inline vec3 operator+(const vec3& _a, const vec3& _b)
{
	return { _a.x + _b.x, _a.y + _b.y, _a.z + _b.z };
}
inline vec3 operator-(const vec3& _a, const vec3& _b)
{
	return { _a.x - _b.x, _a.y - _b.y, _a.z - _b.z };
}
inline vec3 operator*(const vec3& _a, const vec3& _b)
{
	return { _a.x * _b.x, _a.y * _b.y, _a.z * _b.z };
}
inline vec3 operator/(const vec3& _a, const vec3& _b)
{
	return { _a.x / _b.x, _a.y / _b.y, _a.z / _b.z };
}

inline vec3 operator+=(vec3& _a, const vec3& _b)
{
	_a = _a + _b;
	return _a;
}
inline vec3 operator-=(vec3& _a, const vec3& _b)
{
	_a = _a - _b;
	return _a;
}
inline vec3 operator*=(vec3& _a, const vec3& _b)
{
	_a = _a * _b;
	return _a;
}
inline vec3 operator/=(vec3& _a, const vec3& _b)
{
	_a = _a / _b;
	return _a;
}

// Vec4 operators
inline vec4 operator-(const vec4& _a)
{
	return { -_a.x, -_a.y, -_a.z, -_a.w };
}

inline vec4 operator+(const vec4& _a, const float& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b, _a.w + _b };
}
inline vec4 operator-(const vec4& _a, const float& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b, _a.w - _b };
}
inline vec4 operator*(const vec4& _a, const float& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b, _a.w * _b };
}
inline vec4 operator/(const vec4& _a, const float& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b, _a.w / _b };
}
inline vec4 operator+(const float& _a, const vec4& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z, _a + _b.w };
}
inline vec4 operator-(const float& _a, const vec4& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z, _a - _b.w };
}
inline vec4 operator*(const float& _a, const vec4& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z, _a * _b.w };
}
inline vec4 operator/(const float& _a, const vec4& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z, _a / _b.w };
}

inline vec4 operator+=(vec4& _a, const float& _b)
{
	_a = _a + _b;
	return _a;
}
inline vec4 operator-=(vec4& _a, const float& _b)
{
	_a = _a - _b;
	return _a;
}
inline vec4 operator*=(vec4& _a, const float& _b)
{
	_a = _a * _b;
	return _a;
}
inline vec4 operator/=(vec4& _a, const float& _b)
{
	_a = _a / _b;
	return _a;
}

// vec4 and simdfloat
inline vec4 operator+(const vec4& _a, const simdfloat& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b, _a.w + _b };
}
inline vec4 operator-(const vec4& _a, const simdfloat& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b, _a.w - _b };
}
inline vec4 operator*(const vec4& _a, const simdfloat& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b, _a.w * _b };
}
inline vec4 operator/(const vec4& _a, const simdfloat& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b, _a.w / _b };
}
inline vec4 operator+(const simdfloat& _a, const vec4& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z, _a + _b.w };
}
inline vec4 operator-(const simdfloat& _a, const vec4& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z, _a - _b.w };
}
inline vec4 operator*(const simdfloat& _a, const vec4& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z, _a * _b.w };
}
inline vec4 operator/(const simdfloat& _a, const vec4& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z, _a / _b.w };
}

inline vec4 operator+=(vec4& _a, const simdfloat& _b)
{
	_a = _a + _b;
	return _a;
}
inline vec4 operator-=(vec4& _a, const simdfloat& _b)
{
	_a = _a - _b;
	return _a;
}
inline vec4 operator*=(vec4& _a, const simdfloat& _b)
{
	_a = _a * _b;
	return _a;
}
inline vec4 operator/=(vec4& _a, const simdfloat& _b)
{
	_a = _a / _b;
	return _a;
}

// vec4 and vec4
inline vec4 operator+(const vec4& _a, const vec4& _b)
{
	return { _a.x + _b.x, _a.y + _b.y, _a.z + _b.z, _a.w + _b.w };
}
inline vec4 operator-(const vec4& _a, const vec4& _b)
{
	return { _a.x - _b.x, _a.y - _b.y, _a.z - _b.z, _a.w - _b.w };
}
inline vec4 operator*(const vec4& _a, const vec4& _b)
{
	return { _a.x * _b.x, _a.y * _b.y, _a.z * _b.z, _a.w * _b.w };
}
inline vec4 operator/(const vec4& _a, const vec4& _b)
{
	return { _a.x / _b.x, _a.y / _b.y, _a.z / _b.z, _a.w / _b.w };
}

inline vec4 operator+=(vec4& _a, const vec4& _b)
{
	_a = _a + _b;
	return _a;
}
inline vec4 operator-=(vec4& _a, const vec4& _b)
{
	_a = _a - _b;
	return _a;
}
inline vec4 operator*=(vec4& _a, const vec4& _b)
{
	_a = _a * _b;
	return _a;
}
inline vec4 operator/=(vec4& _a, const vec4& _b)
{
	_a = _a / _b;
	return _a;
}

#pragma endregion

#pragma region std::cout operators
#ifndef USE_AVX512
inline std::ostream& operator<<(std::ostream& _os, const simdmask& _v)
{
	alignas(SIMDWIDTH * 4) float arr[SIMDWIDTH];
	simd_store_float(arr, _v);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		_os << arr[i];
		if (i < SIMDWIDTH - 1) _os << ", ";
	}
	return _os;
}
#endif // USE_AVX512
inline std::ostream& operator<<(std::ostream& _os, const simdfloat& _v)
{
	alignas(SIMDWIDTH * 4) float arr[SIMDWIDTH];
	simd_store_float(arr, _v);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		_os << arr[i];
		if (i < SIMDWIDTH - 1) _os << ", ";
	}
	return _os;
}


inline std::ostream& operator<<(std::ostream& _os, const vec2& _v)
{
	_os << "[" << _v.x << "]" << ", " << "[" << _v.y << "]";
	return _os;
}
inline std::ostream& operator<<(std::ostream& _os, const vec3& _v)
{
	_os << "[" << _v.x << "]" << ", " << "[" << _v.y << "]" << ", " << "[" << _v.z << "]";
	return _os;
}
inline std::ostream& operator<<(std::ostream& _os, const vec4& _v)
{
	_os << "[" << _v.x << "]" << ", " << "[" << _v.y << "]" << ", " << "[" << _v.z << "]" << ", " << "[" << _v.w << "]";
	return _os;
}

// overload << for mat2, mat3, mat4
inline std::ostream& operator<<(std::ostream& _os, const mat2& _m)
{
	_os << "[" << _m.columns[0] << "]" << std::endl << "[" << _m.columns[1] << "]";
	return _os;
}

inline std::ostream& operator<<(std::ostream& _os, const mat3& _m)
{
	_os << "[" << _m.columns[0] << "]" << std::endl << "[" << _m.columns[1] << "]" << std::endl << "[" << _m.columns[2] << "]";
	return _os;
}

inline std::ostream& operator<<(std::ostream& _os, const mat4& _m)
{
	_os << "[" << _m.columns[0] << "]" << std::endl << "[" << _m.columns[1] << "]" << std::endl << "[" << _m.columns[2] << "]" << std::endl << "[" << _m.columns[3] << "]";
	return _os;
}

#pragma endregion
#pragma endregion float operators

#pragma region double operators
#pragma region double simd comparison operators

inline simddmask operator>(const simddouble& _a, const simddouble& _b) {
	return simd_cmp_double(_a, _b, _CMP_GT_OQ);
}

inline simddmask operator>(const simddouble& _a, const double& _b) {
	return simd_cmp_double(_a, simd_set1_double(_b), _CMP_GT_OQ);
}

inline simddmask operator>(const double& _a, const simddouble& _b) {
	return simd_cmp_double(simd_set1_double(_a), _b, _CMP_GT_OQ);
}

inline simddmask operator<(const simddouble& _a, const simddouble& _b) {
	return simd_cmp_double(_a, _b, _CMP_LT_OQ);
}

inline simddmask operator<(const simddouble& _a, const double& _b) {
	return simd_cmp_double(_a, simd_set1_double(_b), _CMP_LT_OQ);
}

inline simddmask operator<(const double& _a, const simddouble& _b) {
	return simd_cmp_double(simd_set1_double(_a), _b, _CMP_LT_OQ);
}

inline simddmask operator>=(const simddouble& _a, const simddouble& _b) {
	return simd_cmp_double(_a, _b, _CMP_GE_OQ);
}

inline simddmask operator>=(const simddouble& _a, const double& _b) {
	return simd_cmp_double(_a, simd_set1_double(_b), _CMP_GE_OQ);
}

inline simddmask operator<=(const simddouble& _a, const simddouble& _b) {
	return simd_cmp_double(_a, _b, _CMP_LE_OQ);
}

inline simddmask operator<=(const simddouble& _a, const double& _b) {
	return simd_cmp_double(_a, simd_set1_double(_b), _CMP_LE_OQ);
}

inline simddmask operator==(const simddouble& _a, const simddouble& _b) {
	return simd_cmp_double(_a, _b, _CMP_EQ_OQ);
}

inline simddmask operator==(const simddouble& _a, const double& _b) {
	return simd_cmp_double(_a, simd_set1_double(_b), _CMP_EQ_OQ);
}

inline simddmask operator&&(const simddmask& _a, const simddmask& _b) {
#ifdef USE_AVX512
	return simddmask(_a.value & _b.value);
#else
	return simd_and_double(_a, _b);
#endif
}

inline simddmask operator||(const simddmask& _a, const simddmask& _b) {
#ifdef USE_AVX512
	return simddmask(_a.value | _b.value);
#else
	return simd_or_double(_a, _b);
#endif
}

#pragma endregion simd comparison operators

#pragma region vector operators

// unary negation
inline simddouble operator-(const simddouble& _a)
{
	return simd_sub_double(simd_set1_double(0.0f), _a);
}

// pre-increment operator for simddouble with proper return _value
inline simddouble& operator++(simddouble& _a)
{
	simddouble one = simd_set1_double(1.0);
	_a = simd_add_double(_a, one);
	return _a;
}

inline simddouble& operator--(simddouble& _a)
{
	simddouble one = simd_set1_double(-1.0);
	_a = simd_add_double(_a, one);
	return _a;
}

// post-increment operator for simddouble with proper return _value
inline simddouble operator++(simddouble& _a, int32_t)
{
	simddouble temp = _a;
	_a = simd_add_double(_a, simd_set1_double(1.0));
	return temp;
}
inline simddouble operator--(simddouble& _a, int32_t)
{
	simddouble temp = _a;
	_a = simd_add_double(_a, simd_set1_double(-1.0));
	return temp;
}

// common dmath operators for AVX types
inline simddouble operator+(const simddouble& _a, const simddouble& _b)
{
	return simd_add_double(_a, _b);
}
inline simddouble operator-(const simddouble& _a, const simddouble& _b)
{
	return simd_sub_double(_a, _b);
}
inline simddouble operator*(const simddouble& _a, const simddouble& _b)
{
	return simd_mul_double(_a, _b);
}
inline simddouble operator/(const simddouble& _a, const simddouble& _b)
{
	return simd_div_double(_a, _b);
}

inline simddouble operator+=(simddouble& _a, const simddouble& _b)
{
	_a = simd_add_double(_a, _b);
	return _a;
}
inline simddouble operator-=(simddouble& _a, const simddouble& _b)
{
	_a = simd_sub_double(_a, _b);
	return _a;
}
inline simddouble operator*=(simddouble& _a, const simddouble& _b)
{
	_a = simd_mul_double(_a, _b);
	return _a;
}
inline simddouble operator/=(simddouble& _a, const simddouble& _b)
{
	_a = _a / _b;
	return _a;
}

inline simddouble operator+(const simddouble& _a, const double& _b)
{
	return simd_add_double(_a, simd_set1_double(_b));
}
inline simddouble operator-(const simddouble& _a, const double& _b)
{
	return simd_sub_double(_a, simd_set1_double(_b));
}
inline simddouble operator*(const simddouble& _a, const double& _b)
{
	return simd_mul_double(_a, simd_set1_double(_b));
}
inline simddouble operator/(const simddouble& _a, const double& _b)
{
	return simd_div_double(_a, simd_set1_double(_b));
}

inline simddouble operator+=(simddouble& _a, const double& _b)
{
	_a += simd_set1_double(_b);
	return _a;
}
inline simddouble operator-=(simddouble& _a, const double& _b)
{
	_a -= simd_set1_double(_b);
	return _a;
}
inline simddouble operator*=(simddouble& _a, const double& _b)
{
	_a *= simd_set1_double(_b);
	return _a;
}
inline simddouble operator/=(simddouble& _a, const double& _b)
{
	_a /= simd_set1_double(_b);
	return _a;
}

inline simddouble operator+(const double& _a, const simddouble& _b)
{
	return simd_add_double(simd_set1_double(_a), _b);
}
inline simddouble operator-(const double& _a, const simddouble& _b)
{
	return simd_sub_double(simd_set1_double(_a), _b);
}
inline simddouble operator*(const double& _a, const simddouble& _b)
{
	return simd_mul_double(simd_set1_double(_a), _b);
}
inline simddouble operator/(const double& _a, const simddouble& _b)
{
	return simd_div_double(simd_set1_double(_a), _b);
}

// dvec2 operators
// unary negation
inline dvec2 operator-(const dvec2& _a)
{
	return { -_a.x, -_a.y };
}

inline dvec2 operator+(const dvec2& _a, const double& _b)
{
	return { _a.x + _b, _a.y + _b };
}
inline dvec2 operator-(const dvec2& _a, const double& _b)
{
	return { _a.x - _b, _a.y - _b };
}
inline dvec2 operator*(const dvec2& _a, const double& _b)
{
	return { _a.x * _b, _a.y * _b };
}
inline dvec2 operator/(const dvec2& _a, const double& _b)
{
	return { _a.x / _b, _a.y / _b };
}

inline dvec2 operator+(const double& _a, const dvec2& _b)
{
	return { _a + _b.x, _a + _b.y };
}
inline dvec2 operator-(const double& _a, const dvec2& _b)
{
	return { _a - _b.x, _a - _b.y };
}
inline dvec2 operator*(const double& _a, const dvec2& _b)
{
	return { _a * _b.x, _a * _b.y };
}
inline dvec2 operator/(const double& _a, const dvec2& _b)
{
	return { _a / _b.x, _a / _b.y };
}

inline dvec2 operator+=(dvec2& _a, const double& _b)
{
	_a.x += _b;
	_a.y += _b;
	return _a;
}
inline dvec2 operator-=(dvec2& _a, const double& _b)
{
	_a.x -= _b;
	_a.y -= _b;
	return _a;
}
inline dvec2 operator*=(dvec2& _a, const double& _b)
{
	_a.x *= _b;
	_a.y *= _b;
	return _a;
}
inline dvec2 operator/=(dvec2& _a, const double& _b)
{
	_a.x /= _b;
	_a.y /= _b;
	return _a;
}

// dvec2 and simddouble
inline dvec2 operator+(const dvec2& _a, const simddouble& _b)
{
	return { _a.x + _b, _a.y + _b };
}
inline dvec2 operator-(const dvec2& _a, const simddouble& _b)
{
	return { _a.x - _b, _a.y - _b };
}
inline dvec2 operator*(const dvec2& _a, const simddouble& _b)
{
	return { _a.x * _b, _a.y * _b };
}
inline dvec2 operator/(const dvec2& _a, const simddouble& _b)
{
	return { _a.x / _b, _a.y / _b };
}

inline dvec2 operator+(const simddouble& _a, const dvec2& _b)
{
	return { _a + _b.x, _a + _b.y };
}
inline dvec2 operator-(const simddouble& _a, const dvec2& _b)
{
	return { _a - _b.x, _a - _b.y };
}
inline dvec2 operator*(const simddouble& _a, const dvec2& _b)
{
	return { _a * _b.x, _a * _b.y };
}
inline dvec2 operator/(const simddouble& _a, const dvec2& _b)
{
	return { _a / _b.x, _a / _b.y };
}

inline dvec2 operator+=(dvec2& _a, const simddouble& _b)
{
	_a = _a + _b;
	return _a;
}
inline dvec2 operator-=(dvec2& _a, const simddouble& _b)
{
	_a = _a - _b;
	return _a;
}
inline dvec2 operator*=(dvec2& _a, const simddouble& _b)
{
	_a = _a * _b;
	return _a;
}
inline dvec2 operator/=(dvec2& _a, const simddouble& _b)
{
	_a = _a / _b;
	return _a;
}

// dvec2 and dvec2
inline dvec2 operator+(const dvec2& _a, const dvec2& _b)
{
	return { _a.x + _b.x, _a.y + _b.y };
}
inline dvec2 operator-(const dvec2& _a, const dvec2& _b)
{
	return { _a.x - _b.x, _a.y - _b.y };
}
inline dvec2 operator*(const dvec2& _a, const dvec2& _b)
{
	return { _a.x * _b.x, _a.y * _b.y };
}
inline dvec2 operator/(const dvec2& _a, const dvec2& _b)
{
	return { _a.x / _b.x, _a.y / _b.y };
}

inline dvec2 operator+=(dvec2& _a, const dvec2& _b)
{
	_a = _a + _b;
	return _a;
}
inline dvec2 operator-=(dvec2& _a, const dvec2& _b)
{
	_a = _a - _b;
	return _a;
}
inline dvec2 operator*=(dvec2& _a, const dvec2& _b)
{
	_a = _a * _b;
	return _a;
}
inline dvec2 operator/=(dvec2& _a, const dvec2& _b)
{
	_a = _a / _b;
	return _a;
}

// dvec3 operators
inline dvec3 operator-(const dvec3& _a)
{
	return { -_a.x, -_a.y, -_a.z };
}

// dvec3 and simddouble
inline dvec3 operator+(const dvec3& _a, const double& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b };
}
inline dvec3 operator-(const dvec3& _a, const double& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b };
}
inline dvec3 operator*(const dvec3& _a, const double& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b };
}
inline dvec3 operator/(const dvec3& _a, const double& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b };
}

inline dvec3 operator+(const double& _a, const dvec3& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z };
}
inline dvec3 operator-(const double& _a, const dvec3& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z };
}
inline dvec3 operator*(const double& _a, const dvec3& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z };
}
inline dvec3 operator/(const double& _a, const dvec3& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z };
}

inline dvec3 operator+=(dvec3& _a, const double& _b)
{
	_a = _a + _b;
	return _a;
}
inline dvec3 operator-=(dvec3& _a, const double& _b)
{
	_a = _a - _b;
	return _a;
}
inline dvec3 operator*=(dvec3& _a, const double& _b)
{
	_a = _a * _b;
	return _a;
}
inline dvec3 operator/=(dvec3& _a, const double& _b)
{
	_a = _a / _b;
	return _a;
}

// dvec3 and simddouble
inline dvec3 operator+(const dvec3& _a, const simddouble& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b };
}
inline dvec3 operator-(const dvec3& _a, const simddouble& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b };
}
inline dvec3 operator*(const dvec3& _a, const simddouble& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b };
}
inline dvec3 operator/(const dvec3& _a, const simddouble& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b };
}

inline dvec3 operator+(const simddouble& _a, const dvec3& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z };
}
inline dvec3 operator-(const simddouble& _a, const dvec3& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z };
}
inline dvec3 operator*(const simddouble& _a, const dvec3& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z };
}
inline dvec3 operator/(const simddouble& _a, const dvec3& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z };
}

inline dvec3 operator+=(dvec3& _a, const simddouble& _b)
{
	_a = _a + _b;
	return _a;
}
inline dvec3 operator-=(dvec3& _a, const simddouble& _b)
{
	_a = _a - _b;
	return _a;
}
inline dvec3 operator*=(dvec3& _a, const simddouble& _b)
{
	_a = _a * _b;
	return _a;
}
inline dvec3 operator/=(dvec3& _a, const simddouble& _b)
{
	_a = _a / _b;
	return _a;
}

// dvec3 and dvec3
inline dvec3 operator+(const dvec3& _a, const dvec3& _b)
{
	return { _a.x + _b.x, _a.y + _b.y, _a.z + _b.z };
}
inline dvec3 operator-(const dvec3& _a, const dvec3& _b)
{
	return { _a.x - _b.x, _a.y - _b.y, _a.z - _b.z };
}
inline dvec3 operator*(const dvec3& _a, const dvec3& _b)
{
	return { _a.x * _b.x, _a.y * _b.y, _a.z * _b.z };
}
inline dvec3 operator/(const dvec3& _a, const dvec3& _b)
{
	return { _a.x / _b.x, _a.y / _b.y, _a.z / _b.z };
}

inline dvec3 operator+=(dvec3& _a, const dvec3& _b)
{
	_a = _a + _b;
	return _a;
}
inline dvec3 operator-=(dvec3& _a, const dvec3& _b)
{
	_a = _a - _b;
	return _a;
}
inline dvec3 operator*=(dvec3& _a, const dvec3& _b)
{
	_a = _a * _b;
	return _a;
}
inline dvec3 operator/=(dvec3& _a, const dvec3& _b)
{
	_a = _a / _b;
	return _a;
}

// dvec4 operators
inline dvec4 operator-(const dvec4& _a)
{
	return { -_a.x, -_a.y, -_a.z, -_a.w };
}

inline dvec4 operator+(const dvec4& _a, const double& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b, _a.w + _b };
}
inline dvec4 operator-(const dvec4& _a, const double& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b, _a.w - _b };
}
inline dvec4 operator*(const dvec4& _a, const double& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b, _a.w * _b };
}
inline dvec4 operator/(const dvec4& _a, const double& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b, _a.w / _b };
}

inline dvec4 operator+(const double& _a, const dvec4& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z, _a + _b.w };
}
inline dvec4 operator-(const double& _a, const dvec4& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z, _a - _b.w };
}
inline dvec4 operator*(const double& _a, const dvec4& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z, _a * _b.w };
}
inline dvec4 operator/(const double& _a, const dvec4& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z, _a / _b.w };
}

inline dvec4 operator+=(dvec4& _a, const double& _b)
{
	_a = _a + _b;
	return _a;
}
inline dvec4 operator-=(dvec4& _a, const double& _b)
{
	_a = _a - _b;
	return _a;
}
inline dvec4 operator*=(dvec4& _a, const double& _b)
{
	_a = _a * _b;
	return _a;
}
inline dvec4 operator/=(dvec4& _a, const double& _b)
{
	_a = _a / _b;
	return _a;
}

// dvec4 and simddouble
inline dvec4 operator+(const dvec4& _a, const simddouble& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b, _a.w + _b };
}
inline dvec4 operator-(const dvec4& _a, const simddouble& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b, _a.w - _b };
}
inline dvec4 operator*(const dvec4& _a, const simddouble& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b, _a.w * _b };
}
inline dvec4 operator/(const dvec4& _a, const simddouble& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b, _a.w / _b };
}
inline dvec4 operator+(const simddouble& _a, const dvec4& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z, _a + _b.w };
}
inline dvec4 operator-(const simddouble& _a, const dvec4& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z, _a - _b.w };
}
inline dvec4 operator*(const simddouble& _a, const dvec4& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z, _a * _b.w };
}
inline dvec4 operator/(const simddouble& _a, const dvec4& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z, _a / _b.w };
}

inline dvec4 operator+=(dvec4& _a, const simddouble& _b)
{
	_a = _a + _b;
	return _a;
}
inline dvec4 operator-=(dvec4& _a, const simddouble& _b)
{
	_a = _a - _b;
	return _a;
}
inline dvec4 operator*=(dvec4& _a, const simddouble& _b)
{
	_a = _a * _b;
	return _a;
}
inline dvec4 operator/=(dvec4& _a, const simddouble& _b)
{
	_a = _a / _b;
	return _a;
}

// dvec4 and dvec4
inline dvec4 operator+(const dvec4& _a, const dvec4& _b)
{
	return { _a.x + _b.x, _a.y + _b.y, _a.z + _b.z, _a.w + _b.w };
}
inline dvec4 operator-(const dvec4& _a, const dvec4& _b)
{
	return { _a.x - _b.x, _a.y - _b.y, _a.z - _b.z, _a.w - _b.w };
}
inline dvec4 operator*(const dvec4& _a, const dvec4& _b)
{
	return { _a.x * _b.x, _a.y * _b.y, _a.z * _b.z, _a.w * _b.w };
}
inline dvec4 operator/(const dvec4& _a, const dvec4& _b)
{
	return { _a.x / _b.x, _a.y / _b.y, _a.z / _b.z, _a.w / _b.w };
}

inline dvec4 operator+=(dvec4& _a, const dvec4& _b)
{
	_a = _a + _b;
	return _a;
}
inline dvec4 operator-=(dvec4& _a, const dvec4& _b)
{
	_a = _a - _b;
	return _a;
}
inline dvec4 operator*=(dvec4& _a, const dvec4& _b)
{
	_a = _a * _b;
	return _a;
}
inline dvec4 operator/=(dvec4& _a, const dvec4& _b)
{
	_a = _a / _b;
	return _a;
}
#pragma endregion
#pragma region std::cout operators
#ifndef USE_AVX512
inline std::ostream& operator<<(std::ostream& _os, const simddmask& _v)
{
	alignas(HALFSIMDWIDTH * 8) double arr[8];
	simd_store_double(arr, _v);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		_os << arr[i];
		if (i < HALFSIMDWIDTH - 1) _os << ", ";
	}
	return _os;
}
#endif
inline std::ostream& operator<<(std::ostream& _os, const simddouble& _v)
{
	alignas(HALFSIMDWIDTH * 8) double arr[8];
	simd_store_double(arr, _v);
	for (int32_t i = 0; i < HALFSIMDWIDTH; i++)
	{
		_os << arr[i];
		if (i < HALFSIMDWIDTH - 1) _os << ", ";
	}
	return _os;
}


inline std::ostream& operator<<(std::ostream& _os, const dvec2& _v)
{
	_os << "[" << _v.x << "]" << ", " << "[" << _v.y << "]";
	return _os;
}
inline std::ostream& operator<<(std::ostream& _os, const dvec3& _v)
{
	_os << "[" << _v.x << "]" << ", " << "[" << _v.y << "]" << ", " << "[" << _v.z << "]";
	return _os;
}
inline std::ostream& operator<<(std::ostream& _os, const dvec4& _v)
{
	_os << "[" << _v.x << "]" << ", " << "[" << _v.y << "]" << ", " << "[" << _v.z << "]" << ", " << "[" << _v.w << "]";
	return _os;
}

// overload << for dmat2, dmat3, dmat4
inline std::ostream& operator<<(std::ostream& _os, const dmat2& _m)
{
	_os << "[" << _m.columns[0] << "]" << std::endl << "[" << _m.columns[1] << "]";
	return _os;
}

inline std::ostream& operator<<(std::ostream& _os, const dmat3& _m)
{
	_os << "[" << _m.columns[0] << "]" << std::endl << "[" << _m.columns[1] << "]" << std::endl << "[" << _m.columns[2] << "]";
	return _os;
}

inline std::ostream& operator<<(std::ostream& _os, const dmat4& _m)
{
	_os << "[" << _m.columns[0] << "]" << std::endl << "[" << _m.columns[1] << "]" << std::endl << "[" << _m.columns[2] << "]" << std::endl << "[" << _m.columns[3] << "]";
	return _os;
}

#pragma endregion
#pragma endregion double operators

#pragma region int32_t operators
#pragma region int32_t simd comparison operators

inline simdimask operator>(const simdint& _a, const simdint& _b) {
	return simd_cmpgt_int(_a, _b);
}

inline simdimask operator>(const simdint& _a, const int32_t& _b) {
	return simd_cmpgt_int(_a, simd_set1_int(_b));
}

inline simdimask operator>(const int32_t& _a, const simdint& _b) {
	return simd_cmpgt_int(simd_set1_int(_a), _b);
}

inline simdimask operator<(const simdint& _a, const simdint& _b) {
	return simd_cmpgt_int(_b, _a);
}

inline simdimask operator<(const simdint& _a, const int32_t& _b) {
	return simd_cmpgt_int(simd_set1_int(_b), _a);
}

inline simdimask operator<(const int32_t& _a, const simdint& _b) {
	return simd_cmpgt_int(_b, simd_set1_int(_a));
}

inline simdimask operator>=(const simdint& _a, const simdint& _b) {
#ifndef USE_AVX512
	return simd_or_int(simd_cmpgt_int(_a, _b), simd_cmpeq_int(_a, _b));
#else
	return (simd_cmpgt_int(_a, _b) | simd_cmpeq_int(_a, _b));
#endif
}

inline simdimask operator>=(const simdint& _a, const int32_t& _b) {
#ifndef USE_AVX512
	return simd_or_int(simd_cmpgt_int(_a, simd_set1_int(_b)), simd_cmpeq_int(_a, simd_set1_int(_b)));
#else
	return simd_cmpgt_int(_a, simd_set1_int(_b)) | simd_cmpeq_int(_a, simd_set1_int(_b));
#endif
}

inline simdimask operator<=(const simdint& _a, const simdint& _b) {
#ifndef USE_AVX512
	return simd_or_int(simd_cmpgt_int(_b, _a), simd_cmpeq_int(_b, _a));
#else
	return simd_cmpgt_int(_b, _a) | simd_cmpeq_int(_b, _a);
#endif
}

inline simdimask operator<=(const simdint& _a, const int32_t& _b) {
#ifndef USE_AVX512
	return simd_or_int(simd_cmpgt_int(simd_set1_int(_b), _a), simd_cmpeq_int(simd_set1_int(_b), _a));
#else
	return simd_cmpgt_int(simd_set1_int(_b), _a) | simd_cmpeq_int(simd_set1_int(_b), _a);
#endif
}

inline simdimask operator==(const simdint& _a, const simdint& _b) {
	return simd_cmpeq_int(_a, _b);
}

inline simdimask operator==(const simdint& _a, const int32_t& _b) {
	return simd_cmpeq_int(_a, simd_set1_int(_b));
}

inline simdimask operator&&(const simdimask& _a, const simdimask& _b) {
#ifdef USE_AVX512
	return simdimask(_a.value & _b.value);
#else
	return simd_and_int(_a, _b);
#endif
}

inline simdimask operator||(const simdimask& _a, const simdimask& _b) {
#ifdef USE_AVX512
	return simdimask(_a.value | _b.value);
#else
	return simd_or_int(_a, _b);
#endif
}



#pragma endregion simd comparison operators

#pragma region ivector operators

// unary negation
inline simdint operator-(const simdint& _a)
{
	return simd_sub_int(simd_set1_int(0), _a);
}

// pre-increment operator for simdint with proper return _value
inline simdint& operator++(simdint& _a)
{
	simdint one = simd_set1_int(1);
	_a = simd_add_int(_a, one);
	return _a;
}

inline simdint& operator--(simdint& _a)
{
	simdint one = simd_set1_int(-1);
	_a = simd_add_int(_a, one);
	return _a;
}

// post-increment operator for simdint with proper return _value
inline simdint operator++(simdint& _a, int32_t)
{
	simdint temp = _a;
	_a = simd_add_int(_a, simd_set1_int(1));
	return temp;
}
inline simdint operator--(simdint& _a, int32_t)
{
	simdint temp = _a;
	_a = simd_add_int(_a, simd_set1_int(-1));
	return temp;
}

// common math operators for AVX types
inline simdint operator+(const simdint& _a, const simdint& _b)
{
	return simd_add_int(_a, _b);
}
inline simdint operator-(const simdint& _a, const simdint& _b)
{
	return simd_sub_int(_a, _b);
}
inline simdint operator*(const simdint& _a, const simdint& _b)
{
	return simd_mul_int(_a, _b);
}
inline simdint operator/(const simdint& _a, const simdint& _b)
{
	alignas(SIMDWIDTH * 4) int32_t arr_a[SIMDWIDTH] = { 0 };
	alignas(SIMDWIDTH * 4) int32_t arr_b[SIMDWIDTH] = { 0 };
	simd_store_int(arr_a, _a);
	simd_store_int(arr_b, _b);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		arr_a[i] /= arr_b[i];
	}

	return simd_load_int(arr_a);
}

inline simdint operator+=(simdint& _a, const simdint& _b)
{
	_a = simd_add_int(_a, _b);
	return _a;
}
inline simdint operator-=(simdint& _a, const simdint& _b)
{
	_a = simd_sub_int(_a, _b);
	return _a;
}
inline simdint operator*=(simdint& _a, const simdint& _b)
{
	_a = simd_mul_int(_a, _b);
	return _a;
}
inline simdint operator/=(simdint& _a, const simdint& _b)
{
	_a = _a / _b;
	return _a;
}

inline simdint operator+(const simdint& _a, const int32_t& _b)
{
	return simd_add_int(_a, simd_set1_int(_b));
}
inline simdint operator-(const simdint& _a, const int32_t& _b)
{
	return simd_sub_int(_a, simd_set1_int(_b));
}
inline simdint operator*(const simdint& _a, const int32_t& _b)
{
	return simd_mul_int(_a, simd_set1_int(_b));
}
inline simdint operator/(const simdint& _a, const int32_t& _b)
{
	return _a / simd_set1_int(_b);
}

inline simdint operator+=(simdint& _a, const int32_t& _b)
{
	_a += simd_set1_int(_b);
	return _a;
}
inline simdint operator-=(simdint& _a, const int32_t& _b)
{
	_a -= simd_set1_int(_b);
	return _a;
}
inline simdint operator*=(simdint& _a, const int32_t& _b)
{
	_a *= simd_set1_int(_b);
	return _a;
}
inline simdint operator/=(simdint& _a, const int32_t& _b)
{
	_a /= simd_set1_int(_b);
	return _a;
}

inline simdint operator+(const int32_t& _a, const simdint& _b)
{
	return simd_add_int(simd_set1_int(_a), _b);
}
inline simdint operator-(const int32_t& _a, const simdint& _b)
{
	return simd_sub_int(simd_set1_int(_a), _b);
}
inline simdint operator*(const int32_t& _a, const simdint& _b)
{
	return simd_mul_int(simd_set1_int(_a), _b);
}
inline simdint operator/(const int32_t& _a, const simdint& _b)
{
	return simd_set1_int(_a)/ _b;
}

inline simdint operator%(const simdint& _a, const simdint& _b)
{
	alignas(SIMDWIDTH * 4) int32_t arr_a[SIMDWIDTH] = { 0 };
	alignas(SIMDWIDTH * 4) int32_t arr_b[SIMDWIDTH] = { 0 };
	simd_store_int(arr_a, _a);
	simd_store_int(arr_b, _b);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		arr_a[i] %= arr_b[i];
	}
	return simd_load_int(arr_a);
}
inline simdint operator%=(simdint& _a, const simdint& _b)
{
	_a = _a % _b;
	return _a;
}
inline simdint operator%(const simdint& _a, const int32_t& _b)
{
	alignas(SIMDWIDTH * 4) int32_t arr_a[SIMDWIDTH] = { 0 };
	simd_store_int(arr_a, _a);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		arr_a[i] %= _b;
	}
	return simd_load_int(arr_a);
}
inline simdint operator%=(simdint& _a, const int32_t& _b)
{
	_a = _a % _b;
	return _a;
}


// ivec2 operators
// unary negation
inline ivec2 operator-(const ivec2& _a)
{
	return { -_a.x, -_a.y };
}

// ivec2 and int32_t
inline ivec2 operator+(const ivec2& _a, const int32_t& _b)
{
	return { _a.x + _b, _a.y + _b };
}
inline ivec2 operator-(const ivec2& _a, const int32_t& _b)
{
	return { _a.x - _b, _a.y - _b };
}
inline ivec2 operator*(const ivec2& _a, const int32_t& _b)
{
	return { _a.x * _b, _a.y * _b };
}
inline ivec2 operator/(const ivec2& _a, const int32_t& _b)
{
	return { _a.x / _b, _a.y / _b };
}
inline ivec2 operator%(const ivec2& _a, const int32_t& _b)
{
	return { _a.x % _b, _a.y % _b };
}

inline ivec2 operator+(const int32_t& _a, const ivec2& _b)
{
	return { _a + _b.x, _a + _b.y };
}
inline ivec2 operator-(const int32_t& _a, const ivec2& _b)
{
	return { _a - _b.x, _a - _b.y };
}
inline ivec2 operator*(const int32_t& _a, const ivec2& _b)
{
	return { _a * _b.x, _a * _b.y };
}
inline ivec2 operator/(const int32_t& _a, const ivec2& _b)
{
	return { _a / _b.x, _a / _b.y };
}

inline ivec2 operator+=(ivec2& _a, const int32_t& _b)
{
	_a.x += _b;
	_a.y += _b;
	return _a;
}
inline ivec2 operator-=(ivec2& _a, const int32_t& _b)
{
	_a.x -= _b;
	_a.y -= _b;
	return _a;
}
inline ivec2 operator*=(ivec2& _a, const int32_t& _b)
{
	_a.x *= _b;
	_a.y *= _b;
	return _a;
}
inline ivec2 operator/=(ivec2& _a, const int32_t& _b)
{
	_a.x /= _b;
	_a.y /= _b;
	return _a;
}
inline ivec2 operator%=(ivec2& _a, const int32_t& _b)
{
	_a.x %= _b;
	_a.y %= _b;
	return _a;
}

// ivec2 and simdint
inline ivec2 operator+(const ivec2& _a, const simdint& _b)
{
	return { _a.x + _b, _a.y + _b };
}
inline ivec2 operator-(const ivec2& _a, const simdint& _b)
{
	return { _a.x - _b, _a.y - _b };
}
inline ivec2 operator*(const ivec2& _a, const simdint& _b)
{
	return { _a.x * _b, _a.y * _b };
}
inline ivec2 operator/(const ivec2& _a, const simdint& _b)
{
	return { _a.x / _b, _a.y / _b };
}
inline ivec2 operator%(const ivec2& _a, const simdint& _b)
{
	return { _a.x % _b, _a.y % _b };
}

inline ivec2 operator+(const simdint& _a, const ivec2& _b)
{
	return { _a + _b.x, _a + _b.y };
}
inline ivec2 operator-(const simdint& _a, const ivec2& _b)
{
	return { _a - _b.x, _a - _b.y };
}
inline ivec2 operator*(const simdint& _a, const ivec2& _b)
{
	return { _a * _b.x, _a * _b.y };
}
inline ivec2 operator/(const simdint& _a, const ivec2& _b)
{
	return { _a / _b.x, _a / _b.y };
}

inline ivec2 operator+=(ivec2& _a, const simdint& _b)
{
	_a = _a + _b;
	return _a;
}
inline ivec2 operator-=(ivec2& _a, const simdint& _b)
{
	_a = _a - _b;
	return _a;
}
inline ivec2 operator*=(ivec2& _a, const simdint& _b)
{
	_a = _a * _b;
	return _a;
}
inline ivec2 operator/=(ivec2& _a, const simdint& _b)
{
	_a = _a / _b;
	return _a;
}
inline ivec2 operator%=(ivec2& _a, const simdint& _b)
{
	_a.x %= _b;
	_a.y %= _b;
	return _a;
}

// ivec2 and ivec2
inline ivec2 operator+(const ivec2& _a, const ivec2& _b)
{
	return { _a.x + _b.x, _a.y + _b.y };
}
inline ivec2 operator-(const ivec2& _a, const ivec2& _b)
{
	return { _a.x - _b.x, _a.y - _b.y };
}
inline ivec2 operator*(const ivec2& _a, const ivec2& _b)
{
	return { _a.x * _b.x, _a.y * _b.y };
}
inline ivec2 operator/(const ivec2& _a, const ivec2& _b)
{
	return { _a.x / _b.x, _a.y / _b.y };
}
inline ivec2 operator%(const ivec2& _a, const ivec2& _b)
{
	return { _a.x % _b.x, _a.y % _b.y };
}

inline ivec2 operator+=(ivec2& _a, const ivec2& _b)
{
	_a = _a + _b;
	return _a;
}
inline ivec2 operator-=(ivec2& _a, const ivec2& _b)
{
	_a = _a - _b;
	return _a;
}
inline ivec2 operator*=(ivec2& _a, const ivec2& _b)
{
	_a = _a * _b;
	return _a;
}
inline ivec2 operator/=(ivec2& _a, const ivec2& _b)
{
	_a = _a / _b;
	return _a;
}
inline ivec2 operator%=(ivec2& _a, const ivec2& _b)
{
	_a.x %= _b.x;
	_a.y %= _b.y;
	return _a;
}

// ivec3 operators
// unary negation
inline ivec3 operator-(const ivec3& _a)
{
	return { -_a.x, -_a.y, -_a.z };
}

// ivec3 and int32_t
inline ivec3 operator+(const ivec3& _a, const int32_t& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b };
}
inline ivec3 operator-(const ivec3& _a, const int32_t& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b };
}
inline ivec3 operator*(const ivec3& _a, const int32_t& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b };
}
inline ivec3 operator/(const ivec3& _a, const int32_t& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b };
}
inline ivec3 operator%(const ivec3& _a, const int32_t& _b)
{
	return { _a.x % _b, _a.y % _b, _a.z % _b };
}

inline ivec3 operator+(const int32_t& _a, const ivec3& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z };
}
inline ivec3 operator-(const int32_t& _a, const ivec3& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z };
}
inline ivec3 operator*(const int32_t& _a, const ivec3& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z };
}
inline ivec3 operator/(const int32_t& _a, const ivec3& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z };
}

inline ivec3 operator+=(ivec3& _a, const int32_t& _b)
{
	_a = _a + _b;
	return _a;
}
inline ivec3 operator-=(ivec3& _a, const int32_t& _b)
{
	_a = _a - _b;
	return _a;
}
inline ivec3 operator*=(ivec3& _a, const int32_t& _b)
{
	_a = _a * _b;
	return _a;
}
inline ivec3 operator/=(ivec3& _a, const int32_t& _b)
{
	_a = _a / _b;
	return _a;
}
inline ivec3 operator%=(ivec3& _a, const int32_t& _b)
{
	_a.x %= _b;
	_a.y %= _b;
	_a.z %= _b;
	return _a;
}

// ivec3 and simdint
inline ivec3 operator+(const ivec3& _a, const simdint& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b };
}
inline ivec3 operator-(const ivec3& _a, const simdint& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b };
}
inline ivec3 operator*(const ivec3& _a, const simdint& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b };
}
inline ivec3 operator/(const ivec3& _a, const simdint& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b };
}
inline ivec3 operator%(const ivec3& _a, const simdint& _b)
{
	return { _a.x % _b, _a.y % _b, _a.z % _b };
}

inline ivec3 operator+(const simdint& _a, const ivec3& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z };
}
inline ivec3 operator-(const simdint& _a, const ivec3& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z };
}
inline ivec3 operator*(const simdint& _a, const ivec3& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z };
}
inline ivec3 operator/(const simdint& _a, const ivec3& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z };
}

inline ivec3 operator+=(ivec3& _a, const simdint& _b)
{
	_a = _a + _b;
	return _a;
}
inline ivec3 operator-=(ivec3& _a, const simdint& _b)
{
	_a = _a - _b;
	return _a;
}
inline ivec3 operator*=(ivec3& _a, const simdint& _b)
{
	_a = _a * _b;
	return _a;
}
inline ivec3 operator/=(ivec3& _a, const simdint& _b)
{
	_a = _a / _b;
	return _a;
}
inline ivec3 operator%=(ivec3& _a, const simdint& _b)
{
	_a.x %= _b;
	_a.y %= _b;
	_a.z %= _b;
	return _a;
}

// ivec3 and ivec3
inline ivec3 operator+(const ivec3& _a, const ivec3& _b)
{
	return { _a.x + _b.x, _a.y + _b.y, _a.z + _b.z };
}
inline ivec3 operator-(const ivec3& _a, const ivec3& _b)
{
	return { _a.x - _b.x, _a.y - _b.y, _a.z - _b.z };
}
inline ivec3 operator*(const ivec3& _a, const ivec3& _b)
{
	return { _a.x * _b.x, _a.y * _b.y, _a.z * _b.z };
}
inline ivec3 operator/(const ivec3& _a, const ivec3& _b)
{
	return { _a.x / _b.x, _a.y / _b.y, _a.z / _b.z };
}
inline ivec3 operator%(const ivec3& _a, const ivec3& _b)
{
	return { _a.x % _b.x, _a.y % _b.y, _a.z % _b.z };
}

inline ivec3 operator+=(ivec3& _a, const ivec3& _b)
{
	_a = _a + _b;
	return _a;
}
inline ivec3 operator-=(ivec3& _a, const ivec3& _b)
{
	_a = _a - _b;
	return _a;
}
inline ivec3 operator*=(ivec3& _a, const ivec3& _b)
{
	_a = _a * _b;
	return _a;
}
inline ivec3 operator/=(ivec3& _a, const ivec3& _b)
{
	_a = _a / _b;
	return _a;
}
inline ivec3 operator%=(ivec3& _a, const ivec3& _b)
{
	_a.x %= _b.x;
	_a.y %= _b.y;
	_a.z %= _b.z;
	return _a;
}

// ivec4 operators
inline ivec4 operator-(const ivec4& _a)
{
	return { -_a.x, -_a.y, -_a.z, -_a.w };
}

// ivec4 and int32_t
inline ivec4 operator+(const ivec4& _a, const int32_t& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b, _a.w + _b };
}
inline ivec4 operator-(const ivec4& _a, const int32_t& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b, _a.w - _b };
}
inline ivec4 operator*(const ivec4& _a, const int32_t& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b, _a.w * _b };
}
inline ivec4 operator/(const ivec4& _a, const int32_t& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b, _a.w / _b };
}
inline ivec4 operator%(const ivec4& _a, const int32_t& _b)
{
	return { _a.x % _b, _a.y % _b, _a.z % _b, _a.w % _b };
}

inline ivec4 operator+(const int32_t& _a, const ivec4& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z, _a + _b.w };
}
inline ivec4 operator-(const int32_t& _a, const ivec4& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z, _a - _b.w };
}
inline ivec4 operator*(const int32_t& _a, const ivec4& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z, _a * _b.w };
}
inline ivec4 operator/(const int32_t& _a, const ivec4& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z, _a / _b.w };
}

inline ivec4 operator+=(ivec4& _a, const int32_t& _b)
{
	_a = _a + _b;
	return _a;
}
inline ivec4 operator-=(ivec4& _a, const int32_t& _b)
{
	_a = _a - _b;
	return _a;
}
inline ivec4 operator*=(ivec4& _a, const int32_t& _b)
{
	_a = _a * _b;
	return _a;
}
inline ivec4 operator/=(ivec4& _a, const int32_t& _b)
{
	_a = _a / _b;
	return _a;
}
inline ivec4 operator%=(ivec4& _a, const int32_t& _b)
{
	_a.x %= _b;
	_a.y %= _b;
	_a.z %= _b;
	_a.w %= _b;
	return _a;
}

// ivec4 and simdint
inline ivec4 operator+(const ivec4& _a, const simdint& _b)
{
	return { _a.x + _b, _a.y + _b, _a.z + _b, _a.w + _b };
}
inline ivec4 operator-(const ivec4& _a, const simdint& _b)
{
	return { _a.x - _b, _a.y - _b, _a.z - _b, _a.w - _b };
}
inline ivec4 operator*(const ivec4& _a, const simdint& _b)
{
	return { _a.x * _b, _a.y * _b, _a.z * _b, _a.w * _b };
}
inline ivec4 operator/(const ivec4& _a, const simdint& _b)
{
	return { _a.x / _b, _a.y / _b, _a.z / _b, _a.w / _b };
}
inline ivec4 operator%(const ivec4& _a, const simdint& _b)
{
	return { _a.x % _b, _a.y % _b, _a.z % _b, _a.w % _b };
}

inline ivec4 operator+(const simdint& _a, const ivec4& _b)
{
	return { _a + _b.x, _a + _b.y, _a + _b.z, _a + _b.w };
}
inline ivec4 operator-(const simdint& _a, const ivec4& _b)
{
	return { _a - _b.x, _a - _b.y, _a - _b.z, _a - _b.w };
}
inline ivec4 operator*(const simdint& _a, const ivec4& _b)
{
	return { _a * _b.x, _a * _b.y, _a * _b.z, _a * _b.w };
}
inline ivec4 operator/(const simdint& _a, const ivec4& _b)
{
	return { _a / _b.x, _a / _b.y, _a / _b.z, _a / _b.w };
}

inline ivec4 operator+=(ivec4& _a, const simdint& _b)
{
	_a = _a + _b;
	return _a;
}
inline ivec4 operator-=(ivec4& _a, const simdint& _b)
{
	_a = _a - _b;
	return _a;
}
inline ivec4 operator*=(ivec4& _a, const simdint& _b)
{
	_a = _a * _b;
	return _a;
}
inline ivec4 operator/=(ivec4& _a, const simdint& _b)
{
	_a = _a / _b;
	return _a;
}
inline ivec4 operator%=(ivec4& _a, const simdint& _b)
{
	_a.x %= _b;
	_a.y %= _b;
	_a.z %= _b;
	_a.w %= _b;
	return _a;
}

// ivec4 and ivec4
inline ivec4 operator+(const ivec4& _a, const ivec4& _b)
{
	return { _a.x + _b.x, _a.y + _b.y, _a.z + _b.z, _a.w + _b.w };
}
inline ivec4 operator-(const ivec4& _a, const ivec4& _b)
{
	return { _a.x - _b.x, _a.y - _b.y, _a.z - _b.z, _a.w - _b.w };
}
inline ivec4 operator*(const ivec4& _a, const ivec4& _b)
{
	return { _a.x * _b.x, _a.y * _b.y, _a.z * _b.z, _a.w * _b.w };
}
inline ivec4 operator/(const ivec4& _a, const ivec4& _b)
{
	return { _a.x / _b.x, _a.y / _b.y, _a.z / _b.z, _a.w / _b.w };
}
inline ivec4 operator%(const ivec4& _a, const ivec4& _b)
{
	return { _a.x % _b.x, _a.y % _b.y, _a.z % _b.z, _a.w % _b.w };
}

inline ivec4 operator+=(ivec4& _a, const ivec4& _b)
{
	_a = _a + _b;
	return _a;
}
inline ivec4 operator-=(ivec4& _a, const ivec4& _b)
{
	_a = _a - _b;
	return _a;
}
inline ivec4 operator*=(ivec4& _a, const ivec4& _b)
{
	_a = _a * _b;
	return _a;
}
inline ivec4 operator/=(ivec4& _a, const ivec4& _b)
{
	_a = _a / _b;
	return _a;
}
inline ivec4 operator%=(ivec4& _a, const ivec4& _b)
{
	_a.x %= _b.x;
	_a.y %= _b.y;
	_a.z %= _b.z;
	_a.w %= _b.w;
	return _a;
}
#pragma endregion
#pragma region binary operators

// & operator
inline simdint operator&(const simdint& _a, const simdint& _b)
{
	return simd_and_int(_a, _b);
}

inline ivec2 operator&(const ivec2& _a, const ivec2& _b)
{
	return { _a.x & _b.x, _a.y & _b.y };
}

inline ivec3 operator&(const ivec3& _a, const ivec3& _b)
{
	return { _a.x & _b.x, _a.y & _b.y, _a.z & _b.z };
}

inline ivec4 operator&(const ivec4& _a, const ivec4& _b)
{
	return { _a.x & _b.x, _a.y & _b.y, _a.z & _b.z, _a.w & _b.w };
}

// | operator
inline simdint operator|(const simdint& _a, const simdint& _b)
{
	return simd_or_int(_a, _b);
}

inline ivec2 operator|(const ivec2& _a, const ivec2& _b)
{
	return { _a.x | _b.x, _a.y | _b.y };
}

inline ivec3 operator|(const ivec3& _a, const ivec3& _b)
{
	return { _a.x | _b.x, _a.y | _b.y, _a.z | _b.z };
}

inline ivec4 operator|(const ivec4& _a, const ivec4& _b)
{
	return { _a.x | _b.x, _a.y | _b.y, _a.z | _b.z, _a.w | _b.w };
}

// ^ operator
inline simdint operator^(const simdint& _a, const simdint& _b)
{
	return simd_xor_int(_a, _b);
}

inline ivec2 operator^(const ivec2& _a, const ivec2& _b)
{
	return { _a.x ^ _b.x, _a.y ^ _b.y };
}

inline ivec3 operator^(const ivec3& _a, const ivec3& _b)
{
	return { _a.x ^ _b.x, _a.y ^ _b.y, _a.z ^ _b.z };
}

inline ivec4 operator^(const ivec4& _a, const ivec4& _b)
{
	return { _a.x ^ _b.x, _a.y ^ _b.y, _a.z ^ _b.z, _a.w ^ _b.w };
}

// ~ operator
inline simdint operator~(const simdint& _a)
{
	return simd_xor_int(_a, simd_set1_int(-1));
}

inline ivec2 operator~(const ivec2& _a)
{
	return { ~_a.x, ~_a.y };
}

inline ivec3 operator~(const ivec3& _a)
{
	return { ~_a.x, ~_a.y, ~_a.z };
}

inline ivec4 operator~(const ivec4& _a)
{
	return { ~_a.x, ~_a.y, ~_a.z, ~_a.w };
}

// left shift operator
inline simdint operator<<(const simdint& _a, const int32_t& _b)
{
	return simd_slli_int(_a, _b);
}

inline ivec2 operator<<(const ivec2& _a, const int32_t& _b)
{
	return { _a.x << _b, _a.y << _b };
}

inline ivec3 operator<<(const ivec3& _a, const int32_t& _b)
{
	return { _a.x << _b, _a.y << _b, _a.z << _b };
}

inline ivec4 operator<<(const ivec4& _a, const int32_t& _b)
{
	return { _a.x << _b, _a.y << _b, _a.z << _b, _a.w << _b };
}

// right shift operator
inline simdint operator>>(const simdint& _a, const int32_t& _b)
{
	return simd_srli_int(_a, _b);
}

inline ivec2 operator>>(const ivec2& _a, const int32_t& _b)
{
	return { _a.x >> _b, _a.y >> _b };
}

inline ivec3 operator>>(const ivec3& _a, const int32_t& _b)
{
	return { _a.x >> _b, _a.y >> _b, _a.z >> _b };
}

inline ivec4 operator>>(const ivec4& _a, const int32_t& _b)
{
	return { _a.x >> _b, _a.y >> _b, _a.z >> _b, _a.w >> _b };
}

#pragma endregion binary operators

#pragma region std::cout operators
#ifndef USE_AVX512
inline std::ostream& operator<<(std::ostream& _os, const simdimask& _v)
{
	alignas(SIMDWIDTH * 4) int32_t arr[SIMDWIDTH] = { 0 };
	simd_store_int(arr, _v);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		_os << arr[i];
		if (i < SIMDWIDTH - 1) _os << ", ";
	}
	return _os;
}
#endif
inline std::ostream& operator<<(std::ostream& _os, const simdint& _v)
{
	alignas(SIMDWIDTH * 4) int32_t arr[SIMDWIDTH];
	simd_store_int(arr, _v);
	for (int32_t i = 0; i < SIMDWIDTH; i++)
	{
		_os << arr[i];
		if (i < SIMDWIDTH - 1) _os << ", ";
	}
	return _os;
}


inline std::ostream& operator<<(std::ostream& _os, const ivec2& _v)
{
	_os << "[" << _v.x << "]" << ", " << "[" << _v.y << "]";
	return _os;
}
inline std::ostream& operator<<(std::ostream& _os, const ivec3& _v)
{
	_os << "[" << _v.x << "]" << ", " << "[" << _v.y << "]" << ", " << "[" << _v.z << "]";
	return _os;
}
inline std::ostream& operator<<(std::ostream& _os, const ivec4& _v)
{
	_os << "[" << _v.x << "]" << ", " << "[" << _v.y << "]" << ", " << "[" << _v.z << "]" << ", " << "[" << _v.w << "]";
	return _os;
}

#pragma endregion
#pragma endregion int32_t operators

#endif

