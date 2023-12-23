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

	int len = 100;//�o�[�S�̂̒���
	int hp = status->GetHp();
	int maxhp = status->GetHpMax();
	int barHigh = 4;
	double hpLen = (double)hp / (double)maxhp;//HP�c�ʂ̕\������
	if (hp < 0)
		hp = 0;

	Vector2 posL = Vector2(pos.x - (w * imgMag) / 2, pos.y - h * imgMag - barHigh);//����̐ݒ�
	Vector2 posR = Vector2(pos.x - (w * imgMag) / 2 + len, pos.y - h * imgMag + barHigh);//�E���̐ݒ�
	//�o�[�S�̂�`��
	DrawBox((int)posL.x, (int)posL.y, (int)posR.x, (int)posR.y, DXLIB_COL_GRAY, TRUE);

	if (hpLen >= 0)
	{//HP�c�ʂɍ��킹�Ē����𒲐�����
		posR.x = (float)(pos.x - (w * imgMag) / 2 + (len * hpLen));
	}

	//HP�c�ʂ̕\����`��
	DrawBox((int)posL.x, (int)posL.y, (int)posR.x, (int)posR.y, DXLIB_COL_GREEN, TRUE);
}