#include "MgShaderPresets.h"

MgShader MgShaderPresets::Color(MgVec3 rgb)
{
	MgShader shader(MgFile("src/shaders/ColorPreset.vert").readLiteral(), MgFile("src/shaders/ColorPreset.frag").readLiteral());
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
	MgShader shader(MgFile("src/shaders/VertexColorPreset.vert").readLiteral(), MgFile("src/shaders/VertexColorPreset.frag").readLiteral());
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", MgMath::MgMat4(1.0f));
	shader.uniform("u_view", MgMath::MgMat4(1.0f));
	shader.uniform("u_projection", MgMath::MgMat4(1.0f));
	glUseProgram(0);
	return shader;
}

MgShader MgShaderPresets::Texture()
{
	MgShader shader(MgFile("src/shaders/TexturePreset.vert").readLiteral(), MgFile("src/shaders/TexturePreset.frag").readLiteral());
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", MgMath::MgMat4(1.0f));
	shader.uniform("u_view", MgMath::MgMat4(1.0f));
	shader.uniform("u_projection", MgMath::MgMat4(1.0f));
	glUseProgram(0);
	return shader;
}

MgShader MgShaderPresets::ColorTexture()
{
	MgShader shader(MgFile("src/shaders/ColorTexturePreset.vert").readLiteral(), MgFile("src/shaders/ColorTexturePreset.frag").readLiteral());
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", MgMath::MgMat4(1.0f));
	shader.uniform("u_view", MgMath::MgMat4(1.0f));
	shader.uniform("u_projection", MgMath::MgMat4(1.0f));
	glUseProgram(0);
	return shader;
}
