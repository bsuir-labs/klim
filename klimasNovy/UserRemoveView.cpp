#include "UserRemoveView.h"
#include "UIController.h"
#include "Authorization.h"


UserRemoveView::UserRemoveView()
{
}


UserRemoveView::~UserRemoveView()
{
}


void UserRemoveView::run()
{
    using namespace std;

    wcout << L"Введите имя пользователя, которого вы желаете удалить:\n";
    getc(stdin);

    string username;
    getline(cin, username);

    m_master_controller->m_auth->removeUser(username);
    m_master_controller->pop_ui();
}
