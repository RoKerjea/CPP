class	ScalarConverter
{
	private:
		// static??
	public:
	//constructors

	//tools
	int	parser(std::string input);
	//4 converters from string?
	//9 other converters from one of the 4 types to other 3?
	//1 - 4 print method

};
//convert method
//need to identify type, convert tring o that type
//then need to print it's conversion into all other types
//char, int, float, double
//check if char is displayable(if not, msg)
//need check limits and special values
//big first parser step??
//then print all values translated from original

//if '.' && 'f' -> float
//else if '.' -> double
//else if only int -> int
//if only one char -> char

//edge cases:
//unprintable chars
//-inff, +inff, nanf (float)
//-inf, +inf, nan (double)
//everything outside limits (intmax, float max, etc.)

//1-detect/identify
//2-convert to correct type
//3-convert from that type to other 3 types (with edge cases)
//4-print all 4 results

//IDEAS
//5 member variables: 4 types + int for case identificator?
//store in a double, then cast it as another value? not very good, especially because consign
//maybe just 4 converts and then 4 prints, using explicit conversion?

//PLAN
//id->convert->use result to use the appropriate print-> print do explicit conversion during print