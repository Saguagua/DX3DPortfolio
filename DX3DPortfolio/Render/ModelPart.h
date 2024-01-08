#pragma once

typedef VertexTextureNormalTangentBlend ModelVertex;

class ModelPart
{
public:
	ModelPart();
	~ModelPart();

	void UpdateVertices(void* data, UINT size);

	void IASetBuffer(D3D11_PRIMITIVE_TOPOLOGY type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	void Render(D3D11_PRIMITIVE_TOPOLOGY type = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	void RenderInstanced(UINT count);

	void SetName(string name) { _name = name; }
	string GetName() { return _name; }

	void SetMaterialSlot(UINT slot) { _materialSlot = slot; }

	template<typename T>
	void CreateBuffers(vector<T> vertices, vector<UINT> indices);

	UINT GetMaterialSlot() { return _materialSlot; }

protected:
	string _name;
	vector<UINT> _indices;

	VertexBuffer* _vBuffer;
	IndexBuffer* _iBuffer;
	UINT _materialSlot;
};

template<typename T>
void ModelPart::CreateBuffers(vector<T> vertices, vector<UINT> indices)
{
	_indices = indices;

	_vBuffer = new VertexBuffer(vertices);
	_iBuffer = new IndexBuffer(_indices);
}