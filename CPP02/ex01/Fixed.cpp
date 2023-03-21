#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ori)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ori;
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	_value = num << _rawbits;
}

Fixed::Fixed(const float fnum)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(fnum * (1 << _rawbits));
}

Fixed& Fixed::operator=(const Fixed& ori)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = ori.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fxnum)
{
	out << fxnum.toFloat();
	return out;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat() const
{
	float res;
	res = (float)_value / (float)(1 << _rawbits);
	return (res);
}

int	Fixed::toInt() const
{
	return _value >> _rawbits;
}