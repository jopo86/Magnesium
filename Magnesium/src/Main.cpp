#include <iostream>

#include "MgWindow.h"
#include "MgErrorHandler.h"
#include "MgInputHandler.h"
#include "MgMesh.h"
#include "MgMeshPresets.h"
#include "MgShader.h"
#include "MgShaderPresets.h"
#include "MgMath.h"
#include "MgTexture.h"
#include "MgImageData.h"

using MgMath::MgVec2;
using MgMath::MgVec3;

int main()
{
	MgErrorHandler errorHandler = MgErrorHandler(true, true);

	MgWindow window("Magnesium", 800, 600);
	window.init(errorHandler);
	window.setBackgroundColor(MgVec3(0.0f, 0.6f, 1.0f));

	MgInputHandler input(window);

	float vertices[] = {
		// pos					// tex coords
		-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,		1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f,		1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f,		0.0f, 1.0f
	};

	uint indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	MgMesh quad(vertices, sizeof(vertices), MG_VERTEX_FORMAT_VT, indices, sizeof(indices));
	MgShader shader = MgShaderPresets::Texture();
	MgTexture texture(MgImageData::Load("assets/textures/container.jpg", errorHandler));

	while (window.isOpen())
	{
		if (input.isKeyDown(MG_KEY_ESCAPE)) window.close();

		window.startRender();

		shader.use();
		texture.bind();
		quad.render();
		texture.unbind();
		shader.unuse();

		window.endRender();
	}

	window.dispose();
	quad.dispose();
	errorHandler.dispose();
	shader.dispose();

	return 0;
}
