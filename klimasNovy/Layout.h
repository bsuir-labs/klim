#pragma once
#include <vector>
#include <string>
#include <iostream>

class UIController;

class Layout
{
protected:
    UIController* m_master_controller; // указатель на управляющий контроллер
public:
    Layout(); // конструктор
    virtual ~Layout(); // деструктор

    virtual void run() = 0; // чисто виртуальный метод вывода

    void setMaster(UIController*); // задаём управляющий контроллер
};

