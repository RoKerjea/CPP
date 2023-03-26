#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
	std::string type;

	public:
	Animal();
	Animal(const Animal &ori);
	Animal& operator=(const Animal &ori);
	~Animal();

	virtual void makeSound();
	std::string getType();
}

#endif