

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b1 = new Bureaucrat();
	std::cout << "Debug" << std::endl;
	std::cout << "b1 name : " << b1->getName() << std::endl;
	std::cout << "b1 grade : " << b1->getGrade() << std::endl;

	b1->setGrade(31);

	std::cout << "b1 name : " << b1->getName() << std::endl;
	std::cout << "b1 grade : " << b1->getGrade() << std::endl;

	Bureaucrat *b2 = new Bureaucrat("Anil", 22);

	std::cout << "b2 name : " << b2->getName() << std::endl;
	std::cout << "b2 grade : " << b2->getGrade() << std::endl;

	b1 = b2;

	std::cout << "b1 name : " << b1->getName() << std::endl;
	std::cout << "b1 grade : " << b1->getGrade() << std::endl;

	Bureaucrat *b3 = new Bureaucrat(*b1);

	std::cout << "b3 name : " << b3->getName() << std::endl;
	std::cout << "b3 grade : " << b3->getGrade() << std::endl;

	b3 = b2 = b1;
	return 0;
}
