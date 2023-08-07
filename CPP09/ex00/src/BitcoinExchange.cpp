#include "../includes/BitcoinExchange.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Bitcoin::Bitcoin() : csvDataBase() {
	std::ifstream csvFile("./src/data.csv");
	std::string line;

	if (csvFile.is_open()) {
		int i = 0;
		while (std::getline(csvFile, line))
			if (i++ > 0) csvDataBase.insert(std::make_pair(saveDate(line), saveRate(line)));
		csvFile.close();
		return;
	}
	csvFile.close();
	
}
Bitcoin::~Bitcoin() {}
Bitcoin::Bitcoin(Bitcoin const &cpy) { *this = cpy; }

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

Bitcoin &Bitcoin::operator=(Bitcoin const &cpy) {
	this->csvDataBase = cpy.csvDataBase;
	return *this;
}

/*_______________________________________ NESTED CLASSES ________________________________________*/

Bitcoin::CustomException::CustomException(const std::string &word) : message(word) {
    // Implement the constructor logic here, if needed
}

// Define the what() function
const char *Bitcoin::CustomException::what() const throw() {
    // Implement the what() function logic here, if needed
    return message.c_str();
}

// Define the CustomException destructor
Bitcoin::CustomException::~CustomException() throw() {
    // Implement the destructor logic here, if needed
}

/*__________________________________________ FUNCTIONS __________________________________________*/

std::string Bitcoin::saveDate(std::string line) const {
	size_t pos = line.find(",");
	std::string date = line.substr(0, pos);
	return date;
}

float Bitcoin::saveRate(std::string line) {
	size_t pos = line.find(",") + 1;
	std::string rate = line.substr(pos);
	float exchangeRate = std::stof(rate);
	return exchangeRate;
}

void Bitcoin::isInputCorrect(int argc, char **argv) {
	if (argc != 2) throw CustomException(WRONGARG);
	std::string inputFile = argv[1];
	if (inputFile.find(".txt") == std::string::npos) throw CustomException(WRONGEXT);
	// read the database file and store it in a map
	// read the argument file to a map as well
}

/*___________________________________________ SETTERS ___________________________________________*/
/*___________________________________________ GETTERS ___________________________________________*/

std::map<std::string, float> Bitcoin::getCsvData() { return csvDataBase; }