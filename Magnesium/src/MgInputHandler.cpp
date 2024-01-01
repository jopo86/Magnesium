#include "MgInputHandler.h"

MgInputHandler::MgInputHandler()
{
	window = nullptr;
	p_window = nullptr;
	mouseX = mouseY = 0;
	cursorLocked = false;
}

MgInputHandler::MgInputHandler(MgWindow& window)
{
	this->window = &window;
	p_window = this->window->getGlfwWindowPtr();
	glfwSetKeyCallback(p_window, keyCB);
	this->window->inputHandler = this;
	mouseX = mouseY = 0;
	cursorLocked = false;
}

bool MgInputHandler::isKeyDown(int key)
{
	return keyStates[key] == GLFW_PRESS;
}

bool MgInputHandler::isKeyUp(int key)
{
	return keyStates[key] == GLFW_RELEASE;
}

bool MgInputHandler::isMouseButtonDown(int button)
{
	return glfwGetMouseButton(p_window, button) == GLFW_PRESS;
}

bool MgInputHandler::isMouseButtonUp(int button)
{
	return glfwGetMouseButton(p_window, button) == GLFW_RELEASE;
}

void MgInputHandler::lockCursor()
{
	glfwSetInputMode(p_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	cursorLocked = true;
}

void MgInputHandler::unlockCursor()
{
	glfwSetInputMode(p_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	cursorLocked = false;
}

void MgInputHandler::toggleCursorLock()
{
	if (cursorLocked) unlockCursor();
	else lockCursor();
}

MgWindow* MgInputHandler::getWindow()
{
	return window;
}

double MgInputHandler::getMouseX()
{
	glfwGetCursorPos(p_window, &mouseX, &mouseY);
	return mouseX;
}

double MgInputHandler::getMouseY()
{
	glfwGetCursorPos(p_window, &mouseX, &mouseY);
	return mouseY;
}

void MgInputHandler::keyCB(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	((MgWindow*)glfwGetWindowUserPointer(window))->inputHandler->keyStates[key] = action;
}
