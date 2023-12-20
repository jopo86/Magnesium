#include "MgMeshPresets.h"

MgMesh MgMeshPresets::Line()
{
	// TODO
	return MgMesh();
}

MgMesh MgMeshPresets::Line(float length)
{
	// TODO
	return MgMesh();
}

MgMesh MgMeshPresets::Line(float length, float angle)
{
	// TODO
	return MgMesh();
}

MgMesh MgMeshPresets::Line(MgVec2 origin, float length, float angle)
{
	// TODO
	return MgMesh();
}

MgMesh MgMeshPresets::Line(MgVec2 a, MgVec2 b)
{
	// TODO
	return MgMesh();
}

MgMesh MgMeshPresets::Triangle()
{
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	}; 
	
	uint indices[] = {
		0, 1, 2
	};

	return MgMesh(vertices, sizeof(vertices), MG_VERTEX_FORMAT_V, indices, sizeof(indices));
}

MgMesh MgMeshPresets::Triangle(float base, float height)
{
	float vertices[] = {
		-base / 2.0f, -height / 2.0f, 0.0f,
		 base / 2.0f, -height / 2.0f, 0.0f,
		 0.0f,         height / 2.0f, 0.0f
	};

	uint indices[] = {
		0, 1, 2
	};

	return MgMesh(vertices, sizeof(vertices), MG_VERTEX_FORMAT_V, indices, sizeof(indices));
}

MgMesh MgMeshPresets::Triangle(float side)
{
	return Triangle(side, sqrtf(powf(side / 2.0f, 2.0f) + powf(side, 2.0f)));
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
	return MgMeshPresets::Quad(1.0f);
}

MgMesh MgMeshPresets::Quad(float side)
{
	float vertices[] = {
		-side / 2.0f, -side / 2.0f, 0.0f,
		 side / 2.0f, -side / 2.0f, 0.0f,
		 side / 2.0f,  side / 2.0f, 0.0f,
		-side / 2.0f,  side / 2.0f, 0.0f
	};

	uint indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	return MgMesh(vertices, sizeof(vertices), MG_VERTEX_FORMAT_V, indices, sizeof(indices));
}

MgMesh MgMeshPresets::Quad(float width, float height)
{
	float vertices[] = {
		-width / 2.0f, -height / 2.0f, 0.0f,
		 width / 2.0f, -height / 2.0f, 0.0f,
		 width / 2.0f,  height / 2.0f, 0.0f,
		-width / 2.0f,  height / 2.0f, 0.0f
	};

	uint indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	return MgMesh(vertices, sizeof(vertices), MG_VERTEX_FORMAT_V, indices, sizeof(indices));
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
