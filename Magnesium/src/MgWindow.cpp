#include "MgWindow.h"

MgWindow::MgWindow()
{
	p_window = nullptr;
	title = "Magnesium Window";
	width = 800;
	height = 600;
	bufferWidth = bufferHeight = 0;
	initialized = false;
}

MgWindow::MgWindow(std::string title, int width, int height)
{
	p_window = nullptr;
	this->title = title;
	this->width = width;
	this->height = height;
	bufferWidth = bufferHeight = 0;
	initialized = false;
}

void MgWindow::init()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	p_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
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

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	p_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MgWindow::endRender()
{
	glfwSwapBuffers(p_window);
	glfwPollEvents();
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

std::string MgWindow::getTitle()
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
