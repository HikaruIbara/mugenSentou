#include "battleScene.h"
# define M_PI 3.14159265358979323846 /* pi */
#define g 9.80665

battleScene::battleScene()
{
	waveCount = 0;

	battle = new Battle();
	stInfo = StatusSetInfo();
	enemyCount = 0;
	enemyID = 0;
	for (int i = 0; i < PARTY_MAX; i++)
	{
		playerNum[i] = -1;
		players[i] = new playerObject();
		players[i]->init();
		playersImg[i] = 0;
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemyNum[i] = -1;
		enemys[i] = new enemyObject();
		enemys[i]->init();
		enemysImg[i] = 0;
	}

	//setfontsizeで設定するフォントの大きさ
	cmdFontSize = 32;
	cmdFontSpace = 8;
	selCount = 0;

	infoFontSize = 24;
	infoFontSpace = 8;

	UIwin = new battleWindow();
	actPattern = 0;

#ifdef DEBUG
	backImage = LoadGraph("data/image/backImage.png");
#endif // DEBUG


}

battleScene::~battleScene()
{
	//delete battle;
	//for (int i = 0; i < PARTY_MAX; i++)
	//{
	//	delete players[i];
	//}
	//for (int i = 0; i < ENEMY_MAX; i++)
	//{
	//	delete enemys[i];
	//}
	//delete UIwin;
}

int battleScene::action()
{
#ifdef DEBUG
	if (keyPush(KEY_INPUT_E) && keyPush(KEY_INPUT_T))
	{//強制終了
		PlaySe(SE_SELECT);
		end();
		return SCENE_RESULT;
	}
#endif // DEBUG

	//if (singlePush(KEY_INPUT_SPACE))
	//{
	//	return SCENE_RESULT;
	//}

	//if (singlePush(KEY_INPUT_A))
	//{
	//	battle->AddDamage(players[0]->getStatus(), enemys[0]->getStatus());
	//}

	//window
	ReAction* actPattern = UIwin->action();
	if (actPattern != nullptr)
	{
		//
		battle->SetAct(*actPattern);
		//actPattern = nullptr;
		UIwin->start();
	}

	if (battle->ActionBattle())
	{

	}
	else
	{
		end();
		return SCENE_RESULT;

	}

#ifdef MEMORY_LEAK
	end();
	return SCENE_RESULT;
#endif // MEMORY_LEAK

	return SCENE_BATTLE;
}

void battleScene::draw()
{
#ifdef DEBUG
	DrawGraph(0, 0, backImage, TRUE);
#endif // DEBUG

	for (int i = 0; i < PARTY_MAX; i++)
	{
		players[i]->draw();
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (i == UIwin->GetRowNum())
		{//選択中の敵を半透明に表示する
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 256 - selCount);
			enemys[i]->draw();
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			selCount += 5;
			if (selCount > 128)
				selCount = 0;
		}
		else
		{
			enemys[i]->draw();

		}

	}

	uiDraw();

}

void battleScene::init()
{
	if (waveCount == 0)
	{
		//キャラクターイメージのロード
		int p_0 = LoadGraph("data/image/player/reimu_ff.png");
		//プレイヤーの設定
		for (int i = 0; i < PARTY_MAX_MASTER; i++)
		{
			playersImg[i] = p_0;
			players[i]->setMainImage(playersImg[i]);
			players[i]->init();

		}
		players[0]->init();
		players[0]->setStatus(reimu, PLAYER);

	}
	else
	{
		players[0]->getStatus()->AddHp(10);
		players[0]->getStatus()->AddAt(5);
	}

	stInfo.playerSt = players[0]->getStatus();
	stInfo.trun = 5;
	stInfo.wave = waveCount;
	//敵の設定
	enemyID = autoEnSet.SetEnemy(enemys, &stInfo);
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemys[i]->getUse())
			enemyCount++;
	}

	//画面上のキャラの並び替え
	playerAlignment(PARTY_MAX_MASTER);
	enemyAlignment(enemyCount);

	//ウィンドウの設定
	UIwin->init(enemyID, enemyCount);


	//Battleクラスの初期設定
	Status* party[PARTY_MAX];
	Status* enemy[ENEMY_MAX];

	for (int i = 0; i < PARTY_MAX; i++)
	{
		party[i] = players[i]->getStatus();
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i] = enemys[i]->getStatus();
	}
	battle->StratBattle(party, enemy);
	waveCount++;

}

void battleScene::end()
{
	enemyCount = 0;
	UIwin->end();
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemys[i]->deleteObj();
	}
}

