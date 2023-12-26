#include "MgRenderable.h"

using MgMath::MgMat4;
using MgMath::MgVec3;

MgRenderable::MgRenderable() 
{
	model = MgMat4(1.0f);
}

MgRenderable::MgRenderable(MgMesh mesh)
{
	this->mesh = mesh;
	model = MgMat4(1.0f);
}

MgRenderable::MgRenderable(MgMesh mesh, MgShader shader)
{
	this->mesh = mesh;
	this->shader = shader;
	model = MgMat4(1.0f);
}

MgRenderable::MgRenderable(MgMesh mesh, MgShader shader, MgTexture texture)
{
	this->mesh = mesh;
	this->shader = shader;
	this->texture = texture;
	model = MgMat4(1.0f);
}

void MgRenderable::render()
{
	glUseProgram(shader.getProgramID());
	glBindTexture(GL_TEXTURE_2D, texture.getTextureID());
	shader.uniform("u_model", model);
	glBindVertexArray(mesh.getVaoID());
	glDrawElements(GL_TRIANGLES, mesh.getIndicesSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}

void MgRenderable::translate(MgVec3 xyz)
{
	model.translate(xyz);
}

void MgRenderable::rotate(float degrees, MgVec3 axes)
{
	model.rotate(degrees, axes);
}

void MgRenderable::scale(float scalar)
{
	model.scale(MgVec3(scalar, scalar, scalar));
}

void MgRenderable::scale(MgVec3 xyzScalar)
{
	model.scale(xyzScalar);
}

void MgRenderable::resetTransform()
{
	model = MgMat4(1.0f);
}

MgMesh MgRenderable::getMesh()
{
	return mesh;
}

MgShader MgRenderable::getShader()
{
	return shader;
}

MgTexture MgRenderable::getTexture()
{
	return texture;
}

void MgRenderable::dispose()
{
	texture.dispose();
	shader.dispose();
	mesh.dispose();
}
