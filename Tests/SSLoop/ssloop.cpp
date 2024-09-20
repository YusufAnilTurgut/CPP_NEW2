int main(int ac, char **args)
{
    std::stringstream ss;

    std::string input = "5 56.78 Hello";
    ss << args[1];
    std::string output;
    while(ss >> output)
    {
        std::cout << output << std::endl;;
    }
    if (ac == 2)
	{
		  std::cout << args[1] << std::endl;;
          std::cout << count(args[1]) << std::endl;
 	}
	else
		  std::cout << "Hello World" << std::endl;;
}