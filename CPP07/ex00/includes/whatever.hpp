#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename Num>
Num max(Num a, Num b) {
	return (a > b) ? a : b;
}

template <typename Num>
Num min(Num a, Num b) {
	return (a < b) ? a : b;
}

template <typename Num>
void swap(Num &a, Num &b) {
	Num tmp = a;
	a = b;
	b = tmp;
}

#endif