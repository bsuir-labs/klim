#pragma once
#include <vector>
#include <string>
#include <iostream>

class UIController;

class Layout
{
protected:
    UIController* m_master_controller;
public:
    Layout();
    virtual ~Layout();

    virtual void run() = 0;

    void setMaster(UIController*);
};

