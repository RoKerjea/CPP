#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{
	private:

	public:
	WrongCat();
	WrongCat(const WrongCat &ori);
	~WrongCat();
	WrongCat& operator=(const WrongCat &ori);

	void	makeSound() const;
};

#endif