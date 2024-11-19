#pragma once
#include "Engine/GameObject.h"
class Field;
class LeverMaster;

class LeverBrock :
    public GameObject
{
	int hImage;
	int LeverBrockID;
	Field* fi;
	LeverMaster* lMas;
	int Lscroll;
public:
	LeverBrock(GameObject* scene);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void SetPosition(int x, int y) { transform_.position_.x = x;
	                                 transform_.position_.y = y;}
	void SetLeverBrockID(int ID) { LeverBrockID = ID; }
	int GetLeverBrockID() { return LeverBrockID; }
};

