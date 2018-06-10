#pragma once
#include "../graphics/Mesh.h"

namespace Dusk {
	namespace Rendering {
		class UnlitRenderer {
		public:
			static void Render(Dusk::Graphics::Mesh* meshes, int numMeshes);
		};
	}
}