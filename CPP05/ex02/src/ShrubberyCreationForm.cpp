#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(Shrubbery, 145, 137)
{
	_target = "NoName";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(Shrubbery, 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ori) : AForm(Shrubbery, 145, 137)
{
	_target = ori.getTarget();
	signature = ori.getSigned();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm& operator=(const ShrubberyCreationForm &ori)
{
	this->_target = ori.getTarget();
	this->signature = ori.getSigned();
	return *this;
}

std::string	ShrubberyCreationForm::getTarget()
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{

}