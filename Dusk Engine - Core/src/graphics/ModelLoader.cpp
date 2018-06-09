#include "fbxsdk.h"
#include "fbxsdk/fileio/fbxiosettings.h"
#include "ModelLoader.h"
#include "../core/Logger.h"
#include "glm/vec4.hpp"
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
		LogError("Mesh \"%s\" not found! Did you place it in the output folder?", path);
		return nullptr;
	}

	m->GenerateNormals();

	std::vector<glm::vec4> verts = std::vector<glm::vec4>();
	std::vector<glm::vec4> normals = std::vector<glm::vec4>();

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
			verts.push_back(glm::vec4(v[i][0], v[i][1], v[i][2], 1));
			normals.push_back(glm::vec4(n[i][0], n[i][1], n[i][2], 1));
		}
	}


	return new Mesh(&verts[0], verts.size(), &normals[0], normals.size(), nullptr, NULL);
}
