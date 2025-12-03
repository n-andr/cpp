#include "BitcoinExchange.hpp"
#define DATABASEFILE "data.csv"

int main (int argc, char **argv){

	if (argc != 2){
		std::cerr << "Usage ./btc <file>" << std::endl;
		return 1;
	}

	BitcoinExchange btc(DATABASEFILE, argv[1]);
	btc.parseData();
	btc.parseInputAndConvert();

}