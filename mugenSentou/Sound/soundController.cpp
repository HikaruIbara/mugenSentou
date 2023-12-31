#include <DxLib.h>
#include "../System/baseWindow.h"
#include "soundController.h"
#include "playSe.h"
#include "playBgm.h"


int seVol;
int bgmVol;
baseWindow win[2];
int selectNum;
bool selectFlag;

void InitSound()
{
	MSL::Rect winrect = { 176,16,447,63 };
	win[0].SetWindow(winrect, true);
	win[0].SetString("ƒTƒEƒ“ƒhÝ’è‰æ–Ê", DXLIB_COL_WHITE, 32);
	winrect = { 176,96,447,303 };
	win[1].SetWindow(winrect, true);
	win[1].SetString("SE   : 050\nBGM  : 050\n", DXLIB_COL_WHITE, 28);
	win[1].SetCursol(true);

	seVol = 50;
	bgmVol = 50;
	selectNum = 0;
	selectFlag = false;
	InitSe();
	InitBGM();
}

void SoundAction()
{
	if (singlePush(KEY_INPUT_UP) && selectFlag == false)
	{
		win[1].SetCursolUp();
		selectNum = win[1].GetSelectNum();
	}
	if (singlePush(KEY_INPUT_DOWN) && selectFlag == false)
	{
		win[1].SetCursolDown();
		selectNum = win[1].GetSelectNum();
	}

	if (singlePush(KEY_INPUT_Z) && selectFlag == false)
	{
		selectFlag = true;
	}
	if (singlePush(KEY_INPUT_X))
	{
		selectFlag = false;
	}

	if (volumePush(KEY_INPUT_UP) && selectFlag == true)
	{
		switch (selectNum)
		{
		case 0:
			seVol++;
			Clamp(&seVol);
			SetSEVolume(seVol);
			break;
		case 1:
			bgmVol++;
			Clamp(&bgmVol);
			SetBGMVolume(bgmVol);
			break;
		}
		char setString[2048];
		sprintf_s(setString, "SE   : %03d\nBGM  : %03d\n", seVol, bgmVol);
		win[1].SetString(setString, DXLIB_COL_WHITE, 28);

	}
	if (volumePush(KEY_INPUT_DOWN) && selectFlag == true)
	{
		switch (selectNum)
		{
		case 0:
			seVol--;
			Clamp(&seVol);
			SetSEVolume(seVol);
			break;
		case 1:
			bgmVol--;
			Clamp(&bgmVol);
			SetBGMVolume(bgmVol);
			break;
		}
		char setString[2048];
		sprintf_s(setString, "SE   : %03d\nBGM  : %03d\n", seVol, bgmVol);
		win[1].SetString(setString, DXLIB_COL_WHITE, 28);

	}

	win[0].action();
	win[1].action();
}

void SoundDraw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 127);
	DrawBox(0, 0, 640, 480, DXLIB_COL_BLACK, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,127);
	win[0].draw();
	win[1].draw();
#ifdef  DEBUG
	DrawFormatString(0, 0, DXLIB_COL_GREEN, "%d", selectNum);
#endif //  DEBUG
}

void LoadSoundSE()
{
#ifndef NOT_LOAD_SOUND
	LoadSe();
	SetSEVolume(seVol);
#endif // NOT_LOAD_SOUND
}

void LoadSoundBGM()
{
#ifndef NOT_LOAD_SOUND
	LoadBGM(0);
	SetBGMVolume(bgmVol);
#endif // NOT_LOAD_SOUND

}

void PlaySoundSE(int seNum)
{
	PlaySe(seNum);
}

void PlaySoundBGM(int bgmNum)
{
	PlayBGM(bgmNum);
}

void StopSoundBGM(int bgmNum)
{
	StopBGM(bgmNum);
}

void SetSEVolume(int vol)
{
	seVol = vol;
	ChangeSEVol(seVol);
}

void SetBGMVolume(int vol)
{
	bgmVol = vol;
	ChangeBGMVol(bgmVol);
}

int GetSEVolume()
{
	return seVol;
}

int GetBGMVolume()
{
	return bgmVol;
}

void Clamp(int* vol)
{
	if (*vol > 100)
		*vol = 100;
	if (*vol < 0)
		*vol = 0;

}