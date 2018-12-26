#pragma once
#include <string>
class User
{
protected:
    std::string m_username; // логин
    std::string m_password; // пароль
    unsigned m_permissions; // уровни доступа
    bool m_anonymous;       // флаг, что пользователь анонимен (не залогинен)
public:
    User(); // конструктор
    User(std::string username, std::string password); // конструктор по логину и паролю
    virtual ~User();   // деструктор

    void setPermissions(unsigned);  // задаём права доступа
    bool allowed(unsigned); // проверям права доступа
    bool anonymous();   // проверка на анонимность (что пользователь залогинен)

    std::string username(); // получаем имя пользователя
    std::string password(); // получаем пароль (хэш)

    // операторы сравнения
    friend bool operator< (const User& lhs, const User& rhs);
    friend bool operator> (const User& lhs, const User& rhs);
    friend bool operator<=(const User& lhs, const User& rhs);
    friend bool operator>=(const User& lhs, const User& rhs);
};

