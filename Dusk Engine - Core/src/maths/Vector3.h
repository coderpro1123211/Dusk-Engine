#pragma once

namespace Dusk {
	namespace Maths {
		class Vector3 {
		public:
			Vector3(float x, float y, float z);
			float x, y, z;
		private:
			float m_C[];
		};
	}
}