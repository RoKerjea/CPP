#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

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
	
}