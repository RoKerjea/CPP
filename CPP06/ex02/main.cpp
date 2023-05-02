#include "Base.hpp"

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"

Base *generate(void)
{
	srand(time(NULL));
	int	r = rand() % 3;
	Base *base;
	switch(r)
	{
		case 0:
			base = new A;
			return (base);
		case 1:
			base = new B;
			return (base);
		case 2:
			base = new C;
			return (base);
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Le Downcast de Base en A est possible, donc on a généré une classe A !" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Le Downcast de Base en B est possible, donc on a généré une classe B !" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Le Downcast de Base en C est possible, donc on a généré une classe C !" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Le Downcast de Base en A est possible, donc on a généré une classe A !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Downcast impossible, ce n'est pas une classe A !" << std::endl;
	}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Le Downcast de Base en B est possible, donc on a généré une classe B !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Downcast impossible, ce n'est pas une classe B !" << std::endl;
	}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Le Downcast de Base en C est possible, donc on a généré une classe C !" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Downcast impossible, ce n'est pas une classe C !" << std::endl;
	}
}

int	main()
{
	Base	*newBase = generate();

	std::cout << std::endl;
	identify(newBase);

	std::cout << std::endl;
	identify(*newBase);

	delete newBase;
	return (0);
}