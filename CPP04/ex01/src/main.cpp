#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"

#define N 10

int main()
{
	{
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		delete j;
		delete i;
	}
	{
		Animal*		tab[N];
		int 		i;

		std::cout << RED << "--- Animal tab creation ---" << RESET << std::endl;

		i = -1;
		while (++i < N)
		{
			if (i < N / 2)
				tab[i] = new Dog();
			else
				tab[i] = new Cat();
			std::cout << std::endl;
		}
		i = -1;
		while (++i < N)
			std::cout << "Type of animal number " << i << " : " << tab[i]->getType() << std::endl;		
		std::cout << std::endl;

		std::cout << RED << "--- Animal tab destruction ---" << RESET << std::endl;

		i = -1;
		while (++i < N)
			delete tab[i];
		std::cout << std::endl;

		std::cout << RED << "--- deep copy new / delete ---" << RESET << std::endl;

		Dog			*Rantanplan = new Dog();
		Cat			*Grosminet = new Cat();
		Cat			*Vermithrax = new Cat(*Grosminet);
		Dog			*Lassie = new Dog(*Rantanplan);

		delete Lassie;
		delete Vermithrax;
		delete Rantanplan;
		delete Grosminet;

		std::cout << RED << "--- deep copy constructor / destructor ---" << RESET << std::endl;

		Dog		Oulet;
		Dog		SuperOulet = Oulet;

		Cat		Norminet;
		Cat		SuperNorminet = Norminet;
	}
	{
	std::cout << RED << "--- New tests ---" << RESET << std::endl;
 	Animal	*animalArray [10];
	int		arrayHalf = 5;

	for (int i = 0; i < arrayHalf; i++)
	{
		animalArray [i] = new Dog ();
		animalArray [arrayHalf + i] = new Cat ();
	}
	
	std::cout << std::endl;
	animalArray[3]->makeSound ();
	animalArray[9]->makeSound ();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animalArray [i];

	const Animal *	animal = new Animal ();
	const Animal *	dog = new Dog ();
	const Animal *	cat = new Cat ();
	
	std::cout << std::endl;
	std::cout << animal->getType () << "'s sound : ";
	animal->makeSound ();
	std::cout << dog->getType () << "'s sound : ";
	dog->makeSound ();
	std::cout << cat->getType () << "'s sound : ";
	cat->makeSound ();
	std::cout << std::endl;

	delete dog;
	delete cat;
	delete animal;
	
	std::cout << std::endl;
	
	Cat *	kitty1 = new Cat ();
	Cat *	kitty2 = new Cat (*kitty1);
	Cat *	kitty3 = new Cat ();
	*kitty3 = *kitty1;

	delete kitty1;
	delete kitty2;
	delete kitty3;
	}
	return (0);
}