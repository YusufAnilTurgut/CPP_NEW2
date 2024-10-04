
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "BitcoinExchange.hpp"
int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
		{
			throw std::runtime_error("Error: could not open file.");
			return (0);
		}
		BitcoinExchange btc1(argv[1]);

		btc1.getDatabase();
		btc1.readInputAndExchange();
	}
   	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}