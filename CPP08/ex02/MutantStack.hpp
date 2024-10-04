
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template    <class T>
class   MutantStack : public std::stack<T>
{
    public:
        
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack &copy)
        {
            *this = copy;
        }
        MutantStack &operator = (const MutantStack &copy)
        {
            if (this != &copy)
            {
                std::stack<T>::operator=(copy); 
            }
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin()
        {
            return this->c.begin();
        }
        iterator    end()
        {
            return this->c.end();
        }
};

#endif