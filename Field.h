#pragma once
#include "Engine/GameObject.h"
class Camera;

/// <summary>
/// 地面（プレイフィールド）
/// </summary>
class Field : public GameObject
{
public:
	Field(GameObject* scene);
	~Field();
	void Reset();
	void Update() override;
	void Draw() override;

	/// <summary>
	/// 右側の点が当たっているか調べる
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	/// <returns>めりこんだ量(ドット)</returns>
	int CollisionRight(int x, int y);

	/// <summary>
	/// 左側の点が当たっているか調べる
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	/// <returns>めり込んだ量(ドット)</returns>
	int CollisionLeft(int x, int y);

	/// <summary>
	/// 下の点が当たっているか調べる
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	/// <returns>めり込んだ量(ドット)</returns>
	int CollisionDown(int x, int y);

	/// <summary>
	/// 上の点が当たっているか調べる
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	/// <returns></returns>
	int CollisionUp(int x, int y);

	int CollisionRight2(int x, int y);
	int CollisionLeft2(int x, int y);
	int CollisionDown2(int x, int y);
	int CollisionUp2(int x, int y);

	void IsScroll();
	bool GetLeftSc() { return LeftSc; }
	bool GetRightSc() { return RightSc; }
	bool IsCollisionRight(int i);
	bool IsCollisionLeft(int i);
	bool IsCollisionUp(int i);
	bool IsCollisionDown(int i);

	bool EnemyCollisionRight(int i);
	bool EnemyCollisionLeft(int i);
	void SetScroll(int scroll_) { scroll = scroll_; }
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	int Getscroll() { return scroll; }
	void ChangeChip(int x, int y, int changeNum);
private:
	Camera* cam;
	int hImage;
	int background;
	int stone;

	bool IsWallBlock(int x, int y);
	bool IsWallBlock2(int x, int y);
	int* Map;
	int* Mapbottom;//マップの下部(敵とか配置してる方)
	int width;
	int height;
	int sousa;
	int controll;
	int scroll;
	bool LeftSc, RightSc;
};
