#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(std::string name, unsigned char grade) : _name(name)
{
	if(grade < 1)
		throw GradeTooHighException();
	if(grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

// Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ori)
// {
// 	//need destructor then copy constructor??
// 	this->~Bureaucrat();
// 	this = Bureaucrat(ori);
// 	return *this;
// }

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

int	Bureaucrat::GradeTooHighException()
{
	std::cout << "Grade too high\n" ;
	return (1);
}

int	Bureaucrat::GradeTooLowException()
{
	std::cout << "Grade too low\n" ;
	return (2);
}

unsigned char	Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &target)
{
	out << target.getName() << ", bureaucrat grade " << (int)target.getGrade();
	return out;
}
