/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:10:59 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/23 16:14:54 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int	num = 5;
	horde = zombieHorde(num, "Luc");
	for (int i = 0; i < num; i++)
	{
		horde[i].announce();
	}
	for (int i = 0; i < num; i++)
	{
		delete horde[i];
	}
}