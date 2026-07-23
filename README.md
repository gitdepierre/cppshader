# Cppshader

## Bringing the fun of GLSL to native C++

cppshader is a header-only C++ library that brings much of GLSL syntax and its
programming model into regular C++ code. It reimplements many GLSL features in
software, provides vector and matrix types, and includes a large set of built-
in functions backed by SIMD intrinsics such as SSE4.1 and AVX2.

As a result, you may be able to port GLSL shaders easily, including shader code
from Shadertoy, to pure C++ with only small source changes.

---

## Table of Contents

- [Getting Started](#getting-started)
- [Backend Selection](#backend-selection)
- [Core Types](#core-types)
  - [simdfloat: the SIMD-enabled math type of cppshader](#simdfloat-the-SIMD-enabled-math-type-of-cppshader)
  - [Vector Types](#vector-types)
  - [Matrix Types](#matrix-types)
- [Swizzling](#swizzling)
  - [Swizzle-Based Construction](#swizzle-based-construction)
- [Arithmetic and Operators](#arithmetic-and-operators)
- [Load and Store](#load-and-store)
- [Built-in Functions](#built-in-functions)
  - [Math](#math)
  - [Trigonometry](#trigonometry)
  - [Exponential and Logarithm](#exponential-and-logarithm)
  - [Range and Interpolation](#range-and-interpolation)
  - [Geometric](#geometric)
  - [Min and Max](#min-and-max)
- [Conditional Statements](#conditional-statements)
- [Displaying Data](#displaying-data)
- [Full Shader Examples](#full-shader-examples)
- [Building Samples](#building-samples)
- [License](#license)

---

## Getting Started

Include the single-header library present in "amalgamation" folder. 
It has no dependencies beyond having a compiler that supports 
the SIMD width you want (SSE4.1, AVX2, or AVX512).

```cpp
#include "cppshader.h"

int main()
{

}
```

From there, the syntax looks close to GLSL, with some x86 SIMD-specific bits.

---

## Backend Selection

Pick your SIMD width by uncommenting exactly one define near the top of
`cppshader.h`:

```cpp
//#define USE_AVX512   // 16 floats per lane, requires AVX-512
//#define USE_AVX2     // 8 floats per lane, requires AVX2
#define USE_SSE41       // 4 floats per lane, requires SSE4
//#define USE_SCALAR   // 1 float per lane, no intrinsics
```

The default is `USE_SSE41`.

The selected backend sets `simdwidth` and the related `simd*` macros
automatically, so the same user code can be compiled for different backends
without source changes.

---

## Core Types

### `simdfloat`: the SIMD-enabled math type of cppshader

`simdfloat` is the fundamental datatype of cppshader. It represents `simdwidth` packed
floating-point values and can often be used much like a regular C++ `float`, while holding multiple instances of primitive scalar types.
The examples below assume that `USE_SSE41` is enabled.

Some basic uses:

```cpp
simdfloat a = 1.0f;  // broadcast 1.0f to every lane
simdfloat b = simd_set_float(1.0f, 2.0f, 3.0f, 4.0f); // not recommended, load/store are better

simdfloat c = a + b;  // four additions in one instruction with SSE
simdfloat d = sin(c); // four sine evaluations in one instruction with SSE
```

Alongside `simdfloat`, two companion types are available:

- `simddouble`: double-precision SIMD scalar type; use `halfsimdwidth` for its
  lane count.
- `simdint`: 32-bit integer SIMD scalar type.

Boolean vectors and unsigned integer vectors aren't provided though, and likely
won't be.

Useful broadcast constants are also provided:

```cpp
static const simdfloat SIMDZERO = 0.0f;
static const simdfloat SIMDONE = 1.0f;
static const simdfloat SIMDPI = 3.1415927f;
// search for "useful constants" in cppshader.h to see the rest.
```

When using SIMD internal types, operations are parallelized at instruction
level but don't see each others. Lanes are independent. For example, with
`USE_AVX2`, a dot product on `simdfloat` values does not compute the dot product
of two 8D vectors. Instead, it performs eight independent dot products in
parallel and returns a `simdfloat` containing those eight results.

---

### Vector Types

cppshader provides vector types similar to GLSL, with the same names. Each
component is a `simdfloat`, so a `vec3` stores three SIMD values at once.

| Type | Components |
|---|---|
| `vec2` | `x, y` or `r, g`, or `s, t` |
| `vec3` | `x, y, z` or `r, g, b`, or `s, t, p` |
| `vec4` | `x, y, z, w` or `r, g, b, a`, or `s, t, p, q` |
| `dvec2/3/4` | same layout, double precision |
| `ivec2/3/4` | same layout, integer |

Construction mirrors GLSL, so you can mix `float` literals and `simdfloat`
values:

```cpp
vec3 a(1.0f, 2.0f, 3.0f);  // broadcast each component
vec3 b(0.5f);              // all components = 0.5

simdfloat t = simd_set_float(0.1f, 0.2f, 0.3f, 0.4f); // not recommended
vec2 uv(t, 0.8f);          // per-lane x, broadcast y

vec4 color(uv, 0.0f, 1.0f); // vec4 from vec2 plus two scalars
```

Single-component access is direct:

```cpp
simdfloat len = length(a);
a.z = len;
```

Index access is also supported:

```cpp
simdfloat first = a[0];  // same as a.x
```

For multi-component read or write access, see the swizzling section below.

Double and integer vector variants are also available: `dvec2/3/4` and
`ivec2/3/4`.

---

### Matrix Types

cppshader also provides square matrix types following GLSL naming conventions.

| Type | Columns |
|---|---|
| `mat2` | 2 x `vec2` |
| `mat3` | 3 x `vec3` |
| `mat4` | 4 x `vec4` |

```cpp
// identity matrix
mat3 I(1.0f);

// construct from column vectors
vec3 col0(1, 0, 0);
vec3 col1(0, 1, 0);
vec3 col2(0, 0, 1);
mat3 M(col0, col1, col2);

// access a column
vec3 first_col = M[0];

// access an element
simdfloat val = M[1][2];

// access an element with M(row, col)
simdfloat elem = M(1, 2);

// matrix * vector
vec3 v(1, 2, 3);
vec3 result = M * v;

// matrix * matrix
mat3 product = M * M;
```

Double-precision matrix variants also exist: `dmat2/3/4`. Integer matrices are
not provided.

---

## Swizzling

One of the most recognizable features of GPU shading languages is swizzling,
and cppshader reimplements most of it.

Every vector type exposes the full set of GLSL read swizzles as member
functions, using both `xyzw` and `rgba` (and `stpq`) notation. The main difference from GLSL
is that reading more than one component at once requires an explicit function
call, and assigning a group of components also uses a setter-style function
call.

```cpp
vec3 v(1.0f, 2.0f, 3.0f);

// read swizzles: return a new vector
vec2 a = v.xy();
vec2 b = v.yx();
vec3 c = v.zyx();
vec4 d = v.xyzz();
vec3 e = v.zzz();
vec4 f = v.xxxx();

// rgb aliases work the same way
vec3 col(0.2f, 0.7f, 0.1f);
col = col.bgr();
```

Write swizzles are also available for reordered assignment:

```cpp
vec2 uv(0.5f, 0.3f);
uv.yx(1.0f, 0.0f);  // set y = 1, x = 0
uv.xy(uv);          // identity assignment

vec3 pos(0.0f);
pos.xy(uv);         // assign only x and y from a vec2
```

### Swizzle-Based Construction

```cpp
vec3 test(1.0f, 2.0f, 3.0f);
vec3 result = vec3(test.y, test.x, test.z);  // manual construction
vec3 result2 = test.yxz();                   // swizzle-based construction
test.yxz(result2.zxy());                     // assign back with a swizzle
```

---

## Arithmetic and Operators

All standard C++ arithmetic operators are overloaded for `simdfloat`,
`vec2/3/4`, and `mat2/3/4`, matching GLSL-style semantics.

```cpp
vec3 a(1.0f, 2.0f, 3.0f);
vec3 b(4.0f, 5.0f, 6.0f);

vec3 sum = a + b;
vec3 diff = a - b;
vec3 prod = a * b;  // component-wise
vec3 quot = a / 2.0f;
vec3 neg = -a;
```

Dot product and cross product use dedicated functions.

---

## Load and Store

The preferred way to fill vectorized types is to use load and store operations.
This avoids hard-coded lane assignment and makes it easier to switch between SIMD
widths.

Create arrays, then transfer data to and from `simdfloat`, `simddouble`, or
`simdint` with `simd_load_*` and `simd_store_*`. Buffers should be aligned to
`simdwidth * 4` bytes to preserve compatibility with wider backends. Using
`alignas(64)` for arrays is a practical default.

### Loading: Building a `simdfloat` from an array

```cpp
alignas(64) float tab[simdwidth]; // declaring an aligned array of simdwidth elements

for (int k = 0; k < simdwidth; ++k) // writing loop counter into array
    tab[k] = static_cast<float>(k);

simdfloat value = simd_load_float(tab); // creating a simdfloat with values from the array
```

### Storing: Writing Results Back to an array

```cpp
vec3 position; // initialized somewhere

alignas(64) float out[simdwidth]; // declaring an aligned array of simdwidth elements

simd_store_float(out, position.z); // storing content of position into the array
```

---

## Built-in Functions

Many GLSL built-in functions are implemented, especially in the math and
geometry categories. Most functions accept `simd*` types, numeric literals, and
vector or matrix types where applicable, and they return the matching type.

### Math

```cpp
simdfloat a = abs(-1.5f);
simdfloat b = floor(2.7f);
simdfloat c = ceil(2.1f);
simdfloat d = round(2.5f);
simdfloat e = fract(3.7f);
simdfloat f = sign(-3.0f);
simdfloat g = mod(10.0f, 3.0f);
simdfloat h = pow(2.0f, 8.0f);
simdfloat i = sqrt(9.0f);
simdfloat j = inversesqrt(4.0f);
```

### Trigonometry

```cpp
simdfloat angle = 0.785398f; // pi / 4
simdfloat s = sin(angle);
simdfloat c2 = cos(angle);
simdfloat t2 = tan(angle);

simdfloat a2 = asin(0.5f);
simdfloat a3 = acos(0.5f);
simdfloat a4 = atan(1.0f, 1.0f); // atan2

// Hyperbolic
simdfloat sh = sinh(1.0f);
simdfloat ch = cosh(1.0f);
simdfloat th = tanh(0.5f);
```

### Exponential and Logarithm

```cpp
simdfloat e = exp(1.0f);
simdfloat e2 = exp2(3.0f);
simdfloat l = log(2.718f);
simdfloat l2 = log2(8.0f);
```

### Range and Interpolation

```cpp
vec3 v(0.3f, 1.7f, -0.5f);

vec3 clamped = clamp(v, 0.0f, 1.0f); // clamp individual components values between 0.0f and 1.0f
vec3 mixed = mix(vec3(0.0f), vec3(1.0f), 0.5f); // linear interpolation between 0.0f and 1.0f (here 0.5f)
vec3 stepped = smoothstep(vec3(0.0f), vec3(1.0f), v); // hermite interpolation
```

### Geometric

```cpp
vec3 a(1, 0, 0);
vec3 b2(0, 1, 0);

simdfloat d2 = dot(a, b2); // scalar product
vec3 c3 = cross(a, b2); // cross product
simdfloat len = length(a); // length of a vector
vec3 n = normalize(a); // normalization
simdfloat dist = distance(a, b2); // distance between two points

vec3 incident(0.5f, -1.0f, 0.0f);
vec3 normal2(0.0f, 1.0f, 0.0f);
vec3 refl = reflect(incident, normal2); // reflection vector
```

### Min and Max

```cpp
simdfloat lo = min(a, b);
simdfloat hi = max(a, b);

vec3 vlo = min(vec3(1, 2, 3), vec3(3, 1, 2)); // minimum of individual components
vec3 vhi = max(vec3(0.0f), some_vec); // maximum
```

---

## Conditional Statements

The main limitation of current CPU SIMD execution is conditional control flow.
When a branch affects only some components of a vectorized type, you usually
need a mask, and both code paths must be evaluated before the final values are
selected.

Comparison operators on `simdfloat` return a `simdmask`, which can be used with
`blendv`:

```cpp
simdfloat x; // initialized somewhere
simdmask mask = x > 0.5f;

// GLSL-style ternary via blendv(false_val, true_val, mask)
simdfloat result = blendv(0.0f, 1.0f, mask);

// Works on vectors too
vec4 selected = blendv(colorA, colorB, mask);
```

Execution flow is more constrained than in GLSL. You cannot stop execution for
some lanes while the others continue, so leaving a loop or returning early based
on a condition usually means continuing to execute while checking whether all
lanes now share the same state. Use `maskAll` or `maskNone` for that purpose.

```cpp
simdfloat x; // initialized somewhere with values below 100

// Exit the loop when every lane reaches 100
while (!maskAll(x == 100)) // will stop loop when every lane of x is 100
{
    // In GLSL (not applicable here unless using USE_SCALAR):
    // x++;
    // if (x == 100) break;

    simdfloat tempX = x + 1;
    x = blendv(x, tempX, x < 100); // assigning values according to the condition
}
```

Masks for comparisons and blends on doubles use `simddmask`, and integer masks
use `simdimask`.

---

## Displaying Data

You can use `std::cout` to print any cppshader type, regardless of the selected
SIMD width:

```cpp
simdfloat f = 1.0f;
vec3 position;
mat4 matrix;

std::cout << f << std::endl;
std::cout << position << std::endl;
std::cout << matrix << std::endl;
```

---

## Full Shader Examples

See the `demo_*.cpp` files for complete shader examples ported from Shadertoy.
The main loop is typically a nested loop over image coordinates that builds
`simdfloat` lanes of x values, calls the shader function, and stores the results
back into an image buffer.

---

## Building Samples

Samples are rewritten Shadertoy shaders (see [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md)). They
can be compiled using Visual Studio or GCC, with SFML 2.5 or 2.6 as the only dependency. At runtime,
you can switch demos using the number keys. Remember to put the file `assets/Inter-Regular.ttf` next to the executable.

If you prefer a no-dependancies version, just comment "#define USE_SFML" on top of main.cpp.
You won't need SFML anymore, and a ppm image file will be generated instead.

---

## License

See [LICENSE](LICENSE) and [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

