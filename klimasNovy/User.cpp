#include "User.h"



User::User() // создание анонимного пользователя
{
    m_anonymous = true;
}


User::User(std::string username, std::string password) // создание залогиненого пользователя
{
    m_username = username;
    m_password = password;
    m_anonymous = false;
}


User::~User()
{
}


void User::setPermissions(unsigned permissions)
{
    m_permissions = permissions;
}

bool User::allowed(unsigned permissions) // проверка прав
{
    return bool(m_permissions & permissions);
}

bool User::anonymous()
{
    return m_anonymous;
}

std::string User::username()
{
    return m_username;
}

std::string User::password()
{
    return m_password;
}

bool operator< (const User& lhs, const User& rhs) { return lhs.m_username < rhs.m_username; }
bool operator> (const User& lhs, const User& rhs) { return rhs < lhs; }
bool operator<=(const User& lhs, const User& rhs) { return !(lhs > rhs); }
bool operator>=(const User& lhs, const User& rhs) { return !(lhs < rhs); }