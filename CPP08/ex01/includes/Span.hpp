#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <numeric>
#include <vector>

#define NSPF "No span can be found."
#define SPAF "The span is already full, cannot accept more numbers."

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

#define BAD_INPUT "Wrong testcase ID. Available options are:\n\n      nothing -> options\n"
#define TEST1 "         1    -> test for shortest span\n         2    -> test for longest span\n"
#define TEST2 "         3    -> test for both\n         4    -> test for full span\n"
#define TEST3 "         5    -> test for no span\n         6    -> test for no span\n"

class Span {
   public:
	Span();
	Span(Span const &cpy);
	Span(const unsigned int &numbers);
	~Span();
	Span &operator=(Span const &rhs);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void addNumber(int number);

	template <typename Iterate>
	void addNumber(Iterate begin, Iterate end) {
		if (spanSize < numbers.size() + end - begin) throw(spanAlreadyFullException());
		numbers.insert(numbers.end(), begin, end);
	}

	class noSpanFoundException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class spanAlreadyFullException : public std::exception {
	   public:
		const char *what() const throw();
	};

   private:
	unsigned int spanSize;
	std::vector<int> numbers;
};

#endif