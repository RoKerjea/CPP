/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:52:40 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/22 19:04:52 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class	PhoneBook
{
private:
	int 	contact_count;
	Contact	contacts[8];
public:
	PhoneBook ();
	~PhoneBook ();
	void	add_contact();
	void	search_contact();
};
