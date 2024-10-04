
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string inputFileName): inputFileName(inputFileName) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &copy)
{
    if (this != &copy)
        this->database = copy.database;
    return *this;
}


 void BitcoinExchange::getDatabase()
 {
	std::ifstream data("data.csv");
	std::string line;

	getline(data, line);
	while(getline(data, line))
	{

		float value = std::stof(line.substr(11));
		this->database.insert(std::make_pair(line.substr(0,10), value));
	}
	data.close();
 }

int stringToInt(const std::string &str) {
    std::stringstream ss(str);
    int result;

    ss >> std::ws;  
    ss >> result;

    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid integer input: " + str);
    }

    return result;
}

float stringToFloat(const std::string &str) {
    std::stringstream ss(str);
    float result;

    ss >> std::ws;  
    ss >> result;

    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid float input: " + str);
    }

    return result;
}


void    BitcoinExchange::readInputAndExchange(void)
{
	std::ifstream inputFile(this->inputFileName);
	std::string line;

    if (inputFile.fail())
    {
        inputFile.close();
        throw std::runtime_error("Error: could not open file.");
    }
	getline(inputFile, line);
	while(getline(inputFile, line))
	{
        float value;
        int year, month, day;
        try 
        {

            if (line.substr(0, line.find(' ')).size() == 10)
            {
                try
                {
                    year = stringToInt(line.substr(0,4));
                    month = stringToInt(line.substr(5, 2));
                    day = stringToInt(line.substr(8, 2));
                    value = stringToFloat(line.substr(13));
                }
                catch (std::exception &e)
                {
                    std::cout << "Error: bad input => " << line.substr(0, line.find(' ')) << std::endl;
                    continue;
                }
            }
            else
                throw std::runtime_error("Error: bad input => " + line.substr(0, line.find(' ')));
            if (year < 2009 || year > 2022 || month > 12 || month < 1 || day > 30 || day < 1)
                throw std::runtime_error("Error: bad input => " + line.substr(0, line.find(' ')));
            if (value < 0)
                throw  std::runtime_error("Error: not a positive number.");
            if (value > 1000)
                throw  std::runtime_error("Error: too large a number.");
            this->searchInDatabaseAndPrint(line.substr(0,10), line.substr(13));
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
	}
	inputFile.close();
}



void    BitcoinExchange::searchInDatabaseAndPrint(std::string year, std::string value)
{
    bool flag = false;
    std::map<std::string, float>::iterator it = this->database.begin();

    while (it != this->database.end())
    {
        if (it->first == year)
        {
            std::cout << year << " => " << value << " = " << (it->second * std::stof(value)) << std::endl;
            flag = false;
            break;
        }
        it++;
        if (it == this->database.end())
            flag = true; 
    }
    if (flag)
    {
        it = this->database.lower_bound(year);
        if (it == this->database.begin()) {
            throw std::runtime_error("Error: closest date not found.");            return;
        }
        it--;
        std::cout << year << " => " << value << " = " << (it->second * std::stof(value)) << std::endl;
    }
}

