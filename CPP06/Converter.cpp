
#include "Converter.hpp"



ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { *this = copy; }
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs) { if (this == &rhs) { return (*this); } return (*this); }


int count(std::string str) // If Arg[0] has two words returns 1
{
    std::stringstream ss(str);
    int tmp;
    std::string tmp2;

    tmp = 0;
    if (!str[0])
        return (0);
    while (ss >> tmp2)
    {
        tmp++;
    }
    if (tmp > 1)
        return (0);
    return (1);
}

int	check_dot(std::string str)
{
	int	i = -1;

	while (str[++i])
	{
		if (str[i] == '.')
			return (1);
	}
	return (0);
}

int	check_f(std::string str)
{
	int	i = -1;

	while (str[++i])
	{
		if (str[i] == 'f')
			return (1);
	}
	return (0);
}

void	ScalarConverter::impossible(void)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: impossible" << std::endl;
	std::cout << "Double: impossible" << std::endl;
}

void	psuedo(std::string str)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: " << str << "f" << std::endl;
	std::cout << "Double: " << str << std::endl;
}

void	psuedof(std::string str)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: " << str << std::endl;
	std::cout << "Double: " << str.erase(str.length() - 1) << std::endl;
}

int is_str(std::string str) //If return 1 is str
{
    int i = -1;
    int fcounter = 0;
    int minus = 0;

    if(std::isalpha(str[0]) && str.length() > 1)
        return (1);
    if (str.length() == 1)
        return (0);
    if (str[0] == '.')
        return (1);
    while(str[++i])
    {
        if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != '-')
			return (1);
		if (str[i] == 'f')
			fcounter++;
		if (str[i] == '-')
			minus++;
		if (str[i] == '.' && (!std::isdigit(str[i + 1]) || (i && !std::isdigit(str[i - 1]))))
			return (1);
    }
    if (fcounter > 1 || minus > 1)
		return (1);
    return (0);
}

void	to_char(std::string str)
{
	char	c = str[0];
	std::cout << "Char: '" << static_cast<char>(c)<< "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c)<< ".0" << std::endl;
}

void	float_to(float f)
{
	if ((static_cast<char>(f) >= 32 && static_cast<char>(f) <= 126)) 
		std::cout << "Char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Char: " << "not displayble" << std::endl;
	std::cout << "Int: " << static_cast<int>(f) << std::endl;
	std::cout << "Float: " << f << "f" << std::endl;
	std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

void	double_to(double d)
{
	if ((static_cast<char>(d) >= 32 && static_cast<char>(d) <= 126)) 
		std::cout << "Char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Char: " << "not displayble" << std::endl;
	std::cout << "Int: " << static_cast<int>(d) << std::endl;
	std::cout << "Float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "Double: " << (d) << std::endl;
}

void	int_to(int i)
{
	if (i >= 32 && i <= 126)
		std::cout << "Char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Char: " << "not displayble" << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(i) << ".0" << std::endl;
}

float stringToFloat(const std::string &str) {
    std::stringstream ss(str);
    float result;
    ss >> result;
    return result;
}

double stringToDouble(const std::string &str) {
    std::stringstream ss(str);
    double result;
    ss >> result;
    return result;
}

int stringToInt(const std::string &str) {
    std::stringstream ss(str);
    int result;
    ss >> result;
    return result;
}

void	to_digits(std::string str)
{
	float	f;
	int		i;
	double	d;

	if (check_dot(str) && check_f(str))
	{
		f = stringToFloat(str);
		float_to(f);
	}
	else if (check_dot(str))
	{
		d = stringToDouble(str);
		double_to(d);
	}
	else
	{
		i = stringToInt(str);
		int_to(i);
	}
}


void	ScalarConverter::convert(std::string str)
{
	if (!count(str))
	{
		std::cout << "Count 0" << std::endl;
		ScalarConverter::impossible();
		return ;
	}
	if (str == "+inf" || str == "-inf" || str == "nan")
	{
		psuedo(str);
		return ;
	}
	else if (str == "+inff" || str == "-inff" || str == "nanf")
	{
		psuedof(str);
		return ;
	}
	if (is_str(str)) 
	{
		ScalarConverter::impossible();
		return ;
	}
	if (str.length() == 1 && std::isalpha(str[0]))
	{
		to_char(str);
		return ;
	}
	if (str == "0.0f" || str == "0.0")
	{
		int_to(0);
		return ;
	}
	to_digits(str);
}