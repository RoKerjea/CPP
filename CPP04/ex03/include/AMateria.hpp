#ifndef AMATERIA_HPP
# define AMATERIA_HPP


class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& ori);
		~AMateria();
		AMateria& operator=(const AMateria& ori);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif