#include "Status.h"

Status::Status()
{
	myStatus = allSt.GetPlInitSt(0);
	deathFlag = false;

	id = -1;
	actID = -1;
	tarID = -1;
}

Status::Status(StatusPer st)
{
	myStatus = st;
	deathFlag = false;

	id = -1;
	actID = -1;
	tarID = -1;

}

Status::~Status()
{
}

void Status::initStatus()
{
	myStatus = allSt.GetPlInitSt(0);
	deathFlag = true;

}

void Status::SetStatus(int objectNum, int side)
{
	switch (side)
	{
	case PLAYER:
		myStatus = allSt.GetPlInitSt(objectNum);
		break;
	case ENEMY:
		myStatus = allSt.GetEnInitSt(objectNum);
		break;
	case BOSS:
		myStatus = allSt.GetPlInitSt(objectNum);
		break;
	}
	deathFlag = true;

}

bool Status::CheckDeathFlag()
{
	if (myStatus.hp <= 0)
	{
		deathFlag = true;
		return  deathFlag;
	}
	else
	{
		deathFlag = false;
		return  deathFlag;

	}

}
