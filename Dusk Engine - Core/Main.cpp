#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include "src/core/Window.h"
#include "src/graphics/ModelLoader.h"
#include "src/rendering/ShaderCompiler.h"
#include "src/graphics/Graphics.h"

char* vertSrc = "\
uniform mat4 DUSK_MATRIX_MVP;\
\
void main()\
{\
	gl_Position = DUSK_MATRIX_MVP * gl_Vertex;\
}\0";
char* fragSrc = "\
void main()\
{\
	gl_FragColor = vec4(0.4, 0.4, 0.8, 1.0);\
}\
\0";

int main() {

	Dusk::Core::Window* w = new Dusk::Core::Window(800, 600);

	Dusk::Graphics::Mesh* m = Dusk::Graphics::ModelLoader::Load("D:\\Github Projects\\Dusk Engine\\x64\\Debug\\test.fbx", false);

	//std::ifstream frag;

	//frag.open("D:\\Github Projects\\Dusk Engine\\x64\\Debug\\frag.glsl");
	//frag.seekg(frag._Seekend);
	//const int len = frag.tellg();
	//frag.seekg(frag._Seekbeg);

	//std::cout << "Length of fragment shader file: " << len << std::endl;

	//char* fragSrc = (char*)malloc(2048);
	//frag >> fragSrc;
	//frag.close();

	//frag.open("D:\\Github Projects\\Dusk Engine\\x64\\Debug\\vert.glsl");
	//frag.seekg(frag._Seekend);
	//const int lenV = frag.tellg();
	//frag.seekg(frag._Seekbeg);

	//std::cout << "Length of vertex shader file: " << len << std::endl;

	//char* vertSrc = (char*)malloc(2048);
	//frag >> vertSrc;
	//frag.close();

	std::cout << std::endl << vertSrc << std::endl;
	std::cout << std::endl << fragSrc << std::endl;

	GLuint shader = Dusk::Rendering::ShaderCompiler::CompileFromSource(vertSrc, fragSrc);

	m->SetShader(shader);

	while (!w->PollEvents()) {
		w->Repaint(m, 1);
	}

	system("PAUSE");
	return 0;
}