#pragma once
#include "baseScene.h"
#include "objectList.h"
#include "battleWindow.h"

//ウィンドウの種類
#define ENEMY_INFO		0
#define COMMAND			1
#define PLAYER_INFO		2

class battleScene :
	public baseScene
{
public:

	battleScene();
	~battleScene();

	int action();
	void draw();
	void init();
	void end();

private:
	void playerAlignment(int num);
	void enemyAlignment(int num);
	void uiDraw();
	void drawHPBar(Vector2 pos, int len, int maxhp, int hp);

	playerObject* players[4];
	enemyObject* enemys[16];

	int playersImg[4];
	int enemysImg[16];

	int cmdFontSize;
	int cmdFontSpace;

	int infoFontSize;
	int infoFontSpace;

	battleWindow* cmdWindow[4];

	struct Cursol
	{
		Vector2 pos_1 = Vector2(0, 0);
		Vector2 pos_2 = Vector2(0, 16);
		Vector2 pos_3 = Vector2(16, 8);

		Vector2 oldPos = Vector2(0, 0);

		int yNum = 0; 

		void moveCoursol(Vector2 pos)
		{
			pos_1 -= oldPos;
			pos_2 -= oldPos;
			pos_3 -= oldPos;

			pos_1 += pos;
			pos_2 += pos;
			pos_3 += pos;

			oldPos = pos;
		}

		void drawCursol(Vector2 pos, int color, bool fillFlag)
		{
			moveCoursol(pos);

			DrawTriangle(pos_1.x, pos_1.y,
				pos_2.x, pos_2.y,
				pos_3.x, pos_3.y,
				color, fillFlag);
		}
	}cursol;

	Vector2 cursolPos;

};

