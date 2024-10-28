#pragma once
#include "Engine/GameObject.h"
#include "Field.h"
class Camera;

class Gool :
    public GameObject
{
public:
	Gool(GameObject* scene);
	~Gool();
	void Update() override;
	void Draw() override;

	/// <summary>
	/// 旗の座標をセットする
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	void SetPosition(int x, int y);

	//円の当たり判定をする
	bool CollideCircle(float x, float y, float r);

	void Reset();
private:
	//Field* field;
	Camera* cam;
	bool prevSpaceKey;
	float jumpSpeed;
	int counter;
	bool onGround;
	float sinAngle;
	int hImage;
	float baseY;//生成時のY座標
};

