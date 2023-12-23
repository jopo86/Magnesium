#pragma once

#include <fstream>

#include "Magnesium.h"
#include "MgDisposable.h"
#include "MgErrorHandler.h"

class MgImageData : public MgDisposable
{
public:
	MgImageData();
	MgImageData(ubyte* data, int width, int height, int nChannels);

	static MgImageData Load(const char* filepath);
	static MgImageData Load(const char* filepath, MgErrorHandler& handler);

	ubyte* getData();
	int getWidth();
	int getHeight();
	int getNChannels();

	void setData(ubyte* data);
	void setWidth(int width);
	void setHeight(int height);
	void setNChannels(int nChannels);

	void dispose() override;

private:
	ubyte* data;
	int width, height, nChannels;
};
