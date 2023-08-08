#include "../includes/BitcoinExchange.hpp"

#include <sstream>
#include <string>

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Bitcoin::Bitcoin() : csvDataBase() {
	std::ifstream csvFile("./src/data.csv");
	std::string line;

	validMonths.insert(validMonths.end(), "01");
	validMonths.insert(validMonths.end(), "02");
	validMonths.insert(validMonths.end(), "03");
	validMonths.insert(validMonths.end(), "04");
	validMonths.insert(validMonths.end(), "05");
	validMonths.insert(validMonths.end(), "06");
	validMonths.insert(validMonths.end(), "07");
	validMonths.insert(validMonths.end(), "08");
	validMonths.insert(validMonths.end(), "09");
	validMonths.insert(validMonths.end(), "10");
	validMonths.insert(validMonths.end(), "11");
	validMonths.insert(validMonths.end(), "12");
	validDays.insert(validDays.end(), "01");
	validDays.insert(validDays.end(), "02");
	validDays.insert(validDays.end(), "03");
	validDays.insert(validDays.end(), "04");
	validDays.insert(validDays.end(), "05");
	validDays.insert(validDays.end(), "06");
	validDays.insert(validDays.end(), "07");
	validDays.insert(validDays.end(), "08");
	validDays.insert(validDays.end(), "09");
	for (int i = 10; i < 32; i++) validDays.insert(validDays.end(), std::to_string(i));
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

Bitcoin::CustomException::CustomException(const std::string &word) : message(word) {}
const char *Bitcoin::CustomException::what() const throw() { return message.c_str(); }
Bitcoin::CustomException::~CustomException() throw() {}

/*__________________________________________ FUNCTIONS __________________________________________*/

std::string Bitcoin::saveDate(std::string line) const {
	size_t pos = line.find(",");
	return line.substr(0, pos);
}

float Bitcoin::saveRate(std::string line) const {
	size_t pos = line.find(",") + 1;
	std::string rate = line.substr(pos);
	return std::stof(rate);
}

void Bitcoin::isInputCorrect(int argc, char **argv) {
	if (argc != 2) throw CustomException(WRONGARG);
	std::string inputFile = argv[1];
	if (inputFile.find(".txt") == std::string::npos) throw CustomException(WRONGEXT);
	saveInput(inputFile);
}

void Bitcoin::saveInput(std::string inputFile) {
	std::string line;
	std::ifstream input("./" + inputFile);
	if (input.is_open()) {
		int i = 0;
		while (std::getline(input, line))
			if (i++ > 0) inputDataBase.insert(inputDataBase.end(), line);
		// printVector(getInputData());
		input.close();
	}
	input.close();
}

void Bitcoin::exchange() {
	for (std::vector<std::string>::iterator inputIt = inputDataBase.begin();
		 inputIt != inputDataBase.end(); inputIt++) {
		std::string date = inputIt->substr(0, inputIt->find(" "));
		if (validDate(inputIt->c_str()) == true && validValue(inputIt->c_str()) == true) {
			for (std::map<std::string, float>::iterator mapIt = csvDataBase.begin();
				 mapIt != csvDataBase.end(); mapIt++) {
				// if (mapIt->first.compare(0, 8, date.c_str(), 0, 8) == 0) {
				// IF NO DATE, NEED TO CHECK THE CLOSEST, BUT BEFORE THAT DATE
				if (mapIt->first.compare(date.c_str()) == 0) {
					std::cout << date << " => " << inputIt->substr(inputIt->find("|") + 2) << " = "
							  << amIRichYet(inputIt->c_str(), mapIt->second) << std::endl;
					break;
				} else if (mapIt->first.compare(0, 8, date.c_str(), 0, 8) == 0) {
					std::string closestDate;
					std::string day = date.substr(8);		  // current day on the date
					std::string subDate = date.substr(0, 8);  // the date without the day

					// std::cout << subDate << std::endl;
					// std::cout << day << std::endl;

					std::vector<std::string>::iterator dayListIt = validDays.begin();
					while (dayListIt != validDays.end()) {
						if (dayListIt->compare(day) == 0) break;
						dayListIt++;
					}
					std::map<std::string, float>::iterator closeIt = csvDataBase.begin();
					closestDate = subDate + *dayListIt;
					for (; closeIt != csvDataBase.end(); closeIt++) {
						if (closeIt->first.compare(closestDate.c_str()) == 0) {
							std::cout << date << " => " << inputIt->substr(inputIt->find("|") + 2)
									  << " = " << amIRichYet(inputIt->c_str(), closeIt->second)
									  << std::endl;
						break;
						}
					}
				}
			}
		}
	}
}

bool Bitcoin::validDate(std::string line) {
	std::string date = line.substr(0, line.find(" "));
	std::string year = date.substr(0, date.find("-"));
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	std::stringstream yy(year), mm(month), dd(day);
	int int_Y, int_M, int_D;
	yy >> int_Y, mm >> int_M, dd >> int_D;

	if (int_Y < 1970 || int_Y > 2042) return std::cout << WRONGYEAR << std::endl, false;
	if (validMonth(month) == false) return std::cout << WRONGMONTH << std::endl, false;
	if (validDay(day) == false) return std::cout << WRONGDAY << std::endl, false;
	return true;
}

bool Bitcoin::validMonth(std::string month) {
	std::vector<std::string>::iterator monthIt = validMonths.begin();
	for (; monthIt != validMonths.end(); monthIt++)
		if (monthIt->compare(month) == 0) return true;
	return false;
}

bool Bitcoin::validDay(std::string day) {
	std::vector<std::string>::iterator dayIt = validDays.begin();
	for (; dayIt != validDays.end(); dayIt++)
		if (dayIt->compare(day) == 0) return true;
	return false;
}

bool Bitcoin::validValue(std::string line) {
	std::string strValue = line.substr(line.find("|") + 2);
	std::stringstream numValue(strValue);
	float num;
	numValue >> num;
	if (num < 0) return std::cout << NOTPOS << std::endl, false;
	if (num > 1000) return std::cout << TOOBIG << std::endl, false;
	return true;
}

float Bitcoin::amIRichYet(std::string line, float coins) {
	std::string strValue = line.substr(line.find("|") + 2);
	std::stringstream numValue(strValue);
	float value;
	numValue >> value;
	return coins * value;
}

/*___________________________________________ SETTERS ___________________________________________*/
/*___________________________________________ GETTERS ___________________________________________*/

std::map<std::string, float> Bitcoin::getCsvData() const { return csvDataBase; }
std::vector<std::string> Bitcoin::getInputData() const { return inputDataBase; }
