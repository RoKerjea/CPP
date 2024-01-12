#include "Array.hpp"

int	main(void)
{
	Array<int> array1(5);
	array1[0] = 5;
	array1[1] = 5;
	array1[2] = 5;
	array1[3] = 5;
	array1[4] = 5;
	std::cout << array1 << std::endl;
	std::cout << "size: " << array1.size() << std::endl;
	try
	{
		array1[5] = 5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		array1[-1] = 5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Array<int> array2(array1);
	std::cout << array2 << std::endl;
	array2[0] = 10;
	std::cout <<"array2 after modification: " << array2 << std::endl;
	std::cout <<"array after modification of array2: "array1 << std::endl;
	//check size after deletion/addition

}