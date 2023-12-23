#include "titleScene.h"

titleScene::titleScene()
{
};

titleScene::~titleScene()
{
}

int titleScene::action()
{
	if (singlePush(KEY_INPUT_SPACE))
	{
		return SCENE_BATTLE;
	}

#ifdef MEMORY_LEAK
	return SCENE_BATTLE;
#endif // MEMORY_LEAK

	return SCENE_TITLE;
}

void titleScene::draw()
{
	SetFontSize(96);
	DrawCenterString(320, 64, "ñ≥å¿êÌì¨", GetColor(255, 0, 0));
	SetFontSize(64);
	DrawCenterString(320, 320, "SPACE PUSH", GetColor(255, 0, 0));
}

void titleScene::init()
{
}

void titleScene::end()
{
}
