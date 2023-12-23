#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Magnesium.h"
#include "MgDisposable.h"
#include "MgErrorHandler.h"
#include "MgMath.h"

class MgWindow : public MgDisposable
{

public:
	MgWindow();
	MgWindow(const char* title, int width, int height);

	void init();
	void init(MgErrorHandler& errorHandler);

	void startRender();
	void endRender();

	void close();

	GLFWwindow* getGlfwWindowPtr();
	const char* getTitle();
	int getWidth();
	int getHeight();
	int getBufferWidth();
	int getBufferHeight();
	bool isInitialized();
	bool isOpen();

	void setBackgroundColor(MgMath::MgVec3 rgb);

	void dispose() override;

private:
	GLFWwindow* p_window;
	const char* title;
	int width, height, bufferWidth, bufferHeight;
	float bgR;
	float bgG;
	float bgB;

	bool initialized;

	static void framebufferSizeCB(GLFWwindow* p_window, int width, int height);
};
