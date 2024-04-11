/*stack/deque to use because of specificity of subject?
RPN is conceived with stack as a tool, push and pop by order of reading
so stack seems a logical choice*/
#include "RPN.hpp"

int	main(int ac, char **av) {
	try {
		checkArgumentErrors(ac, av[1], 0);
		rpn(av[1], 0);
	}
	catch(const std::exception& e) {
		std::cerr << _RED << e.what() << _CLEAR << std::endl;
	}
	return 0;
}