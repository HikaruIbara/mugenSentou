//DXlib�̃L�[�{�[�h���͊֘A
//�P�����A�������ςȂ��L�[�{�[�h�F��
#include "DXLib.h"

//��������Ă���̂��킩��ϐ�
char keyBuf[256];
//�O�̃t���[���ɉ�����Ă����̂����킩��ϐ�
char keyOldBuf[256];

int pushCount = 0;

//�L�[���͂̍X�V�@���t���[���Ăяo���Ă����K�v������
void keyUpDate()
{
	for (int i = 0; i < 256; i++)
	{
		keyOldBuf[i] = keyBuf[i];
	}
	GetHitKeyStateAll(keyBuf);
}

//�������ςȂ�
bool keyPush(int KeyNo)
{
	if (keyBuf[KeyNo] == 1)return true;
	return false;
}

//�P����
bool singlePush(int KeyNo)
{
	//�O�̃t���[���ɉ�����ĂȂ��āA���̃t���[���ɉ�����Ă���
	if (keyBuf[KeyNo] == 1 && keyOldBuf[KeyNo] == 0)return true;
	return false;
}

//������
bool keyPushUp(int KeyNo)
{
	//�O�̃t���[���ɉ�����Ă��āA���̃t���[���ɉ�����Ă��Ȃ�
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