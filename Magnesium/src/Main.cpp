#include <iostream>

#include "MgWindow.h"
#include "MgErrorHandler.h"
#include "MgInputHandler.h"
#include "MgMesh.h"
#include "MgMeshPresets.h"
#include "MgShader.h"
#include "MgShaderPresets.h"
#include "MgMath.h"

using MgMath::MgVec3;

int main()
{
	MgErrorHandler errorHandler = MgErrorHandler(true, true);

	MgWindow window("Magnesium", 800, 600);
	window.init(errorHandler);

	MgInputHandler input(window);

	MgMesh triangle = MgMeshPresets::Triangle(MgVec3(-0.5f, -0.5f, 0.0f), MgVec3(0.5f, -0.5f, 0.0f), MgVec3(0.0f, 0.5f, 0.0f));

	MgShader shader = MgShaderPresets::Color(0.0f, 0.4f, 1.0f);
	shader.use();

	while (window.isOpen())
	{
		if (input.isKeyDown(MG_KEY_ESCAPE)) window.close();

		window.startRender();
		triangle.render();
		window.endRender();
	}

	window.dispose();
	triangle.dispose();
	errorHandler.dispose();

	return 0;
}
