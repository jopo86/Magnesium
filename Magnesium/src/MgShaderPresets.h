#pragma once

#include "MgShader.h"
#include "MgUtils.h"
#include "MgMath.h"

namespace MgShaderPresets
{
	using MgMath::MgVec3;

	MgShader Color(MgVec3 rgb);
	MgShader VertexColor();
	MgShader VertexTexture();
	MgShader VertexColorTexture();
}
