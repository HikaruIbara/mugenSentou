#include "Battle.h"

Battle::Battle()
{
	isBtl = false;

	isMyTurn = false;
	TurnCount = 0;
	isTurnSart = false;
	isTurnEnd = false;

	isBtlWin = false;

	for (int i = 0; i < PARTY_MAX; i++)
	{
		playerSt[i] = new Status();

	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemySt[i] = new Status();

	}

	tarEnemyNum = 0;
	actPattern = 0;
	for (int i = 0; i < OBJ_MAX; i++)
	{
		actOrder[i].id = 0;
		actOrder[i].speed = 0;
	}
}

Battle::~Battle()
{
	for (int i = 0; i < PARTY_MAX; i++)
	{
		delete playerSt[i];

	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		delete enemySt[i];
	}
}


void Battle::InitBattle()
{
	isMyTurn = false;
	TurnCount = 0;
	isTurnSart = false;
	isTurnEnd = false;

	isBtlWin = false;

	//�����̏�����
	initXshit();

	//for (int i = 0; i < PARTY_MAX; i++)
	//{
	//	playerSt[i]->SetDeathFlag(true);
	//	playerSt[i]->initStatus();
	//}
	//for (int i = 0; i < ENEMY_MAX; i++)
	//{
	//	enemySt[i]->SetDeathFlag(true);
	//	enemySt[i]->initStatus();
	//}


}

void Battle::StratBattle(Status* pl[PARTY_MAX], Status* en[ENEMY_MAX])
{
	if (isBtl)
		return;

	InitBattle();

	for (int i = 0; i < PARTY_MAX; i++)
	{
		playerSt[i] = pl[i];
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemySt[i] = en[i];

	}

	isBtl = true;
	isTurnSart = true;

}

bool Battle::ActionBattle()
{
	if (!isBtl)
		return false;

	if (isTurnEnd)
	{
		TurnEnd();
		return true;
	}

	if (isTurnSart)
		TurnStrat();

	//todo ���݌Œ�̃L�������m�����s���ł��Ȃ��̂Ŏw��̃L�������m�łł���悤�ɂ���
	if (actPattern != 0)
		ObjAction();

	//todo ���t���[���퓬�ɎQ�����Ă���l�S����HP���Q�Ƃ��Ă��邽�ߗv���P
	if (CheckEndBattle())
	{
		EndBattle();
		return false;

	}

	return true;
}

void Battle::DrawBattle()
{
	if (!isBtl)
		return;

}


bool Battle::EndBattle()
{
	isBtl = false;

	if (isBtlWin)
	{

	}
	else
	{

	}

	return isBtlWin;
}

int Battle::GetNowTurn()
{
	return TurnCount;
}

void Battle::TargetEnemy(int tarEnemy)
{
	tarEnemyNum = tarEnemy;
}

void Battle::SelectCmd(int cmd)
{
	actPattern = cmd;
}

void Battle::SetAct(ReAction act)
{
	tarEnemyNum = act.tarEnemyNum;
	actPattern = act.actPattern;
	playerSt[0]->SetTarID(act.tarEnemyNum);
	playerSt[0]->SetActID(act.actPattern);
}

void Battle::SetTurnStart()
{
	isTurnSart = true;
	isTurnEnd = false;
}

