#pragma once

template<class T> // шаблонный класс Стэк
class Stack
{
protected:

    template<class T>
    class M_Stack // внутренний шаблонный класс 
    {
    public:
        T m_value;    // значение элемента
        M_Stack<T>* m_next; // указатель на следующий элемент
    };

    M_Stack<T>* m_st; // указатель на верхний элемент стэка
public:
    Stack()
    {
        m_st = nullptr;
    }

    virtual ~Stack()
    {
        while (m_st) // подчищаем память
        {
            M_Stack<T>* tmp = m_st->m_next;
            delete m_st;
            m_st = tmp;
        }
    }

    void push(T x) // добавляем новый элемент
    {
        M_Stack<T>* nstack = new M_Stack<T>;
        nstack->m_next = m_st;
        nstack->m_value = x;
        m_st = nstack;
    }


    T top() const // получаем верхний
    {
        return m_st->m_value;
    }

    T pop() const // получаем верхний и удаляем его
    {
        T val = m_st->m_value;

        M_Stack<T>* todel = m_st;
        m_st = m_st->m_next;
        delete todel;

        return val;
    }

    bool empty() // проверка на пустоту 
    {
        return (m_st == nullptr);
    }

    unsigned size() // возвращаем размер стэка
    {
        M_Stack<T>* tmp = m_st;
        unsigned res = 0;
        
        while (tmp)
            res++,
            tmp = tmp->m_next;
        
        return res;
    }
};

