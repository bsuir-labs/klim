#pragma once
#include "Layout.h"
class MainMenu :
    public Layout
{
private:
    void processChoice(int c);
public:
    MainMenu();
    virtual ~MainMenu();

    virtual void run();
};

