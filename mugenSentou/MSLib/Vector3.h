#pragma once
#include <math.h>

class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);

	~Vector3();

	Vector3 one()     { return Vector3( 1, 1, 1); };
	Vector3 zero()    { return Vector3( 0, 0, 0); };
	Vector3 back()    { return Vector3( 0, 0,-1); };
	Vector3 up()      { return Vector3( 0, 1, 0); };
	Vector3 down()    { return Vector3( 0,-1, 0); };
	Vector3 forward() { return Vector3( 0, 0, 1); };
	Vector3 left()    { return Vector3(-1, 0, 0); };
	Vector3 right()   { return Vector3( 1, 0, 0); };

	Vector3 operator -= (const Vector3& in);
	Vector3 operator -  (const Vector3& in);
	Vector3 operator += (const Vector3& in);
	Vector3 operator +  (const Vector3& in);
	Vector3 operator *= (const Vector3& in);
	Vector3 operator *  (const Vector3& in);
	Vector3 operator /= (const Vector3& in);
	Vector3 operator /  (const Vector3& in);
	void operator ++ ();
	void operator -- ();

	/// <summary>
	/// ベクトルの長さを取得する
	/// </summary>
	/// <returns>float: 長さ</returns>
	float magnitude() { return sqrtf(fabsf(x) + fabsf(y) + fabsf(z)); }

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
	float distance(Vector3 des);

	/// <summary>
	/// x,y,zそれぞれの累乗を計算する
	/// </summary>
	/// <param name="float: numの累乗"></param>
	void pow(float num);

	float x;
	float y;
	float z;
};
