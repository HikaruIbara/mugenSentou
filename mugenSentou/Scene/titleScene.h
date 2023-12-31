#pragma once
#include "baseScene.h"
#include "../baseObject.h"

class titleScene :
    public baseScene
{
public:
    titleScene();
    ~titleScene();

    int action();
    void draw();
    void init();
    void end();

private:
    int bgmVol;
};

