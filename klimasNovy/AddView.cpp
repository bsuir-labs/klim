#include "AddView.h"
#include "UIController.h"
#include "wio.h"

AddView::AddView()
{
}


AddView::~AddView()
{
}


void AddView::run() // вывод
{
    using namespace std;

    wstring fname;
    wstring lname;
    wstring addr;
    wstring phone;

    wcout << L"Имя:\n";
    getc(stdin);
    fname = WIO::readw(); // ввод данных
    wcout << L"Фамилия:\n";
    lname = WIO::readw();

    wcout << L"Адрес:\n";
    addr = WIO::readw();
    
    wcout << L"Номер телефона:\n";
    phone = WIO::readw();

    m_master_controller->m_dm->append_data( // добавляем запись в бд
        Record(         // создаём новую запись на основе введённых данных
            0,
            fname,
            lname,
            addr,
            phone
        )
    );
    m_master_controller->pop_ui(); // вернулись обратно
}