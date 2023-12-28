#include "MgTexture.h"

#include <iostream>

MgTexture::MgTexture()
{
	tex = 0;
}

MgTexture::MgTexture(MgImageData imageData)
{
	tex = 0;

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, imageData.getNChannels() == 4 ? GL_RGBA : GL_RGB, imageData.getWidth(), imageData.getHeight(), 0, imageData.getNChannels() == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, imageData.getData());
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	imageData.dispose();
}

MgTexture::MgTexture(MgImageData& imageData, bool disposeImageData)
{
	tex = 0;
	MgImageData* p_imageData = &imageData;

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, p_imageData->getNChannels() == 4 ? GL_RGBA : GL_RGB, p_imageData->getWidth(), imageData.getHeight(), 0, imageData.getNChannels() == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, imageData.getData());
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	if (disposeImageData) p_imageData->dispose();
}

uint MgTexture::getTextureID()
{
	return tex;
}

void MgTexture::dispose()
{
	glDeleteTextures(1, &tex);
	tex = 0;
}
