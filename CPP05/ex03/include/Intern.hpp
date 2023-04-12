#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	private:
		int	identify_cases(std::string typetocrate);

		AForm*	shrubbery (std::string target);
		AForm*	robotomy (std::string target);
		AForm*	pardon (std::string target);

	public:
		//constructors
		Intern();
		Intern(Intern const &ori);
		~Intern();
		Intern& operator=(const Intern &ori);
		//actions
		AForm* makeForm(std::string type, std::string target);
};
