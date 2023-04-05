#include "Form.hpp"

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
	//destroy this, this = Form(ori), return *this?
}

int	Form::GradeTooLowException()
{}

int	Form::GradeTooHighException()
{}

void	Form::beSigned(Bureaucrat *target)
{
	//need to use target->signForm(getSignatureGrade())
	if(target->signForm(getSignatureGrade()) != 0)
		throw GradeTooLowException();
	signed = 1;
}

std::ostream& operator<<(std::ostream& out, const Form &target)
{
	std::cout <<"Form : " target.getName() << " need grade " << target.getSignatureGrade() << " to be signed, ";
	std::cout << (int)target.getExecuteGrade() << "to be executed. Is signed : " << target.getSigned() << std::endl;
	return out;
}