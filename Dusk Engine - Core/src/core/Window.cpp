#include "Window.h"
#include "GLFW/glfw3.h"
#include "../drawing/Mesh.h"

using namespace Dusk::Core;
using namespace Dusk::Drawing;

Dusk::Core::Window::Window(int w, int h)
{
	m_Width = Width = w;
	m_Height = Height = h;
	this->m_Window = glfwCreateWindow(w, h, "Hello World!", NULL, NULL);
	glfwMakeContextCurrent(this->m_Window);
}

void Dusk::Core::Window::Repaint(Mesh* meshes)
{
	//TODO: Drawing code for window here
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);

	glEnd();
	glfwSwapBuffers(this->m_Window);
}

bool Dusk::Core::Window::PollEvents()
{
	glfwPollEvents();
	return glfwWindowShouldClose(this->m_Window);
}
