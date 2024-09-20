
#include "Converter.hpp"


int main(int ac, char **args)
{
	std::cout << "Hello World" << std::endl;
	if (ac == 2)
	{
		ScalarConverter::convert(args[1]);
	}
	else
		ScalarConverter::impossible();
    return 0;
}
