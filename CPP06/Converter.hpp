
#ifndef CONVERTER_HPP
#define  CONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>


class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &rhs);
    public:
        static void convert(std::string str);
        static void impossible(void);
};

#endif