#pragma once
#include "enemyObject.h"
#include "mikainoLib/mikainoLib.h"
#include "AllStatus.h"

struct StatusSetInfo
{
	Status* playerSt;
	int wave;
	int trun;

};

class autoEnemySet
{
public:
	autoEnemySet();
	~autoEnemySet();

	int* SetEnemy(enemyObject* enemys[], StatusSetInfo* stInfo);
private:
	AllSt allSt;
	StatusSetInfo stInfo;
	//指定の人数の敵画像を読み込む
	void LoadEnemyGraph(int* enemyID, int* enemyHandle, int size);
	//指定の人数の敵画像を設定する
	void SetEnemyGraph(enemyObject* enemyObj[], int* enemyhandle, int size);
	//指定の人数の初期設定をする
	void InitEnemyStatus(enemyObject* enemyObj[], int* enemyID, int size);

	void SetEnemyStatus(enemyObject* enemyObj[], int* enemyID, int size);
};

