/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:41:08 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/27 18:52:51 by rokerjea         ###   ########.fr       */
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

int	identifiy_cases (std::string level)
{
	std::string type[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == type[i])
			return (i);
	}
	return (4);
}

typedef void(Harl::*ptr_func)(void);

void	Harl::complain( std::string level )
{
	ptr_func functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int cases = identifiy_cases (level);
	if (cases <= 3)
		(this->*functions[cases])();
}