#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include "src/core/Window.h"
#include "src/graphics/ModelLoader.h"
#include "src/graphics/Graphics.h"

int main() {

	Dusk::Core::Window* w = new Dusk::Core::Window(800, 600);

	Dusk::Graphics::Mesh* m = Dusk::Graphics::ModelLoader::Load("D:\\Github Projects\\Dusk Engine\\x64\\Debug\\", false);

	while (!w->PollEvents()) {
		w->Repaint(m, 1);
	}

	system("PAUSE");
	return 0;
}