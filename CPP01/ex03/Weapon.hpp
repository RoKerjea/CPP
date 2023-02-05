/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:42:26 by rokerjea          #+#    #+#             */
/*   Updated: 2023/02/05 14:36:44 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string weapon_type);
		void	setType(std::string type_to_set);
		std::string const &getType() const;
};

#endif