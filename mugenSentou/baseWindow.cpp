#include "baseWindow.h"

baseWindow::baseWindow()
{
	edgeThick = 0;
	edgeColor = 0;
	mainColor = 0;
}

baseWindow::~baseWindow()
{
}

void baseWindow::SetWindow(MSL::Rect rect, int edgeThick, int edgeColor, int mainColor)
{
	winSize = rect;
	this->edgeColor = edgeThick;
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
}
