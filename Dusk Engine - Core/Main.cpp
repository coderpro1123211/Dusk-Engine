#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "src/core/Window.h"
#include "src/graphics/ModelLoader.h"

int main() {
	
	if (!glfwInit())
	{
		std::cout << "GLFW Init failed" << std::endl;
		system("PAUSE");
		return 1;
	}

	std::cout << "GLFW Initialized" << std::endl;

	Dusk::Core::Window* w = new Dusk::Core::Window(800, 600);
	Dusk::Graphics::Mesh* m = Dusk::Graphics::ModelLoader::Load("C:\\Users\\sax\\Desktop\\Dusk Engine\\Dusk Engine\\x64\\Debug\\test.fbx", false);

	while (!w->PollEvents()) {
		w->Repaint(m, 1);
	}

	system("PAUSE");
	return 0;
}