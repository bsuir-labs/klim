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
    std::string m_db_source;        // имя файла с бд пользователей
    std::vector<User> m_users;      // массив пользователей

    int find(std::string);          // поиск индекса пользователя в массиве
public:
    Authorization();
    virtual ~Authorization();

    bool exists(std::string);   // проверка на существование пользователя

    void setSource(std::string);    // задаём файл с бд
    void loadData();                // загрузка данных
    void saveData();                // сохранение данных
    void sortData();                // сортировка данных

    void addUser(std::string username, std::string password);   // добавление нового пользователя
    User authorize(std::string username, std::string password);  // авторизация пользователя
};
