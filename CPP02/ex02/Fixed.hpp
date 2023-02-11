#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int	_value;
		static const int	_mantissize = 8;
	public:
	//CONSTRUCTORS
		Fixed();
		Fixed(const Fixed &ori);
		~Fixed();
		Fixed(int num);
		Fixed(float fnum);
		Fixed& operator=(const Fixed& ori);

	//OPERATOR COMP
		bool	operator<(const Fixed& right) const;
		bool	operator>(const Fixed& right) const;
		bool	operator<=(const Fixed& right) const;
		bool	operator>=(const Fixed& right) const;
		bool	operator==(const Fixed& right) const;
		bool	operator!=(const Fixed& right) const;

	//OPERATOR MATH
		Fixed operator+(const Fixed& right);
		Fixed operator-(const Fixed& right);
		Fixed operator*(const Fixed& right);
		Fixed operator/(const Fixed& right);

	//OPERATOR INCREMENT/DECREMENT
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

	//COMP
		static Fixed	min(Fixed& left, Fixed& right);
		static Fixed	max(Fixed& left, Fixed& right);
		static Fixed	min(const Fixed& left, const Fixed& right);
		static Fixed	max(const Fixed& left, const Fixed& right);

	//GETTER
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );

	//CONVERTER
		int	toInt() const;
		float	toFloat() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fxnum);

#endif