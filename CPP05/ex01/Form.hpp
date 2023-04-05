#ifndef FORM_HPP
# define FORM_HPP

class Form
{
	private:
		const std::string _name;
		bool	signature;
		const int _signature_grade;
		const int _execute_grade;
	public:
		//every constructor
		Form();
		Form(const Form &ori);
		Form(std::string name, int signature_grade, int execute_grade);
		~Form();
		Form& operator=(const Form &ori);

		void	beSigned(Bureaucrat signatory);

		std::string	getName() const;
		bool	getSigned() const;
		int	getSignatureGrade() const;
		int	getExecuteGrade() const;

		int	GradeTooHighException();
		int	GradeTooLowException();
};

std::ostream& operator<<(std::ostream& out, const Form &target);

#endif

//Notes:
//Form use a Bureaucrat to be signed, bureaucrate internal method is used to check
//if he is allowed to.
//but Bureaucrate use the Form to execute it?