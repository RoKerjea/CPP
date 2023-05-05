#include "Array.hpp"

Array<T>(void) : _tab(NULL) {}

~Array<T>(void)
{
	delete [] this->tab;
}

Array<T>(Array const & copy)
{
	count = copy.size();
	tab = new T[count];
	for (int i = 0; i < count, i++)
		tab[i] = copy.tab[i];
}

Array<T>(unsigned int n)
{
	if (n <= 0)
		throw Array<T>::InvalidAccess();
	count = n;
	tab = new T[count];
}

Array<T> &operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		if (count)
			delete [] tab;
		count = rhs.size();
		tab = new T[count];
		for(int i = 0; i < count, i++)
			tab[i] = rhs.tab[i];
	}
	return (*this);
}

T &operator[](unsigned int index)
{
	if (index >= count)
		throw Array<T>::InvalidAccess();
	return (tab[index]);
}

T const &operator[](unsigned int index) const
{
	if (index >= count)
		throw Array<T>::InvalidAccess();
	return (tab[index]);
}

const char* Array::InvalidAccess::what() const
{
	return("Invalid Access to tab!");
}

unsigned int	size(void) const
{
	return (count);
}