#pragma once
#include "../mikainoLib/mikainoLib.h"
#include "../baseObject.h"
#include "../System/battleWindow.h"

struct ObjOrder
{
	int id;
	int speed;
};

class Battle
{
public:
	Battle();
	~Battle();

	//バトルの開始
	void StratBattle(Status* pl[PARTY_MAX], Status* en[ENEMY_MAX]);
	//メインループ
	bool ActionBattle();
	//描画
	void DrawBattle();

	//現在のターン数
	int GetNowTurn();
	//敵の選択
	void TargetEnemy(int tarEnemy);
	//行動パターンの設定
	void SelectCmd(int cmd);
	//コマンドからの戻り値
	void SetAct(ReAction act);
	//ターン開始のフラグ建て
	void SetTurnStart();
private:
	//バトルの初期化
	void InitBattle();
	//ターン開始処理
	void TurnStrat();
	//ターン終了処理
	void TurnEnd();

	//敵の自動設定
	void AutoEnemySet();

	//敵か味方の生存確認
	//全員が死んでいるならtrueが返ってくる
	bool CheckAllHPZero(Status* objList[], int size);
	//バトルの勝敗チェック
	bool CheckEndBattle();
	//バトルの終了処理	
	bool EndBattle();


	void ObjAction();
	//全員の行動順を決める
	void GetObjOrder();

	/////////////////////
	//行動パターンの関数
	/////////////////////

	//物理攻撃の計算
	bool Attack(Status* attack, Status* dameged);
	//魔法攻撃の計算
	bool Magick(Status* attack, Status* dameged);
	//防御の計算
	bool Defense(Status* myStatus);
	//回復の計算
	bool Recover(Status* myStatus);


	//void swap(ObjOrder* a, ObjOrder* b);
	//void QuickSort(ObjOrder A[], int left, int right);
	int partition(ObjOrder A[], int p, int r);
	void quick_sort(ObjOrder A[], int p, int r);


	/////////////////////////////
	//field上のオブジェクトステイタス
	/////////////////////////////

	Status* playerSt[PARTY_MAX];	//味方のステイタス配列
	Status* enemySt[ENEMY_MAX];		//敵のステイタス配列


	//バトル中
	bool isBtl;

	//ターン数
	int TurnCount;
	bool isTurnSart;
	bool isTurnEnd;

	bool isMyTurn;			//trueなら自分のターン、falseなら相手のターン
	bool isBtlWin;			//勝敗フラグ

	int tarEnemyNum;		//敵選択番号
	int actPattern;			//行動パターン
	ObjOrder actOrder[OBJ_MAX];	//行動順
};

