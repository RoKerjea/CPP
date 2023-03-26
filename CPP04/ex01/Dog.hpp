#ifndef DOG_HPP
# define DOG_HPP

#include "animal.hpp"

class Dog: virtual public Animal
{
	private:
	*Brain _brain;

	public:
	Dog();
	Dog(const Dog &ori);
	~Dog();
	Dog& operator=(const Dog &ori);

	void	makeSound() const;
};

#endif