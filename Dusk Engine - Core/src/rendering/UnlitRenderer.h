#pragma once
#include "../graphics/Mesh.h"

namespace Dusk {
	namespace Rendering {
		class UnlitRenderer {
			static void Render(Dusk::Graphics::Mesh* meshes, int numMeshes, char* shader, int shaderLen);
		};
	}
}