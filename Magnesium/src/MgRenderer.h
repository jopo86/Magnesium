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

	void show(int index);
	void hide(int index);

	void dispose() override;

private:
	std::vector<std::pair<MgRenderable*, bool>> renderables;

	bool optimized;
	std::vector<std::pair<MgShader, std::vector<std::vector<MgRenderable>>>> optimizationPacks;
};
