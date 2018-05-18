#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include "src/core/Window.h"
#include "src/graphics/ModelLoader.h"

int main() {
	
	std::cout << "Initializing GLFW" << std::endl;

	if (!glfwInit())
	{
		std::cout << "GLFW Init failed" << std::endl;
		system("PAUSE");
		return 1;
	}
	Dusk::Core::Window* w = new Dusk::Core::Window(800, 600);

	std::cout << "GLFW Initialized" << std::endl << std::endl;
	std::cout << "Initializing GLEW" << std::endl;
	GLenum e;
	if ((e=glewInit()) != 0)
	{
		std::cout << "GLEW Init failed" << std::endl;
		std::cout << glewGetErrorString(e) << std::endl;
		system("PAUSE");
		return 1;
	}

	std::cout << "GLEW Initialized" << std::endl << std::endl;

	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version   : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl << std::endl;
	std::cout << "Graphics Card  : " << glGetString(GL_RENDERER) << std::endl << std::endl;

	Dusk::Graphics::Mesh* m = Dusk::Graphics::ModelLoader::Load("C:\\Users\\sax\\Desktop\\Dusk Engine\\Dusk Engine\\x64\\Debug\\test.fbx", false);

	while (!w->PollEvents()) {
		w->Repaint(m, 1);
	}

	system("PAUSE");
	return 0;
}