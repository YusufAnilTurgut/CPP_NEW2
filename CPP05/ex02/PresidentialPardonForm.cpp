#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Name", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm((target), 25, 5) , target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        this->target = rhs.target;  
    }
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->executer_control(executor))
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}