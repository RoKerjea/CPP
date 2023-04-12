#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern&	Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm*	Intern::shrubbery ( std::string target )
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::robotomy ( std::string target )
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::pardon ( std::string target )
{
	return new PresidentialPardonForm(target);
}

int	Intern::identify_cases(std::string typetocreate)
{
	std::string type[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (typetocreate == type[i])
			return (i);
	}
	return (3);
}

typedef AForm*(Intern::*ptr_func)(std::string target);

AForm* Intern::makeForm(std::string typetocreate, std::string target)
{
	ptr_func functions[3] = {&Intern::shrubbery, &Intern::robotomy, &Intern::pardon};
	int cases = identify_cases(typetocreate);
	if (cases <= 3)
		return (this->*functions[cases])(target);
	std::cout << "wrong form requested\n";
	return NULL;
}