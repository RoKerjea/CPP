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

	std::cout <<"Max of "<< a << " and " << b << " is ";
	std::cout << max<int>(a, b) << std::endl;
	std::cout <<"Max of "<< a << " and " << b << " is ";
	std::cout << max(a, b) << std::endl;

	float	c = -1.7f;
	float	d = 4.2f;

	std::cout <<"Max of "<< c << " and " << d << " is ";
	std::cout << max<float>(c, d) << std::endl;
	std::cout <<"Max of "<< c << " and " << d << " is ";
	std::cout << max(c, d) << std::endl;
}