#include "LeverBrock.h"
#include "Field.h"
#include "Camera.h"
#include "LeverMaster.h"

namespace
{
	const Size LB_SIZE = { 32,32 };
}

LeverBrock::LeverBrock(GameObject* scene)
	:GameObject(scene, "LeverBrock")
{
	hImage = LoadGraph("Assets/bgchar.png");
	assert(hImage > 0);
	fi = ((Field*)(this->GetParent()));
}

void LeverBrock::Initialize()
{
	lMas = ((LeverMaster*)(this->GetParent()));
}

void LeverBrock::Update()
{
	fi = GetParent()->FindGameObject<Field>();
}

void LeverBrock::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;

	DrawRectGraph(x- fi->Getscroll(), y, LB_SIZE.w *4, LB_SIZE.h * 3, LB_SIZE.w, LB_SIZE.h, hImage, TRUE);
}

void LeverBrock::Release()
{
}
