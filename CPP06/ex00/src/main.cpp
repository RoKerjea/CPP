#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error, need exactly 1 argument\n";
		return (1);
	}
	ScalarConverter	conv;
	conv.convert(av[1]);
	return (0);
}