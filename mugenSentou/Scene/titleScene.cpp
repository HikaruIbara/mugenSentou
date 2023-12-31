#include "titleScene.h"

titleScene::titleScene()
{
	bgmVol = 50;
};

titleScene::~titleScene()
{
}

int titleScene::action()
{
	if (singlePush(KEY_INPUT_SPACE)|| singlePush(KEY_INPUT_Z))
	{
		PlaySoundSE(SE_SELECT);
		return SCENE_BATTLE;
	}

	if (singlePush(KEY_INPUT_UP))
	{
		bgmVol += 2;
		PlaySoundBGM(bgmVol);
	}
	if (singlePush(KEY_INPUT_DOWN))
	{
		bgmVol -= 2;
		PlaySoundBGM(bgmVol);
	}
	PlaySoundBGM(0);

	if (singlePush(KEY_INPUT_S))
	{
		StopSoundBGM(0);
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
