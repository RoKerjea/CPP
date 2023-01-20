/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:09 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 20:45:13 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
// #include "Contact.hpp"
#include <iostream>
#include <string>

/*
Need:
one cpp and hpp per classes
and a main.cpp that will use them

two classes:
	-phonebook
	-contact
phonebook can contain up to 8 contacts
if more, replace the oldest one
3method:
	-ADD
	-SEARCH
	-EXIT

cout/cin for terminal info?
	-cin for getting commands and for parameter(contact data, index of contact)
	-cout for command prompt andw
*/

int	main()
{
	PhoneBook repertoire;
	std::string	cmd = "LOL";
	while (cmd != "EXIT")
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