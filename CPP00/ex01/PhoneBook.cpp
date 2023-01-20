/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:59:34 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 20:53:56 by rokerjea         ###   ########.fr       */
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
PhoneBook::PhoneBook()
{
	contact_count = 0;
}
//destr
PhoneBook::~PhoneBook() {}

void	PhoneBook::add_contact()
{
	contacts[contact_count % 8].fill_contact();
	contact_count++;
}

void	PhoneBook::search_contact()
{
	int	limit = 7;
	if (!contact_count)
	{
		std::cout << "I have no contact yet, snif" << std::endl;
		return ;
	}
	if (contact_count < 8)
		limit = contact_count - 1;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0 ; i <= limit ; i++)
	{
		std::cout << std::setw(10) << i;
		contacts[i].print_search();
	}
	std::cout << "index to search" << std::endl << ">";
	int	index;
	while(!(std::cin >> index) || index > limit || index < 0)
	{
        std::cin.clear();
        std::cin.ignore(1000, '\n');//should be size max from limits.h
        std::cout << "Invalid index.  Try again: ";
    }
	contacts[index].print_full();
}