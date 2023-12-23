#include "baseObject.h"

baseObject::baseObject()
{
	//座標
	pos = pos.zero();
	//サイズ
	w = 0, h = 0;
	//アクティブかどうか
	use = false;
	//ステイタス
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
	//座標
	pos = pos.zero();
	//サイズ
	w = 0, h = 0;
	//アクティブかどうか
	use = false;
	//ステイタス
	status->SetStatus(0, 0);

	mainImg->DeleteImage();

	imgMag = 0;
}
