#pragma once
class RasterizerState
{
public:
	RasterizerState();
	~RasterizerState();

	void SetState();
	void ChangeState(D3D11_FILL_MODE mode);

private:
	ID3D11RasterizerState* _rasterizerState;

	D3D11_RASTERIZER_DESC _desc = {};
};

