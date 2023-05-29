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
		// std::fstream checkinput(int ac, char **av);
		void	execute(char *line);
		// void	parseLine(std::string line);
		// std::string	parseDate(std::string line);
		void	checkData(std::string str);
		void	exploitData(std::string str);
		// float	parseNumber(std::string line);
};

/*
reflexion:
do i need an object? maybe, to store the map
try catch to instanciate object?
throw if input file pb?
throw if line pb?
probably not, need to continue line by line*/