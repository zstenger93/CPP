#include "../includes/Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::_debug(void) { std::cout << DEBUG << std::endl; }
void Harl::_info(void) { std::cout << INFO << std::endl; }
void Harl::_warning(void) { std::cout << WARNING << std::endl; }
void Harl::_error(void) { std::cout << ERROR << std::endl; }

void Harl::ExecuteOption(const std::string& option, void (Harl::*optionFunc)()) {
	std::cout << "[ " << COLOR_Y << option << COLOR_END << " ]" << std::endl;
	(this->*optionFunc)();
	std::cout << std::endl;
}

void Harl::complain(std::string level) {
	int option_id = -1;
	std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*options_ptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = -1; i < 4; ++i)
		if (level.compare(options[i]) == 0) option_id = i;
	switch (option_id) {
		case 0:
			ExecuteOption(options[0], options_ptr[0]);
		case 1:
			ExecuteOption(options[1], options_ptr[1]);
		case 2:
			ExecuteOption(options[2], options_ptr[2]);
		case 3:
			ExecuteOption(options[3], options_ptr[3]);
			break;
		default:
			std::cout << "[ " << INSIGNIFICANT << " ]" << std::endl;
			break;
	}
}
