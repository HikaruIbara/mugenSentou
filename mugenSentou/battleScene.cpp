#include "battleScene.h"

battleScene::battleScene()
{
	for (int i = 0; i < PARTY_MAX; i++)
	{
		players[i] = new playerObject();
		players[i]->init();
		playersImg[i] = 0;
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemys[i] = new enemyObject();
		enemys[i]->init();
		enemysImg[i] = 0;
	}

	//�f�t�H���g�ʒu
	cursolPos = Vector2(48, 352);

	//setfontsize�Őݒ肷��t�H���g�̑傫��
	cmdFontSize = 32;
	cmdFontSpace = 8;

	infoFontSize = 24;
	infoFontSpace = 8;

	for (int i = 0; i < 4; i++)
	{
		cmdWindow[i] = new battleWindow();
	}
}

battleScene::~battleScene()
{
}

int battleScene::action()
{
	if (singlePush(KEY_INPUT_SPACE))
	{
		return SCENE_RESULT;
	}

	if (singlePush(KEY_INPUT_UP))
	{
		cursolPos.y -= 32;
		cursol.yNum++;
	}
	if (singlePush(KEY_INPUT_DOWN))
	{
		cursolPos.y += 32;
		cursol.yNum--;
	}

	if (cursol.yNum >= WINDOE_ITEM_NUM)
	{
		cursolPos.y -= 32;
		cursol.yNum = WINDOE_ITEM_NUM - 1;
	}
	if (cursol.yNum < 0)
	{
		cursolPos.y += 32;
		cursol.yNum = 0;
	}

	printf("�o�g��\n");
	printf("x: %f,y: %f\n", cursolPos.x, cursolPos.y);
	return SCENE_BATTLE;
}

void battleScene::draw()
{
	for (int i = 0; i < PARTY_MAX; i++)
	{
		players[i]->draw();
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemys[i]->draw();

	}

	uiDraw();
}

void battleScene::init()
{
	//�L�����N�^�[�C���[�W�̃��[�h
	int p_0 = LoadGraph("data/image/player/reimu.png");
	int e_0 = LoadGraph("data/image/enemy/ran.png");

	//�v���C���[�ƃG�l�~�[�̐ݒ�
	for (int i = 0; i < PARTY_MAX_MASTER; i++)
	{
		players[i] = new playerObject();
		playersImg[i] = p_0;
		players[i]->setMainImage(playersImg[i]);
		players[i]->init();

	}
	for (int i = 0; i < ENEMY_MAX_MASTER; i++)
	{
		enemys[i] = new enemyObject();
		enemysImg[i] = e_0;
		enemys[i]->setMainImage(enemysImg[i]);
		enemys[i]->init();

	}

	//��ʏ�̃L�����̕��ёւ�
	playerAlignment(PARTY_MAX_MASTER);
	enemyAlignment(ENEMY_MAX_MASTER);


	//�E�B���h�E�̐ݒ�
	Rect rect = Rect{ 0, 336, 256, 144 };
	cmdWindow[ENEMY_INFO]->SetWindow(rect, 6, GetColor(0, 0, 0), GetColor(0, 0, 255));

	rect = Rect{ 32, 336, 192, 144 };
	cmdWindow[COMMAND]->SetWindow(rect, 6, GetColor(0, 0, 0), GetColor(0, 0, 255));

	rect = Rect{ 256, 336, 640-256, 480-336 };
	cmdWindow[PLAYER_INFO]->SetWindow(rect, 6, GetColor(0, 0, 0), GetColor(0, 0, 255));


}

void battleScene::end()
{
}

void battleScene::playerAlignment(int num)
{
	if (num > PARTY_MAX)
		num = PARTY_MAX;

	if (num < 0)
		num = 0;

	//�����ʒu
	Vector2 setPos = Vector2(512, 256);

	int offset = 8;
	for (int i = 0; i < num; i++)
	{
		players[i]->setPostion(setPos);
		setPos.y -= players[i]->getH() + offset;
	}
}

