#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>

struct data
{
    data *next, *previous;
    int priority, priority1;
    bool datatype = true;
};

struct data2
{
    data2 *next, *previous;
    int priority, priority2;
    std::string info;
    bool datatype = false;
};

template <typename type>
class queue
{
private:
    type front *;
    type back *;
    int size;

public:
    queue()
    {
        front = back = NULL;
        size = 0;
    };
    bool checkifempty();
    int value();
    type least() : type DELLleast();
    void add(int priority, std::string info)
};

template <typename type>
bool queue<type>::checkifempty()
{
    return !front;
}

template <typename type>
int queue<type>::value()
{
    return size;
}

template <typename type>
type queue<type>::least()
{
    if (queue<type>::checkifempty())
    {
        throw std::logic_error("Lista jest pusta!");
    }
    type *ptr1, *ptr2;
    ptr1 = ptr2 = front;
    if (ptr1 != NULL)
    {
        do
        {
            if (ptr1->datatype)
            {
                ptr2 = ptr2->next;
                if (ptr2->priority < ptr1->priority)
                {
                    ptr1 = ptr2;
                }
                else
                {
                    ptr2 = ptr2->next;
                    if (ptr2->priority2 < ptr1->priority2)
                        ptr1 = ptr2;
                }
            }

        } while (ptr2 != back);
    }
    return *ptr1;
}
