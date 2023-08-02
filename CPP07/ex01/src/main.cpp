#include "../includes/iter.hpp"

class Awesome {
   public:
	Awesome(void) : _n(42) { return; }
	int get(void) const { return this->_n; }

   private:
	int _n;
};

std::ostream& operator<<(std::ostream& o, Awesome const& rhs) {
	o << rhs.get();
	return o;
}

template <typename T>
void print(T& x) {
	std::cout << x << std::endl;
	return;
}

void fromPDF() {
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print<const int>);
	iter(tab2, 5, print<Awesome>);
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(int);

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charArrayLength = sizeof(charArray) / sizeof(char);

	// Using iter with intArray
	std::cout << "\033[1;4;31mIterating through an INT array:\033[0;0;39m" << std::endl;
	iter(intArray, intArrayLength, printNum<int>);
	std::cout << std::endl;

	// Using iter with doubleArray
	std::cout << "\033[1;4;31mIterating through a DOUBLE array:\033[0;0;39m" << std::endl;
	iter(doubleArray, doubleArrayLength, printNum<double>);
	std::cout << std::endl;

	// Using iter with charArray
	std::cout << "\033[1;4;31mIterating through a CHAR array:\033[0;0;39m" << std::endl;
	iter(charArray, charArrayLength, printNum<char>);
	std::cout << std::endl;

	std::cout << "\033[1;4;31mTest from PDF:\033[0;0;39m" << std::endl;
	fromPDF();
}