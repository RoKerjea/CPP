#include "RPN.hpp"

static bool	divisionByZero(char *av, int i) 
{
	while (av[i]) 
	{
		if (atoi(av + i) == 0 && av[i + 2] == '/')
			return true;
		i++;
	}
	return false;
}


bool	operands(char c) 
{
	if (c != '+' && c != '-' && c != '/' && c != '*')
		return false;
	else
		return true;
}

static bool	incorrectOrder(char *av, int i, int nbCount, int opCount) 
{
	while (av[i]) 
	{
		if (isdigit(av[i])) 
		{
			nbCount++;
			while (av[i] && isdigit(av[i]))
				i++;
		}
		else if (operands(av[i]))
			opCount++;
		i++;
	}
	if (opCount + 1 != nbCount)
		return true;
	else
		return false;
}

static bool	syntaxError(char *av, int i, int nbCount) 
{
	if (incorrectOrder(av, 0, 0, 0) == true)
		return true ;
	while (av[i]) 
	{
		if (isdigit(av[i]))
			nbCount++;
		if (nbCount == 2 && operands(av[i]))
			nbCount = 1;
		else if (nbCount == 3 && operands(av[i]))
			nbCount = 2;
		i++;
	}
	if (nbCount != 1)
		return true;
	else
		return false;
}


void	checkErrors(int ac, char *av, int i) 
{
	if (ac != 2)
		throw std::invalid_argument("Error");
	while (av[i]) 
	{
		if ((!isdigit(av[i])) && operands(av[i]) == false && av[i] != ' ')
			throw std::invalid_argument("Error");
		else
			i++;
	}
	if (syntaxError(av, 0, 0) == true)
		throw std::invalid_argument("Error");
	else if (divisionByZero(av, 0) == true)
		throw std::invalid_argument("Error");
	return ;
}

static int	add(int nb1, int nb2) {return (nb1 + nb2);}

static int	minus(int nb1, int nb2) {return (nb1 - nb2);}

static int	multiply(int nb1, int nb2) {return (nb1 * nb2);}

static int	divide(int nb1, int nb2) {return (nb1 / nb2);}

void	rpn(char *av, int i) 
{
	std::stack<int>	data;
	int				tmp;
	int				j = 0;
	operandFunctions_s	rpns[4] = {
		{'+', &add},
		{'-', &minus},
		{'*', &multiply},
		{'/', &divide}
	};

	while (av[i]) 
	{
		if (isdigit(av[i]))
			data.push(atoi(av + i));
		else if (operands(av[i])) 
		{
			tmp = data.top();
			data.pop();
			while (rpns[j].op != av[i])
				j++;
			tmp = rpns[j].f(data.top(), tmp);
			j = 0;
			data.pop();
			data.push(tmp);
		}
		i++;
	}
	std::cout << GRNCOLOR << data.top() << ENDCOLOR << std::endl;
	return ;
}