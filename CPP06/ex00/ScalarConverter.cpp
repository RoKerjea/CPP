#include "ScalarConverter.hpp"

// void	ScalarConverter::parser(std::string input)
// {
// 	int floatgate;
// 	int doublegate;
// 	floatgate = input.find("f");
// 	doublegate = input.find(".");
// 	if (floatgate)
// 	{

// 	}
// 	else if (doublegate)
// 	{

// 	}
// 	else if ()
// }

// identify type

// convert to proper type
// print with static_cast?
// add edge cases

int	identificator(std::string input)
{
	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return (1);
	if (input.find("f"))//float || isedgefloat
		return (2);
	if (input.find("."))//double || isedgedouble
		return (3);
	if (input.length() != 0)
		return (4);
	return (0);
}

union inputtype {
	int a;
	char c;
	float f;
	double d;
}

void	printconvert(inputtype input, int type)
{
	
}

void convert(std::string input)
{
	int type = identificator(input);
	
	//convert to proper type
	//use print from xx?
	//Orrrr
	//print union input and static cast everything the same way?
}