#pragma once
#include "Layout.h"

class LoginView :
    public Layout
{
public:
    LoginView();
    virtual ~LoginView();

    virtual void run(); // вывод менюшки
};

