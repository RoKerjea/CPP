#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm(Shrubbery, 145, 137)
{
	_target = "NoName";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(Shrubbery, 145, 137)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ori) : AForm(Shrubbery, 145, 137)
{
	_target = ori.getTarget();
	signature = ori.getSigned();
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm& operator=(const RobotomyRequestForm &ori)
{
	this->_target = ori.getTarget();
	this->signature = ori.getSigned();
	return *this;
}

std::string	RobotomyRequestForm::getTarget()
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)
{

}