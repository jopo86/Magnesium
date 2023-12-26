#pragma once

#include <glad/glad.h>

#include "Magnesium.h"
#include "MgErrorHandler.h"
#include "MgMath.h"

class MgShader : public MgDisposable
{
public:
	MgShader();
	MgShader(const char* vertSource, const char* fragSource);
	MgShader(const char* vertSource, const char* fragSource, MgErrorHandler& errorHandler);

	uint getProgramID();
	const char* getVertSource();
	const char* getFragSource();

	void uniform(const char* name, float v0, float v1, float v2, float v3);
	void uniform(const char* name, MgMath::MgMat4 val);

	void dispose() override;

private:
	uint prog;
	const char* vertSource, * fragSource;
};
