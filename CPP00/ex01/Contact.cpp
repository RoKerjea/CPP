/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:39 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 20:52:28 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

Contact::Contact() {}

Contact::~Contact() {}

/*enum for type of field, in same order as i?*/
void	Contact::fill_contact()
{
	static std::string field_name[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	for (int i = 0; i < 5; i++)
	{
		std::cout << field_name[i] << " = " << std::endl << ">";
		std::cin >> field[i];
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
		return str;
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