#include "../includes/Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::_debug(void) { std::cout << DEBUG << std::endl; }
void Harl::_info(void) { std::cout << INFO << std::endl; }
void Harl::_warning(void) { std::cout << WARNING << std::endl; }
void Harl::_error(void) { std::cout << ERROR << std::endl; }

void Harl::complain(std::string level) {
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*options_ptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

    for (int i = -1; i < 4; ++i) {
        if (level.compare(options[i]) == 0) return (this->*options_ptr[i])();
    }
    std::cout << INVALID << std::endl;
}
