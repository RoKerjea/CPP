#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error, need exactly 1 argument\n";
		return (1);
	}
	ScalarConverter::get().convert(av[1]);
	ScalarConverter::get().destruct();
	return (0);
}