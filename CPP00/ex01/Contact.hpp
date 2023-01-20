/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:49 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/20 15:32:34 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Contact
{
public:
	string	first_name;
	string	last_name;
	string	nickname;
	string	phone_number;
	string	darkest_secret;//or a string data[5]? easier to go through

//constructeur sans parametres avec invite de commande pour remplir les champs?
//print full
	void	fill_contact(); //maybe create too?
	void	print_full();
	void	print_search();
//print search
}