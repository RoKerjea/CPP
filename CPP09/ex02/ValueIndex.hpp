#pragma once

#include <iostream>

class ValueIndex
{
	private:
		int _value;
		unsigned long _index;
		//maybe comparaison counter variable here
	public:
		ValueIndex(void);
		ValueIndex(int value, unsigned long index);
		ValueIndex(ValueIndex const &original);
		~ValueIndex(void);
		ValueIndex &operator=(ValueIndex const &rhs);
		int getValue(void) const;
		unsigned long getIndex(void) const;
		bool operator<(ValueIndex const &rhs) const;
		bool operator>(ValueIndex const &rhs) const;
		// bool operator<=(ValueIndex const &rhs) const;
		// bool operator>=(ValueIndex const &rhs) const;
		bool operator==(ValueIndex const &rhs) const;
		bool operator!=(ValueIndex const &rhs) const;
};

std::ostream &operator<<(std::ostream &out, ValueIndex const &rhs);
//if i treat my new class exactly like the int in my pmergeme, i can use the same functions
//and at the end of the sort, i can create a vector of index, and return it
//like:
//for (unsigned long i = 0; i < vec.size(); i++)
//{
//	index_vec.push_back(vec[i].getIndex());
//}

//and in the next recursion, i can use the index vector to create a main chain and a pending chain by using the same index list
/*
 * std::vector<int> main_chain;
 * std::vector<int> pending_chain;
 * for (unsigned long i = 0; i < index_vec.size(); i++)
 * {
 * 	main_chain.push_back(pairs[index_vec[i]].first);
 *  pending_chain.push_back(pairs[index_vec[i]].second);
 * }
 *
*/
//at the main function, i receive a vector of index, and i can create a new vector of int, and fill it by following the index list
//like:
//vector<int> sorted_vec;
//for (unsigned long i = 0; i < index_vec.size(); i++)
//{
//	sorted_vec.push_back(vec[index_vec[i]].getValue());
//}