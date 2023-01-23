/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:41:08 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/23 21:09:42 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug ( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info ( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning ( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error ( void )
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	void (Harl::*functPTR)();
	switch (level)
	{
		case ("DEBUG"):
			functPTR = &Harl::debug;
			break;
		case ("INFO"):
			functPTR = &Harl::info;
			break;
		case ("WARNING"):
			functPTR = &Harl::warning;
			break;
		case ("ERROR"):
			functPTR = &Harl::error;
			break;
	}
	this->functPTR();
	//mais c de la merde en fait:
	//soit c'est une boucle de comparaison de level pour trouvver l'index d'un tableau de pointeur sur fonction,
	//soit c'est des switch avec 4 cas aussi, c'est pareil que des if else pour moi
}