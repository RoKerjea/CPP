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
	public:
		~Span();
		Span();
		Span(unsigned int max);
		Span(Span &ori);
		operator=(Span &ori);

		void	addNumber(int toAdd);
		//void	addNumbers();
		size_t	shortestSpan();
		size_t	longestSpan();
		class InvalidSpan : public std::exception
		{
			public:
				const char* what() const throw();
		}
};