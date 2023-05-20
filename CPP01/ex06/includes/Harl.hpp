#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define COLOR_Y "\033[1;33m"
#define COLOR_R "\033[1;91m"
#define COLOR_END "\033[0;39m"

#define ERROR "Errors? We have only features my friend!"
#define INFO "My allocation status is malloc'd but never free'd"
#define DEBUG "Well, you created the bugs, so debugIT yourself as well!"
#define INSIGNIFICANT "Probably complaining about insignificant problems"
#define SWITCH_OFF "Switching off Harl, because he's complaining too much."
#define INVALID "If you want to have another option, then go and write it by yourself!"
#define INPUT_ERROR                                                                             \
    "Error! You're dumb!.. Uh.. I mean.. Invalid number of arguments. This program requires 1 " \
    "argument!"
#define WARNING \
    "If you don't know what is an alias, just leave your computer open and you will know!!"

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