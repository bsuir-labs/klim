#include "MainMenu.h"
#include "UIController.h"
#include "ListView.h"
#include "AddView.h"
#include "UserAddView.h"
#include "UserRemoveView.h"

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}


void MainMenu::run() // вывод меню
{
    using namespace std;

    int choice;
    bool ok = false;
    do {
        m_master_controller->clr_scr();
        wcout << L"Пример меню\n";
        wcout << L"\n";
        wcout << L"\t1 - Поиск и фильтрация" << "\n";
        wcout << L"\t2 - Новая запись" << "\n";
        wcout << L"\t3 - Добавить пользователя" << "\n";
        wcout << L"\t4 - Удалить пользователя" << "\n";
        wcout << L"\t5 - Сохранить изменения" << "\n";
        wcout << L"\t0 - Выйти" << "\n";

        wcout << L"Ваш выбор > ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        else {
            ok = true;
        }
    } while (cin.bad() || (choice < 0 || choice > 5));

    processChoice(choice);
}

void MainMenu::processChoice(int c)
{
    switch (c)
    {
        case 0:
            m_master_controller->quit(0);   // выход из программы
            break;
        case 1:
            m_master_controller->setLayout(new ListView()); // список всех записей
            break;
        case 2:
            m_master_controller->setLayout(new AddView()); // добавление новой записи
            break;
        case 3:
            m_master_controller->setLayout(new UserAddView()); // добавление нового пользователя
            break;
        case 4:
            m_master_controller->setLayout(new UserRemoveView()); // Удаление пользователя
            break;
        case 5:
            m_master_controller->m_dm->saveData(); // сохранение изменений
            break;
    }
}