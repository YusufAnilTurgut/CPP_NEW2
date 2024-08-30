
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>



class Bureaucrat 
{
	protected:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& old);
		Bureaucrat& 		operator=(const Bureaucrat& rhs);
		const std::string& getName() const;
		int			getGrade() const;
		void 				setGrade(const int &grade);
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

#endif