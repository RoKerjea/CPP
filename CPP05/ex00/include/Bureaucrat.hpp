#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>


class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned char	_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &ori);
		// Bureaucrat& operator=(const Bureaucrat &ori);

		Bureaucrat(std::string name, unsigned char grade);

		std::string	getName() const;
		unsigned char	getGrade() const;

		void	promote();
		void	demote();

		int	GradeTooHighException();
		int	GradeTooLowException();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &target);

#endif