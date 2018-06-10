#include "Mesh.h"
#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include <iostream>
#include <vector>

Dusk::Graphics::Mesh::Mesh(std::vector<glm::vec4> vert, std::vector<glm::vec4> nrm, std::vector<int> index)
{
	this->verts = vert;
	this->normals = nrm;
	this->index = index;
}

void Dusk::Graphics::Mesh::SetShader(GLuint prog)
{
	this->shaderProg = prog;
}
