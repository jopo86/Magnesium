#include <iostream>

#include "MgWindow.h"
#include "MgErrorHandler.h"
#include "MgInputHandler.h"
#include "MgMesh.h"
#include "MgMeshPresets.h"
#include "MgShader.h"
#include "MgShaderPresets.h"
#include "MgUtils.h"

int main()
{
	MgErrorHandler errorHandler = MgErrorHandler(true, true);

	MgWindow window;
	window.init(errorHandler);

	MgInputHandler input(window);

	MgMesh triangle = MgMeshPresets::Triangle();

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
