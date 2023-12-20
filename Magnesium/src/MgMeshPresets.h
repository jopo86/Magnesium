#pragma once

#include <cmath>

#include "Magnesium.h"
#include "MgMesh.h"
#include "MgMath.h"

namespace MgMeshPresets
{
	using MgMath::MgVec2;
	using MgMath::MgVec3;

	MgMesh Line();
	MgMesh Line(float length);
	MgMesh Line(float length, float angle);
	MgMesh Line(MgVec2 origin, float length, float angle);
	MgMesh Line(MgVec2 a, MgVec2 b);

	MgMesh Triangle();
	MgMesh Triangle(float base, float height);
	MgMesh Triangle(float side);
	MgMesh Triangle(MgVec2 a, MgVec2 b, MgVec2 c);

	MgMesh Quad();
	MgMesh Quad(float side);
	MgMesh Quad(float width, float height);
	MgMesh Quad(MgVec2 a, MgVec2 b, MgVec2 c, MgVec2 d);
}
