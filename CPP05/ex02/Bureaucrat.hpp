
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat 
{
	protected:
		const std::string name;
		int grade;
		void 				setGrade(const int &grade);
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& old);
		Bureaucrat& 		operator=(const Bureaucrat& rhs);
		const std::string& getName() const;
		int			getGrade() const;
		void increment(void);
		void decrement(void);
		void signAForm(AForm &AForm);
		void executeForm(AForm const &form);
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


std::ostream& operator<<(std::ostream& os, const Bureaucrat &arg);

std::ostream& operator<<(std::ostream& os, const Bureaucrat &arg);
#endif