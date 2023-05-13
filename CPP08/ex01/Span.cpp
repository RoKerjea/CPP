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

size_t	Span::shortestSpan(void)
{
	if (_vec.size() < 2)
		throw InvalidSpan();
	size_t	res;
	std::vector<int> tmp = _vec;
	std::vector<int>::iterator	index;

	std::sort(tmp.begin(), tmp.end());
	index = tmp.begin();
	while (index != (tmp.end() - 1))
	{
		if(res > (*(index + 1)  *index))
			res = *(index + 1)  *index;
		index++;
	}
	return (res);

}

size_t Span::longestSpan(void)
{
	if (_vec.size() < 2)
		throw InvalidSpan();
	int max = *std::max_element(_vec.begin(), _vec.end());
	int	min = *std::min_element(_vec.begin(), _vec.end());

	return	static_cast<size_t> (max - min);
}

void	Span::AddRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		if (_vec.size() >= _max)
			throw Span::InvalidSpan();
		_vec.push_back(*begin);
		begin++;
	}
}

const	char* Span::InvalidSpan::what() const
{
	return("Invalid operation to Span!");
}