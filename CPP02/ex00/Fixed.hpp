#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int	_value;
		static const int	_rawbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &ori);
		~Fixed();
		Fixed& operator=(const Fixed& ori);

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif