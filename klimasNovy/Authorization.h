#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "User.h"
#include "sha256.h"

class Authorization
{
protected:
    std::string m_db_source;
    std::vector<User> m_users;

    int find(std::string);
public:
    Authorization();
    virtual ~Authorization();

    void setSource(std::string);
    void loadData();
    void saveData();
    void sortData();

    void addUser(std::string username, std::string password);
    User authorize(std::string username, std::string password);
};
