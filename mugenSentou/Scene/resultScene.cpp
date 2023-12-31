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
		PlaySoundSE(SE_SELECT);
		return SCENE_TITLE;
	}

#ifdef MEMORY_LEAK
	return SCENE_TITLE;
#endif // MEMORY_LEAK

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
