#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstdlib>
#include <exception>
#include <iostream>
#include <numeric>
#include <vector>

#define NSPF "No span can be found."
#define SPAF "The span is already full, cannot accept more numbers."

class Span {
   public:
	Span();
	Span(Span const &cpy);
	Span(const unsigned int &numbers);
	~Span();
	Span &operator=(Span const &rhs);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	std::vector<int> getNumbers() const;
	unsigned int getSize() const;
	void addNumber(int number) const;

	class noSpanFoundException : std::exception {
	   public:
		const char *what() const throw();
	};

	class spanAlreadyFullException : std::exception {
	   public:
		const char *what() const throw();
	};

   private:
	unsigned int spanSize;
	std::vector<int> numbers;
};

#endif