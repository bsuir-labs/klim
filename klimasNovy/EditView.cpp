#include "EditView.h"
#include "wio.h"
#include "UIController.h"

EditView::EditView(Record r):m_record(r)
{
}


EditView::~EditView()
{
}


void EditView::run()
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

    wcout << L"Новое имя:\n";
    getc(stdin);
    fname = WIO::readw();
    wcout << L"Новая фамилия:\n";
    lname = WIO::readw();
    wcout << L"Новый адрес:\n";
    addr = WIO::readw();
    wcout << L"Новый номер телефона:\n";
    phone = WIO::readw();

    m_record.set_first_name(fname);
    m_record.set_last_name(lname);
    m_record.set_address(addr);
    m_record.set_phone(phone);

    m_master_controller->m_dm->setById(m_record, m_record.id());
    m_master_controller->pop_ui();
}