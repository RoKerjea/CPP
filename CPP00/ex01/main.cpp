/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:09 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 16:34:57 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
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

int	input_loop(PhoneBook repertoire)
{
	(void)repertoire;
	std::cout << "This is a Phonebook, please type \"ADD\", \"SEARCH\", or \"EXIT\"" << std::endl;
	std::string	cmd;
	std::cin>>cmd;
	if (cmd == "ADD")
	{
		std::cout << "i need to add a contact" << std::endl;
	}
	else if (cmd == "SEARCH")
	{
		std::cout << "i need to search all contacts" << std::endl;
	}
	else if (cmd == "EXIT")
	{
		return (0);
	}
	else
		std::cout << "NO! BAD USER, BAD!" << std::endl;
	return (1);
}

int	main()
{
	/*
	create phonebook, wich will create contacts
	launch loop of input-output
	if loop EXIT, then destroy all and exit
	*/
	PhoneBook repertoire;
	int	end;
	end = 1;
	while (end)
	{
		end = input_loop(repertoire);
	}
	return (0);
}