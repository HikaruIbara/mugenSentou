#include "DebugLog.h"


//*******************************************************
// デバッグ用のコンソールの初期処理(メインループ前に呼ぶ)
//*******************************************************
void DebugLog::initDebugConsole()
{
	debugInfo.debugConsoleDisplayFlg = TRUE;
	// デバッグ用コンソール画面表示フラグが表示しない設定の場合、処理終了
	if (debugInfo.debugConsoleDisplayFlg == FALSE)
	{
		return;
	}
	stream_0 = NULL;
	stream_1 = NULL;

	//デバッグ用にコンソールを呼び出す
	AllocConsole();
	err_0 = freopen_s(&stream_0, "CONOUT$", "w", stdout);
	err_1 = freopen_s(&stream_1, "CONIN$", "r", stdin);
	// デバッグコンソールがアクティブウィンドウになるので
	// ゲーム本体のウィンドウをアクティブにする
	SetForegroundWindow(GetMainWindowHandle());
}

//*******************************************************
// デバッグ用のコンソールのクリア処理
//*******************************************************
void DebugLog::clearDebugConsole()
{
	// デバッグ用コンソール画面表示フラグが表示しない設定の場合、処理終了
	if (debugInfo.debugConsoleDisplayFlg == FALSE)
	{
		return;
	}
	system("cls");
}

//*******************************************************
// デバッグ用のコンソールの終了処理(メインループ後に呼ぶ)
//*******************************************************
void DebugLog::endDebugConsole()
{
	// デバッグ用コンソール画面表示フラグが表示しない設定の場合、処理終了
	if (debugInfo.debugConsoleDisplayFlg == FALSE)
	{
		return;
	}
	fclose(stream_0);
	fclose(stream_1);
	//コンソール解放
	FreeConsole();
}