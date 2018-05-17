#pragma once
#include <GLFW/glfw3.h>
#include "glm/vec4.hpp"

namespace Dusk {
	namespace Graphics {
		class Mesh {
		public:
			Mesh(glm::vec4* vert, int vertLen, glm::vec4* nrm, int nrmLen, int* index, int indexLen);
			int* index;
			glm::vec4* verts;
			glm::vec4* normals;

			int indexLen;
			int vertsLen;
			int normalsLen;
		};
} }