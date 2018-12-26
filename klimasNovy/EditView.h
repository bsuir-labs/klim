#pragma once
#include "Layout.h"
#include "Record.h"

class EditView :
    public Layout
{
protected:
    Record m_record;
public:
    EditView(Record); // деструктор
    virtual ~EditView(); // конструктор

    virtual void run(); // вывод меню
};

