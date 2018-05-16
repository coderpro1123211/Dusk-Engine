#pragma once
#include <GLFW/glfw3.h>
#include "../maths/Vector3.h"

using namespace Dusk::Maths;

namespace Dusk {
	namespace Graphics {
		class Mesh {
		public:
			Mesh(Vector3* vert, int vertLen, Vector3* nrm, int nrmLen, int* index, int indexLen);
			int* index;
			Vector3* verts;
			Vector3* normals;

			int indexLen;
			int vertsLen;
			int normalsLen;
		};
} }