#include "MainMenu.h"
#include "UIController.h"
#include "ListView.h"
#include "AddView.h"
#include "UserAddView.h"

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}


void MainMenu::run()
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
        wcout << L"\t4 - Сохранить изменения" << "\n";
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
            m_master_controller->quit(0);
            break;
        case 1:
            // list everything
            m_master_controller->setLayout(new ListView());
            break;
        case 2:
            // add new
            m_master_controller->setLayout(new AddView());
            break;
        case 3:
            m_master_controller->setLayout(new UserAddView());
            break;
        case 4:
            m_master_controller->m_dm->saveData();
            break;
    }
}