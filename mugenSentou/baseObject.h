#pragma once
#include "DxLib.h"
#include "mikainoLib/mikainoLib.h"
#include "MSLib/MSLib.h"
#include "DxLib.h"
#include <math.h>
#include <winuser.h>
#include <string>

#include "mainDefine.h"
#include "Status.h"

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

	float imgMag;

	void mainImageSize();


public:

	//セッター
	void SetDeath();
	void setPostion(Vector2 pos) { this->pos = pos; }
	void setMainImage(int handle);
	void setStatus(int st, int side) { status.SetStatus(st, side); use = true; }
	void setStatus(Status* st) { status = *st; use = true; }
	void setID(int id) { status.SetID(id); }

	//ゲッター
	double getW() { return w; }
	double getH() { return h; }
	bool getUse() { return use; }
	Status* getStatus() { return &status; }
	int getID() { return status.GetID(); }

	void deleteObj();

};