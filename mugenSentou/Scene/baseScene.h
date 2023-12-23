#pragma once
#include "DxLib.h"
#include "../mikainoLib/mikainoLib.h"
#include <winuser.h>
#include <string>

#include "../mainDefine.h"

//�e�V�[���̃x�[�X�V�[��
class baseScene
{
public:
	baseScene();
	~baseScene();

	virtual int action() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
	virtual void end() = 0;

protected://�p���N���X�ł����Q�Ƃł��Ȃ�

	//�����̒�����
	void DrawCenterString(int x, int y, const char* str, int color);

};