void battleScene::playerAlignment(int num)
{
	if (num > PARTY_MAX)
		num = PARTY_MAX;

	if (num < 0)
		num = 0;

	//初期位置
	Vector2 setPos = Vector2(512, 256);

	int offset = 8;
	for (int i = 0; i < num; i++)
	{
		players[i]->setPostion(setPos);
		setPos.y -= (float)(players[i]->getH() + offset);
	}
}

void battleScene::enemyAlignment(int num)
{
	if (num > ENEMY_MAX)
		num = ENEMY_MAX;

	if (num < 0)
		num = 0;

	//初期位置
	Vector2 setPos = Vector2(64, 240 + 64);
	//Vector2 setPos = Vector2(64,256-32);
	int Xoffset = 96;
	int Yoffset = 64;
	for (int i = 0; i < num; i++)
	{
		enemys[i]->setPostion(setPos);
		if (i == 0)
		{
			setPos.x += Xoffset;
			setPos.y -= Yoffset;

		}
		else if (i == 1)
		{
			setPos.x += Xoffset / 2;
			setPos.y += Yoffset;
		}
		else if (i == 2)
		{
			setPos.x += Xoffset;
			setPos.y -= Yoffset;
		}
	}


	//	int offset = 8;
	//	Vector2 offsetVec = Vector2(-(float)(enemys[0]->getW()), (float)(enemys[0]->getH() / 2));
	//	for (int i = 0; i < num; i++)
	//	{
	//		enemys[i]->setPostion(setPos);
	//		setPos += offsetVec;
	//		if (i >= 2)
	//		{
	//			setPos.x += (float)enemys[i]->getW() + offset;
	//			setPos.y += (float)(enemys[i]->getH() + offset) * i - 1;
	//		}
	//		enemys[i]->setPostion(setPos);
	//		setPos.y -= enemys[i]->getH() + offset;
	//
	//	}
}

void battleScene::drawHPBar(Vector2 pos, int len, int maxhp, int hp)
{
	if (hp < 0)
		hp = 0;
	int barHigh = 4;
	double hpLen = (double)hp / (double)maxhp;

	Vector2 posL = Vector2(pos.x, pos.y - barHigh);
	Vector2 posR = Vector2(pos.x + len, pos.y + barHigh);
	DrawBox((int)posL.x, (int)posL.y, (int)posR.x, (int)posR.y, DXLIB_COL_GRAY, TRUE);//underBar

	if (hpLen >= 0)
	{
		posR.x = (float)(pos.x + len * hpLen);

	}

	DrawBox((int)posL.x, (int)posL.y, (int)posR.x, (int)posR.y, DXLIB_COL_GREEN, TRUE);//overBar

}

void battleScene::uiDraw()
{
	//フォントの大きさを設定
	SetFontSize(cmdFontSize);

	//window
	UIwin->draw();

	//プレイヤー
	//フォントの大きさを設定
	SetFontSize(infoFontSize);

	Status* playerST = players[0]->getStatus();
	Vector2 hpBarPos = Vector2((float)(256 + (playerST->GetName().length() + 4) / 2 * cmdFontSize + infoFontSpace),
		(float)(336 + infoFontSize / 2 + infoFontSpace));
	drawHPBar(hpBarPos, 128, playerST->GetHpMax(), playerST->GetHp());
	DrawFormatString(256 + infoFontSpace, 336 + infoFontSpace, GetColor(255, 255, 255), "%s HP:", playerST->GetName().c_str());
	DrawFormatString(256 + infoFontSpace, 336 + infoFontSize + infoFontSpace, GetColor(255, 255, 255), "ATTACK: %d DEFENSE: %d", playerST->GetAt(), playerST->GetDe());
	DrawFormatString(256 + infoFontSpace, 336 + infoFontSize * 2 + infoFontSpace, GetColor(255, 255, 255), "MP: %d MPUP: %d", playerST->GetMp(), playerST->GetMpUp());
	DrawFormatString(256 + infoFontSpace, 336 + infoFontSize * 3 + infoFontSpace, GetColor(255, 255, 255), "LV: %d EXP: %d", playerST->GetLv(), playerST->GetExp());


	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemys[i]->HpBardraw();
	}

#ifdef DEBUG
	DrawFormatString(640 - infoFontSize / 2 * 8 - 6, 0, DXLIB_COL_GREEN, "%03d WAVE", waveCount);
	DrawFormatString(0, 0, DXLIB_COL_GREEN, "NOWTURN: %d", battle->GetNowTurn());
#endif // DEBUG
}
