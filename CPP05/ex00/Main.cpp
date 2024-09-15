

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{

	try 
	{
	////////////////////////////////////////////////////
	
	Bureaucrat *b3 = new Bureaucrat("b3", 0); // 151 && 0
	 std::cout << *b3 << std::endl;
	
	Bureaucrat *b1 = new Bureaucrat();
	std::cout << "b1 name : " << b1->getName() << std::endl;
	std::cout << "b1 grade : " << b1->getGrade() << std::endl;

	Bureaucrat *b2 = new Bureaucrat("b2", 100);
	std::cout << "b2 name : " << b2->getName() << std::endl;
	std::cout << "b2 grade : " << b2->getGrade() << std::endl;

	Bureaucrat *b6 = new Bureaucrat(*b2);
	std::cout << "b6 name : " << b6->getName() << std::endl;
	std::cout << "b6 grade : " << b6->getGrade() << std::endl;
	
	*b6 = *b1;

	std::cout << "b6 name : " << b6->getName() << std::endl;
	std::cout << "b6 grade : " << b6->getGrade() << std::endl;

	*b6 = *b2 = *b1;

	std::cout << "b1 name : " << b1->getName() << std::endl;
	std::cout << "b1 grade : " << b1->getGrade() << std::endl;

	std::cout << "b2 name : " << b2->getName() << std::endl;
	std::cout << "b2 grade : " << b2->getGrade() << std::endl;

	std::cout << "b6 name : " << b6->getName() << std::endl;
	std::cout << "b6 grade : " << b6->getGrade() << std::endl;
	// //////////////////////////////////////////////////////////

	// Decrement
	Bureaucrat *b7 = new Bureaucrat("b7", 150);
	std::cout << "b7 grade : " << b7->getGrade() << std::endl;
	std::cout << "b7 grade : " << b7->getGrade() << std::endl;
	b7->decrement();

	//Increment
	Bureaucrat *b5 = new Bureaucrat("b5", 1);
	std::cout << "b5 name : " << b5->getName() << std::endl;
	std::cout << "b5 grade : " << b5->getGrade() << std::endl;
	b5->increment();

	/////////////////////////////////////////////////////////

	std::cout << *b1 << std::endl;
	std::cout << *b2 << std::endl;
	delete b1;
	delete b2;
	delete b6;
	delete b7;
	delete b5;
	std::cout << "End Of Code" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
