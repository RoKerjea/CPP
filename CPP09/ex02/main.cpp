
#include "PmergeMe.hpp"


bool    isPositiveNumeric (std::string const& s) {

	return (s.find_first_not_of ("0123456789") == std::string::npos);
}

int checkArgs(int ac, char** av)
{
	for (int i = 1; i < ac; i++)
	{
		if (!isPositiveNumeric (av [i]))
			return 1;
		if (std::atoll (av [i]) == 0 || std::atoll (av [i]) > std::numeric_limits <int>::max ())
			return 1;
	}
	return 0;
}

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./a.out [list of numbers]" << std::endl;
		return 1;
	}
	if (checkArgs(ac, av) == 1)
	{
		std::cout << "Invalid input" << std::endl;
		return 1;
	}
	PmergeMe pm(ac, av);
	pm.Print_vec();
	// pm.Print_lst();
	pm.Sort_vec();
	pm.Sort_lst();
}