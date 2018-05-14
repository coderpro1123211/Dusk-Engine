#include "Window.h"
#include "GLFW/glfw3.h"
#include "../graphics/Mesh.h"

using namespace Dusk::Core;
using namespace Dusk::Graphics;

Dusk::Core::Window::Window(int w, int h)
{
	m_Width = Width = w;
	m_Height = Height = h;
	this->m_Window = glfwCreateWindow(w, h, "Hello World!", NULL, NULL);
	glfwMakeContextCurrent(this->m_Window);
}

void Dusk::Core::Window::Repaint(Mesh* meshes, int meshesLen)
{
	//TODO: Drawing code for window here
	glClearColor(0,0,0.3,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);

	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 1, 0);

	glEnd();
	glfwSwapBuffers(this->m_Window);
}

bool Dusk::Core::Window::PollEvents()
{
	glfwPollEvents();
	bool sC = glfwWindowShouldClose(this->m_Window);
	if (sC) glfwDestroyWindow(this->m_Window);
	return sC;
}
