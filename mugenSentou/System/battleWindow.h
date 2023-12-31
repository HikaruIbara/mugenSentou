#pragma once
#include "baseWindow.h"
#include "../enemyObject.h"
#include "../Sound/playSe.h"
using namespace MSL;

//�E�B���h�E�̎��
#define ENEMY_INFO		0
#define COMMAND			1
#define PLAYER_INFO		2

#define NONE 0
#define ATTACK 1
#define MAGICK 2
#define DEFENSE 3
#define RECOVER 4

const Select selectEne[] =
{
	{0,2,"�₭�����\n�₭�����\n"}
};

const Select selectAct[] =
{
	{ 0, 4, "��������\n�܂ق�\n�ڂ�����\n�A�C�e��\n"		},
	//{ 1, 2, "�����Ƃ�\n�邬\n"						},
	//{ 2, 4, "�t�@�C�A\n�A�N�A\n���[�t\n���J�o��\n"		},
	//{ 3, 1, "�ڂ�����\n"								},
	//{ 4, 1, "�A�C�e��\n"								},
	//{ 5, 3, "�Ȃ���\n����\n�J�E���^\n"}
};

class battleWindow {
public:
	battleWindow();
	~battleWindow();

	//�R�}���h��Ԃ�
	ReAction* action();
	void draw();
	void init(int enemyID[], int size);
	void start();
	void end();

	int GetRowNum() { return nowRowNum; }

private:
	AllSt allst;
	baseWindow* baseWin[4];
	int selectWin;
	int selectNum;
	int nowRowNum;
	int rowNum;
	bool selected;
	ReAction reAct;
	//void SetNowCursol(int nowCur) { nowRowNum = nowCur; };
};