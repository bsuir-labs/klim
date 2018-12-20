#pragma once
#include "Layout.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stack>
#include <fcntl.h>
#include <io.h>
#include "DataManager.h"

class UIController
{
protected:
    std::stack<Layout*> m_lstack;
public:
    DataManager* m_dm;
    Layout* layout;

    UIController();
    UIController(DataManager* dm);
    virtual ~UIController();

    void render();
    void interact();
    void clr_scr(char fill = ' ');

    void quit(int);

    // setters;
    void setLayout(Layout*);
    void pop_ui();
};

