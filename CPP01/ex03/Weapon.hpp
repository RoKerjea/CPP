/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:42:26 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/23 16:45:21 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Weapon
{
	private:
		std::string	type;
	public:
		void	setType(std::string type_to_set);
		std::string *getType();
};