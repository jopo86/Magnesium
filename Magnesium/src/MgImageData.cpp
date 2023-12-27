#include "MgImageData.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stbi/stb_image.h>

MgImageData::MgImageData()
{
	data = nullptr;
	width = height = nChannels = 0;
}

MgImageData::MgImageData(ubyte* data, int width, int height, int nChannels)
{
	this->data = data;
	this->width = width;
	this->height = height;
	this->nChannels = nChannels;
}

MgImageData MgImageData::Load(const char* filepath)
{
	int width = 0, height = 0, nChannels = 0;

#ifndef MG_STBI_FLIP_FIX
	stbi_set_flip_vertically_on_load(true);
#define MG_STBI_FLIP_FIX
#endif

	ubyte* data = stbi_load(filepath, &width, &height, &nChannels, 0);
	return MgImageData(data, width, height, nChannels);
}

MgImageData MgImageData::Load(const char* filepath, MgErrorHandler& errorHandler)
{
	std::ifstream file(filepath);
	if (!file.is_open())
	{
		errorHandler.err("failed to locate file: \"" + std::string(filepath) + "\"");
		return MgImageData();
	}
	file.close();

	int width = 0, height = 0, nChannels = 0;

#ifndef MG_STBI_FLIP_FIX
	stbi_set_flip_vertically_on_load(true);
#define MG_STBI_FLIP_FIX
#endif

	ubyte* data = stbi_load(filepath, &width, &height, &nChannels, 0);
	if (!data)
	{
		errorHandler.err("found file, but failed to load image data: \"" + std::string(filepath) + "\"");
		return MgImageData();
	}

	return MgImageData(data, width, height, nChannels);
}

ubyte* MgImageData::getData()
{
	return data;
}

int MgImageData::getWidth()
{
	return width;
}

int MgImageData::getHeight()
{
	return height;
}

int MgImageData::getNChannels()
{
	return nChannels;
}

void MgImageData::dispose()
{
	stbi_image_free(data);
	data = 0;
	width = height = nChannels = 0;
}
