#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return("AForm's grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("AForm's grade is too low!");
}

AForm::AForm():_name("noname"), _signature_grade(1), _execute_grade(1)
{
	signature = 0;
}

AForm::~AForm(){}

AForm::AForm(std::string name, int signature_grade, int execute_grade) :
_name(name),
_signature_grade(signature_grade),
_execute_grade(execute_grade)
{
	signature = 0;
	checkgrade();
}

AForm::AForm(const AForm &ori) :
_name(ori.getName()),
_signature_grade(ori.getSignatureGrade()),
_execute_grade(ori.getExecuteGrade())
{
	signature = ori.getSigned();
}

AForm& AForm::operator=(const AForm &ori)
{
	this->signature = ori.signature;
	return *this;
}

void	AForm::checkgrade()
{
	if (_signature_grade > 150 || _execute_grade > 150)
		throw GradeTooLowException();
	if (_signature_grade < 1 || _execute_grade < 1)
		throw GradeTooHighException();
}

void	AForm::beSigned(Bureaucrat target)
{
	//need to use target->signAForm(getSignatureGrade())
	if(target.signForm(*this) != 0)
		throw GradeTooLowException();
	signature = 1;
}

std::string const AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->signature);
}

int AForm::getSignatureGrade(void) const
{
	return (this->_signature_grade);
}

int AForm::getExecuteGrade(void) const
{
	return (this->_execute_grade);
}

std::ostream& operator<<(std::ostream& out, const AForm &target)
{
	std::cout <<"AForm : "<< target.getName() << " need grade " << target.getSignatureGrade() << " to be signed, ";
	std::cout << (int)target.getExecuteGrade() << " to be executed. Is signed : " << target.getSigned() << std::endl;
	return out;
}