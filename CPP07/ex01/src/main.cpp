#include "../includes/iter.hpp"

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
  size_t intArrayLength = sizeof(intArray) / sizeof(int);

  double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

  char charArray[] = {'a', 'b', 'c', 'd', 'e'};
  size_t charArrayLength = sizeof(charArray) / sizeof(char);

  // Using iter with intArray
  iter(intArray, intArrayLength, printNum<int>);
  std::cout << std::endl;

  // Using iter with doubleArray
  iter(doubleArray, doubleArrayLength, printNum<double>);
  std::cout << std::endl;

  // Using iter with charArray
  iter(charArray, charArrayLength, printNum<char>);
  std::cout << std::endl;
}