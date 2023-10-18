#include "resultScene.h"

resultScene::resultScene()
{
}

resultScene::~resultScene()
{
}

int resultScene::action()
{
	if (singlePush(KEY_INPUT_SPACE))
	{
		return SCENE_TITLE;
	}

	printf("ƒŠƒUƒ‹ƒg");
	return SCENE_RESULT;
}

void resultScene::draw()
{
	DrawCenterString(320, 64, "Result Score", GetColor(255, 0, 0));
}

void resultScene::init()
{
}

void resultScene::end()
{
}
