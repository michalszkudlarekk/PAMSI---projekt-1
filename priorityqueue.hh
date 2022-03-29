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
