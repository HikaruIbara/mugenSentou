#include"dxlib.h"
#include"image.h"
#define PI    3.1415926535897932384626433832795f

image::image()
{
	GHandle = 0;
	x = 0;
	y = 0;
	GSizeX = 0;
	GSizeY = 0;
	cx = 0;
	cy = 0;
}
image::image(const char* str)
{
	loadImage(str);
}
image::image(int gHandle)
{
	GHandle = gHandle;
	GetImageSize();
}
image::~image()
{
	//DeleteGraph(GHandle);
}

void image::SetImage(int hx, int hy)
{
	x = hx;
	y = hy;
}

bool image::loadImage(const char* str)
{
	GHandle = LoadGraph(str);
	if (GHandle == -1)
	{
		GHandle = NULL;
		return false;
	}
	GetImageSize();
	return true;
}

void image::DrawImage()
{
	DrawGraph(x - GSizeX / 2, y - GSizeY / 2, GHandle, TRUE);
}

void image::DeleteImage()
{
	DeleteGraph(GHandle);
	//GHandle = 0;
}

void image::GetImageSize()
{
	GetGraphSize(GHandle, &GSizeX, &GSizeY);
	//DrawFormatString(0, 0, GetColor(255, 0, 0), "%d×%d", GSizeX, GSizeY);
}


void image::RotaImage(int x, int y, float mag, float rota, int anchor)
{
	GetGraphSize(GHandle, &GSizeX, &GSizeY);
	//SetRotateCenter(GSizeX * mag / 2, GSizeY * mag / 2);
	int dx = x;
	int dy = y;
	cx = 0;
	cy = 0;
	if ((anchor & ANCHOR_XCENTER) != 0)
	{
		dx = (x - GSizeX / 2) + GSizeX / 2;
		cx = GSizeX / 2;
	}
	if ((anchor & ANCHOR_RIGHT) != 0)
	{
		dx = (x - GSizeX) + GSizeX;
		cx = GSizeX;
	}
	if ((anchor & ANCHOR_YCENTER) != 0)
	{
		dy = (y - GSizeY / 2) + GSizeY / 2;
		cy = GSizeY / 2;
	}
	if ((anchor & ANCHOR_BOTTOM) != 0)
	{
		dy = (y - GSizeY) + GSizeY;
		cy = GSizeY;
	}

	DrawRotaGraph3(dx, dy, cx, cy, mag, mag, rota, GHandle, TRUE);

}

void image::SetRotateCenter(int hcx, int hcy)
{
	cx = hcx;
	cy = hcy;
}

int image::GetImageW()
{
	return GSizeX;
}
int image::GetImgaeH()
{
	return GSizeY;
}

int image::GetGhandle()
{
	return GHandle;
}

void image::draw(int x, int y, int anchor)
{
	int dx = x;
	int dy = y;
	if ((anchor & ANCHOR_XCENTER) != 0)dx = (x - GSizeX / 2);
	if ((anchor & ANCHOR_RIGHT) != 0)dx = (x - GSizeX);
	if ((anchor & ANCHOR_YCENTER) != 0)dy = (y - GSizeY / 2);
	if ((anchor & ANCHOR_BOTTOM) != 0)dy = (y - GSizeY);
	DrawGraph(dx, dy, GHandle, TRUE);

	//DrawGraph(x - GSizeX / 2, y - GSizeY / 2, GHandle, TRUE);

}




//// ＢＭＰ画像のメモリへの読みこみ
//GHandle = LoadGraph("test1.bmp");
//
//// 画面左上に描画します(『DrawGraph』を使用)
//DrawGraph(0, 0, GHandle, FALSE);
//
//// 読み込んだ画像のグラフィックハンドルを削除
//DeleteGraph(GHandle);
