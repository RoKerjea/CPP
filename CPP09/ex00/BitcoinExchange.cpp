#include "BitcoinExchange.hpp"

// std::fstream BitcoinExchange::checkinput(int ac, char **av)
// {
// 	std::fstream source_base;
// 	struct stat info;

// 	if (ac != 2)
// 		throw std::invalid_argument("Error: need exactly one argument.");

// 	lstat(av[1], &info);
// 	if (S_ISDIR(info.st_mode) || S_ISLNK(info.st_mode))
// 		throw std::invalid_argument("Error: argument is not a file.");

// 	source_base.open(av[1]);
// 	if(source_base.fail())
// 	{
// 		throw std::invalid_argument("Error: could not open file.");
// 	}
// 	return source_base;
// }

BitcoinExchange::BitcoinExchange(int ac, char **av)
{
	(void)av;
	// std::fstream source_base = checkinput(ac, av);
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
			// std::cout << line << std::endl;
			checkData(line);
			/*
			from example, need step:
			checkdata(check input file, line by line)
			exploitdata(same as parse line, more or less)*/
			// parseLine(line);
		}
	}

}

// void	BitcoinExchange::parseLine(std::string line)
// {
// 	// int c = count(line.begin(), line.end(), '|');
// 	// if(c != 1)
// 	// {
// 	// 	std::cout << "Error: bad input => " << line << std::endl;
// 	// 	return; //maybe should be a throw?
// 	// }
// 	int c = line.find('|');
// 	std::string date = parseDate(line.substr(0, c));
// 	float	number = parseNumber(line.substr(c + 1));
// 	if (date.empty() || number == -1.0)
// 		return;
// 	std::cout << date << " ==> " << number << " = " << number * (--_database.upper_bound(date))-> second << std::endl;
// }

// std::string	parseDate(std::string date)
// {
// 	std::string valid = "0123456789-";
// 	int c  = count(date.begin(), date.end(), '-');
// 	if (c != 2 || date[date.size() - 1] != ' ')
// 	{
// 		std::cout << "Error: bad date => " << date << std::endl;
// 		return ("");
// 	}
// 	date.erase (--date.end());
// 	for (unsigned long i = 0; i < date.size(); i++)
// 		if (valid.find(date[i]) == std::string::npos)
// 		{
// 			std::cout << "Error: bad date => " << date << std::endl;
// 			return ("");
// 		}
// 	return (date);
// }

// float	BitcoinExchange::parseNumber(std::string number)
// {
// 	int	c = count(number.begin(), number.end(), '.');
// 	std::string	valid = "0123456789.";
// 	if (number[0] != ' ' || c > 1)
// 	{
// 		std::cout << "Error: bad value => " << number << std::endl;
// 		return (-1.000);
// 	}
// 	number.erase (number.begin());
// 	if (number[0] == '-')
// 	{
// 		std::cout << "Error: not a positive number => " << number << std::endl;
// 		return (-1.000);
// 	}
// 	for (unsigned long  i = 0; i < number.size(); i++)
// 		if (valid.find(number[i]) == std::string::npos)
// 		{
// 			std::cout << "Error: bad value => " << number << std::endl;
// 			return (-1.000);
// 		}
// 	float	value = std::atof(number);
// 	if (value > 1000.000)
// 	{
// 		std::cout << "Error: too large a number => " << number << std::endl;
// 		return (-1.000);
// 	}
// 	return (value);
// }


// static void	getData(std::map<std::string, long double> *data, const char *dataBase) {
// 	std::fstream						dataBaseFile;
// 	std::string							tmp;
// 	std::string							date;
// 	long double							value;

// 	dataBaseFile.open(dataBase, std::fstream::in);
// 	while (dataBaseFile) {
// 		dataBaseFile >> tmp;
// 		if (tmp.find("-") != std::string::npos) {
// 			date = tmp.substr(0, tmp.find(","));
// 			value = atof(tmp.c_str() + strlen(date.c_str()) + 1);
// 			(*data)[date] = value;
// 		}
// 	}
// 	dataBaseFile.close();
// 	return ;
// }

void	BitcoinExchange::exploitData(std::string str) {
	// std::map<std::string, long double>::iterator		it;
	std::string											date;
	long double											val;

	date = str.substr(0, str.find(" "));
	val = atof(str.c_str() + str.find("|") + 2);

	std::cout << date << " => " << val << " = " << val * (--_database.upper_bound(date))->second << std::endl;
	// it = _database.find(date);
	// if (it != _database.end())
	// 	std::cout << date << " => " << val << " = " << val * _database.at(date) << std::endl;
	// else {
	// 	_database[date] = val;
	// 	it = _database.find(date);
	// 	it--;
	// 	std::cout << date << " => " << val << " = " << val * it->second << std::endl;
	// 	_database.erase(date);
	// }
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

// static void	readInputFile(std::map<std::string, long double> data, const char *inputFile) {
// 	std::fstream	ifs;
// 	std::string		tmp;

// 	ifs.open(inputFile, std::fstream::in);
// 	while (std::getline(ifs, tmp)) {
// 		if (tmp.find("date | value") == std::string::npos) {
// 			checkData(data, tmp);
// 		}
// 	}
// 	return ;
// }

// void	btc(const char *dataBase, const char *inputFile) {
// 	std::map<std::string, long double>	data;

// 	getData(&data, dataBase);
// 	readInputFile(data, inputFile);
// 	return ;
// }

// void	checkArgumentErrors(int ac, char **av) {
// 	std::fstream	ifs;
// 	struct stat		info;

// 	if (ac >= 3)
// 		throw std::invalid_argument("Error: too many argument.");
// 	ifs.open(av[1], std::fstream::in);
// 	if (!(ifs.is_open()))
// 		throw std::invalid_argument("Error: could not open file.");
// 	else
// 		ifs.close();
// 	lstat(av[1], &info);
// 	if (S_ISDIR(info.st_mode) || S_ISLNK(info.st_mode))
// 		throw std::invalid_argument("Error: argument is not a file.");
// 	return ;
// }
