#pragma once
#include "Layout.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Stack.h"
#include <fcntl.h>
#include <io.h>
#include "DataManager.h"
#include "Authorization.h"

class UIController
{
protected:
    Stack<Layout*> m_lstack; // стэк менюшек
public:
    DataManager* m_dm; // указатель на базу данных
    Authorization* m_auth; // указатель на бд пользователей
    Layout* layout; // указатель на текущую менюшку

    UIController(); // конструктор
    UIController(DataManager*, Authorization*); // конструктор
    virtual ~UIController(); // деструктор

    void render(); // вывод текущей менюшки
    void clr_scr(char fill = ' '); // очистка экрана

    void quit(int); // завершение приложения

    // setters;
    void setLayout(Layout*); // задаём новую менюшку
    void pop_ui(); // удаляем текущую менюшку
};

