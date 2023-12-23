#include "autoEnemySet.h"

autoEnemySet::autoEnemySet()
{
	initXshit();
}

autoEnemySet::~autoEnemySet()
{
}

int* autoEnemySet::SetEnemy(enemyObject* enemys[])
{
	int enemyNum = 0;
	int* enemyID;
	int* enemyHandl;
	if (false)
	{//�{�X�� ���̂Ƃ�������\��Ȃ�
		enemyNum = 3;

	}
	else
	{//�G����
		//�G�̐l�������߂�
		enemyNum = xorshift32() % 4 + 1;
		if (enemyNum > ENEMY_MAX)
			return nullptr;//�G���[

		//�G�̐l����ID�̔z����m�ۂ���
		enemyID = new int[enemyNum];
		enemyHandl = new int[enemyNum];

		int maxAllEnIDNum = maxEnObjNum - 1;
		int* allEnID = new int[maxAllEnIDNum];

		for (int i = 0; i < maxAllEnIDNum; i++)
		{
			allEnID[i] = i + 1;
		}

		//�z����V���b�t������
		for (int i = maxAllEnIDNum - 1; i >= 0; --i)
		{
			int j = xorshift32() % (i + 1);
			std::swap(allEnID[i], allEnID[j]);
		}

		//�����_���œG�̎�ނ����߂�
		for (int i = 0; i <= enemyNum; i++)
		{
			enemyID[i] = allEnID[i];
		}

		LoadEnemyGraph(enemyID, enemyHandl, enemyNum);
		SetEnemyGraph(enemys, enemyHandl, enemyNum);
		InitEnemyStatus(enemys, enemyID, enemyNum);

	}

	return enemyID;
}

void autoEnemySet::LoadEnemyGraph(int* enemyID, int* enemyHandle, int size)
{
	char filepath[512] = { 0 };

	for (int i = 0; i < size; i++)
	{
		sprintf_s(filepath, "data/image/enemy/%s.png", allSt.GetEnName_EN(enemyID[i]).c_str());
		enemyHandle[i] = LoadGraph(filepath);
		for (int j = 0; j < 512; j++)
		{
			filepath[i] = 0;
		}
	}
}

void autoEnemySet::SetEnemyGraph(enemyObject* enemyObj[], int* enemyhandle, int size)
{
	for (int i = 0; i < size; i++)
	{
		enemyObj[i]->setMainImage(enemyhandle[i]);
	}
}

void autoEnemySet::InitEnemyStatus(enemyObject* enemyObj[], int* enemyID, int size)
{
	for (int i = 0; i < size; i++)
	{
		enemyObj[i]->init();
		enemyObj[i]->setStatus(enemyID[i],ENEMY);
		enemyObj[i]->setID(enemyID[i]);
	}
}

/*
	//�L�����N�^�[�C���[�W�̃��[�h
	int p_0 = LoadGraph("data/image/player/reimu.png");
	int e_0 = LoadGraph("data/image/enemy/ran.png");
	int boss_0 = LoadGraph("data/image/enemy/yukari.png");

	//�v���C���[�ƃG�l�~�[�̐ݒ�
	for (int i = 0; i < PARTY_MAX_MASTER; i++)
	{
		playersImg[i] = p_0;
		players[i]->setMainImage(playersImg[i]);
		players[i]->init();

	}
	for (int i = 0; i < ENEMY_MAX_MASTER; i++)
	{
		enemysImg[i] = e_0;
		enemys[i]->setMainImage(enemysImg[i]);
		enemys[i]->init();

	}
	players[0]->init();

	players[0]->setStatus(reimu);
	enemys[0]->setStatus(ran);
	enemys[1]->setStatus(ran);
*/