#pragma once
#include "DxLib.h"
#include "../mikainoLib/mikainoLib.h"
#include "../MSLib/MSLib.h"
#include "DxLib.h"
#include <math.h>
#include <winuser.h>
#include <string>

#include "../mainDefine.h"

namespace MSL
{
	struct Rect
	{
		int x;
		int y;
		int w;
		int h;
	};

	struct Cursol
	{
		bool isCursol = false;
		Vector2 pos_1 = Vector2(0, 0);
		Vector2 pos_2 = Vector2(0, 16);
		Vector2 pos_3 = Vector2(16, 8);

		Vector2 oldPos = Vector2(0, 0);

		int yNum = 0;

		void moveCoursol(Vector2 pos)
		{
			pos_1 -= oldPos;
			pos_2 -= oldPos;
			pos_3 -= oldPos;

			pos_1 += pos;
			pos_2 += pos;
			pos_3 += pos;

			oldPos = pos;
		}

		void drawCursol(Vector2 pos, int color, bool fillFlag)
		{
			moveCoursol(pos);

			DrawTriangle((int)pos_1.x, (int)pos_1.y,
				(int)pos_2.x, (int)pos_2.y,
				(int)pos_3.x, (int)pos_3.y,
				color, fillFlag);
		}

		int GetCursolSize_x()
		{
			return (int)(pos_3.x - pos_1.x);
		}
		int GetCursolSize_y()
		{
			return (int)(pos_2.y - pos_1.y);
		}
	};

	struct Select
	{
		int num;
		int kindNum;
		std::string str;
	};

	struct ReAction
	{
		int tarEnemyNum;
		int actPattern;
	};
}

class baseWindow
{
public:
	baseWindow();
	~baseWindow();

	void action();
	void draw();
	void init();
	void end();


protected:

	bool use;
	//座標と大きさ
	MSL::Rect winSize;

	int edgeThick;
	int edgeColor;
	int mainColor;

	int fontSpace_x;
	int fontSpace_y;
	int fontSize;
	int fontColor;
	std::string mainStr;

	MSL::Cursol cursol;

	//カーソル 48,352
	Vector2 cursolPos;
	int rowNum;
	int nowRowNum;
	MSL::Select nowSelect;

	void GetCoursolPos();


public:

	void SetWindow(MSL::Rect rect, bool use = false, int edgeThick = 4, int edgeColor = INT32_MAX, int mainColor = GetColor(0, 0, 255));
	void drawWindow();
	void SetNowCursol(int nowCur) { nowRowNum = nowCur; };

	//セッター
	void SetPostion(int x, int y) { winSize.x = x; winSize.y = y; };
	void SetString(std::string str, int color = 0xffffff, int fontSize = 30, int spaceX = 40, int spaceY = 8);
	void SetSelect(MSL::Select select, int color = 0xffffff, int fontSize = 30, int spaceX = 40, int spaceY = 8);
	void SetCursol(bool use) { cursol.isCursol = use; };
	void SetCursolUp();
	void SetCursolDown();
	void SetUse(bool hUse) { use = hUse; };

	//ゲッター
	MSL::Rect GetWindowPostion() { return winSize; };
	int GetSelectNum();
	MSL::Select GetSelect() { return nowSelect; };
};

