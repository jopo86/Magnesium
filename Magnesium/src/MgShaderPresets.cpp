#include "MgShaderPresets.h"

MgShader MgShaderPresets::Color(MgVec3 rgb)
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/ColorPreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/ColorPreset.frag");
	MgShader shader(vertSource.c_str(), fragSource.c_str());
	shader.use();
	shader.uniform("u_color", rgb.getX(), rgb.getY(), rgb.getZ(), 1.0f);
	shader.unuse();
	return shader;
}

MgShader MgShaderPresets::VertexColor()
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/VertexColorPreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/VertexColorPreset.frag");
	MgShader shader(vertSource.c_str(), fragSource.c_str());
	return shader;
}

MgShader MgShaderPresets::VertexTexture()
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/VertexTexturePreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/VertexTexturePreset.frag");
	MgShader shader(vertSource.c_str(), fragSource.c_str());
	return shader;
}

MgShader MgShaderPresets::VertexColorTexture()
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/VertexColorTexturePreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/VertexColorTexturePreset.frag");
	MgShader shader(vertSource.c_str(), fragSource.c_str());
	return shader;
}
