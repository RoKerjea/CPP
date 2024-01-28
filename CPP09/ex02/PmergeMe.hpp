#pragma once

#include <iostream>
#include <iomanip>
#include <functional>
#include <ctime>
#include <list>
#include <vector>
#include <sstream>
#include <cmath>
#include <iterator>
#include <exception>
#include <algorithm>
#include <cstddef> 
//Note: can i count the number of comparaisons that were made?
//that would be a good way to prove i used ford-Johnson correctly
//compare in example is just std::less<int>()

class PmergeMe
{
	private:
		std::vector<int> _vec;
		// list<int> _lst;
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();

		void	Print_vec();
		void	Sort_vec();
		void	Merge_insert_vec(std::vector<int> &vec);
};

//need a print vec function, to show order at different steps

//need some tools for time measurement
