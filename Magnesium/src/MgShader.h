#pragma once

#include <glad/glad.h>

#include "Magnesium.h"
#include "MgErrorHandler.h"

class MgShader : public MgObject
{
public:
	MgShader();
	MgShader(const char* vertSource, const char* fragSource);
	MgShader(const char* vertSource, const char* fragSource, MgErrorHandler& errorHandler);

	void use();
	static void UseDefault();

	uint getProgram();
	const char* getVertSource();
	const char* getFragSource();

	void dispose() override;

private:
	uint prog;
	const char* vertSource, * fragSource;
};
