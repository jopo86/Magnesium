#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Magnesium.h"
#include "MgErrorHandler.h"
#include "MgMath.h"

/*
 * @brief A class to represent a window.
 * A window must be created and initialized for anything related to OpenGL to occur.
 * Window creation and initialization be the first thing done before any other Magnesium functions.
 * This class is disposable.
 */
class MgWindow : public MgDisposable
{
public:
	/*
	 * @brief Creates an uninitialized 800x600 window with the name "Magnesium Window"
	 */
	MgWindow();

	/*
	 * @brief Creates an uninitialized window with the specified title and dimensions.
	 * @param title The title of the window, usually shown on the left of the top border.
	 * @param width The width of the window, in pixels.
	 * @param height The height of the window, in pixels.
	 */
	MgWindow(const char* title, int width, int height);

	/*
	 * @brief Initializes the window.
	 * This initializes the backends, including GLFW and OpenGL.
	 * This function needs to be called before anything related to OpenGL occurs.
	 * This function may cause errors, it is recommended to use the overload with an error handler.
	 */
	void init();

	/*
	 * @brief Initializes the window.
	 * Passes any OpenGL or GLFW initialization errors to the specified error handler.
	 * This initializes the backends, including GLFW and OpenGL.
	 * This function needs to be called before anything related to OpenGL occurs.
	 * @param errorHandler The error handler to use.
	 */
	void init(MgErrorHandler& errorHandler);

	/*
	 * @brief Prepares to render the current frame.
	 * This function clears the screen to the background color, and clears the color and depth buffers.
	 */
	void startRender();

	/*
	 * @brief Finishes rendering the current frame.
	 * This function polls GLFW events and swaps the window buffers.
	 */
	void endRender();

	/*
	 * @brief Closes the window.
	 * Once called, isOpen() will return false.
	 */
	void close();

	/*
	 * @brief Gets the GLFW window pointer.
	 * Access to the GLFW window is provided for the library, as well as for advanced users.
	 * @return A pointer to the GLFW window.
	 */
	GLFWwindow* getGlfwWindowPtr();

	/*
	 * @brief Gets the title of the window.
	 * @return The title of the window.
	 */
	const char* getTitle();

	/*
	 * @brief Gets the width of the window.
	 * @return The width of the window.
	 */
	int getWidth();

	/*
	 * @brief Gets the height of the window.
	 * @return The height of the window.
	 */
	int getHeight();

	/*
	 * @brief Gets the width of the rendering frame of the window, not including borders.
	 * @return The buffer width of the window, explained above.
	 */
	int getBufferWidth();

	/*
	 * @brief Gets the height of the rendering frame of the window, not including borders.
	 * @return The buffer height of the window, explained above.
	 */
	int getBufferHeight();

	/*
	 * @brief Gets the initialization status of the window.
	 * @return Whether the window has been initialized.
	 */
	bool isInitialized();

	/*
	 * @brief Gets the open/closed status of the window.
	 * @return Whether the window is open.
	 */
	bool isOpen();

	/*
	 * @brief Sets the background color of the window.
	 * This is what color the window clears to at the start of each frame.
	 * @param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
	 */
	void setBackgroundColor(MgMath::MgVec3 rgb);

	/*
	 * @brief Disposes of the window.
	 * This clears up any memory that the object was using.
	 * This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
	 */
	void dispose() override;

private:
	GLFWwindow* p_window;
	const char* title;
	int width, height, bufferWidth, bufferHeight;
	MgMath::MgVec3 background;

	bool initialized;

	static void framebufferSizeCB(GLFWwindow* p_window, int width, int height);
};
