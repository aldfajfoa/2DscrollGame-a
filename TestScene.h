#pragma once
#include "Engine/GameObject.h"
#include <DxLib.h> // DxLibの機能を利用する場合

//テストシーンを管理するクラス
class TestScene : public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TestScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	bool CanMove();
	void StartDead();
private:
	enum State {
	    S_Ready, //Ready表示中(2秒間すたーとを表示)
	    S_Play, //ゲーム中
		S_Clear, //ゲームクリア(クリアを表示してボタンが押されるまで待つ)
		S_Dead, //死亡(ゲームオーバーを表示してボタンが押されるまで待つ)
	};
	State state;          // 現在のステート
	float readyTimer;     // Ready 表示のタイマー
	bool isSoundPlaying;  // 音声再生中かを確認するフラグ
	int soundHandle;      // 音声のハンドル

	XINPUT_STATE input;   // コントローラーの入力状態

	// ステートの切り替えと更新処理
	void StartReady();
	void UpdateReady();
	void StartPlay();
	void UpdatePlay();
	void StartClear();
	void UpdateClear();
	void UpdateDead();
};