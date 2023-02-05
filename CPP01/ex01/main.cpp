/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:10:59 by rokerjea          #+#    #+#             */
/*   Updated: 2023/02/05 13:47:15 by rokerjea         ###   ########.fr       */
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
	delete[] horde;

	num = 12;
	horde = zombieHorde(num, "John");
	for (int i = 0; i < num; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}