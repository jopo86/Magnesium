#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Magnesium.h"
#include "MgWindow.h"
#include "MgDisposable.h"

class MgInputHandler : public MgDisposable
{
public:
	MgInputHandler();
	MgInputHandler(MgWindow window);

	bool isKeyDown(int key);
	bool isKeyUp(int key);
	bool isMouseButtonDown(int button);
	bool isMouseButtonUp(int button);

	void lockCursor();
	void unlockCursor();

	MgWindow getWindow();
	double getMouseX();
	double getMouseY();

	void dispose() override;

private:
	GLFWwindow* p_window;
	double mouseX, mouseY;
};
