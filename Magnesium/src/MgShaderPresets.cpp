#include "MgShaderPresets.h"

MgShader MgShaderPresets::Color(MgVec3 rgb)
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/ColorPreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/ColorPreset.frag");
	MgShader shader(vertSource.c_str(), fragSource.c_str());
	glUseProgram(shader.getProgramID());
	shader.uniform("u_color", rgb.getX(), rgb.getY(), rgb.getZ(), 1.0f);
	shader.uniform("u_model", MgMath::MgMat4(1.0f));
	shader.uniform("u_view", MgMath::MgMat4(1.0f));
	shader.uniform("u_projection", MgMath::MgMat4(1.0f));
	glUseProgram(0);
	return shader;
}

MgShader MgShaderPresets::VertexColor()
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/VertexColorPreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/VertexColorPreset.frag");
	MgShader shader(vertSource.c_str(), fragSource.c_str());
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", MgMath::MgMat4(1.0f));
	shader.uniform("u_view", MgMath::MgMat4(1.0f));
	shader.uniform("u_projection", MgMath::MgMat4(1.0f));
	glUseProgram(0);
	return shader;
}

MgShader MgShaderPresets::Texture()
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/TexturePreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/TexturePreset.frag");
	MgShader shader(vertSource.c_str(), fragSource.c_str());
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", MgMath::MgMat4(1.0f));
	shader.uniform("u_view", MgMath::MgMat4(1.0f));
	shader.uniform("u_projection", MgMath::MgMat4(1.0f));
	glUseProgram(0);
	return shader;
}

MgShader MgShaderPresets::ColorTexture()
{
	std::string vertSource = MgUtils::ReadFile("src/shaders/ColorTexturePreset.vert");
	std::string fragSource = MgUtils::ReadFile("src/shaders/ColorTexturePreset.frag");
	MgShader shader(vertSource.c_str(), fragSource.c_str());
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", MgMath::MgMat4(1.0f));
	shader.uniform("u_view", MgMath::MgMat4(1.0f));
	shader.uniform("u_projection", MgMath::MgMat4(1.0f));
	glUseProgram(0);
	return shader;
}
