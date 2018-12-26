#include "EditView.h"
#include "wio.h"
#include "UIController.h"

EditView::EditView(Record r):m_record(r)
{
}


EditView::~EditView()
{
}


void EditView::run() // вывод меню
{
    using namespace std;

    wcout << L"Просмотр записи\n\n";
    wcout << L"Имя:       " << m_record.first_name() << endl;
    wcout << L"Фамилия:   " << m_record.last_name() << endl;
    wcout << L"Адрес:     " << m_record.address() << endl;
    wcout << L"Телефон:   " << m_record.phone() << endl;
    wcout << endl;

    wstring fname;
    wstring lname;
    wstring addr;
    wstring phone;

    wcout << L"Новое имя (оставьте пустым, чтоб не изменять):\n";
    getc(stdin);
    fname = WIO::readw();
    if (fname == L"") wcout << m_record.first_name() << "\n\n";
    wcout << L"Новая фамилия:\n";
    lname = WIO::readw();
    if (lname == L"") wcout << m_record.last_name() << "\n\n";
    wcout << L"Новый адрес:\n";
    addr = WIO::readw();
    if (addr == L"") wcout << m_record.address() << "\n\n";
    wcout << L"Новый номер телефона:\n";
    phone = WIO::readw();
    if (phone == L"") wcout << m_record.phone() << "\n\n";

    if (fname != L"") m_record.set_first_name(fname); // не изменяем, если пустое
    if (lname != L"") m_record.set_last_name(lname);
    if (addr != L"")  m_record.set_address(addr);
    if (phone != L"") m_record.set_phone(phone);

    m_master_controller->m_dm->setById(m_record, m_record.id()); // обновляем запись в бд
    m_master_controller->pop_ui();                              // возвращаемся назад
}