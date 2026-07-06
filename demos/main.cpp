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


#define USE_SFML //Comment this to remove every SFML dependancy, and generate a ppm file instead

#include <iostream>
#include <fstream>
#include <time.h>
#include "demos.h"
#include "cppshader.h"
#include "omp.h"


simdfloat iTime;
int currentDemo = 0;
vec3 iMouse(0.5f);

inline float scalar_clamp(float value, float minVal, float maxVal)
{
	return value < minVal ? minVal : (value > maxVal ? maxVal : value);
}

#ifdef USE_SFML

#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/OpenGL.hpp"

sf::Image image;



void Pixel(int _i, int _j)
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
	switch (currentDemo)
	{
		case 0: color = RoadRibbon::mainImage(fragCoord); break;
		case 1: color = ShaderArt::mainImage(fragCoord); break;
		case 2: color = Creation::mainImage(fragCoord); break;
		case 3: color = Seascape::mainImage(fragCoord); break;
		case 4: color = Zippy::mainImage(fragCoord); break;
		case 5: color = Fovea::mainImage(fragCoord); break;
		case 6: color = Protean::mainImage(fragCoord); break;
		case 7: color = FractalLand::mainImage(fragCoord); break;
		case 8: color = CoastalLandscape::mainImage(fragCoord); break;
		case 9: color = ChaosCrystal::mainImage(fragCoord); break;
		case 10: color = New::mainImage(fragCoord); break;
		case 11: color = Noise::mainImage(fragCoord); break;
		case 12: color = Hyperkart::mainImage(fragCoord); break;
		case 13: color = GlossyGradients::mainImage(fragCoord); break;
		case 14: color = WickedFractal::mainImage(fragCoord); break;
		case 15: color = RollingHill::mainImage(fragCoord); break;
		case 16: color = Gabor2::mainImage(fragCoord); break;
		case 17: color = VoxelHallColors::mainImage(fragCoord); break;
		case 18: color = Vortex::mainImage(fragCoord); break;
	};

	// Getting color back and writting it to a SFML image
	alignas(64) float colorsX[simdwidth];
	alignas(64) float colorsY[simdwidth];
	alignas(64) float colorsZ[simdwidth];
	simd_store_float(colorsX, color.x);
	simd_store_float(colorsY, color.y);
	simd_store_float(colorsZ, color.z);
	for (int k = 0; k < simdwidth; k++)
	{
		sf::Color col;
		col.r = (unsigned char)(scalar_clamp(colorsX[k], 0.0f, 1.0f) * 255.0f);
		col.g = (unsigned char)(scalar_clamp(colorsY[k], 0.0f, 1.0f) * 255.0f);
		col.b = (unsigned char)(scalar_clamp(colorsZ[k], 0.0f, 1.0f) * 255.0f);
		col.a = 255;

		image.setPixel(_i + k, _j, col);

	}
}

int Run()
{
	sf::RenderWindow window(sf::VideoMode(IWIDTH, IHEIGHT), "My window");

	// Initializing time
	iTime = SIMDZERO;

	sf::Texture texture;
	texture.create(IWIDTH, IHEIGHT);
	image.create(IWIDTH, IHEIGHT, sf::Color::Black);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Font font;
	sf::Text text, text2;
	if (!font.loadFromFile("Inter-Regular.ttf"))
	{
		return -1;
	}
	text.setFont(font);
	text.setCharacterSize(16);

	text2.setFont(font);
	text2.setCharacterSize(16);
	text2.setString("Code has been modified a bit to fit library constraints\nPress left/right arrows to change demo, R to reset time");
	text2.setPosition(0, 20);

	sf::Clock frameClock;
	sf::Clock globalClock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					currentDemo--;
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					currentDemo++;
				}
				else if (event.key.code == sf::Keyboard::R)
					globalClock.restart();
			}
		}

		if (currentDemo < 0)
			currentDemo = 18;
		currentDemo%=19; // Looping the demo index

		switch (currentDemo)
		{
		case 0: text.setString("To the road of ribbon, by XT95"); break;
		case 1:  text.setString("Shader Art Coding Introduction, by kishimisu"); break;
		case 2:  text.setString("Creation by Silexars, by Danguafer"); break;
		case 3:  text.setString("Seascape, by TDM"); break;
		case 4:  text.setString("Zippy char, by SnoopethDuckDuck"); break;
		case 5: text.setString("Fovea detector, by nimitz"); break;
		case 6: text.setString("Protean Clouds, by nimitz"); break;
		case 7:  text.setString("Fractal Land, by Kali"); break;
		case 8:  text.setString("Coastal Landscape, by bitless"); break;
		case 9:  text.setString("Chaos Crystal, by Silexars"); break;
		case 10:  text.setString("New shader"); break;
		case 11:  text.setString("3D Simplex Noise, by Ian McEwan, Ashima Arts, ijm"); break;
		case 12:  text.setString("Hyperkart, by diatribes"); break;
		case 13: text.setString("Glossy Gradients, by Peace"); break;
		case 14: text.setString("Wicked Fractal Flight, by diatribes"); break;
		case 15: text.setString("Rolling Hill, by Dave_Hoskins"); break;
		case 16: text.setString("Gabor^2, by mattz"); break;
		case 17: text.setString("Voxel Hall Colors, by elsif"); break;
		case 18: text.setString("Tribute to Marc-Antoine Mathieu, by leon"); break;
		}

		// Updating the iTime variable, used in the demos to create animations
		iTime = globalClock.getElapsedTime().asSeconds();

		// Rendering the shader
