#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Dusk {
	namespace Rendering {
		class ShaderCompiler {
			GLuint CompileFromSource(char* vert, char* frag);
			GLuint LinkShaders(GLuint vertId, GLuint fragId);
		};
	}
}