#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error, need exactly 1 argument\n";
		return (1);
	}
	ScalarConverter	conv;
	conv.convert(av[1]);
	return (0);
}

/* Real Plan:
identify type, get int or enum
convert to proper type, maybe tagged union
send tagged union to 4 different final converts
send converted value one by one, to their appropriate print, to handle edge cases
finished
Conclusion:
i don't like having to use 4 differents converts,
but i think i have to if i really want to respect the subject (not a template subject, no leaks, etc.)
"type punning" from union struct could work, but it's unreliable,
might leaks, has behavior undefined depending on system. It's too risky for a 42 subject.*/