void battleScene::enemyAlignment(int num)
{
	if (num > 2)
		num = 2;

#if 0
	if (num > ENEMY_MAX)
		num = ENEMY_MAX;
#endif

	if (num < 0)
		num = 0;

	//�����ʒu
	Vector2 setPos = Vector2(200, 80);
#if 0
	//�����ʒu
	Vector2 setPos = Vector2(64, 288);
#endif

	int offset = 8;
	Vector2 offsetVec = Vector2(-(enemys[0]->getW() / 4), enemys[0]->getH() / 4);
	for (int i = 0; i < num; i++)
	{
		enemys[i]->setPostion(setPos);
		setPos += offsetVec;
#if 0
		if (i == 4)
		{
			setPos.x += enemys[i]->getW() + offset;
			setPos.y += (enemys[i]->getH() + offset) * i - 1;
		}
		enemys[i]->setPostion(setPos);
		setPos.y -= enemys[i]->getH() + offset;

#endif
	}
}

void battleScene::drawHPBar(Vector2 pos, int len, int maxhp, int hp)
{
	int barHigh = 8;
	int hpLen = hp / maxhp;
	Vector2 posL = Vector2(pos.x, pos.y - barHigh);
	Vector2 posR = Vector2(pos.x + len, pos.y + barHigh);
	DrawBox(posL.x, posL.y, posR.x, posR.y, GetColor(127, 127, 127), TRUE);//underBar
	DrawBox(posL.x, posL.y, posR.x * hpLen, posR.y, GetColor(0, 255, 0), TRUE);//overBar
}

void battleScene::uiDraw()
{
	//�t�H���g�̑傫����ݒ�
	SetFontSize(cmdFontSize);


	//window
	//DrawFillBox(0, 336, 256, 480, GetColor(0, 0, 255));		//right
	//DrawFillBox(256, 336, 640, 480, GetColor(0, 0, 255));	//left
	cmdWindow[ENEMY_INFO]->drawWindow();
	cmdWindow[PLAYER_INFO]->drawWindow();


	//�G���
	DrawFormatString(32, 336 + cmdFontSpace, GetColor(255, 255, 255), "test");
	DrawFormatString(32, 336 + cmdFontSpace + cmdFontSize, GetColor(255, 255, 255), "test");


	//�R�}���h
	//DrawFillBox(32, 336, 256 - 32, 480, GetColor(255, 0, 255));//window
	cmdWindow[COMMAND]->drawWindow();
	for (int i = 0; i < 4; i++)
	{
		DrawFormatString(64, 336 + (cmdFontSize * i) + cmdFontSpace, GetColor(255, 255, 255), "��������");
	}


	//�v���C���[

	//�t�H���g�̑傫����ݒ�
	SetFontSize(infoFontSize);

	Status playerST = players[0]->getStatus();
	Vector2 hpBarPos = Vector2(256 + infoFontSpace, 336 + playerST.name.length() / 2 * cmdFontSize + infoFontSpace);
	drawHPBar(hpBarPos, 128, playerST.maxhp, playerST.hp);
	DrawFormatString(256 + infoFontSpace, 336 + infoFontSpace, GetColor(255, 255, 255), "%s HP:", playerST.name.c_str());
	DrawFormatString(256 + infoFontSpace, 336 + infoFontSize + infoFontSpace, GetColor(255, 255, 255), "ATTACK: %d DEFENSE: %d", playerST.at, playerST.de);
	DrawFormatString(256 + infoFontSpace, 336 + infoFontSize * 2 + infoFontSpace, GetColor(255, 255, 255), "MP: %d MPUP: %d", playerST.mp, playerST.mpup);
	DrawFormatString(256 + infoFontSpace, 336 + infoFontSize * 3 + infoFontSpace, GetColor(255, 255, 255), "LV: %d EXP: %d", playerST.lv, playerST.exp);

	//�J�[�\�� 48,352
	cursol.drawCursol(cursolPos, GetColor(255, 255, 255), TRUE);

}
