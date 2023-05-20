#include "../includes/Harl.hpp"

int main(void) {
    Harl makeHarl;

    makeHarl.complain("DEBUG");
    makeHarl.complain("INFO");
    makeHarl.complain("WARNING");
    makeHarl.complain("ERROR");
    makeHarl.complain("INVALID");
    return 0;
}