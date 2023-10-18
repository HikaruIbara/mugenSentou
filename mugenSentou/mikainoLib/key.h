#pragma once
void keyUpDate();
bool keyPush(int KeyNo);
bool singlePush(int KeyNo);
bool keyPushUp(int KeyNo);
//現在何が押されているかをポインタで返す
//charの配列は[256]で宣言してください
void nowKeyBuff(char skeyBuf[256]);
