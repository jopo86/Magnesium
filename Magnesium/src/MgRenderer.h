#pragma once

#include <vector>

#include "Magnesium.h"
#include "MgRenderable.h"
#include "MgUtils.h"

/*
 * @brief A class to represent a renderer.
 * This class contains renderables, and renders all of them when render() is called.
 * The benefits of this class are that renderables can be shown/hidden,
 * and there is also an optimization function that will significantly speed up rendering large scenes.
 * This class is disposable.
 */
class MgRenderer : public MgDisposable
{
public:
	/*
	 * @brief Creates a new MgRenderer object containing no renderables.
	 */
	MgRenderer();

	/*
	 * @brief THIS FUNCTION IS NOT IMPLEMENTED YET.
	 * Optimizes the rendering process.
	 * This function should be called after all renderables are added, but before the rendering loop begins.
	 * Behind the scenes, this function groups together renderables with the same shader and/or texture,
	 * so that switching between shaders and textures - an expensive process - occurs much less frequently.
	 */
	void optimize();

	/*
	 * @brief Renders all of the renderables contained by the renderer.
	 * Does not render any renderables that have been hidden by hide().
	 */
	void render();

	/*
	 * @brief Adds a renderable to the renderer.
	 * Note that renderables cannot be removed once added, instead use hide().
	 */
	void add(MgRenderable& renderable);

	/*
	 * @brief Enables rendering for the renderable at the specified index.
	 * The first renderable added has index 0, the next 1, and so on.
	 */
	void show(int index);

	/*
	 * @brief Disables rendering for the renderable at the specified index.
	 * The first renderable added has index 0, the next 1, and so on.
	 */
	void hide(int index);

	/*
	 * @brief Disposes of the renderer, including all of the contained renderables.
	 * This clears up any memory that the object was using.
	 * This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
	 */
	void dispose() override;

private:
	std::vector<std::pair<MgRenderable*, bool>> renderables;

	bool optimized;
	std::vector<std::pair<MgShader, std::vector<std::vector<MgRenderable>>>> optimizationPacks;
};
