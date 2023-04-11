#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool	signature;
		const int _signature_grade;
		const int _execute_grade;

		void	checkgrade();
	public:
		//every constructor
		Form();
		Form(const Form &ori);
		Form(std::string name, int signature_grade, int execute_grade);
		~Form();
		Form& operator=(const Form &ori);

		//setter
		void	beSigned(Bureaucrat signatory);

		//getter
		std::string const getName() const;
		bool	getSigned() const;
		int	getSignatureGrade() const;
		int	getExecuteGrade() const;

		//exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form &target);

//Notes:
//Form use a Bureaucrat to be signed, bureaucrate internal method is used to check
//if he is allowed to.
//but Bureaucrate use the Form to execute it?