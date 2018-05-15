#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include "ModelLoader.h"
#include "../maths/Vector3.h"
#include "../core/Logger.h"
#include "Mesh.h"
#include <iostream>
#include <vector>

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

	std::vector<Vector3> verts = std::vector<Vector3>();
	std::vector<Vector3> normals = std::vector<Vector3>();

	for (int iPoly = 0; iPoly < m->GetPolygonCount(); iPoly++) {
		std::vector<FbxVector4> v = std::vector<FbxVector4>();
		std::vector<FbxVector4> n = std::vector<FbxVector4>();
		for (int iVert = 0; iVert < m->GetPolygonSize(iPoly); iVert++)
		{
			int index = m->GetPolygonVertex(iPoly, iVert);
			FbxVector4 vv = m->GetControlPointAt(index);
			v.push_back(vv);
			FbxVector4 nn;
			bool sN = m->GetPolygonVertexNormal(iPoly, iVert, nn);
			if (!sN) {
				LogError("NORMAL COULD NOT BE READ FOR POLY %d-%d", iPoly, iVert);
			}
			n.push_back(nn);
			LogMessage("POINT: %d:%d-%d", index, iPoly, iVert);
			LogMessage("\tVERTEX: %f : %f : %f", vv[0], vv[1], vv[2]);
			LogMessage("\tNORMAL: %f : %f : %f", nn[0], nn[1], nn[2]);
		}
		for (int i = 0; i < 3; i++) {
			verts.push_back(Vector3(v[i][0], v[i][1], v[i][2]));
			normals.push_back(Vector3(n[i][0], n[i][1], n[i][2]));
		}
	}


	return new Mesh(&verts[0], verts.size(), &normals[0], normals.size(), nullptr, NULL);
}
