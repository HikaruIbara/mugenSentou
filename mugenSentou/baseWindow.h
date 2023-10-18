#pragma once
#include "DxLib.h"
#include "mikainoLib/mikainoLib.h"
#include "MSLib/MSLib.h"
#include "DxLib.h"
#include <math.h>
#include <winuser.h>
#include <string>

#include "mainDefine.h"

namespace MSL
{
	struct Rect
	{
		int x;
		int y;
		int w;
		int h;
	};
}
class baseWindow
{
public:
	baseWindow();
	~baseWindow();

	virtual void action() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
	virtual void end() = 0;


protected:

	//ç¿ïWÇ∆ëÂÇ´Ç≥
	MSL::Rect winSize;
	int edgeThick;
	int edgeColor;
	int mainColor;

public:

	void SetWindow(MSL::Rect rect,int edgeThick,int edgeColor,int mainColor);
	void drawWindow();

};

