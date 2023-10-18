#include "enemyObject.h"

enemyObject::enemyObject()
{
	setDefaultStatus();
}

enemyObject::~enemyObject()
{
}

void enemyObject::action()
{
}

void enemyObject::draw()
{
	mainImg->RotaImage(pos.x, pos.y, imgMag, 0);
}

void enemyObject::init()
{
	imgMag = ENEMY_MAG;
	mainImageSize();
}

void enemyObject::end()
{
}

void enemyObject::setDefaultStatus()
{
	status.name = "エネミー";
	status.maxhp = 10;
	status.at = 10;
	status.de = 5;
	status.exp = 0;
	status.hp = 20;
	status.lv = 1;
	status.mp = 10;
	status.mpup = 1;
}
