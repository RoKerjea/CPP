#include "iter.hpp"


int	main()
{
	int	intTab[10] = {1, 2, 3, 4, 5, 6 ,7 ,8, 9 ,10};
	std::string strTab[4] = {"un", "deux", "trois", "quatre"};

	std::cout << "INT ARRAY:\n" << std::endl;
	::iter(intTab, 10, &printer);

	std::cout << "\nINT ARRAY (after increment):\n" << std::endl;
	::iter(intTab, 10, &increment);
	::iter(intTab, 10, &printer);

	std::cout << "\nSTRING ARRAY:\n" << std::endl;
	::iter(strTab, 4, &printer);

	return 0;
}