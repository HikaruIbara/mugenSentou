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
	status = new Status();

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
	h = (int)(mainImg->GetImgaeH());
	w = (int)(mainImg->GetImageW());

}

void baseObject::SetDeath()
{
	use = false;
}

void baseObject::setMainImage(int handle)
{
	mainImg = new image(handle);
	mainImg->GetImageSize();
}

void baseObject::deleteObj()
{
	//���W
	pos = pos.zero();
	//�T�C�Y
	w = 0, h = 0;
	//�A�N�e�B�u���ǂ���
	use = false;
	//�X�e�C�^�X
	status->SetStatus(0, 0);

	mainImg->DeleteImage();

	imgMag = 0;
}
