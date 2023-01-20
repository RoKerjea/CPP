/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:49 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 18:33:17 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
public:
	std::string	field[5];

//constructeur sans parametres avec invite de commande pour remplir les champs?
//print full
	Contact();
	~Contact();
	void	fill_contact(); //maybe create too?
	void	print_full();
	void	print_search();
//print search
};