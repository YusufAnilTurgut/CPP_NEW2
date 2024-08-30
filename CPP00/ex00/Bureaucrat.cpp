
#include "Bureaucrat.hpp"
#include <stdexcept>


Bureaucrat::Bureaucrat() : name("Default Name")
{
	this->grade = 0;
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : name(name)
{
	
	try {
        if (grade > 150) 
        {
            throw GradeTooHighException();
		}
		else if (grade < 1)
		{
            throw GradeTooLowException();
		}

		this->grade = grade;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
		this->grade = 150;
    }
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
	try
	{
		if (grade > 150)
			throw GradeTooHighException();
		else if (grade < 1)
			throw GradeTooLowException();

		this->grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		this->grade = 150;
	}
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
     return "Grade is too high!, grade must be between 1 < 150";
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
     return "Grade is too low!, frade must be between 1 < 150";
}