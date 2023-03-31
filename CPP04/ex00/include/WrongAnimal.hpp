#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
	std::string type;

	public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &ori);
	WrongAnimal& operator=(const WrongAnimal &ori);
	virtual ~WrongAnimal();

	void makeSound() const;
	std::string getType() const;
};

#endif