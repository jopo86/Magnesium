#pragma once

#include "MgShader.h"
#include "MgFile.h"
#include "MgMath.h"

/*
 * @brief A namespace providing access to preset shaders for convenience.
 * Users would otherwise have to write their own GLSL shader code.
 */
namespace MgShaderPresets
{
	using MgMath::MgVec3;

	/*
	 * @brief Creates a shader that colors the mesh to the specified color.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 * @return The resulting shader.
	 */
	MgShader Color(MgVec3 rgb);

	/*
	 * @brief Creates a shader that uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
	 * @return The resulting shader.
	 */
	MgShader VertexColor();

	/*
	 * @brief Creates a shader that uses additional texture coordinates in the vertex array (vertex format VT or TV) to assign a point on a texture to each vertex.
	 * Interpolates the texture in between vertices.
	 * @return The resulting shader.
	 */
	MgShader Texture();

	/*
	 * @brief Creates a shader that uses a combination of texture coordinates (see Texture() for more info) and RGB color values (vertex format VCT, VTC, etc).
	 * Colors the texture that color, but keeps the... well... texture.
	 * @return The resulting shader.
	 */
	MgShader ColorTexture();
}
