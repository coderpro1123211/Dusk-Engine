#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "UnlitRenderer.h"
#include "../graphics/Mesh.h"
#include "glm/glm.hpp"
#include "glm/mat4x4.hpp"
#include "glm/ext.hpp"

using namespace Dusk::Graphics;

typedef struct {
	GLfloat pos[3];
	GLfloat nrm[3];
	GLubyte col[4];
} vertData;

void Dusk::Rendering::UnlitRenderer::Render(Mesh* meshes, int numMeshes)
{
	for (int i = 0; i < numMeshes; i++) {
		Mesh m = meshes[i];

		glm::mat4 proj = glm::perspective<float>(60, 800.0/600.0, 0, 100);

		glm::mat4 view;
		glm::make_mat4(&view);
		glm::translate(view, glm::vec3(0, 0, -10));

		glm::mat4 model;
		glm::make_mat4(&model);
		//glm::rotate<float>(model, 30, glm::vec3(0, 1, 0));

		glm::mat4 mvp = proj * view * model;

		GLuint shader = m.shaderProg;

		glUseProgram(shader);
		glUniformMatrix4fv(glGetUniformLocation(shader, "DUSK_MATRIX_MVP"), 1, false, &mvp[0][0]);

		std::vector<vertData> arr;

		for (int j = 0; j < m.verts.size(); j++)
		{
			vertData d;
			memset(&d, 0, sizeof(vertData));

			d.pos[0] = m.verts[j].x;
			d.pos[1] = m.verts[j].y;
			d.pos[2] = m.verts[j].z;

			d.nrm[0] = m.normals[j].x;
			d.nrm[1] = m.normals[j].y;
			d.nrm[2] = m.normals[j].z;

			d.col[0] = 1;
			d.col[0] = 1;
			d.col[0] = 1;
			d.col[0] = 1;
			
			arr.push_back(d);
		}

		GLuint vBuf;

		glGenVertexArrays(1, &vBuf);

		glBindVertexBuffer(0, vBuf, 0, sizeof(vertData));
		
		glEnableVertexAttribArray(0);
		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, offsetof(vertData, pos));
		glVertexAttribBinding(0, 0);
		glEnableVertexAttribArray(1);
		glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, offsetof(vertData, nrm));
		glVertexAttribBinding(1, 0);
		glEnableVertexAttribArray(2);
		glVertexAttribFormat(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, offsetof(vertData, col));
		glVertexAttribBinding(2, 0);

		

		glDrawArrays(GL_TRIANGLES, 0, 12*3);
	}
}
