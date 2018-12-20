#pragma once
#include "Layout.h"
#include "Record.h"

class RecordView :
    public Layout
{
protected:
    Record m_record;
public:
    RecordView(Record);
    virtual ~RecordView();

    virtual void run();

};

