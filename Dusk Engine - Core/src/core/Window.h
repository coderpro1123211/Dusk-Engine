#pragma once
#include <GLFW/glfw3.h>
#include "../graphics/Mesh.h"

using namespace Dusk::Graphics;

namespace Dusk { namespace Core {
	class Window {
		public:
			Window (int,int);
			void Repaint(Mesh*, int);
			bool PollEvents();
			int Width, Height;
			char* Title;
		private:
			GLFWwindow* m_Window;
			int m_Width, m_Height;
			char* m_Title;
	};
} }