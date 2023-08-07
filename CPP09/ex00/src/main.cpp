#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	try {
		Bitcoin coin;
		// std::map<std::string, float> print = coin.getCsvData();
		// for (std::map<std::string, float>::iterator printIt = print.begin(); printIt != print.end();
		// 	 printIt++)
		// 	std::cout << printIt->first << "," << printIt->second << std::endl;
		coin.isInputCorrect(argc, argv);
		// coin.exchange();
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return 0;
}

