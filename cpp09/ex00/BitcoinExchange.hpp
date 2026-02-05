#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
private:
	/*I decided using map because it stores its elements in an ordered manner,
	 allowing for efficient searching of the previous date */
	std::map<std::string, float>	_data;
	bool	isValidDate(const std::string &date);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	~BitcoinExchange();

	void	loadDB(const std::string &dbPath);
	void	processInput(const std::string &inputPath);
};

#endif