#include "../includes/Span.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Span::Span() : spanSize(0) {}

Span::Span(Span const &cpy) {
	this->spanSize = cpy.getSize();
	this->numbers = cpy.getNumbers();
}

Span::Span(const unsigned int &nums) : spanSize(nums) {}
Span::~Span() {}

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		this->numbers.clear();
		this->spanSize = rhs.getSize();
		this->numbers = rhs.getNumbers();
	}
	return *this;
}

/*_______________________________________ NESTED CLASSES ________________________________________*/

const char *Span::noSpanFoundException::what() const throw() { return NSPF; }
const char *Span::spanAlreadyFullException::what() const throw() { return SPAF; }

/*__________________________________________ FUNCTIONS __________________________________________*/

unsigned int Span::getSize() const { return this->spanSize; }
std::vector<int> Span::getNumbers() const { return this->numbers; }
