#include "AddView.h"
#include "UIController.h"
#include "wio.h"

AddView::AddView()
{
}


AddView::~AddView()
{
}


void AddView::run()
{
    using namespace std;

    //wchar_t fname[50];
    //wchar_t lname[50];
    //wchar_t addr[50];
    //wchar_t phone[50];
    wstring fname;
    wstring lname;
    wstring addr;
    wstring phone;

    wcout << L"Имя:\n";
    getc(stdin);
    fname = WIO::readw();
    wcout << L"Фамилия:\n";
    lname = WIO::readw();

    wcout << L"Адрес:\n";
    addr = WIO::readw();
    
    wcout << L"Номер телефона:\n";
    phone = WIO::readw();

    m_master_controller->m_dm->append_data(
        Record(
            0,
            fname,
            lname,
            addr,
            phone
        )
    );
    m_master_controller->pop_ui();
}