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
	/// �x�N�g���̒������擾����
	/// </summary>
	/// <returns>float: ����</returns>
	float magnitude() { return sqrtf(fabsf(x) + fabsf(y)); }

	/// <summary>
	/// x,y,z���ꂼ����P�ɐ��K������
	/// ���������x�͈���
	/// </summary>
	void normalize();

	/// <summary>
	/// ���g����w�肵���x�N�^�[�̋�����Ԃ�
	/// ��Βl�Ōv�Z���Ă��邽�߃}�C�i�X�̒l���o�Ȃ�
	/// </summary>
	/// <param name="Vector: �w��̍��W"></param>
	/// <returns>float: ����</returns>
	float distance(Vector2 des);

	/// <summary>
	/// x,y,z���ꂼ��̗ݏ���v�Z����
	/// </summary>
	/// <param name="float: num�̗ݏ�"></param>
	void pow(float num);

	float x;
	float y;
};
