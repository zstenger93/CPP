#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define INVALID "If you want to have another option, then go and write it by yourself!"
#define DEBUG "Well, you created the bugs, so debugIT yourself as well!"
#define INFO "My allocation status is malloc'd but never free'd"
#define WARNING \
    "If you don't know what is an alias, just leave your computer open and you will know!!"
#define ERROR "Errors? We have only features my friend!"

class Harl {
   private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);

   public:
    Harl();
    ~Harl();
    void complain(std::string level);
};

#endif