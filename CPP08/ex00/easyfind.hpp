
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>

template <typename T>
typename  T::iterator   easyfind(T& container, int nbr)
{
    typename T::iterator it = std::find(container.begin(), container.end(), nbr);
    if (it == container.end())
        throw std::runtime_error("Element not found in the container.");
    return it;
}

#endif