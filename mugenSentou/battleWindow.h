#pragma once
#include "baseWindow.h"
class battleWindow :
    public baseWindow
{
public:
    battleWindow();
    ~battleWindow();

    void action();
    void draw();
    void init();
    void end();


};

