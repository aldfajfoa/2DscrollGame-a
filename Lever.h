#pragma once
#include "Engine/GameObject.h"
class Player;
class LeverMaster;
class LeverBrock;
class Field;

class Lever :
    public GameObject
{
	int hImage;
	bool ReversX;
	Player* p;
	Field* fi;
	LeverMaster* lMas;
	int Lscroll;
	int LeverID;
	int soundHandle;//‰¹º‚Ìƒnƒ“ƒhƒ‹
public:
	Lever(GameObject* scene);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void SetPosition(int x, int y);
	void ReversXfalse() { ReversX =false; }
	void DestroyLBrock();
	void SetLeverID(int ID) { LeverID = ID; }
};

