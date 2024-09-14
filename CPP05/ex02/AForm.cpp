
#include "AForm.hpp"

AForm::AForm() : name("Default Name"), sign(false), signGrade(150), execGrade(150)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
    if(this->signGrade > 150 || this->execGrade > 150)
        throw GradeTooLowException();
    else if (this->signGrade < 1 || this->execGrade < 1) 
        throw GradeTooHighException();
}

AForm::~AForm()
{

}

AForm::AForm(const AForm& old) : name(old.name), signGrade(old.signGrade), execGrade(old.execGrade)
{
	this->sign = old.sign;
}


AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		this->sign = rhs.sign;
	}
	return *this;
}

const std::string& 	AForm::getName() const
{
	return this->name;
}

int 	AForm::getSignGrade() const
{
	return this->signGrade;
}

int 	AForm::getExecGrade() const
{
	return this->execGrade;
}

bool 	AForm::getSign() const
{
	return this->sign;
}

std::ostream& operator << (std::ostream& os, const AForm &arg)
{
    os << arg.getName() << ", AForm sign grade " << arg.getSignGrade() << ", AForm exec grade " << arg.getExecGrade() << ", AForm signed " <<  arg.getSign()  << ".";
    return os;
}



void AForm::beSigned(const Bureaucrat& br)
{
    if (br.getGrade() > this->signGrade)
    {
        throw GradeTooLowException();
	}
	this->sign = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low! Grade needs to be between 1 and 150";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High! Grade needs to be between 1 and 150";
}

const char *AForm::FormNotSigned::what() const throw()
{
    return "Form is not signed!";
}



bool    AForm::executer_control(const Bureaucrat &executor) const
{
    if (this->getSign() == false)
        throw FormNotSigned();
    else if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    return true;
}