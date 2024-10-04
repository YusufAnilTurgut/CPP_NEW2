
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP


#include <fstream>
#include <iostream>
#include <string>
#include <map>


class   BitcoinExchange
{
    private:
        const std::string inputFileName;
        std::map<std::string, float> database;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &);
        BitcoinExchange    &operator = (const BitcoinExchange &);

		void    getDatabase(void);
        void    readInputAndExchange(void);
        void    searchInDatabaseAndPrint(std::string year, std::string value);
};


#endif