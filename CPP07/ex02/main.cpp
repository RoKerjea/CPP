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
	//need to construct new array of x elements
	//fill array, access by [] to edit
	//try to acces wrong index in [] (-num and > max)
	//test array.size() to check if number of items is correct
	//check size after deletion/addition

}