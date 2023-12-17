#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Magnesium.h"
#include "MgObject.h"
#include "MgErrorHandler.h"

/*
 * @brief A class that represents a window.
 * Note that init() must be called on the window object after it is created to use it.
 */
class MgWindow : public MgObject
{
public:
	/*
	 * @brief Creates a new MgWindow object with title "Magnesium Window" and dimensions 800x600.
	 */
	MgWindow();

	/*
	 * @brief Creates a new MgWindow object with the specified title and dimensions.
	 * @param title The title of the window.
	 * @param width The width of the window.
	 * @param height The height of the window.
	 */
	MgWindow(std::string title, int width, int height);

	/*
	 * @brief Initializes the window.
	 * This function initializes the backends, including GLFW and GLAD.
	 * Must be called before any other window-related functions,
	 * will cause undefined behavior otherwise.
	 */
	void init();

	/*
	 * @brief Initializes the window.
	 * This function initializes the backends, including GLFW and GLAD.
	 * Must be called before any other window-related functions, will cause undefined behavior otherwise.
	 * @param errorHandler The error handler to use if something goes wrong.
	 */
	void init(MgErrorHandler& errorHandler);

	/*
	 * @brief Clears the screen and gets ready to render.
	 * Should be called before any rendering is done.
	 */
	void startRender();

	/*
	 * @brief Tells the window that rendering is done.
	 * This function swaps window buffers and polls input events.
	 * Should be called after all rendering is done.
	 */
	void endRender();

	/*
	 * @brief Closes the window.
	 * Once this function is called, isOpen() will return false.
	 */
	void close();

	/*
	 * @brief Access to the GLFW window is provided for advanced users only.
	 * @return A pointer to the GLFW window.
	 */
	GLFWwindow* getGlfwWindowPtr();

	/*
	 * @brief Returns the title of the window.
	 * @return The title of the window.
	 */
	std::string getTitle();

	/*
	 * @brief Returns the width of the window.
	 * @return The width of the window.
	 */
	int getWidth();

	/*
	 * @brief Returns the height of the window.
	 * @return The height of the window.
	 */
	int getHeight();

	/*
	 * @brief Returns the width of the rendering part of the window, not including the title bar or borders.
	 * @return The buffer width of the window, explained above.
	 */
	int getBufferWidth();

	/*
	 * @brief Returns the height of the rendering part of the window, not including the title bar or borders.
	 * @return The buffer height of the window, explained above.
	 */
	int getBufferHeight();

	/*
	 * @brief Returns true if init() has been called on the window, otherwise false.
	 * @return Whether or not the window has been initialized.
	 */
	bool isInitialized();

	/*
	 * @brief Returns whether or not the window is open.
	 * @return Whether or not the window is open.
	 */
	bool isOpen();

	/*
	 * @brief Cleans up any memory and/or resources used by the window.
	 * This function should be called when the object is no longer needed, such as when the program exits or the object goes out of scope.
	 */
	void cleanup();

private:
	GLFWwindow* p_window;
	std::string title;
	int width, height, bufferWidth, bufferHeight;

	bool initialized;

	static void framebufferSizeCB(GLFWwindow* p_window, int width, int height);
};
