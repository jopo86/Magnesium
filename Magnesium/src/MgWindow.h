#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Magnesium.h"
#include "MgObject.h"
#include "MgErrorHandler.h"

class MgWindow : public MgObject
{
public:
	MgWindow();
	MgWindow(std::string title, int width, int height);

	void init();
	void init(MgErrorHandler& errorHandler);

	void startRender();
	void endRender();

	void close();

	GLFWwindow* getGlfwWindowPtr();
	std::string getTitle();
	int getWidth();
	int getHeight();
	int getBufferWidth();
	int getBufferHeight();
	bool isInitialized();
	bool isOpen();

	void dispose();

private:
	GLFWwindow* p_window;
	std::string title;
	int width, height, bufferWidth, bufferHeight;

	bool initialized;

	static void framebufferSizeCB(GLFWwindow* p_window, int width, int height);
};
