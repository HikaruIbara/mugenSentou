//DXlibのキーボード入力関連
//単押し、押しっぱなしキーボード認識
#include "DXLib.h"

//今押されているのかわかる変数
char keyBuf[256];
//前のフレームに押されていたのかがわかる変数
char keyOldBuf[256];

int pushCount = 0;

//キー入力の更新　舞フレーム呼び出しておく必要がある
void keyUpDate()
{
	for (int i = 0; i < 256; i++)
	{
		keyOldBuf[i] = keyBuf[i];
	}
	GetHitKeyStateAll(keyBuf);
}

//押しっぱなし
bool keyPush(int KeyNo)
{
	if (keyBuf[KeyNo] == 1)return true;
	return false;
}

//単押し
bool singlePush(int KeyNo)
{
	//前のフレームに押されてなくて、今のフレームに押されている
	if (keyBuf[KeyNo] == 1 && keyOldBuf[KeyNo] == 0)return true;
	return false;
}

//離した
bool keyPushUp(int KeyNo)
{
	//前のフレームに押されていて、今のフレームに押されていない
	if (keyBuf[KeyNo] == 0 && keyOldBuf[KeyNo] == 1)return true;
	return false;
}

bool volumePush(int keyNo)
{
	if (keyPushUp(keyNo))
	{
		pushCount = 0;
		return false;
	}
	if (keyPush(keyNo))
	{

		if (pushCount >= 30)
		{
			return true;
		}
		else if (pushCount < 30)
		{
			pushCount++;
			return singlePush(keyNo);
		}


	}

	return false;
}

void nowKeyBuff(char skeyBuf[256])
{
	for (int i = 0; i < 256; i++)
	{
		skeyBuf[i] = keyBuf[i];
	}
}