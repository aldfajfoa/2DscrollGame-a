#include "LeverMaster.h"
#include "Lever.h"
#include "LeverBrock.h"
#include "Camera.h"

LeverMaster::LeverMaster(GameObject* scene)
	:GameObject(scene, "LeverMaster")
{
	for (int i = 0; i < LEVER_NUM; i++)
	{
		Lever* le = Instantiate<Lever>(this);
		Levers[i] = le;
	}
}

void LeverMaster::Initialize()
{
}

void LeverMaster::Update()
{
	cam = GetParent()->FindGameObject<Camera>();
	int x = (int)transform_.position_.x - cam->GetValue();
}

void LeverMaster::Draw()
{
}

void LeverMaster::Release()
{
}

void LeverMaster::SetLeverPos(int num, int x, int y)
{
	Levers[num - 600]->SetPosition(x, y);
	Levers[num - 600]->SetLeverID(num - 600);
}

void LeverMaster::birthLeverBrock(int x, int y, int ID)
{
	LeverBrock* l = Instantiate<LeverBrock>(GetParent());
	l->SetPosition(x, y);
	l->SetLeverBrockID(ID);
	lBrocks.push_back(l);
}
