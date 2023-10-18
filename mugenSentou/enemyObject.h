#pragma once
#include "baseObject.h"
class enemyObject :
    public baseObject
{
public:
    enemyObject();
    ~enemyObject();

    void action();
    void draw();
    void init();
    void end();

    void setDefaultStatus();
};

