#include <iostream>
#include <stack>

#define _RED "\e[0;31m"
#define _GREEN "\e[0;32m"
#define _YELLOW "\e[33m"
#define _MAGENTA "\e[35m"
#define _CLEAR "\e[0m"

bool	allowedOp(char c);

static bool	illogicSyntax(char *av, int i, int nbCount, int opCount);

static bool	syntaxError(char *av, int i, int nbCount);

static bool	divideByZero(char *av, int i);

void	checkArgumentErrors(int ac, char *av, int i);

static int	add(int nb1, int nb2);

static int	minus(int nb1, int nb2);

static int	multiply(int nb1, int nb2);

static int	divide(int nb1, int nb2);

void	rpn(char *av, int i);