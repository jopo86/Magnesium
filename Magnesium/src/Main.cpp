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
#include "MgRenderable.h"
#include "MgRenderer.h"
#include "MgRenderablePresets.h"
#include "MgGraphics.h"
#include "MgFile.h"

using MgMath::MgVec2;
using MgMath::MgVec3;

int main()
{
	MgErrorHandler errorHandler = MgErrorHandler(true, false);

	MgWindow window("Magnesium", 800, 600);
	window.init(errorHandler);
	window.setBackgroundColor(MgVec3(0.0f, 0.6f, 1.0f));

	MgInputHandler input(window);

	MgRenderer renderer;
				   
	MgRenderable triangle = MgRenderablePresets::ColoredTriangle(0.6f, MgVec3(1.0f, 0.0f, 0.0f));
	MgRenderable quad = MgRenderablePresets::TexturedQuad(MgTexture(MgImageData::Load("assets/textures/container.jpg", errorHandler)));
				   
	renderer.add(triangle);
	renderer.add(quad);

	while (window.isOpen())
	{
		if (input.isKeyDown(MG_KEY_3)) renderer.hide(0);
		if (input.isKeyDown(MG_KEY_4)) renderer.show(0);

		window.startRender();
		renderer.render();
		window.endRender();
	}

	renderer.dispose();
	window.dispose();

	return 0;
}
