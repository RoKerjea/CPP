#include "Span.hpp"

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"

int main()
{
	std::cout << std::endl << RED << "TEST DU SUJET : que des int positifs, ajout au container via addNumber" << RESET << std::endl;
	{
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "short :	" << sp.shortestSpan() << std::endl;
		std::cout << "long :	" << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl << RED << "TEST 1 : int positifs et negatifs, ajout au container via addNumber" << RESET << std::endl;
	{
		Span sp(7);

		sp.addNumber(-8);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(-2147483648);
		sp.addNumber(11);

		std::cout << "short :	" << sp.shortestSpan() << std::endl;
		std::cout << "long :	" << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl << RED << "TEST 2 : int positifs, ajout au container via boucle d'addNumber depassant la limite" << RESET << std::endl;
	{
		Span	span(3);
		int		i = 0;
		try
		{
			while (i < 10)
			{
				span.addNumber(i);
				i += 3;
			}
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "short :	" << span.shortestSpan() << std::endl;
			std::cout << "long :	" << span.longestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl << RED << "TEST 3 : ajout au container via range iterator" << RESET << std::endl;
	{
		try
		{
			std::vector<int>	tab;
			int					i = 0;

			std::cout << YELLOW << "1) cree un vector containeur de taille 100, dont les valeurs vont de 0 a 99" << RESET << std::endl;
			while (i < 100)
			{
				tab.push_back(i);
				i++;
			}
			// i = -1;
			// while (++i < 100)
			// 	std::cout << i << std::endl;

			std::cout << YELLOW << "2) cree un vector containeur via Classe Span : de taille 105, on remplit les 100 premieres entrees avec addRange" << RESET << std::endl;
			Span	rangespan(105);

			rangespan.addRange(tab.begin(), tab.end());

			std::cout << "short :	" << rangespan.shortestSpan() << std::endl;
			std::cout << "long :	" << rangespan.longestSpan() << std::endl;

			std::cout << YELLOW << "3)test : on ajoute qq nb (dont un en trop...) avec addNumber (min -42, max 1000)" << RESET << std::endl;
			try
			{
				rangespan.addNumber(-25);
				rangespan.addNumber(515);
				rangespan.addNumber(1000);
				rangespan.addNumber(-42);
				rangespan.addNumber(210);
				rangespan.addNumber(-300);//en trop, cause une exception
			}
			catch(std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			try
			{
				std::cout << "short :	" << rangespan.shortestSpan() << std::endl;
				std::cout << "long :	" << rangespan.longestSpan() << std::endl;
			}
			catch(std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}