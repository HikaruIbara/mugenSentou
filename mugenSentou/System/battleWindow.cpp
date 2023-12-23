#include "battleWindow.h"

battleWindow::battleWindow()
{
	for (int i = 0; i < 4; i++)
	{
		baseWin[i] = new baseWindow();
		baseWin[i]->SetCursol(true);
	}
	selectWin = 0;
	selectNum = -1;

	rowNum = 0;
	nowRowNum = 0;

	selected = false;
	reAct = 0;
}

battleWindow::~battleWindow()
{
	for (int i = 0; i < 4; i++)
	{
		delete baseWin[i];
	}

}

ReAction* battleWindow::action()
{
	if (singlePush(KEY_INPUT_UP))
	{
		baseWin[selectWin]->SetCursolUp();
		nowRowNum = baseWin[selectWin]->GetSelectNum();
	}
	if (singlePush(KEY_INPUT_DOWN))
	{
		baseWin[selectWin]->SetCursolDown();
		nowRowNum = baseWin[selectWin]->GetSelectNum();
	}

	if (singlePush(KEY_INPUT_Z))
	{
		int cmdSelNum = baseWin[selectWin]->GetSelect().num;
		int num;

		selectNum = baseWin[selectWin]->GetSelectNum();

		if (selectWin == 0)
		{
			reAct->tarEnemyNum = selectNum;

		}
		else if (selectWin == 1)
		{
			//todo: 
			switch (selectNum)
			{
			case ATTACK - 1:
				reAct->actPattern = ATTACK;
				break;
			case MAGICK - 1:
				reAct->actPattern = MAGICK;
				break;
			case DEFENSE - 1:
				reAct->actPattern = DEFENSE;
				break;
			case RECOVER - 1:
				reAct->actPattern = RECOVER;
				break;
			}
			selected = true;

		}
		num = selectNum;
		num = reAct->actPattern;

		if (selectWin == 0)
		{
			selectWin = 1;
			baseWin[1]->SetNowCursol(0);
			baseWin[1]->SetUse(true);
			baseWin[0]->SetUse(false);
		}
		else
		{
			selectWin = 0;
			baseWin[0]->SetNowCursol(0);
			baseWin[0]->SetUse(true);
			baseWin[1]->SetUse(false);

		}
	}
	if (singlePush(KEY_INPUT_X))
	{
		selectWin = 0;
		baseWin[0]->SetNowCursol(0);
		baseWin[0]->SetUse(true);
		baseWin[1]->SetUse(false);
	}

	baseWin[selectWin]->action();

	//動きがないため必要ないかも
	baseWin[PLAYER_INFO]->action();

	if (selected)
	{
		//ReAction* r = reAct;
		//delete reAct;
		//selected = false;
		//return r;
		return reAct;
	}
	else
		return nullptr;
}

void battleWindow::draw()
{

	baseWin[selectWin]->draw();

	//常に表示
	baseWin[PLAYER_INFO]->draw();
}

void battleWindow::init(int enemyID[], int size)
{
	Select selEne;
	std::string winString;

	//sprintf_s(filepath, "data/image/enemy/%s.png", allSt.GetEnName_EN(enemyID[i]).c_str());

	for (int i = 0; i < size; i++)
	{
		winString += allst.GetEnName_JP(enemyID[i]);
		winString += "\n";
	}
	selEne = { 0 ,size, winString };

	//ウィンドウの初期設定
	Rect rect = Rect{ 0, 336, 256, 144 };
	baseWin[ENEMY_INFO]->SetWindow(rect, true);
	baseWin[ENEMY_INFO]->SetSelect(selEne);
	baseWin[ENEMY_INFO]->SetCursol(true);


	rect = Rect{ 32, 336, 192, 144 };
	baseWin[COMMAND]->SetWindow(rect, false);
	baseWin[COMMAND]->SetSelect(selectAct[0]);
	baseWin[COMMAND]->SetCursol(true);

	rect = Rect{ 256, 336, 640 - 256, 480 - 336 };
	baseWin[PLAYER_INFO]->SetWindow(rect, true);
	baseWin[PLAYER_INFO]->SetCursol(false);

	selectWin = 0;
	selectNum = -1;
	rowNum = 0;
	nowRowNum = 0;
	selected = false;
	reAct = new ReAction();

}

void battleWindow::start()
{
	selectWin = 0;
	selectNum = -1;
	rowNum = 0;
	nowRowNum = 0;
	selected = false;
	reAct->actPattern = 0;
	reAct->tarEnemyNum = 0;
}

void battleWindow::end()
{
	if (reAct != nullptr)
		delete reAct;
}
