/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:49 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/22 19:04:26 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
private:
	std::string	field[5];

public:
	Contact();
	~Contact();
	void	fill_contact();
	void	print_full();
	void	print_search();
};