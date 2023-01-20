/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:06:56 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 14:06:13 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **s)
{
	std::string	scream;
	if (ac == 1)
		scream = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		scream = s[1]; //need to add every string if ac > 2
	for (int i = scream.length(); i >= 0; i--)
	{
		scream[i] = std::toupper(scream[i]);
	}
	std::cout << scream << std::endl;
	return 0;
}