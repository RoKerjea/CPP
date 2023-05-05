#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T *tab;
		unsigned int count;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &ori);
		Bureaucrat& operator=(const Array &ori);
		unsigned int	size(void);
		class InvalidAccess : public std::exception
		{
			public:
				const char* what() const throw();
		};
};