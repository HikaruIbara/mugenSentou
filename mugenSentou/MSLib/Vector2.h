#pragma once
#include <math.h>

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);

	~Vector2();

	Vector2 one()   { return Vector2(1, 1); };
	Vector2 zero()  { return Vector2(0, 0); };
	Vector2 up()    { return Vector2(0, 1); };
	Vector2 down()  { return Vector2(0, -1); };
	Vector2 left()  { return Vector2(-1, 0); };
	Vector2 right() { return Vector2(1, 0); };

	Vector2 operator -= (const Vector2& in);
	Vector2 operator -  (const Vector2& in);
	Vector2 operator += (const Vector2& in);
	Vector2 operator +  (const Vector2& in);
	Vector2 operator *= (const Vector2& in);
	Vector2 operator *  (const Vector2& in);
	Vector2 operator /= (const Vector2& in);
	Vector2 operator /  (const Vector2& in);
	Vector2 operator ++ ();
	Vector2 operator -- ();
	bool operator ==(const Vector2& in)const;
	bool operator !=(const Vector2& in)const;

	/// <summary>
	/// ベクトルの長さを取得する
	/// </summary>
	/// <returns>float: 長さ</returns>
	float magnitude() { return sqrtf(fabsf(x) + fabsf(y)); }

	/// <summary>
	/// x,y,zそれぞれを１に正規化する
	/// ただし精度は悪い
	/// </summary>
	void normalize();

	/// <summary>
	/// 自身から指定したベクターの距離を返す
	/// 絶対値で計算しているためマイナスの値が出ない
	/// </summary>
	/// <param name="Vector: 指定の座標"></param>
	/// <returns>float: 距離</returns>
	float distance(Vector2 des);

	/// <summary>
	/// x,y,zそれぞれの累乗を計算する
	/// </summary>
	/// <param name="float: numの累乗"></param>
	void pow(float num);

	float x;
	float y;
};
