#include "playerObject.h"

playerObject::playerObject()
{
	setDefaultStatus();
}

playerObject::~playerObject()
{
}

void playerObject::action()
{
}

void playerObject::draw()
{
	mainImg->RotaImage(pos.x, pos.y, imgMag, 0);
}

void playerObject::init()
{
	imgMag = PLAYER_MAG;
	mainImageSize();
}

void playerObject::end()
{
}

void playerObject::setDefaultStatus()
{
	status.name = "ƒvƒŒƒCƒ„[";
	status.maxhp = 20;
	status.at = 10;
	status.de = 5;
	status.exp = 0;
	status.hp = 20;
	status.lv = 1;
	status.mp = 10;
	status.mpup = 1;
}
