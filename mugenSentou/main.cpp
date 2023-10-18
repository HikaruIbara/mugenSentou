#include "DxLib.h"
#include "mikainoLib/mikainoLib.h"
#include "MSLib/MSLib.h"
#include "baseScene.h"
#include "sceneIist.h"

//プロトタイプ
void init();	//ゲームそのものの初期化
void action();	//動き　キー操作
void draw();	//描画
void end();

DebugLog debLog;

baseScene* baseSc[3];

#if 0
image* yukari;
image* ran;
Vector2 yukariPos(0,0);
Vector2 ranPos(0,0);
#endif

int sceneNo;
int oldSceneNo;

//初期化
void init()
{
	sceneNo = 0;

	baseSc[SCENE_TITLE] = new titleScene();
	baseSc[SCENE_BATTLE] = new battleScene();
	baseSc[SCENE_RESULT] = new resultScene();

#if  0
	yukari = new image("data/image/enemy/yukari.png");
	ran = new image("data/image/ran.png");
#endif //  0
}

//ゲーム中の動作
void action()
{
	keyUpDate();

	sceneNo = baseSc[sceneNo]->action();
	if (sceneNo != oldSceneNo)
	{
		baseSc[sceneNo]->init();
	}

	oldSceneNo = sceneNo;

#if 0
	if (singlePush(KEY_INPUT_UP))
	{
		yukariPos.y -= 8;
		ranPos.y -= 8;
	}
	if (singlePush(KEY_INPUT_DOWN))
	{
		yukariPos.y += 8;
		ranPos.y += 8;
	}
	if (singlePush(KEY_INPUT_LEFT))
	{
		yukariPos.x -= 8;
		ranPos.x -= 8;
	}
	if (singlePush(KEY_INPUT_RIGHT))
	{
		yukariPos.x += 8;
		ranPos.x += 8;
	}

	printf("test");
#endif
}
//ゲーム中の描画
void draw()
{
	baseSc[sceneNo]->draw();

#if 0
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);
	//yukari->RotaImage(yukariPos.x, yukariPos.y, 2, 0);
	yukari->RotaImage(ranPos.x, ranPos.y, 2, 0);
#endif
}

void end()
{
	for (int i = 0; i < SCENE_MAX_COUNT; i++)
	{
		baseSc[i]->end();
	}
}

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//画面サイズを設定
	SetGraphMode(640, 480, 32);
	//ウインドウのタイトル変更
	//SetMainWindowText("dxlibTest");
	//ウインドウモード変更
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	//表示方式をダブルバッファ方式に切り替え
	//SetDrawScreen(DX_SCREEN_BACK);
	SetWindowStyleMode(10);

	//dxlibの初期化後にゲーム部分の初期化
	init();
	debLog.initDebugConsole();
	//ゲームループ
	while (ProcessMessage() == 0)
	{
		debLog.clearDebugConsole();
		action();
		//画面の初期化
		ClearDrawScreen();
		draw();
		//最後に画面転写
		ScreenFlip();
		//エスケープボタンを押すと終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;//ゲームループから抜ける
		}
	}
	end();
	debLog.endDebugConsole();
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}