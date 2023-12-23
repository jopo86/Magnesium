#pragma once

#include <string>
#include <fstream>

#include "Magnesium.h"
#include "MgErrorHandler.h"
#include "MgImageData.h"

namespace MgUtils
{
	std::string ReadFile(const char* filepath);
	std::string ReadFile(const char* filepath, MgErrorHandler& errorHandler);

	void WriteFile(const char* filepath, const char* contents);
}
