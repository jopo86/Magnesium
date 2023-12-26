#include "MgRenderablePresets.h"


MgRenderable MgRenderablePresets::ColoredTriangle(MgVec3 rgb)
{
	return ColoredTriangle(1.0f, 1.0f, rgb);
}

MgRenderable MgRenderablePresets::ColoredTriangle(float side, MgVec3 rgb)
{
	return ColoredTriangle(side, sqrtf(powf(side / 2.0f, 2.0f) + powf(side, 2.0f)), rgb);
}

MgRenderable MgRenderablePresets::ColoredTriangle(float base, float height, MgVec3 rgb)
{
	return ColoredTriangle(
		MgVec2(-base / 2.0f, -height / 2.0f),
		MgVec2( base / 2.0f, -height / 2.0f),
		MgVec2( 0.0f,		  height / 2.0f),
		rgb
	);
}

MgRenderable MgRenderablePresets::ColoredTriangle(MgVec2 a, MgVec2 b, MgVec2 c, MgVec3 rgb)
{
	return MgRenderable(
		MgMeshPresets::Triangle(a, b, c),
		MgShaderPresets::Color(rgb)
	);
}

MgRenderable MgRenderablePresets::VertexColoredTriangle()
{
	return VertexColoredTriangle(1.0f, 1.0f);
}

MgRenderable MgRenderablePresets::VertexColoredTriangle(float side)
{
	return VertexColoredTriangle(side, sqrtf(powf(side / 2.0f, 2.0f) + powf(side, 2.0f)));
}

MgRenderable MgRenderablePresets::VertexColoredTriangle(float base, float height)
{
	return VertexColoredTriangle(
		MgVec2(-base / 2.0f, -height / 2.0f),
		MgVec2(base / 2.0f, -height / 2.0f),
		MgVec2(0.0f, height / 2.0f)
	);
}

MgRenderable MgRenderablePresets::VertexColoredTriangle(MgVec2 a, MgVec2 b, MgVec2 c)
{
	return MgRenderable(
		MgMeshPresets::Triangle(a, b, c),
		MgShaderPresets::VertexColor()
	);
}

MgRenderable MgRenderablePresets::TexturedTriangle(MgTexture texture)
{
	return TexturedTriangle(1.0f, 1.0f, texture);
}

MgRenderable MgRenderablePresets::TexturedTriangle(float side, MgTexture texture)
{
	return TexturedTriangle(side, sqrtf(powf(side / 2.0f, 2.0f) + powf(side, 2.0f)), texture);
}

MgRenderable MgRenderablePresets::TexturedTriangle(float base, float height, MgTexture texture)
{
	return TexturedTriangle(
		MgVec2(-base / 2.0f, -height / 2.0f),
		MgVec2(base / 2.0f, -height / 2.0f),
		MgVec2(0.0f, height / 2.0f),
		texture
	);
}

MgRenderable MgRenderablePresets::TexturedTriangle(MgVec2 a, MgVec2 b, MgVec2 c, MgTexture texture)
{
	float vertices[] = {
		a.getX(), a.getY(), 0.0f,	0.0f, 0.0f,
		b.getX(), b.getY(), 0.0f,	1.0f, 0.0f,
		c.getX(), c.getY(), 0.0f,	0.5f, 1.0f
	};

	uint indices[] = {
		0, 1, 2
	};

	return MgRenderable(
		MgMesh(vertices, sizeof(vertices), MG_VERTEX_FORMAT_VT, indices, sizeof(indices)),
		MgShaderPresets::Texture(),
		texture
	);
}

MgRenderable MgRenderablePresets::ColoredQuad(MgVec3 rgb)
{
	return ColoredQuad(1.0f, rgb);
}

MgRenderable MgRenderablePresets::ColoredQuad(float side, MgVec3 rgb)
{
	return ColoredQuad(side, side, rgb);
}

MgRenderable MgRenderablePresets::ColoredQuad(float width, float height, MgVec3 rgb)
{
	return ColoredQuad(
		MgVec2(-width / 2.0f, -height / 2.0f),
		MgVec2(width / 2.0f, -height / 2.0f),
		MgVec2(width / 2.0f, height / 2.0f),
		MgVec2(-width / 2.0f, height / 2.0f),
		rgb
	);
}

MgRenderable MgRenderablePresets::ColoredQuad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d, MgVec3 rgb)
{
	return MgRenderable(
		MgMeshPresets::Quad(a, b, c, d),
		MgShaderPresets::Color(rgb)
	);
}

MgRenderable MgRenderablePresets::VertexColoredQuad()
{
	return VertexColoredQuad(1.0f);
}

MgRenderable MgRenderablePresets::VertexColoredQuad(float side)
{
	return VertexColoredQuad(side, side);
}

MgRenderable MgRenderablePresets::VertexColoredQuad(float width, float height)
{
	return VertexColoredQuad(
		MgVec2(-width / 2.0f, -height / 2.0f),
		MgVec2( width / 2.0f, -height / 2.0f),
		MgVec2( width / 2.0f,  height / 2.0f),
		MgVec2(-width / 2.0f,  height / 2.0f)
	);
}

MgRenderable MgRenderablePresets::VertexColoredQuad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d)
{
	return MgRenderable(
		MgMeshPresets::Quad(a, b, c, d),
		MgShaderPresets::VertexColor()
	);
}

MgRenderable MgRenderablePresets::TexturedQuad(MgTexture texture)
{
	return TexturedQuad(1.0f, texture);
}

MgRenderable MgRenderablePresets::TexturedQuad(float side, MgTexture texture)
{
	return TexturedQuad(side, side, texture);
}

MgRenderable MgRenderablePresets::TexturedQuad(float width, float height, MgTexture texture)
{
	return TexturedQuad(
		MgVec2(-width / 2.0f, -height / 2.0f),
		MgVec2( width / 2.0f, -height / 2.0f),
		MgVec2( width / 2.0f,  height / 2.0f),
		MgVec2(-width / 2.0f,  height / 2.0f),
		texture
	);
}

MgRenderable MgRenderablePresets::TexturedQuad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d, MgTexture texture)
{
	float vertices[] = {
		a.getX(), a.getY(), 0.0f,	0.0f, 0.0f,
		b.getX(), b.getY(), 0.0f,	1.0f, 0.0f,
		c.getX(), c.getY(), 0.0f,	1.0f, 1.0f,
		d.getX(), d.getY(), 0.0f,	0.0f, 1.0f
	};

	uint indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	return MgRenderable(
		MgMesh(vertices, sizeof(vertices), MG_VERTEX_FORMAT_VT, indices, sizeof(indices)),
		MgShaderPresets::Texture(),
		texture
	);
}

