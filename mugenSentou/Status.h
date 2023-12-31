#pragma once
#include <string>
#include "AllStatus.h"
#include "mainDefine.h"

class Status
{
private:
	StatusPer myStatus;

	bool deathFlag;
	int id;
	int actID;
	int tarID;
	AllSt allSt;

public:
	Status();
	Status(StatusPer st);
	~Status();

	void initStatus();
	void SetStatus(int objectNum, int side);
	StatusPer GetStatus() { return myStatus; }

	bool CheckDeathFlag();

	void SetID(int id) { this->id = id; }
	void SetActID(int id) { actID = id; }
	void SetTarID(int id) { tarID = id; }
	void SetName(std::string* name) { myStatus.name = *name; }
	void SetHp(int hp) { myStatus.hp = hp; }
	void SetHpMax(int hpMax) { myStatus.hpMax = hpMax; }
	void SetAt(int at) { myStatus.at = at; }
	void SetAtMa(int atMa) { myStatus.atMa = atMa; }
	void SetDe(int de) { myStatus.de = de; }
	void SetDeMa(int deMa) { myStatus.deMa = deMa; }
	void SetSpeed(int speed) { myStatus.speed = speed; }
	void SetMp(int mp) { myStatus.mp = mp; }
	void SetMaxMp(int mpMax) { myStatus.mpMax = mpMax; }
	void SetMpUp(int mpUp) { myStatus.mpUp = mpUp; }
	void SetLv(int lv) { myStatus.lv = lv; }
	void SetExp(int exp) { myStatus.exp = exp; }
	void SetDeathFlag(bool flag) { deathFlag = flag; }

	void AddHp(int addHp) { myStatus.hp += addHp; }
	void AddAt(int addat) { myStatus.at += addat; }

	int GetID() { return id; }
	int GetActID() { return actID; }
	int GetTarID() { return tarID; }
	std::string GetName() { return myStatus.name; }
	int GetHp() { return myStatus.hp; }
	int GetHpMax() { return myStatus.hpMax; }
	int GetAt() { return myStatus.at; }
	int GetAtMa() { return myStatus.atMa; }
	int GetDe() { return myStatus.de; }
	int GetDeMa() { return myStatus.deMa; }
	int GetSpeed() { return myStatus.speed; }
	int GetMp() { return myStatus.mp; }
	int GetMaxMp() { return myStatus.mpMax; }
	int GetMpUp() { return myStatus.mpUp; }
	int GetLv() { return myStatus.lv; }
	int GetExp() { return myStatus.exp; }
	bool GetDeathFlag() { return deathFlag; }

};

