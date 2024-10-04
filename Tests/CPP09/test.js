
#include <fstream>
#include <iostream>
#include <string>
#include <map>

int main()
{
	// std::ifstream data("data.csv");
	// std::string line;

	// int  i = 0;
	// while(getline(data, line))
	// {
	// 	i++;
	// 	std::cout << "Line " << i << " :" << line << std::endl;
	// }
	// data.close();
	// std::cout << "End Of Code" << std::endl;

	std::map<std::string, int> mp;

	// 2009-01-02,0
	// 2009-01-05,0
	// 2009-01-08,0
	// 2009-01-11,0
	// 2009-01-14,0
	// 2009-01-17,0
	// 2009-01-20,0

	mp["2009-01-02"] = 1;
	mp["2009-01-04"] = 2;
	mp["2009-01-07"] = 2;
	mp["2009-01-09"] = 2;

	std::map<std::string, int>::iterator it = mp.begin();
	while (it != mp.end())
	{
		std::cout << "Key : " << it->first << std::endl;
		std::cout << "Data : " << it->second << std::endl;
		it++;
	}
	// std::string test = "hello world";
	// std::cout << "Key : " << test.substr(0,4) << std::endl;
	// std::cout << "Key : " << test.substr(4) << std::endl;

	// mp.insert(std::make_pair(test.substr(6), 5));
	// std::cout << mp["world"] << std::endl;

	std::map<std::string, int>::iterator it2 = mp.lower_bound("2009-01-08");
	it2--;
	std::cout << "Key : " << it2->first << std::endl;
	std::cout << "Data : " << it2->second << std::endl;

}