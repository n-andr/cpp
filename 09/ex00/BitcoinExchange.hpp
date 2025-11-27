#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>

#define DATA_FILE_HEADER "date,exchange_rate"

class BitcoinExchange
{
private:
	std::map<std::string, double> _dataMap;
	std::string _inputFile;
	std::string _dataFile;
public:
	BitcoinExchange();
	BitcoinExchange(const std::string& dataFile, const std::string& inputFile);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);	
	~BitcoinExchange();

	parseData();
	parseInput();

	checkHeader(std::string header);
	checkDate(std::string date);
	splipLine(std::string line, std::string date, std::string value) const;

};

#endif