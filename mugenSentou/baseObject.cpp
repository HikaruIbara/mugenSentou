#include "baseObject.h"

baseObject::baseObject()
{
	//���W
	pos = pos.zero();
	//�T�C�Y
	w = 0, h = 0;
	//�A�N�e�B�u���ǂ���
	use = false;
	//�X�e�C�^�X
	status = Status();

	mainImg = new image();

	imgMag = 0;
}

baseObject::~baseObject()
{
}

void baseObject::mainImageSize()
{
	h = -1;
	w = -1;
	h = mainImg->GetImgaeH() * imgMag;
	w = mainImg->GetImageW() * imgMag;
}
