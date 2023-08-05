#ifndef ITER_HPP
#define ITER_HPP

#include <sys/_types/_size_t.h>
#include <cctype>
#include <string>
#include <iostream>

template <typename T, typename Function>
void iter(T *array, size_t length, Function func) {
	for (size_t i = 0; i < length; i++) {
		std::cout << "Element on index " << i << ": ";
		func(array[i]);
	}
}

template <typename T>
void printNum(T &element) {
	std::cout << "\033[1;34m" << element << "\033[0;39m" << std::endl;
}

#endif