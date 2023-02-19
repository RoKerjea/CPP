#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed b( 10 );
	Fixed c(10);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;
	if (a < b)
		std::cout << "< work" << std::endl;
	if (b > a)
		std::cout << "> work" << std::endl;
	if (a <= b && b <= c)
		std::cout << "<= work" << std::endl;
	if (b >= a && b >= c)
		std::cout << ">= work" << std::endl;
	if (b != a)
		std::cout << "!= work" << std::endl;
	if (b != c)
		std::cout << "!= no work" << std::endl;
	if (b == c)
		std::cout << "== work" << std::endl;
	if (b == a)
		std::cout << "== no work" << std::endl;

	std::cout << "addition give " << b + Fixed(5) << std::endl;
	std::cout << "substraction give " << b - Fixed(5) << std::endl;
	std::cout << "multiplication give " << b * Fixed(5) << std::endl;
	std::cout << "division give " << b / Fixed(5) << std::endl;
	std::cout << "0 division give " << b / Fixed(0) << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed const d( 25 );
	Fixed const e( 42 );
	std::cout << Fixed::min( e, d ) << std::endl;
	std::cout << Fixed::max( d, e ) << std::endl;
	return 0;
}