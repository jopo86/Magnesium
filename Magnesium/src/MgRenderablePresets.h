#pragma once

#include "Magnesium.h"
#include "MgRenderable.h"
#include "MgMath.h"
#include "MgShaderPresets.h"
#include "MgMeshPresets.h"
/*
 * @brief A namespace providing access to preset renderables for convenience.
 */
namespace MgRenderablePresets
{
	using MgMath::MgVec2;
	using MgMath::MgVec3;

	/*
	 * @brief Creates a triangle renderable with a base and height of 1 and the specified color.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 * @return The resulting renderable.
	 */
	MgRenderable ColoredTriangle(MgVec3 rgb);

	/*
	 * @brief Creates an equilateral triangle renderable with the specified side length and color.
	 * @param side The side length.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 * @return The resulting renderable.
	 */
	MgRenderable ColoredTriangle(float side, MgVec3 rgb);

	/*
	 * @brief Creates a triangle renderable with the specified base, height, and color.
	 * @param base The base length.
	 * @param height The height.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 * @return The resulting renderable.
	 */
	MgRenderable ColoredTriangle(float base, float height, MgVec3 rgb);

	/*
	 * @brief Creates a triangle renderable with the specified 3 vertices and color.
	 * @param a The first vertex.
	 * @param b The second vertex.
	 * @param c The third vertex.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 * @return The resulting renderable.
	 */
	MgRenderable ColoredTriangle(MgVec2 a, MgVec2 b, MgVec2 c, MgVec3 rgb);

	/*
	 * @brief Creates a triangle renderable with a base and height of 1 and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
	 * @return The resulting renderable.
	 */
	MgRenderable VertexColoredTriangle();

	/*
	 * @brief Creates an equilateral triangle renderable with the specified side length and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
	 * @param side The side length.
	 * @return The resulting renderable.
	 */
	MgRenderable VertexColoredTriangle(float side);

	/*
	 * @brief Creates a triangle renderable with the specified base and height, and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
	 * @param base The base length.
	 * @param height The height.
	 * @return The resulting renderable.
	 */
	MgRenderable VertexColoredTriangle(float base, float height);

	/*
	 * @brief Creates a triangle renderable with the specified 3 vertices and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
	 * @param a The first vertex.
	 * @param b The second vertex.
	 * @param c The third vertex.
	 * @return The resulting renderable.
	 */
	MgRenderable VertexColoredTriangle(MgVec2 a, MgVec2 b, MgVec2 c);

	/*
	 * @brief Creates a triangle renderable with a base and height of 1 and the specified texture.
	 * @param texture The texture to use.
	 * @return The resulting renderable.
	 */
	MgRenderable TexturedTriangle(MgTexture texture);

	/*
	 * @brief Creates an equilateral triangle renderable with the specified side length and texture.
	 * @param side The side length.
	 * @param texture The texture to use.
	 * @return The resulting renderable.
	 */
	MgRenderable TexturedTriangle(float side, MgTexture texture);

	/*
	 * @brief Creates a triangle renderable with the specified base, height, and texture.
	 * @param base The base length.
	 * @param height The height.
	 * @param texture The texture to use.
	 * @return The resulting renderable.
	 */
	MgRenderable TexturedTriangle(float base, float height, MgTexture texture);

	/*
	 * @brief Creates a triangle renderable with the specified 3 vertices and texture.
	 * @param a The first vertex.
	 * @param b The second vertex.
	 * @param c The third vertex.
	 * @param texture The texture to use.
	 * @return The resulting renderable.
	 */
	MgRenderable TexturedTriangle(MgVec2 a, MgVec2 b, MgVec2 c, MgTexture texture);

	/*
	 * @brief Creates a square renderable with side lengths of 1 and the specified color.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 * @return The resulting renderable.
	 */
	MgRenderable ColoredQuad(MgVec3 rgb);

	/*
	 * @brief Creates a square renderable with the specified side length and color.
	 * @param side The side length.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 * @return The resulting renderable.
	 */
	MgRenderable ColoredQuad(float side, MgVec3 rgb);

	/*
	 * @brief Creates a rectangle renderable with the specified width, height, and color.
	 * @param width The width of the rectangle.
	 * @param height The height of the rectangle.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 * @return The resulting renderable.
	 */
	MgRenderable ColoredQuad(float width, float height, MgVec3 rgb);

	/*
	 * @brief Creates a quadrilateral renderable with the specified vertices and color.
	 * @param a The bottom-left vertex.
	 * @param b The bottom-right vertex.
	 * @param c The top-right vertex.
	 * @param d The top-left vertex.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 * @return The resulting renderable.
	 */
	MgRenderable ColoredQuad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d, MgVec3 rgb);

	/*
	 * @brief Creates a square renderable with side lengths of 1 and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
	 * @return The resulting renderable.
	 */
	MgRenderable VertexColoredQuad();

	/*
	 * @brief Creates a square renderable with the specified side length and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
	 * @param side The side length.
	 * @return The resulting renderable.
	 */
	MgRenderable VertexColoredQuad(float side);

	/*
	 * @brief Creates a rectangle renderable with the specified width and height, and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
	 * @param width The width of the rectangle.
	 * @param height The height of the rectangle.
	 * @return The resulting renderable.
	 */
	MgRenderable VertexColoredQuad(float width, float height);

	/*
	 * @brief Creates a quadrilateral renderable with the specified 4 vertices and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
	 * @param a The bottom-left vertex.
	 * @param b The bottom-right vertex.
	 * @param c The top-right vertex.
	 * @param d The top-left vertex.
	 * @return The resulting renderable.
	 */
	MgRenderable VertexColoredQuad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d);

	/*
	 * @brief Creates a square renderable with side lengths of 1 and the specified texture.
	 * @param texture The texture to use.
	 * @return The resulting renderable.
	 */
	MgRenderable TexturedQuad(MgTexture texture);

	/*
	 * @brief Creates a square renderable with the specified side length and texture.
	 * @param side The side length.
	 * @param texture The texture to use.
	 * @return The resulting renderable.
	 */
	MgRenderable TexturedQuad(float side, MgTexture texture);

	/*
	 * @brief Creates a rectangle renderable with the specified width, height, and texture.
	 * @param width The width of the rectangle.
	 * @param height The height of the rectangle.
	 * @param texture The texture to use.
	 * @return The resulting renderable.
	 */
	MgRenderable TexturedQuad(float width, float height, MgTexture texture);
	MgRenderable TexturedQuad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d, MgTexture texture);

}
