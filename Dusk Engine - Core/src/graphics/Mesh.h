#pragma once
#include <GLFW/glfw3.h>
#include "glm/vec4.hpp"
#include <vector>

namespace Dusk {
	namespace Graphics {
		typedef struct {
			GLfloat pos[3];
			GLfloat nrm[3];
			GLubyte col[4];
		} VertexData;
		class Mesh {
		public:
			Mesh(std::vector<glm::vec4> vert, std::vector<glm::vec4> nrm, std::vector<int> index);
			void SetShader(GLuint prog);
			std::vector<int> index;
			std::vector<glm::vec4> verts;
			std::vector<glm::vec4> normals;

			int indexLen;
			int vertsLen;
			int normalsLen;
			std::vector<VertexData> vertData;
			GLuint shaderProg;
			GLuint vertBuffer;
		};
} }