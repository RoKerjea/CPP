#include "Point.hpp"

bool	point_is_in_front(Point p, Point a, Point b)
{
	Fixed cross_prod = (a.getFixedX() - p.getFixedX()) * (b.getFixedY() - p.getFixedY()) -
		(a.getFixedY() - p.getFixedY()) * (b.getFixedX() - p.getFixedX());
	return (cross_prod.toFloat() >= 0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	segment_1;
	bool	segment_2;
	bool	segment_3;

	segment_1 = point_is_in_front(point, a, b);
	segment_2 = point_is_in_front(point, b, c);
	segment_3 = point_is_in_front(point, c, a);

	return (segment_1 == segment_2 && segment_2 == segment_3);
}