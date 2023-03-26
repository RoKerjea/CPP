#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class A_Animal
{
	protected:
	std::string type;

	public:
	A_Animal();
	A_Animal(const A_Animal &ori);
	A_Animal& operator=(const A_Animal &ori);
	~A_Animal();

	virtual void makeSound() = 0;
	std::string getType();
}

#endif