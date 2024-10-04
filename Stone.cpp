#include "Stone.h"
#include <assert.h>
#include "Camera.h"
#include "Player.h"
#include "Field.h"

namespace {
	const float MOVE_SPEED = 0.5f;
	const float GROUND = 400.0f;
	const float JUMP_HEIGHT = 64.0f * 2.0f;
	const float GRAVITY = 9.8f / 60.0f;
}

Stone::Stone(GameObject* scene) : GameObject(scene)
{
	hImage = LoadGraph("Assets/stone.png");
	assert(hImage > 0);
}

Stone::~Stone()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void Stone::Update()
{

	Field* pField = GetParent()->FindGameObject<Field>();

	if (pField != nullptr)
	{
		int push = pField->CollisionDown(transform_.position_.x + 17, transform_.position_.y + 20);

		if (push > 1)
		{
			transform_.position_.y -= push;
			transform_.position_.x -= push - 2;
			jumpSpeed = 0.0f;
			onGround = true;
		}
	}

	if (onGround == false)
	{
		transform_.position_.x += 3.0f;
		transform_.position_.y -= sqrtf(2 * GRAVITY * JUMP_HEIGHT);

		if (pField != nullptr)
		{
			int push = pField->CollisionDown(transform_.position_.x + 5, transform_.position_.y + 20);

			if (push > 0)
			{
				transform_.position_.y += push;
				jumpSpeed = 0.0f;
				onGround = true;
			}

		}
	}

	if (timer == 2)
	{
		Player* pPlayer = GetParent()->FindGameObject<Player>();
		pPlayer->SetPosition(transform_.position_.x, transform_.position_.y - 20);
	}

	jumpSpeed += GRAVITY;
	transform_.position_.y += jumpSpeed;

	if (--timer <= 0)
	{
		KillMe();
	}

	if (CheckHitKey(KEY_INPUT_R))
	{
		Reset();
	}
}

void Stone::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr) {
		x -= cam->GetValue();
	}
	DrawGraph(x, y, hImage, TRUE);
}

void Stone::SetPosition(XMFLOAT3 pos)
{
	transform_.position_ = pos;
	timer = 150;
}

void Stone::Reset()
{
	KillMe();
}
