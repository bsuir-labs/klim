#pragma once
#include "Layout.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stack>
#include <fcntl.h>
#include <io.h>
#include "DataManager.h"
#include "Authorization.h"

class UIController
{
protected:
    std::stack<Layout*> m_lstack;
public:
    DataManager* m_dm;
    Authorization* m_auth;
    Layout* layout;

    UIController();
    UIController(DataManager*, Authorization*);
    virtual ~UIController();

    void render();
    void interact();
    void clr_scr(char fill = ' ');

    void quit(int);

    // setters;
    void setLayout(Layout*);
    void pop_ui();
};

