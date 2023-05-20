#include "../includes/Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) return std::cerr << "[ " << COLOR_R << INPUT_ERROR << COLOR_END << std::endl, 1;
    Harl makeHarl;
    return makeHarl.complain(std::string(argv[1])), 0;
}