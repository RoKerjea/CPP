/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:59:34 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 16:43:37 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"
/*
attributs membres => elements d'une struct
fonctions membres/methodes => fonction qui ne peuvent etre utilises
				que par cette classe

en C les fonctions sont les "blocs" d'elements de design,
en C++, c'est les classes
need:
create new contact, destroy/replace oldest if more than 8
get data of all contact for search
get all data of contact num x
destroy contact then itself?
parse input here?
*/

//init
PhoneBook::PhoneBook() contact_count(0)
{}
//destr
PhoneBook::~PhoneBook() {}

void	PhoneBook::add_contact()
{
	this->contact_count++;
	this->contacts[contact_count]::fill_contact;
}

void	PhoneBook::search_contact()
{
	//line for description of each field
	for (i = 0 ; i < 7)
	{
		std::cout << i << std::endl;
		Phonebook->contacts[i]::print_search();
	}
	std::cout << "index to search" << std::endl;//need check for wrong value in cin
	PhoneBook->contacts[std::cin]::print_full;
}