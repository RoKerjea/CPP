#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	private:
	std::string	ideas[100];

	public:
	Brain();
	Brain(const Brain &ori);
	Brain& operator=(const Brain &ori);
	~Brain();
};

#endif