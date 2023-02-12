#include "Point.hpp"

Point::Point()
{
	_x = Fixed(0);
	_y = Fixed(0);
}

Point::~Point() {}

Point::Point(const Fixed& ori)
{
	*this = ori;
}

Point::Point(const float x, const float y)
{
	_x = Fixed(x);
	_y = Fixed(y);
}

Point& Point::operator=(const Point& ori)
{
	*this = ori;
	return *this;
}

Fixed	Point::getFixedX() const
{
	return _x;
}

Fixed	Point::getFixedY() const
{
	return _y;
}