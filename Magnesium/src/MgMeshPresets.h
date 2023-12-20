#pragma once

#include <cmath>

#include "Magnesium.h"
#include "MgMesh.h"
#include "MgMath.h"

namespace MgMeshPresets
{
	using MgMath::MgVec3;

	MgMesh Triangle();
	MgMesh Triangle(float base, float height);
	MgMesh Triangle(float side);
	MgMesh Triangle(MgVec3 a, MgVec3 b, MgVec3 c);
}
