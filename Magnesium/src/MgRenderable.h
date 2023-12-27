#pragma once

#include <vector>

#include "Magnesium.h"
#include "MgMath.h"
#include "MgMesh.h"
#include "MgShader.h"
#include "MgTexture.h"

/*
 * @brief A class that represents a renderable object.
 * A renderable can be rendered directly, or through the MgRenderer class.
 */
class MgRenderable : public MgDisposable
{
public:
	/*
	 * @brief Creates an empty MgRenderable object.
	 * Trying to use a renderable constructed like this will most likely cause errors.
	 */
	MgRenderable();

	/*
	 * @brief Creates a new MgRenderable object out of the specified mesh.
	 * @param mesh The mesh to use.
	 */
	MgRenderable(MgMesh& mesh);

	/*
	 * @brief Creates a new MgRenderable object out of the specified mesh and shader.
	 * @param mesh The mesh to use.
	 * @param shader The shader to use.
	 */
	MgRenderable(MgMesh& mesh, MgShader& shader);

	/*
	 * @brief Creates a new MgRenderable object out of the specified mesh, shader, and texture.
	 * @param mesh The mesh to use.
	 * @param shader The shader to use.
	 * @param texture The texture to use.
	 */
	MgRenderable(MgMesh& mesh, MgShader& shader, MgTexture& texture);

	/*
	 * @brief Renders the object.
	 * This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
	 */
	void render();

	/*
	 * @brief Changes the renderable's position by the specified 3D vector.
	 * Note that this function inc/decrements the renderable's position, it does not set it.
	 * Directly setting a transform is not natively supported, that would be up to the user to program.
	 * @param xyz The vector to move by.
	 */
	void translate(MgMath::MgVec3 xyz);

	/*
	 * @brief Rotates the renderable by the specified degree angle around the specified axes.
	 * Note that this function inc/decrements the renderable's rotation, it does not set it.
	 * Directly setting a transform is not natively supported, that would be up to the user to program.
	 * @param degrees The degree angle to rotate.
	 * @param axes The axes to rotate around. Here are some examples:
	 * (1, 0, 0) will rotate the specified angle around the x axis.
	 * (1, 1, 1) will rotate the specified angle around all axes.
	 * (0, 0.5, 0) will rotate half the specified angle around the y axis.
	 * (0.6, 0, 1) will rotate 6/10 the specified angle around the x axis and the full specified angle around the z axis.
	 * Numbers below 0 or above 1 will be treated as 0 or 1 respectively.
	 */
	void rotate(float degrees, MgMath::MgVec3 axes);

	/*
	 * @brief Scales the renderable in all dimensions by the specified scalar.
	 * Note that this function scales the renderable by whatever its current scale is, it does not set its scale. 
	 * This means that scale(1) will not reset the renderable's scale, it just wont change it at all.
	 * Directly setting a transform is not natively supported, that would be up to the user to program.
	 * @param scalar The scale multiplier.
	 * If the scalar is 0, it will effectively hide the renderable.
	 */
	void scale(float scalar);

	/*
	 * @brief Scales the renderable by the scalars for each dimension.
	 * Note that this function scales the renderable by whatever its current scale is, it does not set its scale.
	 * This means that scale(1) will not reset the renderable's scale, it just wont change it at all.
	 * Directly setting a transform is not natively supported, that would be up to the user to program.
	 * @param xyzScalar The scalars for each dimension. Here are some examples:
	 * (1, 1, 1) will not change anything.
	 * (1, 0.5, 1) will half the renderable's size on the y axis.
	 * (0.5, 0.5, 2) will half the renderable's size on the x and y axes, and double it's size on the z axis.
	 * If any scalar is 0, it will effectively hide the renderable.
	 */
	void scale(MgMath::MgVec3 xyzScalar);

	/*
	 * @brief Resets the renderable's transforms.
	 * This resets its position to its original vertex positions, its rotation to 0, and its scale to 1.
	 */
	void resetTransform();

	/*
	 * @brief Gets the mesh associated with the renderable.
	 * @return A pointer to the mesh.
	 */
	MgMesh* getMesh();

	/*
	 * @brief Gets the shader associated with the renderable.
	 * @return A pointer to the shader.
	 */
	MgShader* getShader();

	/*
	 * @brief Gets the texture associated with the renderable.
	 * @return A pointer to the texture.
	 */
	MgTexture* getTexture();

	/*
	 * @brief Disposes of the renderable, including the associated mesh, shader, and texture.
	 * This clears up any memory that the object was using.
	 * This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
	 */
	void dispose() override;

private:
	MgMesh* mesh;
	MgShader* shader;
	MgTexture* texture;

	MgMath::MgMat4 model;
};
