
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Name")
{
	this->grade = 0;
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade) : name(name)
{
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
	this->grade = grade;
}