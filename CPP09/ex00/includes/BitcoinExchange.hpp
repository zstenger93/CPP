#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#define WRONGARG "\033[1;31mThis program only runs with 2 arguments.\033[0;39m"
#define WRONGEXT "\033[1;31mThis program only runs with a txt file.\033[0;39m"

class Bitcoin {
   public:
	Bitcoin();
	~Bitcoin();
	Bitcoin(Bitcoin const &cpy);
	Bitcoin &operator=(Bitcoin const &cpy);

	void isInputCorrect(int argc, char **argv);
	void exchange();
	std::string saveDate(std::string line) const;
	float saveRate(std::string line);
	std::map<std::string, float> getCsvData();

	class CustomException : public std::exception {
	   private:
		std::string message;

	   public:
		CustomException(const std::string &word);
		const char *what() const throw();
		virtual ~CustomException() throw();
	};

   private:
	std::map<std::string, float> csvDataBase; // data and exchange rate
	std::map<std::string, float> inputDataBase;
};

#endif