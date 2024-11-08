#pragma once
#include "Engine/GameObject.h"
class Player;

class SpeedStone :
    public GameObject
{
public:
    SpeedStone();
    SpeedStone(GameObject parent);
    ~SpeedStone();
    void Initialize()override;
    void Update() override;
    void Draw() override;

    /// <summary>
    /// スピードストーンの座標をセットする
    /// </summary>
    /// <param name="x">X座標</param>
    /// <param name="y">Y座標</param>
    void SetPosition(int x, int y);


    bool CollideCircle(float x, float y, float r);

    void Reset();

    bool IsAlive() { return isAlive; }
    void DeActivateMe() { isAlive = false; }
    void ActivateMe() { isAlive = true; }
    void KillStone();

private:
    bool prevSpaceKey;
    float jumpSpeed;
    int counter;
    bool onGround;
    float sinAngle;
    int hImage;
    float baseY;//生成時のY座標
    int animType; //状況
    int animFrame;//コマ
    int frameCounter;
    bool IsReverse;
    int tmpPosx, tmpPosy;
    bool isAlive;
    Player* p;
};

