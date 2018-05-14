#pragma once
#include <GLFW/glfw3.h>
#include "../drawing/Mesh.h"

using namespace Dusk::Drawing;

namespace Dusk { namespace Core {
	class Window {
		public:
			Window (int,int);
			void Repaint(Mesh* meshes);
			bool PollEvents();
			int Width, Height;
			char* Title;
		private:
			GLFWwindow* m_Window;
			int m_Width, m_Height;
			char* m_Title[];
	};
} }