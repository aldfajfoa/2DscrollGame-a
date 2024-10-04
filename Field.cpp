#include "Field.h"
#include <assert.h>
#include "Camera.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Gool.h"
#include "KanBan1.h"
#include "Engine/CsvReader.h"



Field::Field(GameObject* scene)
	:GameObject(scene)
{
	hImage = LoadGraph("Assets/bgchar.png");
	background = LoadGraph("Assets/mori.jpg");
	stone = LoadGraph("Assets/isi.png");
	sousa = LoadGraph("Assets/sousa.png");
	assert(hImage > 0);
	assert(background > 0);
	Map = nullptr;
}

Field::~Field()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
	if (Map != nullptr) {
		delete[] Map; //Mapは配列
	}
}

void Field::Reset()
{
	if (Map != nullptr) {
		delete[] Map;
		Map = nullptr;
	}
	CsvReader csv;//データを読むクラスのインスタンスを作成
	bool ret = csv.Load("Assets/stage1.csv");
	assert(ret);
	width = csv.GetWidth(0);
	height = csv.GetHeight();
	Map = new int[width * height];//C言語での動的二次元配列の取り方
	
	for (int h = 0; h < height; h++) 
	{
		if (csv.GetString(0, h) == "") 
		{
			height = h;
			break;
		}
		for (int w = 0; w < width; w++)
		{
			Map[h*width+w] = csv.GetInt(w, h);
		}
	}
	//Mapデータの中で0があれば、Playerの座標を0の位置にする
	for (int h = 0; h < height; h++) 
	{
		for (int w = 0; w < width; w++) 
		{
			switch (csv.GetInt(w,h+height+1))
			{
			case 0://player
			{
				Player* pplayer = GetParent()->FindGameObject<Player>();
				pplayer->SetPosition(w * 32, h * 32);
			}
			break;
			case 1://bird
			{
				Enemy1* pEne1 = Instantiate<Enemy1>(GetParent());
				pEne1->SetPosition(w * 32, h * 32);
			}
			break;
			case 2://Livingthings
			{
				Enemy2* pEne2 = Instantiate<Enemy2>(GetParent());
				pEne2->SetPosition(w * 32, h * 32);
			}
			break;
			case 3://Gool
			{
				Gool* Gools = Instantiate<Gool>(GetParent());
				Gools->SetPosition(w * 32, h * 32);
			}
			break;
			case 4://Gool
			{
				KanBan1* k1 = Instantiate<KanBan1>(GetParent());
				k1->SetPosition(w * 32, h * 32);
			}
			break;
			}
		}
	}
}

void Field::Update()
{
	if (CheckHitKey(KEY_INPUT_R))
		Reset();
}

void Field::Draw()
{
	DrawGraph(0,0, background, TRUE);

	DrawGraph(0, 0, stone, TRUE);

	DrawGraph(0, 50, sousa, TRUE);

	int scroll = 0;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr) 
	{
		scroll = cam->GetValue();
	}

	for (int y = 0; y < height; y++) 
	{
		for (int x = 0; x < width; x++) 
		{
			int chip = Map[y*width+x];
			DrawRectGraph(x*32-scroll, y*32, 32 * (chip % 16), 32 * (chip / 16), 32, 32, hImage, TRUE);
		}
	}
}

int Field::CollisionRight(int x, int y)
{
	if (IsWallBlock(x, y))
	{
		//当たっているので、めり込んだ量を返す
		return x % 32 + 1;
	}
	else
		return 0;
}

int Field::CollisionLeft(int x, int y)
{
	if (IsWallBlock(x, y)) 
	{
		//当たっているので、めり込んだ量を返す
		return x % 32/12;
	}
	else
		return 0;
}

int Field::CollisionDown(int x, int y)
{
	if (IsWallBlock(x, y)) 
	{
		//当たっているので、めり込んだ量を返す
		return y % 32 + 1;
	}
	else
		return 0;
}

int Field::CollisionUp(int x, int y)
{
	if (IsWallBlock(x, y)) 
	{
		//当たっているので、めり込んだ量を返す
		return y % 32 + 1;
	}
	else
		return 0;
}

bool Field::IsWallBlock(int x, int y)
{
	int chipX = x / 32;
	int chipY = y / 32;
	switch (Map[chipY*width+chipX]) 
	{
	case 16:
	case 17:
	case 18:
	case 19:
	case 32:
	case 33:
	case 34:
	case 35:
		return true;
	}
	return false;
}
