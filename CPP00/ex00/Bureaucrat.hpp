
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>


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
		
};

#endif