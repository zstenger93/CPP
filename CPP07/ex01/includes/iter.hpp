#ifndef ITER_HPP
#define ITER_HPP

#include <sys/_types/_size_t.h>

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T)) {
	for (size_t i = 0; i < length; i++) func(array[i]);
}

template <typename T>
void printNum(T element) {
	std::cout << element << " ";
}

#endif