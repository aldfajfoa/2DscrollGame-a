#pragma once
#include "Engine/GameObject.h"
class GameClear :
    public GameObject
{
	int count;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameClear(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
private:
	int clear;
	int mori;
	int s;
	int e;
	XINPUT_STATE input;
};