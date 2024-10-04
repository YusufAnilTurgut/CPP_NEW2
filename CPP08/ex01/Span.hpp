
#ifndef SPAN_HPP
#define SPAN_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <bit>


class   Span
{
    private:
        unsigned int N;
        std::deque<int> data;
    public:
        Span();
        Span(int);
        ~Span();
        Span(const Span &);
        Span    &operator = (const Span &);

        int longestSpan(void);
        int shortestSpan(void);

        void    addNumber(int);
        void	addNumber(std::deque<int>::iterator begin, std::deque<int>::iterator end);

};


#endif