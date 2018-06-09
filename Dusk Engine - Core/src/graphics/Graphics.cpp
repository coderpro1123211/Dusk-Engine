#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "Graphics.h"
#include "../core/Window.h"
#include <iostream>

bool Dusk::GraphicsLibrary::InitializeGLFW() {
	std::cout << "Initializing GLFW" << std::endl;

	if (!glfwInit())
	{
		std::cout << "GLFW Init failed" << std::endl;
		system("PAUSE");
		return false;
	}

	std::cout << "GLFW Initialized" << std::endl << std::endl;
	return true;
}

bool Dusk::GraphicsLibrary::Initialize()
{
	std::cout << "Initializing GLEW" << std::endl;
	GLenum e;
	if ((e = glewInit()) != 0)
	{
		std::cout << "GLEW Init failed" << std::endl;
		std::cout << glewGetErrorString(e) << std::endl;
		system("PAUSE");
		return false;
	}

	std::cout << "GLEW Initialized" << std::endl << std::endl;

	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version   : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl << std::endl;
	std::cout << "Graphics Card  : " << glGetString(GL_RENDERER) << std::endl << std::endl;
	return true;
}
