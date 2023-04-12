#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Bureaucrat's grade is too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Bureaucrat's grade is too low!");
}

Bureaucrat::Bureaucrat() : _name("noname")
{
	_grade = 150;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat &ori) : _name(ori.getName())
{
	_grade = ori.getGrade();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if(grade < 1)
		throw GradeTooHighException();
	if(grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ori)
{
	this->_grade = ori._grade;
	return *this;
}

void	Bureaucrat::promote()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::demote()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

bool	Bureaucrat::signForm(AForm const & formtosign) const
{
	if (getGrade() <= formtosign.getSignatureGrade())
	{
		std::cout << getName() << " signed " << formtosign.getName() << "\n";
		return (0);
	}
	else
	{
		std::cout << getName() << " couldn't sign " << formtosign.getName() << " because ";
		std::cout << "Grade too low to sign" << "\n";
	}
	return (1);
}

bool	Bureaucrat::executeForm(AForm const & form) const
{
	if (getGrade() <= form.getExecuteGrade())
	{
		std::cout << getName() << " executed " << form.getName() << "\n";
		return (0);
	}
	else
	{
		std::cout << getName() << " couldn't execute " << form.getName() << " because ";
		std::cout << "Grade too low to execute" << "\n";
	}
	return (1);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &target)
{
	out << target.getName() << ", bureaucrat grade " << target.getGrade();
	return out;
}
