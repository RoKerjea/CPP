/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:52:40 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 16:42:01 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class	PhoneBook
{
public:
	int 	contact_count;
	Contact	contacts[8];
	// void	PhoneBook (){};//need to create Phonebook with count = 0 and 6 "places" to keep contact
	// void	add_contact();//just a call to contact method? and then update the tab?
	// void	search_contact();//probably 2 parts, preint search all tab, then print full only for tab[x]?
	//what does EXIT do? just quit? or call default destructors?
	//private methods
private:

};