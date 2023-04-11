#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm(Shrubbery, 145, 137)
{
	_target = "NoName";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(Shrubbery, 145, 137)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ori) : AForm(Shrubbery, 145, 137)
{
	_target = ori.getTarget();
	signature = ori.getSigned();
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm& operator=(const PresidentialPardonForm &ori)
{
	this->_target = ori.getTarget();
	this->signature = ori.getSigned();
	return *this;
}

std::string	PresidentialPardonForm::getTarget()
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{

}