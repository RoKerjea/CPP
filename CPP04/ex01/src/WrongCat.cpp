#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "It's a ... Cat? Maybe?\n";
}

WrongCat::WrongCat(const WrongCat &ori)
{
	type = ori.getType();
	std::cout << "There's more Cats(?) now\n";
}

WrongCat::~WrongCat()
{
	std::cout << "Well, might be for the best!\n";
}

WrongCat& WrongCat::operator=(const WrongCat &ori)
{
	if (this == &ori)
		return *this;
	this->~WrongCat();
	new (this) WrongCat(ori);
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Quack!\n";
}