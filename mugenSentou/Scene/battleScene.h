#pragma once
#include "baseScene.h"
#include "../objectList.h"
#include "../System/battleWindow.h"
#include "../System/Battle.h"
#include "../autoEnemySet.h"


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

	int waveCount;

	int playerNum[PARTY_MAX];
	int enemyNum[ENEMY_MAX];

	//int platerHandles[PARTY_MAX];
	//int enemyHandles[ENEMY_MAX];

	//ÉoÉgÉãÇÃèàóù
	Battle* battle;
	autoEnemySet autoEnSet;

	int enemyCount;
	int* enemyID;

	playerObject* players[PARTY_MAX];
	enemyObject* enemys[ENEMY_MAX];

	int playersImg[PARTY_MAX];
	int enemysImg[ENEMY_MAX];

	int cmdFontSize;
	int cmdFontSpace;

	int selCount;

	int infoFontSize;
	int infoFontSpace;

	battleWindow* UIwin;
	int actPattern;


#ifdef DEBUG
	int backImage;
#endif // DEBUG

};

