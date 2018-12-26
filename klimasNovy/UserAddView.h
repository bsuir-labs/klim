#pragma once
#include "Layout.h"
class UserAddView :
    public Layout
{
public:
    UserAddView(); // конструктор
    virtual ~UserAddView(); // деструктор

    virtual void run(); // вывод меню
};

