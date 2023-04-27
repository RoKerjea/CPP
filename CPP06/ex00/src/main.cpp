#include <iostream>
#include <string>

union inputtype{
	int a;
	char c;
	float f;
	double d;
};

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	union U { int a; char b; float c; double d;} u;
	u.c = 3.14;
	void* x = static_cast<void*>(&u.c);    // x's value is "pointer to u"
	char* z = static_cast<char*>(x);     // z's value is "pointer to u"
	int z2 = static_cast<int>(u.c);     // z's value is "pointer to u"
	float* z3 = static_cast<float*>(x);     // z's value is "pointer to u"
	double* z4 = static_cast<double*>(x);     // z's value is "pointer to u"
	// inputtype res;
	// int test;
	// test = 76;
	// res.a = test;
	// void*x = &res;
	// char *c;
	// c = static_cast<char*>(res);
	std::cout << "char : " << *z << std::endl;
	std::cout << "int : " << z2 << std::endl;
	std::cout << "float : " << *z3 << std::endl;
	std::cout << "double : " << *z4 << std::endl;
	return (0);
	// int type = identificator(input);
	// res = convert(input, type);
	// printconvert(res);
}