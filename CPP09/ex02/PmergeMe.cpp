#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	std::transform(av + 1, av + ac, std::back_inserter(_vec), std::atoi);
	std::transform(av + 1, av + ac, std::back_inserter(_lst), std::atoi);
}

PmergeMe::~PmergeMe()
{}

std::vector<ValueIndex> PmergeMe::convert_to_value_index_vec(std::vector<int> &vec)
{
	std::vector<ValueIndex> value_index_vec;
	for (unsigned long i = 0; i < vec.size(); i++)
	{
		value_index_vec.push_back(ValueIndex(vec[i], i));
	}
	return value_index_vec;
}

std::list<ValueIndex> PmergeMe::convert_to_value_index_lst(std::list<int> &lst)
{
	std::list<ValueIndex> value_index_lst;
	unsigned int i = 0;
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); i++)
	{
		value_index_lst.push_back(ValueIndex(*it, i));
		it++;
	}
	return value_index_lst;
}

std::vector<int> PmergeMe::convert_to_int_vec(std::vector<ValueIndex> &value_index_vec)
{
	std::vector<int> int_vec;
	for (unsigned long i = 0; i < value_index_vec.size(); i++)
	{
		int_vec.push_back(value_index_vec[i].getValue());
	}
	return int_vec;
}
std::list<int> PmergeMe::convert_to_int_lst(std::list<ValueIndex> &value_index_lst)
{
	std::list<int> int_lst;
	for (std::list<ValueIndex>::const_iterator it = value_index_lst.begin(); it != value_index_lst.end(); it++)
	{
		int_lst.push_back(it->getValue());
	}
	return int_lst;
}

std::vector<unsigned long> PmergeMe::convert_to_index_vec(std::vector<ValueIndex> &value_index_vec)
{
	std::vector<unsigned long> index_vec;
	for (unsigned long i = 0; i < value_index_vec.size(); i++)
	{
		index_vec.push_back(value_index_vec[i].getIndex());
	}
	return index_vec;
}

