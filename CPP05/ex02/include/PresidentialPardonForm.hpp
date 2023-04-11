#pragma once

#include "Aform.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
	//constructors
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &ori);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm &ori);

	std::string getTarget();
	//virtual?
	void execute(Bureaucrat const &executor);
};