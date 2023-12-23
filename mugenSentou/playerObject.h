#pragma once
#include "baseObject.h"
class playerObject :
    public baseObject
{
public:
    playerObject();
    ~playerObject();

    void action();
    void draw();
    void init();
    void end();

private:
};

