#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool	signature;
		const int _signature_grade;
		const int _execute_grade;

		void	checkgrade();
	public:
		//every constructor
		AForm();
		AForm(const AForm &ori);
		AForm(std::string name, int signature_grade, int execute_grade);
		~AForm();
		AForm& operator=(const AForm &ori);

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

std::ostream& operator<<(std::ostream& out, const AForm &target);

//Notes:
//AForm use a Bureaucrat to be signed, bureaucrate internal method is used to check
//if he is allowed to.
//but Bureaucrate use the AForm to execute it?