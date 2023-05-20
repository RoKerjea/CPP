#include "BitcoinExchange.hpp"

int	main(int ac, char** av)
{
	if (ac != 2)
		return (1);
	return(0);
}
/*
need to check input file (is a file, is a .txt, etc.)
check format of file ("date | value") date is in format YEAR-Month-Day (xxxx-xx-xx)
value must be a float or int >= 0 and <= 1000

Your program should display on the standard output the result of the value multiplied
by the exchange rate according to the date indicated in your database.
If the date used in the input does not exist in your DB then you
must use the closest date contained in your DB. Be careful to use the
lower date and not the upper one.
an error in .txt files should not interrupt the program, but print a precise error message depending on the error.
Ideas:
parse data.csv first, store in a container, read .txt, line by line, find corresponding date (same format)
print result(or error)
use map? but why?
do i need a class? singletone? not OOP possibility?
Date as key value for map? then compare to find closest <= one?
*/