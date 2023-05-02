#pragma once

#include <iostream>

template< typename T >
T const & max(T const & x, T const & y)
{
	return ( x>=y ? x : y);
}

template< typename T >
T const & min(T const & x, T const & y)
{
	return ( x<=y ? x : y);
}

template< typename T >
T swap(T const & x, T const & y)
{
	
}