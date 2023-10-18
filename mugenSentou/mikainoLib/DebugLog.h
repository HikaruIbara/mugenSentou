#pragma once
#include "DxLib.h"
#include <Windows.h>

class DebugLog
{
public:
	void initDebugConsole();
	void clearDebugConsole();
	void endDebugConsole();

private:

	struct debugInfo
	{
		int debugConsoleDisplayFlg;

	}debugInfo;

	FILE* stream_0, * stream_1;
	errno_t err_0, err_1;
};

