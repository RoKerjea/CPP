#include "Bureaucrat.hpp"

// int	main(void)
// {
// 	try
// 	{
// 		Bureaucrat bob = Bureaucrat("bob", 160);
// 		std::cout << "voici " << bob << "\n";
// 	}
// 	catch(std::exception &e)
// 	{
// 		std::cout << "pb : " << e.what() << "\n";
// 	}
// 	return (0);
// }

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"

int main()
{
	{
		std::cout << RED << "Test des constructeurs (default, copy, string)" << RESET << std::endl;	
		try
		{
			std::cout << YELLOW << "creation sur la heap via Default Constructor (Default, 150)" << RESET << std::endl;
			Bureaucrat 		bureaucrat;
			std::cout << bureaucrat << std::endl;

			std::cout << YELLOW << "creation sur la heap via String Constructor (Assistant, 25)" << RESET << std::endl;
			Bureaucrat		assistant("Assistant", 25);
			std::cout << assistant << std::endl;

			std::cout << YELLOW << "creation sur la heap via Copy Constructor (-> Assistant_copy, 25" << RESET << std::endl;
			Bureaucrat 		secretary = assistant;
			std::cout << secretary << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << RED << "Test de la limite haute lors de la construction" << RESET << std::endl;	
		try
		{
			std::cout << YELLOW << "String Constructor (Bureaucrat, -42)" << RESET << std::endl;
			Bureaucrat 		bureaucrat("Bureaucrat", -42);
			std::cout << bureaucrat << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << RED << "Test de la limite basse lors de la construction" << RESET << std::endl;	
		try
		{
			std::cout << YELLOW << "String Constructor (Bureaucrat, 169)" << RESET << std::endl;
			Bureaucrat 		bureaucrat("Bureaucrat", 169);
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << RED << "Test des incrementations et decrementations de grade" << RESET << std::endl;	
		try
		{
			std::cout << YELLOW << "String Constructor (Bureaucrat, 25)" << RESET << std::endl;
			Bureaucrat 		bureaucrat1("Promotion", 25);
			bureaucrat1.promote();
			std::cout << bureaucrat1 << std::endl;

			std::cout << YELLOW << "String Constructor (Bureaucrat, 70)" << RESET << std::endl;
			Bureaucrat 		bureaucrat2("Placard", 70);
			bureaucrat2.demote();
			std::cout << bureaucrat2 << std::endl;

			std::cout << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << RED << "Test d'incrementation en limite haute" << RESET << std::endl;	
		try
		{
			std::cout << YELLOW << "String Constructor (Bureaucrat, 1)" << RESET << std::endl;
			Bureaucrat 		bureaucrat1("TheBestoftheYear", 1);
			bureaucrat1.promote();
			std::cout << bureaucrat1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << RED << "Test de decrementations en limite basse" << RESET << std::endl;	
		try
		{
			std::cout << YELLOW << "String Constructor (Bureaucrat, 150)" << RESET << std::endl;
			Bureaucrat 		bureaucrat1("WorthyofFiring", 150);
			bureaucrat1.demote();
			std::cout << bureaucrat1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}