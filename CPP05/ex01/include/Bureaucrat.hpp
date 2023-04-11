#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
	public:
		//constructors
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &ori);
		Bureaucrat& operator=(const Bureaucrat &ori);
		Bureaucrat(std::string name, int grade);
		//getter
		std::string	getName() const;
		int	getGrade() const;
		//setter
		void	promote();
		void	demote();
		//methods
		bool	signForm(Form formtosign);
	//exceptions
	class GradeTooHighException : public std::exception{
		public :
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public :
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &target);
