#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>

struct data1 /* Rzeczywista struktura */
{
    data1 *next, *previous;
    int priority, priority1; /* Zmienna priority1 potrzebna jest tylko do mieszania wiadomosci */
    std::string info;
    bool dataType = true; /*dataType rowniez potrzebna jest tylko do mieszania wiadomosci */
};

struct data2 /* Struktura potrzebna do mieszania wiadomosci */
{
    data2 *next, *previous;
    int priority, priority1;
    std::string info;
    bool dataType = false;
};

/* Szablon potrzebny do mieszania */
template <typename type>
class queue
{
private:
    type *front;
    type *back;
    int size;

public:
    queue()
    {
        front = back = NULL;
        size = 0;
    };
    bool checkIfEmpty();
    int value();
    type least();
    type pull();
    void push(int priority, std::string info);
};

template <typename type>
bool queue<type>::checkIfEmpty()
{
    return !front;
}

template <typename type>
int queue<type>::value()
{
    return size;
}

template <typename type>
type queue<type>::least() /*funkcja odpowiedzialna za znalezienie najmniej priorytetowej wiadomosci */
{
    if (queue<type>::checkIfEmpty())
    {
        throw std::logic_error("Podana lista jest pusta!");
    }
    type *ptr1, *ptr2;
    ptr1 = ptr2 = front;
    if (ptr1 != NULL)
    {
        do
        {
            if (ptr1->dataType)
            {
                ptr2 = ptr2->next;
                if (ptr2->priority < ptr1->priority)
                {
                    ptr1 = ptr2;
                }
                else
                {
                    ptr2 = ptr2->next;
                    if (ptr2->priority1 < ptr1->priority1)
                        ptr1 = ptr2;
                }
            }

        } while (ptr2 != back);
    }
    return *ptr1;
}

template <typename type>
type queue<type>::pull() /*funkcja odpowiedzialna za usuniecie najmniej priorytetowej wiadomosci */
{
    size--;
    type *ptr, *ptr1, object;
    ptr = ptr1 = front;
    if (queue<type>::checkIfEmpty())
    {
        throw std::logic_error("Lista jest pusta!");
    }
    do
        if (ptr->dataType)
        {
            ptr1 = ptr1->next;
            if (ptr1->priority < ptr->priority)
                ptr = ptr1;
        }
        else
        {
            ptr1 = ptr1->next;
            if (ptr1->priority1 < ptr->priority1)
                ptr = ptr1;
        }
    while (ptr1 != back);

    if (ptr == front && ptr == back)
    {
        front = back = NULL;
    }
    else if (ptr == front)
    {
        front = ptr->next;
        front->previous = front;
    }
    else if (ptr == back)
    {
        back = ptr->previous;
        back->next = back;
    }
    else
    {
        (ptr->next)->previous = (ptr->previous);
        (ptr->previous)->next = (ptr->next);
    }
    object = *ptr;
    delete ptr;
    ptr = NULL;
    return object;
}

template <typename type> /* Funkcja odpowiedzialna za dodanie poszczególnych obiektów do kolejki */
void queue<type>::push(int priority, std::string info)
{
    size++; // 1
    type *ptr;
    ptr = new type;           // 1 obliczenie złożoności obliczeniowej
    ptr->info = info;         // 1
    ptr->priority = priority; // 1
    if (!ptr->dataType)
    {
        ptr->priority1 = rand(); // 1
    }
    if (front == NULL)
    {
        front = ptr;           // 1
        back = ptr;            // 1
        ptr->next = back;      // 1
        ptr->previous = front; // 1
    }
    else
    {
        ptr->next = front;
        front->previous = ptr;
        front = ptr;
        ptr->previous = front;
    }
}

// push nie zalezy od ilosci danych wejsciowych
// O(1) - bez zlozonosci obliczeniowej , f(n)=9