#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	std::transform(av + 1, av + ac, std::back_inserter(_vec), std::atoi);
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::Sort_vec()
{
	//save start time
	std::vector<int> sorted_vec = Merge_insert_vec(_vec);
	std::cout << "sorted vector" << std::endl;
	for (std::vector<int>::const_iterator it = sorted_vec.begin(); it != sorted_vec.end(); ++it) {
		std::cout << *it << " ";
	}
	//the vector should be sorted
	//print the vector
	//print the number of comparaisons
	//print the time it took to sort the vector (start time - end time)

}

void PmergeMe::Print_vec()
{
	for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool vec_is_sorted(std::vector<int> &vec)
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

std::vector<int> PmergeMe::Merge_insert_vec(std::vector<int> &vec)
{
	if (vec_is_sorted(vec))
	{
		return vec;
	}
	if (vec.size() == 2)
	{
		std::swap(vec[0], vec[1]);
		return vec;
	}
	//first step: make pair of elements in the vector
	std::vector<std::pair<int, int> > pairs;
	for (unsigned long i = 0; i < vec.size() - 1; i += 2)
	{
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
	int pending_element = -1;
	if (vec.size() % 2 != 0)
	{
		pending_element = vec[vec.size() - 1];
	}
	//second step: sort inside the pairs
	for (unsigned long i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first < pairs[i].second)
		{
			std::swap(pairs[i].first, pairs[i].second);
		}
		//a comparaison as been made in each iteration of the loop
		//comp count ++??
	}
	std::cout << "list of pairs after sorting inside the pairs" << std::endl;
	for (unsigned long i = 0; i < pairs.size(); i++)
	{
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	}
	std::vector<int> main_chain;
	for (unsigned long i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].first);
	}
	std::cout << "main chain" << std::endl;
	for (unsigned long i = 0; i < main_chain.size(); i++)
	{
		std::cout << main_chain[i] << " ";
	}
	std::cout << std::endl;

	//third step: recursively sort the pairs, using the larger element of each pair
	//extract the larger element of each pair into a vector "Main chain"
	//call merge_insert_vec on the main chain
	//merge_insert_vec will sort the main chain, and return a sorted vector
	//i can use a basic sort for now, and make recursive calls later
	main_chain = Merge_insert_vec(main_chain);
	std::sort(main_chain.begin(), main_chain.end());
	std::cout << "main chain after sort" << std::endl;
	for (unsigned long i = 0; i < main_chain.size(); i++)
	{
		std::cout << main_chain[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int> pending_chain;
	//now i should order the pairs in the vector, using the sorted main chain
	//i don't see how to do that just yet...
	//wait, the result of the merge_insert_vec is a sorted vector corresponding to the main chain...
	//i can use that to create the pending chain, by checking the main chain, finding the next element, getting the pair it belongs to, and adding the other element of the pair to the pending chain. Then deleting the pair from the pair vector.
	//not the most efficient way i think, but it's simple enough to implement
	pending_chain = order_pairs(pairs, main_chain);
	//add the pending element to the pending list of elements
	if (pending_element != -1)
	{
		pending_chain.push_back(pending_element);
	}

	std::cout << "pending chain after ordering" << std::endl;
	for (unsigned long i = 0; i < pending_chain.size(); i++)
	{
		std::cout << pending_chain[i] << " ";
	}
	std::cout << std::endl;
	//get first element of the pending list of elements to be the first element of the main chain (b0 in book)
	main_chain.insert(main_chain.begin(), pending_chain[0]);
	//fourth step : merge the pending unsorted elements of the pairs in the final vector
	//using the jacobsthal sequence to find the next element of the pending chain to add to the main chain
	unsigned long pending_index = 0;
	for (unsigned long i = 0; i < pending_chain.size() - 1; i++)
	{
		std::cout << _YELLOW << "start of iteration " << i << _CLEAR << std::endl;
		std::cout << "pending chain : " << std::endl;
		for (unsigned long i = 0; i < pending_chain.size(); i++)
		{
			std::cout << pending_chain[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "main chain : " << std::endl;
		for (unsigned long i = 0; i < main_chain.size(); i++)
		{
			std::cout << main_chain[i] << " ";
		}
		std::cout << std::endl;
		if (jacobsthal_index(pending_index) > pending_chain.size() - 1)
		{
			std::cout << "jacobsthal index is out of range" << std::endl;
			pending_index = pending_chain.size() - 1;
		}
		else
			pending_index = jacobsthal_index(pending_index);
		unsigned int pending_index_value = pending_chain[pending_index];
		std::cout << "pending index: " << pending_index << std::endl;
		std::cout << "pending value to insert: " << pending_index_value << std::endl;
		//get insert position, using a binary search
		unsigned long insert_position = binary_insert_position(main_chain, 0, main_chain.size() - 1, pending_index_value);
		//insert pending[index] in main chain at insert position
		main_chain.insert(main_chain.begin() + insert_position, pending_index_value);
	}

	std::cout << "pending chain" << std::endl;
	for (unsigned long i = 0; i < pending_chain.size(); i++)
	{
		std::cout << pending_chain[i] << " ";
	}
	std::cout << std::endl;
	//return sorted vector main chain
	return main_chain;
}

unsigned long PmergeMe::binary_insert_position(std::vector<int> &main_chain, unsigned long start, unsigned long end, int value)
{
	if (end < start)
	{
		return start;
	}
	// unsigned long mid = (start + end) / 2;

    unsigned long mid = (start + end) / 2;
	// std::cout << "start: " << start << std::endl;
	// std::cout << "end: " << end << std::endl;
	// std::cout << "mid: " << mid << std::endl;
	// std::cout << "value: " << value << std::endl;
	// std::cout << "size of main chain: " << main_chain.size() << std::endl;
	if (mid == 0)
	{
		return 0;
	}
	// for (unsigned long i = 0; i < main_chain.size(); i++)
	// {
	// 	std::cout << main_chain[i] << " ";
	// }
	// std::cout << std::endl;
	if (value == main_chain[mid])
	{
		return mid + 1;
	}
	if (value > main_chain[mid])
	{
		return binary_insert_position(main_chain, mid + 1, end, value);
	}
	return binary_insert_position(main_chain, start, mid - 1, value);
}

std::vector<int> PmergeMe::order_pairs(std::vector<std::pair<int, int> > &pairs, std::vector<int> &main_chain)
{
	std::vector<int> pending_chain;
	for (unsigned long i = 0; i < main_chain.size(); i++)
	{
		for (unsigned long j = 0; j < pairs.size(); j++)
		{
			if (main_chain[i] == pairs[j].first)
			{
				pending_chain.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
			else if (main_chain[i] == pairs[j].second)
			{
				pending_chain.push_back(pairs[j].first);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	return pending_chain;
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