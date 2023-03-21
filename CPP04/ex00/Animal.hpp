#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
	std::string type;

	public:
	virtual void makeSound();
	/*every method is virtual, and
	every derived object is inherithing
	and overriding the same method differently*/
}

#endif