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

	//�o�g���̊J�n
	void StratBattle(Status* pl[PARTY_MAX], Status* en[ENEMY_MAX]);
	//���C�����[�v
	bool ActionBattle();
	//�`��
	void DrawBattle();

	//���݂̃^�[����
	int GetNowTurn();
	//�G�̑I��
	void TargetEnemy(int tarEnemy);
	//�s���p�^�[���̐ݒ�
	void SelectCmd(int cmd);
	//�R�}���h����̖߂�l
	void SetAct(ReAction act);
	//�^�[���J�n�̃t���O����
	void SetTurnStart();
private:
	//�o�g���̏�����
	void InitBattle();
	//�^�[���J�n����
	void TurnStrat();
	//�^�[���I������
	void TurnEnd();

	//�G�̎����ݒ�
	void AutoEnemySet();

	//�G�������̐����m�F
	//�S��������ł���Ȃ�true���Ԃ��Ă���
	bool CheckAllHPZero(Status* objList[], int size);
	//�o�g���̏��s�`�F�b�N
	bool CheckEndBattle();
	//�o�g���̏I������	
	bool EndBattle();


	void ObjAction();
	//�S���̍s���������߂�
	void GetObjOrder();

	/////////////////////
	//�s���p�^�[���̊֐�
	/////////////////////

	//�����U���̌v�Z
	bool Attack(Status* attack, Status* dameged);
	//���@�U���̌v�Z
	bool Magick(Status* attack, Status* dameged);
	//�h��̌v�Z
	bool Defense(Status* myStatus);
	//�񕜂̌v�Z
	bool Recover(Status* myStatus);


	//void swap(ObjOrder* a, ObjOrder* b);
	//void QuickSort(ObjOrder A[], int left, int right);
	int partition(ObjOrder A[], int p, int r);
	void quick_sort(ObjOrder A[], int p, int r);


	/////////////////////////////
	//field��̃I�u�W�F�N�g�X�e�C�^�X
	/////////////////////////////

	Status* playerSt[PARTY_MAX];	//�����̃X�e�C�^�X�z��
	Status* enemySt[ENEMY_MAX];		//�G�̃X�e�C�^�X�z��


	//�o�g����
	bool isBtl;

	//�^�[����
	int TurnCount;
	bool isTurnSart;
	bool isTurnEnd;

	bool isMyTurn;			//true�Ȃ玩���̃^�[���Afalse�Ȃ瑊��̃^�[��
	bool isBtlWin;			//���s�t���O

	int tarEnemyNum;		//�G�I��ԍ�
	int actPattern;			//�s���p�^�[��
	ObjOrder actOrder[OBJ_MAX];	//�s����
};

