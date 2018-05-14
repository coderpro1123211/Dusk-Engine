#include "Mesh.h"
#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include <iostream>

Dusk::Drawing::Mesh::Mesh(char * path, bool calcNormals)
{
	FbxManager *lSdkManager = FbxManager::Create();
	FbxIOSettings * ios = FbxIOSettings::Create(lSdkManager, IOSROOT);

	ios->SetBoolProp(IMP_FBX_MATERIAL, true);
	ios->SetBoolProp(IMP_FBX_TEXTURE, true);

	FbxScene* lScene = FbxScene::Create(lSdkManager, "");
	FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");
	lImporter->Initialize(path, -1, ios);

	lImporter->Import(lScene);
	lImporter->Destroy();

	for (int i = 0; i < lScene->GetGenericNodeCount(); i++)
	{
		std::cout << "NODE : " << lScene->GetGenericNode(i)->GetName() << std::endl;
	}
}
