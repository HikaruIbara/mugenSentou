#pragma once
#include <string>

typedef struct Select
{
	int num;
	int kindNum;
	std::string str;
};

const Select selectAct[] =
{
	{ 0, 4, "こうげき\nまほう\nぼうぎょ\nアイテム\n"		},
	{ 1, 2, "かくとう\nつるぎ\n"						},
	{ 2, 4, "ファイア\nアクア\nリーフ\nリカバリ\n"		},
	{ 3, 1, "ぼうぎょ\n"								},
	{ 4, 1, "アイテム\n"								},
	{ 5, 3, "なぐり\nけり\nカウンタ"}
};

