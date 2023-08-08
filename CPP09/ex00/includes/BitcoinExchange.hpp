#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define WRONGARG "\033[1;31mThis program only runs with 2 arguments.\033[0;39m"
#define WRONGEXT "\033[1;31mThis program only runs with a txt file.\033[0;39m"
#define WRONGYEAR "\033[1;31mError: The year is invalid.\033[0;39m"
#define WRONGMONTH "\033[1;31mError: The month is invalid.\033[0;39m"
#define WRONGDAY "\033[1;31mError: The day is invalid.\033[0;39m"
#define NOTPOS "\033[1;31mError: Not a positive number. The allowed range is 0-1000.\033[0;39m"
#define TOOBIG "\033[1;31mError: Not a positive number. The allowed range is 0-1000.\033[0;39m"

class Bitcoin {
   public:
	Bitcoin();
	~Bitcoin();
	Bitcoin(Bitcoin const &cpy);
	Bitcoin &operator=(Bitcoin const &cpy);

	// csv
	std::string saveDate(std::string line) const;
	float saveRate(std::string line) const;
	// input
	void isInputCorrect(int argc, char **argv);
	std::map<std::string, float> getCsvData() const;
	std::vector<std::string> getInputData() const;
	void saveInput(std::string inputFile);
	// exchange
	void exchange();
	bool validDate(std::string line);
	bool validMonth(std::string month);
	bool validDay(std::string day);
	bool validValue(std::string line);
	float amIRichYet(std::string line, float coins);

	// for testing
	void printMap(std::map<std::string, float> dataBaseType);
	void printVector(std::vector<std::string> dataBaseType);

	class CustomException : public std::exception {
	   private:
		std::string message;

	   public:
		CustomException(const std::string &word);
		const char *what() const throw();
		virtual ~CustomException() throw();
	};

   private:
	std::map<std::string, float> csvDataBase;  // data and exchange rate
	std::vector<std::string> inputDataBase;	   // data from input file
	std::vector<std::string> validMonths;
	std::vector<std::string> validDays;
};

#endif