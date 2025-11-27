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
	std::ifstream file(_dataFile);

    if (!file.is_open()) {
        std::cerr << "Error: could not open data file." << std::endl;
        exit (1);
    }
	try
	{
		//check header
		std::string line;
		std::getline(file, line);
		checkHeader(line);

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
			_dataMap[date] = value;
		}
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << "Data file : "<< e.what() << '\n';
	}
	
	
	
	
}
void BitcoinExchange::parseInputAndConvert(){

}


void BitcoinExchange::checkHeader(std::string &header){
	if (header.empty()) throw std::runtime_error("Header is missing") ;
	if (header != DATA_FILE_HEADER) throw std::runtime_error("Header mismatch. Expected:" + DATA_FILE_HEADER) ;
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

/*Date format:
YYYY-MM-DD
Check:
length 10
digits at positions 0–3, 5–6, 8–9
'-' at positions 4 and 7

1 ≤ month ≤ 12
1 ≤ day ≤ days_in_month(month, year)
February leap year rule
*/

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
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        throw std::runtime_error("Error: bad date => " + date);
	if (year < 2009)
		throw std::runtime_error("Error: no Bitcoin before 2009 => " + date);
}
 
void BitcoinExchange::splitLine(const std::string &line, std::string &date, std::string &value, char delimiter) const {
	std::string::size_type pos = line.find(delimiter);
    if (pos == std::string::npos)
        throw std::runtime_error("Error: bad input => " + line);
	
	date = line.substr(0, pos);
    value = line.substr(pos + 1);

	if (date.empty() || value.empty())
        throw std::runtime_error("Error: bad input => " + line);
}


/*
beteen 0 an 1000 (can be float)
*/
void BitcoinExchange::checkValue(std::string &value){
	trim(value);
	if (value[0] == '-')
        throw std::runtime_error("Error: not a positive number.");
	std::string::size_type dotPos = value.find('.');
	for (size_t i = 0; i < value.length(); ++i)
    {
        if (i == dotPos)
			continue;
        else if (!std::isdigit(value[i]))
        {
            throw std::runtime_error("Error: bad input => " + value);
        }
    }
	float f = std::atof(value.c_str());
    if (f > 1000.0f)
        throw std::runtime_error("Error: too large a number.");
}