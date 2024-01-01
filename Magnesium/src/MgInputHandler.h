#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Magnesium.h"
#include "MgWindow.h"
#include "MgGraphics.h"

/*
 * @brief A class to handle input from a window.
 * This class can be used to access the state of keys and mouse buttons, as well as the mouse position.
 * It can also lock/unlock the cursor.
 */
class MgInputHandler
{
public:
	/*
	 * @brief Creates an empty MgInputHandler object.
	 * Trying to use an input handler constructed like this will most likely cause errors.
	 */
	MgInputHandler();

	/*
	 * @brief Creates a new MgInputHandler object that gets input from the specified window.
	 * @param window The window to get input from.
	 */
	MgInputHandler(MgWindow& window);

	/*
	 * @brief Gets whether the specified key is currently pressed down.
	 * @param key The key to check. Use the definitions prefixed with MG_KEY.
	 */
	bool isKeyDown(int key);

	/*
	 * @brief Gets whether the specified key is currently idle / not pressed down.
	 * @param key The key to check. Use the definitions prefixed with MG_KEY.
	 */
	bool isKeyUp(int key);

	/*
	 * @brief Gets whether the specified mouse button is currently pressed down.
	 * @param button The mouse button to check. Use the definitions prefixed with MG_MOUSE_BUTTON.
	 */
	bool isMouseButtonDown(int button);

	/*
	 * @brief Gets whether the specified mouse button is currently idle / not pressed down.
	 * @param button The mouse button to check. Use the definitions prefixed with MG_MOUSE_BUTTON.
	 */
	bool isMouseButtonUp(int button);

	/*
	 * @brief Hides the cursor and locks its movement.
	 */
	void lockCursor();

	/*
	 * @brief Shows the cursor and unlocks its movement.
	 */
	void unlockCursor();

	/*
	 * @brief Toggles the cursor lock state.
	 */
	void toggleCursorLock();

	/*
	 * @brief Gets the window that the input handler is associated with.
	 * @return A pointer to the window the input handler gets input from.
	 */
	MgWindow* getWindow();

	/*
	 * @brief Gets the horizontal position of the mouse cursor.
	 * @return The X screen coordinate of the mouse cursor.
	 */
	double getMouseX();

	/*
	 * @brief Gets the vertical position of the mouse cursor.
	 * @return The Y screen coordinate of the mouse cursor.
	 */
	double getMouseY();

private:
	MgWindow* window;
	GLFWwindow* p_window;
	double mouseX, mouseY;
	bool cursorLocked;

	int keyStates[MG_MAX_KEY] = { 0 };

	static void keyCB(GLFWwindow* window, int key, int scancode, int action, int mods);
};
