#include "DxLib.h"
#include "mikainoLib/mikainoLib.h"
#include "MSLib/MSLib.h"
#include "Scene/baseScene.h"
#include "Scene/sceneIist.h"
#include "Sound/soundController.h"

//�v���g�^�C�v
void init();	//�Q�[�����̂��̂̏�����
void action();	//�����@�L�[����
void draw();	//�`��
void end();

#ifndef RELEASE
DebugLog debLog;
#endif //RELEASE

baseScene* baseSc[3];

bool soundSettingFlag;

int sceneNo;
int oldSceneNo;

//������
void init()
{
	soundSettingFlag = false;
	InitSound();
	LoadSoundSE();
	LoadSoundBGM();

	// ********** �t�H���g�̃��[�h **********
	LPCSTR font_path = "data/font/DotGothic16-Regular.ttf"; // �ǂݍ��ރt�H���g�t�@�C���̃p�X
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}

	ChangeFont("Dotgothic16", DX_CHARSET_DEFAULT);

	sceneNo = 0;

	baseSc[SCENE_TITLE] = new titleScene();
	baseSc[SCENE_BATTLE] = new battleScene();
	baseSc[SCENE_RESULT] = new resultScene();

}

//�Q�[�����̓���
void action()
{
	keyUpDate();

	if (singlePush(KEY_INPUT_Q))
	{
		soundSettingFlag = !soundSettingFlag;
	}

	if (soundSettingFlag)
	{
		SoundAction();
		return;
	}

	sceneNo = baseSc[sceneNo]->action();
	if (sceneNo != oldSceneNo)
	{
		baseSc[sceneNo]->init();
	}

	oldSceneNo = sceneNo;

}
//�Q�[�����̕`��
void draw()
{
	baseSc[sceneNo]->draw();

	if (soundSettingFlag)
	{
		SoundDraw();
	}
}

void end()
{
	for (int i = 0; i < SCENE_MAX_COUNT; i++)
	{
		baseSc[i]->end();
	}
	DeleteSe();
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//��ʃT�C�Y��ݒ�
	SetGraphMode(640, 480, 32);
	//�E�C���h�E�̃^�C�g���ύX
	SetMainWindowText("�����퓬");
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

#ifndef RELEASE
	debLog.initDebugConsole();
#endif // RELEASE

	//�Q�[�����[�v
	while (ProcessMessage() == 0)
	{
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
#ifndef RELEASE
	debLog.endDebugConsole();
#endif // RELEASE
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}