#include <iostream>

#include "MgWindow.h"
#include "MgErrorHandler.h"
#include "MgInputHandler.h"
#include "MgMesh.h"
#include "MgMeshPresets.h"
#include "MgShader.h"

int main()
{
	MgErrorHandler errorHandler = MgErrorHandler(true, true);

	MgWindow window;
	window.init(errorHandler);

	MgInputHandler input(window);

	MgMesh triangle = MgMeshPresets::Triangle();

	const char* vertSource = R"(
		#version 330 core

		layout(location = 0) in vec3 pos;

		void main()
		{
			gl_Position = vec4(pos, 1.0f);
		}
	)";

	const char* fragSource = R"(
		#version 330 core

		out vec4 color;

		void main()
		{
			color = vec4(0.0f, 0.3f, 1.0f, 1.0f);
		}
	)";

	MgShader shader(vertSource, fragSource, errorHandler);
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
