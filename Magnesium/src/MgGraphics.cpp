#include "MgGraphics.h"

void MgGraphics::SetWireframe(bool enabled)
{
	glPolygonMode(GL_FRONT_AND_BACK, enabled ? GL_LINE : GL_FILL);
}

void MgGraphics::SetLineWidth(float width)
{
	glLineWidth(width);
}
