#include "Record.h"

Record::Record() :m_id(0)
{

}

Record::Record(unsigned id) : m_id(id)
{

}

Record::~Record()
{}

unsigned Record::id() const
{
    return m_id;
}

std::wstring Record::first_name() const
{
    return m_first_name;
}

std::wstring Record::last_name() const
{
    return m_last_name;
}

std::wstring Record::address() const
{
    return m_address;
}

std::wstring Record::phone() const
{
    return m_phone_number;
}

void Record::set_first_name(std::wstring fn)
{
    m_first_name = fn;
}

void Record::set_last_name(std::wstring ln)
{
    m_last_name = ln;
}

void Record::set_address(std::wstring addr)
{
    m_address = addr;
}

void Record::set_phone(std::wstring ph)
{
    m_phone_number = ph;
}

void Record::set_id(unsigned id)
{
    m_id = id;
}

bool Record::compFName(Record& a, Record& b)
{
    return a.m_first_name < b.m_first_name;
}

bool Record::compLName(Record& a, Record& b)
{
    return a.m_last_name < b.m_last_name;
}

bool Record::compAddress(Record& a, Record& b)
{
    return a.m_address < b.m_address;
}

bool Record::compPhone(Record& a, Record& b)
{
    return a.m_phone_number < b.m_phone_number;
}

bool operator<(Record& lhs, Record& rhs)
{
    return lhs.m_id < rhs.m_id;
}