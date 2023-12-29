#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "Magnesium.h"
#include "MgErrorHandler.h"
#include "MgImageData.h"

namespace MgUtils
{
	template<typename T>
	bool Contains(std::vector<T> vec, T elem)
	{
		for (T _elem : vec) {
			if (_elem == elem) return true;
		}
		return false;
	}
}
