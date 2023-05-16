#include "Serializer.hpp"

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"

int main()
{
	std::cout << RED << "//-----------   test successif   -----------//" << RESET << std::endl;
	{
		Data	*ptr;
		Data	*newptr;
		Serializer obj2;

		ptr = new Data;
		ptr->c = 'c';
		ptr->x = 42;

		uintptr_t	test = obj2.serialize(ptr);
		newptr = obj2.deserialize(test);

		std::cout << GREEN << "adresse du pointeur sur Data avant serial : " << ptr << RESET << std::endl;
		std::cout << ptr->c << std::endl;
		std::cout << ptr->x << std::endl << std::endl;

		std::cout << YELLOW << "on serialize" << RESET << std::endl;
		std::cout << "comparaison ptr / ptr serializé : " << ptr << " | " << test << RESET << std::endl;
		std::cout << ptr->c << std::endl;
		std::cout << ptr->x << std::endl;

		std::cout << YELLOW << "on deserialize" << RESET << std::endl;
		std::cout << "comparaison ptr / ptr déserializé : " << ptr << " | " << newptr << RESET << std::endl;
		std::cout << newptr->c << std::endl;
		std::cout << newptr->x << std::endl;

		delete ptr;
	}
	std::cout << RED << "//-----------   test combiné   -----------//" << RESET << std::endl;
	{
		Data	*ptr;
		Serializer obj1;
		ptr = new Data;
		ptr->c = 'a';
		ptr->x = 25;

		std::cout << std::endl << GREEN << "adresse du pointeur sur Data avant serial/deserial : "<< RESET << ptr << std::endl;
		std::cout << ptr->c << std::endl;
		std::cout << ptr->x << std::endl;

		std::cout << YELLOW << "on serialize ptr, et deserialize dans la foulée" << RESET << std::endl;
		Data *newptr = obj1.deserialize(obj1.serialize(ptr));

		std::cout << std::endl << GREEN << "adresse du pointeur sur Data apres serial/deserial : "<< RESET << ptr << std::endl;
		std::cout << newptr->c << std::endl;
		std::cout << newptr->x << std::endl;

		delete ptr;
	}
	return (0);
}