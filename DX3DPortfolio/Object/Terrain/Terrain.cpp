#include "framework.h"
#include "Terrain.h"

Terrain::Terrain()
{
	CreateVertices();

	_mesh = new Mesh(_vertices, _indices);
	_material = new Material();

	_material->SetShader(L"Texture");
	_material->SetTexture(L"_Texture/IMG/LighthouseScene.png");
}

Terrain::~Terrain()
{
	delete _mesh;
	delete _material;
}

void Terrain::Update()
{
	Transform::Update();
}

void Terrain::Render()
{
	_mBuffer->SetVSBuffer(0);

	_mesh->IASetBuffer();
	_material->IASetBuffer();

	DC->DrawIndexed(_indices.size(), 0, 0);
}

void Terrain::CreateVertices()
{
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			VertexTexture v;
			v.pos = Vector3(j, 0, i);
			v.uv.x = j / (_width - 1);
			v.uv.y = 1 - i / (_height - 1);

			_vertices.push_back(v);
		}
	}

	for (int i = 0; i < _height - 1; i++)
	{
		for (int j = 0; j < _width - 1; j++)
		{
			int index1 = (_width * (i + 1)) + (j + 0);
			int index2 = (_width * (i + 1)) + (j + 1);
			int index3 = (_width * (i + 0)) + (j + 0);
			int index4 = (_width * (i + 0)) + (j + 1);

			_indices.push_back(index1);
			_indices.push_back(index2);
			_indices.push_back(index3);

			_indices.push_back(index3);
			_indices.push_back(index2);
			_indices.push_back(index4);
		}
	}
}
