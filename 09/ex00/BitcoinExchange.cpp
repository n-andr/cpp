#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _dataMap(), _inputFile(), _dataFile(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const std::string& dataFile, const std::string& inputFile): _dataMap(), _inputFile(inputFile), _dataFile(dataFile){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _dataMap(other._dataMap), _inputFile(other._inputFile), _dataFile(other._dataFile) {}
BitcoinExchange::BitcoinExchange& operator=(const BitcoinExchange& other){
	if (this != &other){
		_dataMap = other._dataMap;
		_inputFile = other._inputFile;
		_dataFile = other._dataFile;
	}
	return *this;
}

void BitcoinExchange::parseData(){
	//open
	std::ifstream file(_dataFile);

    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
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
			//split by ,
			splitLine(line, date, value);
			checkDate(date);
			checkValue(value);
			_dataMap[date] = value;
		}
		

	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
	
}
void BitcoinExchange::parseInput(){

}


void BitcoinExchange::checkHeader(std::string header){
	if (header.empty()) throw std::runtime_error("Header is missing") ;
	if (header != DATA_FILE_HEADER) throw std::runtime_error("Header mismatch. Expected:" + DATA_FILE_HEADER) ;
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
void BitcoinExchange::checkDate(std::string date){
	


	if(_dataMap.find(date) != _dataFile.end()) throw std::runtime_error("Error: duplicate date => " + date);
}

void BitcoinExchange::splitLine(const std::string &line, std::string &date, std::string &value) const {
	std::string::size_type pos = line.find(',');
    if (pos == std::string::npos)
        throw std::runtime_error("Error: bad input => " + line);
	
	date = line.substr(0, pos);
    value = line.substr(pos + 1);

	if (date.empty() || value.empty())
        throw std::runtime_error("Error: bad input => " + line);
}