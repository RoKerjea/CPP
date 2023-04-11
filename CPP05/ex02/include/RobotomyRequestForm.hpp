#pragma once

#include "Aform.hpp"

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

	std::string getTarget();
	//virtual?
	void execute(Bureaucrat const &executor);
};