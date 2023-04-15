#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"
#define LOG(x) 	std::cout << "\n\033[34m<> " << x << " <>\033[0m\n";
#define LOGN(x) std::cout << x;
int main()
{
	srand(time(NULL));

	LOG("TEST 1 : GradeTooHighException : init too high")
	try {
		Bureaucrat max = Bureaucrat("max", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 2 : GradeTooLowException : init too low")
	try {
		Bureaucrat ash = Bureaucrat("ash", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 3 : GradeTooHighException : promote limit")
	try {
		Bureaucrat joe = Bureaucrat("joe", 3);
		std::cout << joe << std::endl;
		joe.promote();
		joe.promote();
		joe.promote();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 4 : GradeTooLowException : demote limit")
	try {
		Bureaucrat mia = Bureaucrat("mia", 148);
		std::cout << mia << std::endl;
		mia.demote();
		mia.demote();
		mia.demote();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	LOG("TEST 5 : Bureaucrat accessors")
	try {
		Bureaucrat paul = Bureaucrat("paul", 42);

		std::cout << "getName() : " << paul.getName() << std::endl;
		std::cout << "getGrade(): " << paul.getGrade() << std::endl;
		std::cout << "operator<<: " << paul << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	{
		LOG("TEST 9  : ShrubberyCreationForm::")

		Bureaucrat	obelix	= Bureaucrat("Obelix", 146);
		Bureaucrat	asterix = Bureaucrat("Asterix", 136);
		AForm* A38 = new ShrubberyCreationForm("Home");

		std::cout << *A38 << std::endl;
		try{
		A38->execute(obelix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}

		try{
		A38->beSigned(asterix);
		A38->execute(obelix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}

		try{
		A38->execute(asterix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}
		delete A38;
	}
	{
		LOG("TEST 10 : RobotomyRequestForm::")

		Bureaucrat	obelix	= Bureaucrat("Obelix", 73);
		Bureaucrat	asterix = Bureaucrat("Asterix", 44);
		AForm*	A38 = new RobotomyRequestForm("Detritus");
		std::cout << *A38 << std::endl;
		try{
		A38->execute(obelix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}

		try{
		A38->beSigned(asterix);
		A38->execute(obelix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}

		try{
		A38->execute(asterix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}
		try{
		for (int i = 0; i < 10; i++)
			A38->execute(asterix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}
		delete A38;
	}
	{
		LOG("TEST 11 : PresidentialPardonForm::")

		Bureaucrat	obelix	= Bureaucrat("Obelix", 26);
		Bureaucrat	asterix = Bureaucrat("Asterix", 4);
		AForm*	A38 = new PresidentialPardonForm("Brutus");
		std::cout << *A38 << std::endl;
		try{
		A38->execute(obelix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}

		try{
		A38->beSigned(asterix);
		A38->execute(obelix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}

		try{
		A38->execute(asterix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}
		delete A38;
	}
	{
		LOG("TEST 11 : Generic Form::")
		Bureaucrat	obelix	= Bureaucrat("Obelix", 26);
		Bureaucrat	asterix = Bureaucrat("Asterix", 4);
		AForm*	A38 = new AForm("kbis", 150, 150);
		std::cout << *A38 << std::endl;
		try{
		A38->beSigned(asterix);
		A38->execute(asterix);
		}
		catch (AForm::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
		}
		catch (AForm::NotSignedException &e) {
		std::cerr << e.what() << std::endl;
		}
		delete A38;
	}
	std::cout << std::endl;
	return 0;
}