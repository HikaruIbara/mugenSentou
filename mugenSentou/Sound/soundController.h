#pragma once
#include "soundDefine.h"

void InitSound();

void SoundAction();

void SoundDraw();

void LoadSoundSE();

void LoadSoundBGM();

void PlaySoundSE(int seNum);

void PlaySoundBGM(int bgmNum);

void StopSoundBGM(int bgmNum);

void SetSEVolume(int vol);

void SetBGMVolume(int vol);

int GetSEVolume();

int GetBGMVolume();

void Clamp(int* vol);
