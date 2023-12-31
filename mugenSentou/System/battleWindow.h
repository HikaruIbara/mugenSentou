#pragma once
#include "baseWindow.h"
#include "../enemyObject.h"
#include "../Sound/playSe.h"
using namespace MSL;

//ウィンドウの種類
#define ENEMY_INFO		0
#define COMMAND			1
#define PLAYER_INFO		2

#define NONE 0
#define ATTACK 1
#define MAGICK 2
#define DEFENSE 3
#define RECOVER 4

const Select selectEne[] =
{
	{0,2,"やくもらん\nやくもらん\n"}
};

const Select selectAct[] =
{
	{ 0, 4, "こうげき\nまほう\nぼうぎょ\nアイテム\n"		},
	//{ 1, 2, "かくとう\nつるぎ\n"						},
	//{ 2, 4, "ファイア\nアクア\nリーフ\nリカバリ\n"		},
	//{ 3, 1, "ぼうぎょ\n"								},
	//{ 4, 1, "アイテム\n"								},
	//{ 5, 3, "なぐり\nけり\nカウンタ\n"}
};

class battleWindow {
public:
	battleWindow();
	~battleWindow();

	//コマンドを返す
	ReAction* action();
	void draw();
	void init(int enemyID[], int size);
	void start();
	void end();

	int GetRowNum() { return nowRowNum; }

private:
	AllSt allst;
	baseWindow* baseWin[4];
	int selectWin;
	int selectNum;
	int nowRowNum;
	int rowNum;
	bool selected;
	ReAction reAct;
	//void SetNowCursol(int nowCur) { nowRowNum = nowCur; };
};