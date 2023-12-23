#include "enemyObject.h"

enemyObject::enemyObject()
{
}

enemyObject::~enemyObject()
{
}

void enemyObject::action()
{
}

void enemyObject::draw()
{
	if (!use)
		return;

	mainImg->RotaImage((int)pos.x, (int)pos.y, imgMag, 0, ANCHOR_BOTTOM | ANCHOR_XCENTER);
}

void enemyObject::init()
{
	imgMag = ENEMY_MAG;
	mainImageSize();
	status->SetStatus(0, ENEMY);
	use = false;
	status->SetActID(1);
	status->SetTarID(1);
}

void enemyObject::end()
{
}

void enemyObject::HpBardraw()
{
	if (!use)
		return;

	int len = 100;//バー全体の長さ
	int hp = status->GetHp();
	int maxhp = status->GetHpMax();
	int barHigh = 4;
	double hpLen = (double)hp / (double)maxhp;//HP残量の表示長さ
	if (hp < 0)
		hp = 0;

	Vector2 posL = Vector2(pos.x - (w * imgMag) / 2, pos.y - h * imgMag - barHigh);//左上の設定
	Vector2 posR = Vector2(pos.x - (w * imgMag) / 2 + len, pos.y - h * imgMag + barHigh);//右下の設定
	//バー全体を描画
	DrawBox((int)posL.x, (int)posL.y, (int)posR.x, (int)posR.y, DXLIB_COL_GRAY, TRUE);

	if (hpLen >= 0)
	{//HP残量に合わせて長さを調整する
		posR.x = (float)(pos.x - (w * imgMag) / 2 + (len * hpLen));
	}

	//HP残量の表示を描画
	DrawBox((int)posL.x, (int)posL.y, (int)posR.x, (int)posR.y, DXLIB_COL_GREEN, TRUE);
}