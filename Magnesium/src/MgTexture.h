#pragma once

#include <glad/glad.h>

#include "Magnesium.h"
#include "MgImageData.h"

/*
 * @brief A class to represent a texture that can be applied to a mesh, preferably via a renderable.
 * This class is disposable.
 */
class MgTexture : public MgDisposable
{
public:
	/*
	 * @brief Creates an empty MgTexture object.
	 * Trying to use a texture constructed like this will most likely cause errors.
	 */
	MgTexture();
	
	/*
	 * @brief Creates a new MgTexture object from the specified image data.
	 * Disposes of the image data after use.
	 * This should be used for image data created anonymously, not as a variable.
	 * @param imageData The image data to use and dispose.
	 */
	MgTexture(MgImageData imageData);

	/*
	 * @brief Creates a new MgTexture object from the specified image data.
	 * Disposes of the image data after use if the second argument is true.
	 * This should be used for image data created as a variable, not anonymously.
	 * @param imageData The image data to use.
	 * @param disposeImageData Whether to dispose the image data after use.
	 */
	MgTexture(MgImageData& imageData, bool disposeImageData);

	/*
	 * @brief Gets the ID of the texture in OpenGL.
	 * Access to the texture ID is provided for the library, as well as for advanced users.
	 * @return The ID of the OpenGL texture.
	 */
	uint getTextureID();

	/*
	 * @brief Disposes of the texture.
	 * This clears up any memory that the object was using.
	 * This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
	 */
	void dispose() override;

private:
	uint tex;
};
