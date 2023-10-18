#include "DebugLog.h"


//*******************************************************
// �f�o�b�O�p�̃R���\�[���̏�������(���C�����[�v�O�ɌĂ�)
//*******************************************************
void DebugLog::initDebugConsole()
{
	debugInfo.debugConsoleDisplayFlg = TRUE;
	// �f�o�b�O�p�R���\�[����ʕ\���t���O���\�����Ȃ��ݒ�̏ꍇ�A�����I��
	if (debugInfo.debugConsoleDisplayFlg == FALSE)
	{
		return;
	}
	stream_0 = NULL;
	stream_1 = NULL;

	//�f�o�b�O�p�ɃR���\�[�����Ăяo��
	AllocConsole();
	err_0 = freopen_s(&stream_0, "CONOUT$", "w", stdout);
	err_1 = freopen_s(&stream_1, "CONIN$", "r", stdin);
	// �f�o�b�O�R���\�[�����A�N�e�B�u�E�B���h�E�ɂȂ�̂�
	// �Q�[���{�̂̃E�B���h�E���A�N�e�B�u�ɂ���
	SetForegroundWindow(GetMainWindowHandle());
}

//*******************************************************
// �f�o�b�O�p�̃R���\�[���̃N���A����
//*******************************************************
void DebugLog::clearDebugConsole()
{
	// �f�o�b�O�p�R���\�[����ʕ\���t���O���\�����Ȃ��ݒ�̏ꍇ�A�����I��
	if (debugInfo.debugConsoleDisplayFlg == FALSE)
	{
		return;
	}
	system("cls");
}

//*******************************************************
// �f�o�b�O�p�̃R���\�[���̏I������(���C�����[�v��ɌĂ�)
//*******************************************************
void DebugLog::endDebugConsole()
{
	// �f�o�b�O�p�R���\�[����ʕ\���t���O���\�����Ȃ��ݒ�̏ꍇ�A�����I��
	if (debugInfo.debugConsoleDisplayFlg == FALSE)
	{
		return;
	}
	fclose(stream_0);
	fclose(stream_1);
	//�R���\�[�����
	FreeConsole();
}