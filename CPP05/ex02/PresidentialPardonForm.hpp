#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const std::string &);
        PresidentialPardonForm(const PresidentialPardonForm &);
        PresidentialPardonForm &operator = (const PresidentialPardonForm &);

        void    execute(Bureaucrat const & executor) const;
        
};

#endif