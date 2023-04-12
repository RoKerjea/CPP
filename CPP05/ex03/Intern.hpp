#pragma once

#include "Aform.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Aform;

class Intern
{
	public:
		//constructors
		Intern();
		Intern(Intern const &ori);
		~Intern();
		Intern& operator=(const Intern &ori);
		//actions
		Aform* makeForm(std::string type, std::string target);
};
