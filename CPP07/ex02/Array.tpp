#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	array_ = NULL;
	capacity_ = 0;
}

template <typename T>
Array<T>::~Array()
{
	delete []array_;
}

template <typename T>
Array<T>::Array(Array<T> const & copy)
{
	capacity_ = copy.capacity_;
	array_ = new T[capacity_];
	for (std::size_t i = 0; i < capacity_; i++)
		array_[i] = copy.array_[i];
}

template <typename T>
Array<T>::Array(std::size_t capacity)
{
	capacity_ = capacity;
	array_ = new T[capacity_];
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	Array tmpcopy(rhs);
	swap(tmpcopy);
	return *this;
}
template <typename T>
T const &Array<T>::operator[](std::size_t const index) const
{
	if (index >= capacity_)
		throw Array<T>::InvalidAccess();
	return (array_[index]);
}
template <typename T>
T &Array<T>::operator[](std::size_t const index)
{
	if (index >= capacity_)
		throw Array<T>::InvalidAccess();
	return (array_[index]);
}

template <typename T>
void	Array<T>::swap(Array<T> &other)
{
	std::swap(capacity_, other.capacity_);
	std::swap(array_, other.array_);
}

template <typename T>
const char* Array<T>::InvalidAccess::what() const throw()
{
	return("Invalid Access to array !");
}

template <typename T>
std::size_t	Array<T>::size(void) const
{
	return (capacity_);
}

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> const &array)
{
	out << "[";
	if (array.size() != 0)
	{
		out << array[0];
		for (std::size_t i = 1; i < array.size(); i++)
			out <<", " << array[i];
	}
	out << "]";

	return out;
}

#endif