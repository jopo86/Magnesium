#include "MgInputHandler.h"

MgInputHandler::MgInputHandler()
{
	p_window = nullptr;
	mouseX = mouseY = 0;
}

MgInputHandler::MgInputHandler(MgWindow window)
{
	p_window = window.getGlfwWindowPtr();
	mouseX = mouseY = 0;
}

bool MgInputHandler::isKeyDown(int key)
{
	return glfwGetKey(p_window, key) == GLFW_PRESS;
}

bool MgInputHandler::isKeyUp(int key)
{
	return glfwGetKey(p_window, key) == GLFW_RELEASE;
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
}

void MgInputHandler::unlockCursor()
{
	glfwSetInputMode(p_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

MgWindow MgInputHandler::getWindow()
{
	return *((MgWindow*)glfwGetWindowUserPointer(p_window));
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

void MgInputHandler::dispose()
{
	p_window = nullptr;
	mouseX = mouseY = 0;
}
