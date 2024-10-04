#include "RPN.hpp"
#include <iostream>
#include <stack>

int main(int ac, char **av)
{

	try
	{
		std::stack<int>stck;
		if(ac != 2)
		{
			std::cerr << "Argument Error\n";
			return 1;
		}
		reading(stck, av[1]);
		if(stck.size() == 1)
			std::cout << stck.top() << std::endl;
		else
			std::cerr << "Error\n";
		clearAll(stck);
	}
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return 0;
}