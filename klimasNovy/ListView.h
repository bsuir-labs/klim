#pragma once
#include "Layout.h"
#include "DataManager.h"

class ListView :
    public Layout
{
public:
    ListView();
    virtual ~ListView();

    virtual void run();
    void getInput(vector<Record>&);
};

