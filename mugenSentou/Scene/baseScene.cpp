#include "baseScene.h"

baseScene::baseScene()
{
}

baseScene::~baseScene()
{
}

void baseScene::DrawCenterString(int x, int y, const char* str, int color)
{
	int strWidth, strLen;

	//文字の長さ
	strLen = (int)strlen(str);
	//文字の幅
	strWidth = GetDrawStringWidth(str, strLen);

	DrawString(x - strWidth / 2, y, str, color);

}
