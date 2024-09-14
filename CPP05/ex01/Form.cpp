
#include "Form.hpp"

Form::Form() : name("Default Name"), sign(false), signGrade(150), execGrade(150)
{
}

Form::Form(std::string name, int signGrade, int execGrade) : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
    if(this->signGrade > 150 || this->execGrade > 150)
        throw GradeTooLowException();
    else if (this->signGrade < 1 || this->execGrade < 1) 
        throw GradeTooHighException();
}

Form::~Form()
{

}

Form::Form(const Form& old) : name(old.name), signGrade(old.signGrade), execGrade(old.execGrade)
{
	this->sign = old.sign;
}


Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		this->sign = rhs.sign;
	}
	return *this;
}

const std::string& 	Form::getName() const
{
	return this->name;
}

int 	Form::getSignGrade() const
{
	return this->signGrade;
}

int 	Form::getExecGrade() const
{
	return this->execGrade;
}

bool 	Form::getSign() const
{
	return this->sign;
}

std::ostream& operator << (std::ostream& os, const Form &arg)
{
    os << arg.getName() << ", Form sign grade " << arg.getSignGrade() << ", Form exec grade " << arg.getExecGrade() << ", Form signed " <<  arg.getSign()  << ".";
    return os;
}



void Form::beSigned(const Bureaucrat& br)
{


	if (br.getGrade() > this->signGrade)
	{
		throw GradeTooLowException();
	}
	this->sign = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low! Grade needs to be between 1 and 150";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High! Grade needs to be between 1 and 150";
}