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
	/// �x�N�g���̒������擾����
	/// </summary>
	/// <returns>float: ����</returns>
	float magnitude() { return sqrtf(fabsf(x) + fabsf(y) + fabsf(z)); }

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
	float distance(Vector3 des);

	/// <summary>
	/// x,y,z���ꂼ��̗ݏ���v�Z����
	/// </summary>
	/// <param name="float: num�̗ݏ�"></param>
	void pow(float num);

	float x;
	float y;
	float z;
};