void Battle::ObjAction()
{
	int enCount = 0;
	int plCount = 0;

	for (int i = 0; i < OBJ_MAX; i++)
	{
		int id = actOrder[i].id;

		if (id == 0)
		{
			break;
		}
		else
		{
			if (id >= 100)
			{//�v���C���[
				int act = playerSt[plCount]->GetActID();
				int tar = playerSt[plCount]->GetTarID();

				switch (act)
				{
				case ATTACK:
					Attack(playerSt[plCount], enemySt[tar]);
					break;
				case MAGICK:
					Magick(playerSt[plCount], enemySt[tar]);
					break;
				case DEFENSE:
					Defense(playerSt[plCount]);
					break;
				case RECOVER:
					Recover(playerSt[plCount]);
					break;
				}
				playerSt[plCount]->SetActID(NONE);
				plCount++;
			}
			else
			{//�G

				int act = 0;
				int tar = 0;

				for (int j = 0; j < maxEnObjNum; j++)
				{
					if (enemySt[j]->GetID() == id)
					{//
						act = enemySt[j]->GetActID();
						tar = enemySt[j]->GetTarID();

					}
				}

				switch (act)
				{
				case ATTACK:
					Attack(enemySt[enCount], playerSt[tar - 1]);
					break;
				case MAGICK:
					Magick(enemySt[enCount], playerSt[tar - 1]);
					break;
				case DEFENSE:
					Defense(enemySt[enCount]);
					break;
				case RECOVER:
					Recover(enemySt[enCount]);
					break;
				}
				//enemySt[enCount]->SetActID(NONE);
				enCount++;
			}
		}
	}

	actPattern = 0;
	isTurnEnd = true;
}

void Battle::GetObjOrder()
{
	int liveObjNum = 0;


	//�X�s�[�h��ID����z��ɓ����
	for (int i = 0; i < PARTY_MAX; i++)
	{
		if (playerSt[i]->GetHp() > 0)
		{
			actOrder[liveObjNum].id = playerSt[i]->GetID();
			actOrder[liveObjNum].speed = playerSt[i]->GetSpeed();
			liveObjNum++;
		}
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemySt[i]->GetHp() > 0)
		{
			actOrder[liveObjNum].id = enemySt[i]->GetID();
			actOrder[liveObjNum].speed = enemySt[i]->GetSpeed();
			liveObjNum++;
		}
	}

	//�������ɓ���ւ���
	quick_sort(actOrder, 0, liveObjNum - 1);


}

//�U������
bool Battle::Attack(Status* attack, Status* dameged)
{
	int hp = dameged->GetHp();
	int at = attack->GetAt();
	int de = dameged->GetDe();

	int damage = at / de;

	if (damage > 0)
	{
		hp -= damage;
		if (hp < 0)
			hp = 0;
		dameged->SetHp(hp);
		dameged->CheckDeathFlag();
		return true;
	}
	else
	{//���Ȃ炸5%�̃_���[�W�͐H�炤
		damage = (int)(at * 0.05);
		if (damage <= 0)
			damage = 1;
		hp -= damage;
		if (hp < 0)
			hp = 0;
		dameged->SetHp(hp);
		dameged->CheckDeathFlag();
		return false;
	}

	return false;
}

//���@�U���v�Z
bool Battle::Magick(Status* attack, Status* dameged)
{
	int hp = dameged->GetHp();
	int at = attack->GetAtMa();
	int de = dameged->GetDeMa();

	//�S�����Ōv�Z���邽��0�`100�̊Ԃ̐��l�ł���K�v������
	int tmpDe = (100 - de);
	if (tmpDe > 100)
		tmpDe = 100;
	else if (tmpDe < 0)
		tmpDe = 0;

	int damage = (int)(at * tmpDe * 0.01f);

	if (damage > 0)
	{//�_���[�W���ʂ����ꍇ
		hp -= damage;
		if (hp < 0)
			hp = 0;
		dameged->SetHp(hp);
		dameged->CheckDeathFlag();
		return true;
	}
	else if (damage <= 0)
	{//�_���[�W���ʂ�Ȃ������ꍇ
		return false;
	}

	return false;
}

//�h��v�Z
bool Battle::Defense(Status* myStatus)
{
	int addDe = myStatus->GetDe();

	addDe = (int)(addDe * 1.5);

	myStatus->SetDe(addDe);
	return true;
}

