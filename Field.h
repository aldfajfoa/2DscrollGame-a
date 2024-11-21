#pragma once
#include "Engine/GameObject.h"
class Camera;
class Player;

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

	void IsScroll();
	bool GetLeftSc() { return LeftSc; }
	bool GetRightSc() { return RightSc; }

	bool EnemyCollisionRight(int i);
	bool EnemyCollisionLeft(int i);
	void SetScroll(int scroll_) { scroll = scroll_; }
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	int Getscroll() { return scroll; }
	void ChangeChip(int x, int y, int changeNum);
private:
	const int CH_SIZE = 32;//マップチップサイズ
	Camera* cam;
	int hImage;
	int background;
	int stone;

	bool IsWallBlock(int x, int y);
	int* Map;
	int Backnum;//背景の枚数
	int width;
	int height;
	int sousa;
	int controll;
	int scroll;
	bool LeftSc, RightSc;
};
