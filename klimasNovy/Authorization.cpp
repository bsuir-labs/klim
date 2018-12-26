#include "Authorization.h"
#include <utility>


Authorization::Authorization()
{
}


Authorization::~Authorization()
{
}


void Authorization::setSource(std::string source)
{
    m_db_source = source;
}

void Authorization::loadData() // чтение данных из файла
{                               // (см. DataManager)
    std::ifstream file(m_db_source, std::ios::in | std::ios::binary);
    if (!file) {
        throw "no such file";
    }
    size_t sz = 0;
    file.read((char*)&sz, sizeof(size_t));

    for (size_t i = 0; i < sz; ++i)
    {
        char* username;
        char* password;
        int name_len;
        int pass_len;

        file.read((char*)&name_len, sizeof(int));
        username = new char[name_len];
        file.read(username, name_len);

        file.read((char*)&pass_len, sizeof(int));
        password = new char[pass_len];
        file.read(password, pass_len);

        User cur(username, password);
        m_users.push_back(cur);

        delete[] username;
        delete[] password;
    }
    file.close();
    sortData(); // сортируем для работы бинарного поиска
}


void Authorization::saveData() // сохранение данных (см. DataManager)
{
    std::ofstream file(m_db_source, std::ios::out | std::ios::binary);
    if (!file) {
        return;
    }

    size_t sz = m_users.size();
    file.write((char*)&sz, sizeof(sz));

    for (size_t i = 0; i < m_users.size(); ++i)
    {
        User cur = m_users[i];
        int name_len = cur.username().size() + 1;
        int pass_len = cur.password().size() + 1;
        file.write((char*)&name_len, sizeof(int));
        file.write(cur.username().c_str(), name_len);

        file.write((char*)&pass_len, sizeof(int));
        file.write(cur.password().c_str(), pass_len);
    }
    file.close();
}

void Authorization::sortData() // сортировка данных
{
    std::sort(m_users.begin(), m_users.end()); // стандартная ф-ция сортировки
}

void Authorization::addUser(std::string username, std::string password) // добавление нового пользователя
{
    SHA256 sha256;      // класс шифрования
    std::string hash = sha256(password); // получаем хэш пароля (шифруем его)
    User user(username, hash);  // создаём нового пользователя 

    m_users.push_back(user);  // добавляем его в массив пользователей
    sortData();   // сортируем массив
    saveData();    // сохраняем данные в файл
}


void Authorization::removeUser(std::string username) // удаление пользователя
{
    int index = find(username); // ищем по логину
    if (index == -1)
        return;

    for (size_t i = index; i < m_users.size() - 1; ++i) // сдвигаем в конец
        std::swap(m_users[i + 1], m_users[i]);

    m_users.pop_back(); // удаляем
    saveData(); // сохраняем изменения
}


User Authorization::authorize(std::string username, std::string password) // авторизация пользователя
{
    SHA256 sha256;   // класс шифрования
    std::string hash = sha256(password); // получаем хэш пароля

    int index = find(username);  // ищем пользователя по имени
    if (index == -1)   // если не нашли
    {
        return User(); // возвращаем анонимного пользователя
    }

    if (hash.compare(m_users[index].password()) == 0) // сравниваем хэши паролей
        return m_users[index];  // возвращаем залогиненного пользователя

    return User();  // возвращаем анонимного пользователя
}

int Authorization::find(std::string username) // поиск индекса пользователя по имени
{
    if (m_users.size() == 0) return -1; 

    int l = 0, r = m_users.size() - 1; // бинарный поиск
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (m_users[mid].username() < username)
            l = mid + 1;
        else
            r = mid;
    }
    if (m_users[l].username().compare(username) == 0)
        return l;
    return -1;
}

bool Authorization::exists(std::string username) // проверка на существование
{
    int res = find(username); // пытаемся найти.
    return res != -1; 
}