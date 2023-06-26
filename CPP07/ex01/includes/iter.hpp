#ifndef ITER_HPP
#define ITER_HPP

#include <sys/_types/_size_t.h>

#include <iostream>

template <typename Num>
void iter(Num *array, size_t length, void (*func)(Num)) {
	for (size_t i = 0; i < length; i++) func(array[i]);
}

template <typename Num>
void printNum(Num element) {
	std::cout << element << " ";
}

#endif