#ifndef DEMO__H
#define DEMO__H

#include "cppshader.h"

// Change resolution here
#define IWIDTH 800
#define IHEIGHT 450

// Those variables are needed for the demos
extern simdfloat iTime;
extern vec3 iMouse;
const vec3 iResolution = vec3((float)IWIDTH, (float)IHEIGHT, 0);

namespace RoadRibbon {
	vec4 mainImage(vec2 fragCoord);
}

namespace ShaderArt {
	vec4 mainImage(vec2 fragCoord);
}

namespace Creation {
	vec4 mainImage(vec2 fragCoord);
}

namespace Seascape {
	vec4 mainImage(vec2 fragCoord);
}

namespace Zippy {
	vec4 mainImage(vec2 fragCoord);
}

namespace Fovea {
	vec4 mainImage(vec2 fragCoord);
}

namespace Protean {
	vec4 mainImage(vec2 fragCoord);
}

namespace FractalLand {
	vec4 mainImage(vec2 fragCoord);
}

namespace CoastalLandscape {
	vec4 mainImage(vec2 fragCoord);
}

namespace ChaosCrystal {
	vec4 mainImage(vec2 fragCoord);
}

namespace New {
	vec4 mainImage(vec2 fragCoord);
}

namespace Noise {
	vec4 mainImage(vec2 fragCoord);
}

namespace Hyperkart {
	vec4 mainImage(vec2 fragCoord);
}

namespace GlossyGradients {
	vec4 mainImage(vec2 fragCoord);
}

namespace WickedFractal {
	vec4 mainImage(vec2 fragCoord);
}

namespace RollingHill {
	vec4 mainImage(vec2 fragCoord);
}

namespace Gabor2 {
	vec4 mainImage(vec2 fragCoord);
}

namespace VoxelHallColors
{
	vec4 mainImage(vec2 fragCoord);
}

namespace Vortex
{
	vec4 mainImage(vec2 fragCoord);
}

#endif