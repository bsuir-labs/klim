#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Record.h"

using namespace std;

//template<class T>

class DataManager
{
protected:
    string m_source_file;
    vector<Record> m_data;

    unsigned m_last_changed;
public:
    DataManager() : m_last_changed(0) {}
    virtual ~DataManager() {}

    int setSource(const string& filename)
    {
        m_source_file = filename;
        return 0;
    }

    int loadData()
    {
        ifstream filer(m_source_file.c_str(), ios::in | ios::binary);

        if (!filer) {
            throw "no such file";
        }

        size_t bufferSize = 0;
        filer.read((char*)&bufferSize, sizeof(size_t));

        m_data.clear();

        for (size_t i = 0; i < bufferSize; ++i)
        {
            unsigned id;
            size_t fname_len;
            size_t lname_len;
            size_t addr_len;
            size_t phone_len;

            wchar_t* fname;
            wchar_t* lname;
            wchar_t* addr;
            wchar_t* phone;

            filer.read((char*)&id, sizeof(int));
            filer.read((char*)&fname_len, sizeof(size_t));
            filer.read((char*)&lname_len, sizeof(size_t));
            filer.read((char*)&addr_len, sizeof(size_t));
            filer.read((char*)&phone_len, sizeof(size_t));

            fname = new wchar_t[fname_len];
            lname = new wchar_t[lname_len];
            addr = new wchar_t[addr_len];
            phone = new wchar_t[phone_len];

            filer.read((char*)fname, fname_len * sizeof(wchar_t));
            filer.read((char*)lname, lname_len *sizeof(wchar_t));
            filer.read((char*)addr, addr_len * sizeof(wchar_t));
            filer.read((char*)phone, phone_len * sizeof(wchar_t));

            Record r(
                id,
                fname,
                lname,
                addr,
                phone
            );

            m_data.push_back(r);

            delete[] fname;
            delete[] lname;
            delete[] addr;
            delete[] phone;
        }

        filer.close();

        return 0;
    }

    int saveData()
    {
        ofstream filew(m_source_file.c_str(), ios::out | ios::binary);

        if (!filew) {
            return -1;
        }

        size_t sz = m_data.size();
        filew.write((char*)&sz, sizeof(m_data.size()));

        for (size_t i = 0; i < m_data.size(); ++i)
        {

            unsigned id = m_data[i].id();
            size_t fname_len = m_data[i].first_name().size() + 1;
            size_t lname_len = m_data[i].last_name().size() + 1;
            size_t addr_len = m_data[i].address().size() + 1;
            size_t phone_len = m_data[i].phone().size() + 1;

            wchar_t* fname;
            wchar_t* lname;
            wchar_t* addr;
            wchar_t* phone;
            fname = new wchar_t[fname_len];
            lname = new wchar_t[lname_len];
            addr = new wchar_t[addr_len];
            phone = new wchar_t[phone_len];

            wcscpy_s(fname, fname_len, m_data[i].first_name().c_str());
            wcscpy_s(lname, lname_len, m_data[i].last_name().c_str());
            wcscpy_s(addr, addr_len, m_data[i].address().c_str());
            wcscpy_s(phone, phone_len, m_data[i].phone().c_str());


            filew.write((char*)&id, sizeof(int));
            filew.write((char*)&fname_len, sizeof(size_t));
            filew.write((char*)&lname_len, sizeof(size_t));
            filew.write((char*)&addr_len, sizeof(size_t));
            filew.write((char*)&phone_len, sizeof(size_t));

            

            filew.write((char*)fname, fname_len * sizeof(wchar_t));
            filew.write((char*)lname, lname_len * sizeof(wchar_t));
            filew.write((char*)addr, addr_len * sizeof(wchar_t));
            filew.write((char*)phone, phone_len * sizeof(wchar_t));

            delete[] fname;
            delete[] lname;
            delete[] addr;
            delete[] phone;
        }
        filew.close();
        return 0;
    }

    void setData(vector<Record>& data)
    {
        m_data = data;
    }

    void setById(Record& r, unsigned id)
    {
        int set_index = -1;

        for (size_t i = 0; i < m_data.size() && set_index == -1; ++i)
            if (m_data[i].id() == id)
                set_index = i;

        if (set_index == -1)
            m_data.push_back(r);
        else
            m_data[set_index] = r;
    }

    size_t size()
    {
        return m_data.size();
    }

    Record operator[](size_t index) const
    {
        return m_data[index];
    }

    Record& operator[](size_t index)
    {
        return m_data[index];
    }

    void remove(unsigned id)
    {
        int del_index = -1;

        for (size_t i = 0; i < m_data.size() && del_index == -1; ++i)
            if (m_data[i].id() == id)
                del_index = i;

        if (del_index == -1) return;

        for (size_t i = del_index; i < m_data.size() - 1; ++i)
            swap(m_data[i], m_data[i + 1]);

        m_data.pop_back();
        incLastChanged();
    }

    void incLastChanged()
    {
        m_last_changed++;
    }

    unsigned lastChanged() const
    {
        return m_last_changed;
    }

    void append_data(Record c)
    {
        c.set_id(m_data.empty() ? 0 : m_data.back().id() + 1);
        m_data.push_back(c);
    }

    vector<Record> filter(wstring fname, wstring lname, wstring addr, wstring phone)
    {
        if (m_data.empty()) return vector<Record>();

        vector<Record> result;
        for (auto record : m_data)
        {
            bool ok = true;
            if (fname != L"" && record.first_name().find(fname) == wstring::npos)
                ok = false;
            if (lname != L"" && record.last_name().find(lname) == wstring::npos)
                ok = false;
            if (addr != L"" && record.address().find(addr) == wstring::npos)
                ok = false;
            if (phone != L"" && record.phone().find(phone) == wstring::npos)
                ok = false;

            if (ok)
                result.push_back(record);
        }

        sort(result.begin(), result.end(), Record::compFName);
        return result;
    }
};
