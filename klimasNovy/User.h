#pragma once
#include <string>
class User
{
protected:
    std::string m_username;
    std::string m_password;
    unsigned m_permissions;
    bool m_anonymous;
public:
    User();
    User(std::string username, std::string password);
    virtual ~User();

    void setPermissions(unsigned);
    bool allowed(unsigned);
    bool anonymous();

    std::string username();
    std::string password();

    friend bool operator< (const User& lhs, const User& rhs);// { return m_value < rhs.m_value; }
    friend bool operator> (const User& lhs, const User& rhs);// { return rhs < *this; }
    friend bool operator<=(const User& lhs, const User& rhs);// { return !(*this > rhs); }
    friend bool operator>=(const User& lhs, const User& rhs);// { return !(*this < rhs); }
};

