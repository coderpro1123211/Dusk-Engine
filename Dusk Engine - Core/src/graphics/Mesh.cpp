#include "Mesh.h"
#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include <iostream>

Dusk::Graphics::Mesh::Mesh(glm::vec4 * vert, int vertLen, glm::vec4 * nrm, int nrmLen, int * index, int indexLen)
{
	this->verts = vert;
	this->vertsLen = vertLen;
	this->normals = nrm;
	this->normalsLen = nrmLen;
	this->index = index;
	this->indexLen = indexLen;
}
