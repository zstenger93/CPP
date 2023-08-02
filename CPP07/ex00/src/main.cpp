#include "../includes/whatever.hpp"

int main(void) {
	int a = 2;
	int b = 3;
	std::cout << "\033[1;4;31mBefore swap:\033[0;0;39m "
			  << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "Swappin..." << std::endl;
	std::cout << "\033[1;4;31mAfter swap:\033[0;0;39m "
			  << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "\033[1;4;31mBefore swap:\033[0;0;39m "
			  << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "Swappin..." << std::endl;
	std::cout << "\033[1;4;31mAfter swap:\033[0;0;39m "
			  << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	return 0;
}
