#include "MutantStack.hpp"

template<typename T>
MutantStack::MutantStack()
{}

MutantStack::MutantStack(MutantStack const &copy) : std::stack<T>(copy)
{}

MutantStack::~MutantStack(void)
{}

MutantStack MutantStack::&operator=(MutantStack const &)
{
	return *this;
}

iterator MutantStack::begin(void)
{
	return this->c.begin();
}
iterator MutantStack::end(void)
{
	eturn this->c.end();
}