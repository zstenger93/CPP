#include "../includes/Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) return std::cerr << "[ " << COLOR_R << INPUT_ERROR << COLOR_END << std::endl, 1;
    if (std::string(argv[1]).compare("SWITCH OFF") == 0)
        return std::cout << COLOR_R << SWITCH_OFF << COLOR_END << std::endl, system("make fclean"),
               0;
    Harl makeHarl;
    return makeHarl.complain(std::string(argv[1])), 0;
}