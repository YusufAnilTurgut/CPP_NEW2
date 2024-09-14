
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72,    45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45) , target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        this->target = rhs.target;  
    }
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if(this->executer_control(executor))
    {
        std::cout << "DRRDRDRDRDRDRDRDRDRDRRR" << std::endl;
        time_t current_time = time(NULL);
        if (current_time % 2 == 0)
            std::cout << this->target << " has been robotomize successfully" << std::endl;
        else
            std::cout << this->target << " has been robotomize failed" << std::endl;
    }
}