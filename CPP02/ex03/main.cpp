#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void	test_bsp(void)
{
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	Point p(1, 1);
	if (bsp(a, b, c, p))
		std::cout << "Oui, le point est dans le triangle" << std::endl;
	Point q(5, 5);
	if (!bsp(a, b, c, q))
		std::cout << "Non, le point n'est pas dans le triangle" << std::endl;
	Point r(1, 0);
	if (!bsp(a, b, c, r))
		std::cout << "Non, le point n'est pas dans le triangle" << std::endl;
	Point s(0, 1);
	if (!bsp(a, b, c, s))
		std::cout << "Non, le point n'est pas dans le triangle" << std::endl;
}

int main( void )
{
	Point a;
	Point b(4.5, 6.5);

	float	x = a.getFixedX().toFloat();
	std::cout << x << "\n";
	x = b.getFixedX().toFloat();
	std::cout << x << "\n";
	float	y = b.getFixedY().toFloat();
	std::cout << y << "\n";

	Point c(b);
	x = c.getFixedX().toFloat();
	std::cout << x << "\n";
	y = c.getFixedY().toFloat();
	std::cout << y << "\n";

	Point d(4.7, 6.8);
	Point e;
	e = d;
	x = e.getFixedX().toFloat();
	std::cout << x << "\n";
	x = d.getFixedX().toFloat();
	std::cout << x << "\n";
	y = e.getFixedY().toFloat();
	std::cout << y << "\n";
	y = d.getFixedY().toFloat();
	std::cout << y << "\n";

	test_bsp();
	return 0;
}