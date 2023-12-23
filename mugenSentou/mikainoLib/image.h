#pragma once
class image
{
private:
	int GHandle;
	int x;
	int y;
	int GSizeX, GSizeY;
	int cx, cy;
public:
	image();
	image(const char* str);//オーバーロード
	image(int gHandle);
	~image();

	void SetImage(int hx, int hy);
	bool loadImage(const char* str);
	void DrawImage();
	void DeleteImage();
	void GetImageSize();
	void RotaImage(int x, int y, float mag, float rota, int anchor = 18);
	void SetRotateCenter(int hcx, int hcy);
	int GetImageW();
	int GetImgaeH();
	int GetGhandle();
	void draw(int x, int y, int anchor = 18);
};

#define ANCHOR_LEFT (1)
#define ANCHOR_XCENTER (2)
#define ANCHOR_RIGHT (4)
#define ANCHOR_TOP (8)
#define ANCHOR_YCENTER (16)
#define ANCHOR_BOTTOM (32)