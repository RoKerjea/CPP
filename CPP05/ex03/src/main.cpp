#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"

int main()
{
	std::cout << std::endl << GREEN << "//----------   TEST DES STAGIAIRES (INTERNS)   ----------//" << RESET << std::endl;

	std::cout << std::endl << RED << "intern creates form and lvl 1 signs and execute" << RESET << std::endl;
	std::cout << std::endl << YELLOW << "test Presidential pardon" << RESET << std::endl;
	{
		Intern	randomIntern;
		AForm	*form;

		form = NULL;
		std::cout << std::endl;
		try
		{
			form = randomIntern.makeForm("presidential pardon", "Bender");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		if (form != NULL)
		{
			Bureaucrat executor("Minister of Magic", 1);
			std::cout << std::endl;
			try
			{
				form->beSigned(executor);
				form->execute(executor);
			}
			catch (std::exception &e)
			{
				std::cout << executor.getName() << " : " << e.what() << form->getName() << std::endl;
			}
			std::cout << std::endl;
			delete form;
		}
	}
	std::cout << std::endl << YELLOW << "test Robotomy Request" << RESET << std::endl;
	{
		Intern	randomIntern;
		AForm	*form;

		form = NULL;
		std::cout << std::endl;
		try
		{
			form = randomIntern.makeForm("robotomy request", "C3P0");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		if (form != NULL)
		{
			Bureaucrat executor("Jabba the Hutt", 1);
			std::cout << std::endl;
			try
			{
				form->beSigned(executor);
				form->execute(executor);
			}
			catch (std::exception &e)
			{
				std::cout << executor.getName() << " : " << e.what() << form->getName() << std::endl;
			}
			std::cout << std::endl;
			delete form;
		}
	}
	std::cout << std::endl << YELLOW << "test Shrubbery Creation" << RESET << std::endl;
	{
		Intern	randomIntern;
		AForm	*form;

		form = NULL;
		std::cout << std::endl;
		try
		{
			form = randomIntern.makeForm("shrubbery creation", "Parc_Municipal");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		if (form != NULL)
		{
			Bureaucrat executor("Ministre de l'agriculture", 1);
			std::cout << std::endl;
			try
			{
				form->beSigned(executor);
				form->execute(executor);
			}
			catch (std::exception &e)
			{
				std::cout << executor.getName() << " : " << e.what() << form->getName() << std::endl;
			}
			std::cout << CYAN << "file created !" << RESET << std::endl << std::endl;
			delete form;
		}
	}
	std::cout << std::endl << YELLOW << "test error" << RESET << std::endl;
	{
		Intern	randomIntern;
		AForm	*form;

		form = NULL;
		std::cout << std::endl;
		try
		{
			form = randomIntern.makeForm("shdgshgoshg", "Bender");
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		if (form != NULL)
		{
			Bureaucrat executor("Minister of Magic", 1);
			std::cout << std::endl;
			try
			{
				form->beSigned(executor);
				form->execute(executor);
			}
			catch (std::exception &e)
			{
				std::cout << executor.getName() << " : " << e.what() << form->getName() << std::endl;
			}
			std::cout << std::endl;
			delete form;
		}
	}
	return (0);
}