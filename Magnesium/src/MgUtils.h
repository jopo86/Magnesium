#pragma once

#include <string>
#include <fstream>

#include "MgErrorHandler.h"

namespace MgUtils
{
	std::string ReadFile(const char* filepath);
	std::string ReadFile(const char* filepath, MgErrorHandler& errorHandler);

	void WriteFile(const char* filepath, const char* contents);
}
