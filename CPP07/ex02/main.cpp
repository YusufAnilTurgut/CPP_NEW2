#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
    Array<int> arr(5);
    int* copy = new int[5];
    for (int i = 0; i < 5; i++)
    {
        const int value = rand();
        arr[i] = value;
        copy[i] = value;
    }
    
    Array<int> tmp = arr;
    Array<int> eq(tmp);
    
    std::cout <<"arr : " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;
    
    std::cout <<"tmp : " << std::endl;
        for (int i = 0; i < 5; i++)
    {
        std::cout << tmp[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout <<"eq : " << std::endl;
        for (int i = 0; i < 5; i++)
    {
        std::cout << eq[i] << std::endl;
    }
    std::cout << std::endl;
    try {
        //std::cout << test[20] << std::endl;
        std::cout << eq[-1] << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

    for (int i = 0; i < 5; i++)
    {
        if (copy[i] != arr[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout <<"Size : " <<  arr.size() << std::endl; 
    Array<int> *a1 = new Array<int>();
    Array<int> *a2 = new Array<int>();

    *a1 = arr;
    std::cout <<"Size : " <<  a1->size() << std::endl;  
    delete a1;
    delete a2;

    delete [] copy;
    return 0;
}