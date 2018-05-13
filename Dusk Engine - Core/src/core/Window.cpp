#include "Window.h"
#include "GLFW/glfw3.h"

Dusk::Core::Window::Window(int w, int h)
{
	m_Width = Width = w;
	m_Height = Height = h;
	glfwCreateWindow(w, h, "Hello World!", NULL, NULL);
}
