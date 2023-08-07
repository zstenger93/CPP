#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <map>

class Bitcoin {
   public:
	Bitcoin();
	~Bitcoin();
	Bitcoin(Bitcoin const &cpy);
	Bitcoin &operator=(Bitcoin const &cpy);

   private:
	std::map<std::string, float> csvDataBase;
	std::map<std::string, float> inputDataBase;
};

bool isInputFileCorrect(char *argv);

#endif