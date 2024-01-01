#include "MgWindow.h"

using MgMath::MgVec3;

MgWindow::MgWindow()
{
	p_window = nullptr;
	title = "Magnesium Window";
	width = 800;
	height = 600;
	bufferWidth = bufferHeight = 0;
	initialized = fullscreen = false;
}

MgWindow::MgWindow(const char* title, int width, int height)
{
	p_window = nullptr;
	this->title = title;
	this->width = width;
	this->height = height;
	bufferWidth = bufferHeight = 0;
	initialized = fullscreen = false;
}

void MgWindow::init()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef MG_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	p_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(p_window);
	glfwGetFramebufferSize(p_window, &bufferWidth, &bufferHeight);
	glfwSetWindowUserPointer(p_window, this);
	glfwSetFramebufferSizeCallback(p_window, framebufferSizeCB);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, bufferWidth, bufferHeight);
	glEnable(GL_DEPTH_TEST);

	initialized = true;
}

void MgWindow::init(MgErrorHandler& errorHandler)
{
	if (!glfwInit())
	{
		errorHandler.err("failed to initialize GLFW.");
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef MG_OS_MAC
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	p_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (p_window == nullptr)
	{
		errorHandler.err("failed to create GLFW window.");
		return;
	}

	glfwMakeContextCurrent(p_window);
	glfwGetFramebufferSize(p_window, &bufferWidth, &bufferHeight);
	glfwSetWindowUserPointer(p_window, this);
	glfwSetFramebufferSizeCallback(p_window, framebufferSizeCB);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		errorHandler.err("failed to initialize OpenGL.");
		return;
	}

	glViewport(0, 0, bufferWidth, bufferHeight);
	glEnable(GL_DEPTH_TEST);

	initialized = true;
}

void MgWindow::startRender()
{
	glClearColor(background.getX(), background.getY(), background.getZ(), 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MgWindow::endRender()
{
	glfwPollEvents();
	glfwSwapBuffers(p_window);
}

void MgWindow::setWindowed()
{
	glfwSetWindowMonitor(p_window, nullptr, 0, 0, width, height, 0);
	fullscreen = false;
}

void MgWindow::setFullscreen()
{
	const GLFWvidmode* monitorInfo = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSetWindowMonitor(p_window, glfwGetPrimaryMonitor(), 0, 0, monitorInfo->width, monitorInfo->height, monitorInfo->refreshRate);
	fullscreen = true;
}

void MgWindow::toggleFullscreen()
{
	if (fullscreen) setWindowed();
	else setFullscreen();
}

void MgWindow::close()
{
	glfwSetWindowShouldClose(p_window, GLFW_TRUE);
	initialized = false;
}

GLFWwindow* MgWindow::getGlfwWindowPtr()
{
	return p_window;
}

const char* MgWindow::getTitle()
{
	return title;
}

int MgWindow::getWidth()
{
	return width;
}

int MgWindow::getHeight()
{
	return height;
}

int MgWindow::getBufferWidth()
{
	return bufferWidth;
}

int MgWindow::getBufferHeight()
{
	return bufferHeight;
}

bool MgWindow::isInitialized()
{
	return initialized;
}

bool MgWindow::isOpen()
{
	return !glfwWindowShouldClose(p_window);
}

void MgWindow::setBackgroundColor(MgVec3 rgb)
{
	background = rgb;
}

void MgWindow::dispose()
{
	if (initialized)
	{
		glfwDestroyWindow(p_window);
	}

	p_window = nullptr;
	title = "";
	width = height = bufferWidth = bufferHeight = 0;
	initialized = false;
}

void MgWindow::framebufferSizeCB(GLFWwindow* p_window, int width, int height)
{
	glViewport(0, 0, width, height);

	MgWindow* p_mgWindow = (MgWindow*)glfwGetWindowUserPointer(p_window);
	p_mgWindow->bufferWidth = width;
	p_mgWindow->bufferHeight = height;
}

void MgWindow::keyCB(GLFWwindow* p_window, int key, int scancode, int action, int mods)
{
	MgWindow* p_mgWindow = (MgWindow*)glfwGetWindowUserPointer(p_window);
	p_mgWindow->keyStates[key] = action;
}
