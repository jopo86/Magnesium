#pragma once

#include <vector>

#include "Magnesium.h"
#include "MgMath.h"
#include "MgMesh.h"
#include "MgShader.h"
#include "MgTexture.h"

class MgRenderable : public MgDisposable
{
public:
	MgRenderable();
	MgRenderable(MgMesh mesh);
	MgRenderable(MgMesh mesh, MgShader shader);
	MgRenderable(MgMesh mesh, MgShader shader, MgTexture texture);

	void render();

	void translate(MgMath::MgVec3 xyz);
	void rotate(float degrees, MgMath::MgVec3 axes);
	void scale(float scalar);
	void scale(MgMath::MgVec3 xyzScalar);
	void resetTransform();

	MgMesh getMesh();
	MgShader getShader();
	MgTexture getTexture();

	void dispose() override;

private:
	MgMesh mesh;
	MgShader shader;
	MgTexture texture;

	MgMath::MgMat4 model;
};
