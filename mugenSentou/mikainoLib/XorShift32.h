#pragma once
#include <inttypes.h>
#include <chrono>


//�֐�xorshift32()�����s����O�Ɉ�񂾂����s���Ă�������
void initXshit();

///////////////////////////////////////////////////////
//�@�����@�@XorShit�ƌĂ΂��r�b�g�V�t�g�𗘗p�����^������
//         �r�b�g�V�t�g���O�񂵂Ă��邾���Ȃ̂Ŕ��ɍ����ł�
// 
//�@�����@�@����
//�@�߂�l�@uint32_t�̗���
// 
//�@���֐�xorshift32()�����s����O��initXshit()����񂾂����s���Ă�������
///////////////////////////////////////////////////////
uint32_t xorshift32();
