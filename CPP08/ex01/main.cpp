
#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        //sp.addNumber(13);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        Span sp2 = Span(4);
        std::deque<int> vec1;

        sp2.addNumber(999);
        vec1.push_back(5);
        vec1.push_back(25);
        vec1.push_back(50);
        sp2.addNumber(vec1.begin(), vec1.end());
        

        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;

        std::cout << sp2.longestSpan() << std::endl;

        
        // Span *test1 = new Span(sp2);
        // Span *test2 = new Span();
        
        // *test2 = *test1;
        // std::cout << test1->shortestSpan() << std::endl;
        // std::cout << test1->longestSpan() << std::endl;
        // std::cout << test2->shortestSpan() << std::endl;
        // std::cout << test2->longestSpan() << std::endl;
        // delete test1;
        // delete test2;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}