std::list<unsigned long> PmergeMe::convert_to_index_lst(std::list<ValueIndex> &value_index_lst)
{
	std::list<unsigned long> index_lst;
	for (std::list<ValueIndex>::const_iterator it = value_index_lst.begin(); it != value_index_lst.end(); it++)
	{
		index_lst.push_back(it->getIndex());
	}
	return index_lst;
}
void PmergeMe::Sort_vec()
{
	//save start time
	this->startTime[VEC] = clock();
	std::vector<unsigned long> sorted_vec = Merge_insert_vec(_vec);
	std::vector<int> int_sorted_vec;
	for (unsigned long i = 0; i < sorted_vec.size(); i++)
	{
		int_sorted_vec.push_back(_vec[sorted_vec[i]]);
	}
	this->endTime[VEC] = clock();
	std::cout << "sorted vector" << std::endl;
	for (std::vector<int>::const_iterator it = int_sorted_vec.begin(); it != int_sorted_vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout	<< _YELLOW << "Time to process a range of " << _vec.size() << " elements with std::vector: "
				<< this->endTime[VEC] - this->startTime[VEC] << " us"  << _CLEAR << std::endl;
	//the vector should be sorted
	//print the vector
	//print the number of comparaisons
	//print the time it took to sort the vector (start time - end time)
}

void PmergeMe::Sort_lst()
{
	//save start time
	this->startTime[LST] = clock();
	//list of index of the elements in _lst, sorted
	std::cout << "start of list sort" << std::endl;
	std::list<unsigned long> sorted_lst = Merge_insert_lst(_lst);
	std::cout << "end of list sort, start of list reordering" << std::endl;
	//new list of sorted elements. created from the sorted index
	std::list<int> int_sorted_lst;
	for (std::list<unsigned long>::const_iterator it = sorted_lst.begin(); it != sorted_lst.end(); it++)
	{
		std::list<int>::const_iterator front = _lst.begin();
		std::advance(front, *it);
		int_sorted_lst.push_back(*front);
	}
/*
	for (std::list<ValueIndex>::const_iterator it = value_index_lst.begin(); it != value_index_lst.end(); it++)
	{
		index_lst.push_back(it->getIndex());
	}*/
	this->endTime[LST] = clock();
	std::cout << "sorted list" << std::endl;
	for (std::list<int>::const_iterator it = int_sorted_lst.begin(); it != int_sorted_lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout	<< _YELLOW << "Time to process a range of " << _lst.size() << " elements with std::list: "
				<< this->endTime[LST] - this->startTime[LST] << " us"  << _CLEAR << std::endl;
	//the list should be sorted
	//print the list
	//print the number of comparaisons
	//print the time it took to sort the list (start time - end time)
}

void PmergeMe::Print_vec()
{
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::Print_lst()
{
	for (std::list<int>::const_iterator it = _lst.begin(); it != _lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool vec_is_sorted(std::vector<ValueIndex> &vec)
{
	for (unsigned long i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i] > vec[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool lst_is_sorted(std::list<ValueIndex> &lst)
{
	if (lst.size() == 1)
	{
		return true;
	}
	for (std::list<ValueIndex>::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		std::list<ValueIndex>::const_iterator itnext = it;
		advance(itnext, 1);
		if (itnext == lst.end())
		{
			break;
		}
		if (it->getValue() > itnext->getValue())
		{
			std::cout << "not sorted" << std::endl;
			for (std::list<ValueIndex>::const_iterator it = lst.begin(); it != lst.end(); it++)
			{
				std::cout << it->getValue() << " ";
			}
			std::cout << std::endl;
			return false;
		}
	}
	return true;
}

std::vector<unsigned long> PmergeMe::Merge_insert_vec(std::vector<int> &intvec)
{
	std::vector<ValueIndex> vec = convert_to_value_index_vec(intvec);
	if (vec_is_sorted(vec))
	{
		return convert_to_index_vec(vec);
	}
	if (vec.size() == 2)
	{
		std::swap(vec[0], vec[1]);
		return convert_to_index_vec(vec);
	}
	//FIRST STEP: make pair of elements in the vector
	std::vector<std::pair<ValueIndex, ValueIndex> > pairs;
	for (unsigned long i = 0; i < vec.size() - 1; i += 2)
	{
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
	ValueIndex pending_element = ValueIndex(-1, -1);
	if (vec.size() % 2 != 0)
	{
		pending_element = vec[vec.size() - 1];
	}
	//SECOND STEP: order inside the pairs,first > second
	for (unsigned long i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first < pairs[i].second)
		{
			std::swap(pairs[i].first, pairs[i].second);
		}
		//a comparaison as been made in each iteration of the loop
		//comp count ++??
	}
	//create a new vector with the value of each "first" in the pair => main_chain
	std::vector<ValueIndex> main_chain;
	for (unsigned long i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].first);
	}
	//THIRD STEP: recursively sort the pairs, using the larger element of each pair
	//call merge_insert_vec on the main chain
	//merge_insert_vec will sort the main chain, and return a sorted vector
	std::vector<int> main_chain_int = convert_to_int_vec(main_chain);
	std::vector<unsigned long> pair_sorted_index = Merge_insert_vec(main_chain_int);
	main_chain.clear();
	std::vector<ValueIndex> pending_chain;
	for (unsigned long i = 0; i < pair_sorted_index.size(); i++)
	{
		main_chain.push_back(pairs[pair_sorted_index[i]].first);
		pending_chain.push_back(pairs[pair_sorted_index[i]].second);
	}
	//add the pending element (if any) to the pending list of elements
	if (pending_element != ValueIndex(-1, -1))
	{
		pending_chain.push_back(pending_element);
	}
	std::cout << std::endl;
	//get first element of the pending list of elements to be the first element of the main chain (b0 in book)
	main_chain.insert(main_chain.begin(), pending_chain[0]);
	//FOURTH : merge the pending unsorted elements of the pairs in the final vector
	//using the jacobsthal sequence to find the next element of the pending chain to insert to the main chain
	unsigned long pending_index = 0;
	for (unsigned long i = 0; i < pending_chain.size() - 1; i++)
	{
		if (jacobsthal_index(pending_index) > pending_chain.size() - 1)
		{
			pending_index = pending_chain.size() - 1;
		}
		else
			pending_index = jacobsthal_index(pending_index);
		ValueIndex pending_index_value = pending_chain[pending_index];
		//get insert position, using a binary search
		unsigned long insert_position = binary_insert_position_vec(main_chain, 0, main_chain.size() - 1, pending_index_value);
		//insert pending[index] in main chain at insert position
		main_chain.insert(main_chain.begin() + insert_position, pending_index_value);
	}
	return convert_to_index_vec(main_chain);
}

std::list<unsigned long> PmergeMe::Merge_insert_lst(std::list<int> &intlst)
{
	std::list<ValueIndex> lst = convert_to_value_index_lst(intlst);
	std::cout << "converted to value index list" << std::endl;
	if (lst_is_sorted(lst))
	{
		std::cout << "list is sorted" << std::endl;
		return convert_to_index_lst(lst);
	}
	if (lst.size() == 2)
	{
		std::cout << "list size = 2 unsorted" << std::endl;
		lst.reverse();
		return convert_to_index_lst(lst);
	}
	//FIRST STEP: make pair of elements in the list
	std::list<std::pair<ValueIndex, ValueIndex> > pairs;
	// pairs.insert(pairs.begin(), std::make_pair(*lst.begin(), *lst.begin()));
	// std::cout << "content of pairs" << std::endl;
	// std::cout << "pair first: " << pairs.begin()->first.getValue() << pairs.begin()->first.getIndex() << std::endl;
	// std::cout << "pair second: " << pairs.begin()->second.getValue() << pairs.begin()->second.getIndex() << std::endl;
	// exit(0);
	std::cout<< _RED << "start of pair creation" << _CLEAR << std::endl;
	// int i = 0;

	ValueIndex pending_element = ValueIndex(-1, -1);
	for(std::list<ValueIndex>::const_iterator it = lst.begin(); it != lst.end(); it++)
	{ 
		std::cout << "value index: " << it->getValue()  << std::endl;
		std::list<ValueIndex>::const_iterator itnext = it;
		std::advance(itnext, 1);
		if (itnext == lst.end())
		{
			pending_element = *it;
			std::cout << "value index: of pending: " << it->getValue()  << std::endl;
			break;
		}
		std::cout << "next value index: " << itnext->getValue() << std::endl;
		// pairs.push_back(std::make_pair(*it, *itnext));
		std::pair<ValueIndex, ValueIndex> pair = std::make_pair(*it, *itnext);
		it++;
		std::cout << "pair created" << std::endl;
		std::cout << "pair first: " << pair.first.getValue() << " "<< pair.first.getIndex() << std::endl;
		std::cout << "pair second: " << pair.second.getValue() << " "<<  pair.second.getIndex() << std::endl;
		pairs.insert(pairs.end(), pair);
	}
	std::cout << "pending element" << std::endl;
	// ValueIndex pending_element = ValueIndex(-1, -1);
	// if (lst.size() % 2 != 0)
	// {
	// 	std::list<ValueIndex>::const_iterator it = lst.end();
	// 	pending_element = *it;
	// 	std::cout << "there is a pending element : " << pending_element.getValue() << std::endl;
	// }
	std::cout << "end of pair creation" << std::endl;
	//SECOND STEP: order inside the pairs,first > second
	for (std::list<std::pair<ValueIndex, ValueIndex> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->first < it->second)
		{
			std::cout << "swap" << std::endl;
			//TODO swap correctly
			ValueIndex second = it->second;
			it->second = it->first;
			it->first = second;
		}
	}
	//create a new list with the value of each "first" in the pair => main_chain
	std::list<ValueIndex> main_chain;
	for (std::list<std::pair<ValueIndex, ValueIndex> >::const_iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		main_chain.push_back(it->first);
	}
	std::cout << "main chain" << std::endl;
	for (std::list<ValueIndex>::const_iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << it->getValue() << " ";
	}
	std::cout << std::endl;
	//THIRD STEP: recursively sort the pairs, using the larger element of each pair
	//call merge_insert_lst on the main chain
	//merge_insert_lst will sort the main chain, and return a sorted list
	std::list<int> main_chain_int = convert_to_int_lst(main_chain);
	std::list<unsigned long> pair_sorted_index = Merge_insert_lst(main_chain_int);
	main_chain.clear();
	std::cout << _RED<< "main chain of unsorted int"<< _CLEAR << std::endl;
	for (std::list<int>::const_iterator it = main_chain_int.begin(); it != main_chain_int.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "list of sorted index" << std::endl;
	for (std::list<unsigned long>::const_iterator it = pair_sorted_index.begin(); it != pair_sorted_index.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::list<ValueIndex> pending_chain;
	for (std::list<unsigned long>::const_iterator it_pair = pair_sorted_index.begin(); it_pair != 	pair_sorted_index.end(); it_pair++)
	{
		std::list<std::pair<ValueIndex, ValueIndex> >::const_iterator it = pairs.begin();
		std::advance(it, *it_pair);
		//need to get the pairs element at index pair_sorted_index *it
		main_chain.push_back(it->first);
		pending_chain.push_back(it->second);
	}
	//add the pending element (if any) to the pending list of elements
	if (pending_element != ValueIndex(-1, -1))
	{
		pending_chain.push_back(pending_element);
	}
	//get first element of the pending list of elements to be the first element of the main chain (b0 in book)
	std::cout << "ordered pending chain" << std::endl;
	for (std::list<ValueIndex>::const_iterator it = pending_chain.begin(); it != pending_chain.end(); it++)
	{
		std::cout << it->getValue() << " ";
	}
	std::cout << std::endl;
	main_chain.insert(main_chain.begin(), *pending_chain.begin());
	std::cout << "sorted main chain before insert" << std::endl;
	for (std::list<ValueIndex>::const_iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << it->getValue() << " ";
	}
	std::cout << std::endl;
	//FOURTH : merge the pending unsorted elements of the pairs in the final list
	//using the jacobsthal sequence to find the next element of the pending chain to insert to the main chain
	unsigned long pending_index = 0;
	for (unsigned long i = 0; i < pending_chain.size() - 1; i++)
	{
		if (jacobsthal_index(pending_index) > pending_chain.size() - 1)
		{
			pending_index = pending_chain.size() - 1;
		}
		else
			pending_index = jacobsthal_index(pending_index);
		std::list<ValueIndex>::const_iterator it = pending_chain.begin();
		std::advance(it, pending_index);
		ValueIndex pending_index_value = *it;
		//get insert position, using a binary search
		std::cout << "value to insert: " << pending_index_value.getValue() << std::endl;
		unsigned long insert_position = binary_insert_position_lst(main_chain, 0, main_chain.size(), pending_index_value);
		std::cout << "value to insert: " << pending_index_value.getValue() << std::endl;
		std::cout << "insert position: " << insert_position << std::endl;
		//insert pending[index] in main chain at insert position
		std::list<ValueIndex>::iterator itmain = main_chain.begin();
		std::advance(itmain, insert_position);
		main_chain.insert(itmain, pending_index_value);
	}
	std::cout << "sorted chain, as value index list" << std::endl;
	for (std::list<ValueIndex>::const_iterator it = main_chain.begin(); it != main_chain.end(); it++)
	{
		std::cout << it->getValue() << " ";
	}
	std::cout << std::endl;
	return convert_to_index_lst(main_chain);
}

unsigned long PmergeMe::binary_insert_position_vec(std::vector<ValueIndex> &main_chain, unsigned long start, unsigned long end, ValueIndex value)
{
	if (end < start)
	{
		return start;
	}
    unsigned long mid = (start + end) / 2;
	if (mid == 0)
	{
		return 0;
	}
	if (value == main_chain[mid])
	{
		return mid + 1;
	}
	if (value > main_chain[mid])
	{
		return binary_insert_position_vec(main_chain, mid + 1, end, value);
	}
	return binary_insert_position_vec(main_chain, start, mid - 1, value);
}

unsigned long PmergeMe::binary_insert_position_lst(std::list<ValueIndex> &main_chain, unsigned long start, unsigned long end, ValueIndex value)
{
	if (end < start)
	{
		return start;
	}
    unsigned long mid = (start + end) / 2;
	std::cout << "start: " << start << std::endl;
	std::cout << "end: " << end << std::endl;
	std::cout << "mid: " << mid << std::endl;
	// if (mid == 0)
	// {
	// 	return 0;
	// }
	std::list<ValueIndex>::const_iterator itmid = main_chain.begin();
	std::advance(itmid, mid);
	std::cout << "value of itmid: " << itmid->getValue() << std::endl; 
	if (value.getValue() == itmid->getValue())
	{
		return mid + 1;
	}
	if (value.getValue() > itmid->getValue())
	{
		return binary_insert_position_lst(main_chain, mid + 1, end, value);
	}
	if (mid == 0)
	{
		return 0;
	}
	return binary_insert_position_lst(main_chain, start, mid - 1, value);
}

//need a function to get the next index to add to the main chain
//it use the jacobsthal sequence
//if the previous index is 3, the next index should be 2, and the next next index should be 5
//if the previous index is 5, the next index should be 4, and the next next index should be 11
//if the previous index is 11, the next index should be 10, 9, 8, 7, 6, then 21, 20, 19

unsigned long PmergeMe::jacobsthal_index(unsigned long index)
{
	//i substract 1 from the result, because the first element of the vector is at index 0, not 1
	//not super clean, but will improve it later //TODO
	if (index == 0)
	{
		return 3 - 1;
	}
	if (index == 1)
	{
		return 5 - 1;
	}
	if (index == 2)
	{
		return 2 - 1;
	}
	static unsigned long jacobsthal_sequence[] = {
		1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123
		};
	for (unsigned long i = 0; i < 35 ; i++) {
		//three cases possible:
		//index is in the sequence => return element value - 1;
		if (index + 1 == jacobsthal_sequence[i])
		{
			return jacobsthal_sequence[i] - 2;
		}
		//index is equal to an element of the sequence + 1 => return element[i + 2](if index == 3, i == 1 , 4 and 5 were already done, so return 6)
		else if (index == jacobsthal_sequence[i])
		{
			// std::cout << "index after " << index << ": " << jacobsthal_sequence[i + 2] << std::endl;
			return jacobsthal_sequence[i + 2] - 1;
		}
	}
	//else => return index - 1
	return index - 1;
}