#include "Lever.h"
#include "Field.h"
#include "Player.h"
#include "Camera.h"
#include "LeverMaster.h"
#include "LeverBrock.h"
#include "Field.h"

namespace 
{
	const Size L_SIZE = { 37,32 };
}

Lever::Lever(GameObject* scene) 
	:GameObject(scene, "Lever")
{
	hImage = LoadGraph("Assets/Lever_.png");
	assert(hImage > 0);
	ReversX = true;
	lMas = ((LeverMaster*)(this->GetParent()));
	fi = lMas->GetParent()->FindGameObject<Field>();
}

void Lever::Initialize()
{
}

void Lever::Update()
{
	p = fi->GetParent()->FindGameObject<Player>();
	//ƒvƒŒƒCƒ„[‚Æ‚Ì“–‚½‚è”»’è
	if (p != nullptr) {
		if (p->CollideCircle(transform_.position_.x + (L_SIZE.w / 2), transform_.position_.y + (L_SIZE.h / 2), 20.0f))
		{
			ReversX = false;
			DestroyLBrock();
		}
	}
}

void Lever::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	
	Camera* lcam = lMas->Getcam();
	Lscroll = fi->Getscroll();
	if (lcam != nullptr) {
		Lscroll = lcam->GetValue();
	}
	DrawRectGraph(x-Lscroll, y,0,0,L_SIZE.w,L_SIZE.h, hImage, TRUE, ReversX);
}

void Lever::Release()
{
}

void Lever::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

void Lever::DestroyLBrock()
{
	for (int i = 0; i < lMas->GetlBrocks().size(); i++)
	{
		if (LeverID == lMas->GetlBrocks()[i]->GetLeverBrockID())
		{
			int cx = lMas->GetlBrocks()[i]->GetPosition().x / 32;
			int cy = lMas->GetlBrocks()[i]->GetPosition().y / 32;
			fi->ChangeChip(cx, cy, 255);
			lMas->GetlBrocks()[i]->KillMe();
		}
	}
}
