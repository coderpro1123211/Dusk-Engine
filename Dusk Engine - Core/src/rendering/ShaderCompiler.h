#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Dusk {
	namespace Rendering {
		class ShaderCompiler {
			GLuint CompileFromSource(char* vert, char* frag);
			GLuint CompileShader(const char* src, GLenum type, char* id);
			GLuint LinkShaders(GLuint vertId, GLuint fragId);
		};
	}
}