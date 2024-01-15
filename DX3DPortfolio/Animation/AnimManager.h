#pragma once
class AnimManager
{
public:
	AnimManager(SkeletalMesh* mesh);
	~AnimManager();

	void AddAnimation(string actorName, string animName, float speed, float direction);
	void PlaySequence(Actor::State state, float speed, float takeTime);

	void Update(float speed = 0, float direction = 0);
	void SetSubResources();

	void CreateTexture();

	void SetTarget(class Actor* target) { _target = target; }
private:
	void CreateClipTransform(int index);
	
	SkeletalMesh*& _meshRef;

	vector<AnimSequence*> _sequences = {};

	ClipTransform* _clipTransforms = nullptr;
	ClipTransform* _nodeTransforms = nullptr;

	FrameBuffer* _frameBuffer = nullptr;
	ID3D11Texture2D* _animationTexture = nullptr;
	ID3D11ShaderResourceView* _srv = nullptr;

	Actor* _target;

	Actor::State _state; // MoveComp 로 이동할 예정
};

