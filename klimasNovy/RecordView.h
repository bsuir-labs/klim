#pragma once
#include "Layout.h"
#include "Record.h"

class RecordView :
    public Layout
{
protected:
    Record m_record; // текущая запись
public:
    RecordView(Record); // конструктор
    virtual ~RecordView(); // деструктор

    virtual void run(); // вывод

};

