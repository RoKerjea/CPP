/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:41:58 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/23 18:49:17 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include <string>
#include <iostream>

class HumanB
{
	private:
		std::string	name;
		Weapon	weapon;
	public:
		HumanB(std::string name);
		void	attack();
		void	setWeapon(Weapon weapon);
};