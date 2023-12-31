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
	//�w��̐l���̓G�摜��ǂݍ���
	void LoadEnemyGraph(int* enemyID, int* enemyHandle, int size);
	//�w��̐l���̓G�摜��ݒ肷��
	void SetEnemyGraph(enemyObject* enemyObj[], int* enemyhandle, int size);
	//�w��̐l���̏����ݒ������
	void InitEnemyStatus(enemyObject* enemyObj[], int* enemyID, int size);

	void SetEnemyStatus(enemyObject* enemyObj[], int* enemyID, int size);
};

