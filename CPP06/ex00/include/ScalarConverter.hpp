#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iomanip>

class	ScalarConverter
{
	private:
	//constructors
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const&);
	void	operator=(ScalarConverter const&);
	static ScalarConverter* _instance;
	int	type;
	union{
		char a;
		int b;
		float c;
		double d;
	};
	public:
	static void destruct();

	//static class accessor
	static ScalarConverter& get();

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