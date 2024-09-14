
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class   ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &);
        ShrubberyCreationForm(const ShrubberyCreationForm &);
        ShrubberyCreationForm &operator = (const ShrubberyCreationForm &);

        void    execute(Bureaucrat const & executor) const;
};

#endif