/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:15:37 by rokerjea          #+#    #+#             */
/*   Updated: 2023/02/21 15:40:03 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string brainStr;
	brainStr = "HI THIS IS BRAIN";

	std::string *stringPTR = &brainStr;

	std::string &stringREF = brainStr;

	std::cout << "adress of string = " << &brainStr <<std::endl;
	std::cout << "adress in stringPTR = " << stringPTR <<std::endl;
	std::cout << "adress in stringREF = " << &stringREF <<std::endl;

	std::cout << "string = " << brainStr << std::endl;
	std::cout << "string pointed by stringPTR = " << *stringPTR << std::endl;
	std::cout << "string pointed by stringREF = " << stringREF << std::endl;
}