#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) :
_data(copy._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy)
		this->_data = copy._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::loadDB(const std::string &dbPath) {
	std::ifstream	file(dbPath.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open database file." << std::endl;
		return ;
	}

	std::string line;
	// lets skip first line "date,exchange_rate"
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t comma = line.find(',');
		if (comma != std::string::npos) {
			std::string	date = line.substr(0, comma);
			//Extract second part, from comma to end and convert & cast it to float
			float rate = static_cast<float>(std::atof(line.substr(comma + 1).c_str()));
			_data[date] = rate;
		}
	}
	file.close();
}

bool	BitcoinExchange::isValidDate(const std::string &date) {
	if(date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1)
		return false;
	
	//Max days depending on the month:
	int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Adjustment for leap years in February:
	if ((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0)) 
		daysPerMonth[1] = 29;

	if (day > daysPerMonth[month - 1])
		return false;
	
	return true;
}

void	BitcoinExchange::processInput(const std::string &inputPath) {
	std::ifstream file(inputPath.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file" << std::endl;
		return;
	}

	std::string line;
	// Skip "date | value"
	std::getline(file, line);

	while (std::getline(file, line)) {
		//validat format. Should contain a '|'
		size_t sep = line.find('|');
		if (sep == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = line.substr(0, sep);
		//Remove final spaces in the date:
		size_t	last = date.find_last_not_of(" \t");
		if (last != std::string::npos)
			date.erase(last + 1);

		// Check if a valid date:
		if (!isValidDate(date)){
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		

		float	val = static_cast<float>(std::atof(line.substr(sep + 1).c_str()));

		if (val < 0) {
			std::cout << "Error: not a positive number" << std::endl;
			continue;
		}
		if (val > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		//Search for the date:
		//lower_bound returns the first element that is NOT less than (>=)
		std::map<std::string, float>::iterator it = _data.lower_bound(date);

		if (it != _data.end() && it->first == date) {
			// If we find the exact date, we print the date and value:
			std::cout << date << " => " << val << " = " << (val * it->second) << std::endl;
		} else {
			// if not exact date: if it is begin() there are no previout dates:
			if (it == _data.begin()) {
				std::cout << "Error: no data found for " << date << std::endl;
			} else {
				// we go back one to get the nearest lower date:
				--it;
				std::cout << date << " => " << val << " = " << (val * it->second) << std::endl;
			}
		}
	}
}
