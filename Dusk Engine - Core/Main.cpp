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

	//FbxManager *lSdkManager = FbxManager::Create();
	//FbxIOSettings * ios = FbxIOSettings::Create(lSdkManager, IOSROOT);

	//ios->SetBoolProp(IMP_FBX_MATERIAL, true);
	//ios->SetBoolProp(IMP_FBX_TEXTURE, true);

	//FbxScene* lScene = FbxScene::Create(lSdkManager, "");
	//FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");
	//lImporter->Initialize("C:\\Users\\sax\\Desktop\\Dusk Engine\\Dusk Engine\\x64\\Debug\\test.fbx", -1, ios);

	//lImporter->Import(lScene);

	//std::cout << "NODES : " << lScene->GetNodeCount() << std::endl;
	//std::cout << "STATUS: " << lImporter->GetStatus().GetErrorString() << std::endl;

	//for (int i = 0; i < lScene->GetNodeCount(); i++)
	//{
	//	std::cout << "ROOT : " << lScene->GetNode(i)->GetName() << std::endl;
	//	FbxNode* n = lScene->GetNode(i);
	//	std::cout << "TYPE : " << n->GetTypeName() << std::endl;
	//	std::cout << "COUNT: " << n->GetChildCount() << std::endl;
	//}

	//lImporter->Destroy();

	while (!w->PollEvents()) {
		w->Repaint(m, 1);
	}

	system("PAUSE");
	return 0;
}