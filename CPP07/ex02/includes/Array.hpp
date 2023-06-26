#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

template <typename A>
class Array {
   public:
	Array() : elements(nullptr), arraySize(0) {}

	Array(unsigned int n) : arraySize(n) {
		if (n == 0)
			elements = nullptr;
		else
			elements = new A[arraySize]();
	}

	Array(const Array& cpy) : arraySize(cpy.arraySize) {
		elements = new A[arraySize];
		for (unsigned int i = 0; i < arraySize; ++i) {
			elements[i] = cpy.elements[i];
		}
	}

	Array& operator=(const Array& rhs) {
		if (this != &rhs) {
			delete[] elements;
			arraySize = rhs.arraySize;
			elements = new A[arraySize];
			for (unsigned int i = 0; i < arraySize; ++i) {
				elements[i] = rhs.elements[i];
			}
		}
		return *this;
	}

	~Array() { delete[] elements; }

	A& operator[](unsigned int index) {
		if (index >= arraySize) {
			throw std::exception();
		}
		return elements[index];
	}

	class IndexOutOfBoundsException : std::exception {
	   public:
		char const* what() const throw() { return "index out of range.\n"; }
	};

	unsigned int size() const { return arraySize; }

   private:
	A* elements;
	unsigned int arraySize;
};

#endif