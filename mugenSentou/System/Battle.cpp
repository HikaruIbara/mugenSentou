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

	//乱数の初期化
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

	//todo 現在固定のキャラ同士しか行動できないので指定のキャラ同士でできるようにする
	if (actPattern != 0)
		ObjAction();

	//todo 毎フレーム戦闘に参加している人全員のHPを参照しているため要改善
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
			{//プレイヤー
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
			{//敵

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


	//スピードとID情報を配列に入れる
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

	//早い順に入れ替える
	quick_sort(actOrder, 0, liveObjNum - 1);


}

//攻撃処理
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
	{//かならず5%のダメージは食らう
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

//魔法攻撃計算
bool Battle::Magick(Status* attack, Status* dameged)
{
	int hp = dameged->GetHp();
	int at = attack->GetAtMa();
	int de = dameged->GetDeMa();

	//百分率で計算するため0～100の間の数値である必要がある
	int tmpDe = (100 - de);
	if (tmpDe > 100)
		tmpDe = 100;
	else if (tmpDe < 0)
		tmpDe = 0;

	int damage = (int)(at * tmpDe * 0.01f);

	if (damage > 0)
	{//ダメージが通った場合
		hp -= damage;
		if (hp < 0)
			hp = 0;
		dameged->SetHp(hp);
		dameged->CheckDeathFlag();
		return true;
	}
	else if (damage <= 0)
	{//ダメージが通らなかった場合
		return false;
	}

	return false;
}

//防御計算
bool Battle::Defense(Status* myStatus)
{
	int addDe = myStatus->GetDe();

	addDe = (int)(addDe * 1.5);

	myStatus->SetDe(addDe);
	return true;
}

//回復計算
bool Battle::Recover(Status* mystatus)
{
	//ダメージ量
	int hpDifVal = mystatus->GetHpMax() - mystatus->GetHp();

	//ダメージを受けていなければ回復しない
	if (hpDifVal <= 0)
		return false;

	//回復量は魔法攻撃に比例する
	int recoverVal = mystatus->GetAtMa();

	//回復量が最大HPより回復しないようにする
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
	{//hpが残っていたらfalseを返し、生き残っている判定にする
		if (objList[i]->GetHp() > 0)
			return false;
	}

	//全員のhpが0以下の時trueを返し、全員が死んでいる判定にする
	return true;
}

bool Battle::CheckEndBattle()
{
	int plSize = sizeof(playerSt) / sizeof(playerSt[0]);
	int enSize = sizeof(enemySt) / sizeof(enemySt[0]);

	if (CheckAllHPZero(playerSt, plSize))
	{//負け
		isBtlWin = false;
		return true;
	}
	else if (CheckAllHPZero(enemySt, enSize))
	{//勝ち
		isBtlWin = true;
		return true;
	}

	return false;
}

////値を交換する関数
//void Battle::swap(ObjOrder* a, ObjOrder* b) {
//
//	ObjOrder* acttemp = a;
//	a = b;
//	b = acttemp;
//}
//
///*クイックソート*/
//void Battle::QuickSort(ObjOrder A[], int left, int right)
//{
//	// 変数定義
//	int Left, Right;
//	int pivot;
//
//	// 初期値は引数から
//	Left = left; Right = right;
//
//	// 基準は真ん中に設定
//	pivot = A[(left + right) / 2].speed;
//
//	// ソーティング
//	while (1) {
//
//		// 基準より小さい値を左から見つけていく
//		while (A[Left].speed < pivot) Left++;
//
//		// 基準より大きい値を右から見つけていく
//		while (pivot < A[Right].speed) Right--;
//
//		// 見つかった値の順序が逆になったら終了 
//		if (Left >= Right) break;
//
//		// 値を交換
//		swap(&A[Left], &A[Right]);
//
//		// 次の値に移動
//		Left++; Right--;
//
//	}
//
//	//左のデータ群を対象としてクイックソートを再帰
//	if (left < Left - 1) QuickSort(A, left, Left - 1);
//
//	//右のデータ群を対象としてクイックソートを再帰
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
	int q;  // partition分割の基準となる要素のインデックス
	if (p < r) {
		q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}
