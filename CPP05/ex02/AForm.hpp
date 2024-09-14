#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool sign;
	const int signGrade;
	const int execGrade;

public:
	AForm();
	AForm(std::string name, int signGrade, int execGrade);
	virtual ~AForm();
	AForm(const AForm& old);
	AForm& operator=(const AForm& rhs);
	const std::string&			getName() const;
	bool		getSign() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	void beSigned(const Bureaucrat& br);
	virtual void execute(Bureaucrat const & executor) const = 0;
	bool    executer_control(const Bureaucrat &executor) const;
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
		class FormNotSigned: public std::exception
        {
            public:
                virtual const char *what()const throw();
        };
	};

std::ostream& operator<<(std::ostream& os, const AForm &arg);




#endif