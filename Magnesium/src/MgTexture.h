#pragma once

#include <glad/glad.h>

#include "Magnesium.h"
#include "MgImageData.h"

class MgTexture : public MgDisposable
{
public:
	MgTexture();
	MgTexture(MgImageData imageData, bool disposeImageData);

	uint getTextureID();
	MgImageData getImageData();

	void dispose() override;

private:
	uint tex;
	MgImageData imageData;
};
