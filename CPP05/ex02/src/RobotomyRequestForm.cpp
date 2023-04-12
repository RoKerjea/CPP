#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45)
{
	_target = "NoName";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ori) : AForm("Robotomy", 72, 45)
{
	_target = ori.getTarget();
	signature = ori.getSigned();
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &ori)
{
	_target = ori.getTarget();
	signature = ori.getSigned();
	return *this;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execAction()
{
	std::cout << "VRRRRZZZZZZZZZZZZ" << std::endl;
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully";
	else
		std::cout << getTarget() << " robotomy failed";
}
