#pragma once

#include <fstream>

#include "Magnesium.h"
#include "MgErrorHandler.h"

/*
 * @brief A class to contain image data.
 * This includes the actual byte data of the image, dimensions, and the format (RGB/RGBA).
 * This class is disposable.
 */
class MgImageData : public MgDisposable
{
public:
	/*
	 * @brief Creates an empty MgImageData object.
	 * Trying to use image data constructed like this will most likely cause errors.
	 */
	MgImageData();

	/*
	 * @brief Creates a new MgImageData object with the specified byte data, dimensions, and format.
	 * Format is specified by number of channels: 3 = RGB, 4 = RGBA.
	 */
	MgImageData(ubyte* data, int width, int height, int nChannels);

	/*
	 * @brief Creates a new MgImageData object from the image at the specified file path.
	 * This function may cause errors, it is recommended to use the overload with an error handler.
	 * @param filepath The file path to the image.
	 * @return The MgImageData object that was created.
	 */
	static MgImageData Load(const char* filepath);

	/*
	 * @brief Creates a new MgImageData object from the image at the specified file path.
	 * Passes an error to the specified error handler if the file was not found.
	 * @param filepath The file path to the image.
	 * @param errorHandler The error handler to use.
	 * @return The MgImageData object that was created.
	 */
	static MgImageData Load(const char* filepath, MgErrorHandler& errorHandler);

	/*
	 * @brief Gets the actual byte data of the image.
	 * This is used by the library, it does not have much use for the user.
	 * @return A pointer (array) to the byte data.
	 */
	ubyte* getData();

	/*
	 * @brief Gets the width of the image.
	 * @return The width of the image.
	 */
	int getWidth();

	/*
	 * @brief Gets the height of the image.
	 * @return The height of the image.
	 */
	int getHeight();

	/*
	 * @brief Gets the format of the image.
	 * @return The format of the image as a number of channels: 3 = RGB, 4 = RGBA.
	 */
	int getNChannels();

	/*
	 * @brief Disposes of the image data.
	 * This clears up any memory that the object was using.
	 * This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
	 */
	void dispose() override;

private:
	ubyte* data;
	int width, height, nChannels;
};
