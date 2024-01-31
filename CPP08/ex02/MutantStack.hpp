#pragma once

#include <iostream>
#include <stack>

template<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		MutantStack(MutantStack const &copy) : std::stack<T>(copy) {}
		virtual ~MutantStack(void){}
		MutantStack &operator=(MutantStack const &) {return *this;}

		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator begin(void) {return this->c.begin(); }
		iterator end(void) {return this->c.end(); }
};