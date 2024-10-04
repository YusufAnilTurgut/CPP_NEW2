
#include "Span.hpp"

Span::Span()
{
    this->N = 0;
}

Span::Span(int N)
{
    this->N = N;
}

Span::~Span() {}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span    &Span::operator = (const Span &copy)
{
    if (this != &copy)
    {
        this->N = copy.N;
        this->data = copy.data;
    }
    return *this;
}

void    Span::addNumber(int number)
{
    if (this->data.size() != this->N)
        this->data.push_back(number);
    else
        throw std::runtime_error("Number already added or max len!");
}

int Span::longestSpan(void)
{
    if (this->data.size() > 1)
        return (*std::max_element(this->data.begin(), this->data.end()) - *std::min_element(this->data.begin(), this->data.end()));
    else
        throw std::runtime_error("Insufficient number of numbers!");
}

int Span::shortestSpan(void)
{
    if (this->data.size() > 1)
    {
        std::deque<int> sort = this->data;
        std::sort(sort.begin(), sort.end());

        int smallDiff = sort[1] - sort[0];

        for (int i = 2; i < (int)sort.size(); i++)
        {
            if (sort[i] - sort[i - 1] < smallDiff)
                smallDiff = sort[i] - sort[i - 1];
        }
        return smallDiff;
    }
    else
        throw std::runtime_error("Insufficient number of numbers!");
}


void	Span::addNumber(std::deque<int>::iterator begin, std::deque<int>::iterator end)
{
    std::deque<int>::iterator tmp = begin;
    unsigned int count = 0;
    while (tmp != end)
    {
        count++;
        tmp++;
    }
    if(this->data.size() + count > this->N)
    {
        throw std::runtime_error("Number already added or max len!");
    }
    while (begin != end)
    {
        this->data.push_back(*begin);
        begin++;
    }
}

