#include "baseWindow.h"

baseWindow::baseWindow()
{
	use = false;

	winSize = { 0,0,0,0 };
	edgeThick = 0;
	edgeColor = 0;
	mainColor = 0;

	fontColor = 0;
	fontSpace_x = 0;
	fontSpace_y = 0;
	fontSize = 0;
	mainStr = "";

	cursolPos.zero();
	rowNum = 0;
	nowRowNum = 0;

}

baseWindow::~baseWindow()
{
}

void baseWindow::action()
{
	if (cursol.isCursol)
	{
		cursolPos.x = (float)(winSize.x + fontSpace_x - cursol.GetCursolSize_x());
		cursolPos.y = (float)((winSize.y + fontSpace_y + fontSize / 2 - cursol.GetCursolSize_y() / 2) + (fontSize * nowRowNum) + (2 * nowRowNum));
	}
}

void baseWindow::draw()
{
	if (!use)
		return;

	drawWindow();
	if (cursol.isCursol)
	{
		cursol.drawCursol(cursolPos, INT32_MAX, TRUE);
		//cursol.drawCursol(cursolPos,GetColor(255,255,255),true);

	}
}

void baseWindow::init()
{
}

void baseWindow::end()
{
}

void baseWindow::SetWindow(MSL::Rect rect, bool use, int edgeThick, int edgeColor, int mainColor)
{
	this->use = use;
	winSize = rect;
	this->edgeThick = edgeThick;
	this->edgeColor = edgeColor;
	this->mainColor = mainColor;
}

void baseWindow::drawWindow()
{
	DrawBox(winSize.x,
		winSize.y,
		winSize.x + winSize.w,
		winSize.y + winSize.h,
		mainColor,
		TRUE);

	if (mainStr != "")
	{
		SetFontSize(fontSize);
		DrawString(winSize.x + fontSpace_x,
			winSize.y + fontSpace_y,
			mainStr.c_str(),
			fontColor);

	}

	//left
	DrawLine(winSize.x + edgeThick / 2,
		winSize.y,
		winSize.x + edgeThick / 2,
		winSize.y + winSize.h,
		edgeColor,
		edgeThick);

	//top
	DrawLine(winSize.x,
		winSize.y + edgeThick / 2,
		winSize.x + winSize.w,
		winSize.y + edgeThick / 2,
		edgeColor,
		edgeThick
	);

	//right
	DrawLine(winSize.x + winSize.w - edgeThick / 2,
		winSize.y,
		winSize.x + winSize.w - edgeThick / 2,
		winSize.y + winSize.h,
		edgeColor,
		edgeThick);

	//down
	DrawLine(winSize.x,
		winSize.y + winSize.h - edgeThick / 2,
		winSize.x + winSize.w,
		winSize.y + winSize.h - edgeThick / 2,
		edgeColor,
		edgeThick);
}

void baseWindow::SetString(std::string str, int color, int fontSize, int spaceX, int spaceY)
{
	mainStr = str;
	fontColor = color;
	GetCoursolPos();
	this->fontSize = fontSize;
	fontSpace_x = spaceX;
	fontSpace_y = spaceY;
}

void baseWindow::SetFormatString(const char* str, ...)
{
	//va_list args;
	//va_start(args, str);
	//for (int i = 0; str[i]!='\0'; ++i) {
	//	printf("%c\n", va_arg(args, char*));
	//	switch (str[i]) {
	//	case 'd':
	//		printf("%d\n", va_arg(args, int));
	//		break;
	//	case 'f':
	//		printf("%f\n", va_arg(args, double));
	//		break;
	//	case 'c':
	//		printf("%c\n", va_arg(args, char*));
	//		break;
	//	case 's':
	//		printf("%s\n", va_arg(args, char*));
	//		break;
	//	default:
	//		break;
	//	}
	//}
	//va_end(args);
}

void baseWindow::SetSelect(MSL::Select select, int color, int fontSize, int spaceX, int spaceY)
{
	nowSelect = select;
	mainStr = select.str;
	fontColor = color;
	GetCoursolPos();
	this->fontSize = fontSize;
	fontSpace_x = spaceX;
	fontSpace_y = spaceY;
}

void baseWindow::SetCursolUp()
{
	nowRowNum--;
	if (nowRowNum < 0)
	{
		nowRowNum = 0;
	}
}

void baseWindow::SetCursolDown()
{
	nowRowNum++;
	if (nowRowNum >= rowNum)
	{
		nowRowNum = rowNum - 1;
	}
}


int baseWindow::GetSelectNum()
{
	if (!cursol.isCursol)
		return -1;

	return nowRowNum;
}


void baseWindow::GetCoursolPos()
{
	rowNum = 0;
	char tmp = static_cast<char>(tolower(static_cast<unsigned char>('\n')));

	for (char i : mainStr)
		if (tolower(static_cast<unsigned char>(i)) == tmp)
			rowNum++;

}


