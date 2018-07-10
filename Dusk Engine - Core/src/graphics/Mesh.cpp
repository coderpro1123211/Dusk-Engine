#include "GL\glew.h"
#include "GLFW\glfw3.h"
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

	vertData = std::vector<VertexData>(verts.size());
	for (int j = 0; j < verts.size(); j++)
	{
		VertexData d;
		memset(&d, 0, sizeof(VertexData));

		d.pos[0] = verts[j].x;
		d.pos[1] = verts[j].y;
		d.pos[2] = verts[j].z;

		d.nrm[0] = normals[j].x;
		d.nrm[1] = normals[j].y;
		d.nrm[2] = normals[j].z;

		d.col[0] = 1;
		d.col[1] = 1;
		d.col[2] = 1;
		d.col[3] = 1;

		printf("%02f | %f,%f,%f\n", j, verts[j].x, verts[j].y, verts[j].z);
		printf("\t\t%f,%f,%f\n", d.pos[0], d.pos[1], d.pos[2]);

		vertData.push_back(d);
	}

	glGenBuffers(1, &vertBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertData), &vertData[0], GL_STATIC_DRAW);
}

void Dusk::Graphics::Mesh::SetShader(GLuint prog)
{
	this->shaderProg = prog;
}
