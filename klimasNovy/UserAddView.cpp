#include "UserAddView.h"
#include "Authorization.h"
#include "UIController.h"


UserAddView::UserAddView()
{
}


UserAddView::~UserAddView()
{
}


void UserAddView::run() // вывод меню
{
    using namespace std;

    string username;
    string password;

    bool ok = false;

    do {
        wcout << L"Для отмены, нажмите enter, оставив поле для логина пустым\n\n";
        wcout << L"Логин нового пользователя:" << endl;
        getc(stdin);
        getline(cin, username); 

        if (username == "")
        {
            m_master_controller->pop_ui(); // отменяем 
            return;
        }

        wcout << L"Пароль нового пользователя:" << endl;
        getline(cin, password);

        m_master_controller->clr_scr();                  // очищаем экран

        if (m_master_controller->m_auth->exists(username)) // проверяем существование пользователя
        {
            wcout << L"Пользователь с таким именем уже существует :с" << endl;
        }
        else {
            ok = true;
            m_master_controller->m_auth->addUser(username, password); // добавляем пользователя в бд
            m_master_controller->m_auth->saveData(); // сохраняем изменения бд в файл
        }
    } while (!ok); 
    
    m_master_controller->pop_ui(); // возвращаемся назад
}