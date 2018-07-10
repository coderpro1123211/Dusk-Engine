#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Dusk {
	namespace Rendering {
		class ShaderCompiler {
		public:
			static GLuint CompileFromSource(char* vert, char* frag);
			static GLuint CompileShader(const char* src, GLenum type, char* id);
			static GLuint LinkShaders(GLuint vertId, GLuint fragId);
		};
	}
}