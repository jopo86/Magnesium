#include "MgMeshPresets.h"

MgMesh MgMeshPresets::Triangle()
{
	return Triangle(1.0f, 1.0f);
}

MgMesh MgMeshPresets::Triangle(float side)
{
	return Triangle(side, sqrtf(powf(side / 2.0f, 2.0f) + powf(side, 2.0f)));
}

MgMesh MgMeshPresets::Triangle(float base, float height)
{
	return Triangle(
		MgVec2(-base / 2.0f, -height / 2.0f),
		MgVec2( base / 2.0f, -height / 2.0f),
		MgVec2( 0.0f,         height / 2.0f)
	);
}

MgMesh MgMeshPresets::Triangle(MgVec2 a, MgVec2 b, MgVec2 c)
{
	float vertices[] = {
		a.getX(), a.getY(), 0.0f,
		b.getX(), b.getY(), 0.0f,
		c.getX(), c.getY(), 0.0f
	};

	uint indices[] = {
		0, 1, 2
	};

	return MgMesh(vertices, sizeof(vertices), MG_VERTEX_FORMAT_V, indices, sizeof(indices));
}

MgMesh MgMeshPresets::Quad()
{
	return Quad(1.0f);
}

MgMesh MgMeshPresets::Quad(float side)
{
	return Quad(side, side);
}

MgMesh MgMeshPresets::Quad(float width, float height)
{
	return Quad(
		MgVec2(-width / 2.0f, -height / 2.0f),
		MgVec2( width / 2.0f, -height / 2.0f),
		MgVec2( width / 2.0f,  height / 2.0f),
		MgVec2(-width / 2.0f,  height / 2.0f)
	);
}

MgMesh MgMeshPresets::Quad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d)
{
	float vertices[] = {
		a.getX(), a.getY(), 0.0f,
		b.getX(), b.getY(), 0.0f,
		c.getX(), c.getY(), 0.0f,
		d.getX(), d.getY(), 0.0f
	};

	uint indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	return MgMesh(vertices, sizeof(vertices), MG_VERTEX_FORMAT_V, indices, sizeof(indices));
}
