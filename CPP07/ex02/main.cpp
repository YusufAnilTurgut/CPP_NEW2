#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
    Array<int> numbers(20);
    int* mirror = new int[20];
    for (int i = 0; i < 5; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    Array<int> tmp = numbers;
    Array<int> test(tmp);
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << numbers[i] << std::endl;
    }
        for (int i = 0; i < 5; i++)
    {
        std::cout << tmp[i] << std::endl;
    }
        for (int i = 0; i < 5; i++)
    {
        std::cout << test[i] << std::endl;
    }
    try {
        //std::cout << test[20] << std::endl;
        std::cout << test[-1] << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

    for (int i = 0; i < 5; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout <<"Size : " <<  numbers.size() << std::endl; 
    Array<int> *a1 = new Array<int>();
    Array<int> *a2 = new Array<int>();

    *a1 = numbers;
    std::cout <<"Size : " <<  a1->size() << std::endl;  
    delete a1;
    delete a2;

    delete [] mirror;//
    return 0;
}