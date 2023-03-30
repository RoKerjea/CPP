#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: virtual public Animal
{
	private:

	public:
	Dog();
	Dog(const Dog &ori);
	~Dog();
	Dog& operator=(const Dog &ori);

	void	makeSound() const;
};

#endif