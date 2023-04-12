#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		//constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &ori);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm &ori);
		//getter
		std::string getTarget() const;
		//action
		void execAction();
};