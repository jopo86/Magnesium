#pragma once

#include "Magnesium.h"
#include "MgRenderable.h"
#include "MgMath.h"
#include "MgShaderPresets.h"
#include "MgMeshPresets.h"

namespace MgRenderablePresets
{
	using MgMath::MgVec2;
	using MgMath::MgVec3;

	MgRenderable ColoredTriangle(MgVec3 rgb);
	MgRenderable ColoredTriangle(float side, MgVec3 rgb);
	MgRenderable ColoredTriangle(float base, float height, MgVec3 rgb);
	MgRenderable ColoredTriangle(MgVec2 a, MgVec2 b, MgVec2 c, MgVec3 rgb);

	MgRenderable VertexColoredTriangle();
	MgRenderable VertexColoredTriangle(float side);
	MgRenderable VertexColoredTriangle(float base, float height);
	MgRenderable VertexColoredTriangle(MgVec2 a, MgVec2 b, MgVec2 c);

	MgRenderable TexturedTriangle(MgTexture texture);
	MgRenderable TexturedTriangle(float side, MgTexture texture);
	MgRenderable TexturedTriangle(float base, float height, MgTexture texture);
	MgRenderable TexturedTriangle(MgVec2 a, MgVec2 b, MgVec2 c, MgTexture texture);


	MgRenderable ColoredQuad(MgVec3 rgb);
	MgRenderable ColoredQuad(float side, MgVec3 rgb);
	MgRenderable ColoredQuad(float width, float height, MgVec3 rgb);
	MgRenderable ColoredQuad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d, MgVec3 rgb);

	MgRenderable VertexColoredQuad();
	MgRenderable VertexColoredQuad(float side);
	MgRenderable VertexColoredQuad(float width, float height);
	MgRenderable VertexColoredQuad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d);

	MgRenderable TexturedQuad(MgTexture texture);
	MgRenderable TexturedQuad(float side, MgTexture texture);
	MgRenderable TexturedQuad(float width, float height, MgTexture texture);
	MgRenderable TexturedQuad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d, MgTexture texture);

}
