#pragma once

#include "Aform.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
	//constructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &ori);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &ori);

	std::string getTarget();
	//virtual?
	void execute(Bureaucrat const &executor);
};