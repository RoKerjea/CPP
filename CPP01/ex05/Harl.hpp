/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:36:02 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/23 18:49:19 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Harl
{
	private:
		void	debug ( void );
		void	info ( void );
		void	warning ( void );
		void	error ( void );
	public:
		void	complain( std::string level );
};
