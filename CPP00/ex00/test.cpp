

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b1 = new Bureaucrat();
	std::cout << "Debug" << std::endl;
	std::cout << "b1 name : " << b1->getName() << std::endl;
	std::cout << "b1 grade : " << b1->getGrade() << std::endl;

	b1->setGrade(500);

	std::cout << "b1 grade : " << b1->getGrade() << std::endl;

	Bureaucrat *b2 = new Bureaucrat("Anil", 500);

	std::cout << "b2 grade : " << b2->getGrade() << std::endl;

	Bureaucrat *b3 = new Bureaucrat("Anil", 20);

	std::cout << "b3 grade : " << b3->getGrade() << std::endl;

	return 0;
}
