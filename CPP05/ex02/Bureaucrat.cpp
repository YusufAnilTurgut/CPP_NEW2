
#include "Bureaucrat.hpp"
#include <stdexcept>


Bureaucrat::Bureaucrat() : name("Default Name")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : name(name)
{

    if (grade < 1) 
    {
        throw GradeTooHighException();
	}
	else if (grade > 150)
	{
        throw GradeTooLowException();
	}

	this->grade = grade;
}


Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& old) : name(old.name)
{
	this->grade = old.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		this->grade = rhs.grade;
	}
	return *this;
}


std::ostream& operator << (std::ostream& os, const Bureaucrat &arg)
{
    os << arg.getName() << ", bureaucrat grade " << arg.getGrade() << ".";
    return os;
}

const std::string& 	Bureaucrat::getName() const
{
	return this->name;
}

int 	Bureaucrat::getGrade() const
{
	return this->grade;
}

void			Bureaucrat::setGrade(const int &grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();

	this->grade = grade;	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
     return "Grade is too high!, grade must be between 1 < 150";
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
     return "Grade is too low!, grade must be between 1 < 150";
}

void Bureaucrat::increment(void)
{
	int currentGrade = this->getGrade();
	currentGrade--;
	this->setGrade(currentGrade);
}

void Bureaucrat::decrement(void)
{
	int currentGrade = this->getGrade();
	currentGrade++;
	this->setGrade(currentGrade);
}

void Bureaucrat::signAForm(AForm &AForm)
{
    if (AForm.getSign() == false)
    {
        try
        {
            AForm.beSigned(*this);   
			std::cout << this->getName() << " signed " << AForm.getName() << std::endl; 
        }
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
     
    }
    else
        std::cout  << this->getName() << " couldn't sign " << AForm.getName() << " because AForm already signed!" << std::endl;
}

void    Bureaucrat::executeForm(AForm const &AForm)
{
	try 
	{
    	AForm.execute(*this);
		std::cout << this->getName() << " executed " << AForm.getName() << std::endl;
	}
    catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}