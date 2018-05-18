#include "UnlitRenderer.h"
#include "../graphics/Mesh.h"
#include "GLFW/glfw3.h"

using namespace Dusk::Graphics;

void Dusk::Rendering::UnlitRenderer::Render(Mesh* meshes, int numMeshes, char* shader, int shaderLen)
{
	
	for (int i = 0; i < numMeshes; i++) {
		Mesh* m = &meshes[i];
	}
}
