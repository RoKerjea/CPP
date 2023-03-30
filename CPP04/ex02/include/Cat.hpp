#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: virtual public Animal
{
	private:
	Brain *brain;

	public:
	Cat();
	Cat(const Cat &ori);
	~Cat();
	Cat& operator=(const Cat &ori);

	void	makeSound() const;
};

#endif