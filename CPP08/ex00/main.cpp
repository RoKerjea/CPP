#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	std::vector<int> nums;
	for(int i = 0; i < 20; i++)
		nums.push_back(i);
	std::cout << "found : " << *easyfind(nums, 5) << " in vector!\n";
	std::cout << "found : " << *easyfind(nums, 0) << " in vector!\n";
	std::cout << "found : " << *easyfind(nums, 19) << " in vector!\n";
	try
	{
		std::cout << "found : " << *easyfind(nums, 20) << " in vector!\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() <<std::endl;
	}


	std::list<int> lnums;
	for(int i = 0; i < 20; i++)
		lnums.push_back(i);
	std::cout << "found : " << *easyfind(lnums, 5) << " in list!\n";
	std::cout << "found : " << *easyfind(lnums, 0) << " in list!\n";
	std::cout << "found : " << *easyfind(lnums, 19) << " in list!\n";
	try
	{
		std::cout << "found : " << *easyfind(lnums, 20) << " in list!\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() <<std::endl;
	}
	return(0);
}