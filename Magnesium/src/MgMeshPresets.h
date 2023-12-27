/*
 * @file A header file providing access to preset meshes.
 */

#pragma once

#include <cmath>

#include "Magnesium.h"
#include "MgMesh.h"
#include "MgMath.h"

namespace MgMeshPresets
{
	using MgMath::MgVec2;
	using MgMath::MgVec3;

	/*
	 * @brief Creates a triangle mesh with a base and height of 1.
	 * @return The resulting mesh.
	 */
	MgMesh Triangle();

	/*
	 * @brief Creates an equilateral triangle mesh with the specified side length.
	 * @param side The side length.
	 * @return The resulting mesh.
	 */
	MgMesh Triangle(float side);

	/*
	 * @brief Creates a triangle mesh with the specified base and height lengths.
	 * @return The resulting mesh.
	 */
	MgMesh Triangle(float base, float height);

	/*
	 * @brief Creates a triangle mesh with the specified 3 vertices.
	 * @param a The first vertex.
	 * @param b The second vertex.
	 * @param c The third vertex.
	 * @return The resulting mesh.
	 */
	MgMesh Triangle(MgVec2 a, MgVec2 b, MgVec2 c);

	/*
	 * @brief Creates a square with side lengths of 1.
	 * @return The resulting mesh.
	 */
	MgMesh Quad();

	/*
	 * @brief Creates a square with the specified side length.
	 * @param The side length.
	 * @return The resulting mesh.
	 */
	MgMesh Quad(float side);

	/*
	 * @brief Creates a rectangle with the specified width and height.
	 * @return The resulting mesh.
	 */
	MgMesh Quad(float width, float height);

	/*
	 * @brief Creates a quadrilateral with the specified vertices.
	 * @param a The bottom-left vertex.
	 * @param b The bottom-right vertex.
	 * @param c The top-right vertex.
	 * @param d The top-left vertex.
	 * @return The resulting mesh.
	 */
	MgMesh Quad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d);
}
