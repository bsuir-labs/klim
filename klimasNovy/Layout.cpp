#include "Layout.h"


Layout::Layout()
{
}


Layout::~Layout()
{

}

void Layout::setMaster(UIController* controller) // задаём управляющий контроллер
{
    m_master_controller = controller;
}
