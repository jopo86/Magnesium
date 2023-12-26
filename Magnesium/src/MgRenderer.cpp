#include "MgRenderer.h"

using std::vector;
using std::pair;

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
	for (int i = 0; i < renderables.size(); i++)
	{
		renderables[i]->render();
	}
}

void MgRenderer::add(MgRenderable& renderable)
{
	renderables.push_back(&renderable);
}

vector<MgRenderable*> MgRenderer::getRenderables()
{
	return renderables;
}

MgRenderable* MgRenderer::getRenderable(int index)
{
	return renderables[index];
}

void MgRenderer::dispose()
{
	for (int i = 0; i < renderables.size(); i++)
	{
		renderables[i]->dispose();
	}
}
