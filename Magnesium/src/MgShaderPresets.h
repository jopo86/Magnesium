#pragma once

#include "MgShader.h"
#include "MgUtils.h"

namespace MgShaderPresets
{
	MgShader Color(float r, float g, float b);
	MgShader VertexColor();
	MgShader VertexTexture();
	MgShader VertexColorTexture();
}
