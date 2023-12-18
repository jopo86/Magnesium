#include "MgMesh.h"

MgMesh::MgMesh()
{
	vao = vbo = ibo = verticesSize = indicesSize = 0;
	vertices = nullptr;
	indices = nullptr;
}

MgMesh::MgMesh(float* vertices, uint* indices, uint verticesSize, uint indicesSize)
{
	vao = vbo = ibo = 0;
	this->vertices = vertices;
	this->indices = indices;
	this->verticesSize = verticesSize;
	this->indicesSize = indicesSize;
	
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void MgMesh::render()
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indicesSize / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}

float* MgMesh::getVertices()
{
	return vertices;
}

uint* MgMesh::getIndices()
{
	return indices;
}

uint MgMesh::getVerticesSize()
{
	return verticesSize;
}

uint MgMesh::getIndicesSize()
{
	return indicesSize;
}

void MgMesh::dispose()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
	vao = vbo = ibo = verticesSize = indicesSize = 0;
	vertices = nullptr;
	indices = nullptr;
}
