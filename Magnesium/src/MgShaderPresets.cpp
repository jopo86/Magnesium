#include "MgShaderPresets.h"

MgShader MgShaderPresets::Color(float r, float g, float b)
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/ColorPreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/ColorPreset.frag");
	MgShader shader(vertSource.c_str(), fragSource.c_str());
	shader.use();
	shader.uniform("u_color", r, g, b, 1.0f);
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
