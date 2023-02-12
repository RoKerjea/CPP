bool	point_is_in_front(Point p, Point a, Point b)
{
	Fixed cross_prod = (a.getFixedX() - p.getFixedX()) * (b.getFixedY() - p.getFixedY()) -
		(a.getFixedY() - p.getFixedY()) * (b.getFixedX() - p.getFixedX());
	if (cross_prod > 0)
		return (true);
	return (false);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	
}