#pragma omp parallel for schedule(dynamic,32)
		for (int i = 0; i < IHEIGHT * IWIDTH; i += simdwidth)
		{
			Pixel(i % IWIDTH, i / IWIDTH);
		}

		texture.update(image);

		window.clear(sf::Color::Green);
		window.draw(sprite);
		window.draw(text);
		window.draw(text2);
		window.display();
		std::cout << "FPS : " << 1.0f/frameClock.restart().asSeconds() << std::endl; // Displaying frame time
	}
}
#else //Not using SFML
uint32_t image[IWIDTH * IHEIGHT];

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
	switch (currentDemo)
	{
	case 0: color = RoadRibbon::mainImage(fragCoord); break;
	case 1: color = ShaderArt::mainImage(fragCoord); break;
	case 2: color = Creation::mainImage(fragCoord); break;
	case 3: color = Seascape::mainImage(fragCoord); break;
	case 4: color = Zippy::mainImage(fragCoord); break;
	case 5: color = Fovea::mainImage(fragCoord); break;
	case 6: color = Protean::mainImage(fragCoord); break;
	case 7: color = FractalLand::mainImage(fragCoord); break;
	case 8: color = CoastalLandscape::mainImage(fragCoord); break;
	case 9: color = ChaosCrystal::mainImage(fragCoord); break;
	case 10: color = New::mainImage(fragCoord); break;
	case 11: color = Noise::mainImage(fragCoord); break;
	case 12: color = Hyperkart::mainImage(fragCoord); break;
	case 13: color = GlossyGradients::mainImage(fragCoord); break;
	case 14: color = WickedFractal::mainImage(fragCoord); break;
	case 15: color = RollingHill::mainImage(fragCoord); break;
	case 16: color = Gabor2::mainImage(fragCoord); break;
	case 17: color = VoxelHallColors::mainImage(fragCoord); break;
	case 18: color = Vortex::mainImage(fragCoord); break;
	};

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


void Run()
{
	std::cout << "Choose which demo to run:" << std::endl;
	std::cout << "[0] To the road of ribbon, by XT95" << std::endl;
	std::cout << "[1] Shader Art Coding Introduction, by kishimisu" << std::endl;
	std::cout << "[2] Creation by Silexars, by Danguafer" << std::endl;
	std::cout << "[3] Seascape, by TDM" << std::endl;
	std::cout << "[4] Zippy char, by SnoopethDuckDuck" << std::endl;
	std::cout << "[5] Fovea detector, by nimitz" << std::endl;
	std::cout << "[6] Protean Clouds, by nimitz" << std::endl;
	std::cout << "[7] Fractal Land, by Kali" << std::endl;
	std::cout << "[8] Coastal Landscape, by bitless" << std::endl;
	std::cout << "[9] Chaos Crystal, by Silexars" << std::endl;
	std::cout << "[10] New shader" << std::endl;
	std::cout << "[11] 3D Simplex Noise, by Ian McEwan, Ashima Arts, ijm" << std::endl;
	std::cout << "[12] Hyperkart, by diatribes" << std::endl;
	std::cout << "[13] Glossy Gradients, by Peace" << std::endl;
	std::cout << "[14] Wicked Fractal Flight, by diatribes" << std::endl;
	std::cout << "[15] Rolling Hill, by Dave_Hoskins" << std::endl;
	std::cout << "[16] Gabor^2, by mattz" << std::endl;
	std::cout << "[17] Voxel Hall Colors, by elsif" << std::endl;
	std::cout << "[18] Tribute to Marc-Antoine Mathieu, by leon" << std::endl;
	std::string choice;
	std::cin >> choice;

	if (choice == std::string("0")) currentDemo = 0;
	if (choice == std::string("1")) currentDemo = 1;
	if (choice == std::string("2")) currentDemo = 2;
	if (choice == std::string("3")) currentDemo = 3;
	if (choice == std::string("4")) currentDemo = 4;
	if (choice == std::string("5")) currentDemo = 5;
	if (choice == std::string("6")) currentDemo = 6;
	if (choice == std::string("7")) currentDemo = 7;
	if (choice == std::string("8")) currentDemo = 8;
	if (choice == std::string("9")) currentDemo = 9;
	if (choice == std::string("10")) currentDemo = 10;
	if (choice == std::string("11")) currentDemo = 11;
	if (choice == std::string("12")) currentDemo = 12;
	if (choice == std::string("13")) currentDemo = 13;
	if (choice == std::string("14")) currentDemo = 14;
	if (choice == std::string("15")) currentDemo = 15;
	if (choice == std::string("16")) currentDemo = 16;
	if (choice == std::string("17")) currentDemo = 17;

	iTime = 5.0f;

	for (int i = 0; i < IHEIGHT * IWIDTH; i += simdwidth)
	{
		PixelPPM(i % IWIDTH, i / IWIDTH);
	}
	// Writing the result to a PPM file
	std::fstream file("generated.ppm", std::ios::out|std::ios::binary);
	file << "P6\n" << IWIDTH << " " << IHEIGHT <<"\n255\n";
	for (int i = 0; i < IWIDTH * IHEIGHT; i++)
	{
		uint32_t col = image[i];
		unsigned char r = (col >> 24) & 0xFF;
		unsigned char g = (col >> 16) & 0xFF;
		unsigned char b = (col >> 8) & 0xFF;
		file << r;
		file << g;
		file << b;
	}

	std::cout <<"Snapshot has been saved as \"generated.ppm\", press enter to exit...\n";
	getchar();

}

#endif
int main()
{

	Run();
}
