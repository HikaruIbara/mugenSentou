#pragma once

struct StatusPer
{
	std::string name;	//�L�����N�^�[�̖��O
	int hp;				//�̗�
	int hpMax;			//�̗͂̍ő�l
	int at;				//�����U����
	int atMa;			//���@�U����
	int de;				//�����h���
	int deMa;			//���@�h���
	int speed;			//�s�����x
	int mp;				//���@��
	int mpMax;			//���@�ʂ̍ő�l
	int mpUp;			//�^�[�����̖��@�ʂ̉񕜗�
	int lv;				//���x��
	int exp;			//�o���l
};

#define STRING(var) #var

const enum PlayerObjNum
{
	playerdammy,
	reimu,
	// ���Ō�ɒǉ�����Ƃ��́����X�V���ĂˁB
};
constexpr int maxPlObjNum = reimu + 1;
const std::string playerObjName[]
{
	"�_�~�[",
	"�ꂢ��"
};

const enum EnemyObjNum
{
	enemydammy,
	ran,
	chen,
	mai,
	satono
	// ���Ō�ɒǉ�����Ƃ��́����X�V���ĂˁB
};
constexpr int maxEnObjNum = satono + 1;
const std::string enemyObjName[]
{
	"�_�~�[",
	"���",
	"������",
	"�܂�",
	"���Ƃ�"
};

const enum BossObjNum
{
	bossdammy,
	yukari,
	okina
	// ���Ō�ɒǉ�����Ƃ��́����X�V���ĂˁB
};
constexpr int maxBossObjNum = okina + 1;
const std::string bossObjName[]
{
	"�_�~�[",
	"�䂩��",
	"������"
};

class AllSt
{
private:
	StatusPer initPlSt[maxPlObjNum] =
	{
		{"dammy",-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{"reimu",10,10,6,9,12,15,10,4,4,1,1,10}

	};

	StatusPer initEnSt[maxEnObjNum] =
	{
		{"dammy" ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{"ran"   ,20,20, 4, 7,10,12, 7, 6, 6, 1, 1,10},
		{"chen"  ,20,20, 4, 7,10,12, 6, 6, 6, 1, 1,10},
		{"mai"   ,20,20, 4, 7,10,12, 4, 6, 6, 1, 1,10},
		{"satono",20,20, 4, 7,10,12, 3, 6, 6, 1, 1,10}
	};
public:
	StatusPer GetPlInitSt(PlayerObjNum num)
	{
		return initPlSt[num];
	}
	StatusPer GetPlInitSt(int num)
	{
		return initPlSt[num];
	}
	std::string GetPlName_EN(int num)
	{
		return initPlSt[num].name;
	}
	std::string GetPlName_JP(int num)
	{
		return playerObjName[num];
	}

	StatusPer GetEnInitSt(EnemyObjNum num)
	{
		return initEnSt[num];
	}
	StatusPer GetEnInitSt(int num)
	{
		return initEnSt[num];
	}
	std::string GetEnName_EN(int num)
	{
		return initEnSt[num].name;
	}
	std::string GetEnName_JP(int num)
	{
		return enemyObjName[num];
	}

	StatusPer nowAllStatus[maxBossObjNum] =
	{
		{"dammy",-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{"reimu",10,10,5,2,6,10,10,1,1,0},
		{"ran",50,50,5,2,5,10,10,1,1,0},
	};
};
