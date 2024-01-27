#include "Span.hpp"

Span::Span()
{
	_max = 0;
}

Span::~Span(){}

Span::Span(unsigned int max)
{
	_max = max;
}

Span::Span(const Span &ori)
{
	*this = ori;
}

Span	&Span::operator=(Span const &ori)
{
	if(this != &ori)
	{
		this->_max = ori._max;
		this->_vec = ori._vec;
	}
	return *this;
}

void	Span::addNumber(int toAdd)
{
	if(_vec.size() < _max)
		_vec.push_back(toAdd);
	else
		throw Span::InvalidSpan();
}

long	Span::shortestSpan(void)
{
	if (_vec.size() < 2)
		throw InvalidSpan();
	long	res;
	std::vector<int> tmp = _vec;
	std::vector<int>::iterator	index;

	std::sort(tmp.begin(), tmp.end());
	index = tmp.begin();
	while (index != (tmp.end() - 1))
	{
		if(res > (*(index + 1) - *index))
			res = *(index + 1) - *index;
		index++;
	}
	return (res);

}

long Span::longestSpan(void)
{
	if (_vec.size() < 2)
		throw InvalidSpan();
	int max = *std::max_element(_vec.begin(), _vec.end());
	int	min = *std::min_element(_vec.begin(), _vec.end());

	return	(max - min);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) > static_cast<int>(_max))
		throw InvalidSpan();
	_vec.insert(_vec.end(), begin, end);
}

const	char *Span::InvalidSpan::what(void) const throw()
{
	return("Invalid operation to Span!");
}