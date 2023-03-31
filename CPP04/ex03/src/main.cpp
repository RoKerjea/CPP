// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

# include "AMateria.hpp"
# include "Character.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

int	main (void)
{
	std::cout << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure ());

	AMateria*	tmp;

	// ERROR HANDLING
	src->learnMateria(NULL);
	
	tmp = new Cure ();
	src->learnMateria(tmp);
	delete (tmp);

	std::cout << std::endl;
	
	ICharacter* me = new Character("Me");

	AMateria*	tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	AMateria*	tmp3 = src->createMateria("cure");
	me->equip(tmp3);
	AMateria*	tmp4 = src->createMateria("ice");
	me->equip(tmp4);
	AMateria*	tmp5 = src->createMateria("cure");
	me->equip(tmp5);

	// ERROR HANDLING
	me->equip(NULL);
	
	AMateria*	tmp7 = src->createMateria("blabla");
	tmp7 = src->createMateria("cure");
	me->equip(tmp7);
	delete tmp7;

	std::cout << std::endl;
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	std::cout << std::endl;
	
	// unequip ne delete pas donc s'en occuper dans le main
	// tmp = me->getMateria (2);
	me->unequip (2);
	delete tmp4;
	// delete tmp;

	tmp = src->createMateria ("ice");
	me->equip (tmp);
	me->use (2, *bob);

	std::cout << std::endl;

	Character me1 ("me1");
	tmp = src->createMateria ("ice");
	me1.equip (tmp);
	Character me2 (me1);
	me1.unequip (0);
	delete tmp;
	me1.use (0, *bob);
	me2.use (0, *bob);
	
	delete me;
	delete bob;
	delete src;
	return 0;
}