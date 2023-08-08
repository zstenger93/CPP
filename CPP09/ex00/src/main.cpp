#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	try {
		Bitcoin coin;
		coin.isInputCorrect(argc, argv);
		coin.exchange();
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return 0;
}

void Bitcoin::printMap(std::map<std::string, float> dataBaseType) {
	std::map<std::string, float> print = dataBaseType;
	int i = 0;
	for (std::map<std::string, float>::iterator printIt = print.begin(); printIt != print.end();
		 printIt++)
		std::cout << i++ << ": " << printIt->first << " | " << printIt->second << std::endl;
}

void Bitcoin::printVector(std::vector<std::string> dataBaseType) {
	std::vector<std::string> print = dataBaseType;
	int i = 0;
	for (std::vector<std::string>::iterator printIt = print.begin(); printIt != print.end();
		 printIt++)
		std::cout << i++ << ": " << *printIt << std::endl;
	
}