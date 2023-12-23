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

	//�����̒���
	strLen = (int)strlen(str);
	//�����̕�
	strWidth = GetDrawStringWidth(str, strLen);

	DrawString(x - strWidth / 2, y, str, color);

}
