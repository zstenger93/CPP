#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv) {
	try {
		if (argc != 2) throw;
		if (isInputFileCorrect(argv[1]) == false) throw;
		// read the database file and store it in a map
		// read the argument file to a map as well
	} catch (std::exception &error) {
		
    }
}

bool isInputFileCorrect(char *argv) {


	return true;
}