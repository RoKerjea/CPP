#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
	private:
		unsigned int		_max;
		std::vector<int>	_vec;

		Span(Span const &ori);
		Span();
	public:
		Span &operator=(Span const &ori);
		~Span();
		Span(unsigned int max);

		void	addNumber(int toAdd);
		long	shortestSpan();
		long	longestSpan();
		void  addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		class InvalidSpan : public std::exception
		{
			public:
				const char* what() const throw();
		};
};