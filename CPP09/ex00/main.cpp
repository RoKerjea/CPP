#include "BitcoinExchange.hpp"

int	main(int ac, char** av)
{
	try {
		BitcoinExchange be (ac, av);
		be.execute(av[1]);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return(0);
}
/*
need to check input file (is a file, is a .txt, etc.)
check format of file ("date | value") date is in format YEAR-Month-Day (xxxx-xx-xx)
value must be a float or int >= 0 and <= 1000
*/