#pragma once

struct StatusPer
{
	std::string name;	//キャラクターの名前
	int hp;				//体力
	int hpMax;			//体力の最大値
	int at;				//物理攻撃力
	int atMa;			//魔法攻撃力
	int de;				//物理防御力
	int deMa;			//魔法防御力
	int speed;			//行動速度
	int mp;				//魔法量
	int mpMax;			//魔法量の最大値
	int mpUp;			//ターン毎の魔法量の回復量
	int lv;				//レベル
	int exp;			//経験値
};

#define STRING(var) #var

const enum PlayerObjNum
{
	playerdammy,
	reimu,
	// ※最後に追加するときは↓も更新してね。
};
constexpr int maxPlObjNum = reimu + 1;
const std::string playerObjName[]
{
	"ダミー",
	"れいむ"
};

const enum EnemyObjNum
{
	enemydammy,
	ran,
	chen,
	mai,
	satono
	// ※最後に追加するときは↓も更新してね。
};
constexpr int maxEnObjNum = satono + 1;
const std::string enemyObjName[]
{
	"ダミー",
	"らん",
	"ちぇん",
	"まい",
	"さとの"
};

const enum BossObjNum
{
	bossdammy,
	yukari,
	okina
	// ※最後に追加するときは↓も更新してね。
};
constexpr int maxBossObjNum = okina + 1;
const std::string bossObjName[]
{
	"ダミー",
	"ゆかり",
	"おきな"
};

class AllSt
{
private:
	StatusPer initPlSt[maxPlObjNum] =
	{
		{"dammy",-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{"reimu",10,10,6,9,12,15,10,4,4,1,1,10}

	};

	StatusPer initEnSt[maxEnObjNum] =
	{
		{"dammy" ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{"ran"   ,20,20, 4, 7,10,12, 7, 6, 6, 1, 1,10},
		{"chen"  ,20,20, 4, 7,10,12, 6, 6, 6, 1, 1,10},
		{"mai"   ,20,20, 4, 7,10,12, 4, 6, 6, 1, 1,10},
		{"satono",20,20, 4, 7,10,12, 3, 6, 6, 1, 1,10}
	};
public:
	StatusPer GetPlInitSt(PlayerObjNum num)
	{
		return initPlSt[num];
	}
	StatusPer GetPlInitSt(int num)
	{
		return initPlSt[num];
	}
	std::string GetPlName_EN(int num)
	{
		return initPlSt[num].name;
	}
	std::string GetPlName_JP(int num)
	{
		return playerObjName[num];
	}

	StatusPer GetEnInitSt(EnemyObjNum num)
	{
		return initEnSt[num];
	}
	StatusPer GetEnInitSt(int num)
	{
		return initEnSt[num];
	}
	std::string GetEnName_EN(int num)
	{
		return initEnSt[num].name;
	}
	std::string GetEnName_JP(int num)
	{
		return enemyObjName[num];
	}

	StatusPer nowAllStatus[maxBossObjNum] =
	{
		{"dammy",-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{"reimu",10,10,5,2,6,10,10,1,1,0},
		{"ran",50,50,5,2,5,10,10,1,1,0},
	};
};
