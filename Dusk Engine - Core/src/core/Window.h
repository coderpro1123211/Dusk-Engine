#pragma once

namespace Dusk { namespace Core {
	class Window {
		public:
			Window (int,int);
			int Width, Height;
			char* Title;
		private:
			int m_Width, m_Height;
			char* m_Title[];
	};
} }