//�񕜌v�Z
bool Battle::Recover(Status* mystatus)
{
	//�_���[�W��
	int hpDifVal = mystatus->GetHpMax() - mystatus->GetHp();

	//�_���[�W���󂯂Ă��Ȃ���Ή񕜂��Ȃ�
	if (hpDifVal <= 0)
		return false;

	//�񕜗ʂ͖��@�U���ɔ�Ⴗ��
	int recoverVal = mystatus->GetAtMa();

	//�񕜗ʂ��ő�HP���񕜂��Ȃ��悤�ɂ���
	if (hpDifVal < recoverVal)
	{
		recoverVal = hpDifVal;
	}

	mystatus->AddHp(recoverVal);

	return true;
}

void Battle::TurnStrat()
{
	GetObjOrder();


	isTurnSart = false;
}

void Battle::TurnEnd()
{
	TurnCount++;

	isTurnEnd = false;
	isTurnSart = true;
}

void Battle::AutoEnemySet()
{

}

bool Battle::CheckAllHPZero(Status* objList[], int size)
{
	for (int i = 0; i < size; i++)
	{//hp���c���Ă�����false��Ԃ��A�����c���Ă��锻��ɂ���
		if (objList[i]->GetHp() > 0)
			return false;
	}

	//�S����hp��0�ȉ��̎�true��Ԃ��A�S��������ł��锻��ɂ���
	return true;
}

bool Battle::CheckEndBattle()
{
	int plSize = sizeof(playerSt) / sizeof(playerSt[0]);
	int enSize = sizeof(enemySt) / sizeof(enemySt[0]);

	if (CheckAllHPZero(playerSt, plSize))
	{//����
		isBtlWin = false;
		return true;
	}
	else if (CheckAllHPZero(enemySt, enSize))
	{//����
		isBtlWin = true;
		return true;
	}

	return false;
}

////�l����������֐�
//void Battle::swap(ObjOrder* a, ObjOrder* b) {
//
//	ObjOrder* acttemp = a;
//	a = b;
//	b = acttemp;
//}
//
///*�N�C�b�N�\�[�g*/
//void Battle::QuickSort(ObjOrder A[], int left, int right)
//{
//	// �ϐ���`
//	int Left, Right;
//	int pivot;
//
//	// �����l�͈�������
//	Left = left; Right = right;
//
//	// ��͐^�񒆂ɐݒ�
//	pivot = A[(left + right) / 2].speed;
//
//	// �\�[�e�B���O
//	while (1) {
//
//		// ���菬�����l�������猩���Ă���
//		while (A[Left].speed < pivot) Left++;
//
//		// ����傫���l���E���猩���Ă���
//		while (pivot < A[Right].speed) Right--;
//
//		// ���������l�̏������t�ɂȂ�����I�� 
//		if (Left >= Right) break;
//
//		// �l������
//		swap(&A[Left], &A[Right]);
//
//		// ���̒l�Ɉړ�
//		Left++; Right--;
//
//	}
//
//	//���̃f�[�^�Q��ΏۂƂ��ăN�C�b�N�\�[�g���ċA
//	if (left < Left - 1) QuickSort(A, left, Left - 1);
//
//	//�E�̃f�[�^�Q��ΏۂƂ��ăN�C�b�N�\�[�g���ċA
//	if (Right + 1 < right) QuickSort(A, Right + 1, right);
//
//}

int Battle::partition(ObjOrder A[], int p, int r) {
	int i, j;
	ObjOrder x, tmp;
	// initialize
	i = p - 1;
	x = A[r];
	for (j = p; j < r; j++) {
		if (A[j].speed <= x.speed) {
			i++;
			// exchange
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	// exchange
	tmp = A[i + 1];
	A[i + 1] = x;
	A[r] = tmp;

	return i + 1;
}

void Battle::quick_sort(ObjOrder A[], int p, int r) {
	int q;  // partition�����̊�ƂȂ�v�f�̃C���f�b�N�X
	if (p < r) {
		q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}
