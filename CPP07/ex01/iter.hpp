#pragma once

#include <iostream>
#include <string>
#include <cstddef>


template< typename T >
void	iter( T* tab, size_t tab_size, void (*fct)(const T&))
{
	for (size_t i = 0; i < tab_size; i++)
		fct(tab[i]);
	return;
}

template<typename T>
void printer(T const & var) {
	std::cout << var << std::endl;
}

template<typename T>
void increment(const T& var) {
	++(const_cast<T&>(var));
}
