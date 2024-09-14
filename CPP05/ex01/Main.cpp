

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try 
	{

		////////////////////////////////////////////////////
		

		Bureaucrat *b1 = new Bureaucrat();

		Bureaucrat *b2 = new Bureaucrat("b2", 5);
		
		
		Form *f1 = new Form();
		std::cout << *f1 << std::endl;

		Form *f2 = new Form("f2", 100, 120);
		std::cout << *f2 << std::endl;

		Form *f3 = new Form("f3", 5, 5);
		std::cout << *f3 << std::endl;


		
		std::cout << *f3 << std::endl;

		Bureaucrat *b8 = new Bureaucrat("b8", 6);
		std::cout << "b8 name : " << b8->getName() << std::endl;
		std::cout << "b8 grade : " << b8->getGrade() << std::endl;
		b8->signForm(*f3);
 		//f3->beSigned(*b8);
		// b8->signForm(*f2);

		std::cout << "End of Code" << std::endl;
		delete b1;
		delete b2;
		delete b8;
		
		delete f1;
		delete f2; 
		delete f3;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
