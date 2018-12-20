#pragma once
#include "Layout.h"
#include "Record.h"

class EditView :
    public Layout
{
protected:
    Record m_record;
public:
    EditView(Record);
    virtual ~EditView();

    virtual void run();
};

