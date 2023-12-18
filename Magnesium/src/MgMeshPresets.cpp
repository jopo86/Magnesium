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

	return MgMesh(vertices, indices, sizeof(vertices), sizeof(indices));
}
