#include "UserAddView.h"
#include "Authorization.h"
#include "UIController.h"


UserAddView::UserAddView()
{
}


UserAddView::~UserAddView()
{
}


void UserAddView::run()
{
    using namespace std;

    string username;
    string password;

    bool ok = false;

    do {
        wcout << L"Логин нового пользователя:" << endl;
        getc(stdin);
        getline(cin, username);
        wcout << L"Пароль нового пользователя:" << endl;
        getline(cin, password);

        m_master_controller->clr_scr();

        if (m_master_controller->m_auth->exists(username))
        {
            wcout << L"Пользователь с таким именем уже существует :с" << endl;
        }
        else {
            ok = true;
            m_master_controller->m_auth->addUser(username, password);
            m_master_controller->m_auth->saveData();
        }
    } while (!ok);
    
    m_master_controller->pop_ui();
}