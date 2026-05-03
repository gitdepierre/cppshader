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

#include <iostream>
#include <time.h>

#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/OpenGL.hpp"

#include "demos.h"
#include "cppshader.h"
#include "omp.h"

simdfloat iTime;
vec3 iMouse(0.5f);
sf::Image image;
int currentDemo = 0;

inline float scalar_clamp(float value, float minVal, float maxVal)
{
	return value < minVal ? minVal : (value > maxVal ? maxVal : value);
}

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
		case 11: color = Linear::mainImage(fragCoord); break;
		case 12: color = Julia::mainImage(fragCoord); break;
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

int main()
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
	text.setString("To the road of ribbon, by XT95");

	text2.setFont(font);
	text2.setCharacterSize(16);
	text2.setString("Code has been modified a bit to fit library constraints\nPress 0-9 to change demo, R to reset time");
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
				if (event.key.code == sf::Keyboard::Num1)
				{
					currentDemo = 0;
					text.setString("To the road of ribbon, by XT95");
				}
				else if (event.key.code == sf::Keyboard::Num2)
				{
					currentDemo = 1;
					text.setString("Shader Art Coding Introduction, by kishimisu");
				}
				else if (event.key.code == sf::Keyboard::Num3)
				{
					currentDemo = 2;
					text.setString("Creation by Silexars, by Danguafer");
				}
				else if (event.key.code == sf::Keyboard::Num4)
				{
					currentDemo = 3;
					text.setString("Seascape, by TDM");
				}
				else if (event.key.code == sf::Keyboard::Num5)
				{
					currentDemo = 4;
					text.setString("Zippy char, by SnoopethDuckDuck");
				}
				else if (event.key.code == sf::Keyboard::Num6)
				{
					currentDemo = 5;
					text.setString("Fovea detector, by nimitz");
				}
				else if (event.key.code == sf::Keyboard::Num7)
				{
					currentDemo = 6;
					text.setString("Protean Clouds, by nimitz");
				}
				else if (event.key.code == sf::Keyboard::Num8)
				{
					currentDemo = 7;
					text.setString("Fractal Land, by Kali");
				}
				else if (event.key.code == sf::Keyboard::Num9)
				{
					currentDemo = 8;
					text.setString("Coastal Landscape, by bitless");
				}
				else if (event.key.code == sf::Keyboard::Num0)
				{
					currentDemo = 9;
					text.setString("Chaos Crystal, by Silexars");
				}

				else if (event.key.code == sf::Keyboard::R)
					globalClock.restart();
			}
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
