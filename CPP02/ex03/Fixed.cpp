#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ori)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = ori;
}

Fixed::Fixed(int num)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = num << _mantissize;
}

Fixed::Fixed(const float fnum)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(fnum * (1 << _mantissize));
}

Fixed& Fixed::operator=(const Fixed& ori)
{
	// std::cout << "Copy assignment operator called" << std::endl;
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
	// std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat() const
{
	float res;
	res = (float)_value / (float)(1 << _mantissize);
	return (res);
}

int	Fixed::toInt() const
{
	return _value >> _mantissize;
}

bool	Fixed::operator<(const Fixed& right) const
{
	return (_value < right._value);
}

bool	Fixed::operator>(const Fixed& right) const
{
	return (_value > right._value);
}

bool	Fixed::operator>=(const Fixed& right) const
{
	return !(_value < right._value);
}

bool	Fixed::operator<=(const Fixed& right) const
{
	return !(_value > right._value);
}

bool	Fixed::operator==(const Fixed& right) const
{
	return (_value == right._value);
}

bool	Fixed::operator!=(const Fixed& right) const
{
	return !(_value == right._value);
}

Fixed	Fixed::max(Fixed& left, Fixed& right)
{
	if (left > right)
		return left;
	return right;
}

Fixed	Fixed::min(Fixed& left, Fixed& right)
{
	if (left < right)
		return left;
	return right;
}

Fixed	Fixed::max(const Fixed& left, const Fixed& right)
{
	if (left > right)
		return left;
	return right;
}

Fixed	Fixed::min(const Fixed& left, const Fixed& right)
{
	if (left < right)
		return left;
	return right;
}

Fixed Fixed::operator+(const Fixed& right)
{
	Fixed res(this->toFloat() + right.toFloat());
	return res;
}

Fixed Fixed::operator-(const Fixed& right)
{
	Fixed res(this->toFloat() - right.toFloat());
	return res;
}

Fixed Fixed::operator*(const Fixed& right)
{
	this->_value =
	((long long)this->_value * (long long)right.getRawBits()) >>
		this->_mantissize;
	return *this;
}

Fixed Fixed::operator/(const Fixed& right)
{
	if (right.toFloat() == 0)
	{
		std::cout << "!!Division by 0\n";
		return (Fixed(0));
	}
	this->_value =
	((long long)this->_value << this->_mantissize) /
	right.getRawBits();
	return *this;
}

Fixed&	Fixed::operator++()
{
	++_value;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++_value;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	--_value;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--_value;
	return (tmp);
}