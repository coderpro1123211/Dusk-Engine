#pragma once
#include "../graphics/Mesh.h"

namespace Dusk {
	namespace Rendering {
		class UnlitRenderer {
			void Render(Dusk::Graphics::Mesh* meshes, int numMeshes, char* shader, int shaderLen);
		};
	}
}