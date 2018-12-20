#include "RecordView.h"
#include "UIController.h"
#include "EditView.h"

RecordView::RecordView(Record r):m_record(r)
{
}


RecordView::~RecordView()
{
}


void RecordView::run()
{
    using namespace std;

    wcout << L"Просмотр записи\n\n";
    wcout << L"Имя:       " << m_record.first_name() << endl;
    wcout << L"Фамилия:   " << m_record.last_name() << endl;
    wcout << L"Адрес:     " << m_record.address() << endl;
    wcout << L"Телефон:   " << m_record.phone() << endl;
    wcout << endl;

    int choice;
    bool ok = false;
    do {
        //m_master_controller->clr_scr();
        wcout << L"0 - - - Вернуться назад\n";
        wcout << L"1 - - - Изменить запись\n";
        wcout << L"2 - - - Удалить запись\n";

        wcout << L"Ваш выбор > ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        else {
            if (choice >= 0 && choice < 3)
                ok = true;
        }
    } while (!ok);

    int t = 0;
    switch (choice)
    {
        case 0:
            m_master_controller->pop_ui();
            break;
        case 1:
            // edit
            m_master_controller->setLayout(new EditView(m_record));
            break;
        case 2:
            wcout << L"Вы уверены? Введите 1, чтобы продолжить\n> ";
            cin >> t;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                break;
            }
            if (t == 1)
            {
                m_master_controller->m_dm->remove(m_record.id());
                m_master_controller->pop_ui();
            }
            break;
    }
}