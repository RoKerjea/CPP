/*gpt proposition, to explore and understand better*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

// void mergeInsertSort(std::vector<int>& vec) {
//     if (vec.size() <= 1)
//         return;

//     std::vector<int>::iterator middle = vec.begin() + vec.size() / 2;
//     std::vector<int> left(vec.begin(), middle);
//     std::vector<int> right(middle, vec.end());

//     mergeInsertSort(left);
//     mergeInsertSort(right);

//     std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
// }

// void mergeInsertSort(std::list<int>& lst) {
//     if (lst.size() <= 1)
//         return;

//     std::list<int> left, right;
//     std::list<int>::iterator middle = lst.begin();
//     std::advance(middle, lst.size() / 2);

//     left.splice(left.begin(), lst, lst.begin(), middle);
//     right.splice(right.begin(), lst, lst.begin(), lst.end());

//     mergeInsertSort(left);
//     mergeInsertSort(right);

//     std::merge(left.begin(), left.end(), right.begin(), right.end(), lst.begin());
// }

// void displaySequence(const std::vector<int>& vec) {
//     std::cout << "Unsorted sequence: ";
//     for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

// void displaySequence(const std::list<int>& lst) {
//     std::cout << "Unsorted sequence: ";
//     for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

// int main() {
//     const int NUM_INTEGERS = 3000;

//     std::vector<int> vec;
//     std::list<int> lst;

//     // Generate a random sequence of positive integers
//     srand(static_cast<unsigned int>(time(NULL)));
//     for (int i = 0; i < NUM_INTEGERS; ++i) {
//         int num = rand() % 10000 + 1; // Range: 1 to 10000
//         vec.push_back(num);
//         lst.push_back(num);
//     }

//     displaySequence(vec);
//     displaySequence(lst);

//     clock_t start = clock();
//     mergeInsertSort(vec);
//     clock_t end = clock();
//     double timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;

//     start = clock();
//     mergeInsertSort(lst);
//     end = clock();
//     double timeList = static_cast<double>(end - start) / CLOCKS_PER_SEC;

//     std::cout << "Sorted sequence (vector): ";
//     for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Sorted sequence (list): ";
//     for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

// 	std::cout << "Time taken (vector): " << timeVec << " seconds" << std::endl;
//     std::cout << "Time taken (list): " << timeList << " seconds" << std::endl;

//     return 0;
// }
#include "PmergeMe.hpp"
int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./a.out [list of numbers]" << std::endl;
		return 1;
	}
	PmergeMe pm(ac, av);
	//checkArgs();
	pm.Print_vec();
	pm.Sort_vec();
	// std::cout << "index after 2: " << pm.jacobsthal_index(2) << std::endl;
	// std::cout << "index after 4: " << pm.jacobsthal_index(4) << std::endl;
	// std::cout << "index after 85: " << pm.jacobsthal_index(85) << std::endl;
	// std::cout << "index after 10: " << pm.jacobsthal_index(10) << std::endl;
	// std::cout << "index after 11: " << pm.jacobsthal_index(11) << std::endl;
	// std::cout << "index after 12: " << pm.jacobsthal_index(12) << std::endl;
	// std::cout << "index after 13: " << pm.jacobsthal_index(13) << std::endl;
}