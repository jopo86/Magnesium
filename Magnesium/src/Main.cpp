#include <iostream>

#include "MgWindow.h"
#include "MgErrorHandler.h"
#include "MgInputHandler.h"
#include "MgMesh.h"
#include "MgMeshPresets.h"

int main()
{
	MgErrorHandler errorHandler = MgErrorHandler(true, false);

	MgWindow window;
	window.init(errorHandler);

	MgInputHandler input(window);

	MgMesh triangle = MgMeshPresets::Triangle();

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
