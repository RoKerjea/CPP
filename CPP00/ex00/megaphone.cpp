/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:06:56 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/22 18:18:58 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	get_scream(int ac, char **av)
{
	std::string	scream;
	if (ac == 1)
		scream = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
			scream += av[i];
	}
	return (scream);
}

int	main(int ac, char **s)
{
	std::string	scream;
	scream = get_scream(ac, s);
	for (int i = scream.length(); i >= 0; i--)
	{
		scream[i] = std::toupper(scream[i]);
	}
	std::cout << scream << std::endl;
	return 0;
}