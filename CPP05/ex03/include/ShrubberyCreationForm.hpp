#pragma once

#include "AForm.hpp"
#include <fstream>

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

	void execAction();
	std::string getTarget() const;
	//virtual?
};