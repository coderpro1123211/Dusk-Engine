#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include "ModelLoader.h"
#include "../maths/Vector3.h"
#include "Mesh.h"
#include <iostream>

Dusk::Graphics::Mesh* Dusk::Graphics::ModelLoader::Load(char *path, bool calcNormals)
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

	FbxNode* n = NULL;
	FbxMesh* m = NULL;

	for (int i = 0; i < lScene->GetNodeCount(); i++)
	{
		n = lScene->GetNode(i);
		FbxNodeAttribute* a = n->GetNodeAttribute();
		if (a == nullptr) continue;
		if (a->GetAttributeType() == a->eMesh) {
			m = n->GetMesh();
			break;
		}
	}

	if (m == NULL) {
		std::cout << "FATAL! " << std::endl;
	}

	m->GenerateNormals();

	for (int iPoly = 0; iPoly < m->GetPolygonCount(); iPoly++) {
		for (int iVert = 0; iVert < m->GetPolygonSize(iPoly); iVert++)
		{
			int index = m->GetPolygonVertex(iPoly, iVert);
			FbxVector4 v = m->GetControlPointAt(index);
			FbxVector4 n;
			bool sN = m->GetPolygonVertexNormal(iPoly, iVert, n);
			if (!sN) {
				std::cout << "FATAL! NORMAL COULD NOT BE READ" << std::endl;
			}

			std::cout << "POINT: " << index << " : " << iPoly << "-" << iVert << std::endl;
			std::cout << "\tVERTEX: " << v[0] << " " << v[1] << " " << v[2] << std::endl;
			std::cout << "\tNORMAL: " << n[0] << " " << n[1] << " " << n[2] << std::endl;
		}
	}


	return nullptr;//new Mesh();
}
