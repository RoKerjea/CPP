/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:59:34 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/22 18:10:17 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_count = 0;
}

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
		if (std::cin.eof())
		{
			return ;
		}
        std::cin.clear();
        std::cin.ignore(1000, '\n');//should be size max from limits.h
        std::cout << "Invalid index.  Try again: "<< std::endl;
    }
	contacts[index].print_full();
}