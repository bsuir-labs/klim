#pragma once
#include <string>

class Record
{
protected:
    unsigned m_id;

    std::wstring m_first_name;
    std::wstring m_last_name;
    std::wstring m_address;
    std::wstring m_phone_number;

public:
    Record();
    Record(
        unsigned id,
        std::wstring first_name,
        std::wstring last_name,
        std::wstring address,
        std::wstring phone
    ) : m_id(id),
        m_first_name(first_name),
        m_last_name(last_name),
        m_address(address),
        m_phone_number(phone)
    {}

    Record(unsigned);
    virtual ~Record();

    unsigned id() const;
    std::wstring first_name() const;
    std::wstring last_name() const;
    std::wstring address() const;
    std::wstring phone() const;

    void set_first_name(std::wstring);
    void set_last_name(std::wstring);
    void set_address(std::wstring);
    void set_phone(std::wstring);
    void set_id(unsigned);

    static bool compFName(Record&, Record&);
    static bool compLName(Record&, Record&);
    static bool compAddress(Record&, Record&);
    static bool compPhone(Record&, Record&);

    friend bool operator<(Record&, Record&);
};