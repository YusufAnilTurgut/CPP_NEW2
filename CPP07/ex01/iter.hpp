
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T, typename F>
void iter(T *array, int length, void(*func)(F const &))
{
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
} 

#endif