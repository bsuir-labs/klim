#pragma once
#include "Layout.h"

class Authorization;

class LoginView :
    public Layout
{
protected:
    Authorization* auth;
public:
    LoginView(Authorization*);
    virtual ~LoginView();

    virtual void run();
};

