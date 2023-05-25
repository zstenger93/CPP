#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define ERROR "Errors? We have only features my friend!"
#define INFO "My allocation status is malloc'd but never free'd"
#define DEBUG "Well, you created the bugs, so debugIT yourself as well!"
#define INVALID "If you want to have another option, then go and write it by yourself!"
#define WARNING \
	"If you don't know what is an alias, just leave your computer open and you will know!!"

class Harl {
   public:
	Harl();
	~Harl();
	void complain(std::string level);

   private:
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
};

#endif