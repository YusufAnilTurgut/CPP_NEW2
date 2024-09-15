

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{

	try 
	{
		

		Bureaucrat *b1 = new Bureaucrat();
		std::cout << *b1 << std::endl;

		Bureaucrat *b2 = new Bureaucrat("b2", 5);
		std::cout << *b2 << std::endl;

		PresidentialPardonForm *ppf1 = new PresidentialPardonForm();
		std::cout << *ppf1 << std::endl;
		b2->signAForm(*ppf1);
		std::cout << *ppf1 << std::endl;
		ppf1->execute(*b2);

		PresidentialPardonForm *ppf2 = new PresidentialPardonForm("Target 2");
		std::cout << *ppf2 << std::endl;
		b2->signAForm(*ppf2);
		b2->signAForm(*ppf2);
		ppf2->execute(*b2);
		
		delete ppf2;
		delete ppf1;

		RobotomyRequestForm *rrf1 = new RobotomyRequestForm();
		b2->signAForm(*rrf1);
		b2->signAForm(*rrf1);
		b2->executeForm(*rrf1);
		std::cout << *rrf1 << std::endl;

		RobotomyRequestForm *rrf2 = new RobotomyRequestForm("Target 3"); 
		std::cout << *rrf2 << std::endl;


		b2->signAForm(*rrf2);
		b1->signAForm(*rrf2);
		b2->executeForm(*rrf2);
		delete rrf2;
		delete rrf1;

		ShrubberyCreationForm *scf1 = new ShrubberyCreationForm();
		std::cout << *scf1 << std::endl;


		ShrubberyCreationForm *scf2 = new ShrubberyCreationForm("Tartget Shu");
		std::cout << *scf2 << std::endl;	

		b1->signAForm(*scf2);
		b2->signAForm(*scf2);
		b2->signAForm(*scf2);
		b1->executeForm(*scf2);
		b2->executeForm(*scf2);

		delete scf1;
		delete scf2;
		std::cout << "End Of Code" << std::endl;
		delete b1;
		delete b2;
		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}




	return 0;
}
