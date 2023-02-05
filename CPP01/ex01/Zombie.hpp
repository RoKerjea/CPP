/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:14:18 by rokerjea          #+#    #+#             */
/*   Updated: 2023/02/05 13:39:46 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		~Zombie();
		void	announce( void );
		void	baptise(std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif