#include "MgShader.h"

MgShader::MgShader() : vertSource(""), fragSource("")
{
	prog = 0;
}

MgShader::MgShader(const char* vertSource, const char* fragSource) : vertSource(vertSource), fragSource(fragSource)
{
	uint vert = glCreateShader(GL_VERTEX_SHADER);
	uint frag = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vert, 1, &vertSource, nullptr);
	glShaderSource(frag, 1, &fragSource, nullptr);

	glCompileShader(vert);
	glCompileShader(frag);

	prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);
	glLinkProgram(prog);

	glDeleteShader(vert);
	glDeleteShader(frag);
}

MgShader::MgShader(const char* vertSource, const char* fragSource, MgErrorHandler& errorHandler) : vertSource(vertSource), fragSource(fragSource)
{
	uint vert = glCreateShader(GL_VERTEX_SHADER);
	uint frag = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vert, 1, &vertSource, nullptr);
	glShaderSource(frag, 1, &fragSource, nullptr);

	int result;

	glCompileShader(vert);
	glGetShaderiv(vert, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		char infoBuffer[MG_BUFFER_SIZE];
		glGetShaderInfoLog(vert, MG_BUFFER_SIZE, nullptr, infoBuffer);
		errorHandler.err("failed to compile a vertex shader, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		return;
	}

	glCompileShader(frag);
	glGetShaderiv(frag, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		char infoBuffer[MG_BUFFER_SIZE];
		glGetShaderInfoLog(frag, MG_BUFFER_SIZE, nullptr, infoBuffer);
		errorHandler.err("failed to compile a fragment shader, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		return;
	}

	prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);

	glLinkProgram(prog);
	glGetProgramiv(prog, GL_LINK_STATUS, &result);
	if (!result)
	{
		char infoBuffer[MG_BUFFER_SIZE];
		glGetProgramInfoLog(prog, MG_BUFFER_SIZE, nullptr, infoBuffer);
		errorHandler.err("failed to link a shader program, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		return;
	}

	glValidateProgram(prog);
	glGetProgramiv(prog, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		char infoBuffer[MG_BUFFER_SIZE];
		glGetProgramInfoLog(prog, MG_BUFFER_SIZE, nullptr, infoBuffer);
		errorHandler.err("failed to validate a shader program, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		return;
	}

	glDeleteShader(vert);
	glDeleteShader(frag);
}

void MgShader::use()
{
	glUseProgram(prog);
}

void MgShader::UseDefault()
{
	glUseProgram(0);
}

uint MgShader::getProgram()
{
	return prog;
}

const char* MgShader::getVertSource()
{
	return vertSource;
}

const char* MgShader::getFragSource()
{
	return fragSource;
}

void MgShader::dispose()
{
	if (prog) glDeleteProgram(prog);
	prog = 0;
	vertSource = fragSource = "";
}
