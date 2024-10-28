#include "Lever.h"
#include "Field.h"
#include "Player.h"

namespace 
{
	const Size L_SIZE = { 64,64 };
}

bool Lever::CollideCircle(float x, float y, float r)
{
	return false;
}

Lever::Lever(GameObject* scene)
{
	hImage = LoadGraph("Assets/Lever_.png");
	assert(hImage > 0);
	ReversX = false;
}

void Lever::Initialize()
{
	p = GetParent()->FindGameObject<Player>();
}

void Lever::Update()
{
	if (CollideCircle(transform_.position_.x + 32.0f, transform_.position_.y + 32.0f, 20.0f))
	{
	}
}

void Lever::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Field* field = GetParent()->FindGameObject<Field>();
	DrawRectGraph(x - field->Getscroll(), y,0,0,L_SIZE.w,L_SIZE.h, hImage, TRUE, ReversX);
}

void Lever::Release()
{
}

void Lever::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}
