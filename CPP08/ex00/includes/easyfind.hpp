#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#define NOTFOUND "\033[1;31mNot found by easyfind so it was hard to find.\033[0;39m"

template <typename T>
int easyfind(T &container, int num) {
	typename T::iterator val = std::find(container.begin(), container.end(), num);
	if (val != container.end()) return std::distance(container.begin(), val);
	return std::cout << NOTFOUND << std::endl, 1;
}

#endif