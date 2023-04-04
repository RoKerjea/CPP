#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat bob = Bureaucrat("bob", 20);
	}
	catch(int status_num)
	{
		std::cout << "error num " << status_num << std::endl;
	}
	std::cout << "voici " << bob << "\n";
	return (0);
}