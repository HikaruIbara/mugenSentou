#pragma once

#define RELEASE
#define DEBUG
#define NOT_LOAD_SOUND
//#define MEMORY_LEAK

//シーン関連
#define SCENE_TITLE  0
#define SCENE_BATTLE 1
#define SCENE_RESULT 2

#define SCENE_MAX_COUNT 3


//オブジェクト関連
#define PLAYER 0
#define ENEMY 1
#define BOSS 2

#define PARTY_MAX 4
#define ENEMY_MAX 8
#define OBJ_MAX (PARTY_MAX + ENEMY_MAX)

#define PARTY_MAX_MASTER 1
#define ENEMY_MAX_MASTER 2

#define PLAYER_MAG 3
#define ENEMY_MAG 2


#define WINDOE_ITEM_NUM 4


//DxLibカラー設定
//										RED         GREEN      BLUE
#define DXLIB_COL_RED     (unsigned int)255 << 16 | 0   << 8 | 0   
#define DXLIB_COL_GREEN   (unsigned int)0   << 16 | 255 << 8 | 0   
#define DXLIB_COL_BLUE    (unsigned int)0   << 16 | 0   << 8 | 255   
#define DXLIB_COL_YELLOW  (unsigned int)255 << 16 | 255 << 8 | 0
#define DXLIB_COL_CYAN    (unsigned int)0   << 16 | 255 << 8 | 255   
#define DXLIB_COL_MAGENTA (unsigned int)255 << 16 | 0   << 8 | 255   
#define DXLIB_COL_BLACK   (unsigned int)0   << 16 | 0   << 8 | 0
#define DXLIB_COL_GRAY    (unsigned int)127 << 16 | 127 << 8 | 127
#define DXLIB_COL_WHITE   (unsigned int)255 << 16 | 255 << 8 | 255

