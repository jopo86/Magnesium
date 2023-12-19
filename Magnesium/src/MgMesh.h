#pragma once

#include <glad/glad.h>

#include "Magnesium.h"
#include "MgObject.h"

class MgMesh : public MgObject
{
public:
	MgMesh();
	MgMesh(float* vertices, uint* indices, uint verticesSize, uint indicesSize);

	void render();

	float* getVertices();
	uint* getIndices();
	uint getVerticesSize();
	uint getIndicesSize();

	void dispose() override;

private:
	uint vao, vbo, ibo;

	float* vertices;
	uint* indices;
	uint verticesSize, indicesSize;
};
