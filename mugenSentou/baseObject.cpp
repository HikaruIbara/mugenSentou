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
