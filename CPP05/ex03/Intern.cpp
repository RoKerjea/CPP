#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}


Aform*	Intern::shrubbery ( std::string target )
{
	return()
}

Aform*	Intern::robotomy ( std::string target )
{
}

Aform*	Intern::pardon ( std::string target )
{
}

int	identifiy_cases (std::string typetocreate)
{
	std::string type[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (typetocreate == type[i])
			return (i);
	}
	return (3);
}

typedef void(Intern::*ptr_func)(void);

Aform* Intern::makeForm(std::string typetocreate, std::string target)
{
	ptr_func functions[3] = {&Intern::shrubbery, &Intern::robotomy, &Intern::pardon};
	int cases = identifiy_cases (typetocreate);
	if (cases <= 3)
		return (this->*functions[cases])(target);
	std::cout << "wrong form requested\n";
	return NULL;
}