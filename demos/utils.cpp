#ifndef UTIL__CPP


#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <functional>
#include "cppshader.h"

#define COMPILE_TESTS

inline void Compare(const simdfloat& _provided, const simdfloat& _expected)
{
	alignas(64) float tabA[simdwidth] = { 0 };
	alignas(64) float tabB[simdwidth] = { 0 };

	simd_store_float(tabA, _provided);
	simd_store_float(tabB, _expected);

	for (int i = 0; i < simdwidth; i++)
	{
		if (std::abs(tabA[i] - tabB[i]) > 0.001f)
		{
			std::cout << "Compare failed" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;

			exit(0);
		}

		if (std::isnan(tabA[i]))
		{
			std::cout << "NaN detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}

		if (std::isinf(tabA[i]))
		{
			std::cout << "INF detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}
	}
}

inline void CompareMask(const simdmask& _provided, const simdmask& _expected)
{
#if !(defined (USE_AVX512) || defined(USE_SCALAR))
#ifndef USE_AVX512
	alignas(64) float tabA[simdwidth] = { 0 };
	alignas(64) float tabB[simdwidth] = { 0 };

	simd_store_float(tabA, _provided);
	simd_store_float(tabB, _expected);

	for (int i = 0; i < simdwidth; i++)
	{
		if (std::abs(tabA[i] - tabB[i]) > 0.001f)
		{
			std::cout << "Compare failed" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;

			exit(0);
		}

		if (std::isnan(tabA[i]))
		{
			std::cout << "NaN detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}

		if (std::isinf(tabA[i]))
		{
			std::cout << "INF detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}
	}
	#else
        if ((_provided & 0xFFFF) != (_expected & 0xFFFF))
        {
			std::cout << "Compare failed" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;

			exit(0);
        }
	#endif
#else
	if ((_provided&0xFFFF) != (_expected&0xFFFF))
	{
		std::cout << "Compare failed" << std::endl;
		std::cout << "Provided: " << _provided << std::endl;
		std::cout << "Expected: " << _expected << std::endl;
		exit(0);
	}
#endif
}

inline void CompareDouble(const simddouble& _provided, const simddouble& _expected)
{
	alignas(64) double tabA[halfsimdwidth] = { 0 };
	alignas(64) double tabB[halfsimdwidth] = { 0 };

	simd_store_double(tabA, _provided);
	simd_store_double(tabB, _expected);

	for (int i = 0; i < halfsimdwidth; i++)
	{
		if (std::abs(tabA[i] - tabB[i]) > 0.001)
		{
			std::cout << "Compare failed" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;

			exit(0);
		}

		if (std::isnan(tabA[i]))
		{
			std::cout << "NaN detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}

		if (std::isinf(tabA[i]))
		{
			std::cout << "INF detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}
	}

}

inline void CompareMaskDouble(const simddmask& _provided, const simddmask& _expected)
{
#if !(defined (USE_AVX512) || defined(USE_SCALAR))
#ifndef USE_AVX512
	alignas(64) double tabA[halfsimdwidth] = { 0 };
	alignas(64) double tabB[halfsimdwidth] = { 0 };

	simd_store_double(tabA, _provided);
	simd_store_double(tabB, _expected);

	for (int i = 0; i < halfsimdwidth; i++)
	{
		if (std::abs(tabA[i] - tabB[i]) > 0.001)
		{
			std::cout << "Compare failed" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;

			exit(0);
		}

		if (std::isnan(tabA[i]))
		{
			std::cout << "NaN detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}

		if (std::isinf(tabA[i]))
		{
			std::cout << "INF detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}
	}
		#else
        if ((_provided & 0xFF) != (_expected & 0xFF))
        {
			std::cout << "Compare failed" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;

			exit(0);
        }
	#endif
#else
	if ((_provided & 0xFF) != (_expected & 0xFF))
	{
		std::cout << "Compare failed" << std::endl;
		std::cout << "Provided: " << _provided << std::endl;
		std::cout << "Expected: " << _expected << std::endl;
		exit(0);
	}
#endif
}

inline void CompareInt(const simdint& _provided, const simdint& _expected)
{

	alignas(64) int tabA[simdwidth] = { 0 };
	alignas(64) int tabB[simdwidth] = { 0 };

	simd_store_int(tabA, _provided);
	simd_store_int(tabB, _expected);

	for (int i = 0; i < simdwidth; i++)
	{
		if (tabA[i] != tabB[i])
		{
			std::cout << "Compare failed" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;

			exit(0);
		}

		if (std::isnan(tabA[i]))
		{
			std::cout << "NaN detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}

		if (std::isinf(tabA[i]))
		{
			std::cout << "INF detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}
	}
}

inline void CompareMaskInt(const simdimask& _provided, const simdimask& _expected)
{
#if !(defined (USE_AVX512) || defined(USE_SCALAR))

#ifndef USE_AVX512
	alignas(64) int tabA[simdwidth] = { 0 };
	alignas(64) int tabB[simdwidth] = { 0 };

	simd_store_int(tabA, _provided);
	simd_store_int(tabB, _expected);

	for (int i = 0; i < simdwidth; i++)
	{
		if (tabA[i] != tabB[i])
		{
			std::cout << "Compare failed" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;

			exit(0);
		}

		if (std::isnan(tabA[i]))
		{
			std::cout << "NaN detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}

		if (std::isinf(tabA[i]))
		{
			std::cout << "INF detected" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;
			exit(0);
		}
	}
	#else
        if ((_provided & 0xFFFF) != (_expected & 0xFFFF))
        {
			std::cout << "Compare failed" << std::endl;
			std::cout << "Provided: " << _provided << std::endl;
			std::cout << "Expected: " << _expected << std::endl;

			exit(0);
        }
	#endif
#else
	if ((_provided & 0xFFFF) != (_expected & 0xFFFF))
	{
		std::cout << "Compare failed" << std::endl;
		std::cout << "Provided: " << _provided << std::endl;
		std::cout << "Expected: " << _expected << std::endl;
		exit(0);
	}
#endif
}

inline void FillTabResult(const float* _tabVal, float* _tabValRes, std::function<float(const float&, const int&)> lambda)
{
	for (int i = 0; i < simdwidth; i++)
	{
		_tabValRes[i] = lambda(_tabVal[i], i);
	}
}

inline void FillTabResultDouble(const double* _tabVal, double* _tabValRes, std::function<double(const double&, const int&)> lambda)
{
	for (int i = 0; i < halfsimdwidth; i++)
	{
		_tabValRes[i] = lambda(_tabVal[i], i);
	}
}

inline void FillTabResultInt(const int* _tabVal, int* _tabValRes, std::function<int(const int&, const int&)> lambda)
{
	for (int i = 0; i < simdwidth; i++)
	{
		_tabValRes[i] = lambda(_tabVal[i], i);
	}
}

inline void TestsFloat()
{

#ifdef COMPILE_TESTS

#pragma region float tests

	alignas(64) const float tabVal[16] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 8.0f, 7.0f, 6.0f,	5.0f, 4.0f, 3.0f, 2.0f };
	alignas(64) const float tabValNeg[16] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, -8.0f, -7.0f, -6.0f, -5.0f, -4.0f, -3.0f, -2.0f, -1.0f };
	alignas(64) const float tabSmallVal[16] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, -0.1f, -0.2f, -0.3f, -0.4f, -0.5f, -0.6f, -0.7f, -0.8f };
	alignas(64) const float tabRandomVal[16] = { 0.123f, 0.456f, 0.789f, 1.234f, 2.345f, 3.456f, 4.567f, 5.678f, -0.123f, -0.456f, -0.789f, -1.234f, -2.345f, -3.456f, -4.567f, -5.678f };
	alignas(64) const float tabValAcosh[16] = { 1.1f, 1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f, 1.8f, 2.0f, 2.2f, 2.4f, 2.6f, 2.8f, 3.0f, 3.5f, 4.0f };
	alignas(64) const float tabValMin[16] = { 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f };
	alignas(64) const float tabValMax[16] = { 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f };


	alignas(64) const float tabMask[16] = { 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, -1.0f };
#if defined(USE_AVX512)
	alignas(64) const __mmask16 testmask = 0b0101010101010101;
#elif defined (USE_SCALAR)
	const int testmask = 1;
#else
	simdmask testmask = simd_load_float(tabMask);
#endif

	alignas(64) float tabValResult[16] = { 0 };

	simdfloat veca, vecb, vecc;
	vec2 vec2a, vec2b, vec2c;
	vec3 vec3a, vec3b, vec3c;
	vec4 vec4a, vec4b, vec4c;

	mat2 mat2a, mat2b, mat2c;
	mat3 mat3a, mat3b, mat3c;
	mat4 mat4a, mat4b, mat4c;

	simdmask maskResult;
	float lengthResult[16];


	std::cout << "simdfloat operator-(const simdfloat& a)" << std::endl;
	veca = simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return -val; });
	Compare(-veca, simd_load_float(tabValResult));

	std::cout << "simdfloat& operator++(simdfloat& a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = ++veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1; });
	Compare(veca, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat& operator--(simdfloat& a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = --veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1; });
	Compare(veca, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat operator++(simdfloat& a, int)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = veca++;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1; });
	Compare(veca, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat operator--(simdfloat& a, int)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = veca--;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1; });
	Compare(veca, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat operator+(const simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = veca + veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat operator-(const simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = veca - veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat operator*(const simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = veca * veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat operator/(const simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = veca / veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat operator+=(simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca += veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator-=(simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca -= veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator*=(simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca *= veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator/=(simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca /= veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator+(const simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca = veca + 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1.0f; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator-(const simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca = veca - 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1.0f; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator*(const simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca = veca * 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 2.0f; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator/(const simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca = veca / 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / 2.0f; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator+=(simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca += 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1.0f; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator-=(simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca -= 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1.0f; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator*=(simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca *= 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 2.0f; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator/=(simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca /= 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / 2.0f; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator+(const float& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca = 1.0f + veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f + val; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator-(const float& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca = 1.0f - veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f - val; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator*(const float& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca = 2.0f * veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 2.0f * val; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat operator/(const float& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	veca = 2.0f / veca;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 2.0f / val; });
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "vec2 operator-(const vec2& a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = -vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return -val; });
	Compare(vec2a.x, simd_load_float(tabValResult));
	Compare(vec2a.y, simd_load_float(tabValResult));

	std::cout << "vec2 operator+(const vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a + vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec2a.x, simd_load_float(tabValResult));
	Compare(vec2a.y, simd_load_float(tabValResult));

	std::cout << "vec2 operator-(const vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a - vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec2a.x, simd_load_float(tabValResult));
	Compare(vec2a.y, simd_load_float(tabValResult));

	std::cout << "vec2 operator*(const vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a * vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec2a.x, simd_load_float(tabValResult));
	Compare(vec2a.y, simd_load_float(tabValResult));

	std::cout << "vec2 operator/(const vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a / vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec2a.x, simd_load_float(tabValResult));
	Compare(vec2a.y, simd_load_float(tabValResult));

	std::cout << "vec2 operator+(const float& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = 1.0f + vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f + val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator-(const float& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = 1.0f - vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f - val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator*(const float& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = 2.0f * vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 2.0f * val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator/(const float& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = 2.0f / vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 2.0f / val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator+=(vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a += 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1.0f; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator-=(vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a -= 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1.0f; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator*=(vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a *= 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 2.0f; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator/=(vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a /= 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / 2.0f; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator+(const vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a + simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator-(const vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a - simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator*(const vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a * simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator/(const vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a / simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator+(const simdfloat& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = simd_load_float(tabVal) + vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator-(const simdfloat& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = simd_load_float(tabVal) - vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator*(const simdfloat& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = simd_load_float(tabVal) * vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator/(const simdfloat& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = simd_load_float(tabVal) / vec2a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator+=(vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a += simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator-=(vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a -= simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator*=(vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a *= simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator/=(vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a /= simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator+(const vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a + vec2b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator-(const vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a - vec2b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator*(const vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a * vec2b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator/(const vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a = vec2a / vec2b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator+=(vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a += vec2b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator-=(vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a -= vec2b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator*=(vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a *= vec2b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec2 operator/=(vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2a /= vec2b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec2a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator-(const vec3& a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = -vec3a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return -val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator+(const vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a + 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1.0f; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator-(const vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a - 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1.0f; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator*(const vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a * 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 2.0f; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator/(const vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a / 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / 2.0f; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator+(const float& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = 1.0f + vec3a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f + val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator-(const float& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = 1.0f - vec3a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f - val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator*(const float& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = 2.0f * vec3a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 2.0f * val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator/(const float& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = 2.0f / vec3a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 2.0f / val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator+=(vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a += 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1.0f; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator-=(vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a -= 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1.0f; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator*=(vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a *= 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 2.0f; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator/=(vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a /= 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / 2.0f; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator+(const vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a + simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator-(const vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a - simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator*(const vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a * simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator/(const vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a / simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator+(const simdfloat& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = simd_load_float(tabVal) + vec3a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator-(const simdfloat& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = simd_load_float(tabVal) - vec3a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator*(const simdfloat& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = simd_load_float(tabVal) * vec3a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator/(const simdfloat& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = simd_load_float(tabVal) / vec3a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator+=(vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a += simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator-=(vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a -= simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator*=(vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a *= simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator/=(vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a /= simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator+(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a + vec3b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator-(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a - vec3b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator*(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a * vec3b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator/(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a = vec3a / vec3b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator+=(vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a += vec3b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator-=(vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a -= vec3b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator*=(vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a *= vec3b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec3 operator/=(vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3a /= vec3b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec3a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator-(const vec4& a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = -vec4a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return -val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator+(const vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a + 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1.0f; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator-(const vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a - 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1.0f; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator*(const vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a * 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 2.0f; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator/(const vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a / 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / 2.0f; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator+(const float& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = 1.0f + vec4a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f + val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator-(const float& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = 1.0f - vec4a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f - val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator*(const float& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = 2.0f * vec4a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 2.0f * val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator/(const float& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = 2.0f / vec4a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 2.0f / val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator+=(vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a += 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 1.0f; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator-=(vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a -= 1.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - 1.0f; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator*=(vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a *= 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 2.0f; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator/=(vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a /= 2.0f;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / 2.0f; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator+(const vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a + simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator-(const vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a - simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator*(const vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a * simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator/(const vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a / simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator+(const simdfloat& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = simd_load_float(tabVal) + vec4a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec4b.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator-(const simdfloat& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = simd_load_float(tabVal) - vec4a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec4b.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator*(const simdfloat& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = simd_load_float(tabVal) * vec4a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec4b.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator/(const simdfloat& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = simd_load_float(tabVal) / vec4a;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec4b.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator+=(vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a += simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator-=(vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a -= simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator*=(vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a *= simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator/=(vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a /= simd_load_float(tabVal);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator+(const vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a + vec4b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator-(const vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a - vec4b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator*(const vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a * vec4b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator/(const vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a = vec4a / vec4b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator+=(vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a += vec4b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator-=(vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a -= vec4b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator*=(vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a *= vec4b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	std::cout << "vec4 operator/=(vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4a /= vec4b;
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val / val; });
	Compare(vec4a.x, simd_load_float(tabValResult));

	// Tests for abs
	std::cout << "simdfloat abs(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = abs(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::abs(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 abs(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = abs(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::abs(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 abs(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = abs(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::abs(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 abs(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = abs(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::abs(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for acos
	std::cout << "simdfloat acos(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabSmallVal);
	vecb = acos(veca);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::acos(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 acos(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec2b = acos(vec2a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::acos(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 acos(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec3b = acos(vec3a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::acos(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 acos(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec4b = acos(vec4a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::acos(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for acosh

	std::cout << "simdfloat acosh(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabValAcosh);
	vecb = acosh(veca);
	FillTabResult(tabValAcosh, tabValResult, [](const float& val, const int& idx) { return std::acosh(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 acosh(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabValAcosh), simd_load_float(tabValAcosh));
	vec2b = acosh(vec2a);
	FillTabResult(tabValAcosh, tabValResult, [](const float& val, const int& idx) { return std::acosh(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 acosh(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabValAcosh), simd_load_float(tabValAcosh), simd_load_float(tabValAcosh));
	vec3b = acosh(vec3a);
	FillTabResult(tabValAcosh, tabValResult, [](const float& val, const int& idx) { return std::acosh(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 acosh(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabValAcosh), simd_load_float(tabValAcosh), simd_load_float(tabValAcosh), simd_load_float(tabValAcosh));
	vec4b = acosh(vec4a);
	FillTabResult(tabValAcosh, tabValResult, [](const float& val, const int& idx) { return std::acosh(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for asin
	std::cout << "simdfloat asin(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabSmallVal);
	vecb = asin(veca);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::asin(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 asin(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec2b = asin(vec2a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::asin(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 asin(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec3b = asin(vec3a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::asin(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 asin(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec4b = asin(vec4a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::asin(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for asinh
	std::cout << "simdfloat asinh(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = asinh(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::asinh(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 asinh(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = asinh(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::asinh(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 asinh(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = asinh(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::asinh(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 asinh(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = asinh(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::asinh(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for atan (single parameter)
	std::cout << "simdfloat atan(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = atan(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::atan(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 atan(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = atan(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::atan(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 atan(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = atan(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::atan(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 atan(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = atan(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::atan(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for atan2 (two parameters)
	std::cout << "simdfloat atan(const simdfloat& _a, const simdfloat& _b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecc = (0.5f);
	vecb = atan(veca, vecc);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::atan2(val, 0.5f); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat atan(const vec2&, const vec2&)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2((0.5f), (0.5f));
	vec2c = atan(vec2a, vec2b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::atan2(val, 0.5f); });
	Compare(vec2c.x, simd_load_float(tabValResult));
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "simdfloat atan(const vec3&, const vec3&)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3((0.5f), (0.5f), (0.5f));
	vec3c = atan(vec3a, vec3b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::atan2(val, 0.5f); });
	Compare(vec3c.x, simd_load_float(tabValResult));
	Compare(vec3c.y, simd_load_float(tabValResult));
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "simdfloat atan(const vec4&, const vec4&)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4((0.5f), (0.5f), (0.5f), (0.5f));
	vec4c = atan(vec4a, vec4b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::atan2(val, 0.5f); });
	Compare(vec4c.x, simd_load_float(tabValResult));


	// Tests for atanh
	std::cout << "simdfloat atanh(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabSmallVal);
	vecb = atanh(veca);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::atanh(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 atanh(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec2b = atanh(vec2a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::atanh(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 atanh(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec3b = atanh(vec3a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::atanh(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 atanh(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec4b = atanh(vec4a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::atanh(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for blendv
// Tests for blendv
	std::cout << "simdfloat blendv(const simdfloat& a, const simdfloat& b, const simdfloat& testmask)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = simd_load_float(tabValAcosh);

	vecc = blendv(vecb, veca, testmask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabValResult[i] = tabMask[i] < 0.0f ? tabVal[i] : tabValAcosh[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabValResult[i] = tabMask[i] < 0.0f ? tabValAcosh[i] : tabVal[i];
	}
#elif defined(USE_SCALAR)
	tabValResult[0] = tabMask[0] == 0.0f ? tabVal[0] : tabValAcosh[0];
#endif
	Compare(vecc, simd_load_float(tabValResult));

	std::cout << "vec2 blendv(const vec2& a, const vec2& b, const simdfloat& testmask)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2(simd_load_float(tabValAcosh), simd_load_float(tabValAcosh));

	vec2c = blendv(vec2b, vec2a, testmask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabValResult[i] = tabMask[i] < 0.0f ? tabVal[i] : tabValAcosh[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabValResult[i] = tabMask[i] < 0.0f ? tabValAcosh[i] : tabVal[i];
	}
#elif defined(USE_SCALAR)
	tabValResult[0] = tabMask[0] == 0.0f ? tabVal[0] : tabValAcosh[0];
#endif
	Compare(vec2c.x, simd_load_float(tabValResult));
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "vec3 blendv(const vec3& a, const vec3& b, const simdfloat& testmask)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3(simd_load_float(tabValAcosh), simd_load_float(tabValAcosh), simd_load_float(tabValAcosh));

	vec3c = blendv(vec3b, vec3a, testmask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabValResult[i] = tabMask[i] < 0.0f ? tabVal[i] : tabValAcosh[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabValResult[i] = tabMask[i] < 0.0f ? tabValAcosh[i] : tabVal[i];
	}
#elif defined(USE_SCALAR)
	tabValResult[0] = tabMask[0] == 0.0f ? tabVal[0] : tabValAcosh[0];
#endif
	Compare(vec3c.x, simd_load_float(tabValResult));
	Compare(vec3c.y, simd_load_float(tabValResult));
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "vec4 blendv(const vec4& a, const vec4& b, const simdfloat& testmask)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4(simd_load_float(tabValAcosh), simd_load_float(tabValAcosh), simd_load_float(tabValAcosh), simd_load_float(tabValAcosh));

	vec4c = blendv(vec4b, vec4a, testmask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabValResult[i] = tabMask[i] < 0.0f ? tabVal[i] : tabValAcosh[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabValResult[i] = tabMask[i] < 0.0f ? tabValAcosh[i] : tabVal[i];
	}
#elif defined(USE_SCALAR)
	tabValResult[0] = tabMask[0] == 0.0f ? tabVal[0] : tabValAcosh[0];
#endif
	Compare(vec4c.x, simd_load_float(tabValResult));
	Compare(vec4c.y, simd_load_float(tabValResult));
	Compare(vec4c.z, simd_load_float(tabValResult));
	Compare(vec4c.w, simd_load_float(tabValResult));


	// Tests for ceil
	std::cout << "simdfloat ceil(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = ceil(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::ceil(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 ceil(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = ceil(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::ceil(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 ceil(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = ceil(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::ceil(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 ceil(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = ceil(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::ceil(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for distance
	std::cout << "simdfloat distance(const simdfloat&, const simdfloat&)" << std::endl;
	veca = simd_load_float(tabVal);
	vecc = (0.5f);
	vecb = distance(veca, vecc);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::abs(val - 0.5f); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat distance(const vec2&, const vec2&)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2((0.5f), (0.5f));
	vec2c = distance(vec2a, vec2b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sqrt(std::pow(val - 0.5f, 2) + std::pow(val - 0.5f, 2)); });
	Compare(vec2c.x, simd_load_float(tabValResult));
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "simdfloat distance(const vec3&, const vec3&)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3((0.5f), (0.5f), (0.5f));
	vec3c = distance(vec3a, vec3b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sqrt(std::pow(val - 0.5f, 2) + std::pow(val - 0.5f, 2) + std::pow(val - 0.5f, 2)); });
	Compare(vec3c.x, simd_load_float(tabValResult));
	Compare(vec3c.y, simd_load_float(tabValResult));
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "simdfloat distance(const vec4&, const vec4&)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4((0.5f), (0.5f), (0.5f), (0.5f));
	vec4c = distance(vec4a, vec4b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sqrt(std::pow(val - 0.5f, 2) + std::pow(val - 0.5f, 2) + std::pow(val - 0.5f, 2) + std::pow(val - 0.5f, 2)); });
	Compare(vec4c.x, simd_load_float(tabValResult));
	Compare(vec4c.y, simd_load_float(tabValResult));
	Compare(vec4c.z, simd_load_float(tabValResult));
	Compare(vec4c.w, simd_load_float(tabValResult));



	// Tests for max
	std::cout << "simdfloat max(const simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecc = (0.5f);
	vecb = max(veca, vecc);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 0.5f); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat max(const simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = max(veca, 5.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 5.0f); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat max(const float& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = max(5.0f, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(5.0f, val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 max(const vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = max(vec2a, (0.5f));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 0.5f); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 max(const simdfloat& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = max((0.5f), vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(0.5f, val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 max(const vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = max(vec2a, 5.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 5.0f); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 max(const float& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = max(5.0f, vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(5.0f, val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 max(const vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2 vec2d = vec2((0.5f), (0.5f));
	vec2b = max(vec2a, vec2d);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 0.5f); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 max(const vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = max(vec3a, (0.5f));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 0.5f); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 max(const simdfloat& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = max((0.5f), vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(0.5f, val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 max(const vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = max(vec3a, 5.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 5.0f); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 max(const float& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = max(5.0f, vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(5.0f, val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 max(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3 vec3d = vec3((0.5f), (0.5f), (0.5f));
	vec3b = max(vec3a, vec3d);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 0.5f); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 max(const vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = max(vec4a, (0.5f));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 0.5f); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 max(const simdfloat& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = max((0.5f), vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(0.5f, val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 max(const vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = max(vec4a, 5.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 5.0f); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 max(const float& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = max(5.0f, vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(5.0f, val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 max(const vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4 vec4d = vec4((0.5f), (0.5f), (0.5f), (0.5f));
	vec4b = max(vec4a, vec4d);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(val, 0.5f); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for min
	std::cout << "simdfloat min(const simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecc = (0.5f);
	vecb = min(veca, vecc);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 0.5f); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat min(const simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = min(veca, 5.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 5.0f); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat min(const float& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = min(5.0f, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(5.0f, val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 min(const vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = min(vec2a, (0.5f));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 0.5f); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 min(const simdfloat& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = min((0.5f), vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(0.5f, val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 min(const vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = min(vec2a, 5.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 5.0f); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 min(const float& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = min(5.0f, vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(5.0f, val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 min(const vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2d = vec2((0.5f), (0.5f));
	vec2b = min(vec2a, vec2d);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 0.5f); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 min(const vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = min(vec3a, (0.5f));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 0.5f); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 min(const simdfloat& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = min((0.5f), vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(0.5f, val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 min(const vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = min(vec3a, 5.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 5.0f); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 min(const float& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = min(5.0f, vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(5.0f, val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 min(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3d = vec3((0.5f), (0.5f), (0.5f));
	vec3b = min(vec3a, vec3d);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 0.5f); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 min(const vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = min(vec4a, (0.5f));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 0.5f); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 min(const simdfloat& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = min((0.5f), vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(0.5f, val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 min(const vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = min(vec4a, 5.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 5.0f); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 min(const float& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = min(5.0f, vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(5.0f, val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 min(const vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4d = vec4((0.5f), (0.5f), (0.5f), (0.5f));
	vec4b = min(vec4a, vec4d);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::min(val, 0.5f); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for clamp
	std::cout << "float clamp(const float& v, const float& minVal, const float& maxVal)" << std::endl;
	if (clamp(7.5f, 2.0f, 10.0f) != 7.5f) {
		std::cout << "Clamp failed for float" << std::endl;
		exit(0);
	}

	std::cout << "simdfloat clamp(const simdfloat& v, const simdfloat& minVal, const simdfloat& maxVal)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = clamp(veca, simd_load_float(tabValMin), simd_load_float(tabValMax));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat clamp(const simdfloat& v, const float& minVal, const float& maxVal)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = clamp(veca, 2.0f, 10.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 clamp(const vec2& v, const simdfloat& minVal, const simdfloat& maxVal)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = clamp(vec2a, simd_load_float(tabValMin), simd_load_float(tabValMax));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 clamp(const vec2& v, const float& minVal, const float& maxVal)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = clamp(vec2a, 2.0f, 10.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 clamp(const vec2& v, const vec2& minVal, const vec2& maxVal)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2 vec2Min = vec2(simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec2 vec2Max = vec2(simd_load_float(tabValMax), simd_load_float(tabValMax));
	vec2b = clamp(vec2a, vec2Min, vec2Max);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 clamp(const vec3& v, const simdfloat& minVal, const simdfloat& maxVal)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = clamp(vec3a, simd_load_float(tabValMin), simd_load_float(tabValMax));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 clamp(const vec3& v, const float& minVal, const float& maxVal)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = clamp(vec3a, 2.0f, 10.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 clamp(const vec3& v, const vec3& minVal, const vec3& maxVal)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3 vec3Min = vec3(simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec3 vec3Max = vec3(simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax));
	vec3b = clamp(vec3a, vec3Min, vec3Max);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 clamp(const vec4& v, const simdfloat& minVal, const simdfloat& maxVal)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = clamp(vec4a, simd_load_float(tabValMin), simd_load_float(tabValMax));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 clamp(const vec4& v, const float& minVal, const float& maxVal)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = clamp(vec4a, 2.0f, 10.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 clamp(const vec4& v, const vec4& minVal, const vec4& maxVal)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4 vec4Min = vec4(simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec4 vec4Max = vec4(simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax));
	vec4b = clamp(vec4a, vec4Min, vec4Max);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for cos
	std::cout << "simdfloat cos(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = cos(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::cos(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 cos(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = cos(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::cos(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 cos(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = cos(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::cos(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 cos(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = cos(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::cos(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for cosh
	std::cout << "simdfloat cosh(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = cosh(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::cosh(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 cosh(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = cosh(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::cosh(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 cosh(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = cosh(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::cosh(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 cosh(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = cosh(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::cosh(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for degrees
	std::cout << "simdfloat degrees(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = degrees(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 180.0f / 3.14159265358979323846f; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 degrees(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = degrees(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 180.0f / 3.14159265358979323846f; });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 degrees(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = degrees(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 180.0f / 3.14159265358979323846f; });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 degrees(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = degrees(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 180.0f / 3.14159265358979323846f; });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for exp
	std::cout << "simdfloat exp(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabSmallVal);
	vecb = exp(veca);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::exp(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 exp(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec2b = exp(vec2a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::exp(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 exp(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec3b = exp(vec3a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::exp(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 exp(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec4b = exp(vec4a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::exp(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for exp2
	std::cout << "simdfloat exp2(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabSmallVal);
	vecb = exp2(veca);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::exp2(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 exp2(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec2b = exp2(vec2a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::exp2(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 exp2(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec3b = exp2(vec3a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::exp2(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 exp2(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec4b = exp2(vec4a);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::exp2(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for fma
	std::cout << "simdfloat fma(const simdfloat& _a, const simdfloat& _b, const simdfloat& _c)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = (0.5f);
	vecc = (2.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::fma(val, 0.5f, 2.0f); });
	Compare(fma(veca, vecb, vecc), simd_load_float(tabValResult));

	std::cout << "vec2 fma(const vec2& _a, const vec2& _b, const vec2& _c)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = vec2((0.5f), (0.5f));
	vec2c = vec2((2.0f), (2.0f));
	vec2 vec2FmaResult = fma(vec2a, vec2b, vec2c);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::fma(val, 0.5f, 2.0f); });
	Compare(vec2FmaResult.x, simd_load_float(tabValResult));
	Compare(vec2FmaResult.y, simd_load_float(tabValResult));

	std::cout << "vec3 fma(const vec3& _a, const vec3& _b, const vec3& _c)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = vec3((0.5f), (0.5f), (0.5f));
	vec3c = vec3((2.0f), (2.0f), (2.0f));
	vec3 vec3FmaResult = fma(vec3a, vec3b, vec3c);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::fma(val, 0.5f, 2.0f); });
	Compare(vec3FmaResult.x, simd_load_float(tabValResult));
	Compare(vec3FmaResult.y, simd_load_float(tabValResult));
	Compare(vec3FmaResult.z, simd_load_float(tabValResult));

	std::cout << "vec4 fma(const vec4& _a, const vec4& _b, const vec4& _c)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = vec4((0.5f), (0.5f), (0.5f), (0.5f));
	vec4c = vec4((2.0f), (2.0f), (2.0f), (2.0f));
	vec4 vec4FmaResult = fma(vec4a, vec4b, vec4c);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::fma(val, 0.5f, 2.0f); });
	Compare(vec4FmaResult.x, simd_load_float(tabValResult));
	Compare(vec4FmaResult.y, simd_load_float(tabValResult));
	Compare(vec4FmaResult.z, simd_load_float(tabValResult));
	Compare(vec4FmaResult.w, simd_load_float(tabValResult));

	// Tests for inversesqrt
	std::cout << "simdfloat inversesqrt(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = inversesqrt(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f / std::sqrt(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 inversesqrt(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = inversesqrt(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f / std::sqrt(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 inversesqrt(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = inversesqrt(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f / std::sqrt(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 inversesqrt(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = inversesqrt(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return 1.0f / std::sqrt(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for ldexp
	std::cout << "simdfloat ldexp(const simdfloat& _a, const simdfloat& _b)" << std::endl;
	veca = simd_load_float(tabSmallVal);
	vecb = (2.0f);
	vecc = ldexp(veca, vecb);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::ldexp(val, (int)2.0f); });
	Compare(vecc, simd_load_float(tabValResult));

	std::cout << "vec2 ldexp(const vec2& _a, const vec2& _b)" << std::endl;
	vec2a = vec2(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec2b = vec2((2.0f), (2.0f));
	vec2c = ldexp(vec2a, vec2b);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::ldexp(val, (int)2.0f); });
	Compare(vec2c.x, simd_load_float(tabValResult));
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "vec3 ldexp(const vec3& _a, const vec3& _b)" << std::endl;
	vec3a = vec3(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec3b = vec3((2.0f), (2.0f), (2.0f));
	vec3c = ldexp(vec3a, vec3b);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::ldexp(val, (int)2.0f); });
	Compare(vec3c.x, simd_load_float(tabValResult));
	Compare(vec3c.y, simd_load_float(tabValResult));
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "vec4 ldexp(const vec4& _a, const vec4& _b)" << std::endl;
	vec4a = vec4(simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal), simd_load_float(tabSmallVal));
	vec4b = vec4((2.0f), (2.0f), (2.0f), (2.0f));
	vec4c = ldexp(vec4a, vec4b);
	FillTabResult(tabSmallVal, tabValResult, [](const float& val, const int& idx) { return std::ldexp(val, (int)2.0f); });
	Compare(vec4c.x, simd_load_float(tabValResult));
	Compare(vec4c.y, simd_load_float(tabValResult));
	Compare(vec4c.z, simd_load_float(tabValResult));
	Compare(vec4c.w, simd_load_float(tabValResult));

	// Tests for length
	std::cout << "simdfloat length(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	veca = length(vec2a);
	FillTabResult(tabVal, lengthResult, [](const float& val, const int& idx) { return std::sqrt(val * val + 0.5f * 0.5f); });
	Compare(veca, simd_load_float(lengthResult));

	std::cout << "simdfloat length(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	veca = length(vec3a);
	for (int i = 0; i < 16; ++i) {
		lengthResult[i] = std::sqrt(tabVal[i] * tabVal[i] + 0.5f * 0.5f + 2.0f * 2.0f);
	}
	Compare(veca, simd_load_float(lengthResult));

	std::cout << "simdfloat length(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	veca = length(vec4a);
	for (int i = 0; i < 16; ++i) {
		lengthResult[i] = std::sqrt(tabVal[i] * tabVal[i] + 0.5f * 0.5f + 2.0f * 2.0f + tabValAcosh[i] * tabValAcosh[i]);
	}
	Compare(veca, simd_load_float(lengthResult));

	// Tests for lerp
	std::cout << "simdfloat lerp(const simdfloat&, const simdfloat&, const simdfloat&)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = simd_load_float(tabValMin);
	vecc = (0.5f);
	simdfloat lerpResult = lerp(veca, vecb, vecc);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(lerpResult, simd_load_float(tabValResult));

	std::cout << "simdfloat lerp(const simdfloat&, const simdfloat&, const float&)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = simd_load_float(tabValMin);
	lerpResult = lerp(veca, vecb, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(lerpResult, simd_load_float(tabValResult));

	std::cout << "vec2 lerp(const vec2&, const vec2&, const float&)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (3.0f));
	vec2b = vec2(simd_load_float(tabValMin), (5.0f));
	vec2c = lerp(vec2a, vec2b, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec2c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "vec2 lerp(const vec2&, const vec2&, const simdfloat&)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (3.0f));
	vec2b = vec2(simd_load_float(tabValMin), (5.0f));
	veca = (0.5f);
	vec2c = lerp(vec2a, vec2b, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec2c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "vec2 lerp(const vec2&, const vec2&, const vec2&)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (3.0f));
	vec2b = vec2(simd_load_float(tabValMin), (5.0f));
	vec2 vec2t = vec2((0.5f), (0.3f));
	vec2c = lerp(vec2a, vec2b, vec2t);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec2c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.3f * (5.0f - 3.0f); });
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "vec3 lerp(const vec3&, const vec3&, const float&)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (3.0f), (7.0f));
	vec3b = vec3(simd_load_float(tabValMin), (5.0f), (9.0f));
	vec3c = lerp(vec3a, vec3b, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec3c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec3c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.5f * (9.0f - 7.0f); });
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "vec3 lerp(const vec3&, const vec3&, const simdfloat&)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (3.0f), (7.0f));
	vec3b = vec3(simd_load_float(tabValMin), (5.0f), (9.0f));
	veca = (0.5f);
	vec3c = lerp(vec3a, vec3b, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec3c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec3c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.5f * (9.0f - 7.0f); });
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "vec3 lerp(const vec3&, const vec3&, const vec3&)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (3.0f), (7.0f));
	vec3b = vec3(simd_load_float(tabValMin), (5.0f), (9.0f));
	vec3 vec3t = vec3((0.5f), (0.3f), (0.7f));
	vec3c = lerp(vec3a, vec3b, vec3t);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec3c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.3f * (5.0f - 3.0f); });
	Compare(vec3c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.7f * (9.0f - 7.0f); });
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "vec4 lerp(const vec4&, const vec4&, const float&)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (3.0f), (7.0f), (11.0f));
	vec4b = vec4(simd_load_float(tabValMin), (5.0f), (9.0f), (13.0f));
	vec4c = lerp(vec4a, vec4b, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec4c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec4c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.5f * (9.0f - 7.0f); });
	Compare(vec4c.z, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 11.0f + 0.5f * (13.0f - 11.0f); });
	Compare(vec4c.w, simd_load_float(tabValResult));

	std::cout << "vec4 lerp(const vec4&, const vec4&, const simdfloat&)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (3.0f), (7.0f), (11.0f));
	vec4b = vec4(simd_load_float(tabValMin), (5.0f), (9.0f), (13.0f));
	veca = (0.5f);
	vec4c = lerp(vec4a, vec4b, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec4c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec4c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.5f * (9.0f - 7.0f); });
	Compare(vec4c.z, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 11.0f + 0.5f * (13.0f - 11.0f); });
	Compare(vec4c.w, simd_load_float(tabValResult));

	std::cout << "vec4 lerp(const vec4&, const vec4&, const vec4&)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (3.0f), (7.0f), (11.0f));
	vec4b = vec4(simd_load_float(tabValMin), (5.0f), (9.0f), (13.0f));
	vec4 vec4t = vec4((0.5f), (0.3f), (0.7f), (0.2f));
	vec4c = lerp(vec4a, vec4b, vec4t);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec4c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.3f * (5.0f - 3.0f); });
	Compare(vec4c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.7f * (9.0f - 7.0f); });
	Compare(vec4c.z, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 11.0f + 0.2f * (13.0f - 11.0f); });
	Compare(vec4c.w, simd_load_float(tabValResult));

	// Tests for log
	std::cout << "simdfloat log(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = log(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::log(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 log(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = log(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::log(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 log(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = log(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::log(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 log(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = log(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::log(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for log2
	std::cout << "simdfloat log2(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = log2(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::log2(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 log2(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = log2(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::log2(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 log2(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = log2(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::log2(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 log2(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = log2(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::log2(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for mix
	std::cout << "simdfloat mix(const simdfloat&, const simdfloat&, const simdfloat&)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = simd_load_float(tabValMin);
	vecc = (0.5f);
	simdfloat mixResult = mix(veca, vecb, vecc);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(mixResult, simd_load_float(tabValResult));

	std::cout << "simdfloat mix(const simdfloat&, const simdfloat&, const float&)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = simd_load_float(tabValMin);
	mixResult = mix(veca, vecb, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(mixResult, simd_load_float(tabValResult));

	std::cout << "vec2 mix(const vec2&, const vec2&, const float&)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (3.0f));
	vec2b = vec2(simd_load_float(tabValMin), (5.0f));
	vec2c = mix(vec2a, vec2b, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec2c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "vec2 mix(const vec2&, const vec2&, const simdfloat&)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (3.0f));
	vec2b = vec2(simd_load_float(tabValMin), (5.0f));
	veca = (0.5f);
	vec2c = mix(vec2a, vec2b, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec2c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "vec2 mix(const vec2&, const vec2&, const vec2&)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (3.0f));
	vec2b = vec2(simd_load_float(tabValMin), (5.0f));
	vec2t = vec2((0.5f), (0.3f));
	vec2c = mix(vec2a, vec2b, vec2t);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec2c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.3f * (5.0f - 3.0f); });
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "vec3 mix(const vec3&, const vec3&, const float&)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (3.0f), (7.0f));
	vec3b = vec3(simd_load_float(tabValMin), (5.0f), (9.0f));
	vec3c = mix(vec3a, vec3b, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec3c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec3c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.5f * (9.0f - 7.0f); });
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "vec3 mix(const vec3&, const vec3&, const simdfloat&)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (3.0f), (7.0f));
	vec3b = vec3(simd_load_float(tabValMin), (5.0f), (9.0f));
	veca = (0.5f);
	vec3c = mix(vec3a, vec3b, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec3c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec3c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.5f * (9.0f - 7.0f); });
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "vec3 mix(const vec3&, const vec3&, const vec3&)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (3.0f), (7.0f));
	vec3b = vec3(simd_load_float(tabValMin), (5.0f), (9.0f));
	vec3t = vec3((0.5f), (0.3f), (0.7f));
	vec3c = mix(vec3a, vec3b, vec3t);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec3c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.3f * (5.0f - 3.0f); });
	Compare(vec3c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.7f * (9.0f - 7.0f); });
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "vec4 mix(const vec4&, const vec4&, const float&)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (3.0f), (7.0f), (11.0f));
	vec4b = vec4(simd_load_float(tabValMin), (5.0f), (9.0f), (13.0f));
	vec4c = mix(vec4a, vec4b, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec4c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec4c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.5f * (9.0f - 7.0f); });
	Compare(vec4c.z, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 11.0f + 0.5f * (13.0f - 11.0f); });
	Compare(vec4c.w, simd_load_float(tabValResult));

	std::cout << "vec4 mix(const vec4&, const vec4&, const simdfloat&)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (3.0f), (7.0f), (11.0f));
	vec4b = vec4(simd_load_float(tabValMin), (5.0f), (9.0f), (13.0f));
	veca = (0.5f);
	vec4c = mix(vec4a, vec4b, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec4c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.5f * (5.0f - 3.0f); });
	Compare(vec4c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.5f * (9.0f - 7.0f); });
	Compare(vec4c.z, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 11.0f + 0.5f * (13.0f - 11.0f); });
	Compare(vec4c.w, simd_load_float(tabValResult));

	std::cout << "vec4 mix(const vec4&, const vec4&, const vec4&)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (3.0f), (7.0f), (11.0f));
	vec4b = vec4(simd_load_float(tabValMin), (5.0f), (9.0f), (13.0f));
	vec4t = vec4((0.5f), (0.3f), (0.7f), (0.2f));
	vec4c = mix(vec4a, vec4b, vec4t);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val + 0.5f * (2.0f - val); });
	Compare(vec4c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 3.0f + 0.3f * (5.0f - 3.0f); });
	Compare(vec4c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 7.0f + 0.7f * (9.0f - 7.0f); });
	Compare(vec4c.z, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) { return 11.0f + 0.2f * (13.0f - 11.0f); });
	Compare(vec4c.w, simd_load_float(tabValResult));


	// Tests for radians
	std::cout << "simdfloat radians(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = radians(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 3.14159265358979323846f / 180.0f; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 radians(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = radians(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 3.14159265358979323846f / 180.0f; });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 radians(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = radians(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 3.14159265358979323846f / 180.0f; });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 radians(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = radians(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val * 3.14159265358979323846f / 180.0f; });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for reflect
	std::cout << "vec2 reflect(const vec2& _a, const vec2& _b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = normalize(vec2((2.0f), (2.0f)));
	vec2c = reflect(vec2a, vec2b);
	// reflect(I, N) = I - 2.0 * dot(N, I) * N
	for (int idx = 0; idx < 16; ++idx) {
		float tempAX = tabVal[idx];
		float tempAY = 0.5f;
		float tempBX = 2.0f / std::sqrt(2.0f * 2.0f + 2.0f * 2.0f);
		float tempBY = 2.0f / std::sqrt(2.0f * 2.0f + 2.0f * 2.0f);
		tabValResult[idx] = tempAX - 2.0f * (tempBX * tempAX + tempBY * tempAY) * tempBX;
	}
	Compare(vec2c.x, simd_load_float(tabValResult));

	std::cout << "vec3 reflect(const vec3& _a, const vec3& _b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = normalize(vec3((2.0f), (2.0f), (2.0f)));
	vec3c = reflect(vec3a, vec3b);
	for (int idx = 0; idx < 16; ++idx) {
		float tempAX = tabVal[idx];
		float tempAY = 0.5f;
		float tempAZ = 2.0f;
		float tempBX = 2.0f / std::sqrt(2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f);
		float tempBY = 2.0f / std::sqrt(2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f);
		float tempBZ = 2.0f / std::sqrt(2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f);
		tabValResult[idx] = tempAX - 2.0f * (tempBX * tempAX + tempBY * tempAY + tempBZ * tempAZ) * tempBX;
	}
	Compare(vec3c.x, simd_load_float(tabValResult));

	std::cout << "vec4 reflect(const vec4& _a, const vec4& _b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = normalize(vec4((2.0f), (2.0f), (2.0f), (2.0f)));
	vec4c = reflect(vec4a, vec4b);
	for (int idx = 0; idx < 16; ++idx) {
		float tempAX = tabVal[idx];
		float tempAY = 0.5f;
		float tempAZ = 2.0f;
		float tempAW = tabValAcosh[idx];
		float tempBX = 2.0f / std::sqrt(2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f);
		float tempBY = 2.0f / std::sqrt(2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f);
		float tempBZ = 2.0f / std::sqrt(2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f);
		float tempBW = 2.0f / std::sqrt(2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f + 2.0f * 2.0f);
		tabValResult[idx] = tempAX - 2.0f * (tempBX * tempAX + tempBY * tempAY + tempBZ * tempAZ + tempBW * tempAW) * tempBX;
	}
	Compare(vec4c.x, simd_load_float(tabValResult));

	// Tests for refract
	// Tests for refract
	std::cout << "vec2 refract(const vec2& _a, const vec2& _b, const float& eta)" << std::endl;
	vec2a = vec2(simd_load_float(tabSmallVal), (0.5f));
	vec2b = normalize(vec2((0.0f), (1.0f)));
	vec2c = refract(vec2a, vec2b, 0.75f);
	for (int idx = 0; idx < 16; ++idx) {
		float I_x = tabSmallVal[idx];
		float I_y = 0.5f;
		float N_x = 0.0f;
		float N_y = 1.0f;
		float eta = 0.75f;
		float dotNI = N_x * I_x + N_y * I_y;
		float k = 1.0f - eta * eta * (1.0f - dotNI * dotNI);
		if (k < 0.0f) {
			tabValResult[idx] = 0.0f;
		}
		else {
			tabValResult[idx] = eta * I_x - (eta * dotNI + std::sqrt(k)) * N_x;
		}
	}
	Compare(vec2c.x, simd_load_float(tabValResult));

	std::cout << "vec2 refract(const vec2& _a, const vec2& _b, const simdfloat& eta)" << std::endl;
	vec2a = vec2(simd_load_float(tabSmallVal), (0.5f));
	vec2b = normalize(vec2((0.0f), (1.0f)));
	vec2c = refract(vec2a, vec2b, (0.75f));
	for (int idx = 0; idx < 16; ++idx) {
		float I_x = tabSmallVal[idx];
		float I_y = 0.5f;
		float N_x = 0.0f;
		float N_y = 1.0f;
		float eta = 0.75f;
		float dotNI = N_x * I_x + N_y * I_y;
		float k = 1.0f - eta * eta * (1.0f - dotNI * dotNI);
		if (k < 0.0f) {
			tabValResult[idx] = 0.0f;
		}
		else {
			tabValResult[idx] = eta * I_x - (eta * dotNI + std::sqrt(k)) * N_x;
		}
	}
	Compare(vec2c.x, simd_load_float(tabValResult));

	std::cout << "vec3 refract(const vec3& _a, const vec3& _b, const float& eta)" << std::endl;
	vec3a = vec3(simd_load_float(tabSmallVal), (0.5f), (0.2f));
	vec3b = normalize(vec3((0.0f), (1.0f), (0.0f)));
	vec3c = refract(vec3a, vec3b, 0.75f);
	for (int idx = 0; idx < 16; ++idx) {
		float I_x = tabSmallVal[idx];
		float I_y = 0.5f;
		float I_z = 0.2f;
		float N_x = 0.0f;
		float N_y = 1.0f;
		float N_z = 0.0f;
		float eta = 0.75f;
		float dotNI = N_x * I_x + N_y * I_y + N_z * I_z;
		float k = 1.0f - eta * eta * (1.0f - dotNI * dotNI);
		if (k < 0.0f) {
			tabValResult[idx] = 0.0f;
		}
		else {
			tabValResult[idx] = eta * I_x - (eta * dotNI + std::sqrt(k)) * N_x;
		}
	}
	Compare(vec3c.x, simd_load_float(tabValResult));

	std::cout << "vec3 refract(const vec3& _a, const vec3& _b, const simdfloat& eta)" << std::endl;
	vec3a = vec3(simd_load_float(tabSmallVal), (0.5f), (0.2f));
	vec3b = normalize(vec3((0.0f), (1.0f), (0.0f)));
	vec3c = refract(vec3a, vec3b, (0.75f));
	for (int idx = 0; idx < 16; ++idx) {
		float I_x = tabSmallVal[idx];
		float I_y = 0.5f;
		float I_z = 0.2f;
		float N_x = 0.0f;
		float N_y = 1.0f;
		float N_z = 0.0f;
		float eta = 0.75f;
		float dotNI = N_x * I_x + N_y * I_y + N_z * I_z;
		float k = 1.0f - eta * eta * (1.0f - dotNI * dotNI);
		if (k < 0.0f) {
			tabValResult[idx] = 0.0f;
		}
		else {
			tabValResult[idx] = eta * I_x - (eta * dotNI + std::sqrt(k)) * N_x;
		}
	}
	Compare(vec3c.x, simd_load_float(tabValResult));

	std::cout << "vec4 refract(const vec4& _a, const vec4& _b, const float& eta)" << std::endl;
	vec4a = vec4(simd_load_float(tabSmallVal), (0.5f), (0.2f), (0.1f));
	vec4b = normalize(vec4((0.0f), (1.0f), (0.0f), (0.0f)));
	vec4c = refract(vec4a, vec4b, 0.75f);
	for (int idx = 0; idx < 16; ++idx) {
		float I_x = tabSmallVal[idx];
		float I_y = 0.5f;
		float I_z = 0.2f;
		float I_w = 0.1f;
		float N_x = 0.0f;
		float N_y = 1.0f;
		float N_z = 0.0f;
		float N_w = 0.0f;
		float eta = 0.75f;
		float dotNI = N_x * I_x + N_y * I_y + N_z * I_z + N_w * I_w;
		float k = 1.0f - eta * eta * (1.0f - dotNI * dotNI);
		if (k < 0.0f) {
			tabValResult[idx] = 0.0f;
		}
		else {
			tabValResult[idx] = eta * I_x - (eta * dotNI + std::sqrt(k)) * N_x;
		}
	}
	Compare(vec4c.x, simd_load_float(tabValResult));

	std::cout << "vec4 refract(const vec4& _a, const vec4& _b, const simdfloat& eta)" << std::endl;
	vec4a = vec4(simd_load_float(tabSmallVal), (0.5f), (0.2f), (0.1f));
	vec4b = normalize(vec4((0.0f), (1.0f), (0.0f), (0.0f)));
	vec4c = refract(vec4a, vec4b, (0.75f));
	for (int idx = 0; idx < 16; ++idx) {
		float I_x = tabSmallVal[idx];
		float I_y = 0.5f;
		float I_z = 0.2f;
		float I_w = 0.1f;
		float N_x = 0.0f;
		float N_y = 1.0f;
		float N_z = 0.0f;
		float N_w = 0.0f;
		float eta = 0.75f;
		float dotNI = N_x * I_x + N_y * I_y + N_z * I_z + N_w * I_w;
		float k = 1.0f - eta * eta * (1.0f - dotNI * dotNI);
		if (k < 0.0f) {
			tabValResult[idx] = 0.0f;
		}
		else {
			tabValResult[idx] = eta * I_x - (eta * dotNI + std::sqrt(k)) * N_x;
		}
	}
	Compare(vec4c.x, simd_load_float(tabValResult));


	// Tests for round
	std::cout << "simdfloat round(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = round(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::round(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 round(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = round(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::round(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 round(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = round(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::round(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 round(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = round(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::round(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for sign
	std::cout << "simdfloat sign(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabValNeg);
	vecb = sign(veca);
	FillTabResult(tabValNeg, tabValResult, [](const float& val, const int& idx) { return val > 0.0f ? 1.0f : (val < 0.0f ? -1.0f : 0.0f); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 sign(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabValNeg), simd_load_float(tabValNeg));
	vec2b = sign(vec2a);
	FillTabResult(tabValNeg, tabValResult, [](const float& val, const int& idx) { return val > 0.0f ? 1.0f : (val < 0.0f ? -1.0f : 0.0f); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 sign(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabValNeg), simd_load_float(tabValNeg), simd_load_float(tabValNeg));
	vec3b = sign(vec3a);
	FillTabResult(tabValNeg, tabValResult, [](const float& val, const int& idx) { return val > 0.0f ? 1.0f : (val < 0.0f ? -1.0f : 0.0f); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 sign(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabValNeg), simd_load_float(tabValNeg), simd_load_float(tabValNeg), simd_load_float(tabValNeg));
	vec4b = sign(vec4a);
	FillTabResult(tabValNeg, tabValResult, [](const float& val, const int& idx) { return val > 0.0f ? 1.0f : (val < 0.0f ? -1.0f : 0.0f); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for sin
	std::cout << "simdfloat sin(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = sin(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sin(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 sin(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = sin(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sin(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 sin(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = sin(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sin(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 sin(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = sin(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sin(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for sinh
	std::cout << "simdfloat sinh(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = sinh(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sinh(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 sinh(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = sinh(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sinh(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 sinh(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = sinh(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sinh(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 sinh(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = sinh(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sinh(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for step
	std::cout << "simdfloat step(const simdfloat& _edge, const simdfloat& _x)" << std::endl;
	veca = simd_load_float(tabValMin); // edge = 2.0f
	vecb = simd_load_float(tabVal);     // x
	vecc = step(veca, vecb);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vecc, simd_load_float(tabValResult));

	std::cout << "simdfloat step(const float& _edge, const simdfloat& _x)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = step(5.0f, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 5.0f ? 0.0f : 1.0f;
		});
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "simdfloat step(const simdfloat& _edge, const float& _x)" << std::endl;
	veca = simd_load_float(tabValMin); // edge = 2.0f
	vecb = step(veca, 5.0f);
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 5.0f < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 step(const vec2& _edge, const simdfloat& _x)" << std::endl;
	vec2a = vec2(simd_load_float(tabValMin), (5.0f));
	veca = simd_load_float(tabVal);
	vec2b = step(vec2a, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec2b.x, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 5.0f ? 0.0f : 1.0f;
		});
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 step(const simdfloat& _edge, const vec2& _x)" << std::endl;
	veca = simd_load_float(tabValMin); // edge = 2.0f
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = step(veca, vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec2b.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 0.5f < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 step(const vec2& _edge, const vec2& _x)" << std::endl;
	vec2a = vec2(simd_load_float(tabValMin), (5.0f));
	vec2b = vec2(simd_load_float(tabVal), (7.0f));
	vec2c = step(vec2a, vec2b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec2c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 7.0f < 5.0f ? 0.0f : 1.0f;
		});
	Compare(vec2c.y, simd_load_float(tabValResult));

	std::cout << "vec3 step(const vec3& _edge, const simdfloat& _x)" << std::endl;
	vec3a = vec3(simd_load_float(tabValMin), (5.0f), (8.0f));
	veca = simd_load_float(tabVal);
	vec3b = step(vec3a, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec3b.x, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 5.0f ? 0.0f : 1.0f;
		});
	Compare(vec3b.y, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 8.0f ? 0.0f : 1.0f;
		});
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 step(const simdfloat& _edge, const vec3& _x)" << std::endl;
	veca = simd_load_float(tabValMin); // edge = 2.0f
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (7.0f));
	vec3b = step(veca, vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec3b.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 0.5f < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec3b.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 7.0f < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 step(const vec3& _edge, const vec3& _x)" << std::endl;
	vec3a = vec3(simd_load_float(tabValMin), (5.0f), (8.0f));
	vec3b = vec3(simd_load_float(tabVal), (7.0f), (12.0f));
	vec3c = step(vec3a, vec3b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec3c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 7.0f < 5.0f ? 0.0f : 1.0f;
		});
	Compare(vec3c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 12.0f < 8.0f ? 0.0f : 1.0f;
		});
	Compare(vec3c.z, simd_load_float(tabValResult));

	std::cout << "vec4 step(const vec4& _edge, const simdfloat& _x)" << std::endl;
	vec4a = vec4(simd_load_float(tabValMin), (5.0f), (8.0f), (11.0f));
	veca = simd_load_float(tabVal);
	vec4b = step(vec4a, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec4b.x, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 5.0f ? 0.0f : 1.0f;
		});
	Compare(vec4b.y, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 8.0f ? 0.0f : 1.0f;
		});
	Compare(vec4b.z, simd_load_float(tabValResult));
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 11.0f ? 0.0f : 1.0f;
		});
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 step(const simdfloat& _edge, const vec4& _x)" << std::endl;
	veca = simd_load_float(tabValMin); // edge = 2.0f
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (7.0f), (3.0f));
	vec4b = step(veca, vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec4b.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 0.5f < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec4b.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 7.0f < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec4b.z, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 3.0f < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 step(const vec4& _edge, const vec4& _x)" << std::endl;
	vec4a = vec4(simd_load_float(tabValMin), (5.0f), (8.0f), (11.0f));
	vec4b = vec4(simd_load_float(tabVal), (7.0f), (12.0f), (9.0f));
	vec4c = step(vec4a, vec4b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		return val < 2.0f ? 0.0f : 1.0f;
		});
	Compare(vec4c.x, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 7.0f < 5.0f ? 0.0f : 1.0f;
		});
	Compare(vec4c.y, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 12.0f < 8.0f ? 0.0f : 1.0f;
		});
	Compare(vec4c.z, simd_load_float(tabValResult));
	FillTabResult(tabValResult, tabValResult, [](const float& val, const int& idx) {
		return 9.0f < 11.0f ? 0.0f : 1.0f;
		});
	Compare(vec4c.w, simd_load_float(tabValResult));


	// Tests for sqrt
	std::cout << "simdfloat sqrt(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = sqrt(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sqrt(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 sqrt(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = sqrt(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sqrt(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 sqrt(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = sqrt(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sqrt(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 sqrt(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = sqrt(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::sqrt(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for tan
	std::cout << "simdfloat tan(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = tan(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::tan(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 tan(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = tan(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::tan(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 tan(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = tan(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::tan(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 tan(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = tan(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::tan(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for tanh
	std::cout << "simdfloat tanh(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = tanh(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::tanh(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 tanh(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = tanh(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::tanh(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 tanh(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = tanh(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::tanh(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 tanh(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = tanh(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::tanh(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for trunc
	std::cout << "simdfloat trunc(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabRandomVal);
	vecb = trunc(veca);
	FillTabResult(tabRandomVal, tabValResult, [](const float& val, const int& idx) { return std::trunc(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 trunc(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = trunc(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::trunc(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 trunc(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = trunc(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::trunc(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 trunc(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = trunc(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::trunc(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for dot
	std::cout << "simdfloat dot(const vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = vec2((2.0f), simd_load_float(tabValAcosh));
	veca = dot(vec2a, vec2b);
	for (int i = 0; i < simdwidth; i++) {
		tabValResult[i] = tabVal[i] * 2.0f + 0.5f * tabValAcosh[i];
	}
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat dot(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = vec3((2.0f), simd_load_float(tabValAcosh), simd_load_float(tabValMin));
	veca = dot(vec3a, vec3b);
	for (int i = 0; i < simdwidth; i++) {
		tabValResult[i] = tabVal[i] * 2.0f + 0.5f * tabValAcosh[i] + 2.0f * tabValMin[i];
	}
	Compare(veca, simd_load_float(tabValResult));

	std::cout << "simdfloat dot(const vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = vec4((2.0f), simd_load_float(tabValAcosh), simd_load_float(tabValMin), simd_load_float(tabValMax));
	veca = dot(vec4a, vec4b);
	for (int i = 0; i < simdwidth; i++) {
		tabValResult[i] = tabVal[i] * 2.0f + 0.5f * tabValAcosh[i] + 2.0f * tabValMin[i] + tabValAcosh[i] * tabValMax[i];
	}
	Compare(veca, simd_load_float(tabValResult));

	// Tests for cross
	std::cout << "vec3 cross(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = vec3((2.0f), simd_load_float(tabValAcosh), simd_load_float(tabValMin));
	vec3c = cross(vec3a, vec3b);
	for (int i = 0; i < simdwidth; i++) {
		tabValResult[i] = 0.5f * tabValMin[i] - 2.0f * tabValAcosh[i];
	}
	Compare(vec3c.x, simd_load_float(tabValResult));
	for (int i = 0; i < simdwidth; i++) {
		tabValResult[i] = 2.0f * 2.0f - tabVal[i] * tabValMin[i];
	}
	Compare(vec3c.y, simd_load_float(tabValResult));
	for (int i = 0; i < simdwidth; i++) {
		tabValResult[i] = tabVal[i] * tabValAcosh[i] - 0.5f * 2.0f;
	}
	Compare(vec3c.z, simd_load_float(tabValResult));

	// Tests for normalize
	std::cout << "vec2 normalize(const vec2& v)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = normalize(vec2a);
	for (int i = 0; i < simdwidth; i++) {
		float len = std::sqrt(tabVal[i] * tabVal[i] + 0.5f * 0.5f);
		tabValResult[i] = tabVal[i] / len;
	}
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec3 normalize(const vec3& v)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = normalize(vec3a);
	for (int i = 0; i < simdwidth; i++) {
		float len = std::sqrt(tabVal[i] * tabVal[i] + 0.5f * 0.5f + 2.0f * 2.0f);
		tabValResult[i] = tabVal[i] / len;
	}
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec4 normalize(const vec4& v)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = normalize(vec4a);
	for (int i = 0; i < simdwidth; i++) {
		float len = std::sqrt(tabVal[i] * tabVal[i] + 0.5f * 0.5f + 2.0f * 2.0f + tabValAcosh[i] * tabValAcosh[i]);
		tabValResult[i] = tabVal[i] / len;
	}
	Compare(vec4b.x, simd_load_float(tabValResult));
	for (int i = 0; i < simdwidth; i++) {
		float len = std::sqrt(tabVal[i] * tabVal[i] + 0.5f * 0.5f + 2.0f * 2.0f + tabValAcosh[i] * tabValAcosh[i]);
		tabValResult[i] = 0.5f / len;
	}
	Compare(vec4b.y, simd_load_float(tabValResult));
	for (int i = 0; i < simdwidth; i++) {
		float len = std::sqrt(tabVal[i] * tabVal[i] + 0.5f * 0.5f + 2.0f * 2.0f + tabValAcosh[i] * tabValAcosh[i]);
		tabValResult[i] = 2.0f / len;
	}
	Compare(vec4b.z, simd_load_float(tabValResult));
	for (int i = 0; i < simdwidth; i++) {
		float len = std::sqrt(tabVal[i] * tabVal[i] + 0.5f * 0.5f + 2.0f * 2.0f + tabValAcosh[i] * tabValAcosh[i]);
		tabValResult[i] = tabValAcosh[i] / len;
	}
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for floor
	std::cout << "simdfloat floor(const simdfloat& _a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = floor(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::floor(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 floor(const vec2& _a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = floor(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::floor(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 floor(const vec3& _a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = floor(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::floor(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 floor(const vec4& _a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = floor(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::floor(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for fract
	std::cout << "simdfloat fract(const simdfloat& a)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = fract(veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 fract(const vec2& a)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), simd_load_float(tabVal));
	vec2b = fract(vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val); });
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec3 fract(const vec3& a)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec3b = fract(vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val); });
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec4 fract(const vec4& a)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal), simd_load_float(tabVal));
	vec4b = fract(vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val); });
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	// Tests for mod
	std::cout << "simdfloat mod(const simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = (0.5f);
	vecc = mod(veca, vecb);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 0.5f) * 0.5f; });
	Compare(vecc, simd_load_float(tabValResult));

	std::cout << "simdfloat mod(const simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = mod(veca, 3.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 3.0f) * 3.0f; });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 mod(const vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = mod(vec2a, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 0.5f) * 0.5f; });
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec2 mod(const vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = mod(vec2a, 3.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 3.0f) * 3.0f; });
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec2 mod(const vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = vec2((0.5f), (2.0f));
	vec2c = mod(vec2a, vec2b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 0.5f) * 0.5f; });
	Compare(vec2c.x, simd_load_float(tabValResult));

	std::cout << "vec3 mod(const vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = mod(vec3a, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 0.5f) * 0.5f; });
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec3 mod(const vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = mod(vec3a, 3.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 3.0f) * 3.0f; });
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec3 mod(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = vec3((0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec3c = mod(vec3a, vec3b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 0.5f) * 0.5f; });
	Compare(vec3c.x, simd_load_float(tabValResult));

	std::cout << "vec4 mod(const vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = mod(vec4a, 0.5f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 0.5f) * 0.5f; });
	Compare(vec4b.x, simd_load_float(tabValResult));

	std::cout << "vec4 mod(const vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = mod(vec4a, 3.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 3.0f) * 3.0f; });
	Compare(vec4b.x, simd_load_float(tabValResult));

	std::cout << "vec4 mod(const vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = vec4((0.5f), (2.0f), simd_load_float(tabValAcosh), simd_load_float(tabValMin));
	vec4c = mod(vec4a, vec4b);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return val - std::floor(val / 0.5f) * 0.5f; });
	Compare(vec4c.x, simd_load_float(tabValResult));

	// Tests for modf
	std::cout << "modf(const simddouble&, simddouble&)" << std::endl;
	std::cout << "modf(const dvec2&, dvec2&)" << std::endl;
	std::cout << "modf(const dvec3&, dvec3&)" << std::endl;
	std::cout << "modf(const dvec4&, dvec4&)" << std::endl;

	// Tests for pow
	std::cout << "simdfloat pow(const simdfloat& a, const simdfloat& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = (2.0f);
	vecc = pow(veca, vecb);
	FillTabResult(tabVal, tabValResult, [&tabSmallVal](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vecc, simd_load_float(tabValResult));

	std::cout << "simdfloat pow(const simdfloat& a, const float& b)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = pow(veca, 2.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 pow(const vec2& a, const simdfloat& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = pow(vec2a, (2.0f));
	FillTabResult(tabVal, tabValResult, [&tabSmallVal](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec2 pow(const vec2& a, const float& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = pow(vec2a, 2.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec2 pow(const vec2& a, const vec2& b)" << std::endl;
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = vec2((2.0f), (2.0f));
	vec2c = pow(vec2a, vec2b);
	FillTabResult(tabVal, tabValResult, [&tabSmallVal](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vec2c.x, simd_load_float(tabValResult));

	std::cout << "vec3 pow(const vec3& a, const simdfloat& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = pow(vec3a, (2.0f));
	FillTabResult(tabVal, tabValResult, [&tabSmallVal](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec3 pow(const vec3& a, const float& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = pow(vec3a, 2.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec3 pow(const vec3& a, const vec3& b)" << std::endl;
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = vec3((2.0f), (2.0f), (2.0f));
	vec3c = pow(vec3a, vec3b);
	FillTabResult(tabVal, tabValResult, [&tabSmallVal](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vec3c.x, simd_load_float(tabValResult));

	std::cout << "vec4 pow(const vec4& a, const simdfloat& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = pow(vec4a, (2.0f));
	FillTabResult(tabVal, tabValResult, [&tabSmallVal](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vec4b.x, simd_load_float(tabValResult));

	std::cout << "vec4 pow(const vec4& a, const float& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = pow(vec4a, 2.0f);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vec4b.x, simd_load_float(tabValResult));

	std::cout << "vec4 pow(const vec4& a, const vec4& b)" << std::endl;
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = vec4((2.0f), (2.0f), (2.0f), (2.0f));
	vec4c = pow(vec4a, vec4b);
	FillTabResult(tabVal, tabValResult, [&tabSmallVal](const float& val, const int& idx) { return std::pow(val, 2.0f); });
	Compare(vec4c.x, simd_load_float(tabValResult));

	// Tests for smoothstep
	std::cout << "simdfloat smoothstep(const simdfloat& edge0, const simdfloat& edge1, const simdfloat& x)" << std::endl;
	veca = simd_load_float(tabValMin); // edge0 = 2.0f
	vecb = simd_load_float(tabValMax); // edge1 = 10.0f
	vecc = simd_load_float(tabVal);    // x
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (val - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(smoothstep(veca, vecb, vecc), simd_load_float(tabValResult));

	std::cout << "simdfloat smoothstep(const float& edge0, const float& edge1, const simdfloat& x)" << std::endl;
	veca = simd_load_float(tabVal);
	vecb = smoothstep(2.0f, 10.0f, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (val - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vecb, simd_load_float(tabValResult));

	std::cout << "vec2 smoothstep(const vec2& edge0, const vec2& edge1, const simdfloat& x)" << std::endl;
	vec2Min = vec2(simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec2Max = vec2(simd_load_float(tabValMax), simd_load_float(tabValMax));
	veca = simd_load_float(tabVal);
	vec2b = smoothstep(vec2Min, vec2Max, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (val - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 smoothstep(const vec2& edge0, const vec2& edge1, const float& x)" << std::endl;
	vec2Min = vec2(simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec2Max = vec2(simd_load_float(tabValMax), simd_load_float(tabValMax));
	vec2b = smoothstep(vec2Min, vec2Max, 5.0f);
	FillTabResult(tabValMin, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (5.0f - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vec2b.x, simd_load_float(tabValResult));
	Compare(vec2b.y, simd_load_float(tabValResult));

	std::cout << "vec2 smoothstep(const vec2& edge0, const vec2& edge1, const vec2& x)" << std::endl;
	vec2Min = vec2(simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec2Max = vec2(simd_load_float(tabValMax), simd_load_float(tabValMax));
	vec2a = vec2(simd_load_float(tabVal), (0.5f));
	vec2b = smoothstep(vec2Min, vec2Max, vec2a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (val - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vec2b.x, simd_load_float(tabValResult));

	std::cout << "vec3 smoothstep(const vec3& edge0, const vec3& edge1, const simdfloat& x)" << std::endl;
	vec3Min = vec3(simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec3Max = vec3(simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax));
	veca = simd_load_float(tabVal);
	vec3b = smoothstep(vec3Min, vec3Max, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (val - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 smoothstep(const vec3& edge0, const vec3& edge1, const float& x)" << std::endl;
	vec3Min = vec3(simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec3Max = vec3(simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax));
	vec3b = smoothstep(vec3Min, vec3Max, 5.0f);
	FillTabResult(tabValMin, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (5.0f - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vec3b.x, simd_load_float(tabValResult));
	Compare(vec3b.y, simd_load_float(tabValResult));
	Compare(vec3b.z, simd_load_float(tabValResult));

	std::cout << "vec3 smoothstep(const vec3& edge0, const vec3& edge1, const vec3& x)" << std::endl;
	vec3Min = vec3(simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec3Max = vec3(simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax));
	vec3a = vec3(simd_load_float(tabVal), (0.5f), (2.0f));
	vec3b = smoothstep(vec3Min, vec3Max, vec3a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (val - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vec3b.x, simd_load_float(tabValResult));

	std::cout << "vec4 smoothstep(const vec4& edge0, const vec4& edge1, const simdfloat& x)" << std::endl;
	vec4Min = vec4(simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec4Max = vec4(simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax));
	veca = simd_load_float(tabVal);
	vec4b = smoothstep(vec4Min, vec4Max, veca);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (val - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 smoothstep(const vec4& edge0, const vec4& edge1, const float& x)" << std::endl;
	vec4Min = vec4(simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec4Max = vec4(simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax));
	vec4b = smoothstep(vec4Min, vec4Max, 5.0f);
	FillTabResult(tabValMin, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (5.0f - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vec4b.x, simd_load_float(tabValResult));
	Compare(vec4b.y, simd_load_float(tabValResult));
	Compare(vec4b.z, simd_load_float(tabValResult));
	Compare(vec4b.w, simd_load_float(tabValResult));

	std::cout << "vec4 smoothstep(const vec4& edge0, const vec4& edge1, const vec4& x)" << std::endl;
	vec4Min = vec4(simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin), simd_load_float(tabValMin));
	vec4Max = vec4(simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax), simd_load_float(tabValMax));
	vec4a = vec4(simd_load_float(tabVal), (0.5f), (2.0f), simd_load_float(tabValAcosh));
	vec4b = smoothstep(vec4Min, vec4Max, vec4a);
	FillTabResult(tabVal, tabValResult, [](const float& val, const int& idx) {
		float t = std::max(0.0f, std::min(1.0f, (val - 2.0f) / (10.0f - 2.0f)));
		return t * t * (3.0f - 2.0f * t);
		});
	Compare(vec4b.x, simd_load_float(tabValResult));


	// Tests for mat2 multiplication
	std::cout << "vec2 mul(const mat2& m, const vec2& v)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	vec2a = vec2((5.0f), (6.0f));
	vec2b = mul(mat2a, vec2a);
	Compare(vec2b.x, (23.0f));
	Compare(vec2b.y, (34.0f));

	std::cout << "vec2 mul(const vec2& v, const mat2& m)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	vec2a = vec2((5.0f), (6.0f));
	vec2b = mul(vec2a, mat2a);
	Compare(vec2b.x, (17.0f));
	Compare(vec2b.y, (39.0f));

	std::cout << "mat2 mul(const mat2& _m1, const mat2& _mat2)" << std::endl;
	mat2b = mat2((1.0f), (0.0f), (2.0f), (-1.0f));
	mat2a = mat2((3.0f), (4.0f), (-2.0f), (-3.0f));
	mat2c = mul(mat2a, mat2b);
	Compare(mat2c[0][0], (3.0f));
	Compare(mat2c[0][1], (4.0f));
	Compare(mat2c[1][0], (8.0f));
	Compare(mat2c[1][1], (11.0f));

	std::cout << "vec2 operator*(const mat2& m, const vec2& v)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	vec2a = vec2((5.0f), (6.0f));
	vec2b = mat2a * vec2a;
	Compare(vec2b.x, (23.0f));
	Compare(vec2b.y, (34.0f));

	std::cout << "vec2 operator*(const vec2& v, const mat2& m)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	vec2a = vec2((5.0f), (6.0f));
	vec2b = vec2a * mat2a;
	Compare(vec2b.x, (17.0f));
	Compare(vec2b.y, (39.0f));

	// Tests for mat3 multiplication
	std::cout << "vec3 mul(const mat3& m, const vec3& v)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	vec3a = vec3((2.0f), (3.0f), (4.0f));
	vec3b = mul(mat3a, vec3a);
	Compare(vec3b.x, (42.0f));
	Compare(vec3b.y, (51.0f));
	Compare(vec3b.z, (60.0f));

	std::cout << "vec3 mul(const vec3& v, const mat3& m)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	vec3a = vec3((2.0f), (3.0f), (4.0f));
	vec3b = mul(vec3a, mat3a);
	Compare(vec3b.x, (20.0f));
	Compare(vec3b.y, (47.0f));
	Compare(vec3b.z, (74.0f));

	std::cout << "mat3 mul(const mat3& _m1, const mat3& _mat2)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = mat3((11.0f), (12.0f), (13.0f),
		(14.0f), (15.0f), (16.0f),
		(17.0f), (18.0f), (19.0f));
	mat3c = mul(mat3a, mat3b);
	Compare(mat3c[0][0], (150.0f));
	Compare(mat3c[0][1], (186.0f));
	Compare(mat3c[0][2], (222.0f));
	Compare(mat3c[1][0], (186.0f));
	Compare(mat3c[1][1], (231.0f));
	Compare(mat3c[1][2], (276.0f));
	Compare(mat3c[2][0], (222.0f));
	Compare(mat3c[2][1], (276.0f));
	Compare(mat3c[2][2], (330.0f));

	std::cout << "vec3 operator*(const mat3& m, const vec3& v)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	vec3a = vec3((2.0f), (3.0f), (4.0f));
	vec3b = mat3a * vec3a;
	Compare(vec3b.x, (42.0f));
	Compare(vec3b.y, (51.0f));
	Compare(vec3b.z, (60.0f));

	std::cout << "vec3 operator*(const vec3& v, const mat3& m)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	vec3a = vec3((2.0f), (3.0f), (4.0f));
	vec3b = vec3a * mat3a;
	Compare(vec3b.x, (20.0f));
	Compare(vec3b.y, (47.0f));
	Compare(vec3b.z, (74.0f));

	// Tests for mat4 multiplication
	std::cout << "vec4 mul(const mat4& m, const vec4& v)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	vec4a = vec4((2.0f), (3.0f), (4.0f), (5.0f));
	vec4b = mul(mat4a, vec4a);
	Compare(vec4b.x, (118.0f));
	Compare(vec4b.y, (132.0f));
	Compare(vec4b.z, (146.0f));
	Compare(vec4b.w, (160.0f));

	std::cout << "vec4 mul(const vec4& v, const mat4& m)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	vec4a = vec4((2.0f), (3.0f), (4.0f), (5.0f));
	vec4b = mul(vec4a, mat4a);
	Compare(vec4b.x, (40.0f));
	Compare(vec4b.y, (96.0f));
	Compare(vec4b.z, (152.0f));
	Compare(vec4b.w, (208.0f));

	std::cout << "mat4 mul(const mat4& _m1, const mat4& _mat2)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = mat4((17.0f), (18.0f), (19.0f), (20.0f),
		(21.0f), (22.0f), (23.0f), (24.0f),
		(25.0f), (26.0f), (27.0f), (28.0f),
		(29.0f), (30.0f), (31.0f), (32.0f));
	mat4c = mul(mat4a, mat4b);
	Compare(mat4c[0][0], (538.0f));
	Compare(mat4c[0][1], (612.0f));
	Compare(mat4c[0][2], (686.0f));
	Compare(mat4c[0][3], (760.0f));
	Compare(mat4c[1][0], (650.0f));
	Compare(mat4c[1][1], (740.0f));
	Compare(mat4c[1][2], (830.0f));
	Compare(mat4c[1][3], (920.0f));
	Compare(mat4c[2][0], (762.0f));
	Compare(mat4c[2][1], (868.0f));
	Compare(mat4c[2][2], (974.0f));
	Compare(mat4c[2][3], (1080.0f));
	Compare(mat4c[3][0], (874.0f));
	Compare(mat4c[3][1], (996.0f));
	Compare(mat4c[3][2], (1118.0f));
	Compare(mat4c[3][3], (1240.0f));

	std::cout << "vec4 operator*(const mat4& m, const vec4& v)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	vec4a = vec4((2.0f), (3.0f), (4.0f), (5.0f));
	vec4b = mat4a* vec4a;
	Compare(vec4b.x, (118.0f));
	Compare(vec4b.y, (132.0f));
	Compare(vec4b.z, (146.0f));
	Compare(vec4b.w, (160.0f));

	std::cout << "vec4 operator*(const vec4& v, const mat4& m)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	vec4a = vec4((2.0f), (3.0f), (4.0f), (5.0f));
	vec4b = vec4a * mat4a;
	Compare(vec4b.x, (40.0f));
	Compare(vec4b.y, (96.0f));
	Compare(vec4b.z, (152.0f));
	Compare(vec4b.w, (208.0f));

	std::cout << "mat2 operator+(const mat2& a, const mat2& b)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	mat2b = mat2((5.0f), (6.0f), (7.0f), (8.0f));
	mat2c = mat2a + mat2b;
	Compare(mat2c[0][0], (6.0f));
	Compare(mat2c[0][1], (8.0f));
	Compare(mat2c[1][0], (10.0f));
	Compare(mat2c[1][1], (12.0f));

	std::cout << "mat2 operator-(const mat2& a, const mat2& b)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	mat2b = mat2((5.0f), (6.0f), (7.0f), (8.0f));
	mat2c = mat2a - mat2b;
	Compare(mat2c[0][0], (-4.0f));
	Compare(mat2c[0][1], (-4.0f));
	Compare(mat2c[1][0], (-4.0f));
	Compare(mat2c[1][1], (-4.0f));

	std::cout << "mat2 operator*(const mat2& a, const mat2& b)" << std::endl;
	mat2b = mat2((1.0f), (0.0f), (2.0f), (-1.0f));
	mat2a = mat2((3.0f), (4.0f), (-2.0f), (-3.0f));
	mat2c = mat2a * mat2b;
	Compare(mat2c[0][0], (3.0f));
	Compare(mat2c[0][1], (4.0f));
	Compare(mat2c[1][0], (8.0f));
	Compare(mat2c[1][1], (11.0f));

	std::cout << "mat2 operator+=(mat2& a, const mat2& b)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	mat2b = mat2((5.0f), (6.0f), (7.0f), (8.0f));
	mat2a += mat2b;
	Compare(mat2a[0][0], (6.0f));
	Compare(mat2a[0][1], (8.0f));
	Compare(mat2a[1][0], (10.0f));
	Compare(mat2a[1][1], (12.0f));

	std::cout << "mat2 operator-=(mat2& a, const mat2& b)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	mat2b = mat2((5.0f), (6.0f), (7.0f), (8.0f));
	mat2a -= mat2b;
	Compare(mat2a[0][0], (-4.0f));
	Compare(mat2a[0][1], (-4.0f));
	Compare(mat2a[1][0], (-4.0f));
	Compare(mat2a[1][1], (-4.0f));

	std::cout << "mat2 operator*=(mat2& a, const mat2& b)" << std::endl;
	mat2b = mat2((1.0f), (0.0f), (2.0f), (-1.0f));
	mat2a = mat2((3.0f), (4.0f), (-2.0f), (-3.0f));
	mat2a *= mat2b;
	Compare(mat2c[0][0], (3.0f));
	Compare(mat2c[0][1], (4.0f));
	Compare(mat2c[1][0], (8.0f));
	Compare(mat2c[1][1], (11.0f));

	std::cout << "mat2 operator*(const mat2& m, const simdfloat& s)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	mat2b = mat2a * (2.0f);
	Compare(mat2b[0][0], (2.0f));
	Compare(mat2b[0][1], (4.0f));
	Compare(mat2b[1][0], (6.0f));
	Compare(mat2b[1][1], (8.0f));

	std::cout << "mat2 operator*(const simdfloat& s, const mat2& m)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	mat2b = (2.0f) * mat2a;
	Compare(mat2b[0][0], (2.0f));
	Compare(mat2b[0][1], (4.0f));
	Compare(mat2b[1][0], (6.0f));
	Compare(mat2b[1][1], (8.0f));

	std::cout << "vec2 operator*(const vec2& v, const mat2& m)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	vec2a = vec2((5.0f), (6.0f));
	vec2b = vec2a * mat2a;
	Compare(vec2b.x, (17.0f));
	Compare(vec2b.y, (39.0f));

	std::cout << "vec2 operator*(const mat2& m, const vec2& v)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	vec2a = vec2((5.0f), (6.0f));
	vec2b = mat2a * vec2a;
	Compare(vec2b.x, (23.0f));
	Compare(vec2b.y, (34.0f));

	std::cout << "vec2 operator*=(vec2& v, const mat2& m)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	vec2a = vec2((5.0f), (6.0f));
	vec2a *= mat2a;
	Compare(vec2a.x, (17.0f));
	Compare(vec2a.y, (39.0f));

	std::cout << "mat3 operator+(const mat3& a, const mat3& b)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = mat3((10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f),
		(16.0f), (17.0f), (18.0f));
	mat3c = mat3a + mat3b;
	Compare(mat3c[0][0], (11.0f));
	Compare(mat3c[0][1], (13.0f));
	Compare(mat3c[0][2], (15.0f));
	Compare(mat3c[1][0], (17.0f));
	Compare(mat3c[1][1], (19.0f));
	Compare(mat3c[1][2], (21.0f));
	Compare(mat3c[2][0], (23.0f));
	Compare(mat3c[2][1], (25.0f));
	Compare(mat3c[2][2], (27.0f));

	std::cout << "mat3 operator-(const mat3& a, const mat3& b)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = mat3((10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f),
		(16.0f), (17.0f), (18.0f));
	mat3c = mat3a - mat3b;
	Compare(mat3c[0][0], (-9.0f));
	Compare(mat3c[0][1], (-9.0f));
	Compare(mat3c[0][2], (-9.0f));
	Compare(mat3c[1][0], (-9.0f));
	Compare(mat3c[1][1], (-9.0f));
	Compare(mat3c[1][2], (-9.0f));
	Compare(mat3c[2][0], (-9.0f));
	Compare(mat3c[2][1], (-9.0f));
	Compare(mat3c[2][2], (-9.0f));

	std::cout << "mat3 operator*(const mat3& a, const mat3& b)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = mat3((11.0f), (12.0f), (13.0f),
		(14.0f), (15.0f), (16.0f),
		(17.0f), (18.0f), (19.0f));
	mat3c = mat3a * mat3b;
	Compare(mat3c[0][0], (150.0f));
	Compare(mat3c[0][1], (186.0f));
	Compare(mat3c[0][2], (222.0f));
	Compare(mat3c[1][0], (186.0f));
	Compare(mat3c[1][1], (231.0f));
	Compare(mat3c[1][2], (276.0f));
	Compare(mat3c[2][0], (222.0f));
	Compare(mat3c[2][1], (276.0f));
	Compare(mat3c[2][2], (330.0f));

	std::cout << "mat3 operator+=(mat3& a, const mat3& b)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = mat3((10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f),
		(16.0f), (17.0f), (18.0f));
	mat3a += mat3b;
	Compare(mat3a[0][0], (11.0f));
	Compare(mat3a[0][1], (13.0f));
	Compare(mat3a[0][2], (15.0f));
	Compare(mat3a[1][0], (17.0f));
	Compare(mat3a[1][1], (19.0f));
	Compare(mat3a[1][2], (21.0f));
	Compare(mat3a[2][0], (23.0f));
	Compare(mat3a[2][1], (25.0f));
	Compare(mat3a[2][2], (27.0f));

	std::cout << "mat3 operator-=(mat3& a, const mat3& b)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = mat3((10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f),
		(16.0f), (17.0f), (18.0f));
	mat3a -= mat3b;
	Compare(mat3a[0][0], (-9.0f));
	Compare(mat3a[0][1], (-9.0f));
	Compare(mat3a[0][2], (-9.0f));
	Compare(mat3a[1][0], (-9.0f));
	Compare(mat3a[1][1], (-9.0f));
	Compare(mat3a[1][2], (-9.0f));
	Compare(mat3a[2][0], (-9.0f));
	Compare(mat3a[2][1], (-9.0f));
	Compare(mat3a[2][2], (-9.0f));

	std::cout << "mat3 operator*=(mat3& a, const mat3& b)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = mat3((11.0f), (12.0f), (13.0f),
		(14.0f), (15.0f), (16.0f),
		(17.0f), (18.0f), (19.0f));
	mat3a *= mat3b;
	Compare(mat3a[0][0], (150.0f));
	Compare(mat3a[0][1], (186.0f));
	Compare(mat3a[0][2], (222.0f));
	Compare(mat3a[1][0], (186.0f));
	Compare(mat3a[1][1], (231.0f));
	Compare(mat3a[1][2], (276.0f));
	Compare(mat3a[2][0], (222.0f));
	Compare(mat3a[2][1], (276.0f));
	Compare(mat3a[2][2], (330.0f));

	std::cout << "mat3 operator*(const mat3& m, const simdfloat& s)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = mat3a * (2.0f);
	Compare(mat3b[0][0], (2.0f));
	Compare(mat3b[0][1], (4.0f));
	Compare(mat3b[0][2], (6.0f));
	Compare(mat3b[1][0], (8.0f));
	Compare(mat3b[1][1], (10.0f));
	Compare(mat3b[1][2], (12.0f));
	Compare(mat3b[2][0], (14.0f));
	Compare(mat3b[2][1], (16.0f));
	Compare(mat3b[2][2], (18.0f));

	std::cout << "mat3 operator*(const simdfloat& s, const mat3& m)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = (2.0f) * mat3a;
	Compare(mat3b[0][0], (2.0f));
	Compare(mat3b[0][1], (4.0f));
	Compare(mat3b[0][2], (6.0f));
	Compare(mat3b[1][0], (8.0f));
	Compare(mat3b[1][1], (10.0f));
	Compare(mat3b[1][2], (12.0f));
	Compare(mat3b[2][0], (14.0f));
	Compare(mat3b[2][1], (16.0f));
	Compare(mat3b[2][2], (18.0f));

	std::cout << "vec3 operator*(const vec3& v, const mat3& m)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	vec3a = vec3((2.0f), (3.0f), (4.0f));
	vec3b = vec3a * mat3a;
	Compare(vec3b.x, (20.0f));
	Compare(vec3b.y, (47.0f));
	Compare(vec3b.z, (74.0f));

	std::cout << "vec3 operator*(const mat3& m, const vec3& v)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	vec3a = vec3((2.0f), (3.0f), (4.0f));
	vec3b = mat3a * vec3a;
	Compare(vec3b.x, (42.0f));
	Compare(vec3b.y, (51.0f));
	Compare(vec3b.z, (60.0f));

	std::cout << "vec3 operator*=(vec3& v, const mat3& m)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	vec3a = vec3((2.0f), (3.0f), (4.0f));
	vec3a *= mat3a;
	Compare(vec3a.x, (20.0f));
	Compare(vec3a.y, (47.0f));
	Compare(vec3a.z, (74.0f));

	std::cout << "mat4 operator+(const mat4& a, const mat4& b)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = mat4((17.0f), (18.0f), (19.0f), (20.0f),
		(21.0f), (22.0f), (23.0f), (24.0f),
		(25.0f), (26.0f), (27.0f), (28.0f),
		(29.0f), (30.0f), (31.0f), (32.0f));
	mat4c = mat4a + mat4b;
	Compare(mat4c[0][0], (18.0f));
	Compare(mat4c[0][1], (20.0f));
	Compare(mat4c[0][2], (22.0f));
	Compare(mat4c[0][3], (24.0f));
	Compare(mat4c[1][0], (26.0f));
	Compare(mat4c[1][1], (28.0f));
	Compare(mat4c[1][2], (30.0f));
	Compare(mat4c[1][3], (32.0f));
	Compare(mat4c[2][0], (34.0f));
	Compare(mat4c[2][1], (36.0f));
	Compare(mat4c[2][2], (38.0f));
	Compare(mat4c[2][3], (40.0f));
	Compare(mat4c[3][0], (42.0f));
	Compare(mat4c[3][1], (44.0f));
	Compare(mat4c[3][2], (46.0f));
	Compare(mat4c[3][3], (48.0f));

	std::cout << "mat4 operator-(const mat4& a, const mat4& b)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = mat4((17.0f), (18.0f), (19.0f), (20.0f),
		(21.0f), (22.0f), (23.0f), (24.0f),
		(25.0f), (26.0f), (27.0f), (28.0f),
		(29.0f), (30.0f), (31.0f), (32.0f));
	mat4c = mat4a - mat4b;
	Compare(mat4c[0][0], (-16.0f));
	Compare(mat4c[0][1], (-16.0f));
	Compare(mat4c[0][2], (-16.0f));
	Compare(mat4c[0][3], (-16.0f));
	Compare(mat4c[1][0], (-16.0f));
	Compare(mat4c[1][1], (-16.0f));
	Compare(mat4c[1][2], (-16.0f));
	Compare(mat4c[1][3], (-16.0f));
	Compare(mat4c[2][0], (-16.0f));
	Compare(mat4c[2][1], (-16.0f));
	Compare(mat4c[2][2], (-16.0f));
	Compare(mat4c[2][3], (-16.0f));
	Compare(mat4c[3][0], (-16.0f));
	Compare(mat4c[3][1], (-16.0f));
	Compare(mat4c[3][2], (-16.0f));
	Compare(mat4c[3][3], (-16.0f));

	std::cout << "mat4 operator*(const mat4& a, const mat4& b)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = mat4((17.0f), (18.0f), (19.0f), (20.0f),
		(21.0f), (22.0f), (23.0f), (24.0f),
		(25.0f), (26.0f), (27.0f), (28.0f),
		(29.0f), (30.0f), (31.0f), (32.0f));
	mat4c = mat4a * mat4b;
	Compare(mat4c[0][0], (538.0f));
	Compare(mat4c[0][1], (612.0f));
	Compare(mat4c[0][2], (686.0f));
	Compare(mat4c[0][3], (760.0f));
	Compare(mat4c[1][0], (650.0f));
	Compare(mat4c[1][1], (740.0f));
	Compare(mat4c[1][2], (830.0f));
	Compare(mat4c[1][3], (920.0f));
	Compare(mat4c[2][0], (762.0f));
	Compare(mat4c[2][1], (868.0f));
	Compare(mat4c[2][2], (974.0f));
	Compare(mat4c[2][3], (1080.0f));
	Compare(mat4c[3][0], (874.0f));
	Compare(mat4c[3][1], (996.0f));
	Compare(mat4c[3][2], (1118.0f));
	Compare(mat4c[3][3], (1240.0f));

	std::cout << "mat4 operator+=(mat4& a, const mat4& b)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = mat4((17.0f), (18.0f), (19.0f), (20.0f),
		(21.0f), (22.0f), (23.0f), (24.0f),
		(25.0f), (26.0f), (27.0f), (28.0f),
		(29.0f), (30.0f), (31.0f), (32.0f));
	mat4a += mat4b;
	Compare(mat4a[0][0], (18.0f));
	Compare(mat4a[0][1], (20.0f));
	Compare(mat4a[0][2], (22.0f));
	Compare(mat4a[0][3], (24.0f));
	Compare(mat4a[1][0], (26.0f));
	Compare(mat4a[1][1], (28.0f));
	Compare(mat4a[1][2], (30.0f));
	Compare(mat4a[1][3], (32.0f));
	Compare(mat4a[2][0], (34.0f));
	Compare(mat4a[2][1], (36.0f));
	Compare(mat4a[2][2], (38.0f));
	Compare(mat4a[2][3], (40.0f));
	Compare(mat4a[3][0], (42.0f));
	Compare(mat4a[3][1], (44.0f));
	Compare(mat4a[3][2], (46.0f));
	Compare(mat4a[3][3], (48.0f));

	std::cout << "mat4 operator-=(mat4& a, const mat4& b)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = mat4((17.0f), (18.0f), (19.0f), (20.0f),
		(21.0f), (22.0f), (23.0f), (24.0f),
		(25.0f), (26.0f), (27.0f), (28.0f),
		(29.0f), (30.0f), (31.0f), (32.0f));
	mat4a -= mat4b;
	Compare(mat4a[0][0], (-16.0f));
	Compare(mat4a[0][1], (-16.0f));
	Compare(mat4a[0][2], (-16.0f));
	Compare(mat4a[0][3], (-16.0f));
	Compare(mat4a[1][0], (-16.0f));
	Compare(mat4a[1][1], (-16.0f));
	Compare(mat4a[1][2], (-16.0f));
	Compare(mat4a[1][3], (-16.0f));
	Compare(mat4a[2][0], (-16.0f));
	Compare(mat4a[2][1], (-16.0f));
	Compare(mat4a[2][2], (-16.0f));
	Compare(mat4a[2][3], (-16.0f));
	Compare(mat4a[3][0], (-16.0f));
	Compare(mat4a[3][1], (-16.0f));
	Compare(mat4a[3][2], (-16.0f));
	Compare(mat4a[3][3], (-16.0f));

	std::cout << "mat4 operator*=(mat4& a, const mat4& b)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = mat4((17.0f), (18.0f), (19.0f), (20.0f),
		(21.0f), (22.0f), (23.0f), (24.0f),
		(25.0f), (26.0f), (27.0f), (28.0f),
		(29.0f), (30.0f), (31.0f), (32.0f));
	mat4a *= mat4b;
	Compare(mat4a[0][0], (538.0f));
	Compare(mat4a[0][1], (612.0f));
	Compare(mat4a[0][2], (686.0f));
	Compare(mat4a[0][3], (760.0f));
	Compare(mat4a[1][0], (650.0f));
	Compare(mat4a[1][1], (740.0f));
	Compare(mat4a[1][2], (830.0f));
	Compare(mat4a[1][3], (920.0f));
	Compare(mat4a[2][0], (762.0f));
	Compare(mat4a[2][1], (868.0f));
	Compare(mat4a[2][2], (974.0f));
	Compare(mat4a[2][3], (1080.0f));
	Compare(mat4a[3][0], (874.0f));
	Compare(mat4a[3][1], (996.0f));
	Compare(mat4a[3][2], (1118.0f));
	Compare(mat4a[3][3], (1240.0f));

	std::cout << "mat4 operator*(const mat4& m, const simdfloat& s)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = mat4a * (2.0f);
	Compare(mat4b[0][0], (2.0f));
	Compare(mat4b[0][1], (4.0f));
	Compare(mat4b[0][2], (6.0f));
	Compare(mat4b[0][3], (8.0f));
	Compare(mat4b[1][0], (10.0f));
	Compare(mat4b[1][1], (12.0f));
	Compare(mat4b[1][2], (14.0f));
	Compare(mat4b[1][3], (16.0f));
	Compare(mat4b[2][0], (18.0f));
	Compare(mat4b[2][1], (20.0f));
	Compare(mat4b[2][2], (22.0f));
	Compare(mat4b[2][3], (24.0f));
	Compare(mat4b[3][0], (26.0f));
	Compare(mat4b[3][1], (28.0f));
	Compare(mat4b[3][2], (30.0f));
	Compare(mat4b[3][3], (32.0f));

	std::cout << "mat4 operator*(const simdfloat& s, const mat4& m)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = (2.0f) * mat4a;
	Compare(mat4b[0][0], (2.0f));
	Compare(mat4b[0][1], (4.0f));
	Compare(mat4b[0][2], (6.0f));
	Compare(mat4b[0][3], (8.0f));
	Compare(mat4b[1][0], (10.0f));
	Compare(mat4b[1][1], (12.0f));
	Compare(mat4b[1][2], (14.0f));
	Compare(mat4b[1][3], (16.0f));
	Compare(mat4b[2][0], (18.0f));
	Compare(mat4b[2][1], (20.0f));
	Compare(mat4b[2][2], (22.0f));
	Compare(mat4b[2][3], (24.0f));
	Compare(mat4b[3][0], (26.0f));
	Compare(mat4b[3][1], (28.0f));
	Compare(mat4b[3][2], (30.0f));
	Compare(mat4b[3][3], (32.0f));

	std::cout << "vec4 operator*(const vec4& v, const mat4& m)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	vec4a = vec4((2.0f), (3.0f), (4.0f), (5.0f));
	vec4b = vec4a * mat4a;
	Compare(vec4b.x, (40.0f));
	Compare(vec4b.y, (96.0f));
	Compare(vec4b.z, (152.0f));
	Compare(vec4b.w, (208.0f));

	std::cout << "vec4 operator*(const mat4& m, const vec4& v)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	vec4a = vec4((2.0f), (3.0f), (4.0f), (5.0f));
	vec4b = mat4a * vec4a;
	Compare(vec4b.x, (118.0f));
	Compare(vec4b.y, (132.0f));
	Compare(vec4b.z, (146.0f));
	Compare(vec4b.w, (160.0f));

	std::cout << "vec4 operator*=(vec4& v, const mat4& m)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	vec4a = vec4((2.0f), (3.0f), (4.0f), (5.0f));
	vec4a *= mat4a;
	Compare(vec4a.x, (40.0f));
	Compare(vec4a.y, (96.0f));
	Compare(vec4a.z, (152.0f));
	Compare(vec4a.w, (208.0f));

	std::cout << "simdfloat determinant(const mat2& _m)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	// det = 1*4 - 2*3 = 4 - 6 = -2
	veca = determinant(mat2a);
	Compare(veca, (-2.0f));

	std::cout << "simdfloat determinant(const mat3& _m)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	// det = 1*(5*9 - 6*8) - 4*(2*9 - 3*8) + 7*(2*6 - 3*5) = 1*(-3) - 4*(-6) + 7*(-3) = -3 + 24 - 21 = 0
	veca = determinant(mat3a);
	Compare(veca, (0.0f));

	std::cout << "simdfloat determinant(const mat4& _m)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	veca = determinant(mat4a);
	Compare(veca, (0.0f));

	std::cout << "mat2 inverse(const mat2& _m)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	mat2b = inverse(mat2a);
	Compare(mat2b[0][0], (-2.0f));
	Compare(mat2b[0][1], (1.0f));
	Compare(mat2b[1][0], (1.5f));
	Compare(mat2b[1][1], (-0.5f));

	std::cout << "mat3 inverse(const mat3& _m)" << std::endl;


	std::cout << "mat4 inverse(const mat4& _m)" << std::endl;


	std::cout << "mat2 transpose(const mat2& _m)" << std::endl;
	mat2a = mat2((1.0f), (2.0f), (3.0f), (4.0f));
	mat2b = transpose(mat2a);
	Compare(mat2b[0][0], (1.0f));
	Compare(mat2b[0][1], (3.0f));
	Compare(mat2b[1][0], (2.0f));
	Compare(mat2b[1][1], (4.0f));

	std::cout << "mat3 transpose(const mat3& _m)" << std::endl;
	mat3a = mat3((1.0f), (2.0f), (3.0f),
		(4.0f), (5.0f), (6.0f),
		(7.0f), (8.0f), (9.0f));
	mat3b = transpose(mat3a);
	Compare(mat3b[0][0], (1.0f));
	Compare(mat3b[0][1], (4.0f));
	Compare(mat3b[0][2], (7.0f));
	Compare(mat3b[1][0], (2.0f));
	Compare(mat3b[1][1], (5.0f));
	Compare(mat3b[1][2], (8.0f));
	Compare(mat3b[2][0], (3.0f));
	Compare(mat3b[2][1], (6.0f));
	Compare(mat3b[2][2], (9.0f));

	std::cout << "mat4 transpose(const mat4& _m)" << std::endl;
	mat4a = mat4((1.0f), (2.0f), (3.0f), (4.0f),
		(5.0f), (6.0f), (7.0f), (8.0f),
		(9.0f), (10.0f), (11.0f), (12.0f),
		(13.0f), (14.0f), (15.0f), (16.0f));
	mat4b = transpose(mat4a);
	Compare(mat4b[0][0], (1.0f));
	Compare(mat4b[0][1], (5.0f));
	Compare(mat4b[0][2], (9.0f));
	Compare(mat4b[0][3], (13.0f));
	Compare(mat4b[1][0], (2.0f));
	Compare(mat4b[1][1], (6.0f));
	Compare(mat4b[1][2], (10.0f));
	Compare(mat4b[1][3], (14.0f));
	Compare(mat4b[2][0], (3.0f));
	Compare(mat4b[2][1], (7.0f));
	Compare(mat4b[2][2], (11.0f));
	Compare(mat4b[2][3], (15.0f));
	Compare(mat4b[3][0], (4.0f));
	Compare(mat4b[3][1], (8.0f));
	Compare(mat4b[3][2], (12.0f));
	Compare(mat4b[3][3], (16.0f));

	std::cout << "operator>(const simdfloat&, const simdfloat&)" << std::endl;
	veca = (1.0f);
	vecb = (2.0f);
	maskResult = veca > vecb;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator>(const simdfloat&, const float&)" << std::endl;
	veca = (1.0f);
	maskResult = veca > 2.0f;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator>(const float&, const simdfloat&)" << std::endl;
	veca = (3.0f);
	maskResult = 2.0f > veca;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator<(const simdfloat&, const simdfloat&)" << std::endl;
	veca = (3.0f);
	vecb = (2.0f);
	maskResult = veca < vecb;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator<(const simdfloat&, const float&)" << std::endl;
	veca = (3.0f);
	maskResult = veca < 2.0f;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator<(const float&, const simdfloat&)" << std::endl;
	veca = (1.0f);
	maskResult = 2.0f < veca;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator>=(const simdfloat&, const simdfloat&)" << std::endl;
	veca = (1.0f);
	vecb = (2.0f);
	maskResult = veca >= vecb;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator>=(const simdfloat&, const float&)" << std::endl;
	veca = (1.0f);
	maskResult = veca >= 2.0f;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator<=(const simdfloat&, const simdfloat&)" << std::endl;
	veca = (3.0f);
	vecb = (2.0f);
	maskResult = veca <= vecb;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator<=(const simdfloat&, const float&)" << std::endl;
	veca = (3.0f);
	maskResult = veca <= 2.0f;
	CompareMask(maskResult, (0.0f));

	std::cout << "operator==(const simdfloat&, const simdfloat&)" << std::endl;
	Compare((1.0f) == (2.0f), (0.0f));

	std::cout << "operator==(const simdfloat&, const float&)" << std::endl;
	Compare((1.0f) == 2.0f, (0.0f));

	std::cout << "operator&&(const simdmask&, const simdmask&)" << std::endl;
	CompareMask((-1.0f) < (0.0f) && (-1.0f) < (-2.0f), (0.0f));

	std::cout << "operator||(const simdmask&, const simdmask&)" << std::endl;
	CompareMask((-1.0f) > (0.0f) || (-1.0f) < (-2.0f), (0.0f));

	std::cout << "int maskAll(const simdmask & _mask)" << std::endl;
#if defined(USE_AVX512)
	maskResult = 0xFFFF;
#elif defined (USE_SCALAR)
	maskResult = 1;
#else
	maskResult = (-1.0f);
#endif
	if (maskAll(maskResult) != 1) {
		std::cout << "maskAll failed" << std::endl;
		exit(0);
	}
#if defined(USE_AVX512)
	maskResult = 0;
#elif defined (USE_SCALAR)
	maskResult = 0;
#else
	maskResult = (0.0f);
#endif
	if (maskAll(maskResult) != 0) {
		std::cout << "maskAll failed" << std::endl;
		exit(0);
	}
#ifndef USE_SCALAR
#if !(defined(USE_AVX512))
	maskResult = simd_load_float(tabMask);
#else
	maskResult = testmask;
#endif
	if (maskAll(maskResult) != 0) {
		std::cout << "maskAll failed" << std::endl;
		exit(0);
	}
#endif // USE_SCALAR

	std::cout << "int maskNone(const simdmask & _mask)" << std::endl;
#if defined(USE_AVX512)
	maskResult = 0xFFFF;
#elif defined (USE_SCALAR)
	maskResult = 1;
#else
	maskResult = (-1.0f);
#endif
	if (maskNone(maskResult) != 0) {
		std::cout << "maskNone failed" << std::endl;
		exit(0);
	}
#if defined(USE_AVX512)
	maskResult = 0;
#elif defined (USE_SCALAR)
	maskResult = 0;
#else
	maskResult = (0.0f);
#endif
	if (maskNone(maskResult) != 1) {
		std::cout << "maskNone failed" << std::endl;
		exit(0);
	}
#ifndef USE_SCALAR
#if !(defined(USE_AVX512))
	maskResult = simd_load_float(tabMask);
#else
	maskResult = testmask;
#endif
	if (maskNone(maskResult) != 0) {
		std::cout << "maskNone failed" << std::endl;
		exit(0);
	}
#endif

#pragma endregion float tests

#endif // COMPILE_TESTS
}

inline void TestsDouble()
{

#ifdef COMPILE_TESTS

#pragma region double tests

	alignas(64) const double tabdVal[16] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 8.0, 7.0, 6.0,	5.0, 4.0, 3.0, 2.0};
alignas(64) const double tabdValNeg[16] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, -8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0 };
alignas(64) const double tabSmalldVal[16] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, -0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7, -0.8 };
alignas(64) const double tabRandomdVal[16] = { 0.123, 0.456, 0.789, 1.234, 2.345, 3.456, 4.567, 5.678, -0.123, -0.456, -0.789, -1.234, -2.345, -3.456, -4.567, -5.678 };
alignas(64) const double tabdValAcosh[16] = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 2.0, 2.2, 2.4, 2.6, 2.8, 3.0, 3.5, 4.0 };
alignas(64) const double tabdValMin[16] = { 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0 };
alignas(64) const double tabdValMax[16] = { 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0 };


alignas(64) const double tabdMask[16] = { 0.0, -1.0, 0.0, -1.0, 0.0, -1.0, 0.0, -1.0, 0.0, -1.0, 0.0, -1.0, 0.0, -1.0, 0.0, -1.0 };
#if defined(USE_AVX512)
alignas(64) const __mmask16 testdmask = 0b0101010101010101;
#elif defined(USE_SCALAR)
const int testdmask = 1;
#else
simddmask testdmask = simd_load_double(tabdMask);
#endif

alignas(64) double tabdValResult[16] = { 0 };

simddouble dveca, dvecb, dvecc;
dvec2 dvec2a, dvec2b, dvec2c;
dvec3 dvec3a, dvec3b, dvec3c;
dvec4 dvec4a, dvec4b, dvec4c;

dmat2 dmat2a, dmat2b, dmat2c;
dmat3 dmat3a, dmat3b, dmat3c;
dmat4 dmat4a, dmat4b, dmat4c;

simddmask dmaskResult;

double lengthResultDouble[16];


	std::cout << "simddouble operator-(const simddouble& a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return -val; });
	CompareDouble(-dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble& operator++(simddouble& a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = ++dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1; });
	CompareDouble(dveca, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble& operator--(simddouble& a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = --dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1; });
	CompareDouble(dveca, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble operator++(simddouble& a, int)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = dveca++;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1; });
	CompareDouble(dveca, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble operator--(simddouble& a, int)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = dveca--;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1; });
	CompareDouble(dveca, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble operator+(const simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = dveca + dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble operator-(const simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = dveca - dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble operator*(const simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = dveca * dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble operator/(const simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = dveca / dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble operator+=(simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca += dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dveca, simd_load_double(tabdValResult));


	std::cout << "simddouble operator-=(simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca -= dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator*=(simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca *= dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator/=(simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca /= dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator+(const simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca = dveca + 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1.0; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator-(const simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca = dveca - 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1.0; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator*(const simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca = dveca * 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 2.0; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator/(const simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca = dveca / 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / 2.0; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator+=(simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca += 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1.0; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator-=(simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca -= 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1.0; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator*=(simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca *= 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 2.0; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator/=(simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca /= 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / 2.0; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator+(const double& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca = 1.0 + dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 + val; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator-(const double& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca = 1.0 - dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 - val; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator*(const double& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca = 2.0 * dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 2.0 * val; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble operator/(const double& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dveca = 2.0 / dveca;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 2.0 / val; });
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator-(const dvec2& a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = -dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return -val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2a.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator+(const dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a + dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2a.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator-(const dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a - dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2a.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator*(const dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a * dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2a.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator/(const dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a / dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2a.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator+(const double& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = 1.0 + dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 + val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator-(const double& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = 1.0 - dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 - val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator*(const double& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = 2.0 * dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 2.0 * val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator/(const double& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = 2.0 / dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 2.0 / val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator+=(dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a += 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1.0; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator-=(dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a -= 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1.0; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator*=(dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a *= 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 2.0; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator/=(dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a /= 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / 2.0; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator+(const dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a + simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator-(const dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a - simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator*(const dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a * simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator/(const dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a / simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator+(const simddouble& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = simd_load_double(tabdVal) + dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator-(const simddouble& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = simd_load_double(tabdVal) - dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator*(const simddouble& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = simd_load_double(tabdVal) * dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator/(const simddouble& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = simd_load_double(tabdVal) / dvec2a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator+=(dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a += simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator-=(dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a -= simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator*=(dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a *= simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator/=(dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a /= simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator+(const dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a + dvec2b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator-(const dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a - dvec2b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator*(const dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a * dvec2b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator/(const dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a = dvec2a / dvec2b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator+=(dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a += dvec2b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator-=(dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a -= dvec2b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator*=(dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a *= dvec2b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 operator/=(dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2a /= dvec2b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec2a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator-(const dvec3& a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = -dvec3a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return -val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator+(const dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a + 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1.0; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator-(const dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a - 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1.0; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator*(const dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a * 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 2.0; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator/(const dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a / 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / 2.0; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator+(const double& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = 1.0 + dvec3a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 + val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator-(const double& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = 1.0 - dvec3a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 - val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator*(const double& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = 2.0 * dvec3a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 2.0 * val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator/(const double& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = 2.0 / dvec3a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 2.0 / val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator+=(dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a += 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1.0; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator-=(dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a -= 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1.0; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator*=(dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a *= 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 2.0; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator/=(dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a /= 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / 2.0; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator+(const dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a + simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator-(const dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a - simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator*(const dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a * simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator/(const dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a / simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator+(const simddouble& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = simd_load_double(tabdVal) + dvec3a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator-(const simddouble& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = simd_load_double(tabdVal) - dvec3a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator*(const simddouble& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = simd_load_double(tabdVal) * dvec3a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator/(const simddouble& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = simd_load_double(tabdVal) / dvec3a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator+=(dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a += simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator-=(dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a -= simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator*=(dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a *= simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator/=(dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a /= simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator+(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a + dvec3b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator-(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a - dvec3b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator*(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a * dvec3b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator/(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a = dvec3a / dvec3b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator+=(dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a += dvec3b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator-=(dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a -= dvec3b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator*=(dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a *= dvec3b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 operator/=(dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3a /= dvec3b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec3a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator-(const dvec4& a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = -dvec4a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return -val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator+(const dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a + 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1.0; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator-(const dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a - 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1.0; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator*(const dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a * 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 2.0; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator/(const dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a / 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / 2.0; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator+(const double& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = 1.0 + dvec4a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 + val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator-(const double& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = 1.0 - dvec4a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 - val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator*(const double& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = 2.0 * dvec4a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 2.0 * val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator/(const double& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = 2.0 / dvec4a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 2.0 / val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator+=(dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a += 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 1.0; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator-=(dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a -= 1.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - 1.0; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator*=(dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a *= 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 2.0; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator/=(dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a /= 2.0;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / 2.0; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator+(const dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a + simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator-(const dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a - simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator*(const dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a * simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator/(const dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a / simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator+(const simddouble& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = simd_load_double(tabdVal) + dvec4a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator-(const simddouble& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = simd_load_double(tabdVal) - dvec4a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator*(const simddouble& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = simd_load_double(tabdVal) * dvec4a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator/(const simddouble& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = simd_load_double(tabdVal) / dvec4a;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator+=(dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a += simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator-=(dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a -= simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator*=(dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a *= simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator/=(dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a /= simd_load_double(tabdVal);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator+(const dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a + dvec4b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator-(const dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a - dvec4b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator*(const dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a * dvec4b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator/(const dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a = dvec4a / dvec4b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator+=(dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a += dvec4b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator-=(dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a -= dvec4b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator*=(dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a *= dvec4b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 operator/=(dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4a /= dvec4b;
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val / val; });
	CompareDouble(dvec4a.x, simd_load_double(tabdValResult));

	// Tests for abs
	std::cout << "simddouble abs(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = abs(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::abs(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 abs(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = abs(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::abs(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 abs(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = abs(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::abs(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 abs(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = abs(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::abs(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for acos
	std::cout << "simddouble acos(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabSmalldVal);
	dvecb = acos(dveca);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::acos(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 acos(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec2b = acos(dvec2a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::acos(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 acos(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec3b = acos(dvec3a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::acos(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 acos(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec4b = acos(dvec4a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::acos(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for acosh

	std::cout << "simddouble acosh(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdValAcosh);
	dvecb = acosh(dveca);
	FillTabResultDouble(tabdValAcosh, tabdValResult, [](const double& val, const int& idx) { return std::acosh(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 acosh(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh));
	dvec2b = acosh(dvec2a);
	FillTabResultDouble(tabdValAcosh, tabdValResult, [](const double& val, const int& idx) { return std::acosh(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 acosh(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh));
	dvec3b = acosh(dvec3a);
	FillTabResultDouble(tabdValAcosh, tabdValResult, [](const double& val, const int& idx) { return std::acosh(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 acosh(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh));
	dvec4b = acosh(dvec4a);
	FillTabResultDouble(tabdValAcosh, tabdValResult, [](const double& val, const int& idx) { return std::acosh(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for asin
	std::cout << "simddouble asin(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabSmalldVal);
	dvecb = asin(dveca);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::asin(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 asin(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec2b = asin(dvec2a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::asin(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 asin(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec3b = asin(dvec3a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::asin(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 asin(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec4b = asin(dvec4a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::asin(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for asinh
	std::cout << "simddouble asinh(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = asinh(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::asinh(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 asinh(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = asinh(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::asinh(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 asinh(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = asinh(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::asinh(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 asinh(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = asinh(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::asinh(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for atan (single parameter)
	std::cout << "simddouble atan(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = atan(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::atan(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 atan(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = atan(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::atan(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 atan(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = atan(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::atan(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 atan(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = atan(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::atan(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for atan2 (two parameters)
	std::cout << "simddouble atan(const simddouble& _a, const simddouble& _b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecc = (0.5);
	dvecb = atan(dveca, dvecc);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::atan2(val, 0.5); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble atan(const dvec2&, const dvec2&)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2((0.5), (0.5));
	dvec2c = atan(dvec2a, dvec2b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::atan2(val, 0.5); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "simddouble atan(const dvec3&, const dvec3&)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3((0.5), (0.5), (0.5));
	dvec3c = atan(dvec3a, dvec3b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::atan2(val, 0.5); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "simddouble atan(const dvec4&, const dvec4&)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4((0.5), (0.5), (0.5), (0.5));
	dvec4c = atan(dvec4a, dvec4b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::atan2(val, 0.5); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));

	// Tests for atanh
	std::cout << "simddouble atanh(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabSmalldVal);
	dvecb = atanh(dveca);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::atanh(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 atanh(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec2b = atanh(dvec2a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::atanh(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 atanh(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec3b = atanh(dvec3a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::atanh(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 atanh(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec4b = atanh(dvec4a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::atanh(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for blendv
// Tests for blendv
	std::cout << "simddouble blendv(const simddouble& a, const simddouble& b, const simddouble& testdmask)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = simd_load_double(tabdValAcosh);

	dvecc = blendv(dvecb, dveca, testdmask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabdValResult[i] = tabdMask[i] < 0.0 ? tabdVal[i] : tabdValAcosh[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabdValResult[i] = tabdMask[i] < 0.0 ? tabdValAcosh[i] : tabdVal[i];
	}
#elif defined(USE_SCALAR)
	tabdValResult[0] = tabdMask[0] == 0.0 ? tabdVal[0] : tabdValAcosh[0];
#endif
	CompareDouble(dvecc, simd_load_double(tabdValResult));

	std::cout << "dvec2 blendv(const dvec2& a, const dvec2& b, const simddouble& testdmask)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2(simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh));

	dvec2c = blendv(dvec2b, dvec2a, testdmask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabdValResult[i] = tabdMask[i] < 0.0 ? tabdVal[i] : tabdValAcosh[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabdValResult[i] = tabdMask[i] < 0.0 ? tabdValAcosh[i] : tabdVal[i];
	}
#elif defined(USE_SCALAR)
	tabdValResult[0] = tabdMask[0] == 0.0 ? tabdVal[0] : tabdValAcosh[0];
#endif
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 blendv(const dvec3& a, const dvec3& b, const simddouble& testdmask)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3(simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh));

	dvec3c = blendv(dvec3b, dvec3a, testdmask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabdValResult[i] = tabdMask[i] < 0.0 ? tabdVal[i] : tabdValAcosh[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabdValResult[i] = tabdMask[i] < 0.0 ? tabdValAcosh[i] : tabdVal[i];
	}
#elif defined(USE_SCALAR)
	tabdValResult[0] = tabdMask[0] == 0.0 ? tabdVal[0] : tabdValAcosh[0];
#endif
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 blendv(const dvec4& a, const dvec4& b, const simddouble& testdmask)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4(simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh), simd_load_double(tabdValAcosh));

	dvec4c = blendv(dvec4b, dvec4a, testdmask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabdValResult[i] = tabdMask[i] < 0.0 ? tabdVal[i] : tabdValAcosh[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabdValResult[i] = tabdMask[i] < 0.0 ? tabdValAcosh[i] : tabdVal[i];
	}
#elif defined(USE_SCALAR)
	tabdValResult[0] = tabdMask[0] == 0.0 ? tabdVal[0] : tabdValAcosh[0];
#endif
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));

	// Tests for distance
	std::cout << "simddouble distance(const simddouble&, const simddouble&)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecc = (0.5);
	dvecb = distance(dveca, dvecc);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::abs(val - 0.5); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble distance(const dvec2&, const dvec2&)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2((0.5), (0.5));
	dvec2c = distance(dvec2a, dvec2b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sqrt(std::pow(val - 0.5, 2) + std::pow(val - 0.5, 2)); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "simddouble distance(const dvec3&, const dvec3&)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3((0.5), (0.5), (0.5));
	dvec3c = distance(dvec3a, dvec3b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sqrt(std::pow(val - 0.5, 2) + std::pow(val - 0.5, 2) + std::pow(val - 0.5, 2)); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "simddouble distance(const dvec4&, const dvec4&)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4((0.5), (0.5), (0.5), (0.5));
	dvec4c = distance(dvec4a, dvec4b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sqrt(std::pow(val - 0.5, 2) + std::pow(val - 0.5, 2) + std::pow(val - 0.5, 2) + std::pow(val - 0.5, 2)); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));

	// Tests for ceil
	std::cout << "simddouble ceil(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = ceil(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::ceil(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 ceil(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = ceil(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::ceil(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 ceil(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = ceil(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::ceil(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 ceil(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = ceil(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::ceil(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for max
	std::cout << "simddouble max(const simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecc = (0.5);
	dvecb = max(dveca, dvecc);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 0.5); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble max(const simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = max(dveca, 5.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 5.0); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble max(const double& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = max(5.0, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(5.0, val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 max(const dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = max(dvec2a, (0.5));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 0.5); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 max(const simddouble& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = max((0.5), dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(0.5, val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 max(const dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = max(dvec2a, 5.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 5.0); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 max(const double& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = max(5.0, dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(5.0, val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 max(const dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2 dvec2d = dvec2((0.5), (0.5));
	dvec2b = max(dvec2a, dvec2d);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 0.5); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 max(const dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = max(dvec3a, (0.5));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 0.5); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 max(const simddouble& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = max((0.5), dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(0.5, val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 max(const dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = max(dvec3a, 5.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 5.0); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 max(const double& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = max(5.0, dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(5.0, val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 max(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3 dvec3d = dvec3((0.5), (0.5), (0.5));
	dvec3b = max(dvec3a, dvec3d);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 0.5); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 max(const dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = max(dvec4a, (0.5));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 0.5); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 max(const simddouble& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = max((0.5), dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(0.5, val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 max(const dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = max(dvec4a, 5.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 5.0); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 max(const double& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = max(5.0, dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(5.0, val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 max(const dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4 dvec4d = dvec4((0.5), (0.5), (0.5), (0.5));
	dvec4b = max(dvec4a, dvec4d);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(val, 0.5); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for min
	std::cout << "simddouble min(const simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecc = (0.5);
	dvecb = min(dveca, dvecc);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 0.5); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble min(const simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = min(dveca, 5.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 5.0); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble min(const double& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = min(5.0, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(5.0, val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 min(const dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = min(dvec2a, (0.5));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 0.5); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 min(const simddouble& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = min((0.5), dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(0.5, val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 min(const dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = min(dvec2a, 5.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 5.0); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 min(const double& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = min(5.0, dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(5.0, val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 min(const dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2d = dvec2((0.5), (0.5));
	dvec2b = min(dvec2a, dvec2d);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 0.5); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 min(const dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = min(dvec3a, (0.5));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 0.5); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 min(const simddouble& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = min((0.5), dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(0.5, val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 min(const dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = min(dvec3a, 5.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 5.0); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 min(const double& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = min(5.0, dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(5.0, val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 min(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3d = dvec3((0.5), (0.5), (0.5));
	dvec3b = min(dvec3a, dvec3d);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 0.5); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 min(const dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = min(dvec4a, (0.5));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 0.5); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 min(const simddouble& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = min((0.5), dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(0.5, val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 min(const dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = min(dvec4a, 5.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 5.0); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 min(const double& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = min(5.0, dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(5.0, val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 min(const dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4d = dvec4((0.5), (0.5), (0.5), (0.5));
	dvec4b = min(dvec4a, dvec4d);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::min(val, 0.5); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for clamp
	std::cout << "double clamp(const double& v, const double& minVal, const double& maxVal)" << std::endl;
	if (clamp(7.5, 2.0, 10.0) != 7.5) {
		std::cout << "Clamp failed for double" << std::endl;
		exit(0);
	}

	std::cout << "simddouble clamp(const simddouble& v, const simddouble& minVal, const simddouble& maxVal)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = clamp(dveca, simd_load_double(tabdValMin), simd_load_double(tabdValMax));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble clamp(const simddouble& v, const double& minVal, const double& maxVal)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = clamp(dveca, 2.0, 10.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 clamp(const dvec2& v, const simddouble& minVal, const simddouble& maxVal)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = clamp(dvec2a, simd_load_double(tabdValMin), simd_load_double(tabdValMax));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 clamp(const dvec2& v, const double& minVal, const double& maxVal)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = clamp(dvec2a, 2.0, 10.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 clamp(const dvec2& v, const dvec2& minVal, const dvec2& maxVal)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2 dvec2Min = dvec2(simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec2 dvec2Max = dvec2(simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dvec2b = clamp(dvec2a, dvec2Min, dvec2Max);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 clamp(const dvec3& v, const simddouble& minVal, const simddouble& maxVal)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = clamp(dvec3a, simd_load_double(tabdValMin), simd_load_double(tabdValMax));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 clamp(const dvec3& v, const double& minVal, const double& maxVal)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = clamp(dvec3a, 2.0, 10.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 clamp(const dvec3& v, const dvec3& minVal, const dvec3& maxVal)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3 dvec3Min = dvec3(simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec3 dvec3Max = dvec3(simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dvec3b = clamp(dvec3a, dvec3Min, dvec3Max);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 clamp(const dvec4& v, const simddouble& minVal, const simddouble& maxVal)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = clamp(dvec4a, simd_load_double(tabdValMin), simd_load_double(tabdValMax));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 clamp(const dvec4& v, const double& minVal, const double& maxVal)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = clamp(dvec4a, 2.0, 10.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 clamp(const dvec4& v, const dvec4& minVal, const dvec4& maxVal)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4 dvec4Min = dvec4(simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec4 dvec4Max = dvec4(simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dvec4b = clamp(dvec4a, dvec4Min, dvec4Max);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::max(2.0, std::min(val, 10.0)); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for cos
	std::cout << "simddouble cos(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = cos(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::cos(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 cos(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = cos(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::cos(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 cos(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = cos(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::cos(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 cos(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = cos(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::cos(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for cosh
	std::cout << "simddouble cosh(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = cosh(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::cosh(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 cosh(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = cosh(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::cosh(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 cosh(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = cosh(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::cosh(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 cosh(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = cosh(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::cosh(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for degrees
	std::cout << "simddouble degrees(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = degrees(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 180.0 / 3.14159265358979323846f; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 degrees(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = degrees(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 180.0 / 3.14159265358979323846f; });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 degrees(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = degrees(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 180.0 / 3.14159265358979323846f; });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 degrees(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = degrees(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 180.0 / 3.14159265358979323846f; });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for exp
	std::cout << "simddouble exp(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabSmalldVal);
	dvecb = exp(dveca);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::exp(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 exp(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec2b = exp(dvec2a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::exp(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 exp(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec3b = exp(dvec3a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::exp(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 exp(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec4b = exp(dvec4a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::exp(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for exp2
	std::cout << "simddouble exp2(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabSmalldVal);
	dvecb = exp2(dveca);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::exp2(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 exp2(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec2b = exp2(dvec2a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::exp2(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 exp2(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec3b = exp2(dvec3a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::exp2(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 exp2(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec4b = exp2(dvec4a);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::exp2(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for fma
	std::cout << "simddouble fma(const simddouble& _a, const simddouble& _b, const simddouble& _c)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = (0.5);
	dvecc = (2.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::fma(val, 0.5, 2.0); });
	CompareDouble(fma(dveca, dvecb, dvecc), simd_load_double(tabdValResult));

	std::cout << "dvec2 fma(const dvec2& _a, const dvec2& _b, const dvec2& _c)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = dvec2((0.5), (0.5));
	dvec2c = dvec2((2.0), (2.0));
	dvec2 dvec2FmaResult = fma(dvec2a, dvec2b, dvec2c);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::fma(val, 0.5, 2.0); });
	CompareDouble(dvec2FmaResult.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2FmaResult.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 fma(const dvec3& _a, const dvec3& _b, const dvec3& _c)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = dvec3((0.5), (0.5), (0.5));
	dvec3c = dvec3((2.0), (2.0), (2.0));
	dvec3 dvec3FmaResult = fma(dvec3a, dvec3b, dvec3c);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::fma(val, 0.5, 2.0); });
	CompareDouble(dvec3FmaResult.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3FmaResult.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3FmaResult.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 fma(const dvec4& _a, const dvec4& _b, const dvec4& _c)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = dvec4((0.5), (0.5), (0.5), (0.5));
	dvec4c = dvec4((2.0), (2.0), (2.0), (2.0));
	dvec4 dvec4FmaResult = fma(dvec4a, dvec4b, dvec4c);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::fma(val, 0.5, 2.0); });
	CompareDouble(dvec4FmaResult.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4FmaResult.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4FmaResult.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4FmaResult.w, simd_load_double(tabdValResult));

	// Tests for inversesqrt
	std::cout << "simddouble inversesqrt(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = inversesqrt(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 / std::sqrt(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 inversesqrt(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = inversesqrt(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 / std::sqrt(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 inversesqrt(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = inversesqrt(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 / std::sqrt(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 inversesqrt(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = inversesqrt(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return 1.0 / std::sqrt(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for ldexp
	std::cout << "simddouble ldexp(const simddouble& _a, const simddouble& _b)" << std::endl;
	dveca = simd_load_double(tabSmalldVal);
	dvecb = (2.0);
	dvecc = ldexp(dveca, dvecb);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::ldexp(val, (int)2.0); });
	CompareDouble(dvecc, simd_load_double(tabdValResult));

	std::cout << "dvec2 ldexp(const dvec2& _a, const dvec2& _b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec2b = dvec2((2.0), (2.0));
	dvec2c = ldexp(dvec2a, dvec2b);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::ldexp(val, (int)2.0); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 ldexp(const dvec3& _a, const dvec3& _b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec3b = dvec3((2.0), (2.0), (2.0));
	dvec3c = ldexp(dvec3a, dvec3b);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::ldexp(val, (int)2.0); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 ldexp(const dvec4& _a, const dvec4& _b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal), simd_load_double(tabSmalldVal));
	dvec4b = dvec4((2.0), (2.0), (2.0), (2.0));
	dvec4c = ldexp(dvec4a, dvec4b);
	FillTabResultDouble(tabSmalldVal, tabdValResult, [](const double& val, const int& idx) { return std::ldexp(val, (int)2.0); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));

	// Tests for length
	std::cout << "simddouble length(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dveca = length(dvec2a);
	FillTabResultDouble(tabdVal, lengthResultDouble, [](const double& val, const int& idx) { return std::sqrt(val * val + 0.5 * 0.5); });
	CompareDouble(dveca, simd_load_double(lengthResultDouble));

	std::cout << "simddouble length(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dveca = length(dvec3a);
	for (int i = 0; i < 16; ++i) {
		lengthResultDouble[i] = std::sqrt(tabdVal[i] * tabdVal[i] + 0.5 * 0.5 + 2.0 * 2.0);
	}
	CompareDouble(dveca, simd_load_double(lengthResultDouble));

	std::cout << "simddouble length(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dveca = length(dvec4a);
	for (int i = 0; i < 16; ++i) {
		lengthResultDouble[i] = std::sqrt(tabdVal[i] * tabdVal[i] + 0.5 * 0.5 + 2.0 * 2.0 + tabdValAcosh[i] * tabdValAcosh[i]);
	}
	CompareDouble(dveca, simd_load_double(lengthResultDouble));

	// Tests for lerp
	std::cout << "simddouble lerp(const simddouble&, const simddouble&, const simddouble&)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = simd_load_double(tabdValMin);
	dvecc = (0.5);
	simddouble lerpdResult = lerp(dveca, dvecb, dvecc);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(lerpdResult, simd_load_double(tabdValResult));

	std::cout << "simddouble lerp(const simddouble&, const simddouble&, const double&)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = simd_load_double(tabdValMin);
	lerpdResult = lerp(dveca, dvecb, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(lerpdResult, simd_load_double(tabdValResult));

	std::cout << "dvec2 lerp(const dvec2&, const dvec2&, const double&)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (3.0));
	dvec2b = dvec2(simd_load_double(tabdValMin), (5.0));
	dvec2c = lerp(dvec2a, dvec2b, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 lerp(const dvec2&, const dvec2&, const simddouble&)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (3.0));
	dvec2b = dvec2(simd_load_double(tabdValMin), (5.0));
	dveca = (0.5);
	dvec2c = lerp(dvec2a, dvec2b, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 lerp(const dvec2&, const dvec2&, const dvec2&)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (3.0));
	dvec2b = dvec2(simd_load_double(tabdValMin), (5.0));
	dvec2 dvec2t = dvec2((0.5), (0.3));
	dvec2c = lerp(dvec2a, dvec2b, dvec2t);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.3 * (5.0 - 3.0); });
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 lerp(const dvec3&, const dvec3&, const double&)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (3.0), (7.0));
	dvec3b = dvec3(simd_load_double(tabdValMin), (5.0), (9.0));
	dvec3c = lerp(dvec3a, dvec3b, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.5 * (9.0 - 7.0); });
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 lerp(const dvec3&, const dvec3&, const simddouble&)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (3.0), (7.0));
	dvec3b = dvec3(simd_load_double(tabdValMin), (5.0), (9.0));
	dveca = (0.5);
	dvec3c = lerp(dvec3a, dvec3b, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.5 * (9.0 - 7.0); });
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 lerp(const dvec3&, const dvec3&, const dvec3&)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (3.0), (7.0));
	dvec3b = dvec3(simd_load_double(tabdValMin), (5.0), (9.0));
	dvec3 dvec3t = dvec3((0.5), (0.3), (0.7));
	dvec3c = lerp(dvec3a, dvec3b, dvec3t);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.3 * (5.0 - 3.0); });
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.7 * (9.0 - 7.0); });
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 lerp(const dvec4&, const dvec4&, const double&)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (3.0), (7.0), (11.0));
	dvec4b = dvec4(simd_load_double(tabdValMin), (5.0), (9.0), (13.0));
	dvec4c = lerp(dvec4a, dvec4b, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.5 * (9.0 - 7.0); });
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 11.0 + 0.5 * (13.0 - 11.0); });
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 lerp(const dvec4&, const dvec4&, const simddouble&)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (3.0), (7.0), (11.0));
	dvec4b = dvec4(simd_load_double(tabdValMin), (5.0), (9.0), (13.0));
	dveca = (0.5);
	dvec4c = lerp(dvec4a, dvec4b, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.5 * (9.0 - 7.0); });
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 11.0 + 0.5 * (13.0 - 11.0); });
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 lerp(const dvec4&, const dvec4&, const dvec4&)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (3.0), (7.0), (11.0));
	dvec4b = dvec4(simd_load_double(tabdValMin), (5.0), (9.0), (13.0));
	dvec4 dvec4t = dvec4((0.5), (0.3), (0.7), (0.2));
	dvec4c = lerp(dvec4a, dvec4b, dvec4t);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.3 * (5.0 - 3.0); });
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.7 * (9.0 - 7.0); });
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 11.0 + 0.2 * (13.0 - 11.0); });
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));

	// Tests for log
	std::cout << "simddouble log(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = log(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::log(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 log(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = log(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::log(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 log(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = log(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::log(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 log(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = log(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::log(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for log2
	std::cout << "simddouble log2(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = log2(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::log2(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 log2(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = log2(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::log2(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 log2(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = log2(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::log2(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 log2(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = log2(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::log2(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for mix
	std::cout << "simddouble mix(const simddouble&, const simddouble&, const simddouble&)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = simd_load_double(tabdValMin);
	dvecc = (0.5);
	simddouble dmixResult = mix(dveca, dvecb, dvecc);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dmixResult, simd_load_double(tabdValResult));

	std::cout << "simddouble mix(const simddouble&, const simddouble&, const double&)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = simd_load_double(tabdValMin);
	dmixResult = mix(dveca, dvecb, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dmixResult, simd_load_double(tabdValResult));

	std::cout << "dvec2 mix(const dvec2&, const dvec2&, const double&)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (3.0));
	dvec2b = dvec2(simd_load_double(tabdValMin), (5.0));
	dvec2c = mix(dvec2a, dvec2b, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 mix(const dvec2&, const dvec2&, const simddouble&)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (3.0));
	dvec2b = dvec2(simd_load_double(tabdValMin), (5.0));
	dveca = (0.5);
	dvec2c = mix(dvec2a, dvec2b, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 mix(const dvec2&, const dvec2&, const dvec2&)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (3.0));
	dvec2b = dvec2(simd_load_double(tabdValMin), (5.0));
	dvec2t = dvec2((0.5), (0.3));
	dvec2c = mix(dvec2a, dvec2b, dvec2t);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.3 * (5.0 - 3.0); });
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 mix(const dvec3&, const dvec3&, const double&)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (3.0), (7.0));
	dvec3b = dvec3(simd_load_double(tabdValMin), (5.0), (9.0));
	dvec3c = mix(dvec3a, dvec3b, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.5 * (9.0 - 7.0); });
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 mix(const dvec3&, const dvec3&, const simddouble&)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (3.0), (7.0));
	dvec3b = dvec3(simd_load_double(tabdValMin), (5.0), (9.0));
	dveca = (0.5);
	dvec3c = mix(dvec3a, dvec3b, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.5 * (9.0 - 7.0); });
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 mix(const dvec3&, const dvec3&, const dvec3&)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (3.0), (7.0));
	dvec3b = dvec3(simd_load_double(tabdValMin), (5.0), (9.0));
	dvec3t = dvec3((0.5), (0.3), (0.7));
	dvec3c = mix(dvec3a, dvec3b, dvec3t);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.3 * (5.0 - 3.0); });
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.7 * (9.0 - 7.0); });
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 mix(const dvec4&, const dvec4&, const double&)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (3.0), (7.0), (11.0));
	dvec4b = dvec4(simd_load_double(tabdValMin), (5.0), (9.0), (13.0));
	dvec4c = mix(dvec4a, dvec4b, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.5 * (9.0 - 7.0); });
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 11.0 + 0.5 * (13.0 - 11.0); });
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 mix(const dvec4&, const dvec4&, const simddouble&)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (3.0), (7.0), (11.0));
	dvec4b = dvec4(simd_load_double(tabdValMin), (5.0), (9.0), (13.0));
	dveca = (0.5);
	dvec4c = mix(dvec4a, dvec4b, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.5 * (5.0 - 3.0); });
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.5 * (9.0 - 7.0); });
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 11.0 + 0.5 * (13.0 - 11.0); });
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 mix(const dvec4&, const dvec4&, const dvec4&)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (3.0), (7.0), (11.0));
	dvec4b = dvec4(simd_load_double(tabdValMin), (5.0), (9.0), (13.0));
	dvec4t = dvec4((0.5), (0.3), (0.7), (0.2));
	dvec4c = mix(dvec4a, dvec4b, dvec4t);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val + 0.5 * (2.0 - val); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 3.0 + 0.3 * (5.0 - 3.0); });
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 7.0 + 0.7 * (9.0 - 7.0); });
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) { return 11.0 + 0.2 * (13.0 - 11.0); });
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));


	// Tests for radians
	std::cout << "simddouble radians(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = radians(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 3.14159265358979323846f / 180.0; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 radians(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = radians(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 3.14159265358979323846f / 180.0; });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 radians(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = radians(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 3.14159265358979323846f / 180.0; });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 radians(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = radians(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val * 3.14159265358979323846f / 180.0; });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for reflect
	std::cout << "dvec2 reflect(const dvec2& _a, const dvec2& _b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = normalize(dvec2((2.0), (2.0)));
	dvec2c = reflect(dvec2a, dvec2b);
	// reflect(I, N) = I - 2.0 * dot(N, I) * N
	for (int idx = 0; idx < 16; ++idx) {
		double tempAX = tabdVal[idx];
		double tempAY = 0.5f;
		double tempBX = 2.0 / std::sqrt(2.0 * 2.0 + 2.0 * 2.0);
		double tempBY = 2.0 / std::sqrt(2.0 * 2.0 + 2.0 * 2.0);
		tabdValResult[idx] = tempAX - 2.0 * (tempBX * tempAX + tempBY * tempAY) * tempBX;
	}
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 reflect(const dvec3& _a, const dvec3& _b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = normalize(dvec3((2.0), (2.0), (2.0)));
	dvec3c = reflect(dvec3a, dvec3b);
	for (int idx = 0; idx < 16; ++idx) {
		double tempAX = tabdVal[idx];
		double tempAY = 0.5f;
		double tempAZ = 2.0;
		double tempBX = 2.0 / std::sqrt(2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0);
		double tempBY = 2.0 / std::sqrt(2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0);
		double tempBZ = 2.0 / std::sqrt(2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0);
		tabdValResult[idx] = tempAX - 2.0 * (tempBX * tempAX + tempBY * tempAY + tempBZ * tempAZ) * tempBX;
	}
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 reflect(const dvec4& _a, const dvec4& _b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = normalize(dvec4((2.0), (2.0), (2.0), (2.0)));
	dvec4c = reflect(dvec4a, dvec4b);
	for (int idx = 0; idx < 16; ++idx) {
		double tempAX = tabdVal[idx];
		double tempAY = 0.5f;
		double tempAZ = 2.0;
		double tempAW = tabdValAcosh[idx];
		double tempBX = 2.0 / std::sqrt(2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0);
		double tempBY = 2.0 / std::sqrt(2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0);
		double tempBZ = 2.0 / std::sqrt(2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0);
		double tempBW = 2.0 / std::sqrt(2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0 + 2.0 * 2.0);
		tabdValResult[idx] = tempAX - 2.0 * (tempBX * tempAX + tempBY * tempAY + tempBZ * tempAZ + tempBW * tempAW) * tempBX;
	}
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));

	// Tests for refract
	std::cout << "refract(const dvec2&, const dvec2&, const double&)" << std::endl;
	std::cout << "refract(const dvec2&, const dvec2&, const simddouble&)" << std::endl;
	std::cout << "refract(const dvec3&, const dvec3&, const double&)" << std::endl;
	std::cout << "refract(const dvec3&, const dvec3&, const simddouble&)" << std::endl;
	std::cout << "refract(const dvec4&, const dvec4&, const double&)" << std::endl;
	std::cout << "refract(const dvec4&, const dvec4&, const simddouble&)" << std::endl;

	// Tests for round
	std::cout << "simddouble round(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = round(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::round(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 round(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = round(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::round(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 round(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = round(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::round(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 round(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = round(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::round(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for sign
	std::cout << "simddouble sign(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdValNeg);
	dvecb = sign(dveca);
	FillTabResultDouble(tabdValNeg, tabdValResult, [](const double& val, const int& idx) { return val > 0.0 ? 1.0 : (val < 0.0 ? -1.0 : 0.0); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 sign(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdValNeg), simd_load_double(tabdValNeg));
	dvec2b = sign(dvec2a);
	FillTabResultDouble(tabdValNeg, tabdValResult, [](const double& val, const int& idx) { return val > 0.0 ? 1.0 : (val < 0.0 ? -1.0 : 0.0); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 sign(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdValNeg), simd_load_double(tabdValNeg), simd_load_double(tabdValNeg));
	dvec3b = sign(dvec3a);
	FillTabResultDouble(tabdValNeg, tabdValResult, [](const double& val, const int& idx) { return val > 0.0 ? 1.0 : (val < 0.0 ? -1.0 : 0.0); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 sign(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdValNeg), simd_load_double(tabdValNeg), simd_load_double(tabdValNeg), simd_load_double(tabdValNeg));
	dvec4b = sign(dvec4a);
	FillTabResultDouble(tabdValNeg, tabdValResult, [](const double& val, const int& idx) { return val > 0.0 ? 1.0 : (val < 0.0 ? -1.0 : 0.0); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for sin
	std::cout << "simddouble sin(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = sin(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sin(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 sin(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = sin(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sin(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 sin(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = sin(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sin(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 sin(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = sin(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sin(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for sinh
	std::cout << "simddouble sinh(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = sinh(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sinh(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 sinh(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = sinh(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sinh(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 sinh(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = sinh(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sinh(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 sinh(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = sinh(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sinh(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for step
	std::cout << "simddouble step(const simddouble& _edge, const simddouble& _x)" << std::endl;
	dveca = simd_load_double(tabdValMin); // edge = 2.0
	dvecb = simd_load_double(tabdVal);     // x
	dvecc = step(dveca, dvecb);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvecc, simd_load_double(tabdValResult));

	std::cout << "simddouble step(const double& _edge, const simddouble& _x)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = step(5.0, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 5.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "simddouble step(const simddouble& _edge, const double& _x)" << std::endl;
	dveca = simd_load_double(tabdValMin); // edge = 2.0
	dvecb = step(dveca, 5.0);
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 5.0 < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 step(const dvec2& _edge, const simddouble& _x)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdValMin), (5.0));
	dveca = simd_load_double(tabdVal);
	dvec2b = step(dvec2a, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 5.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 step(const simddouble& _edge, const dvec2& _x)" << std::endl;
	dveca = simd_load_double(tabdValMin); // edge = 2.0
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = step(dveca, dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 0.5f < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 step(const dvec2& _edge, const dvec2& _x)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdValMin), (5.0));
	dvec2b = dvec2(simd_load_double(tabdVal), (7.0));
	dvec2c = step(dvec2a, dvec2b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 7.0 < 5.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec2c.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 step(const dvec3& _edge, const simddouble& _x)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdValMin), (5.0), (8.0));
	dveca = simd_load_double(tabdVal);
	dvec3b = step(dvec3a, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 5.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 8.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 step(const simddouble& _edge, const dvec3& _x)" << std::endl;
	dveca = simd_load_double(tabdValMin); // edge = 2.0
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (7.0));
	dvec3b = step(dveca, dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 0.5f < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 7.0 < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 step(const dvec3& _edge, const dvec3& _x)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdValMin), (5.0), (8.0));
	dvec3b = dvec3(simd_load_double(tabdVal), (7.0), (12.0));
	dvec3c = step(dvec3a, dvec3b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 7.0 < 5.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 12.0 < 8.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 step(const dvec4& _edge, const simddouble& _x)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdValMin), (5.0), (8.0), (11.0));
	dveca = simd_load_double(tabdVal);
	dvec4b = step(dvec4a, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 5.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 8.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 11.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 step(const simddouble& _edge, const dvec4& _x)" << std::endl;
	dveca = simd_load_double(tabdValMin); // edge = 2.0
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (7.0), (3.0));
	dvec4b = step(dveca, dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 0.5f < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 7.0 < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 3.0 < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 step(const dvec4& _edge, const dvec4& _x)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdValMin), (5.0), (8.0), (11.0));
	dvec4b = dvec4(simd_load_double(tabdVal), (7.0), (12.0), (9.0));
	dvec4c = step(dvec4a, dvec4b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		return val < 2.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 7.0 < 5.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4c.y, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 12.0 < 8.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4c.z, simd_load_double(tabdValResult));
	FillTabResultDouble(tabdValResult, tabdValResult, [](const double& val, const int& idx) {
		return 9.0 < 11.0 ? 0.0 : 1.0;
		});
	CompareDouble(dvec4c.w, simd_load_double(tabdValResult));


	// Tests for sqrt
	std::cout << "simddouble sqrt(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = sqrt(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sqrt(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 sqrt(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = sqrt(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sqrt(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 sqrt(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = sqrt(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sqrt(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 sqrt(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = sqrt(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::sqrt(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for tan
	std::cout << "simddouble tan(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = tan(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::tan(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 tan(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = tan(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::tan(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 tan(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = tan(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::tan(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 tan(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = tan(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::tan(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for tanh
	std::cout << "simddouble tanh(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = tanh(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::tanh(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 tanh(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = tanh(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::tanh(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 tanh(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = tanh(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::tanh(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 tanh(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = tanh(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::tanh(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for trunc
	std::cout << "simddouble trunc(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabRandomdVal);
	dvecb = trunc(dveca);
	FillTabResultDouble(tabRandomdVal, tabdValResult, [](const double& val, const int& idx) { return std::trunc(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 trunc(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = trunc(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::trunc(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 trunc(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = trunc(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::trunc(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 trunc(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = trunc(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::trunc(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for dot
	std::cout << "simddouble dot(const dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = dvec2((2.0), simd_load_double(tabdValAcosh));
	dveca = dot(dvec2a, dvec2b);
	for (int i = 0; i < halfsimdwidth; i++) {
		tabdValResult[i] = tabdVal[i] * 2.0 + 0.5f * tabdValAcosh[i];
	}
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble dot(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = dvec3((2.0), simd_load_double(tabdValAcosh), simd_load_double(tabdValMin));
	dveca = dot(dvec3a, dvec3b);
	for (int i = 0; i < halfsimdwidth; i++) {
		tabdValResult[i] = tabdVal[i] * 2.0 + 0.5f * tabdValAcosh[i] + 2.0 * tabdValMin[i];
	}
	CompareDouble(dveca, simd_load_double(tabdValResult));

	std::cout << "simddouble dot(const dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = dvec4((2.0), simd_load_double(tabdValAcosh), simd_load_double(tabdValMin), simd_load_double(tabdValMax));
	dveca = dot(dvec4a, dvec4b);
	for (int i = 0; i < halfsimdwidth; i++) {
		tabdValResult[i] = tabdVal[i] * 2.0 + 0.5f * tabdValAcosh[i] + 2.0 * tabdValMin[i] + tabdValAcosh[i] * tabdValMax[i];
	}
	CompareDouble(dveca, simd_load_double(tabdValResult));

	// Tests for cross
	std::cout << "dvec3 cross(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = dvec3((2.0), simd_load_double(tabdValAcosh), simd_load_double(tabdValMin));
	dvec3c = cross(dvec3a, dvec3b);
	for (int i = 0; i < halfsimdwidth; i++) {
		tabdValResult[i] = 0.5f * tabdValMin[i] - 2.0 * tabdValAcosh[i];
	}
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));
	for (int i = 0; i < halfsimdwidth; i++) {
		tabdValResult[i] = 2.0 * 2.0 - tabdVal[i] * tabdValMin[i];
	}
	CompareDouble(dvec3c.y, simd_load_double(tabdValResult));
	for (int i = 0; i < halfsimdwidth; i++) {
		tabdValResult[i] = tabdVal[i] * tabdValAcosh[i] - 0.5f * 2.0;
	}
	CompareDouble(dvec3c.z, simd_load_double(tabdValResult));

	// Tests for normalize
	std::cout << "dvec2 normalize(const dvec2& v)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = normalize(dvec2a);
	for (int i = 0; i < halfsimdwidth; i++) {
		double len = std::sqrt(tabdVal[i] * tabdVal[i] + 0.5f * 0.5);
		tabdValResult[i] = tabdVal[i] / len;
	}
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 normalize(const dvec3& v)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = normalize(dvec3a);
	for (int i = 0; i < halfsimdwidth; i++) {
		double len = std::sqrt(tabdVal[i] * tabdVal[i] + 0.5f * 0.5f + 2.0 * 2.0);
		tabdValResult[i] = tabdVal[i] / len;
	}
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 normalize(const dvec4& v)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = normalize(dvec4a);
	for (int i = 0; i < halfsimdwidth; i++) {
		double len = std::sqrt(tabdVal[i] * tabdVal[i] + 0.5f * 0.5f + 2.0 * 2.0 + tabdValAcosh[i] * tabdValAcosh[i]);
		tabdValResult[i] = tabdVal[i] / len;
	}
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	for (int i = 0; i < halfsimdwidth; i++) {
		double len = std::sqrt(tabdVal[i] * tabdVal[i] + 0.5f * 0.5f + 2.0 * 2.0 + tabdValAcosh[i] * tabdValAcosh[i]);
		tabdValResult[i] = 0.5f / len;
	}
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	for (int i = 0; i < halfsimdwidth; i++) {
		double len = std::sqrt(tabdVal[i] * tabdVal[i] + 0.5f * 0.5f + 2.0 * 2.0 + tabdValAcosh[i] * tabdValAcosh[i]);
		tabdValResult[i] = 2.0 / len;
	}
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	for (int i = 0; i < halfsimdwidth; i++) {
		double len = std::sqrt(tabdVal[i] * tabdVal[i] + 0.5f * 0.5f + 2.0 * 2.0 + tabdValAcosh[i] * tabdValAcosh[i]);
		tabdValResult[i] = tabdValAcosh[i] / len;
	}
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for floor
	std::cout << "simddouble floor(const simddouble& _a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = floor(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::floor(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 floor(const dvec2& _a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = floor(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::floor(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 floor(const dvec3& _a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = floor(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::floor(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 floor(const dvec4& _a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = floor(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::floor(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for fract
	std::cout << "simddouble fract(const simddouble& a)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = fract(dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 fract(const dvec2& a)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec2b = fract(dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec3 fract(const dvec3& a)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec3b = fract(dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec4 fract(const dvec4& a)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal), simd_load_double(tabdVal));
	dvec4b = fract(dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	// Tests for mod
	std::cout << "simddouble mod(const simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = (0.5);
	dvecc = mod(dveca, dvecb);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 0.5) * 0.5f; });
	CompareDouble(dvecc, simd_load_double(tabdValResult));

	std::cout << "simddouble mod(const simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = mod(dveca, 3.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 3.0) * 3.0; });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 mod(const dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = mod(dvec2a, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 0.5) * 0.5f; });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 mod(const dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = mod(dvec2a, 3.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 3.0) * 3.0; });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 mod(const dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = dvec2((0.5), (2.0));
	dvec2c = mod(dvec2a, dvec2b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 0.5) * 0.5f; });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 mod(const dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = mod(dvec3a, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 0.5) * 0.5f; });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 mod(const dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = mod(dvec3a, 3.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 3.0) * 3.0; });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 mod(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = dvec3((0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec3c = mod(dvec3a, dvec3b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 0.5) * 0.5f; });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 mod(const dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = mod(dvec4a, 0.5);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 0.5) * 0.5f; });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 mod(const dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = mod(dvec4a, 3.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 3.0) * 3.0; });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 mod(const dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = dvec4((0.5), (2.0), simd_load_double(tabdValAcosh), simd_load_double(tabdValMin));
	dvec4c = mod(dvec4a, dvec4b);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return val - std::floor(val / 0.5) * 0.5f; });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));

	// Tests for modf
	std::cout << "modf(const simdfloat&, simdfloat&)" << std::endl;
	std::cout << "modf(const vec2&, vec2&)" << std::endl;
	std::cout << "modf(const vec3&, vec3&)" << std::endl;
	std::cout << "modf(const vec4&, vec4&)" << std::endl;




	// Tests for pow
	std::cout << "simddouble pow(const simddouble& a, const simddouble& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = (2.0);
	dvecc = pow(dveca, dvecb);
	FillTabResultDouble(tabdVal, tabdValResult, [&tabSmalldVal](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvecc, simd_load_double(tabdValResult));

	std::cout << "simddouble pow(const simddouble& a, const double& b)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = pow(dveca, 2.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 pow(const dvec2& a, const simddouble& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = pow(dvec2a, (2.0));
	FillTabResultDouble(tabdVal, tabdValResult, [&tabSmalldVal](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 pow(const dvec2& a, const double& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = pow(dvec2a, 2.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec2 pow(const dvec2& a, const dvec2& b)" << std::endl;
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = dvec2((2.0), (2.0));
	dvec2c = pow(dvec2a, dvec2b);
	FillTabResultDouble(tabdVal, tabdValResult, [&tabSmalldVal](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvec2c.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 pow(const dvec3& a, const simddouble& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = pow(dvec3a, (2.0));
	FillTabResultDouble(tabdVal, tabdValResult, [&tabSmalldVal](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 pow(const dvec3& a, const double& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = pow(dvec3a, 2.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 pow(const dvec3& a, const dvec3& b)" << std::endl;
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = dvec3((2.0), (2.0), (2.0));
	dvec3c = pow(dvec3a, dvec3b);
	FillTabResultDouble(tabdVal, tabdValResult, [&tabSmalldVal](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvec3c.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 pow(const dvec4& a, const simddouble& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = pow(dvec4a, (2.0));
	FillTabResultDouble(tabdVal, tabdValResult, [&tabSmalldVal](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 pow(const dvec4& a, const double& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = pow(dvec4a, 2.0);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 pow(const dvec4& a, const dvec4& b)" << std::endl;
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = dvec4((2.0), (2.0), (2.0), (2.0));
	dvec4c = pow(dvec4a, dvec4b);
	FillTabResultDouble(tabdVal, tabdValResult, [&tabSmalldVal](const double& val, const int& idx) { return std::pow(val, 2.0); });
	CompareDouble(dvec4c.x, simd_load_double(tabdValResult));

	// Tests for smoothstep
	std::cout << "simddouble smoothstep(const simddouble& edge0, const simddouble& edge1, const simddouble& x)" << std::endl;
	dveca = simd_load_double(tabdValMin); // edge0 = 2.0
	dvecb = simd_load_double(tabdValMax); // edge1 = 10.0
	dvecc = simd_load_double(tabdVal);    // x
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (val - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(smoothstep(dveca, dvecb, dvecc), simd_load_double(tabdValResult));

	std::cout << "simddouble smoothstep(const double& edge0, const double& edge1, const simddouble& x)" << std::endl;
	dveca = simd_load_double(tabdVal);
	dvecb = smoothstep(2.0, 10.0, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (val - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvecb, simd_load_double(tabdValResult));

	std::cout << "dvec2 smoothstep(const dvec2& edge0, const dvec2& edge1, const simddouble& x)" << std::endl;
	dvec2Min = dvec2(simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec2Max = dvec2(simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dveca = simd_load_double(tabdVal);
	dvec2b = smoothstep(dvec2Min, dvec2Max, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (val - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 smoothstep(const dvec2& edge0, const dvec2& edge1, const double& x)" << std::endl;
	dvec2Min = dvec2(simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec2Max = dvec2(simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dvec2b = smoothstep(dvec2Min, dvec2Max, 5.0);
	FillTabResultDouble(tabdValMin, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (5.0 - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec2b.y, simd_load_double(tabdValResult));

	std::cout << "dvec2 smoothstep(const dvec2& edge0, const dvec2& edge1, const dvec2& x)" << std::endl;
	dvec2Min = dvec2(simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec2Max = dvec2(simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dvec2a = dvec2(simd_load_double(tabdVal), (0.5));
	dvec2b = smoothstep(dvec2Min, dvec2Max, dvec2a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (val - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvec2b.x, simd_load_double(tabdValResult));

	std::cout << "dvec3 smoothstep(const dvec3& edge0, const dvec3& edge1, const simddouble& x)" << std::endl;
	dvec3Min = dvec3(simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec3Max = dvec3(simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dveca = simd_load_double(tabdVal);
	dvec3b = smoothstep(dvec3Min, dvec3Max, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (val - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 smoothstep(const dvec3& edge0, const dvec3& edge1, const double& x)" << std::endl;
	dvec3Min = dvec3(simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec3Max = dvec3(simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dvec3b = smoothstep(dvec3Min, dvec3Max, 5.0);
	FillTabResultDouble(tabdValMin, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (5.0 - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec3b.z, simd_load_double(tabdValResult));

	std::cout << "dvec3 smoothstep(const dvec3& edge0, const dvec3& edge1, const dvec3& x)" << std::endl;
	dvec3Min = dvec3(simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec3Max = dvec3(simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dvec3a = dvec3(simd_load_double(tabdVal), (0.5), (2.0));
	dvec3b = smoothstep(dvec3Min, dvec3Max, dvec3a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (val - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvec3b.x, simd_load_double(tabdValResult));

	std::cout << "dvec4 smoothstep(const dvec4& edge0, const dvec4& edge1, const simddouble& x)" << std::endl;
	dvec4Min = dvec4(simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec4Max = dvec4(simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dveca = simd_load_double(tabdVal);
	dvec4b = smoothstep(dvec4Min, dvec4Max, dveca);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (val - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 smoothstep(const dvec4& edge0, const dvec4& edge1, const double& x)" << std::endl;
	dvec4Min = dvec4(simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec4Max = dvec4(simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dvec4b = smoothstep(dvec4Min, dvec4Max, 5.0);
	FillTabResultDouble(tabdValMin, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (5.0 - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.y, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.z, simd_load_double(tabdValResult));
	CompareDouble(dvec4b.w, simd_load_double(tabdValResult));

	std::cout << "dvec4 smoothstep(const dvec4& edge0, const dvec4& edge1, const dvec4& x)" << std::endl;
	dvec4Min = dvec4(simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin), simd_load_double(tabdValMin));
	dvec4Max = dvec4(simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax), simd_load_double(tabdValMax));
	dvec4a = dvec4(simd_load_double(tabdVal), (0.5), (2.0), simd_load_double(tabdValAcosh));
	dvec4b = smoothstep(dvec4Min, dvec4Max, dvec4a);
	FillTabResultDouble(tabdVal, tabdValResult, [](const double& val, const int& idx) {
		double t = std::max(0.0, std::min(1.0, (val - 2.0) / (10.0 - 2.0)));
		return t * t * (3.0 - 2.0 * t);
		});
	CompareDouble(dvec4b.x, simd_load_double(tabdValResult));


	// Tests for dmat2 multiplication
	std::cout << "dvec2 mul(const dmat2& m, const dvec2& v)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dvec2a = dvec2((5.0), (6.0));
	dvec2b = mul(dmat2a, dvec2a);
	CompareDouble(dvec2b.x, (23.0));
	CompareDouble(dvec2b.y, (34.0));

	std::cout << "dvec2 mul(const dvec2& v, const dmat2& m)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dvec2a = dvec2((5.0), (6.0));
	dvec2b = mul(dvec2a, dmat2a);
	CompareDouble(dvec2b.x, (17.0));
	CompareDouble(dvec2b.y, (39.0));

	std::cout << "dmat2 mul(const dmat2& _m1, const dmat2& _dmat2)" << std::endl;
	dmat2b = dmat2((1.0), (0.0), (2.0), (-1.0));
	dmat2a = dmat2((3.0), (4.0), (-2.0), (-3.0));
	dmat2c = mul(dmat2a, dmat2b);
	CompareDouble(dmat2c[0][0], (3.0));
	CompareDouble(dmat2c[0][1], (4.0));
	CompareDouble(dmat2c[1][0], (8.0));
	CompareDouble(dmat2c[1][1], (11.0));

	std::cout << "dvec2 operator*(const dmat2& m, const dvec2& v)" << std::endl;


	std::cout << "dvec2 operator*(const dvec2& v, const dmat2& m)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dvec2a = dvec2((5.0), (6.0));
	dvec2b = dvec2a * dmat2a;
	CompareDouble(dvec2b.x, (17.0));
	CompareDouble(dvec2b.y, (39.0));

	// Tests for dmat3 multiplication
	std::cout << "dvec3 mul(const dmat3& m, const dvec3& v)" << std::endl;


	std::cout << "dvec3 mul(const dvec3& v, const dmat3& m)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dvec3a = dvec3((2.0), (3.0), (4.0));
	dvec3b = mul(dvec3a, dmat3a);
	CompareDouble(dvec3b.x, (20.0));
	CompareDouble(dvec3b.y, (47.0));
	CompareDouble(dvec3b.z, (74.0));

	std::cout << "dmat3 mul(const dmat3& _m1, const dmat3& _dmat2)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = dmat3((11.0), (12.0), (13.0),
		(14.0), (15.0), (16.0),
		(17.0), (18.0), (19.0));
	dmat3c = mul(dmat3a, dmat3b);
	CompareDouble(dmat3c[0][0], (150.0));
	CompareDouble(dmat3c[0][1], (186.0));
	CompareDouble(dmat3c[0][2], (222.0));
	CompareDouble(dmat3c[1][0], (186.0));
	CompareDouble(dmat3c[1][1], (231.0));
	CompareDouble(dmat3c[1][2], (276.0));
	CompareDouble(dmat3c[2][0], (222.0));
	CompareDouble(dmat3c[2][1], (276.0));
	CompareDouble(dmat3c[2][2], (330.0));

	std::cout << "dvec3 operator*(const dmat3& m, const dvec3& v)" << std::endl;


	std::cout << "dvec3 operator*(const dvec3& v, const dmat3& m)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dvec3a = dvec3((2.0), (3.0), (4.0));
	dvec3b = dvec3a * dmat3a;
	CompareDouble(dvec3b.x, (20.0));
	CompareDouble(dvec3b.y, (47.0));
	CompareDouble(dvec3b.z, (74.0));

	// Tests for dmat4 multiplication
	std::cout << "dvec4 mul(const dmat4& m, const dvec4& v)" << std::endl;


	std::cout << "dvec4 mul(const dvec4& v, const dmat4& m)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dvec4a = dvec4((2.0), (3.0), (4.0), (5.0));
	dvec4b = mul(dvec4a, dmat4a);
	CompareDouble(dvec4b.x, (40.0));
	CompareDouble(dvec4b.y, (96.0));
	CompareDouble(dvec4b.z, (152.0));
	CompareDouble(dvec4b.w, (208.0));

	std::cout << "dmat4 mul(const dmat4& _m1, const dmat4& _dmat2)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = dmat4((17.0), (18.0), (19.0), (20.0),
		(21.0), (22.0), (23.0), (24.0),
		(25.0), (26.0), (27.0), (28.0),
		(29.0), (30.0), (31.0), (32.0));
	dmat4c = mul(dmat4a, dmat4b);
	CompareDouble(dmat4c[0][0], (538.0));
	CompareDouble(dmat4c[0][1], (612.0));
	CompareDouble(dmat4c[0][2], (686.0));
	CompareDouble(dmat4c[0][3], (760.0));
	CompareDouble(dmat4c[1][0], (650.0));
	CompareDouble(dmat4c[1][1], (740.0));
	CompareDouble(dmat4c[1][2], (830.0));
	CompareDouble(dmat4c[1][3], (920.0));
	CompareDouble(dmat4c[2][0], (762.0));
	CompareDouble(dmat4c[2][1], (868.0));
	CompareDouble(dmat4c[2][2], (974.0));
	CompareDouble(dmat4c[2][3], (1080.0));
	CompareDouble(dmat4c[3][0], (874.0));
	CompareDouble(dmat4c[3][1], (996.0));
	CompareDouble(dmat4c[3][2], (1118.0));
	CompareDouble(dmat4c[3][3], (1240.0));

	std::cout << "dvec4 operator*(const dmat4& m, const dvec4& v)" << std::endl;


	std::cout << "dvec4 operator*(const dvec4& v, const dmat4& m)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dvec4a = dvec4((2.0), (3.0), (4.0), (5.0));
	dvec4b = dvec4a * dmat4a;
	CompareDouble(dvec4b.x, (40.0));
	CompareDouble(dvec4b.y, (96.0));
	CompareDouble(dvec4b.z, (152.0));
	CompareDouble(dvec4b.w, (208.0));

	std::cout << "dmat2 operator+(const dmat2& a, const dmat2& b)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dmat2b = dmat2((5.0), (6.0), (7.0), (8.0));
	dmat2c = dmat2a + dmat2b;
	CompareDouble(dmat2c[0][0], (6.0));
	CompareDouble(dmat2c[0][1], (8.0));
	CompareDouble(dmat2c[1][0], (10.0));
	CompareDouble(dmat2c[1][1], (12.0));

	std::cout << "dmat2 operator-(const dmat2& a, const dmat2& b)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dmat2b = dmat2((5.0), (6.0), (7.0), (8.0));
	dmat2c = dmat2a - dmat2b;
	CompareDouble(dmat2c[0][0], (-4.0));
	CompareDouble(dmat2c[0][1], (-4.0));
	CompareDouble(dmat2c[1][0], (-4.0));
	CompareDouble(dmat2c[1][1], (-4.0));

	std::cout << "dmat2 operator*(const dmat2& a, const dmat2& b)" << std::endl;
	dmat2b = dmat2((1.0), (0.0), (2.0), (-1.0));
	dmat2a = dmat2((3.0), (4.0), (-2.0), (-3.0));
	dmat2c = dmat2a * dmat2b;
	CompareDouble(dmat2c[0][0], (3.0));
	CompareDouble(dmat2c[0][1], (4.0));
	CompareDouble(dmat2c[1][0], (8.0));
	CompareDouble(dmat2c[1][1], (11.0));

	std::cout << "dmat2 operator+=(dmat2& a, const dmat2& b)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dmat2b = dmat2((5.0), (6.0), (7.0), (8.0));
	dmat2a += dmat2b;
	CompareDouble(dmat2a[0][0], (6.0));
	CompareDouble(dmat2a[0][1], (8.0));
	CompareDouble(dmat2a[1][0], (10.0));
	CompareDouble(dmat2a[1][1], (12.0));

	std::cout << "dmat2 operator-=(dmat2& a, const dmat2& b)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dmat2b = dmat2((5.0), (6.0), (7.0), (8.0));
	dmat2a -= dmat2b;
	CompareDouble(dmat2a[0][0], (-4.0));
	CompareDouble(dmat2a[0][1], (-4.0));
	CompareDouble(dmat2a[1][0], (-4.0));
	CompareDouble(dmat2a[1][1], (-4.0));

	std::cout << "dmat2 operator*=(dmat2& a, const dmat2& b)" << std::endl;
	dmat2b = dmat2((1.0), (0.0), (2.0), (-1.0));
	dmat2a = dmat2((3.0), (4.0), (-2.0), (-3.0));
	dmat2a *= dmat2b;
	CompareDouble(dmat2c[0][0], (3.0));
	CompareDouble(dmat2c[0][1], (4.0));
	CompareDouble(dmat2c[1][0], (8.0));
	CompareDouble(dmat2c[1][1], (11.0));

	std::cout << "dmat2 operator*(const dmat2& m, const simddouble& s)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dmat2b = dmat2a * (2.0);
	CompareDouble(dmat2b[0][0], (2.0));
	CompareDouble(dmat2b[0][1], (4.0));
	CompareDouble(dmat2b[1][0], (6.0));
	CompareDouble(dmat2b[1][1], (8.0));

	std::cout << "dmat2 operator*(const simddouble& s, const dmat2& m)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dmat2b = (2.0) * dmat2a;
	CompareDouble(dmat2b[0][0], (2.0));
	CompareDouble(dmat2b[0][1], (4.0));
	CompareDouble(dmat2b[1][0], (6.0));
	CompareDouble(dmat2b[1][1], (8.0));

	std::cout << "dvec2 operator*(const dvec2& v, const dmat2& m)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dvec2a = dvec2((5.0), (6.0));
	dvec2b = dvec2a * dmat2a;
	CompareDouble(dvec2b.x, (17.0));
	CompareDouble(dvec2b.y, (39.0));

	std::cout << "dvec2 operator*(const dmat2& m, const dvec2& v)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dvec2a = dvec2((5.0), (6.0));
	dvec2b = dmat2a * dvec2a;
	CompareDouble(dvec2b.x, (23.0));
	CompareDouble(dvec2b.y, (34.0));

	std::cout << "dvec2 operator*=(dvec2& v, const dmat2& m)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dvec2a = dvec2((5.0), (6.0));
	dvec2a *= dmat2a;
	CompareDouble(dvec2a.x, (17.0));
	CompareDouble(dvec2a.y, (39.0));

	std::cout << "dmat3 operator+(const dmat3& a, const dmat3& b)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = dmat3((10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0),
		(16.0), (17.0), (18.0));
	dmat3c = dmat3a + dmat3b;
	CompareDouble(dmat3c[0][0], (11.0));
	CompareDouble(dmat3c[0][1], (13.0));
	CompareDouble(dmat3c[0][2], (15.0));
	CompareDouble(dmat3c[1][0], (17.0));
	CompareDouble(dmat3c[1][1], (19.0));
	CompareDouble(dmat3c[1][2], (21.0));
	CompareDouble(dmat3c[2][0], (23.0));
	CompareDouble(dmat3c[2][1], (25.0));
	CompareDouble(dmat3c[2][2], (27.0));

	std::cout << "dmat3 operator-(const dmat3& a, const dmat3& b)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = dmat3((10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0),
		(16.0), (17.0), (18.0));
	dmat3c = dmat3a - dmat3b;
	CompareDouble(dmat3c[0][0], (-9.0));
	CompareDouble(dmat3c[0][1], (-9.0));
	CompareDouble(dmat3c[0][2], (-9.0));
	CompareDouble(dmat3c[1][0], (-9.0));
	CompareDouble(dmat3c[1][1], (-9.0));
	CompareDouble(dmat3c[1][2], (-9.0));
	CompareDouble(dmat3c[2][0], (-9.0));
	CompareDouble(dmat3c[2][1], (-9.0));
	CompareDouble(dmat3c[2][2], (-9.0));

	std::cout << "dmat3 operator*(const dmat3& a, const dmat3& b)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = dmat3((11.0), (12.0), (13.0),
		(14.0), (15.0), (16.0),
		(17.0), (18.0), (19.0));
	dmat3c = dmat3a * dmat3b;
	CompareDouble(dmat3c[0][0], (150.0));
	CompareDouble(dmat3c[0][1], (186.0));
	CompareDouble(dmat3c[0][2], (222.0));
	CompareDouble(dmat3c[1][0], (186.0));
	CompareDouble(dmat3c[1][1], (231.0));
	CompareDouble(dmat3c[1][2], (276.0));
	CompareDouble(dmat3c[2][0], (222.0));
	CompareDouble(dmat3c[2][1], (276.0));
	CompareDouble(dmat3c[2][2], (330.0));

	std::cout << "dmat3 operator+=(dmat3& a, const dmat3& b)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = dmat3((10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0),
		(16.0), (17.0), (18.0));
	dmat3a += dmat3b;
	CompareDouble(dmat3a[0][0], (11.0));
	CompareDouble(dmat3a[0][1], (13.0));
	CompareDouble(dmat3a[0][2], (15.0));
	CompareDouble(dmat3a[1][0], (17.0));
	CompareDouble(dmat3a[1][1], (19.0));
	CompareDouble(dmat3a[1][2], (21.0));
	CompareDouble(dmat3a[2][0], (23.0));
	CompareDouble(dmat3a[2][1], (25.0));
	CompareDouble(dmat3a[2][2], (27.0));

	std::cout << "dmat3 operator-=(dmat3& a, const dmat3& b)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = dmat3((10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0),
		(16.0), (17.0), (18.0));
	dmat3a -= dmat3b;
	CompareDouble(dmat3a[0][0], (-9.0));
	CompareDouble(dmat3a[0][1], (-9.0));
	CompareDouble(dmat3a[0][2], (-9.0));
	CompareDouble(dmat3a[1][0], (-9.0));
	CompareDouble(dmat3a[1][1], (-9.0));
	CompareDouble(dmat3a[1][2], (-9.0));
	CompareDouble(dmat3a[2][0], (-9.0));
	CompareDouble(dmat3a[2][1], (-9.0));
	CompareDouble(dmat3a[2][2], (-9.0));

	std::cout << "dmat3 operator*=(dmat3& a, const dmat3& b)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = dmat3((11.0), (12.0), (13.0),
		(14.0), (15.0), (16.0),
		(17.0), (18.0), (19.0));
	dmat3a *= dmat3b;
	CompareDouble(dmat3a[0][0], (150.0));
	CompareDouble(dmat3a[0][1], (186.0));
	CompareDouble(dmat3a[0][2], (222.0));
	CompareDouble(dmat3a[1][0], (186.0));
	CompareDouble(dmat3a[1][1], (231.0));
	CompareDouble(dmat3a[1][2], (276.0));
	CompareDouble(dmat3a[2][0], (222.0));
	CompareDouble(dmat3a[2][1], (276.0));
	CompareDouble(dmat3a[2][2], (330.0));

	std::cout << "dmat3 operator*(const dmat3& m, const simddouble& s)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = dmat3a * (2.0);
	CompareDouble(dmat3b[0][0], (2.0));
	CompareDouble(dmat3b[0][1], (4.0));
	CompareDouble(dmat3b[0][2], (6.0));
	CompareDouble(dmat3b[1][0], (8.0));
	CompareDouble(dmat3b[1][1], (10.0));
	CompareDouble(dmat3b[1][2], (12.0));
	CompareDouble(dmat3b[2][0], (14.0));
	CompareDouble(dmat3b[2][1], (16.0));
	CompareDouble(dmat3b[2][2], (18.0));

	std::cout << "dmat3 operator*(const simddouble& s, const dmat3& m)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = (2.0) * dmat3a;
	CompareDouble(dmat3b[0][0], (2.0));
	CompareDouble(dmat3b[0][1], (4.0));
	CompareDouble(dmat3b[0][2], (6.0));
	CompareDouble(dmat3b[1][0], (8.0));
	CompareDouble(dmat3b[1][1], (10.0));
	CompareDouble(dmat3b[1][2], (12.0));
	CompareDouble(dmat3b[2][0], (14.0));
	CompareDouble(dmat3b[2][1], (16.0));
	CompareDouble(dmat3b[2][2], (18.0));

	std::cout << "dvec3 operator*(const dvec3& v, const dmat3& m)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dvec3a = dvec3((2.0), (3.0), (4.0));
	dvec3b = dvec3a * dmat3a;
	CompareDouble(dvec3b.x, (20.0));
	CompareDouble(dvec3b.y, (47.0));
	CompareDouble(dvec3b.z, (74.0));

	std::cout << "dvec3 operator*(const dmat3& m, const dvec3& v)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dvec3a = dvec3((2.0), (3.0), (4.0));
	dvec3b = dmat3a * dvec3a;
	CompareDouble(dvec3b.x, (42.0));
	CompareDouble(dvec3b.y, (51.0));
	CompareDouble(dvec3b.z, (60.0));

	std::cout << "dvec3 operator*=(dvec3& v, const dmat3& m)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dvec3a = dvec3((2.0), (3.0), (4.0));
	dvec3a *= dmat3a;
	CompareDouble(dvec3a.x, (20.0));
	CompareDouble(dvec3a.y, (47.0));
	CompareDouble(dvec3a.z, (74.0));

	std::cout << "dmat4 operator+(const dmat4& a, const dmat4& b)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = dmat4((17.0), (18.0), (19.0), (20.0),
		(21.0), (22.0), (23.0), (24.0),
		(25.0), (26.0), (27.0), (28.0),
		(29.0), (30.0), (31.0), (32.0));
	dmat4c = dmat4a + dmat4b;
	CompareDouble(dmat4c[0][0], (18.0));
	CompareDouble(dmat4c[0][1], (20.0));
	CompareDouble(dmat4c[0][2], (22.0));
	CompareDouble(dmat4c[0][3], (24.0));
	CompareDouble(dmat4c[1][0], (26.0));
	CompareDouble(dmat4c[1][1], (28.0));
	CompareDouble(dmat4c[1][2], (30.0));
	CompareDouble(dmat4c[1][3], (32.0));
	CompareDouble(dmat4c[2][0], (34.0));
	CompareDouble(dmat4c[2][1], (36.0));
	CompareDouble(dmat4c[2][2], (38.0));
	CompareDouble(dmat4c[2][3], (40.0));
	CompareDouble(dmat4c[3][0], (42.0));
	CompareDouble(dmat4c[3][1], (44.0));
	CompareDouble(dmat4c[3][2], (46.0));
	CompareDouble(dmat4c[3][3], (48.0));

	std::cout << "dmat4 operator-(const dmat4& a, const dmat4& b)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = dmat4((17.0), (18.0), (19.0), (20.0),
		(21.0), (22.0), (23.0), (24.0),
		(25.0), (26.0), (27.0), (28.0),
		(29.0), (30.0), (31.0), (32.0));
	dmat4c = dmat4a - dmat4b;
	CompareDouble(dmat4c[0][0], (-16.0));
	CompareDouble(dmat4c[0][1], (-16.0));
	CompareDouble(dmat4c[0][2], (-16.0));
	CompareDouble(dmat4c[0][3], (-16.0));
	CompareDouble(dmat4c[1][0], (-16.0));
	CompareDouble(dmat4c[1][1], (-16.0));
	CompareDouble(dmat4c[1][2], (-16.0));
	CompareDouble(dmat4c[1][3], (-16.0));
	CompareDouble(dmat4c[2][0], (-16.0));
	CompareDouble(dmat4c[2][1], (-16.0));
	CompareDouble(dmat4c[2][2], (-16.0));
	CompareDouble(dmat4c[2][3], (-16.0));
	CompareDouble(dmat4c[3][0], (-16.0));
	CompareDouble(dmat4c[3][1], (-16.0));
	CompareDouble(dmat4c[3][2], (-16.0));
	CompareDouble(dmat4c[3][3], (-16.0));

	std::cout << "dmat4 operator*(const dmat4& a, const dmat4& b)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = dmat4((17.0), (18.0), (19.0), (20.0),
		(21.0), (22.0), (23.0), (24.0),
		(25.0), (26.0), (27.0), (28.0),
		(29.0), (30.0), (31.0), (32.0));
	dmat4c = dmat4a * dmat4b;
	CompareDouble(dmat4c[0][0], (538.0));
	CompareDouble(dmat4c[0][1], (612.0));
	CompareDouble(dmat4c[0][2], (686.0));
	CompareDouble(dmat4c[0][3], (760.0));
	CompareDouble(dmat4c[1][0], (650.0));
	CompareDouble(dmat4c[1][1], (740.0));
	CompareDouble(dmat4c[1][2], (830.0));
	CompareDouble(dmat4c[1][3], (920.0));
	CompareDouble(dmat4c[2][0], (762.0));
	CompareDouble(dmat4c[2][1], (868.0));
	CompareDouble(dmat4c[2][2], (974.0));
	CompareDouble(dmat4c[2][3], (1080.0));
	CompareDouble(dmat4c[3][0], (874.0));
	CompareDouble(dmat4c[3][1], (996.0));
	CompareDouble(dmat4c[3][2], (1118.0));
	CompareDouble(dmat4c[3][3], (1240.0));

	std::cout << "dmat4 operator+=(dmat4& a, const dmat4& b)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = dmat4((17.0), (18.0), (19.0), (20.0),
		(21.0), (22.0), (23.0), (24.0),
		(25.0), (26.0), (27.0), (28.0),
		(29.0), (30.0), (31.0), (32.0));
	dmat4a += dmat4b;
	CompareDouble(dmat4a[0][0], (18.0));
	CompareDouble(dmat4a[0][1], (20.0));
	CompareDouble(dmat4a[0][2], (22.0));
	CompareDouble(dmat4a[0][3], (24.0));
	CompareDouble(dmat4a[1][0], (26.0));
	CompareDouble(dmat4a[1][1], (28.0));
	CompareDouble(dmat4a[1][2], (30.0));
	CompareDouble(dmat4a[1][3], (32.0));
	CompareDouble(dmat4a[2][0], (34.0));
	CompareDouble(dmat4a[2][1], (36.0));
	CompareDouble(dmat4a[2][2], (38.0));
	CompareDouble(dmat4a[2][3], (40.0));
	CompareDouble(dmat4a[3][0], (42.0));
	CompareDouble(dmat4a[3][1], (44.0));
	CompareDouble(dmat4a[3][2], (46.0));
	CompareDouble(dmat4a[3][3], (48.0));

	std::cout << "dmat4 operator-=(dmat4& a, const dmat4& b)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = dmat4((17.0), (18.0), (19.0), (20.0),
		(21.0), (22.0), (23.0), (24.0),
		(25.0), (26.0), (27.0), (28.0),
		(29.0), (30.0), (31.0), (32.0));
	dmat4a -= dmat4b;
	CompareDouble(dmat4a[0][0], (-16.0));
	CompareDouble(dmat4a[0][1], (-16.0));
	CompareDouble(dmat4a[0][2], (-16.0));
	CompareDouble(dmat4a[0][3], (-16.0));
	CompareDouble(dmat4a[1][0], (-16.0));
	CompareDouble(dmat4a[1][1], (-16.0));
	CompareDouble(dmat4a[1][2], (-16.0));
	CompareDouble(dmat4a[1][3], (-16.0));
	CompareDouble(dmat4a[2][0], (-16.0));
	CompareDouble(dmat4a[2][1], (-16.0));
	CompareDouble(dmat4a[2][2], (-16.0));
	CompareDouble(dmat4a[2][3], (-16.0));
	CompareDouble(dmat4a[3][0], (-16.0));
	CompareDouble(dmat4a[3][1], (-16.0));
	CompareDouble(dmat4a[3][2], (-16.0));
	CompareDouble(dmat4a[3][3], (-16.0));

	std::cout << "dmat4 operator*=(dmat4& a, const dmat4& b)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = dmat4((17.0), (18.0), (19.0), (20.0),
		(21.0), (22.0), (23.0), (24.0),
		(25.0), (26.0), (27.0), (28.0),
		(29.0), (30.0), (31.0), (32.0));
	dmat4a *= dmat4b;
	CompareDouble(dmat4a[0][0], (538.0));
	CompareDouble(dmat4a[0][1], (612.0));
	CompareDouble(dmat4a[0][2], (686.0));
	CompareDouble(dmat4a[0][3], (760.0));
	CompareDouble(dmat4a[1][0], (650.0));
	CompareDouble(dmat4a[1][1], (740.0));
	CompareDouble(dmat4a[1][2], (830.0));
	CompareDouble(dmat4a[1][3], (920.0));
	CompareDouble(dmat4a[2][0], (762.0));
	CompareDouble(dmat4a[2][1], (868.0));
	CompareDouble(dmat4a[2][2], (974.0));
	CompareDouble(dmat4a[2][3], (1080.0));
	CompareDouble(dmat4a[3][0], (874.0));
	CompareDouble(dmat4a[3][1], (996.0));
	CompareDouble(dmat4a[3][2], (1118.0));
	CompareDouble(dmat4a[3][3], (1240.0));

	std::cout << "dmat4 operator*(const dmat4& m, const simddouble& s)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = dmat4a * (2.0);
	CompareDouble(dmat4b[0][0], (2.0));
	CompareDouble(dmat4b[0][1], (4.0));
	CompareDouble(dmat4b[0][2], (6.0));
	CompareDouble(dmat4b[0][3], (8.0));
	CompareDouble(dmat4b[1][0], (10.0));
	CompareDouble(dmat4b[1][1], (12.0));
	CompareDouble(dmat4b[1][2], (14.0));
	CompareDouble(dmat4b[1][3], (16.0));
	CompareDouble(dmat4b[2][0], (18.0));
	CompareDouble(dmat4b[2][1], (20.0));
	CompareDouble(dmat4b[2][2], (22.0));
	CompareDouble(dmat4b[2][3], (24.0));
	CompareDouble(dmat4b[3][0], (26.0));
	CompareDouble(dmat4b[3][1], (28.0));
	CompareDouble(dmat4b[3][2], (30.0));
	CompareDouble(dmat4b[3][3], (32.0));

	std::cout << "dmat4 operator*(const simddouble& s, const dmat4& m)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = (2.0) * dmat4a;
	CompareDouble(dmat4b[0][0], (2.0));
	CompareDouble(dmat4b[0][1], (4.0));
	CompareDouble(dmat4b[0][2], (6.0));
	CompareDouble(dmat4b[0][3], (8.0));
	CompareDouble(dmat4b[1][0], (10.0));
	CompareDouble(dmat4b[1][1], (12.0));
	CompareDouble(dmat4b[1][2], (14.0));
	CompareDouble(dmat4b[1][3], (16.0));
	CompareDouble(dmat4b[2][0], (18.0));
	CompareDouble(dmat4b[2][1], (20.0));
	CompareDouble(dmat4b[2][2], (22.0));
	CompareDouble(dmat4b[2][3], (24.0));
	CompareDouble(dmat4b[3][0], (26.0));
	CompareDouble(dmat4b[3][1], (28.0));
	CompareDouble(dmat4b[3][2], (30.0));
	CompareDouble(dmat4b[3][3], (32.0));

	std::cout << "dvec4 operator*(const dvec4& v, const dmat4& m)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dvec4a = dvec4((2.0), (3.0), (4.0), (5.0));
	dvec4b = dvec4a * dmat4a;
	CompareDouble(dvec4b.x, (40.0));
	CompareDouble(dvec4b.y, (96.0));
	CompareDouble(dvec4b.z, (152.0));
	CompareDouble(dvec4b.w, (208.0));

	std::cout << "dvec4 operator*(const dmat4& m, const dvec4& v)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dvec4a = dvec4((2.0), (3.0), (4.0), (5.0));
	dvec4b = dmat4a * dvec4a;
	CompareDouble(dvec4b.x, (118.0));
	CompareDouble(dvec4b.y, (132.0));
	CompareDouble(dvec4b.z, (146.0));
	CompareDouble(dvec4b.w, (160.0));

	std::cout << "dvec4 operator*=(dvec4& v, const dmat4& m)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dvec4a = dvec4((2.0), (3.0), (4.0), (5.0));
	dvec4a *= dmat4a;
	CompareDouble(dvec4a.x, (40.0));
	CompareDouble(dvec4a.y, (96.0));
	CompareDouble(dvec4a.z, (152.0));
	CompareDouble(dvec4a.w, (208.0));

	std::cout << "simddouble determinant(const dmat2& _m)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	// det = 1*4 - 2*3 = 4 - 6 = -2
	dveca = determinant(dmat2a);
	CompareDouble(dveca, (-2.0));

	std::cout << "simddouble determinant(const dmat3& _m)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	// det = 1*(5*9 - 6*8) - 4*(2*9 - 3*8) + 7*(2*6 - 3*5) = 1*(-3) - 4*(-6) + 7*(-3) = -3 + 24 - 21 = 0
	dveca = determinant(dmat3a);
	CompareDouble(dveca, (0.0));

	std::cout << "simddouble determinant(const dmat4& _m)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dveca = determinant(dmat4a);
	CompareDouble(dveca, (0.0));

	std::cout << "dmat2 inverse(const dmat2& _m)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dmat2b = inverse(dmat2a);
	CompareDouble(dmat2b[0][0], (-2.0));
	CompareDouble(dmat2b[0][1], (1.0));
	CompareDouble(dmat2b[1][0], (1.5));
	CompareDouble(dmat2b[1][1], (-0.5));

	std::cout << "dmat3 inverse(const dmat3& _m)" << std::endl;

	std::cout << "dmat4 inverse(const dmat4& _m)" << std::endl;


	std::cout << "dmat2 transpose(const dmat2& _m)" << std::endl;
	dmat2a = dmat2((1.0), (2.0), (3.0), (4.0));
	dmat2b = transpose(dmat2a);
	// Transpose échange lignes et colonnes
	// Si columns[0] = [1, 2], columns[1] = [3, 4] (row-major interprétation)
	// Transposée: columns[0] = [1, 3], columns[1] = [2, 4]
	CompareDouble(dmat2b[0][0], (1.0));
	CompareDouble(dmat2b[0][1], (3.0));
	CompareDouble(dmat2b[1][0], (2.0));
	CompareDouble(dmat2b[1][1], (4.0));

	std::cout << "dmat3 transpose(const dmat3& _m)" << std::endl;
	dmat3a = dmat3((1.0), (2.0), (3.0),
		(4.0), (5.0), (6.0),
		(7.0), (8.0), (9.0));
	dmat3b = transpose(dmat3a);
	CompareDouble(dmat3b[0][0], (1.0));
	CompareDouble(dmat3b[0][1], (4.0));
	CompareDouble(dmat3b[0][2], (7.0));
	CompareDouble(dmat3b[1][0], (2.0));
	CompareDouble(dmat3b[1][1], (5.0));
	CompareDouble(dmat3b[1][2], (8.0));
	CompareDouble(dmat3b[2][0], (3.0));
	CompareDouble(dmat3b[2][1], (6.0));
	CompareDouble(dmat3b[2][2], (9.0));

	std::cout << "dmat4 transpose(const dmat4& _m)" << std::endl;
	dmat4a = dmat4((1.0), (2.0), (3.0), (4.0),
		(5.0), (6.0), (7.0), (8.0),
		(9.0), (10.0), (11.0), (12.0),
		(13.0), (14.0), (15.0), (16.0));
	dmat4b = transpose(dmat4a);
	CompareDouble(dmat4b[0][0], (1.0));
	CompareDouble(dmat4b[0][1], (5.0));
	CompareDouble(dmat4b[0][2], (9.0));
	CompareDouble(dmat4b[0][3], (13.0));
	CompareDouble(dmat4b[1][0], (2.0));
	CompareDouble(dmat4b[1][1], (6.0));
	CompareDouble(dmat4b[1][2], (10.0));
	CompareDouble(dmat4b[1][3], (14.0));
	CompareDouble(dmat4b[2][0], (3.0));
	CompareDouble(dmat4b[2][1], (7.0));
	CompareDouble(dmat4b[2][2], (11.0));
	CompareDouble(dmat4b[2][3], (15.0));
	CompareDouble(dmat4b[3][0], (4.0));
	CompareDouble(dmat4b[3][1], (8.0));
	CompareDouble(dmat4b[3][2], (12.0));
	CompareDouble(dmat4b[3][3], (16.0));



	std::cout << "operator>(const simddouble&, const simddouble&)" << std::endl;
	dveca = (1.0);
	dvecb = (2.0);
	dmaskResult = dveca > dvecb;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator>(const simddouble&, const double&)" << std::endl;
	dveca = (1.0);
	dmaskResult = dveca > 2.0;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator>(const double&, const simddouble&)" << std::endl;
	dveca = (3.0);
	dmaskResult = 2.0 > dveca;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator<(const simddouble&, const simddouble&)" << std::endl;
	dveca = (3.0);
	dvecb = (2.0);
	dmaskResult = dveca < dvecb;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator<(const simddouble&, const double&)" << std::endl;
	dveca = (3.0);
	dmaskResult = dveca < 2.0;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator<(const double&, const simddouble&)" << std::endl;
	dveca = (1.0);
	dmaskResult = 2.0 < dveca;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator>=(const simddouble&, const simddouble&)" << std::endl;
	dveca = (1.0);
	dvecb = (2.0);
	dmaskResult = dveca >= dvecb;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator>=(const simddouble&, const double&)" << std::endl;
	dveca = (1.0);
	dmaskResult = dveca >= 2.0;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator<=(const simddouble&, const simddouble&)" << std::endl;
	dveca = (3.0);
	dvecb = (2.0);
	dmaskResult = dveca <= dvecb;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator<=(const simddouble&, const double&)" << std::endl;
	dveca = (3.0);
	dmaskResult = dveca <= 2.0;
	CompareMaskDouble(dmaskResult, (0.0));

	std::cout << "operator==(const simddouble&, const simddouble&)" << std::endl;
	CompareMaskDouble((1.0) == (2.0), (0.0));

	std::cout << "operator==(const simddouble&, const double&)" << std::endl;
	CompareMaskDouble((1.0) == 2.0, (0.0));

	std::cout << "operator&&(const simddmask&, const simddmask&)" << std::endl;
	CompareMaskDouble((-1.0) < (0.0) && (-1.0) < (-2.0), (0.0));

	std::cout << "operator||(const simddmask&, const simddmask&)" << std::endl;
	CompareMaskDouble((-1.0) > (0.0) || (-1.0) < (-2.0), (0.0));

	std::cout << "int maskAll(const simddmask & _dmask)" << std::endl;
#if defined(USE_AVX512)
	dmaskResult = 0xFFFF;
#elif defined (USE_SCALAR)
	dmaskResult = 1;
#else
	dmaskResult = (-1.0);
#endif
	if (maskAll(dmaskResult) != 1) {
		std::cout << "maskAll failed" << std::endl;
		exit(0);
	}
#if defined(USE_AVX512)
	dmaskResult = 0;
#elif defined (USE_SCALAR)
	dmaskResult = 0;
#else
	dmaskResult = (0.0);
#endif
	if (maskAll(dmaskResult) != 0) {
		std::cout << "maskAll failed" << std::endl;
		exit(0);
	}
#ifndef USE_SCALAR
#if !(defined(USE_AVX512))
	dmaskResult = simd_load_double(tabdMask);
#else
	dmaskResult = testdmask;
#endif
	if (maskAll(dmaskResult) != 0) {
		std::cout << "maskAll failed" << std::endl;
		exit(0);
	}
#endif

	std::cout << "int maskNone(const simddmask & _dmask)" << std::endl;
#if defined(USE_AVX512)
	dmaskResult = 0xFFFF;
#elif defined (USE_SCALAR)
	dmaskResult = 1;
#else
	dmaskResult = (-1.0);
#endif
	if (maskNone(dmaskResult) != 0) {
		std::cout << "maskNone failed" << std::endl;
		exit(0);
	}
#if defined(USE_AVX512)
	dmaskResult = 0;
#elif defined (USE_SCALAR)
	dmaskResult = 0;
#else
	dmaskResult = (0.0);
#endif
	if (maskNone(dmaskResult) != 1) {
		std::cout << "maskNone failed" << std::endl;
		exit(0);
	}
#ifndef USE_SCALAR
#if !(defined(USE_AVX512))
	dmaskResult = simd_load_double(tabdMask);
#else
	dmaskResult = testdmask;
#endif
	if (maskNone(dmaskResult) != 0) {
		std::cout << "maskNone failed" << std::endl;
		exit(0);
	}
#endif



#pragma endregion


#endif // COMPILE_TESTS
}

inline void TestsInt()
{

#ifdef COMPILE_TESTS

#pragma region int tests

	alignas(64) const int tabiVal[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2 };
	alignas(64) const int tabiValNeg[16] = { 1, 2, 3, 4, 5, 6, 7, 8, -8, -7, -6, -5, -4, -3, -2, -1 };
	alignas(64) const int tabiValMin[16] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
	alignas(64) const int tabiValMax[16] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };


	alignas(64) const int tabiMask[16] = { 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1 };
#if defined(USE_AVX512)
	alignas(64) const __mmask16 testimask = 0b0101010101010101;
#elif defined (USE_SCALAR)
	const int testimask = 1;
#else
	simdimask testimask = simd_load_int(tabiMask);
#endif
	simdimask imaskResult;

	alignas(64) int tabiValResult[16] = { 0 };

	simdint iveca, ivecb, ivecc;
	ivec2 ivec2a, ivec2b, ivec2c;
	ivec3 ivec3a, ivec3b, ivec3c;
	ivec4 ivec4a, ivec4b, ivec4c;

	std::cout << " simdint abs(const simdint& _a)" << std::endl;
	iveca = simd_load_int(tabiMask);
	ivecb = abs(iveca);
	FillTabResultInt(tabiMask, tabiValResult, [](const float& val, const int& idx) { return std::abs(val); });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << " ivec2 abs(const ivec2& _a)" << std::endl;
	ivec2a = { simd_load_int(tabiMask),  simd_load_int(tabiMask) };
	ivec2b = abs(ivec2a);
	FillTabResultInt(tabiMask, tabiValResult, [](const float& val, const int& idx) { return std::abs(val); });
	CompareInt(ivec2b.x, simd_load_int(tabiValResult));
	CompareInt(ivec2b.y, simd_load_int(tabiValResult));

	std::cout << " ivec3 abs(const ivec3& _a)" << std::endl;
	ivec3a = { simd_load_int(tabiMask),  simd_load_int(tabiMask),  simd_load_int(tabiMask) };
	ivec3b = abs(ivec3a);
	FillTabResultInt(tabiMask, tabiValResult, [](const float& val, const int& idx) { return std::abs(val); });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << " ivec4 abs(const ivec4& _a)" << std::endl;
	ivec4a = { simd_load_int(tabiMask),  simd_load_int(tabiMask),  simd_load_int(tabiMask),  simd_load_int(tabiMask) };
	ivec4b = abs(ivec4a);
	FillTabResultInt(tabiMask, tabiValResult, [](const float& val, const int& idx) { return std::abs(val); });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));
	CompareInt(ivec4b.y, simd_load_int(tabiValResult));
	CompareInt(ivec4b.z, simd_load_int(tabiValResult));
	CompareInt(ivec4b.w, simd_load_int(tabiValResult));

	std::cout << " simdint blendv(const simdint& _a, const simdint& _b, const simdimask& _mask)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = simd_load_int(tabiMask);

	ivecc = blendv(ivecb, iveca, testimask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabiValResult[i] = tabiMask[i] < 0 ? tabiVal[i] : tabiMask[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabiValResult[i] = tabiMask[i] < 0 ? tabiMask[i] : tabiVal[i];
	}
#elif defined(USE_SCALAR)
	tabiValResult[0] = tabiMask[0] == 0 ? tabiVal[0] : tabiMask[0];
#endif
	CompareInt(ivecc, simd_load_int(tabiValResult));

	std::cout << " ivec2 blendv(const ivec2& _a, const ivec2& _b, const simdimask& _mask)" << std::endl;
	ivec2a = { simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec2b = { simd_load_int(tabiMask),  simd_load_int(tabiMask) };
	ivec2c = blendv(ivec2b, ivec2a, testimask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabiValResult[i] = tabiMask[i] < 0 ? tabiVal[i] : tabiMask[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabiValResult[i] = tabiMask[i] < 0 ? tabiMask[i] : tabiVal[i];
	}
#elif defined(USE_SCALAR)
	tabiValResult[0] = tabiMask[0] == 0 ? tabiVal[0] : tabiMask[0];
#endif
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec3 blendv(const ivec3& _a, const ivec3& _b, const simdimask& _mask)" << std::endl;
	ivec3a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec3b = { simd_load_int(tabiMask),  simd_load_int(tabiMask),  simd_load_int(tabiMask) };
	ivec3c = blendv(ivec3b, ivec3a, testimask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabiValResult[i] = tabiMask[i] < 0 ? tabiVal[i] : tabiMask[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabiValResult[i] = tabiMask[i] < 0 ? tabiMask[i] : tabiVal[i];
	}
#elif defined(USE_SCALAR)
	tabiValResult[0] = tabiMask[0] == 0 ? tabiVal[0] : tabiMask[0];
#endif
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec4 blendv(const ivec4& _a, const ivec4& _b, const simdimask& _mask)" << std::endl;
	ivec4a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec4b = { simd_load_int(tabiMask),  simd_load_int(tabiMask),  simd_load_int(tabiMask),  simd_load_int(tabiMask) };
	ivec4c = blendv(ivec4b, ivec4a, testimask);
#if !(defined(USE_SCALAR) || defined(USE_AVX512))
	for (int i = 0; i < simdwidth; i++)
	{
		tabiValResult[i] = tabiMask[i] < 0 ? tabiVal[i] : tabiMask[i];
	}
#elif (defined USE_AVX512)
	for (int i = 0; i < simdwidth; i++)
	{
		tabiValResult[i] = tabiMask[i] < 0 ? tabiMask[i] : tabiVal[i];
	}
#elif defined(USE_SCALAR)
	tabiValResult[0] = tabiMask[0] == 0 ? tabiVal[0] : tabiMask[0];
#endif
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));

	std::cout << " simdint max(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = (5);
	ivecc = max(iveca, ivecb);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivecc, simd_load_int(tabiValResult));

	std::cout << " ivec2 max(const ivec2& _a, const simdint& _b)" << std::endl;
	ivec2a = { simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec2c = max(ivec2a, (5));
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec2 max(const simdint& _a, const ivec2& _b)" << std::endl;
	ivec2a = { simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec2c = max((5), ivec2a);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec2 max(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = { simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec2b = { (5),  (5) };
	ivec2c = max(ivec2a, ivec2b);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec3 max(const ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec3c = max(ivec3a, (5));
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec3 max(const simdint& _a, const ivec3& _b)" << std::endl;
	ivec3a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec3c = max((5), ivec3a);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec3 max(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec3b = { (5),  (5),  (5) };
	ivec3c = max(ivec3a, ivec3b);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec4 max(const ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec4c = max(ivec4a, (5));
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));

	std::cout << " ivec4 max(const simdint& _a, const ivec4& _b)" << std::endl;
	ivec4a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec4c = max((5), ivec4a);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));

	std::cout << " ivec4 max(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec4b = { (5),  (5),  (5),  (5) };
	ivec4c = max(ivec4a, ivec4b);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::max(val, 5); });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));

	std::cout << " simdint min(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = (5);
	ivecc = min(iveca, ivecb);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivecc, simd_load_int(tabiValResult));

	std::cout << " ivec2 min(const ivec2& _a, const simdint& _b)" << std::endl;
	ivec2a = { simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec2c = min(ivec2a, (5));
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec2 min(const simdint& _a, const ivec2& _b)" << std::endl;
	ivec2a = { simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec2c = min((5), ivec2a);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec2 min(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = { simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec2b = { (5),  (5) };
	ivec2c = min(ivec2a, ivec2b);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec3 min(const ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec3c = min(ivec3a, (5));
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec3 min(const simdint& _a, const ivec3& _b)" << std::endl;
	ivec3a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec3c = min((5), ivec3a);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec3 min(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec3b = { (5),  (5),  (5) };
	ivec3c = min(ivec3a, ivec3b);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec4 min(const ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec4c = min(ivec4a, (5));
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));

	std::cout << " ivec4 min(const simdint& _a, const ivec4& _b)" << std::endl;
	ivec4a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec4c = min((5), ivec4a);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));

	std::cout << " ivec4 min(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec4b = { (5),  (5),  (5),  (5) };
	ivec4c = min(ivec4a, ivec4b);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return std::min(val, 5); });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));

	std::cout << " simdint clamp(const simdint& _v, const simdint& _minVal, const simdint& _maxVal)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = clamp(iveca, simd_load_int(tabiValMin), simd_load_int(tabiValMax));
	FillTabResultInt(tabiVal, tabiValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << " ivec2 clamp(const ivec2& _v, const simdint& _minVal, const simdint& _maxVal)" << std::endl;
	ivec2a = { simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec2c = clamp(ivec2a, simd_load_int(tabiValMin), simd_load_int(tabiValMax));
	FillTabResultInt(tabiVal, tabiValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec2 clamp(const ivec2& _v, const ivec2& _minVal, const ivec2& _maxVal)" << std::endl;
	ivec2a = { simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec2b = { simd_load_int(tabiValMin),  simd_load_int(tabiValMin) };
	ivec2c = { simd_load_int(tabiValMax),  simd_load_int(tabiValMax) };
	ivec2c = clamp(ivec2a, ivec2b, ivec2c);
	FillTabResultInt(tabiVal, tabiValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec3 clamp(const ivec3& _v, const simdint& _minVal, const simdint& _maxVal)" << std::endl;
	ivec3a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec3c = clamp(ivec3a, simd_load_int(tabiValMin), simd_load_int(tabiValMax));
	FillTabResultInt(tabiVal, tabiValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec3 clamp(const ivec3& _v, const ivec3& _minVal, const ivec3& _maxVal)" << std::endl;
	ivec3a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec3b = { simd_load_int(tabiValMin),  simd_load_int(tabiValMin),  simd_load_int(tabiValMin) };
	ivec3c = { simd_load_int(tabiValMax),  simd_load_int(tabiValMax),  simd_load_int(tabiValMax) };
	ivec3c = clamp(ivec3a, ivec3b, ivec3c);
	FillTabResultInt(tabiVal, tabiValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec4 clamp(const ivec4& _v, const simdint& _minVal, const simdint& _maxVal)" << std::endl;
	ivec4a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec4c = clamp(ivec4a, simd_load_int(tabiValMin), simd_load_int(tabiValMax));
	FillTabResultInt(tabiVal, tabiValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));

	std::cout << " ivec4 clamp(const ivec4& _v, const ivec4& _minVal, const ivec4& _maxVal)" << std::endl;
	ivec4a = { simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal),  simd_load_int(tabiVal) };
	ivec4b = { simd_load_int(tabiValMin),  simd_load_int(tabiValMin),  simd_load_int(tabiValMin),  simd_load_int(tabiValMin) };
	ivec4c = { simd_load_int(tabiValMax),  simd_load_int(tabiValMax),  simd_load_int(tabiValMax),  simd_load_int(tabiValMax) };
	ivec4c = clamp(ivec4a, ivec4b, ivec4c);
	FillTabResultInt(tabiVal, tabiValResult, [](const float& val, const int& idx) { return std::max(2.0f, std::min(val, 10.0f)); });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));

	std::cout << " simdint sign(const simdint& _a)" << std::endl;
	iveca = simd_load_int(tabiValNeg);
	ivecc = sign(iveca);
	FillTabResultInt(tabiValNeg, tabiValResult, [](const int& val, const int& idx) { return val > 0 ? 1 : (val < 0 ? -1 : 0); });
	CompareInt(ivecc, simd_load_int(tabiValResult));

	std::cout << " ivec2 sign(const ivec2& _a)" << std::endl;
	ivec2a = { simd_load_int(tabiValNeg),  simd_load_int(tabiValNeg) };
	ivec2c = sign(ivec2a);
	FillTabResultInt(tabiValNeg, tabiValResult, [](const int& val, const int& idx) { return val > 0 ? 1 : (val < 0 ? -1 : 0); });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << " ivec3 sign(const ivec3& _a)" << std::endl;
	ivec3a = { simd_load_int(tabiValNeg),  simd_load_int(tabiValNeg),  simd_load_int(tabiValNeg) };
	ivec3c = sign(ivec3a);
	FillTabResultInt(tabiValNeg, tabiValResult, [](const int& val, const int& idx) { return val > 0 ? 1 : (val < 0 ? -1 : 0); });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << " ivec4 sign(const ivec4& _a)" << std::endl;
	ivec4a = { simd_load_int(tabiValNeg),  simd_load_int(tabiValNeg),  simd_load_int(tabiValNeg),  simd_load_int(tabiValNeg) };
	ivec4c = sign(ivec4a);
	FillTabResultInt(tabiValNeg, tabiValResult, [](const int& val, const int& idx) { return val > 0 ? 1 : (val < 0 ? -1 : 0); });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));
	CompareInt(ivec4c.y, simd_load_int(tabiValResult));
	CompareInt(ivec4c.z, simd_load_int(tabiValResult));
	CompareInt(ivec4c.w, simd_load_int(tabiValResult));



	std::cout << "simdint operator-(const simdint& _a)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = -iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return -val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint& operator++(simdint& _a)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = ++iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 1; });
	CompareInt(iveca, simd_load_int(tabiValResult));
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint& operator--(simdint& _a)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = --iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 1; });
	CompareInt(iveca, simd_load_int(tabiValResult));
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator++(simdint& _a, int)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca++;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 1; });
	CompareInt(iveca, simd_load_int(tabiValResult));
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator--(simdint& _a, int)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca--;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 1; });
	CompareInt(iveca, simd_load_int(tabiValResult));
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator+(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca + iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator-(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca - iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator*(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca * iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator/(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca / iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator+=(simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	iveca += iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + val; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "simdint operator-=(simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	iveca -= iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - val; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "simdint operator*=(simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	iveca *= iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * val; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "simdint operator/=(simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	iveca /= iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / val; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "simdint operator+(const simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca + 1;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 1; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator-(const simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca - 1;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 1; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator*(const simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca * 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 2; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator/(const simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca / 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator+(const int& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = 1 + iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 1 + val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator-(const int& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = 1 - iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 1 - val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator*(const int& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = 2 * iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 2 * val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator/(const int& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = 2 / iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 2 / val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "simdint operator+=(simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	iveca += 1;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 1; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "simdint operator-=(simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	iveca -= 1;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 1; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "simdint operator*=(simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	iveca *= 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 2; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "simdint operator/=(simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	iveca /= 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator+(const int& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = 2 + iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 2 + val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator-(const int& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = 10 - iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 10 - val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator*(const int& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = 3 * iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 3 * val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator/(const int& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = 100 / iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 100 / val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator%(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecc = (3);
	ivecb = iveca % ivecc;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val % 3; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator%=(simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecc = (3);
	iveca %= ivecc;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val % 3; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator%(const simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca % 5;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val % 5; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator%=(simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	iveca %= 5;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val % 5; });
	CompareInt(iveca, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator-(const ivec2& _a)" << std::endl;
	ivec2 ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2A = -ivec2A;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return -val; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator+(const ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2 ivec2B = ivec2A + 5;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val + 5; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator-(const ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2B = ivec2A - 3;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val - 3; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator*(const ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2B = ivec2A * 2;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val * 2; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator/(const ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2B = ivec2A / 2;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator%(const ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2B = ivec2A % 3;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val % 3; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator+(const int& _a, const ivec2& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2B = 10 + ivec2A;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 10 + val; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator-(const int& _a, const ivec2& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2B = 10 - ivec2A;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 10 - val; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator*(const int& _a, const ivec2& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2B = 4 * ivec2A;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 4 * val; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator/(const int& _a, const ivec2& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2B = 100 / ivec2A;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 100 / val; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator+=(ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2A += 7;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val + 7; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator-=(ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2A -= 2;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val - 2; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator*=(ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2A *= 3;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val * 3; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator/=(ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2A /= 2;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator%=(ivec2& _a, const int& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2A %= 4;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val % 4; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator+(const ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (3);
	ivec2B = ivec2A + iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val + 3; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator-(const ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (2);
	ivec2B = ivec2A - iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val - 2; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator*(const ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (4);
	ivec2B = ivec2A * iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val * 4; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator/(const ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (2);
	ivec2B = ivec2A / iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator%(const ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec2B = ivec2A % iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val % 5; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator+(const simdint& _a, const ivec2& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (6);
	ivec2B = iveca + ivec2A;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 6 + val; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator-(const simdint& _a, const ivec2& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (20);
	ivec2B = iveca - ivec2A;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 20 - val; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator*(const simdint& _a, const ivec2& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec2B = iveca * ivec2A;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 5 * val; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator/(const simdint& _a, const ivec2& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (100);
	ivec2B = iveca / ivec2A;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return 100 / val; });
	CompareInt(ivec2B.x, simd_load_int(tabiValResult));
	CompareInt(ivec2B.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator+=(ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (8);
	ivec2A += iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val + 8; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator-=(ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (3);
	ivec2A -= iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val - 3; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator*=(ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (6);
	ivec2A *= iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val * 6; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator/=(ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (2);
	ivec2A /= iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator%=(ivec2& _a, const simdint& _b)" << std::endl;
	ivec2A = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (7);
	ivec2A %= iveca;
	FillTabResultInt((const int*)tabiVal, (int*)tabiValResult, [](const int& val, const int& idx) { return val % 7; });
	CompareInt(ivec2A.x, simd_load_int(tabiValResult));
	CompareInt(ivec2A.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator+(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2c = ivec2a + ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 5; });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator-(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2c = ivec2a - ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 5; });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator*(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2c = ivec2a * ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 5; });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator/(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2c = ivec2a / ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 5; });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator%(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2c = ivec2a % ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % 5; });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));
	CompareInt(ivec2c.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator+=(ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2a += ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 5; });
	CompareInt(ivec2a.x, simd_load_int(tabiValResult));
	CompareInt(ivec2a.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator-=(ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2a -= ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 5; });
	CompareInt(ivec2a.x, simd_load_int(tabiValResult));
	CompareInt(ivec2a.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator*=(ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2a *= ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 5; });
	CompareInt(ivec2a.x, simd_load_int(tabiValResult));
	CompareInt(ivec2a.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator/=(ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2a /= ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 5; });
	CompareInt(ivec2a.x, simd_load_int(tabiValResult));
	CompareInt(ivec2a.y, simd_load_int(tabiValResult));

	std::cout << "ivec2 operator%=(ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2a %= ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % 5; });
	CompareInt(ivec2a.x, simd_load_int(tabiValResult));
	CompareInt(ivec2a.y, simd_load_int(tabiValResult));

	// Tests for ivec3 operators
	std::cout << "ivec3 operator-(const ivec3& _a)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = -ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return -val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator+(const ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3a + 5;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 5; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator-(const ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3a - 3;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 3; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator*(const ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3a * 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 2; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator/(const ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3a / 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator%(const ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3a % 3;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % 3; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator+(const int& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = 10 + ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 10 + val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator-(const int& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = 20 - ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 20 - val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator*(const int& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = 3 * ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 3 * val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator/(const int& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = 100 / ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 100 / val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator+=(ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a += 7;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 7; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator-=(ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a -= 4;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 4; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator*=(ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a *= 3;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 3; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator/=(ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a /= 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator%=(ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a %= 5;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % 5; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator+(const ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = 5;
	ivec3b = ivec3a + iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 5; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator-(const ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3b = ivec3a - iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 5; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator*(const ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3b = ivec3a * iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 5; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator/(const ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3b = ivec3a / iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 5; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator%(const ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3b = ivec3a % iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % 5; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator+(const simdint& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3b = iveca + ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 5 + val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator-(const simdint& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3b = iveca - ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 5 - val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator*(const simdint& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3b = iveca * ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 5 * val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator/(const simdint& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3b = iveca / ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 5 / val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));
	CompareInt(ivec3b.y, simd_load_int(tabiValResult));
	CompareInt(ivec3b.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator+=(ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3a += iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 5; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator-=(ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3a -= iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 5; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator*=(ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3a *= iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 5; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator/=(ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3a /= iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 5; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "ivec3 operator%=(ivec3& _a, const simdint& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	iveca = (5);
	ivec3a %= iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % 5; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator+(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3c = ivec3a + ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + val; });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator-(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3c = ivec3a - ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - val; });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator*(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3c = ivec3a * ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * val; });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator/(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3c = ivec3a / ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / val; });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator%(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3c = ivec3a % ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % val; });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));
	CompareInt(ivec3c.y, simd_load_int(tabiValResult));
	CompareInt(ivec3c.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator+=(ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a += ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + val; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator-=(ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a -= ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - val; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator*=(ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a *= ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * val; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator/=(ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a /= ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / val; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator%=(ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3a %= ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % val; });
	CompareInt(ivec3a.x, simd_load_int(tabiValResult));
	CompareInt(ivec3a.y, simd_load_int(tabiValResult));
	CompareInt(ivec3a.z, simd_load_int(tabiValResult));

	// ivec4 unary operator
	std::cout << "inline ivec4 operator-(const ivec4& _a)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = -ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return -val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));
	CompareInt(ivec4b.y, simd_load_int(tabiValResult));
	CompareInt(ivec4b.z, simd_load_int(tabiValResult));
	CompareInt(ivec4b.w, simd_load_int(tabiValResult));

	// ivec4 with scalar
	std::cout << "inline ivec4 operator+(const ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a + 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 2; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));
	CompareInt(ivec4b.y, simd_load_int(tabiValResult));
	CompareInt(ivec4b.z, simd_load_int(tabiValResult));
	CompareInt(ivec4b.w, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator-(const ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a - 1;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 1; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator*(const ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a * 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 2; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator/(const ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a / 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator%(const ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a % 3;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % 3; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator+(const int& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = 2 + ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 2 + val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator-(const int& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = 10 - ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 10 - val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator*(const int& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = 2 * ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 2 * val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator/(const int& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = 10 / ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return 10 / val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator+=(ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a += 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + 2; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator-=(ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a -= 1;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - 1; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator*=(ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a *= 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * 2; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator/=(ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a /= 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / 2; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator%=(ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a %= 3;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % 3; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	// ivec4 with simdint
	std::cout << "inline ivec4 operator+(const ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a + simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator-(const ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a - simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator*(const ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a * simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator/(const ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a / simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator%(const ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a % simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator+(const simdint& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = simd_load_int(tabiVal) + ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator-(const simdint& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = simd_load_int(tabiVal) - ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator*(const simdint& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = simd_load_int(tabiVal) * ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator/(const simdint& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = simd_load_int(tabiVal) / ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator+=(ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a += simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator-=(ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a -= simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator*=(ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a *= simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator/=(ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a /= simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator%=(ivec4& _a, const simdint& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a %= simd_load_int(tabiVal);
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	// ivec4 with ivec4
	std::cout << "inline ivec4 operator+(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4c = ivec4a + ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + val; });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator-(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4c = ivec4a - ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - val; });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator*(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4c = ivec4a * ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * val; });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator/(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4c = ivec4a / ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / val; });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator%(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4c = ivec4a % ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % val; });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator+=(ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a += ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val + val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator-=(ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a -= ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val - val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator*=(ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a *= ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val * val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator/=(ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a /= ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val / val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator%=(ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4a %= ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val % val; });
	CompareInt(ivec4a.x, simd_load_int(tabiValResult));

	// Bitwise operators
	std::cout << "inline simdint operator&(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = (5);
	ivecc = iveca & ivecb;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val & 5; });
	CompareInt(ivecc, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator&(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2c = ivec2a & ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val & 5; });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator&(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3((5), (5), (5));
	ivec3c = ivec3a & ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val & 5; });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator&(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4((5), (5), (5), (5));
	ivec4c = ivec4a & ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val & 5; });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator|(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = (5);
	ivecc = iveca | ivecb;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val | 5; });
	CompareInt(ivecc, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator|(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2c = ivec2a | ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val | 5; });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator|(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3((5), (5), (5));
	ivec3c = ivec3a | ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val | 5; });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator|(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4((5), (5), (5), (5));
	ivec4c = ivec4a | ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val | 5; });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator^(const simdint& _a, const simdint& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = (5);
	ivecc = iveca ^ ivecb;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val ^ 5; });
	CompareInt(ivecc, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator^(const ivec2& _a, const ivec2& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2((5), (5));
	ivec2c = ivec2a ^ ivec2b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val ^ 5; });
	CompareInt(ivec2c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator^(const ivec3& _a, const ivec3& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3((5), (5), (5));
	ivec3c = ivec3a ^ ivec3b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val ^ 5; });
	CompareInt(ivec3c.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator^(const ivec4& _a, const ivec4& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4((5), (5), (5), (5));
	ivec4c = ivec4a ^ ivec4b;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val ^ 5; });
	CompareInt(ivec4c.x, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator~(const simdint& _a)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = ~iveca;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return ~val; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator~(const ivec2& _a)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ~ivec2a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return ~val; });
	CompareInt(ivec2b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator~(const ivec3& _a)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ~ivec3a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return ~val; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator~(const ivec4& _a)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ~ivec4a;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return ~val; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator<<(const simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca << 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val << 2; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator<<(const ivec2& _a, const int& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2a << 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val << 2; });
	CompareInt(ivec2b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator<<(const ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3a << 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val << 2; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator<<(const ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a << 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val << 2; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "inline simdint operator>>(const simdint& _a, const int& _b)" << std::endl;
	iveca = simd_load_int(tabiVal);
	ivecb = iveca >> 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val >> 2; });
	CompareInt(ivecb, simd_load_int(tabiValResult));

	std::cout << "inline ivec2 operator>>(const ivec2& _a, const int& _b)" << std::endl;
	ivec2a = ivec2(simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec2b = ivec2a >> 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val >> 2; });
	CompareInt(ivec2b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec3 operator>>(const ivec3& _a, const int& _b)" << std::endl;
	ivec3a = ivec3(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec3b = ivec3a >> 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val >> 2; });
	CompareInt(ivec3b.x, simd_load_int(tabiValResult));

	std::cout << "inline ivec4 operator>>(const ivec4& _a, const int& _b)" << std::endl;
	ivec4a = ivec4(simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal), simd_load_int(tabiVal));
	ivec4b = ivec4a >> 2;
	FillTabResultInt(tabiVal, tabiValResult, [](const int& val, const int& idx) { return val >> 2; });
	CompareInt(ivec4b.x, simd_load_int(tabiValResult));

	std::cout << "operator>(const simdint&, const simdint&)" << std::endl;
	iveca = (1);
	ivecb = (2);
	imaskResult = iveca > ivecb;
	CompareMaskInt(imaskResult, (0));
	iveca = (3);
	ivecb = (2);
	imaskResult = iveca > ivecb;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator> failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator> failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator>(const simdint&, const int&)" << std::endl;
	iveca = (1);
	imaskResult = iveca > 2;
	CompareMaskInt(imaskResult, (0));
	iveca = (3);
	imaskResult = iveca > 2;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator> failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator> failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator>(const int&, const simdint&)" << std::endl;
	iveca = (3);
	imaskResult = 2 > iveca;
	CompareMaskInt(imaskResult, (0));
	iveca = (1);
	imaskResult = 2 > iveca;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator> failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator> failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator<(const simdint&, const simdint&)" << std::endl;
	iveca = (3);
	ivecb = (2);
	imaskResult = iveca < ivecb;
	CompareMaskInt(imaskResult, (0));
	iveca = (1);
	ivecb = (2);
	imaskResult = iveca < ivecb;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator< failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator< failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator<(const simdint&, const int&)" << std::endl;
	iveca = (3);
	imaskResult = iveca < 2;
	CompareMaskInt(imaskResult, (0));
	iveca = (1);
	imaskResult = iveca < 2;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator< failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator< failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator<(const int&, const simdint&)" << std::endl;
	iveca = (1);
	imaskResult = 2 < iveca;
	CompareMaskInt(imaskResult, (0));
	iveca = (3);
	imaskResult = 2 < iveca;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator< failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator< failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator>=(const simdint&, const simdint&)" << std::endl;
	iveca = (1);
	ivecb = (2);
	imaskResult = iveca >= ivecb;
	CompareMaskInt(imaskResult, (0));
	iveca = (2);
	ivecb = (2);
	imaskResult = iveca >= ivecb;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator>= failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator>= failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator>=(const simdint&, const int&)" << std::endl;
	iveca = (1);
	imaskResult = iveca >= 2;
	CompareMaskInt(imaskResult, (0));
	iveca = (2);
	imaskResult = iveca >= 2;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator>= failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator>= failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator<=(const simdint&, const simdint&)" << std::endl;
	iveca = (3);
	ivecb = (2);
	imaskResult = iveca <= ivecb;
	CompareMaskInt(imaskResult, (0));
	iveca = (2);
	ivecb = (2);
	imaskResult = iveca <= ivecb;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator<= failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator<= failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator<=(const simdint&, const int&)" << std::endl;
	iveca = (3);
	imaskResult = iveca <= 2;
	CompareMaskInt(imaskResult, (0));
	iveca = (2);
	imaskResult = iveca <= 2;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator<= failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator<= failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator==(const simdint&, const simdint&)" << std::endl;
	iveca = (1);
	ivecb = (2);
	imaskResult = iveca == ivecb;
	CompareMaskInt(imaskResult, (0));
	iveca = (2);
	ivecb = (2);
	imaskResult = iveca == ivecb;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator== failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator== failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator==(const simdint&, const int&)" << std::endl;
	iveca = (1);
	imaskResult = iveca == 2;
	CompareMaskInt(imaskResult, (0));
	iveca = (2);
	imaskResult = iveca == 2;
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator== failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator== failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator&&(const simdimask&, const simdint&)" << std::endl;
	iveca = (-1);
	ivecb = (0);
	imaskResult = (iveca < (0)) && (ivecb < (-2));
	CompareMaskInt(imaskResult, (0));
	iveca = (-1);
	ivecb = (-3);
	imaskResult = (iveca < (0)) && (ivecb < (-2));
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator&& failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator&& failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif

	std::cout << "operator||(const simdint&, const simdint&)" << std::endl;
	iveca = (-1);
	ivecb = (0);
	imaskResult = (iveca > (0)) || (ivecb < (-2));
	CompareMaskInt(imaskResult, (0));
	iveca = (-1);
	ivecb = (-3);
	imaskResult = (iveca < (0)) || (ivecb < (-2));
#if defined(USE_AVX512)
	if (imaskResult != 0xFFFF) {
		std::cout << "operator|| failed" << std::endl;
		exit(0);
	}
#elif defined(USE_SCALAR)
	if (imaskResult != 1) {
		std::cout << "operator|| failed" << std::endl;
		exit(0);
	}
#else
	CompareMaskInt(imaskResult, (-1));
#endif



#pragma endregion int tests

#endif // COMPILE_TESTS
}

inline void Tests()
{
	TestsFloat();
	TestsDouble();
	TestsInt();
}

#endif
