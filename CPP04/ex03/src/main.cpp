// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* Char = new Character("Char");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	Char->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	Char->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	Char->use(0, *bob);
// 	Char->use(1, *bob);
// 	delete bob;
// 	delete Char;
// 	delete src;
// 	return 0;
// }

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"

# include "AMateria.hpp"
# include "Character.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

int	main (void)
{

	std::cout << RED << "--- MateriaSource learn 4 materias ---" << RESET << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure ());

	AMateria*	tmp;

	// ERROR HANDLING

	std::cout << RED << "--- Nothing should happen here ---" << RESET << std::endl;
	src->learnMateria(NULL);

	tmp = new Ice ();
	src->learnMateria(tmp);
	delete (tmp);

	std::cout << RED << "--- Char1 is created and equip 4 materias created by MateriaSource ---" << RESET << std::endl;

	ICharacter* Char = new Character("Char1");

	AMateria*	tmp2 = src->createMateria("ice");
	Char->equip(tmp2);
	AMateria*	tmp3 = src->createMateria("cure");
	Char->equip(tmp3);
	AMateria*	tmp4 = src->createMateria("ice");
	Char->equip(tmp4);
	AMateria*	tmp5 = src->createMateria("cure");
	Char->equip(tmp5);

	// ERROR HANDLING
	std::cout << RED << "--- Nothing should happen here (No bugs or leaks either) ---" << RESET << std::endl;

	Char->unequip (2);
	Char->equip(NULL);
	Char->equip(tmp4);
	AMateria*	tmp7 = src->createMateria("blabla");
	tmp7 = src->createMateria("cure");
	Char->equip(tmp7);
	delete tmp7;

	std::cout << RED << "--- Char1 use his equipped materias on a new Char ---" << RESET << std::endl;

	ICharacter* bob = new Character("bob");
	Char->use(0, *bob);
	Char->use(1, *bob);
	Char->use(2, *bob);
	Char->use(3, *bob);
	Char->use(4, *bob);

	std::cout << RED << "--- Char1 unequip one of his materias to equip another one ---" << RESET << std::endl;

	// unequip ne delete pas donc s'en occuper dans le main
	Char->unequip (2);
	Char->use(2, *bob);
	delete tmp4;

	tmp = src->createMateria ("cure");
	Char->equip (tmp);
	Char->use (2, *bob);

	std::cout << RED << "--- a new Char3 equip a materia, char4 is copied from char3,\nchar3 unequip his materia and can't use it anymore,\nchar4 should still be able to use it  ---" << RESET << std::endl;

	Character Char1 ("Char1");
	tmp = src->createMateria ("ice");
	Char1.equip (tmp);
	Character Char2 (Char1);
	Char1.unequip (0);
	delete tmp;
	Char1.use (0, *bob);
	Char2.use (0, *bob);

	delete Char;
	delete bob;
	delete src;
	return 0;
}