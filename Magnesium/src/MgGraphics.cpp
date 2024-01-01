#include "MgGraphics.h"

bool wireframe = false;

void MgGraphics::SetWireframe(bool enabled)
{
	glPolygonMode(GL_FRONT_AND_BACK, enabled ? GL_LINE : GL_FILL);
	wireframe = enabled;
}

void MgGraphics::ToggleWireframe()
{
	if (wireframe) SetWireframe(false);
	else SetWireframe(true);
}

void MgGraphics::SetLineWidth(float width)
{
	glLineWidth(width);
}
