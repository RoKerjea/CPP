/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:52:40 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/22 18:09:01 by rokerjea         ###   ########.fr       */
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
private:
};
