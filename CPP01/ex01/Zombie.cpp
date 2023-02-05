/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:16:14 by rokerjea          #+#    #+#             */
/*   Updated: 2023/02/05 13:39:33 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::baptise(std::string name)
{
	_name = name;
}