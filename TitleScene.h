#pragma once
#include "Engine/GameObject.h"
class TitleScene :
    public GameObject
{
	int count;
public:
	//�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
private:
	int title;
	int mori;
	int moji1;
	int moji2;
	XINPUT_STATE input;
};

