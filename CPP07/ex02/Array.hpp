#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T *array_;
		std::size_t capacity_;

		void	swap(Array &other);

	public:
		Array();
		~Array();
		Array(std::size_t capacity);
		Array(Array const &ori);

		Array &operator=(Array const &ori);

		T const &operator[](std::size_t const index) const;
		T &operator[](std::size_t const index);
		std::size_t	size(void) const;
		class InvalidAccess : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> const &array );

#include "Array.tpp"