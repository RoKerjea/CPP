#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string base_file_name)
{
	std::ifstream source_base;
	source_base.open(base_file_name);//need protection in case of failure
	if(source_base.fail())
	{
		//error during file.open()
	}
	while (!source_base.eof())
	{
		std::string line;
		getline(source_base, line);
		try
		{
			_database.insert (make_pair(line.substr(0, 10), std::atof(line.substr(11))));
		}
		catch(const std::exception& e) {}
	}
	source_base.close();
}

void	BitcoinExchange::execute(std::string input_file)
{
	std::ifstream input;
	input.open(input_file);
	if(input.fail())
	{
		//error during file.open()
	}
	while (!input.eof())
	{
		std::string line;
		std::getline(input_file, line);
		parseLine(line);
	}
}

void	BitcoinExchange::parseLine(std::string line)
{
	int c = count(line.begin(), line.end(), '|');
	if(c != 1)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return; //maybe should be a throw?
	}
	c = line.find('|');
	std::string date = parseDate(line.substr(0, c));
	float	number = parseNumber(line.substr(c + 1));
	if (date.empty() || number == -1.0)
		return;
	std::cout << date << " ==> " << number << " = " << number * (--_database.upper_bound(date))-> second << std::endl;
}

std::string	parseDate(std::string date)
{
	std::string valid = "0123456789-";
	int c  = count(date.begin(), date.end(), '-');
	if (c != 2 || date[date.size() - 1] != ' ')
	{
		std::cout << "Error: bad date => " << date << std::endl;
		return ("");
	}
	date.erase (--date.end());
	for (unsigned long i = 0; i < date.size(); i++)
		if (valid.find(date[i]) == std::string::npos)
		{
			std::cout << "Error: bad date => " << date << std::endl;
			return ("");
		}
	return (date);
}

float	BitcoinExchange::parseNumber(std::string number)
{
	int	c = count(number.begin(), number.end(), '.');
	std::string	valid = "0123456789.";
	if (number[0] != ' ' || c > 1)
	{
		std::cout << "Error: bad value => " << number << std::endl;
		return (-1.000);
	}
	number.erase (number.begin());
	if (number[0] == '-')
	{
		std::cout << "Error: not a positive number => " << number << std::endl;
		return (-1.000);
	}
	for (unsigned long  i = 0; i < number.size(); i++)
		if (valid.find(number[i]) == std::string::npos)
		{
			std::cout << "Error: bad value => " << number << std::endl;
			return (-1.000);
		}
	float	value = std::atof(number);
	if (value > 1000.000)
	{
		std::cout << "Error: too large a number => " << number << std::endl;
		return (-1.000);
	}
	return (value);
}