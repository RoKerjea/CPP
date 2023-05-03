#pragma once

#include <iostream>

template< typename T >
void	iter( T* tab, size_t tab_size, void (*fct)(T const &))
{
	for (size_t i = 0; i <= tab_size; i++)
		fct(tab[i]);
	return;
}
