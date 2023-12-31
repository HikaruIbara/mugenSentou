#pragma once
#include <inttypes.h>
#include <chrono>


//関数xorshift32()を実行する前に一回だけ実行してください
void initXshit();

///////////////////////////////////////////////////////
//　説明　　XorShitと呼ばれるビットシフトを利用した疑似乱数
//         ビットシフトを三回しているだけなので非常に高速です
// 
//　引数　　無し
//　戻り値　uint32_tの乱数
// 
//　※関数xorshift32()を実行する前にinitXshit()を一回だけ実行してください
///////////////////////////////////////////////////////
uint32_t xorshift32();

