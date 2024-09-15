
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137) , target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        this->target = rhs.target;  
    }
    return *this;
}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (this->executer_control(executor))
    {
        std::ofstream file(this->target + "_shrubbery");

        file << "              ,@@@@@@@," << std::endl;
        file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
        file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
        file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
        file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
        file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
        file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
        file << "       |o|        | |         | |" << std::endl;
        file << "       |.|        | |         | |" << std::endl;
        file << "\\\\/ .\\_\\/\\_/__/  ,\\_//__\\\\/.  \\_//__/" << std::endl;

        file.close();
    }
    
}