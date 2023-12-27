#include "MgRenderer.h"

MgRenderer::MgRenderer()
{
	renderables = {};
	optimizationPacks = {};
	optimized = false;
}

void MgRenderer::optimize()
{

}

void MgRenderer::render()
{
	for (const std::pair<MgRenderable*, bool>& renderable : renderables)
	{
		if (renderable.second) renderable.first->render();
	}
}

void MgRenderer::add(MgRenderable& renderable)
{
	renderables.push_back({ &renderable, true });
}

void MgRenderer::show(int index)
{
	renderables[index].second = true;
}

void MgRenderer::hide(int index)
{
	renderables[index].second = false;
}

void MgRenderer::dispose()
{
	for (int i = 0; i < renderables.size(); i++)
	{
		renderables[i].first->dispose();
	}
}
