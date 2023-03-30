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
	virtual ~Animal();

	virtual void makeSound() const;
	std::string getType() const;
};

#endif