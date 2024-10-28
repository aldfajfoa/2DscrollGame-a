#pragma once
#include "Engine/GameObject.h"
class Player;

class Lever :
    public GameObject
{
	int hImage;
	bool ReversX;
	Player* p;
	//‰~‚Ì“–‚½‚è”»’è
	bool CollideCircle(float x, float y, float r);
public:
	Lever(GameObject* scene);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void SetPosition(int x, int y);
};

