#pragma once
#include "Engine/GameObject.h"
class GameClear :
    public GameObject
{
	int count;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	GameClear(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
private:
	int clear;
	int mori;
	int s;
	int e;
	XINPUT_STATE input;
};