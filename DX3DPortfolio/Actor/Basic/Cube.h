#pragma once
class Cube :public Transform
{
public:
	Cube();
	~Cube();

	void Update();
	void Render();

private:
	void CreateVertices();

	Vector3 _size = {10.0f, 10.0f, 10.0f};

	vector<VertexTexture> _vertices;
	vector<UINT> _indices;

	StaticMesh* _mesh;
	Material* _material;
};

