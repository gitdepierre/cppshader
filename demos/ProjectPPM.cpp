/*
 * MIT License
 *
 * Copyright 2026 Pierre GEISSLER
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "demos.h"
#include "cppshader.h"

uint32_t image[IWIDTH * IHEIGHT];
simdfloat iTime;
inline float scalar_clamp(float value, float minVal, float maxVal)
{
	return value < minVal ? minVal : (value > maxVal ? maxVal : value);
}

void PixelPPM(int _i, int _j)
{
	// Filling a big array here, able to accomodate every SIMD flavour at loading
	alignas(64) float tab[16] = {
			(float)_i + 0.0f,
			(float)_i + 1.0f,
			(float)_i + 2.0f,
			(float)_i + 3.0f,
			(float)_i + 4.0f,
			(float)_i + 5.0f,
			(float)_i + 6.0f,
			(float)_i + 7.0f,
			(float)_i + 8.0f,
			(float)_i + 9.0f,
			(float)_i + 10.0f,
			(float)_i + 11.0f,
			(float)_i + 12.0f,
			(float)_i + 13.0f,
			(float)_i + 14.0f,
			(float)_i + 15.0f,
	};

	vec2 fragCoord(simd_load_float(tab), (float)(IHEIGHT - _j));
	vec4 color;

	// Running the current demo, and storing the result in "color" variable
	color = RoadRibbon::mainImage(fragCoord);

	// Getting color back and writting it to a SFML image
	alignas(64) float colorsX[simdwidth];
	alignas(64) float colorsY[simdwidth];
	alignas(64) float colorsZ[simdwidth];
	simd_store_float(colorsX, color.x);
	simd_store_float(colorsY, color.y);
	simd_store_float(colorsZ, color.z);
	for (int k = 0; k < simdwidth; k++)
	{
		uint32_t col = (uint32_t)(scalar_clamp(colorsX[k], 0.0f, 1.0f) * 255.0f);
		col = (col << 8) | (uint32_t)(scalar_clamp(colorsY[k], 0.0f, 1.0f) * 255.0f);
		col = (col << 8) | (uint32_t)(scalar_clamp(colorsZ[k], 0.0f, 1.0f) * 255.0f);
		col = (col << 8) | 255;

		image[(_i + k) + _j * IWIDTH] = col;

	}
}


 int RunPPM()
 {
    iTime += 5.0f;

    printf("Demo will generate a snapshot of 'To the road of ribbon, by XT95', and write it to a PPM file, press a key to continue...\n");
    getchar();  

    for (int i = 0; i < IHEIGHT * IWIDTH; i += simdwidth)
    {
        PixelPPM(i % IWIDTH, i / IWIDTH);
    }
    char filename[] = "To_the_road_of_ribbon_by_XT95.ppm";
    // Writing the result to a PPM file
    FILE* f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n255\n", IWIDTH, IHEIGHT);
    for (int i = 0; i < IWIDTH * IHEIGHT; i++)  
    {
        uint32_t col = image[i];
        unsigned char r = (col >> 24) & 0xFF;
        unsigned char g = (col >> 16) & 0xFF;
        unsigned char b = (col >> 8) & 0xFF;
        fputc(r, f);
        fputc(g, f);
        fputc(b, f);
    }
    fclose(f);

    printf("Snapshot has been generated as %s, press a key to exit...\n", filename);
    getchar();  

    return 0;
 }