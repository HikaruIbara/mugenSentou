#include "DxLib.h"
#include "mikainoLib/mikainoLib.h"
#include "MSLib/MSLib.h"
#include "baseScene.h"
#include "sceneIist.h"

//�v���g�^�C�v
void init();	//�Q�[�����̂��̂̏�����
void action();	//�����@�L�[����
void draw();	//�`��
void end();

DebugLog debLog;

baseScene* baseSc[3];

#if 0
image* yukari;
image* ran;
Vector2 yukariPos(0,0);
Vector2 ranPos(0,0);
#endif

int sceneNo;
int oldSceneNo;

//������
void init()
{
	sceneNo = 0;

	baseSc[SCENE_TITLE] = new titleScene();
	baseSc[SCENE_BATTLE] = new battleScene();
	baseSc[SCENE_RESULT] = new resultScene();

#if  0
	yukari = new image("data/image/enemy/yukari.png");
	ran = new image("data/image/ran.png");
#endif //  0
}

//�Q�[�����̓���
void action()
{
	keyUpDate();

	sceneNo = baseSc[sceneNo]->action();
	if (sceneNo != oldSceneNo)
	{
		baseSc[sceneNo]->init();
	}

	oldSceneNo = sceneNo;

#if 0
	if (singlePush(KEY_INPUT_UP))
	{
		yukariPos.y -= 8;
		ranPos.y -= 8;
	}
	if (singlePush(KEY_INPUT_DOWN))
	{
		yukariPos.y += 8;
		ranPos.y += 8;
	}
	if (singlePush(KEY_INPUT_LEFT))
	{
		yukariPos.x -= 8;
		ranPos.x -= 8;
	}
	if (singlePush(KEY_INPUT_RIGHT))
	{
		yukariPos.x += 8;
		ranPos.x += 8;
	}

	printf("test");
#endif
}
//�Q�[�����̕`��
void draw()
{
	baseSc[sceneNo]->draw();

#if 0
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);
	//yukari->RotaImage(yukariPos.x, yukariPos.y, 2, 0);
	yukari->RotaImage(ranPos.x, ranPos.y, 2, 0);
#endif
}

void end()
{
	for (int i = 0; i < SCENE_MAX_COUNT; i++)
	{
		baseSc[i]->end();
	}
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//��ʃT�C�Y��ݒ�
	SetGraphMode(640, 480, 32);
	//�E�C���h�E�̃^�C�g���ύX
	//SetMainWindowText("dxlibTest");
	//�E�C���h�E���[�h�ύX
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	//�\���������_�u���o�b�t�@�����ɐ؂�ւ�
	//SetDrawScreen(DX_SCREEN_BACK);
	SetWindowStyleMode(10);

	//dxlib�̏�������ɃQ�[�������̏�����
	init();
	debLog.initDebugConsole();
	//�Q�[�����[�v
	while (ProcessMessage() == 0)
	{
		debLog.clearDebugConsole();
		action();
		//��ʂ̏�����
		ClearDrawScreen();
		draw();
		//�Ō�ɉ�ʓ]��
		ScreenFlip();
		//�G�X�P�[�v�{�^���������ƏI������
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;//�Q�[�����[�v���甲����
		}
	}
	end();
	debLog.endDebugConsole();
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}