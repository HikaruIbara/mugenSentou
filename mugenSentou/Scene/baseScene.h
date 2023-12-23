#pragma once
#include "DxLib.h"
#include "../mikainoLib/mikainoLib.h"
#include <winuser.h>
#include <string>

#include "../mainDefine.h"

//各シーンのベースシーン
class baseScene
{
public:
	baseScene();
	~baseScene();

	virtual int action() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
	virtual void end() = 0;

protected://継承クラスでしか参照できない

	//文字の中央寄せ
	void DrawCenterString(int x, int y, const char* str, int color);

};

