#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria*	bag[4];

	public:
		Character();
		Character(std::string name);
		Character(const Character& ori);
		~Character();
		Character& operator=(const Character& ori);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif