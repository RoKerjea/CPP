#pragma once

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map <std::string, float> _database;
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &ori);
		BitcoinExchange &operator=(BitcoinExchange const &ori);
	public:
		~BitcoinExchange();
		BitcoinExchange(std::string base_file_name);
		void	execute(std::string line);
		void	parseLine(std::string line);
		std::string	parseDate(std::string line);
		float	parseNumber(std::string line);
};