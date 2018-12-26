#include "ListView.h"
#include <iostream>
#include <iomanip>
#include "UIController.h"
#include "RecordView.h"
#include "wio.h"


ListView::ListView()
{
}


ListView::~ListView()
{
}


void ListView::run() // вывод меню
{
    using namespace std;

    wstring fname_filter; // запросы для фильтрации
    wstring lname_filter;
    wstring address_filter;
    wstring phone_filter;

    wcout << L"Фильтрация. Оставьте поля пустыми, если фильтрация не требуется.\n";
    wcout << L"По имени:\n";

    getc(stdin);
    fname_filter = WIO::readw(); // чтение юникода из консоли
    wcout << L"По фамилии:\n";
    lname_filter = WIO::readw();
    wcout << L"По адресу:\n";
    address_filter = WIO::readw();
    wcout << L"По телефону:\n";
    phone_filter = WIO::readw();

    vector<Record> result = m_master_controller->m_dm->filter( // получение фильтрованых данных
        fname_filter,
        lname_filter,
        address_filter,
        phone_filter
    );

    streamsize fname_sz = 0,
        lname_sz = 0,
        addr_sz = 0,
        phone_sz = 0;

    for (auto x: result)
    {
        fname_sz = max((unsigned) fname_sz, x.first_name().size());
        lname_sz = max((unsigned) lname_sz, x.last_name().size());
        addr_sz = max((unsigned)addr_sz, x.address().size());
        phone_sz = max((unsigned)phone_sz, x.phone().size());
    }

    for (size_t i = 0; i < result.size(); ++i) // вывод
    {
        wcout << L"[" << i << L"] ";
        wcout << left << setw(fname_sz + 1) << result[i].first_name();
        wcout << left << setw(lname_sz + 1) << result[i].last_name();
        wcout << left << setw(addr_sz + 1) << result[i].address();
        wcout << left << setw(phone_sz + 1) << result[i].phone();
        wcout << "\n";
    }

    getInput(result); // взаимодействие с пользователем
}

void ListView::getInput(vector<Record>& result) // взаимодействие с пользователем
{
    int choice;
    bool ok = true;
    wcout << L"Чтобы просмотреть подробнее введите номер записи\n";
    wcout << L"Введите -1, чтобы вернуться назад\n";
    do {
        wcout << L"Ваш выбор > ";
        cin >> choice;
        if (cin.fail() || (choice < -1 || choice >= result.size())) // проверка на валидность ввода
        {
            cin.clear();
            cin.ignore();
        }
        else {
            ok = true;
        }
    } while (!ok);

    if (choice == -1)
        m_master_controller->pop_ui();
    else
        m_master_controller->setLayout(new RecordView(result[choice])); // подробный просмотр записи
}