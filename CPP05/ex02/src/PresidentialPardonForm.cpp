#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Pardon", 25, 5)
{
	_target = "NoName";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Pardon", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ori) : AForm("Pardon", 25, 5)
{
	_target = ori.getTarget();
	signature = ori.getSigned();
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ori)
{
	_target = ori.getTarget();
	signature = ori.getSigned();
	return *this;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execAction()
{
	std::cout << "You are, by the present announce, informed that " << getTarget() << "\n";
	std::cout << "has been graciously pardoned by Zaphod Beeblebrox!\n";
}