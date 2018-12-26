#pragma once
#include <string>

class Record
{
protected:
    unsigned m_id;

    std::wstring m_first_name;   // имя
    std::wstring m_last_name;   // фамилия
    std::wstring m_address;     // адрес
    std::wstring m_phone_number;    // номер телефона

public:
    Record();       // конструктор
    Record(         // конструктор из данных
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

    Record(unsigned); // конструктор по id
    virtual ~Record(); // деструктор

    unsigned id() const;            // получаем id
    std::wstring first_name() const; // получаем имя
    std::wstring last_name() const; // получаем фамилию
    std::wstring address() const;   // получаем адрес
    std::wstring phone() const;     // получаем номер телефона

    void set_first_name(std::wstring); // задаём имя
    void set_last_name(std::wstring);   // задаём фамилию
    void set_address(std::wstring);     // задаём адрес
    void set_phone(std::wstring);       // задаём телефон
    void set_id(unsigned);              // задаём айди

    static bool compFName(Record&, Record&);    // компаратор по имени
    static bool compLName(Record&, Record&);    // компаратор по фамилии
    static bool compAddress(Record&, Record&);  // компаратор по адресу
    static bool compPhone(Record&, Record&);    // компаратор по телефону

    friend bool operator<(Record&, Record&);    // перегрузка оператора сравнения <
};