#include <iostream>

int main(int argc, char **argv) {
    unsigned int len;
    std::string s;

    if (argc == 1) return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
    for (int i = 1; i < argc; i++) {
        s = argv[i];
        len = s.length();
        for (unsigned int k = 0; k < len; k++) s[k] = std::toupper(s.at(k));
        std::cout << s;
    }
    return (std::cout << std::endl, 0);
}
