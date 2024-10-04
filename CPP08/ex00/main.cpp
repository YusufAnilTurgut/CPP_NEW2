
#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> *vec1 = new std::vector<int>();

        vec1->push_back(2);
        vec1->push_back(3);
        vec1->push_back(5);
        vec1->push_back(6);
        vec1->push_back(4);

        std::vector<int>::iterator it = easyfind(*vec1, 3);
        while (it != vec1->end())
        {
            std::cout << *it << std::endl;
            it++;
        }
        
        delete vec1;

        std::deque<int> *deque1 = new std::deque<int>();
        deque1->push_back(2);
        deque1->push_back(3);
        deque1->push_back(5);
        deque1->push_back(6);
        deque1->push_back(4);
        std::deque<int>::iterator it2 = easyfind(*deque1, 5);
        std::cout << std::endl;
        while (it2 != deque1->begin())
        {
            std::cout << *it2 << std::endl;
            --it2; 
        }
        std::cout << *it2 << std::endl; // Baş
        
        //std::cout << *easyfind(*deque1, 32) << std::endl;
        delete deque1;
    
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}