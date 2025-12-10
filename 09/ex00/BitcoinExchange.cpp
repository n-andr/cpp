#include "BitcoinExchange.hpp"

//OCF
BitcoinExchange::BitcoinExchange(): _dataMap(), _inputFile(), _dataFile(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const std::string& dataFile, const std::string& inputFile): _dataMap(), _inputFile(inputFile), _dataFile(dataFile){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _dataMap(other._dataMap), _inputFile(other._inputFile), _dataFile(other._dataFile) {}
BitcoinExchange&  BitcoinExchange::operator=(const BitcoinExchange& other){
	if (this != &other){
		_dataMap = other._dataMap;
		_inputFile = other._inputFile;
		_dataFile = other._dataFile;
	}
	return *this;
}
//end OCF



void BitcoinExchange::parseData(){
	//open
	std::ifstream file(_dataFile.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: could not open data file." << std::endl;
        exit (1);
    }
	try
	{
		//check header
		std::string line;
		std::getline(file, line);
		checkHeader(line, DATA_FILE_HEADER);

		//check line by line and skipe empty lines
		while (std::getline(file, line))
		{
			if(line.empty()) continue;
			std::string date;
			std::string value; 
			splitLine(line, date, value, ',');
			checkDate(date);
			checkValue(value);
			if(_dataMap.find(date) != _dataMap.end()) 
				throw std::runtime_error("Error: duplicate date => " + date);
			
			_dataMap[date] = std::strtod(value.c_str(), NULL);
		}
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << "Data file : "<< e.what() << '\n';
	}
	
	
	
	
}
void BitcoinExchange::parseInputAndConvert(){

	std::ifstream file(_inputFile.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        exit (1);
    }
	std::string line;
	std::getline(file, line);
	try
		{checkHeader(line, INPUT_FILE_HEADER);}
	catch(const std::exception& e) 
		{std::cerr << e.what() << '\n';}

	//check line by line and skipe empty lines
	while (std::getline(file, line))
	{
		if(line.empty()) continue;
		try
		{
			std::string date;
			std::string value; 
			splitLine(line, date, value, '|');
			checkDate(date);
			checkValue(value);
			//this check needs to be performed on input file value
			double amount = std::strtod(value.c_str(), NULL);
			if (amount > 1000.0)
				throw std::runtime_error("Error: too large a number.");
			std::map<std::string, double>::iterator it = _dataMap.lower_bound(date);
			if (it == _dataMap.end()) --it;
			else if (it->first != date) { //it->first is the key in the map (the date)
				if (it == _dataMap.begin())
					throw std::runtime_error("Error: no earlier data for date => " + date);
				it--;
			}
			double result = amount * it->second;
			std::cout << date << " => " << amount << " = " << result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}	
}


void BitcoinExchange::checkHeader(std::string &header, const std::string &expected){
	if (header.empty()) throw std::runtime_error("Header is missing") ;
	if (header != expected) throw std::runtime_error("Header mismatch. Expected: " + expected);

}

static void trim(std::string &s)
{
    // remove leading spaces
    while (!s.empty() && (s[0] == ' ' || s[0] == '\t'))
        s.erase(0, 1);

    // remove trailing spaces
    while (!s.empty() && (s[s.size() - 1] == ' ' || s[s.size() - 1] == '\t'))
        s.erase(s.size() - 1, 1);
}

void BitcoinExchange::checkDate(std::string &date){
	
	trim(date);
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') throw std::runtime_error("Error: bad input => " + date);
	
	// Check all digits
	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			throw std::runtime_error("Error: bad input => " + date);
	}

	int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12) throw std::runtime_error("Error: bad date => " + date);

	// Days in each month
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	//Leap year - Feb has 29 days. Year is divisible by 4, BUT if it is divisible by 100 then  Not Leap, BUT if it is also divisible by 400 → then it is a leap year.
	bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (isLeap)
       { daysInMonth[1] = 29;}

    if (day < 1 || day > daysInMonth[month - 1])
        {throw std::runtime_error("Error: bad date => " + date);}

	if (year < 2009)
		{throw std::runtime_error("Error: no Bitcoin before 2009 => " + date);}
}
 
void BitcoinExchange::splitLine(const std::string &line, std::string &date, std::string &value, char delimiter) const {
	std::string::size_type pos = line.find(delimiter);
    if (pos == std::string::npos)
        {throw std::runtime_error("Error: bad input => " + line);}
	
	date = line.substr(0, pos);
    value = line.substr(pos + 1);

	if (date.empty() || value.empty())
        {throw std::runtime_error("Error: bad input => " + line);}
}

void BitcoinExchange::checkValue(std::string &value){
	trim(value);
	if (value[0] == '-')
        throw std::runtime_error("Error: not a positive number.");
	// Use strtod for numeric validation
    char *endptr = NULL;
    std::strtod(value.c_str(), &endptr);

    // strtod stops at first invalid char check that everything was consumed
    if (*endptr != '\0')
        throw std::runtime_error("Error: bad input => " + value);
}
