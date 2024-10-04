

#include "RPN.hpp"

void clearAll(std::stack<int>& stck){
	while(stck.size() > 0)
    	stck.pop();
}


void calculate(std::stack<int>& stck, char symbol)
{
	int nbr = 0;
	if(stck.size() < 2)
	{
		clearAll(stck);
		throw  std::runtime_error("Error");
		
	}

	if (symbol == '+')
	{
		nbr = stck.top();
		stck.pop();
		nbr += stck.top();
		stck.pop();
		stck.push(nbr);  
	}
	else if (symbol == '-')
	{
		nbr = stck.top();
		stck.pop();
		nbr = stck.top() - nbr;
		stck.pop();
		stck.push(nbr);  
	}
	else if (symbol == '*')
	{
		nbr = stck.top();
		stck.pop();
		nbr = stck.top() * nbr;
		stck.pop();
		stck.push(nbr);  
	}
	else if (symbol == '/')
	{
		try
		{
			nbr = stck.top();
			stck.pop();
			nbr = stck.top() / nbr;
			stck.pop();
			stck.push(nbr);  
		}
		catch(std::exception& ep){
            std::cerr << ep.what() << std::endl;
            clearAll(stck);
            exit(1);
        }
	}
}


void reading(std::stack<int>& stck, std::string input)
{
    std::string symbols = "+-/*";
    for (size_t i = 0; i < input.length(); i++)
    {
        if(std::isspace(input[i]))
            continue;
        else if(std::isdigit(input[i]))
            stck.push(input[i] - '0');
        else if(symbols.find(input[i]) != std::string::npos)
            calculate(stck, input[i]);
        else{
            clearAll(stck);
            throw  std::runtime_error("Error");
        }
    }
}
