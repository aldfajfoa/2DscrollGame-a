#pragma once
#include "Engine/GameObject.h"
class Player;

/// <summary>
/// �v���C���[���������
/// </summary>
class Stone : public GameObject
{
public:
	Stone(GameObject* scene);
	~Stone();
	void Update() override;
	void Draw() override;
	void SetPosition(XMFLOAT3 pos);
	void Reset();
private:
	Player* pPlayer;
	int hImage;
	int timer;
	bool prevSpaceKey;
	float jumpSpeed;
	bool onGround;
};
