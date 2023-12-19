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
