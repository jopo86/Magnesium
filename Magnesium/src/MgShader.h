#pragma once

#include <glad/glad.h>

#include "Magnesium.h"
#include "MgErrorHandler.h"
#include "MgDisposable.h"

class MgShader : public MgDisposable
{
public:
	MgShader();
	MgShader(const char* vertSource, const char* fragSource);
	MgShader(const char* vertSource, const char* fragSource, MgErrorHandler& errorHandler);

	void use();
	void unuse();

	uint getProgram();
	const char* getVertSource();
	const char* getFragSource();

	void uniform(const char* name, float v0, float v1, float v2, float v3);

	void dispose() override;

private:
	uint prog;
	const char* vertSource, * fragSource;
};
