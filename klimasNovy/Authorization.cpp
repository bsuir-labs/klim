#include "Authorization.h"



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

void Authorization::loadData()
{
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
    sortData();
}


void Authorization::saveData()
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

void Authorization::sortData()
{
    std::sort(m_users.begin(), m_users.end());
}

void Authorization::addUser(std::string username, std::string password)
{
    SHA256 sha256;
    std::string hash = sha256(password);
    User user(username, hash);

    m_users.push_back(user);
    sortData();
    saveData();
}

User Authorization::authorize(std::string username, std::string password)
{
    SHA256 sha256;
    std::string hash = sha256(password);

    int index = find(username);
    if (index == -1)
    {
        return User(); // anonymous user
    }

    if (hash.compare(m_users[index].password()) == 0)
        return m_users[index];

    return User();
}

int Authorization::find(std::string username)
{
    if (m_users.size() == 0) return -1;

    int l = 0, r = m_users.size() - 1;
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

bool Authorization::exists(std::string username)
{
    int res = find(username);
    return res != -1;
}