#pragma once
#include "enemyObject.h"
#include "mikainoLib/mikainoLib.h"
#include "AllStatus.h"

class autoEnemySet
{
public:
	autoEnemySet();
	~autoEnemySet();

	int* SetEnemy(enemyObject* enemys[]);
private:
	AllSt allSt;

	//�w��̐l���̓G�摜��ǂݍ���
	void LoadEnemyGraph(int* enemyID, int* enemyHandle, int size);
	//�w��̐l���̓G�摜��ݒ肷��
	void SetEnemyGraph(enemyObject* enemyObj[], int* enemyhandle, int size);
	//�w��̐l���̏����ݒ������
	void InitEnemyStatus(enemyObject* enemyObj[], int* enemyID, int size);
};

