#include <DxLib.h>
#include "playBgm.h"

int bgmLineCounter;
char bgmStringBuf[FILENAME_MAX];
int bgmFilelistHandle;
int bgmHandles[BGM_MAX];

void InitBGM()
{
	bgmLineCounter = 0;
	for (int i = 0; i < FILENAME_MAX; i++)
	{
		bgmStringBuf[i] = 0;
	}
	for (int i = 0; i < BGM_MAX; i++)
	{
		bgmHandles[i] = 0;
	}
	bgmFilelistHandle = 0;
}

void LoadBGM(int bgmNum)
{
	if (bgmNum < 0 || bgmNum >= BGM_MAX)
		return;

	char filepath[2048];
	sprintf_s(filepath, "%s%s", BGM_PATH, "filelist.list");
	//ファイルリストの読み込み
	bgmFilelistHandle = FileRead_open(filepath);
	while (FileRead_eof(bgmFilelistHandle) == 0 || bgmLineCounter < BGM_MAX)	// ファイルの終端に到達するかSEの上限に達するまでまでループ
	{
		char sefilepath[2046];
		// ファイルリストをもとにファイル名を取得する
		FileRead_gets(bgmStringBuf, sizeof(bgmStringBuf), bgmFilelistHandle);
		if (bgmLineCounter == bgmNum)
		{
			sprintf_s(sefilepath, "%s%s", BGM_PATH, bgmStringBuf);
			bgmHandles[bgmLineCounter] = LoadSoundMem(sefilepath);
		}
		bgmLineCounter++;
	}
}

void DeleteBGM()
{
	for (int i = 0; i < BGM_MAX; i++)
	{
		if (bgmHandles[i] != 0 && bgmHandles[i] != -1)
			DeleteSoundMem(bgmHandles[i]);
	}
}

void PlayBGM(int bgmNum)
{
	if (bgmNum < 0 || bgmNum >= BGM_MAX)
		return;
	if (CheckSoundMem(bgmHandles[bgmNum]) == 0)
	{
		PlaySoundMem(bgmHandles[bgmNum], DX_PLAYTYPE_BACK);
	}
}

void StopBGM(int bgmNum)
{
	if (bgmNum < 0 || bgmNum >= BGM_MAX)
		return;
	if (CheckSoundMem(bgmHandles[bgmNum]) == 1)
	{
		StopSoundMem(bgmHandles[bgmNum]);
	}
}

void ChangeBGMVol(int vol)
{
	int bgmVol = vol;
	if (bgmVol < 0)
		bgmVol = 0;
	if (bgmVol > 100)
		bgmVol = 100;

	ChangeVolumeSoundMem(255 * bgmVol / 100, bgmHandles[0]);

}
