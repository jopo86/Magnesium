#pragma once

#include <glad/glad.h>

#include "Magnesium.h"
#include "MgDisposable.h"
#include "MgImageData.h"

class MgTexture : public MgDisposable
{
public:
	MgTexture();
	MgTexture(MgImageData imageData);
	void bind();
	void unbind();

	MgImageData getImageData();

	void dispose() override;

private:
	uint tex;
	MgImageData imageData;
};
