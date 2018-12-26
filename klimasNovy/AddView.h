#pragma once
#include "Layout.h"
class AddView :
    public Layout
{
public:
    AddView();          // конструктор
    virtual ~AddView(); // деструктор

    virtual void run(); // вывод
};

