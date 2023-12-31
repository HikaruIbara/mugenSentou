#include "DxLib.h"
#include "mikainoLib/mikainoLib.h"
#include "MSLib/MSLib.h"
#include "Scene/baseScene.h"
#include "Scene/sceneIist.h"
#include "Sound/soundController.h"

//プロトタイプ
void init();	//ゲームそのものの初期化
void action();	//動き　キー操作
void draw();	//描画
void end();

#ifndef RELEASE
DebugLog debLog;
#endif //RELEASE

baseScene* baseSc[3];

bool soundSettingFlag;

int sceneNo;
int oldSceneNo;

//初期化
void init()
{
	soundSettingFlag = false;
	InitSound();
	LoadSoundSE();
	LoadSoundBGM();

	// ********** フォントのロード **********
	LPCSTR font_path = "data/font/DotGothic16-Regular.ttf"; // 読み込むフォントファイルのパス
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}

	ChangeFont("Dotgothic16", DX_CHARSET_DEFAULT);

	sceneNo = 0;

	baseSc[SCENE_TITLE] = new titleScene();
	baseSc[SCENE_BATTLE] = new battleScene();
	baseSc[SCENE_RESULT] = new resultScene();

}

//ゲーム中の動作
void action()
{
	keyUpDate();

	if (singlePush(KEY_INPUT_Q))
	{
		soundSettingFlag = !soundSettingFlag;
	}

	if (soundSettingFlag)
	{
		SoundAction();
		return;
	}

	sceneNo = baseSc[sceneNo]->action();
	if (sceneNo != oldSceneNo)
	{
		baseSc[sceneNo]->init();
	}

	oldSceneNo = sceneNo;

}
//ゲーム中の描画
void draw()
{
	baseSc[sceneNo]->draw();

	if (soundSettingFlag)
	{
		SoundDraw();
	}
}

void end()
{
	for (int i = 0; i < SCENE_MAX_COUNT; i++)
	{
		baseSc[i]->end();
	}
	DeleteSe();
}

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//画面サイズを設定
	SetGraphMode(640, 480, 32);
	//ウインドウのタイトル変更
	SetMainWindowText("無限戦闘");
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

#ifndef RELEASE
	debLog.initDebugConsole();
#endif // RELEASE

	//ゲームループ
	while (ProcessMessage() == 0)
	{
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
#ifndef RELEASE
	debLog.endDebugConsole();
#endif // RELEASE
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}