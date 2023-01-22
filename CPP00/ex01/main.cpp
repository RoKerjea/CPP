/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:09 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/22 18:08:49 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook repertoire;
	std::string	cmd = "LOL";
	while (cmd != "EXIT" && !std::cin.eof())
	{
		std::cout << "This is a Phonebook, please type \"ADD\", \"SEARCH\", or \"EXIT\"" << std::endl << ">";
		std::cin>>cmd;
		if (cmd == "ADD")
		{
			repertoire.add_contact();
		}
		else if (cmd == "SEARCH")
		{
			repertoire.search_contact();
		}
		else if (cmd != "EXIT")
			std::cout << "NO! BAD USER, BAD!" << std::endl;
	}
	return (0);
}