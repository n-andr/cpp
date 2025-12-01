#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>		// for strtod()

#define DATA_FILE_HEADER "date,exchange_rate"
#define INPUT_FILE_HEADER "date | value"


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

	void parseData();
	void parseInputAndConvert();

	void checkHeader(std::string &header, const std::string &expected);
	void checkDate(std::string &date);
	void checkValue(std::string &value);
	void splitLine(const std::string &line, std::string &date, std::string &value, char delimiter) const;

};

#endif