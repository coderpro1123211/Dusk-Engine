#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "UnlitRenderer.h"
#include "../graphics/Mesh.h"
#include "glm/glm.hpp"
#include "glm/mat4x4.hpp"
#include "glm/ext.hpp"

using namespace Dusk::Graphics;

void Dusk::Rendering::UnlitRenderer::Render(Mesh* meshes, int numMeshes)
{
	for (int i = 0; i < numMeshes; i++) {
		Mesh m = meshes[i];

		glm::mat4 proj = glm::perspective<float>(glm::radians(60.0f), 800.0/600.0, 0, 100);

		glm::mat4 view = glm::lookAt(
			glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
			glm::vec3(0, 0, 0), // and looks at the origin
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);

		glm::mat4 model = glm::mat4(1.0f);
		//glm::rotate<float>(model, 30, glm::vec3(0, 1, 0));

		glm::mat4 mvp = proj * view * model;

		GLuint shader = m.shaderProg;
		glUseProgram(shader);

		glUniformMatrix4fv(glGetUniformLocation(shader, "DUSK_MATRIX_MVP"), 1, false, &mvp[0][0]);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, m.vertBuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			7,                  // stride
			(void*)0            // array buffer offset
		);

		glDrawArrays(GL_TRIANGLES, 0, m.vertsLen);
		glDisableVertexAttribArray(0);

	}
}
