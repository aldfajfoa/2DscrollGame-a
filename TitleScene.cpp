#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Player.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene")
{
	title = LoadGraph("Assets/Title.png");
	mori = LoadGraph("Assets/mori1.jpg");
	moji1 = LoadGraph("Assets/Start.png");
	moji2 = LoadGraph("Assets/exit.png");
}

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	count -= 1;
	// “ü—Íó‘Ô‚ðŽæ“¾
	GetJoypadXInputState(DX_INPUT_PAD1, &input);

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TEST);
		//pPlayer->Player();
		//CheckHitKey
	}
	if (input.Buttons[XINPUT_BUTTON_START] == 1)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		Release();
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}

	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		exit(0);
	}
	if (input.Buttons[XINPUT_BUTTON_BACK])
	{
		if (count <= 0)
		{
			exit(0);
		}
	}
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, mori, TRUE);
	DrawGraph(100, 200, title, TRUE);
	DrawGraph(200, 400, moji1, TRUE);
	DrawGraph(200, 500, moji2, TRUE);
}

void TitleScene::Release()
{
	DeleteGraph(title);
	DeleteGraph(mori);
	DeleteGraph(moji1);
	DeleteGraph(moji2);
}
