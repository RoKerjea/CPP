/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:37:24 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/27 16:41:09 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string getfile(std::ifstream& file)
{

	std::string	content;
	std::string line;
	while (getline (file, line))
	{
		if (!content.empty())
			content += "\n";
		content += line;
	}
	return content;
}

void	find_and_replace(std::string& input, const std::string& s1, const std::string& s2)
{
	size_t	pos = 0;
	pos = input.find(s1, pos);
	while (pos != std::string::npos)
	{
		input.erase(pos, s1.length());
		input.insert(pos, s2);
		pos = input.find(s1, pos);
	}
}

int	main(int ac, char** av)
{
	if (ac != 4)
		return (2);
	std::ifstream infile;
	infile.open (av[1]);
	if (infile.is_open())
	{
		std::string input = getfile(infile);
		infile.close();
	}
	else
		std::cout << "Can't open infile!" << std::endl;
	find_and_replace(input, av[2], av[3]);
	std::string output_name = av[1];
	output_name += ".replace";
	std::ofstream outfile;
	outfile.open (output_name.c_str());
	if (outfile.is_open())
	{
		outfile << input;
		outfile.close();
	}
	else
		std::cout << "Can't open outfile!" << std::endl;
	return (0);
}
