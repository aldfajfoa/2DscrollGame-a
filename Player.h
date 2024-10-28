#pragma once
#include "Engine/GameObject.h"
class Camera;
class Field;

/// <summary>
/// �v���C���[�L����
/// </summary>
class Player : public GameObject
{
public:
	Player(GameObject* scene);
	~Player();
	void Update() override;
	void Draw() override;

	/// <summary>
	/// �v���C���[�̍��W���Z�b�g����
	/// </summary>
	/// <param name="x">X���W</param>
	/// <param name="y">Y���W</param>
	void SetPosition(int x, int y);

	void Reset();

	int count;

	bool GetReversX() { return ReversX; }
	void ControlCollision();
	void SetGround(float _ground) { Ground = _ground; }
	bool MovePlayer();
private:
	int hImage;
	int kazu;

	GameObject* sceneTop;
	Camera* cam;
	Field* field;
	bool prevSpaceKey;
	float jumpSpeed;
	bool onGround;
	int counter;
	int rcount;
	int animType; //��
	int animFrame;//�R�}
	int frameCounter;
	float transparency;//�����x
	float readyTimer;
	bool ReversX;
	int tmpPosx,tmpPosy;
	int ceiling;
	int Ground;
	bool firstGround;

	enum State {
		S_Walk=0,
		S_Cry,
	};
	State state;
};