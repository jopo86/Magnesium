#pragma once

/*
 * @brief A namespace providing useful graphics settings.
 */

#include <glad/glad.h>

#include "Magnesium.h"

namespace MgGraphics
{
	/*
	 * @brief Sets whether to render full objects, or only their outlines.
	 * Wireframe renders only render lines between vertices.
	 * @param enabled Whether wireframe mode is enabled/disabled.
	 */
	void SetWireframe(bool enabled);

	/*
	 * @brief Sets the width of lines rendered (for wireframe mode).
	 * @param width The width of the lines, in pixels.
	 */
	void SetLineWidth(float width);
}
