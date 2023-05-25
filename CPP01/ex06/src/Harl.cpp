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

	int option_id = -1;

	for (int i = -1; i < 4; ++i)
		if (level.compare(options[i]) == 0) option_id = i;
	switch (option_id) {
		case 0:
			std::cout << "[ " << COLOR_Y << options[0] << COLOR_END << " ]" << std::endl;
			(this->*options_ptr[0])();
			std::cout << std::endl;
		case 1:
			std::cout << "[ " << COLOR_Y << options[1] << COLOR_END << " ]" << std::endl;
			(this->*options_ptr[1])();
			std::cout << std::endl;
		case 2:
			std::cout << "[ " << COLOR_Y << options[2] << COLOR_END << " ]" << std::endl;
			(this->*options_ptr[2])();
			std::cout << std::endl;
		case 3:
			std::cout << "[ " << COLOR_Y << options[3] << COLOR_END << " ]" << std::endl;
			(this->*options_ptr[3])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ " << INSIGNIFICANT << " ]" << std::endl;
	}
}
