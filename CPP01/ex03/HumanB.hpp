/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:41:58 by rokerjea          #+#    #+#             */
/*   Updated: 2023/02/05 14:38:18 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string	name;
		Weapon	*weapon;
	public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon &weapon);
};

#endif