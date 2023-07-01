#include "../includes/Span.hpp"

#include <algorithm>
#include <vector>

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Span::Span() : spanSize(0) {}

Span::Span(Span const &cpy) {
	this->spanSize = cpy.spanSize;
	this->numbers = cpy.numbers;
}

Span::Span(const unsigned int &nums) : spanSize(nums) {}
Span::~Span() {}

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		this->spanSize = rhs.spanSize;
		this->numbers = rhs.numbers;
	}
	return *this;
}

/*_______________________________________ NESTED CLASSES ________________________________________*/

const char *Span::noSpanFoundException::what() const throw() { return NSPF; }
const char *Span::spanAlreadyFullException::what() const throw() { return SPAF; }

/*__________________________________________ FUNCTIONS __________________________________________*/

void Span::addNumber(int number) {
	if (spanSize == numbers.size()) throw(spanAlreadyFullException());
	numbers.push_back(number);
}

unsigned int Span::shortestSpan() {
	if (numbers.size() < 2) throw(noSpanFoundException());
	std::vector<int> tmp = numbers;
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = *(tmp.begin() + 1) - *(tmp.begin());
	for (std::vector<int>::iterator i = tmp.begin(); i < tmp.end(); i++)
		if ((unsigned int)(*(i + 1) - *i) < shortest) shortest = *(i + 1) - *i;
	return shortest;
}

unsigned int Span::longestSpan() {
	if (numbers.size() < 2) throw(noSpanFoundException());
	return *std::max_element(numbers.begin(), numbers.end()) -
		   *std::min_element(numbers.begin(), numbers.end());
}