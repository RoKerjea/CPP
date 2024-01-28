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
	_vec = Merge_insert_vec(_vec);
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

void PmergeMe::Merge_insert_vec(std::vector<int> &vec)
{
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
	//third step: recursively sort the pairs, using the larger element of each pair
	//extract the larger element of each pair into a vector "Main chain"
	//call merge_insert_vec on the main chain
	//merge_insert_vec will sort the main chain, and return a sorted vector
	//i can use a basic sort for now, and make recursive calls later

	//now i should order the pairs in the vector, using the sorted main chain
	//i don't see how to do that just yet...
	//wait, the result of the merge_insert_vec is a sorted vector corresponding to the main chain...
	//i can use that to create the pending chain, by checking the main chain, finding the next element, getting the pair it belongs to, and adding the other element of the pair to the pending chain. Then deleting the pair from the pair vector.
	//not the most efficient way i think, but it's simple enough to implement
	//get pending list of elements (the .second of each pair)
	//add the pending element to the pending list of elements
	//get first element of the pending list of elements to be the first element of the main chain (b0 in book)
	//fourth step : merge the pending unsorted elements of the pairs in the final vector
	//using the jacobsthal sequence to find the next element of the pending chain to add to the main chain
	//add the next element of the pending chain to the main chain, using a binary search
	//return sorted vector main chain
}