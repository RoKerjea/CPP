#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(&Point ori);
		~Point();

		Point& operator=(const Point& ori);
		Fixed getFixedX(void) const;
		Fixed getFixedY(void) const;
};

#endif