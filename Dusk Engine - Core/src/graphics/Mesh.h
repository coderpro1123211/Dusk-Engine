#pragma once
#include <GLFW/glfw3.h>
#include "glm/vec4.hpp"
#include <vector>

namespace Dusk {
	namespace Graphics {
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
			GLuint shaderProg;
		};
} }