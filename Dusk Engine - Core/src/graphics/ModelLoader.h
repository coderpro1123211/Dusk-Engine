#pragma once
#include "Mesh.h"

namespace Dusk {
	namespace Graphics {
		class ModelLoader {
		public:
			static Mesh* Load(char*, bool);
		};
	}
}