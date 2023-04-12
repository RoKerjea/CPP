#pragma once

#include "AForm.hpp"

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
		//getter
		std::string getTarget() const;
		//action
		void execAction();
};