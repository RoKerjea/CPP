/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:37:24 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/27 17:42:22 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string getfile(char *infile_name)
{
	std::ifstream infile;
	infile.open (infile_name);
	if (!infile.is_open())
	{
		std::cout << "Can't open infile!" << std::endl;
		return "";
	}
	std::string	input;
	std::string line;
	while (getline (infile, line))
	{
		if (!input.empty())
			input += "\n";
		input += line;
	}
	infile.close();
	return input;
}

void	find_and_replace(std::string& input, const std::string& s1, const std::string& s2)
{
	size_t	pos = input.find(s1, 0);
	while (pos != std::string::npos)
	{
		input.erase(pos, s1.length());
		input.insert(pos, s2);
		pos = input.find(s1, pos);
	}
}

void	write_to_outfile(std::string output_name, std::string output)
{
	std::ofstream outfile;
	outfile.open (output_name.c_str());
	if (outfile.is_open())
	{
		outfile << output;
		outfile.close();
	}
	else
		std::cout << "Can't open outfile!" << std::endl;
}

int	main(int ac, char** av)
{
	if (ac != 4)
		return (2);
	std::string input = getfile(av[1]);
	if (input.empty())
		return (1);
	find_and_replace(input, av[2], av[3]);

	std::string output_name = av[1];
	output_name += ".replace";
	write_to_outfile(output_name, input);
	return (0);
}
