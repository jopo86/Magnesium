#pragma once

#include <glad/glad.h>

#include "Magnesium.h"

/*
 * @brief A class to represent a mesh.
 * This includes vertices, the positions of each point on the mesh, as well as indices, the order of vertices as indices.
 * This class is disposable.
 */
class MgMesh : public MgDisposable
{
public:
	/*
	 * @brief Creates an empty MgMesh object.
	 * Trying to use a mesh object constructed like this will most likely cause errors.
	 */
	MgMesh();

	/*
	 * @brief Creats a new MgMesh object with the specified vertices and indices.
	 * @param vertices The vertex array.
	 * @param verticesSize The size, in bytes, of the vertex array. Use sizeof().
	 * @param vertexFormat The format of the vertices. Use the definitions prefixed with MG_VERTEX_FORMAT.
	 * @param indices The index array.
	 * @param indicesSize The size, in bytes, of the index array. Use sizeof().
	 */
	MgMesh(float* vertices, uint verticesSize, int vertexFormat, uint* indices, uint indicesSize);

	/*
	 * @brief Gets the vertex array object ID.
	 * Access to the VAO is provided for the library, as well as for advanced users.
	 * @return The VAO ID.
	 */
	uint getVaoID();

	/*
	 * @brief Gets the vertices of the mesh.
	 * @return The vertex array.
	 */
	float* getVertices();

	/*
	 * @brief Gets the indices of the mesh.
	 * @return The index array.
	 */
	uint* getIndices();

	/*
	 * @brief Gets the size of the vertices.
	 * @return The size, in bytes, of the vertex array.
	 */
	uint getVerticesSize();

	/*
	 * @brief Gets the size of the indices.
	 * @return The size, in bytes, of the index array.
	 */
	uint getIndicesSize();

	/*
	 * @brief Disposes of the mesh.
	 * This clears up any memory that the object was using.
	 * This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
	 */
	void dispose() override;

private:
	uint vao, vbo, ibo;

	float* vertices;
	uint* indices;
	uint verticesSize, indicesSize;
};
