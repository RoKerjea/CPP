/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:52:40 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 20:41:54 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class	PhoneBook
{
public:
	int 	contact_count;
	Contact	contacts[8];

	PhoneBook ();//need to create Phonebook with count = 0 and 8 "places" to keep contact
	~PhoneBook ();
	void	add_contact();//just a call to contact method? and then update the tab?
	void	search_contact();//probably 2 parts, print search all tab, then print full only for tab[x]?
	//private methods
private:
};
/* std::cout << "index to search" << std::endl << ">";//need check for wrong value in cin
	std::string	index;
	std::cin >> index;
	if (index.length() != 1 || index.empty() || !std::isdigit(index[0]))
	{
		std::cout << "invalid index" << std::endl;
		return ;
	}
	int	index_int = index[0] - 48;
	if (index_int >= 0 && index_int <= limit)
		contacts[index].print_full();
	return ; */