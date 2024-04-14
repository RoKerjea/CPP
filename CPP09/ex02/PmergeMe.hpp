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
#include <limits>
#include <string>
#include "ValueIndex.hpp"
//Note: can i count the number of comparaisons that were made?
//that would be a good way to prove i used ford-Johnson correctly
//compare in example is just std::less<int>()
#define _RED "\e[0;31m"
#define _GREEN "\e[0;32m"
#define _YELLOW "\e[33m"
#define _MAGENTA "\e[35m"
#define _CLEAR "\e[0m"

enum{
	VEC,
	LST,
};

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::list<int> _lst;
		clock_t startTime[2];
		clock_t endTime[2];
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();

		void	Print_vec();
		void	Sort_vec();
		std::vector<unsigned long>	Merge_insert_vec(std::vector<int> &vec);
		std::vector<int> order_pairs_vec(std::vector<std::pair<int, int> > &pairs, std::vector<int> &main_chain);
		unsigned long binary_insert_position_vec(std::vector<ValueIndex> &main_chain, unsigned long start, unsigned long end, ValueIndex value);

		std::vector<int> convert_to_int_vec(std::vector<ValueIndex> &value_index_vec);
		std::vector<ValueIndex> convert_to_value_index_vec(std::vector<int> &vec);
		std::vector<unsigned long> convert_to_index_vec(std::vector<ValueIndex> &value_index_vec);

		void	Print_lst();
		void	Sort_lst();
		std::list<unsigned long>	Merge_insert_lst(std::list<int> &vec);
		std::list<int> order_pairs_lst(std::list<std::pair<int, int> > &pairs, std::list<int> &main_chain);
		unsigned long binary_insert_position_lst(std::list<ValueIndex> &main_chain, unsigned long start, unsigned long end, ValueIndex value);

		std::list<int> convert_to_int_lst(std::list<ValueIndex> &value_index_lst);
		std::list<ValueIndex> convert_to_value_index_lst(std::list<int> &vec);
		std::list<unsigned long> convert_to_index_lst(std::list<ValueIndex> &value_index_lst);


		unsigned long jacobsthal_index(unsigned long index);
};

