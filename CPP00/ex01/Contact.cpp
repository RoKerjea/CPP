/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:39 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/23 15:02:15 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::fill_contact()
{
	static std::string field_name[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	for (int i = 0; i < 5; i++)
	{
		std::cout << field_name[i] << " = " << std::endl << ">";
		// std::cin >> field[i];//need to protect against empty field
		while(!(std::cin >> field[i]))
		{
			if (std::cin.eof())
			{
				return ;
			}
			std::cin.clear();
			std::cin.ignore(1000, '\n');//should be size max from limits.h
			std::cout << "Invalid string, try again: "<< std::endl;
		}
	}
}

void	Contact::print_full()
{
	static std::string field_name[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	for (int i = 0; i < 5; i++)
	{
		std::cout << std::setw(15) << setiosflags(std::ios::left);
		std::cout << field_name[i] << " : " << field[i]<<std::endl;
	}
}

std::string format_str(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return str;
}

void	Contact::print_search()
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|" << std::setw(10) << format_str(field[i]);
	}
	std::cout << std::endl;
}