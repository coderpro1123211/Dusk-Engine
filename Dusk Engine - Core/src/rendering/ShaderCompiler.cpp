#include "ShaderCompiler.h"
#include "../core/Logger.h"
#include <vector>

GLuint Dusk::Rendering::ShaderCompiler::CompileFromSource(char * vert, char * frag)
{
	//Compile the shader stages
	GLuint vertId = CompileShader(vert, GL_VERTEX_SHADER, "Vertex");
	GLuint fragId = CompileShader(frag, GL_FRAGMENT_SHADER, "Fragment");
	
	//Link shaders
	GLuint prog = LinkShaders(vertId, fragId);

	return prog;
}

GLuint Dusk::Rendering::ShaderCompiler::CompileShader(const char * src, GLenum type, char* id)
{
	//Compile the shader
	GLuint shaderId = glCreateShader(type);

	const GLchar* s = ((GLchar*)src);

	glShaderSource(shaderId, 1, &s, NULL);
	glCompileShader(shaderId);

	//Get the info about the shader
	GLint success = 0;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE) { //Shader compilation failed

		GLint maxLength = 0;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shaderId, maxLength, &maxLength, &errorLog[0]);

		LogError("%s shader compilation failed: %s", id, &errorLog[0]);
		glDeleteShader(shaderId);

		return NULL;
	}

	return shaderId;
}

GLuint Dusk::Rendering::ShaderCompiler::LinkShaders(GLuint vertId, GLuint fragId)
{
	GLuint program = glCreateProgram();

	glAttachShader(program, vertId);
	glAttachShader(program, fragId);

	glLinkProgram(program);

	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

		glDeleteProgram(program);

		glDeleteShader(vertId);
		glDeleteShader(fragId);

		LogError("Shader linking failed : %s\n", &infoLog[0]);
		return NULL;
	}

	return program;
}
