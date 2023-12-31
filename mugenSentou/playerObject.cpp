#include "playerObject.h"

playerObject::playerObject()
{
}

playerObject::~playerObject()
{
}

void playerObject::action()
{
}

void playerObject::draw()
{
	mainImg->RotaImage((int)pos.x, (int)pos.y, imgMag, 0);
}

void playerObject::init()
{
	imgMag = PLAYER_MAG;
	mainImageSize();
	status.SetStatus(0,PLAYER);
	use = true;
	setID(101);

}

void playerObject::end()
{
}