#include "LoginView.h"
#include "UIController.h"
#include "Authorization.h"
#include "MainMenu.h"


LoginView::LoginView()
{
}


LoginView::~LoginView()
{
}


void LoginView::run() // вывод меню
{
    using namespace std;

    User result; // пользователь текущий
    string username,
        password;

    do {
        wcout << L"Имя пользователя:" << endl;
        getline(cin, username);
        wcout << L"Пароль:" << endl;
        getline(cin, password);

        result = m_master_controller->m_auth->authorize(username, password);

        m_master_controller->clr_scr();

        if (result.anonymous())
        {
            wcout << L"Неправильный пароль, попробуйте ещё раз" << endl;
        }
    } while (result.anonymous());
    
    m_master_controller->setLayout(new MainMenu());
}