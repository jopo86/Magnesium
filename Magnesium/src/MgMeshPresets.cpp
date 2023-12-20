#include "MgMeshPresets.h"

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

MgMesh MgMeshPresets::Triangle(MgVec3 a, MgVec3 b, MgVec3 c)
{
	float vertices[] = {
		a.getX(), a.getY(), a.getZ(),
		b.getX(), b.getY(), b.getZ(),
		c.getX(), c.getY(), c.getZ()
	};

	uint indices[] = {
		0, 1, 2
	};

	return MgMesh(vertices, sizeof(vertices), MG_VERTEX_FORMAT_V, indices, sizeof(indices));
}
