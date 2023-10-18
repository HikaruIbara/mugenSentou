#pragma once
#include "baseScene.h"
class resultScene :
    public baseScene
{
public:
    resultScene();
    ~resultScene();

    int action();
    void draw();
    void init();
    void end();
};

