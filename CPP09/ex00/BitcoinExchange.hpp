#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>
#include <map>
#include <cstring>
#include <string>
#include <exception>

class BitcoinExchange
{
	private:
		std::map <std::string, float> _database;
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &ori);
		BitcoinExchange &operator=(BitcoinExchange const &ori);
	public:
		~BitcoinExchange(){};
		BitcoinExchange(int ac, char **av);
		void	execute(char *line);
		void	checkData(std::string str);
		void	exploitData(std::string str);
};
