/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:53:04 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/23 16:56:45 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

class HumanA
{
	private:
		std::string	name;
		Weapon	weapon;
	public:
		HumanA(std::string name, Weapon weapon);
}