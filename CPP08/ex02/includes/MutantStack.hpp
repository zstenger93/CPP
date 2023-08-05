#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

#define RED "\033[1;4;31m"
#define END "\033[1;0;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

#define BAD_INPUT "Wrong testcase ID. Available options are:\n\n      nothing -> options\n"
#define TEST1 "         1    -> test finding an element in the stack with iterator\n"
#define TEST2 "         2    -> test for the case from the PDF\n"

#define SEARCHING_FOR "\033[1;4;31mSearching for element:\033[0;0;39m "
#define CHECKING_AT "\033[1;4;34mChecking element at index:\033[0;0;39m "
#define NO_MATCH_AT "\033[1;33mNo match, going to check element at index:\033[0;39m "
#define ITERATING "\033[1;31mIterating..."
#define ELEM "\033[1;32mThe element\033[0;39m "
#define FOUND_AT " \033[1;32mhas been found at index: \033[0;39m"

template <typename T>
class MutantStack : public std::stack<T> {
   public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin() { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }
	const_iterator begin() const { return std::stack<T>::c.begin(); }
	const_iterator end() const { return std::stack<T>::c.end(); }
};

#endif