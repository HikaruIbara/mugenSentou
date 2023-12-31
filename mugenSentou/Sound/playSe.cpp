#include <DxLib.h>
#include "playSe.h"

int lineCounter;
char stringBuf[FILENAME_MAX];
int filelistHandle;
int seHandles[SE_MAX];

void InitSe()
{
	lineCounter = 0;
	for (int i = 0; i < FILENAME_MAX; i++)
	{
		stringBuf[i] = 0;
	}
	for (int i = 0; i < SE_MAX; i++)
	{
		seHandles[i] = 0;
	}
	filelistHandle = 0;

}

void LoadSe()
{
	char filepath[2048];
	sprintf_s(filepath, "%s%s", SE_PATH, "filelist.list");
	//ファイルリストの読み込み
	filelistHandle = FileRead_open(filepath);
	while (FileRead_eof(filelistHandle) == 0 || lineCounter < SE_MAX)	// ファイルの終端に到達するかSEの上限に達するまでまでループ
	{
		char sefilepath[2046];
		// ファイルリストをもとにファイル名を取得する
		FileRead_gets(stringBuf, sizeof(stringBuf), filelistHandle);
		sprintf_s(sefilepath, "%s%s", SE_PATH, stringBuf);
		seHandles[lineCounter] = LoadSoundMem(sefilepath);

		lineCounter++;
	}
}

void DeleteSe()
{
	for (int i = 0; i < SE_MAX; i++)
	{
		if (seHandles[i] != 0 && seHandles[i] != -1)
			DeleteSoundMem(seHandles[i]);
	}
}

void PlaySe(int seNum)
{
	if (seNum < 0 || seNum >= SE_MAX)
		return;

	PlaySoundMem(seHandles[seNum], DX_PLAYTYPE_BACK);
}

void ChangeSEVol(int vol)
{
	int seVol = vol;
	if (seVol < 0)
		seVol = 0;
	if (seVol > 100)
		seVol = 100;

	for (int i = 0; i < SE_MAX; i++)
	{
		if (seHandles[i] != 0 && seHandles[i] != -1)
			ChangeVolumeSoundMem(255 * seVol / 100, seHandles[i]);
	}

}