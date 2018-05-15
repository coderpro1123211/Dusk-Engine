#pragma once

namespace Dusk {
	namespace Maths {
		class Vector3 {
		public:
			Vector3(double x, double y, double z);
			double x, y, z;
		private:
			double m_C[];
		};
	}
}