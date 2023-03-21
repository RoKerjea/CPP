#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int	_value;
		static const int	_rawbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &ori);
		~Fixed();
		Fixed(int num);
		Fixed(float fnum);
		Fixed& operator=(const Fixed& ori);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt() const;
		float	toFloat() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fxnum);

#endif