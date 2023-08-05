#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cctype>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <new>
#include <stdexcept>
#include <string>

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

template <typename T>
class Array {
   public:
	Array() : elements(NULL), arraySize(0) {}

	Array(unsigned int n) : arraySize(n) {
		if (n == 0)
			elements = NULL;
		else
			elements = new T[arraySize]();
	}

	Array(const Array& cpy) : arraySize(cpy.arraySize) {
		if (arraySize != 0) {
			elements = new T[arraySize]();
			for (unsigned int i = 0; i < arraySize; ++i) elements[i] = cpy.elements[i];
		} else
			elements = NULL;
	}

	Array& operator=(const Array& rhs) {
		if (this != &rhs) {
			delete[] elements;
			arraySize = rhs.arraySize;
			if (arraySize > 0) {
				elements = new T[arraySize]();
				for (unsigned int i = 0; i < arraySize; ++i) elements[i] = rhs.elements[i];
			}
		}
		return *this;
	}

	~Array() { delete[] elements; }

	T& operator[](unsigned int index) {
		if (index < 0 || index >= arraySize) throw IndexOutOfBoundsException();
		return elements[index];
	}

	T const& operator[](unsigned int index) const {
		if (index < 0 || index >= arraySize) throw IndexOutOfBoundsException();
		return elements[index];
	}

	class IndexOutOfBoundsException : public std::exception {
	   public:
		char const* what() const throw() { return "index out of range.\n"; }
	};

	unsigned int size() const { return arraySize; }

   private:
	T* elements;
	unsigned int arraySize;
};

#endif