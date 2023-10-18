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
	struct Status
	{
		std::string name;
		int maxhp;
		int hp;
		int at;
		int de;
		int mp;
		int mpup;
		int lv;
		int exp;
	};

}
using namespace MSL;

class baseObject
{
public:
	baseObject();
	~baseObject();

	virtual void action() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
	virtual void end() = 0;


protected:
	//座標
	Vector2 pos;
	//サイズ
	int w, h;
	//アクティブかどうか
	bool use;
	//ステータス
	Status status;

	image* mainImg;

	int imgMag;

	void mainImageSize();


public:

	//セッター
	void setPostion(Vector2 pos) { this->pos = pos; }
	void setMainImage(int handle) { mainImg = new image(handle); }
	void setStatus(Status st) { status = st; }

	//ゲッター
	double getW() { return w; }
	double getH() { return h; }
	bool getUse() { return use; }
	Status getStatus() { return status; }



};