#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(int ac, char **av)
{
	(void)av;
	std::fstream source_base;
	struct stat info;

	if (ac != 2)
		throw std::invalid_argument("Error: need exactly one argument.");

	lstat("data.csv", &info);
	if (S_ISDIR(info.st_mode) || S_ISLNK(info.st_mode))
		throw std::invalid_argument("Error: argument is not a file.");

	source_base.open("data.csv");
	if(source_base.fail())
	{
		throw std::invalid_argument("Error: could not open file.");
	}
	std::string							date;
	long double							value;
	while (!source_base.eof())
	{
		std::string line;
		source_base >> line;
		try
		{
			date = line.substr(0, line.find(","));
			value = atof(line.c_str() + strlen(date.c_str()) + 1);
			_database.insert (make_pair(date, value));
		}
		catch(const std::exception& e) {}
	}
	source_base.close();
}

void	BitcoinExchange::execute(char *input_file)
{
	std::ifstream input;
	struct stat info;

	lstat(input_file, &info);
	if (S_ISDIR(info.st_mode) || S_ISLNK(info.st_mode))
		throw std::invalid_argument("Error: argument is not a file.");
	input.open(input_file, std::fstream::in);
	if(input.fail())
	{
		throw std::invalid_argument("Error: could not open file.");
	}
	std::string line;
	while (std::getline(input, line))
	{
		if (line.find("date | value") == std::string::npos)
		{
			checkData(line);
		}
	}
}

void	BitcoinExchange::exploitData(std::string str) {
	std::string											date;
	long double											val;

	date = str.substr(0, str.find(" "));
	val = atof(str.c_str() + str.find("|") + 2);

	std::cout << date << " => " << val << " = " << val * (--_database.upper_bound(date))->second << std::endl;
	return ;
}

void	BitcoinExchange::checkData(std::string str) {
	int		year;
	int		month;
	int		day;
	long	val;

	year = atoi(str.c_str());
	if (year < 2009) {
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	month = atoi(str.c_str() + 5);
	if (month < 1 || month > 12) {
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	day = atoi(str.c_str() + 8);
	if (day < 1 || day > 31) {
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	val = atol(str.c_str() + 13);
	if (val < 0 || val > 1000) {
		if (val < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (val > 1000)
			std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	if (year == 2009 && month == 1 && day < 2) {
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	exploitData(str);
	return ;
}

