#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	Bitcoin coin;

	try {
		std::string inputFile = argv[1];
		coin.isInputCorrect(argc, inputFile);
		coin.exchange();
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return 0;
}

void Bitcoin::isInputCorrect(int argc, std::string inputFile) {
	if (argc != 2) throw CustomException(WRONGARG);
	if (inputFile.find(".csv") == false) throw CustomException(WRONGEXT);
	// read the database file and store it in a map
	// read the argument file to a map as well
}