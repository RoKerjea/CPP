// #include "MutantStack.hpp"
// #include <iostream>

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

#include "MutantStack.hpp"
#include <list>

#define RESET "\e[0m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYAN "\e[0;36m"
#define ORANGE "\e[38;2;255;165;0m"

int main()
{
	{
		std::cout << std::endl << RED << "TEST DU SUJET" << RESET << std::endl;
		std::cout << std::endl << GREEN << "Avec la MutantStack !" << RESET << std::endl;

		MutantStack<int>	mstack;

		std::cout << std::endl << ORANGE << "1) On cree une stack et on y entre 2 valeurs" << RESET << std::endl;
		std::cout << "is the stack empty ? true = 1 / false = 0 --> " << mstack.empty() << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << "size :		" << mstack.size() << std::endl;	
		std::cout << "top value :	" << mstack.top() << std::endl;

		std::cout << std::endl << ORANGE << "2) On retire la valeur du top de la stack" << RESET << std::endl;
		mstack.pop();
		std::cout  << "size :		" << mstack.size() << std::endl;
		std::cout << "top value :	" << mstack.top() << std::endl;

		std::cout << std::endl << ORANGE << "3) On ajoute plein de valeurs" << RESET << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(42);
		mstack.push(4242);
		mstack.push(24);
		mstack.push(2424);
		mstack.push(0);

		std::cout  << "size :		" << mstack.size() << std::endl;
		std::cout << "top value :	" << mstack.top() << std::endl;

		std::cout << std::endl << ORANGE << "4) On affiche le contenu de la stack (bottom to top) grace au MutantStack Iterator !" << RESET << std::endl;	
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "is the stack empty ? true = 1 / false = 0 --> " << mstack.empty() << std::endl;

	//---------------------------//

		std::cout << std::endl << GREEN << "Test du constructeur par copie" << RESET << std::endl;
		MutantStack<int>	copystack = mstack;

		std::cout  << "size :		" << copystack.size() << std::endl;
		std::cout << "top value :	" << copystack.top() << std::endl;

		std::cout << std::endl << ORANGE << "4) On affiche le contenu de copystack (bottom to top) grace au MutantStack Iterator !" << RESET << std::endl;	
		// MutantStack<int>::iterator itc = copystack.begin();
		// MutantStack<int>::iterator itec = copystack.end();
		it = copystack.begin();
		ite = copystack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	//---------------------------//
		std::cout << std::endl << GREEN << "Avec la stack originelle !" << RESET << std::endl;
		
		std::stack<int>	s(mstack);
		std::cout << std::endl << ORANGE << "1) On cree une stack de type stack originelle, copie de notre mutantStack" << RESET << std::endl;
		std::cout << "size :		" << s.size() << std::endl;	
		std::cout << "top value :	" << s.top() << std::endl;

		std::cout << std::endl << ORANGE << "2) On retire la valeur du top de la stack" << RESET << std::endl;
		s.pop();
		std::cout  << "size :		" << s.size() << std::endl;
		std::cout << "top value :	" << s.top() << std::endl;

		std::cout << std::endl << ORANGE << "3) On ajoute une valeur" << RESET << std::endl;
		s.push(258963);

		std::cout  << "size :		" << s.size() << std::endl;
		std::cout << "top value :	" << s.top() << std::endl;
	}
//---------------------------//
	{
		std::cout << std::endl << RED << "COMPARAISON AVEC CONTAINER LIST" << RESET << std::endl;
	
		std::list<int>	lst;

		std::cout << std::endl << ORANGE << "1) On cree une list et on y entre 2 valeurs" << RESET << std::endl;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "size :		" << lst.size() << std::endl;	
		std::cout << "top value :	" << lst.back() << std::endl;

		std::cout << std::endl << ORANGE << "2) On retire la valeur du back de la lst ( = top de la stack !)" << RESET << std::endl;
		lst.pop_back();
		std::cout  << "size :		" << lst.size() << std::endl;
		std::cout << "top value :	" << lst.back() << std::endl;

		std::cout << std::endl << ORANGE << "3) On ajoute plein de valeurs" << RESET << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(42);
		lst.push_back(4242);
		lst.push_back(24);
		lst.push_back(2424);
		lst.push_back(0);

		std::cout  << "size :		" << lst.size() << std::endl;
		std::cout << "top value :	" << lst.back() << std::endl;

		std::cout << std::endl << ORANGE << "4) On affiche le contenu de la stack (bottom to top) grace au MutantStack Iterator !" << RESET << std::endl;	
		std::list<int>::iterator itl = lst.begin();
		std::list<int>::iterator itel = lst.end();
		++itl;
		--itl;
		while (itl != itel)
		{
			std::cout << *itl << std::endl;
			++itl;
		}
	}

	return 0;
}