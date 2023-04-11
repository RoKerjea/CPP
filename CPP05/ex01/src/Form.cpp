#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return("Form's grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Form's grade is too low!");
}

Form::Form():_name("noname"), _signature_grade(1), _execute_grade(1)
{
	signature = 0;
}

Form::~Form(){}

Form::Form(std::string name, int signature_grade, int execute_grade) :
_name(name),
_signature_grade(signature_grade),
_execute_grade(execute_grade)
{
	signature = 0;
	checkgrade();
}

Form::Form(const Form &ori) :
_name(ori.getName()),
_signature_grade(ori.getSignatureGrade()),
_execute_grade(ori.getExecuteGrade())
{
	signature = ori.getSigned();
}

Form& Form::operator=(const Form &ori)
{
	this->signature = ori.signature;
	return *this;
}

void	Form::checkgrade()
{
	if (_signature_grade > 150 || _execute_grade > 150)
		throw GradeTooLowException();
	if (_signature_grade < 1 || _execute_grade < 1)
		throw GradeTooHighException();
}

void	Form::beSigned(Bureaucrat target)
{
	//need to use target->signForm(getSignatureGrade())
	if(target.signForm(*this) != 0)
		throw GradeTooLowException();
	signature = 1;
}

std::string const Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->signature);
}

int Form::getSignatureGrade(void) const
{
	return (this->_signature_grade);
}

int Form::getExecuteGrade(void) const
{
	return (this->_execute_grade);
}

std::ostream& operator<<(std::ostream& out, const Form &target)
{
	std::cout <<"Form : "<< target.getName() << " need grade " << target.getSignatureGrade() << " to be signed, ";
	std::cout << (int)target.getExecuteGrade() << " to be executed. Is signed : " << target.getSigned() << std::endl;
	return out;
}