#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::~Point() {}

Point::Point(const Point &ori) : 	_x(ori.getFixedX()),
									_y(ori.getFixedY())
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point &Point::operator=(const Point& ori)
{
	this->~Point();
	new (this) Point(ori.getFixedX().toFloat(), ori.getFixedY().toFloat());
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