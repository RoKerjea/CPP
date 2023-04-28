#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>

class	ScalarConverter
{
	private:
		int	type;
		union{
			char a;
			int b;
			float c;
			double d;
		};
	public:
	//constructors
	ScalarConverter();
	~ScalarConverter();

	//getter
	char	getchar();
	int		getint();
	float	getfloat();
	double	getdouble();

	//checker
	int		ischarpossible();
	int		isintpossible();

	//printer
	void	universal_print_char();
	void	universal_print_int();
	void	universal_print_float();
	void	universal_print_double();

	//tools
	int		identificator(std::string input);
	void	first_convert(std::string input);
	void	convert(std::string input);
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
//try catch until get proper format, then send pointer to print, then explicit static cast to new res?
//id->convert->use result to use the appropriate print-> print do explicit conversion during print
//static cast des videos de l'intra?
//polymorphisme of the convert method to id implivcitly? but it's always a string as input though


//int b = static_cast<int>(a); converti la valeur de a en format int pour assigner a b
//c'est une conversion explicit, ce qui est plus safe pour les demotion

//dynamic cast, peut echouer, demande que la classe soit soit polymorphe, avec fonction membre virtuelle
//pobablement utile pour exo 02 avec exception et try/catch


//reinterpret cast?? pas trop compris