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
	return MgShader(vertSource.c_str(), fragSource.c_str());
}

MgShader MgShaderPresets::Texture()
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/TexturePreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/TexturePreset.frag");
	return MgShader(vertSource.c_str(), fragSource.c_str());
}

MgShader MgShaderPresets::ColorTexture()
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/ColorTexturePreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/ColorTexturePreset.frag");
	return MgShader(vertSource.c_str(), fragSource.c_str());
}
