#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool sign;
	const int signGrade;
	const int execGrade;

public:
	Form();
	Form(std::string name, int signGrade, int execGrade);
	~Form();
	Form(const Form& old);
	Form& operator=(const Form& rhs);
	const std::string&			getName() const;
	bool		getSign() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	void beSigned(const Bureaucrat& br);

	class GradeTooHighException : public std::exception
		{
			public:
				  virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
					virtual const char* what() const throw();
		};
	};

std::ostream& operator<<(std::ostream& os, const Form &arg);




#endif