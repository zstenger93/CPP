#include "../includes/Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(10), c(42.42f), d(b);
    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << ASINT << std::endl;
    std::cout << "b is " << b.toInt() << ASINT << std::endl;
    std::cout << "c is " << c.toInt() << ASINT << std::endl;
    std::cout << "d is " << d.toInt() << ASINT << std::endl;

    return 0;
}