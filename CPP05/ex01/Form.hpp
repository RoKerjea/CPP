#ifndef FORM_HPP
# define FORM_HPP

class Form
{
	private:
		const std::string _name;
		bool	signature;
		const unsigned char signature_grade;
		const unsigned char execute_grade;
	public:
		//every constructor

		void	beSigned(Bureaucrat signatory);

		std::string	getName() const;
		bool	getSigned() const;
		unsigned char	getSignatureGrade() const;
		unsigned char	getExecuteGrade() const;
};

std::ostream& operator<<(std::ostream& out, const Form &target);

#endif