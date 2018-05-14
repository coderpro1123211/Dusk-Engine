#include <GLFW/glfw3.h>
#include <iostream>
#include "src/core/Window.h"

int main() {
	
	if (!glfwInit())
	{
		std::cout << "GLFW Init failed" << std::endl;
		system("PAUSE");
		return 1;
	}

	Dusk::Core::Window* w = new Dusk::Core::Window(800, 600);

	while (!w->PollEvents()) {
		w->Repaint(nullptr);
	}

	system("PAUSE");
	return 0;
}