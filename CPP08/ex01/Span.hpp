#pragma once

class Span
{
	private:
		int	_max;
	public:
		~Span();
		Span();
		Span(int max);
		Span(Span &ori);

		void	addNumber(int toAdd);
		//void	addNumbers();
		long	shortestSpan();
		long	longestSpan();
		class InvalidSpan : public std::exception
		{
			public:
				const char* what() const throw();
		}

};