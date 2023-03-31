#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource
{
	private:
	AMateria*   known_materia[4];

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& ori);
		MateriaSource& operator=(const MateriaSource& ori);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif