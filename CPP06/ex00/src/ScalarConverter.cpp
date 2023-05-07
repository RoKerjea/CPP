#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}
ScalarConverter::~ScalarConverter()
{}

char	ScalarConverter::getchar()
{
	switch(type)
	{
		case 0:
			return (a);
		case 1:
			return (static_cast<char>(b));
		case 2:
			return (static_cast<char>(c));
		case 3:
			return (static_cast<char>(d));
	}
	return (0);
}

int		ScalarConverter::getint()
{
	switch(type)
	{
		case 0:
			return (static_cast<int>(a));
		case 1:
			return (b);
		case 2:
			return (static_cast<int>(c));
		case 3:
			return (static_cast<int>(d));
	}
	return (0);
}

float	ScalarConverter::getfloat()
{
	switch(type)
	{
		case 0:
			return (static_cast<float>(a));
		case 1:
			return (static_cast<float>(b));
		case 2:
			return (c);
		case 3:
			return (static_cast<float>(d));
	}
	return (0);
}

double	ScalarConverter::getdouble()
{
	switch(type)
	{
		case 0:
			return (static_cast<double>(a));
		case 1:
			return (static_cast<double>(b));
		case 2:
			return (static_cast<double>(c));
		case 3:
			return (d);
	}
	return (0);
}

int ScalarConverter::ischarpossible()
{
	switch(type)
	{
		case 0:
			return (1);
		case 1:
			if (b < CHAR_MIN || b > CHAR_MAX)
				return (0);
			return(1);
		case 2:
			if (std::isnan(c) || std::isinf(c) || c < CHAR_MIN || c > CHAR_MAX)
				return (0);
			return(1);
		case 3:
			if (std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX)
				return (0);
			return(1);
	}
	return (0);
}

void	ScalarConverter::universal_print_char()
{
	char ch = getchar();
	if (!ischarpossible())
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(ch))
		std::cout << "char: '" << ch << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

int ScalarConverter::isintpossible()
{
	switch(type)
	{
		case 0:
			return (1);
		case 1:
			if (b < INT_MIN || b > INT_MAX)
				return (0);
			return(1);
		case 2:
			if (std::isnan(c) || std::isinf(c) || c < INT_MIN || c > (float)INT_MAX)
				return (0);
			return(1);
		case 3:
			if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > (double)INT_MAX)
				return (0);
			return(1);
	}
	return (0);
}

void	ScalarConverter::universal_print_int()
{
	long i = getint();
	if (!isintpossible())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::universal_print_float()
{
	float fl = getfloat();
	std::cout << "float: " << std::setprecision(5) << fl;
	if (fl - static_cast<long>(fl) == 0)
		std::cout << ".0";
	std::cout << "f\n";
}

void	ScalarConverter::universal_print_double()
{
	double db = getdouble();
	std::cout << "double: " << std::setprecision(9) << db;
	if (db - static_cast<int>(db) == 0)
		std::cout << ".0";
	std::cout << "\n";
}

void	ScalarConverter::first_convert(std::string input)
{
	switch(type)
	{
		case 0:
			a = input[0];
			return ;
		case 1:
			b = std::atol(input.c_str());
			return ;
		case 2:
			c = std::strtof(input.c_str(), NULL);
			return ;
		case 3:
			d = std::strtod(input.c_str(), NULL);
			return ;
	}
	std::cout << "error?\n";
}

int	ScalarConverter::identificator(std::string input)
{
	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return (0);
	if (input.find_first_not_of("+-0123456789") == std::string::npos)
		return (1);
	if (input[input.length() - 1] == 'f' && input != "+inf" && input != "-inf")
		return (2);
	if (input.find(".") || input == "+inf" || input == "-inf" || input == "nan")
		return (3);
	return (4);
}

void	ScalarConverter::convert(std::string input)
{
	type = identificator(input);
	if (type == 4)
		return;
	// std::cout << input << " of type: " << type << std::endl;
	first_convert(input);
	universal_print_char();
	universal_print_int();
	universal_print_float();
	universal_print_double();
}
