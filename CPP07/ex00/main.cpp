#include "whatever.hpp"

// int main( void )
// {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }

int	main(void)
{
	int	a = 21;
	int	b = 42;

	std::cout <<"Max of "<< a << " and " << b << "\nis ";
	std::cout << max(a, b) << std::endl;
	std::cout <<"and Min is " << min(a, b) << std::endl;
	std::cout <<"Before swap a = "<< a << " and b = " << b << std::endl;
	swap(a, b);
	std::cout <<"After swap a = "<< a << " and b = " << b << std::endl;


	float	c = -1.7f;
	float	d = 4.2f;

	std::cout <<"Max of "<< c << " and " << d << "\nis ";
	std::cout << max(c, d) << std::endl;
	std::cout <<"and Min is " << min(c, d) << std::endl;
	std::cout <<"Before swap c = "<< c << " and d = " << d << std::endl;
	swap(c, d);
	std::cout <<"After swap c = "<< c << " and d = " << d << std::endl;
}