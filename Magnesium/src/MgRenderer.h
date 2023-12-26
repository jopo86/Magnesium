#pragma once

#include <vector>

#include "Magnesium.h"
#include "MgRenderable.h"
#include "MgUtils.h"

class MgRenderer : public MgDisposable
{
public:
	MgRenderer();

	void optimize();
	void render();

	void add(MgRenderable& renderable);

	std::vector<MgRenderable*> getRenderables();
	MgRenderable* getRenderable(int index);

	void dispose() override;

private:
	std::vector<MgRenderable*> renderables;

	bool optimized;
	std::vector<std::pair<MgShader, std::vector<std::vector<MgRenderable>>>> optimizationPacks;
};
