

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{

	try 
	{
		

		Bureaucrat *b1 = new Bureaucrat();
		std::cout << "b1 name : " << b1->getName() << std::endl;
		std::cout << "b1 grade : " << b1->getGrade() << std::endl;

		Bureaucrat *b2 = new Bureaucrat("b2", 1);
		std::cout << "b2 name : " << b2->getName() << std::endl;
		std::cout << "b2 grade : " << b2->getGrade() << std::endl;

		PresidentialPardonForm *ppf1 = new PresidentialPardonForm();
		std::cout << *ppf1 << std::endl;
		b2->signAForm(*ppf1);
		ppf1->execute(*b2);

		PresidentialPardonForm *ppf2 = new PresidentialPardonForm("Target 2");
		std::cout << *ppf2 << std::endl;
		b2->signAForm(*ppf2);
		ppf2->execute(*b2);
		
		delete ppf2;
		delete ppf1;

		RobotomyRequestForm *rrf1 = new RobotomyRequestForm();
		b2->signAForm(*rrf1);
		rrf1->execute(*b2);
		std::cout << *rrf1 << std::endl;

		RobotomyRequestForm *rrf2 = new RobotomyRequestForm("Target 3"); //72 45
		std::cout << *rrf2 << std::endl;


		b1->signAForm(*rrf2);
		b2->signAForm(*rrf2);
		rrf1->execute(*b1);
		rrf1->execute(*b2);
		delete rrf2;
		delete rrf1;

		delete b1;
		delete b2;
		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}




	return 0;
}
