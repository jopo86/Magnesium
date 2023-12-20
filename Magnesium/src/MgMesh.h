#pragma once

#include <glad/glad.h>

#include "Magnesium.h"
#include "MgDisposable.h"

class MgMesh : public MgDisposable
{
public:
	MgMesh();
	MgMesh(float* vertices, uint verticesSize, int vertexFormat, uint* indices, uint indicesSize);
	MgMesh(float* vertices, uint verticesSize, int vertexFormat, int unit, uint* indices, uint indicesSize);

	void render();

	float* getVertices();
	uint* getIndices();
	uint getVerticesSize();
	uint getIndicesSize();
	int getUnit();

	void setUnit(int val);

	void dispose() override;

private:
	uint vao, vbo, ibo;

	float* vertices;
	uint* indices;
	uint verticesSize, indicesSize;

	int unit;
};
